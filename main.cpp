#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    int n, k;
    cout << "Enter number of participants: ";
    cin >> n;
    cout << "Enter elimination interval: ";
    cin >> k;

    if (n <= 0 || k <= 0) {
        cout << "Invalid input!";
        return 0;
    }

    Node* head = new Node{1, nullptr};
    Node* temp = head;

    for (int i = 2; i <= n; i++) {
        temp->next = new Node{i, nullptr};
        temp = temp->next;
    }
    temp->next = head;

    Node* cur = head;
    Node* prev = temp;

    cout << "Elimination order: ";

    while (cur->next != cur) {
        for (int i = 1; i < k; i++) {
            prev = cur;
            cur = cur->next;
        }

        cout << cur->data << " ";
        prev->next = cur->next;

        if (cur == head)
            head = cur->next;

        delete cur;
        cur = prev->next;
    }

    cout << "\nSurvivor: " << cur->data << endl;
    delete cur;

    return 0;
}