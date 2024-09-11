int DoublyInsert(int data, int index, dnode<int>* &Ptr) {
    dnode<int>* newNode = new dnode<int>(data); 
    dnode<int>* temp = Ptr;

    if (index == 0) {
        newNode->next = Ptr;
        if (Ptr != nullptr) {
            Ptr->prev = newNode;
        }
        Ptr = newNode; 
        return 1; 
    }

    for (int i = 0; i < index - 1; i++) {
        if (temp == nullptr) return 0; 
        temp = temp->next;
    }

    if (temp == nullptr) return 0;

    newNode->next = temp->next;
    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;

    return 1;
}
