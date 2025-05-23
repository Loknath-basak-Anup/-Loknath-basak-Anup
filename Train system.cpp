#include <bits/stdc++.h>
using namespace std;

struct Node {
    string trainID;
    Node* next;
};

Node* head = nullptr;


void add_train( string id) {
    Node* newTrain = new Node;
    newTrain->trainID = id;
    newTrain->next = nullptr;

    if (head == nullptr) {
        head = newTrain;
        cout << "Train " << id << " added.\n";
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newTrain;
    cout << "Train " << id << " added.\n";
}


void depart_train( string id) {
    if (head == nullptr) {
        cout << "No train to remove.\n";
        return;
    }

    if (head->trainID == id) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Train " << id << " departed.\n";
        return;
    }

    Node* curr = head;
    while (curr->next != nullptr && curr->next->trainID != id)
        curr = curr->next;

    if (curr->next != nullptr) {
        Node* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
        cout << "Train " << id << " departed.\n";
    } else {
        cout << "Train " << id << " not found.\n";
    }
}


void emergency_block(int pos) {
    if (head == nullptr) {
        cout << "No trains available.\n";
        return;
    }

    if (pos < 0) {
        cout << "Invalid position.\n";
        return;
    }

    if (pos == 0) {
        Node* temp = head;
        head = head->next;
        cout << "Train " << temp->trainID << " Remove the train at position pos (0-based) due to a track blockage.\n";
        delete temp;
        return;
    }

    Node* curr = head;
    for (int i = 0; i < pos - 1 && curr != nullptr; i++) {
        curr = curr->next;
    }

    if (curr == nullptr || curr->next == nullptr) {
        cout << "Invalid position.\n";
        return;
    }

    Node* temp = curr->next;
    curr->next = curr->next->next;
    cout << "Train " << temp->trainID << " removed from position " << pos << " (emergency).\n";
    delete temp;
}


void display_tracks() {
    if (head == nullptr) {
        cout << "No trains on track.\n";
        return;
    }

    Node* temp = head;
    cout << "Trains on track: ";
    while (temp != nullptr) {
        cout << temp->trainID << " ";
        temp = temp->next;
    }
    cout << "\n";
}


void clear_all() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    int choice;
    string id;
    int pos;

    do {
        cout << "\n~Railway Station Menu~\n";
        cout << "1. Add Train .\n";
        cout << "2. Depart Train by ID .\n";
        cout << "3. Emergency Block (by Position) .\n";
        cout << "4. Display Tracks .\n";
        cout << "5. Exit.\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Train ID to add: ";
                cin >> id;
                add_train(id);
                break;
            case 2:
                cout << "Enter Train ID to depart: ";
                cin >> id;
                depart_train(id);
                break;
            case 3:
                cout << "Enter position to remove (0-based): ";
                cin >> pos;
                emergency_block(pos);
                break;
            case 4:
                display_tracks();
                break;
            case 5:
                clear_all();
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
