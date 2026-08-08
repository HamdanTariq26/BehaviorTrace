# BehaviorTrace

<p align="center">
  <strong>A Windows-based C++ project for system-level keyboard event monitoring and local activity logging.</strong>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Language-C%2B%2B-blue?style=for-the-badge" alt="C++">
  <img src="https://img.shields.io/badge/Platform-Windows-0078D4?style=for-the-badge" alt="Windows">
  <img src="https://img.shields.io/badge/API-Windows%20API-5C2D91?style=for-the-badge" alt="Windows API">
  <img src="https://img.shields.io/badge/Architecture-x64-success?style=for-the-badge" alt="x64">
</p>

<p align="center">
  <a href="#overview">Overview</a> •
  <a href="#features">Features</a> •
  <a href="#how-it-works">How It Works</a> •
  <a href="#security--privacy">Security & Privacy</a> •
  <a href="#building">Building</a>
</p>

---

## Overview

**BehaviorTrace** is a native Windows application written in **C++** that explores system-level keyboard event handling through the Windows API.

The project demonstrates how a Windows application can receive keyboard input events, process them, and store resulting activity locally.

Rather than operating as a Windows service or installing itself as a persistent system component, BehaviorTrace runs as a regular user-space process. After launch, its visible interface is hidden while the process continues running in the background.

The project was built as a practical exploration of Windows API programming, event handling, process behavior, and local data management.

> ⚠️ **Usage Notice**
>
> BehaviorTrace should only be used on systems where you have explicit authorization to monitor keyboard activity.

---

## ✨ Features

* ⌨️ **Keyboard Event Monitoring**

  * Processes keyboard input at the Windows API level.

* 🖥️ **Native Windows Application**

  * Built using C++ and Windows-specific APIs.

* 📝 **Local Activity Logging**

  * Captured information is handled and stored locally.

* 👻 **Background Operation**

  * The visible application interface hides after execution while the process continues running.

* 🎛️ **Task Manager Control**

  * Runs as a normal Windows process and can be located and terminated through Task Manager.

* 🚫 **No Windows Service**

  * The application does not install or register itself as a Windows service.

* 🔄 **No Automatic Startup**

  * The application does not configure itself to automatically launch after Windows restarts.

* 🌐 **No Remote Transmission**

  * The project does not include a remote server or automatic cloud upload mechanism.

---

## 🔍 How It Works

At a high level, the application follows this lifecycle:

```text
┌─────────────────────┐
│   User launches     │
│    BehaviorTrace    │
└──────────┬──────────┘
           │
           ▼
┌─────────────────────┐
│ Application starts  │
│ as a normal process │
└──────────┬──────────┘
           │
           ▼
┌─────────────────────┐
│ Visible interface   │
│      is hidden      │
└──────────┬──────────┘
           │
           ▼
┌─────────────────────┐
│ Keyboard events are │
│      processed      │
└──────────┬──────────┘
           │
           ▼
┌─────────────────────┐
│ Data handled/stored │
│       locally       │
└─────────────────────┘
```

The program remains a regular user-space process while it is running.

It does **not** convert itself into a Windows service, install a driver, or establish automatic startup persistence.

---

## 🔐 Security & Privacy

BehaviorTrace intentionally uses a straightforward execution model.

### Process Visibility

After launch, the application's visible interface is hidden, but the underlying process remains a normal Windows process.

It can be managed through standard Windows administration tools such as **Task Manager**.

For example:

```text
Task Manager
     │
     ├── Processes
     │
     └── PC Optimizer
             │
             └── End Task
```

There is no mechanism intended to prevent the user or system administrator from terminating the process.

### No Startup Persistence

BehaviorTrace does not register itself to automatically start with Windows.

If the computer is restarted:

```text
Windows Shutdown
       ↓
Computer Restart
       ↓
BehaviorTrace is NOT running
       ↓
Manual launch required
```

This is an intentional part of the application's lifecycle.

### Local Data Handling

The project is designed around local data handling.

There is no built-in:

* Cloud storage
* Remote logging server
* Automatic upload
* Network-based synchronization
* Remote command mechanism

Collected information remains on the local machine according to the application's implementation.

