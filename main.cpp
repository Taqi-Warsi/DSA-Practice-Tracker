#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void addProblem() {
    string topic, problem, difficulty, status;

    cin.ignore();

    cout << "Enter DSA Topic: ";
    getline(cin, topic);

    cout << "Enter Problem Name: ";
    getline(cin, problem);

    cout << "Enter Difficulty (Easy/Medium/Hard): ";
    getline(cin, difficulty);

    cout << "Enter Status (Solved/Pending): ";
    getline(cin, status);

    ofstream file("problems.txt", ios::app);

    file << topic << " | "
         << problem << " | "
         << difficulty << " | "
         << status << endl;

    file.close();

    cout << "\nProblem added successfully!\n";
}

void viewProblems() {
    ifstream file("problems.txt");
    string line;

    cout << "\n===== DSA Practice Problems =====\n";

    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

void searchByTopic() {
    string topic, line;
    bool found = false;

    cin.ignore();

    cout << "Enter topic to search: ";
    getline(cin, topic);

    ifstream file("problems.txt");

    cout << "\n===== Search Results =====\n";

    while (getline(file, line)) {
        if (line.find(topic) != string::npos) {
            cout << line << endl;
            found = true;
        }
    }

    file.close();

    if (!found) {
        cout << "No problems found for this topic.\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n===== DSA PRACTICE TRACKER =====\n";
        cout << "1. Add Problem\n";
        cout << "2. View Problems\n";
        cout << "3. Search by Topic\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addProblem();
                break;

            case 2:
                viewProblems();
                break;

            case 3:
                searchByTopic();
                break;

            case 4:
                cout << "Keep practicing DSA!\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
