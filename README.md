# ROS 2 Calculator Service Project

## 📌 Project Description

This project implements a **Calculator using ROS 2 Service Architecture**.

The project consists of two ROS 2 nodes:

1. **Calculator Server Node**
   - Provides the calculator service.
   - Receives calculation requests from the client.
   - Performs arithmetic operations.
   - Sends the result back to the client.

2. **Calculator Client Node**
   - Sends calculation requests to the server.
   - Receives and displays the calculated result.

A custom ROS 2 service interface (`Cal.srv`) is created to exchange data between client and server.

The project is developed using **ROS 2 Humble**, **C++**, and the **colcon build system**.

---

# 🚀 Features

The calculator supports:

- Addition (+)
- Subtraction (-)
- Multiplication (*)
- Division (/)

The client provides:

- First number (`a`)
- Second number (`b`)
- Third number (`c`)
- Operation type

The server processes the request and returns:

- Calculation result
- Status message

---

# 🛠️ Technologies Used

- ROS 2 Humble
- Ubuntu 22.04
- C++
- ROS 2 Services
- Custom Service Messages
- Colcon Build System
- Git & GitHub

---

# 📂 Package Structure

```
tutorial_interfaces
│
├── CMakeLists.txt
├── package.xml
│
├── msg
│   ├── Num.msg
│   └── Sphere.msg
│
├── srv
│   └── Cal.srv
│
├── src
│   ├── calculator_server.cpp
│   └── calculator_client.cpp
│
└── launch
    └── calculator.launch.py
```

---

# 📄 Service Interface

## Cal.srv

Location:

```
tutorial_interfaces/srv/Cal.srv
```

Content:

```
int64 a
int64 b
int64 c
string operation
---
int64 result
string message
```

### Request

Client sends:

```
a
b
c
operation
```

### Response

Server returns:

```
result
message
```

---

# ⚙️ Installation and Setup

## 1. Install ROS 2 Humble

Make sure ROS 2 Humble is installed and sourced:

```bash
source /opt/ros/humble/setup.bash
```

---

# 📥 Clone Repository

Create ROS 2 workspace:

```bash
mkdir -p ~/ros2_ws/src
```

Go into source folder:

```bash
cd ~/ros2_ws/src
```

Clone repository:

```bash
git clone https://github.com/Abhiraj-Sawant/ROS2Pkgs.git
```

Enter repository:

```bash
cd ROS2Pkgs
```

Switch to required branch:

```bash
git checkout abhiraj
```

Copy the package into ROS 2 workspace:

```bash
cp -r tutorial_interfaces ~/ros2_ws/src/
```

---

# 🔨 Build the Package

Go to workspace:

```bash
cd ~/ros2_ws
```

Build:

```bash
colcon build --packages-select tutorial_interfaces
```

Source the workspace:

```bash
source install/setup.bash
```

---

# ▶️ Running the Calculator

## Method 1: Run Server and Client Separately

### Terminal 1: Start Server

Source ROS:

```bash
source /opt/ros/humble/setup.bash
```

Source workspace:

```bash
source ~/ros2_ws/install/setup.bash
```

Run server:

```bash
ros2 run tutorial_interfaces calculator_server
```

Output:

```
Calculator service is ready...
```

---

### Terminal 2: Run Client

Source ROS:

```bash
source /opt/ros/humble/setup.bash
```

Source workspace:

```bash
source ~/ros2_ws/install/setup.bash
```

Run client:

```bash
ros2 run tutorial_interfaces calculator_client
```

---

# 🧮 Example Execution

Client:

```
===== ROS2 Calculator =====

Enter First Number:
10

Enter Second Number:
20

Enter Third Number:
30

Choose Operation:

1. Addition
2. Subtraction
3. Multiplication
4. Division

Enter Choice:
1
```

Server:

```
Incoming request received

a: 10
b: 20
c: 30

Operation: Addition

Sending response
```

Client:

```
Result: 60
Message: Addition successful
```

---

# 🚀 Running Using Launch File

Build package:

```bash
colcon build --packages-select tutorial_interfaces
```

Source:

```bash
source install/setup.bash
```

Run:

```bash
ros2 launch tutorial_interfaces calculator.launch.py
```

The launch file starts:

- Calculator Server
- Calculator Client

using ROS 2 parameters.

---

# 🔍 Useful ROS 2 Commands

Check available services:

```bash
ros2 service list
```

Check service type:

```bash
ros2 service type /calculator
```

Check package:

```bash
ros2 pkg list | grep tutorial_interfaces
```

---

# 📌 Git Workflow

Create personal branch:

```bash
git checkout -b abhiraj
```

Add changes:

```bash
git add .
```

Commit:

```bash
git commit -m "Added ROS2 calculator project"
```

Push:

```bash
git push origin abhiraj
```

---

# 👨‍💻 Author

**Abhiraj Sawant**

Automation and Robotics Engineering Student

ROS 2 Calculator Service Project

---

# 📜 License

This project is released under the Apache-2.0 License.
