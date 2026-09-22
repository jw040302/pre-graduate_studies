#include <algorithm>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

class Worker
{
private:
    int m_Id;
    std::string m_Name;

public:
    Worker(int id, std::string name) : m_Id(id), m_Name(name)
    {
    }

    virtual ~Worker()
    {
    }

    int getId() const
    {
        return m_Id;
    }

    const std::string &getName() const
    {
        return m_Name;
    }

    virtual int getRoleCode() const = 0;
    virtual std::string getRoleName() const = 0;
    virtual std::string getDuty() const = 0;

    void showInfo() const
    {
        std::cout << "编号：" << m_Id
                  << "\t姓名：" << m_Name
                  << "\t岗位：" << getRoleName()
                  << "\t职责：" << getDuty() << "\n";
    }
};

class Employee : public Worker
{
public:
    Employee(int id, std::string name) : Worker(id, name)
    {
    }

    int getRoleCode() const override
    {
        return 1;
    }

    std::string getRoleName() const override
    {
        return "员工";
    }

    std::string getDuty() const override
    {
        return "完成经理交付的任务";
    }
};

class Manager : public Worker
{
public:
    Manager(int id, std::string name) : Worker(id, name)
    {
    }

    int getRoleCode() const override
    {
        return 2;
    }

    std::string getRoleName() const override
    {
        return "经理";
    }

    std::string getDuty() const override
    {
        return "完成老板任务并向员工分配任务";
    }
};

class Boss : public Worker
{
public:
    Boss(int id, std::string name) : Worker(id, name)
    {
    }

    int getRoleCode() const override
    {
        return 3;
    }

    std::string getRoleName() const override
    {
        return "老板";
    }

    std::string getDuty() const override
    {
        return "管理公司全部事务";
    }
};

class WorkerManager
{
private:
    std::vector<std::unique_ptr<Worker>> m_Workers;
    std::string m_FileName;

    int readInt(const std::string &prompt) const
    {
        while (true)
        {
            std::cout << prompt;

            std::string input;
            std::getline(std::cin, input);

            std::stringstream stream(input);
            int value = 0;
            char extra = 0;

            if (stream >> value && !(stream >> extra))
            {
                return value;
            }

            std::cout << "请输入有效整数。\n";
        }
    }

    std::string readName(const std::string &prompt) const
    {
        while (true)
        {
            std::cout << prompt;

            std::string name;
            std::getline(std::cin, name);

            if (!name.empty() && name.find('|') == std::string::npos)
            {
                return name;
            }

            std::cout << "姓名不能为空，也不能包含字符|。\n";
        }
    }

    int readRole() const
    {
        while (true)
        {
            int role = readInt("请选择岗位（1.员工 2.经理 3.老板）：");

            if (role >= 1 && role <= 3)
            {
                return role;
            }

            std::cout << "岗位编号必须是1、2或3。\n";
        }
    }

    std::unique_ptr<Worker> createWorker(int id, const std::string &name, int role) const
    {
        if (role == 1)
        {
            return std::unique_ptr<Worker>(new Employee(id, name));
        }

        if (role == 2)
        {
            return std::unique_ptr<Worker>(new Manager(id, name));
        }

        if (role == 3)
        {
            return std::unique_ptr<Worker>(new Boss(id, name));
        }

        return std::unique_ptr<Worker>();
    }

    int findIndexById(int id) const
    {
        for (std::size_t index = 0; index < m_Workers.size(); index++)
        {
            if (m_Workers[index]->getId() == id)
            {
                return static_cast<int>(index);
            }
        }

        return -1;
    }

    void load()
    {
        std::ifstream input(m_FileName.c_str());

        if (!input.is_open())
        {
            return;
        }

        std::string line;

        while (std::getline(input, line))
        {
            std::stringstream stream(line);
            std::string idText;
            std::string roleText;
            std::string name;

            if (!std::getline(stream, idText, '|') ||
                !std::getline(stream, roleText, '|') ||
                !std::getline(stream, name))
            {
                continue;
            }

            try
            {
                int id = std::stoi(idText);
                int role = std::stoi(roleText);
                std::unique_ptr<Worker> worker = createWorker(id, name, role);

                if (worker && findIndexById(id) == -1)
                {
                    m_Workers.push_back(std::move(worker));
                }
            }
            catch (...)
            {
            }
        }
    }

