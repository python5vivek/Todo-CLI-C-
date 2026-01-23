#include <iostream>
#include <vector>
using namespace std;

struct Todo {
    string title;
    bool completed;
};

int main(void) {
    cout << "Welcome To my Todo-Application" << endl;
    vector<Todo> todos;
    int choice;
    while (true) {
    cout << "0. Exit\n1. Add Todo\n2. View Todos\n3. Complete Todo\n4. Delete Todo\nChoose an option: ";
    cin >> choice;
    if (choice == 1) {
        Todo newTodo;
        cout << "Enter Todo title: ";
        cin >> ws;
        getline(cin, newTodo.title);
        newTodo.completed = false;
        todos.push_back(newTodo);
        cout << "Todo added successfully!" << endl;
    } else if (choice == 2) {
        cout << "Your Todos:" << endl;
        for (size_t i = 0; i < todos.size(); ++i) {
            cout << i + 1 << ". " << todos[i].title 
                 << (todos[i].completed ? " [Completed]" : " [Pending]") << endl;
        }
    }else if (choice == 0) {
        cout << "Exiting the application. Goodbye!" << endl;
        break;
    }else if (choice == 3) {
        size_t todoIndex;
        for (size_t i = 0; i < todos.size(); ++i) {
            cout << i + 1 << ". " << todos[i].title 
                 << (todos[i].completed ? " [Completed]" : " [Pending]") << endl;
        }
        cout << "Enter the Todo number to mark as completed: ";
        cin >> todoIndex;
        if (todoIndex > 0 && todoIndex <= todos.size()) {
            todos[todoIndex - 1].completed = true;
            cout << "Todo marked as completed!" << endl;
        } else {
            cout << "Invalid Todo number!" << endl;
        }
    } else if (choice == 4) {
        size_t todoIndex;
        for (size_t i = 0; i < todos.size(); ++i) {
            cout << i + 1 << ". " << todos[i].title 
                 << (todos[i].completed ? " [Completed]" : " [Pending]") << endl;
        }
        cout << "Enter the Todo number to delete: ";
        cin >> todoIndex;
        if (todoIndex > 0 && todoIndex <= todos.size()) {
            todos.erase(todos.begin() + todoIndex - 1);
            cout << "Todo deleted successfully!" << endl;
        } else {
            cout << "Invalid Todo number!" << endl;
        }
    } else {
        cout << "Invalid choice!" << endl;
        choice = 0;
    }
}
    return 0;
}
