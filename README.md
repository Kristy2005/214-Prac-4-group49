# 214-Prac-4-group49
# TaskForge

TaskForge is a hierarchical work-processing system developed for COS 214 Practical 4.

The system models a nested body of work in the **Logistics** domain. It allows individual work items and groups of work to be managed as part of the same hierarchical structure.

The project is implemented in **C++11** and demonstrates the following Gang of Four design patterns:

* Composite
* Iterator
* State
* Decorator

## Team Members

| Name       | Student Number   |
| ---------- | ---------------- |
| Kristy Heesen | u24702341 |
| Livhuwani Munyai | u25449029 |
| Maeryn Pillay | u25146484 |

## Project Features

TaskForge demonstrates:

* A recursive hierarchy containing groups and individual work items
* Multiple ways of traversing the hierarchy
* Independent iterators over the same structure
* State-dependent behaviour and lifecycle transitions
* Runtime decorators that can be stacked
* Runtime changes to the hierarchy or object behaviour
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
TaskForge/
|
|-- src/                 Source files
|-- include/             Header files
|-- docs/                UML diagrams and design documentation
|-- main.cpp             Program entry point
|-- Makefile             Project build instructions
|-- Dockerfile           Docker environment
|-- README.md            Project documentation
```

The exact source structure may differ as development continues.

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

The project includes a Docker environment containing the tools required to compile, run and debug TaskForge.

The Docker environment includes:

```text
g++
make
gdb
valgrind
```

No project-specific development tools need to be installed directly on the host computer.

### Build the Docker Image

From the root directory of the repository run:

```bash
docker build -t taskforge .
```

### Open the Docker Environment

Run:

```bash
docker run --rm -it --entrypoint /bin/bash taskforge
```

Once inside the container, compile the project using:

```bash
make
```

Then run TaskForge using:

```bash
./taskforge
```

## GDB

To debug TaskForge using GDB inside the Docker container:

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

## Valgrind

To check the program for memory leaks and memory errors:

```bash
valgrind --leak-check=full --show-leak-kinds=all ./taskforge
```

The final implementation should contain no definitely-lost memory originating from the project code.

## UML Documentation

The `docs/` directory contains the UML documentation for the project.

The project includes:

* UML Class Diagram
* UML Object Diagram
* UML State Diagram
* Three UML Activity Diagrams

The diagrams reflect the final C++ implementation and the runtime behaviour of TaskForge.

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