> **Privacy Note:** Keyboard activity can contain passwords, messages, personal information, and other sensitive data. Only use the software in environments where monitoring has been explicitly authorized.

---

## 🧠 What This Project Demonstrates

BehaviorTrace provides a practical example of several Windows programming concepts.

### Windows API

The project interacts directly with Windows functionality rather than relying entirely on high-level cross-platform abstractions.

### Event Processing

Keyboard input is handled through system-level event mechanisms, providing an example of how applications can respond to operating-system events.

### Native C++

The project is implemented in C++, providing direct access to Windows APIs and native process functionality.

### Process Lifecycle

The project also demonstrates the distinction between:

* A normal user application
* A background process
* A Windows service
* Startup persistence

BehaviorTrace operates as a **normal user-space process**.

---

## 🛠️ Technology Stack

| Component         | Technology    |
| :---------------- | :------------ |
| **Language**      | C++           |
| **Platform**      | Windows       |
| **API**           | Windows API   |
| **IDE**           | Visual Studio |
| **Build System**  | MSBuild       |
| **Architecture**  | x64           |
| **Configuration** | Debug         |

---

## 📋 Requirements

Before building the project, make sure you have:

* **Windows 10 or later**
* **Visual Studio 2022** or compatible Visual Studio version
* **Desktop development with C++** workload
* **Windows SDK**
* **x64 C++ build tools**

---

## 🚀 Getting Started

### 1. Clone the Repository

```bash
git clone https://github.com/HamdanTariq26/BehaviorTrace.git
```

Navigate into the project:

```bash
cd BehaviorTrace
```

### 2. Open the Solution

Open:

```text
myProject.sln
```

using Visual Studio.

### 3. Select the Build Configuration

Use:

```text
Configuration: Debug
Platform: x64
```

### 4. Build

Build the solution using:

```text
Build → Build Solution
```

or:

```text
Ctrl + Shift + B
```

### 5. Run

Launch the generated executable from Visual Studio or the resulting `x64/Debug` directory.

---

## 📁 Project Structure

```text
BehaviorTrace/
│
├── .vs/                         # Local Visual Studio data
│
├── myProject/
│   ├── main.cpp                 # Main application source
│   ├── myProject.vcxproj        # Visual Studio project
│   ├── myProject.vcxproj.filters
│   └── myProject.vcxproj.user
│
├── x64/
│   └── Debug/                  # Generated build files
│
├── myProject.sln               # Visual Studio solution
│
├── .gitignore
│
└── README.md
```

> Build outputs and Visual Studio-generated files are excluded from version control through `.gitignore`.

---

## 🖥️ Platform Support

BehaviorTrace currently relies on Windows-specific functionality.

| Operating System |     Support     |
| :--------------: | :-------------: |
|    🪟 Windows    |   ✅ Supported   |
|     🐧 Linux     | ❌ Not supported |
|     🍎 macOS     | ❌ Not supported |

The project is **not intended to be cross-platform** in its current form.

---

## 🧪 Development

The project can be used as a starting point for experimenting with:

* Windows API programming
* Native C++ applications
* Keyboard event processing
* Event-driven programming
* Local file I/O
* Windows process management
* Application lifecycle behavior
* System-level input handling

---

## ⚠️ Responsible Use

BehaviorTrace interacts with keyboard input, which can contain highly sensitive information.

Use it only in environments where you have the appropriate permission to perform monitoring.

The software is provided for development, testing, research, and controlled environments. The developer is not responsible for unauthorized deployment or misuse.

---

## 📜 License

This project is distributed under the license included in the repository.

See [`LICENSE`](LICENSE) for the complete terms and conditions.

---

## 👤 Author

**Hamdan Tariq**

Bachelors in Artificial Intelligence

<p>
  <a href="https://github.com/HamdanTariq26">
    <img src="https://img.shields.io/badge/GitHub-HamdanTariq26-181717?style=for-the-badge&logo=github" alt="GitHub">
  </a>
</p>

---

## ⭐ Project Status

> **Status:** Active Development

BehaviorTrace is currently a Windows-focused project and may evolve as additional Windows API and native C++ functionality is explored.

---

<p align="center">
  <sub>Built with C++ and the Windows API.</sub>
</p>
