# 海龟自动巡逻项目

本项目使用 ROS 2 Humble 和 turtlesim，实现四目标点闭环自动巡逻。

## 已实现功能

- 订阅 `/turtle1/pose` 获取实时位置和朝向。
- 发布 `/turtle1/cmd_vel` 控制直线速度与角速度。
- 按配置文件中的目标点循环巡逻并统计完成圈数。
- 通过参数调整路线、速度、控制增益和到达误差。
- 通过服务开始、暂停或重置巡逻。
- 通过 `/turtle_patrol/status` 发布当前状态。
- 使用 Launch 一条命令同时启动 turtlesim 和巡逻节点。

## 构建

由于项目路径包含中文，构建产物统一放在纯英文目录：

```bash
cd ~/桌面/pre-graduate_studies/03_ROS2/02_turtle_patrol_ws
export PATH=/usr/bin:/bin:$PATH
source /opt/ros/humble/setup.bash
colcon --log-base ~/ros2_colcon/02_turtle_patrol_ws/log build --base-paths src --build-base ~/ros2_colcon/02_turtle_patrol_ws/build --install-base ~/ros2_colcon/02_turtle_patrol_ws/install --packages-select turtle_patrol
source ~/ros2_colcon/02_turtle_patrol_ws/install/setup.bash
```

## 一键启动

启动前请先关闭之前手动运行的 `turtlesim_node`，避免出现两个同名节点。

```bash
ros2 launch turtle_patrol turtle_patrol.launch.py
```

启动但暂不巡逻：

```bash
ros2 launch turtle_patrol turtle_patrol.launch.py autostart:=false
```

## 运行控制

```bash
ros2 service call /turtle_patrol/start std_srvs/srv/Trigger "{}"
ros2 service call /turtle_patrol/stop std_srvs/srv/Trigger "{}"
ros2 service call /turtle_patrol/reset_route std_srvs/srv/Trigger "{}"
ros2 topic echo /turtle_patrol/status
```

## 常用参数

参数默认值位于 `config/patrol.yaml`：

- `waypoints_x`、`waypoints_y`：巡逻目标点坐标。
- `max_linear_speed`：最大直线速度。
- `max_angular_speed`：最大旋转速度。
- `linear_gain`、`angular_gain`：距离和角度控制增益。
- `angle_tolerance`：允许开始前进的角度误差。
- `arrival_tolerance`：判定到达目标点的距离误差。
- `autostart`：启动后是否立即巡逻。

运行过程中也可以修改速度：

```bash
ros2 param set /turtle_patrol max_linear_speed 1.0
```

## 项目结构

```text
turtle_patrol/
├── config/patrol.yaml
├── launch/turtle_patrol.launch.py
├── turtle_patrol/move_forward.py
├── turtle_patrol/patrol_node.py
├── package.xml
└── setup.py
```
