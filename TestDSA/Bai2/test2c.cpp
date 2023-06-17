void xoaNode(Node** head, int x) {
    Node* q= *head;
    Node* p= null;

    while (q != null && q->data != x) {
        p= q;
        q= q->next;
    }
    
    if (q!= nullptr) {
        if (p== nullptr) {
            *head = q-> next;
        } else {
            p->next = q->next;
        }
        delete q;
    }
}
