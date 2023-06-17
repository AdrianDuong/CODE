#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
struct linkedList{
    Node* head;
    LinkedList() { head = NULL; }
    void addNode(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }
    void nhap(int n) {
        int data;
        for (int i = 0; i < n; i++) {
            cin >> data;
            addNode(data);
        }
    }
    void duyet() {
        Node* curr = head;
        while(curr != NULL) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {
    linkedList list;
    int n;
    cin >> n;
    list.nhap(n);
    list.duyet();
    return 0;
}