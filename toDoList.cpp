#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct ToDo {
    string description;
    bool completed;
};

vector<ToDo> toDoList;

void addToList(const string& description) {
    ToDo newlist;
    newlist.description = description;
    newlist.completed = false;
    toDoList.push_back(newlist);
}

void viewList() {
    cout << "Tasks:\n";
    for (const auto& task : toDoList) {
        cout << "- " << task.description << " (" << (task.completed ? "Completed" : "Not yet Completed") << ")\n";
    }
}

void markListAsCompleted(int index) {
    if (index >= 0 && index < toDoList.size()) {
        toDoList[index].completed = true;
    }
}

void removeList(int index) {
    if (index >= 0 && index < toDoList.size()) {
        toDoList.erase(toDoList.begin() + index);
    }
}

int main() {
    int choice;
    string description;

    do {
        cout << "----------TO-DO LIST----------\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                cin.ignore();
                getline(cin, description);
                addToList(description);
                break;
            case 2:
                viewList();
                break;
            case 3:
                int index;
                cout << "Enter task index: ";
                cin >> index;
                markListAsCompleted(index);
                break;
            case 4:
                cout << "Enter task index: ";
                cin >> index;
                removeList(index);
                break;
            case 5:
               cout << "Exiting...\n";
               cout<<"THANK YOU!!\n";
                break;
            default:
               cout << "Invalid choice. Please try again.\n";
                break;
        }

        cout << "\n";
    } while (choice != 5);

    return 0;
}
