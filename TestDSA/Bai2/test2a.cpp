#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* next;
};

struct linkedList{
    node* head;
    linkedList() { head = NULL; }
    void addnode() {
        int data;
        Node* newNode = new node();
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }
    void nhap(int n) {
        int data;
        for (int i=0; i<n; i++) {
            cin>>data;
            addnode(data);
        }
    }
    void in() {
        node* curr = head;
        while(curr!=NULL) {
            cout<<curr->data<<" ";
            curr=curr->next;
        }
        cout<<endl;
    }
};
int main() {
    linkedList list;
    int n;
    cin >> n;
    list.nhap(n);
    list.in();
    return 0;
}



