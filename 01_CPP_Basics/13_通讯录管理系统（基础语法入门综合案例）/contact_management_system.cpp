#include <iostream>
#include <string>

struct Person
{
    std::string mName;
    int mSex;
    int mAge;
    std::string mTel;
    std::string mAdd;
};

struct Addressbooks
{
    struct Person personArray[1000];

    int mSize;
};

void showMenu()
{
    std::cout << "1、添加联系人\n2、显示联系人\n3、删除联系人\n4、查找联系人\n5、"
                 "修改联系人\n6、清空联系人\n0、退出通讯录\n";
}

void addPerson(Addressbooks *abs)
{
    if (abs->mSize == 1000)
    {
        std::cout << "通讯录已满，无法添加！" << std::endl;
        return;
    }
    else
    {
        // 姓名
        std::string name;
        std::cout << "请输入姓名：\n";
        std::cin >> name;
        abs->personArray[abs->mSize].mName = name;

        // 性别
        std::cout << "请输入性别：\n1——男\n2——女\n";
        int sex = 0;
        while (true)
        {
            std::cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArray[abs->mSize].mSex = sex;
                break;
            }
            std::cout << "输入有误，请重新输入。\n";
        }

        // 年龄
        std::cout << "请输入年龄：\n";
        int age = 0;
        std::cin >> age;
        abs->personArray[abs->mSize].mAge = age;

        // 电话
        std::cout << "请输入电话：\n";
        std::string tel;
        std::cin >> tel;
        abs->personArray[abs->mSize].mTel = tel;

        // 住址
        std::cout << "请输入住址：\n";
        std::string add;
        std::cin >> add;
        abs->personArray[abs->mSize].mAdd = add;

        abs->mSize++;
        std::cout << "添加成功！\n";
        std::cout << "按回车键返回菜单...\n";
        std::cin.ignore(1024, '\n');
        std::cin.get();
        system("clear");
    }
}

void showPerson(Addressbooks *abs)
{
    if (abs->mSize == 0)
    {
        std::cout << "无记录\n";
    }
    else
    {
        for (int i = 0; i < abs->mSize; i++)
        {
            std::cout << "姓名：" << abs->personArray[i].mName;
            std::cout << "  |  性别：" << (abs->personArray[i].mSex == 1 ? "男" : "女");
            std::cout << "  |  年龄：" << abs->personArray[i].mAge;
            std::cout << "  |  电话：" << abs->personArray[i].mTel;
            std::cout << "  |  住址：" << abs->personArray[i].mAdd << std::endl;
        }
    }
    std::cout << "按回车键返回菜单...\n";
    std::cin.ignore(1024, '\n');
    std::cin.get();
    system("clear");
}

int isExist(Addressbooks *abs, std::string name)
{
    for (int i = 0; i < abs->mSize; i++)
    {
        if (abs->personArray[i].mName == name)
        {
            return i;
        }
    }
    return -1;
}

void deletePerson(Addressbooks *abs)
{
    std::cout << "请输入您要删除的联系人：\n";

    std::string name;
    std::cin >> name;

    int ret = isExist(abs, name);
    if (ret != -1)
    {
        for (int i = ret; i < abs->mSize; i++)
        {
            abs->personArray[i] = abs->personArray[i + 1];
        }
        abs->mSize--;
        std::cout << "删除成功！\n";
        std::cout << "按回车键返回菜单...\n";
        std::cin.ignore(1024, '\n');
        std::cin.get();
        system("clear");
    }
    else
    {
        std::cout << "查无此人！\n";
        std::cout << "按回车键返回菜单...\n";
        std::cin.ignore(1024, '\n');
        std::cin.get();
        system("clear");
    }
}

void findPerson(Addressbooks *abs)
{
    std::cout << "请输入您要查找的联系人：\n";
    std::string name;
    std::cin >> name;

    int ret = isExist(abs, name);
    if (ret != -1)
    {
        std::cout << "姓名：" << abs->personArray[ret].mName;
        std::cout << "  |  性别：" << (abs->personArray[ret].mSex == 1 ? "男" : "女");
        std::cout << "  |  年龄：" << abs->personArray[ret].mAge;
        std::cout << "  |  电话：" << abs->personArray[ret].mTel;
        std::cout << "  |  住址：" << abs->personArray[ret].mAdd << std::endl;
        std::cout << "按回车键返回菜单...\n";
        std::cin.ignore(1024, '\n');
        std::cin.get();
        system("clear");
    }
    else
    {
        std::cout << "查无此人！\n";
        std::cout << "按回车键返回菜单...\n";
        std::cin.ignore(1024, '\n');
        std::cin.get();
        system("clear");
    }
}

void modifyPerson(Addressbooks *abs)
{
    std::cout << "请输入您要修改的联系人：\n";
    std::string name;
    std::cin >> name;

    int ret = isExist(abs, name);
    if (ret != -1)
    {
        // 姓名
        std::string name;
        std::cout << "请输入姓名：";
        std::cin >> name;
        abs->personArray[ret].mName = name;

        // 性别
        std::cout << "请输入性别：\n1——男\n2——女\n";
        while (true)
        {
            int sex = 0;
            std::cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArray[ret].mSex = sex;
                break;
            }
            std::cout << "输入有误，请重新输入。\n";
        }

        // 年龄
        std::cout << "请输入年龄：\n";
        int age = 0;
        std::cin >> age;
        abs->personArray[ret].mAge = age;

        // 电话
        std::cout << "请输入电话：\n";
        std::string tel;
        std::cin >> tel;
        abs->personArray[ret].mTel = tel;

        // 住址
        std::cout << "请输入住址：\n";
        std::string add;
        std::cin >> add;
        abs->personArray[ret].mAdd = add;

        std::cout << "修改成功！\n";
        std::cout << "按回车键返回菜单...\n";
        std::cin.ignore(1024, '\n');
        std::cin.get();
        system("clear");
    }
    else
    {
        std::cout << "查无此人！\n";
        std::cout << "按回车键返回菜单...\n";
        std::cin.ignore(1024, '\n');
        std::cin.get();
        system("clear");
    }
}

void clearPerson(Addressbooks *abs)
{
    abs->mSize = 0;
    std::cout << "通讯录已清空！\n";
    std::cout << "按回车键返回菜单...\n";
    std::cin.ignore(1024, '\n');
    std::cin.get();
    system("clear");
}

int main()
{
    Addressbooks abs;
    abs.mSize = 0;

    int select = 0;

    while (true)
    {
        showMenu();

        std::cin >> select;
        switch (select)
        {
        case 0: // 退出
            std::cout << "欢迎下次使用";
            return 0;
            break;
        case 1: // 添加
            addPerson(&abs);
            break;
        case 2: // 显示
            showPerson(&abs);
            break;
        case 3: // 删除
            deletePerson(&abs);
            break;
        case 4: // 查找
            findPerson(&abs);
            break;
        case 5: // 修改
            modifyPerson(&abs);
            break;
        case 6: // 清空
            clearPerson(&abs);
            break;
        }
    }

    return 0;
}