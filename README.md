# 214-Prac-4-group49
# TaskForge

TaskForge is a hierarchical work-processing system developed for COS 214 Practical 4.

The system models a nested body of work in the **corporate facilities complaint and maintenance management** domain. It allows complaints to be organised across companies, buildings, floors or departments, and complaint categories while supporting lifecycle management, priority handling and optional notifications.

The project is implemented in **C++11** and demonstrates the following Gang of Four design patterns:

* Composite
* Iterator
* State
* Decorator

## Team Members

| Name | Student Number |
| ---------- | ---------------- |
| Kristy Heesen | u24702341 |
| Livhuwani Munyai | u25449029 |
| Maeryn Pillay | u25146484 |

## Project Features

TaskForge demonstrates:

* A recursive hierarchy containing groups and individual complaints
* Multiple ways of traversing the hierarchy
* Independent iterators over the same runtime structure
* State-dependent behaviour and lifecycle transitions
* Valid and invalid state transitions
* Runtime decorators that can be stacked
* Urgent complaint priority handling
* Optional complaint notifications
* Runtime changes to the hierarchy or object behaviour
* Snapshot-based traversal
* Safe polymorphic object destruction and memory management

## Design Patterns

### Composite

The Composite pattern is used to represent the hierarchical structure of TaskForge.

Individual work items act as leaf objects while groups can contain both individual items and other groups.

### Iterator

The Iterator pattern provides traversal of the TaskForge hierarchy without exposing the internal container used to store objects.

The system supports at least two different traversal behaviours and allows multiple independent iterators to operate on the same hierarchy.

### State

The State pattern controls the lifecycle of individual work items.

The behaviour of a work item depends on its current state, and invalid state transitions are handled by the system.

### Decorator

The Decorator pattern allows optional responsibilities to be added to objects dynamically at runtime.

Decorators can also be stacked so that an object can have multiple additional behaviours while still being accessed through the same abstraction.

## Repository Structure

```text
214-Prac-4-group49/
|
|-- *.cpp                     C++ source files
|-- *.h                       C++ header files
|-- main.cpp                  Program entry point
|-- Makefile                  Project build instructions
|-- Dockerfile                Docker environment
|-- README.md                 Project documentation
|
|-- docs/
    |
    |-- diagrams/
        |-- Activity Diagram1.jpg
        |-- Activity Diagram2.jpg
        |-- Activity Diagram3.jpg
        |-- Object Diagram.jpg
        |-- State Diagram.jpg
        |-- Prac4.vpp
        |-- Cos_214 PracDocument.docx
        |-- Debugging Evidence.png
        |-- GDB Evidence.png
        |-- Valgrind Evidence.png
```

The `docs/diagrams/` directory contains the UML diagrams, Visual Paradigm project file, written project documentation and debugging evidence used for the practical.

## Building the Project

The final executable is named:

```bash
taskforge
```

The project can be compiled using:

```bash
make
```

To remove generated object files and the executable:

```bash
make clean
```

To rebuild the complete project:

```bash
make clean
make
```

## Running TaskForge

After compiling the project:

```bash
./taskforge
```

## Docker

The project includes a Docker environment containing the tools required to compile, run, debug and investigate TaskForge.

The Docker image is based on Ubuntu 22.04 and includes:

```text
build-essential
g++
make
gdb
valgrind
doxygen
graphviz
```

No project-specific development tools need to be installed directly on the host computer.

The Docker container uses `/app` as its working directory and copies the complete repository into the container.

### Build the Docker Image

From the root directory of the repository run:

```bash
docker build -t taskforge .
```

### Run TaskForge Directly with Docker

The Dockerfile is configured to automatically run:

```bash
make clean && make && ./taskforge
```

Therefore, TaskForge can be compiled and executed using:

```bash
docker run --rm -it taskforge
```

### Open the Docker Environment

To open an interactive shell inside the Docker environment:

```bash
docker run --rm -it --entrypoint /bin/bash taskforge
```

Once inside the container, the project files are located in:

```bash
/app
```

Compile the project using:

```bash
make clean
make
```

Then run TaskForge using:

```bash
./taskforge
```

## GDB

GDB is installed inside the Docker environment.

To open a Docker shell with debugging permissions:

```bash
docker run --rm -it \
  --cap-add=SYS_PTRACE \
  --security-opt seccomp=unconfined \
  --entrypoint /bin/bash taskforge
```

Once inside the container, start GDB using:

```bash
gdb ./taskforge
```

Example useful GDB commands:

```text
break main
run
next
step
print variableName
continue
quit
```

GDB was used during development to inspect program execution, state changes and runtime behaviour.

## Valgrind

Valgrind is installed inside the Docker environment.

Open the Docker environment using:

```bash
docker run --rm -it --entrypoint /bin/bash taskforge
```

Then run:

```bash
valgrind --leak-check=full --show-leak-kinds=all ./taskforge
```

The final implementation should contain no definitely-lost memory originating from the project code.

Valgrind evidence is included in the project documentation.

## UML Documentation

The `docs/diagrams/` directory contains the UML documentation for the project.

The project includes:

* UML Class Diagram
* UML Object Diagram
* UML State Diagram
* Three UML Activity Diagrams

The diagrams reflect the final C++ implementation and runtime behaviour of TaskForge.

Additional debugging and investigation evidence is also stored in this directory.

## GitHub Workflow

Development is performed collaboratively using Git and GitHub.

The `main` branch is protected. Team members should develop features on separate branches and create Pull Requests before merging changes into `main`.

A Pull Request requires approval from at least one other team member before it can be merged.

Example workflow:

```bash
git checkout -b feature-name
```

After making changes:

```bash
git add .
git commit -m "Meaningful description of changes"
git push -u origin feature-name
```

A Pull Request can then be created on GitHub to merge the branch into `main`.

Team members should use meaningful commit messages and contribute throughout the development of the project.

## Course Information

**Module:** COS 214
**Practical:** Practical 4
**Project:** TaskForge - Hierarchical Work Processing
**Language:** C++11
