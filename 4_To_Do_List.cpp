#include <iostream>
#include <vector>
#include <algorithm>
#include <string>  // Add this line

using namespace std;

// Structure to represent a task
struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

// Function prototypes
void addTask(vector<Task>& todoList, const string& description);
void viewTasks(const vector<Task>& todoList);
void markCompleted(vector<Task>& todoList, const string& description);
void removeTask(vector<Task>& todoList, const string& description);

int main() {
    vector<Task> todoList;

    char choice;
    do {
        cout << "TO-DO LIST MANAGER\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Choose an option (1-5): ";
        cin >> choice;

        switch (choice) {
            case '1': {
                string taskDescription;
                cout << "Enter the task description: ";
                cin.ignore(); // Clear the input buffer
                getline(cin, taskDescription);
                addTask(todoList, taskDescription);
                break;
            }
            case '2':
                viewTasks(todoList);
                break;
            case '3': {
                string taskDescription;
                cout << "Enter the task description to mark as completed: ";
                cin.ignore();
                getline(cin, taskDescription);
                markCompleted(todoList, taskDescription);
                break;
            }
            case '4': {
                string taskDescription;
                cout << "Enter the task description to remove: ";
                cin.ignore();
                getline(cin, taskDescription);
                removeTask(todoList, taskDescription);
                break;
            }
            case '5':
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }

    } while (choice != '5');

    return 0;
}

// Function to add a task to the list
void addTask(vector<Task>& todoList, const string& description) {
    todoList.push_back(Task(description));
    cout << "Task added successfully.\n";
}

// Function to view the tasks in the list
void viewTasks(const vector<Task>& todoList) {
    cout << "TO-DO LIST:\n";
    for (const auto& task : todoList) {
        cout << "- " << task.description;
        if (task.completed) {
            cout << " (Completed)";
        }
        cout << "\n";
    }
    cout << endl;
}

// Function to mark a task as completed
void markCompleted(vector<Task>& todoList, const string& description) {
    auto it = find_if(todoList.begin(), todoList.end(), [&](const Task& task) { return task.description == description; });

    if (it != todoList.end()) {
        it->completed = true;
        cout << "Task marked as completed.\n";
    } else {
        cout << "Task not found.\n";
    }
}

// Function to remove a task from the list
void removeTask(vector<Task>& todoList, const string& description) {
    auto it = remove_if(todoList.begin(), todoList.end(), [&](const Task& task) { return task.description == description; });

    if (it != todoList.end()) {
        todoList.erase(it, todoList.end());
        cout << "Task removed successfully.\n";
    } else {
        cout << "Task not found.\n";
    }
}
