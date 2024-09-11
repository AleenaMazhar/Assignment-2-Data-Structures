int DoublyDelete(int index, dnode<int>* &Ptr) {
    if (Ptr == nullptr) return 0; 

    dnode<int>* temp = Ptr;

    if (index == 0) {
        Ptr = Ptr->next;
        if (Ptr != nullptr) {
            Ptr->prev = nullptr;
        }
        delete temp;
        return 1;
    }

    for (int i = 0; i < index; i++) {
        if (temp == nullptr) return 0;
        temp = temp->next;
    }

    if (temp == nullptr) return 0;

    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    }
    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }

    delete temp;
    return 1;
}