    void save() const
    {
        std::ofstream output(m_FileName.c_str());

        for (std::size_t index = 0; index < m_Workers.size(); index++)
        {
            const Worker &worker = *m_Workers[index];
            output << worker.getId() << '|'
                   << worker.getRoleCode() << '|'
                   << worker.getName() << '\n';
        }
    }

    void addWorker()
    {
        int id = readInt("请输入职工编号：");

        if (findIndexById(id) != -1)
        {
            std::cout << "该职工编号已存在。\n";
            return;
        }

        std::string name = readName("请输入职工姓名：");
        int role = readRole();

        m_Workers.push_back(createWorker(id, name, role));
        save();

        std::cout << "职工添加成功。\n";
    }

    void showWorkers() const
    {
        if (m_Workers.empty())
        {
            std::cout << "暂无职工信息。\n";
            return;
        }

        for (std::size_t index = 0; index < m_Workers.size(); index++)
        {
            m_Workers[index]->showInfo();
        }
    }

    void removeWorker()
    {
        int id = readInt("请输入要删除的职工编号：");
        int index = findIndexById(id);

        if (index == -1)
        {
            std::cout << "未找到该职工。\n";
            return;
        }

        m_Workers.erase(m_Workers.begin() + index);
        save();

        std::cout << "职工删除成功。\n";
    }

    void updateWorker()
    {
        int id = readInt("请输入要修改的职工编号：");
        int index = findIndexById(id);

        if (index == -1)
        {
            std::cout << "未找到该职工。\n";
            return;
        }

        int newId = readInt("请输入新的职工编号：");
        int duplicateIndex = findIndexById(newId);

        if (duplicateIndex != -1 && duplicateIndex != index)
        {
            std::cout << "新的职工编号已存在。\n";
            return;
        }

        std::string name = readName("请输入新的职工姓名：");
        int role = readRole();

        m_Workers[index] = createWorker(newId, name, role);
        save();

        std::cout << "职工信息修改成功。\n";
    }

    void findWorker() const
    {
        int id = readInt("请输入要查询的职工编号：");
        int index = findIndexById(id);

        if (index == -1)
        {
            std::cout << "未找到该职工。\n";
            return;
        }

        m_Workers[index]->showInfo();
    }

    void sortWorkers()
    {
        if (m_Workers.empty())
        {
            std::cout << "暂无职工信息。\n";
            return;
        }

        int order = readInt("请选择排序方式（1.升序 2.降序）：");

        if (order != 1 && order != 2)
        {
            std::cout << "排序方式无效。\n";
            return;
        }

        std::sort(
            m_Workers.begin(),
            m_Workers.end(),
            [order](const std::unique_ptr<Worker> &first,
                    const std::unique_ptr<Worker> &second)
            {
                if (order == 1)
                {
                    return first->getId() < second->getId();
                }

                return first->getId() > second->getId();
            });

        save();
        showWorkers();
    }

    void clearWorkers()
    {
        std::cout << "确认清空全部职工信息吗？输入yes确认：";

        std::string confirmation;
        std::getline(std::cin, confirmation);

        if (confirmation != "yes")
        {
            std::cout << "已取消清空操作。\n";
            return;
        }

        m_Workers.clear();
        save();

        std::cout << "职工信息已清空。\n";
    }

    void showMenu() const
    {
        std::cout << "\n========== 职工管理系统 ==========\n";
        std::cout << "1. 添加职工\n";
        std::cout << "2. 显示职工\n";
        std::cout << "3. 删除职工\n";
        std::cout << "4. 修改职工\n";
        std::cout << "5. 查询职工\n";
        std::cout << "6. 编号排序\n";
        std::cout << "7. 清空信息\n";
        std::cout << "0. 退出系统\n";
    }

public:
    WorkerManager(std::string fileName) : m_FileName(fileName)
    {
        load();
    }

    void run()
    {
        while (true)
        {
            showMenu();
            int choice = readInt("请选择操作：");

            switch (choice)
            {
            case 1:
                addWorker();
                break;
            case 2:
                showWorkers();
                break;
            case 3:
                removeWorker();
                break;
            case 4:
                updateWorker();
                break;
            case 5:
                findWorker();
                break;
            case 6:
                sortWorkers();
                break;
            case 7:
                clearWorkers();
                break;
            case 0:
                std::cout << "感谢使用职工管理系统。\n";
                return;
            default:
                std::cout << "无效操作，请重新选择。\n";
            }
        }
    }
};

int main()
{
    WorkerManager manager("workers.txt");
    manager.run();

    return 0;
}
