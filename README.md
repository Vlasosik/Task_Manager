Task Management System
This is a task management system that allows users to create, manage, and track tasks with various functionalities like categorization, prioritization, status tracking, and deadline reminders.

Task Model
The Task class includes attributes such as:

Title: The name of the task.
Description: A detailed description of the task.
Priority: The priority level of the task (e.g., High, Medium, Low).
Status: The status of the task (e.g., "In Progress", "Completed").
Deadline: The deadline for completing the task.
The "Factory" design pattern is used to create tasks of different types, such as high-priority tasks, personal tasks, and more.

Categories
The Category class is used to group tasks into categories such as:

Work
Personal
Study
You can create new categories and assign tasks to them, providing an organized structure for managing tasks.

Task Manager
The TaskManager class is the central component of the system, managing the task list and providing methods for:

Adding, editing, and deleting tasks.
Sorting tasks by priority, deadline, or status.
Accessing a singleton instance to manage the tasks globally across the application.
The "Singleton" design pattern is applied to ensure that only one instance of TaskManager exists.

Reporting and Filtering
Filters: You can filter tasks by categories, priority, status, and deadline.
Export: A feature to export completed tasks into a report, which can be saved in formats such as .txt or .csv.
Multithreading
A background reminder mechanism is implemented using std::thread and std::mutex to periodically check all tasks with deadlines. This system runs in a separate thread to notify users about upcoming deadlines.

Exception Handling
Custom exceptions are defined for task management, specifically:

TaskManagerException: Handles errors related to task management, such as invalid deadlines or missing categories.
Technologies Used
C++: The primary programming language used.
STL: Standard Template Library (STL) containers like std::vector and std::map are used for task storage and management.
Multithreading: Utilizes std::thread for background processes and std::mutex for synchronizing access to shared data.
Features
Task creation with various attributes.
Categorization of tasks.
Task sorting by priority, status, or deadline.
Filtering tasks by different criteria.
Task completion export to .txt or .csv format.
Deadline reminders using multithreading.
Exception handling for specific task management errors.
