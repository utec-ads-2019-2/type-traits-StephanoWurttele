#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;
    int cuenta=0;
    
    Node(T data) : data(data) {
        next = nullptr;
        prev = nullptr;
    }
    
    void killSelf();
};

template <typename T>
void Node<T>::killSelf() {
    if (this->next!=nullptr) {
        next->killSelf();
    }
    delete this;
}

#endif