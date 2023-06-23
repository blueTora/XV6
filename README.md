# XV6 OS Project Repository
Fall 2021

Welcome to the XV6 OS Projects repository! This repository contains three projects that extend the functionality of the XV6 operating system. Each project introduces new system calls and implements additional features to enhance the capabilities of XV6. Let's dive into the details of each project.

## Project 1: Adding System Calls - ProcCount and ReadCount

The first project focuses on expanding the system call interface of XV6. Two new system calls, `getProcCount()` and `getReadCount()`, have been added to provide additional information about the system.

- `int getProcCount(void)`

  The `getProcCount()` system call returns the total number of active processes currently running in the XV6 operating system. This system call can be utilized by user programs or other system utilities to obtain information about the system's process count.

- `int getReadCount(void)`

  The `getReadCount()` system call retrieves the number of times the `read()` system call has been invoked since the system started running. This system call can be used to gather statistics about the usage of the `read()` operation, allowing for monitoring and analysis of read operations within XV6.

## Project 2: Adding System Calls - ProcTick and Sysinfo

In the second project, two additional system calls, `getProcTick(pid)` and `sysinfo(info)`, have been introduced to XV6, further expanding its functionality.

- `int getProcTick(int pid)`

  The `getProcTick(pid)` system call retrieves the total number of ticks (i.e., CPU cycles) used by the process identified by the provided process ID (pid) from th moment it was created. This system call enables monitoring and profiling of individual process performance, allowing for detailed analysis and optimization.

- `int sysinfo(struct sysinfo *info)`

The `sysinfo(info)` system call returns a structure containing important information and statistics about the system. This system call is valuable for developing system monitoring tools and gathering vital information about the system's state.

The structure `sysinfo` has the following fields:

```c
struct sysinfo {
  long uptime;             // Seconds since boot
  unsigned long totalram;  // Total usable main memory size
  unsigned long freeram;   // Available memory size
  unsigned short procs;    // Number of current processes
};
```

- `uptime`: Represents the number of seconds since the system started running. It provides an indication of how long the system has been operational.

- `totalram`: Indicates the total amount of usable main memory (RAM) available in the system. It represents the overall capacity of memory that can be utilized by processes.

- `freeram`: Represents the available memory size, indicating the amount of unused memory currently accessible by the system. This value fluctuates based on system demands and memory allocations.

- `procs`: Denotes the number of current processes running in the system. It provides an understanding of the workload and activity level within the operating system.

## Project 3: Implementing Waiting Queue, Dispatcher, and Unit Operations

The third project is a comprehensive enhancement to XV6, introducing a waiting queue, dispatcher, and four unit operations. To accomplish this, several new system calls have been implemented.

### Waiting Queue and Dispatcher

The waiting queue and dispatcher facilitate managing and scheduling threads within XV6. The waiting queue is responsible for holding threads waiting for execution, while the dispatcher selects the next thread to run based on a specific scheduling policy.

### System Calls

The following system calls have been implemented to support the waiting queue, dispatcher, and unit operations:

- `int thread_create(void *stack, int status)`:

   This system call creates a new thread with the provided stack and status parameters. It enables concurrent execution of multiple threads within XV6.

- `int thread_wait()`:

  The `thread_wait()` system call allows a thread to wait until all other threads have completed execution. It ensures synchronization and coordination among threads.

- `int unit0_operation()`, `int unit1_operation()`, `int unit2_operation()`, and `int unit3_operation()`:

### Unit Operations

  These system calls implement unit operations that perform specific tasks or operations within XV6. Each unit operation serves a distinct purpose and contributes to the overall functionality of the operating system.

- `unit0_operation()`

The `unit0_operation()` system call performs a specific operation on a value within XV6. It adds 7 to the value and then applies the modulo operation by M. This operation can be used for various purposes, such as transforming or manipulating data in a controlled manner.

- `unit1_operation()`

The `unit1_operation()` system call multiplies a value within XV6 by 2 and then applies the modulo operation by M. Similar to `unit0_operation()`, this operation allows for controlled data manipulation by scaling the value and ensuring it stays within defined bounds.

- `unit2_operation()`

The `unit2_operation()` system call multiplies a value within XV6 by 3 and then applies the modulo operation by M. This operation is another form of controlled data manipulation, effectively scaling the value by a factor of 3 while keeping it within the specified range.

- `unit3_operation()`

The `unit3_operation()` system call prints out the value it receives as input. This operation provides a means to display or log the value for debugging or informational purposes. It can be used to track the progress or state of the system during execution.

These unit operations offer flexibility and extend the capabilities of XV6. By utilizing them in your programs or system utilities, you can perform various computations, transformations, and observations based on the specific requirements of your project.

## Acknowledgments

We would like to express our gratitude to the developers and maintainers of XV6 for creating an excellent foundation for operating systems education. This project builds upon their work, extending XV6's functionality and providing additional learning opportunities.
