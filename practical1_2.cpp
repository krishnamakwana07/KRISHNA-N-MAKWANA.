#include <iostream>
using namespace std;

class Book {
public:
    int id, copies;
    string title, author;

    void add() {
        cout << "Enter ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Title: ";
        getline(cin, title);

        cout << "Enter Author: ";
        getline(cin, author);

        cout << "Enter Copies: ";
        cin >> copies;
    }

    void display() {
        cout << id << " | " << title << " | "
             << author << " | Copies: " << copies << endl;
    }
};

Book b[100];
int n = 0;

void issueBook() {
    int search;
    cout << "Enter ID: ";
    cin >> search;

    for (int i = 0; i < n; i++) {
        if (b[i].id == search) {
            if (b[i].copies > 0) {
                b[i].copies--;
                cout << "Issued!\n";
            } else {
                cout << "No copies!\n";
            }
            return;
        }
    }
}

void returnBook() {
    int search;
    cout << "Enter ID: ";
    cin >> search;

    for (int i = 0; i < n; i++) {
        if (b[i].id == search) {
            b[i].copies++;
            cout << "Returned!\n";
            return;
        }
    }
}

int main() {
    int choice;

    do {
        cout << "\n1.Add 2.Issue 3.Return 4.Display 5.Exit\n";
        cin >> choice;

        if (choice == 1) {
            b[n].add();
            n++;
        }
        else if (choice == 2) issueBook();
        else if (choice == 3) returnBook();
        else if (choice == 4) {
            for (int i = 0; i < n; i++) {
                b[i].display();
            }
        }

    } while (choice != 5);

    return 0;
}