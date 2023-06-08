#pragma once
#include "Node.h"

template<typename T>
class LinkedList {
public:
    Node<T>* head;
    Node<T>* tail;
    int size;

    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void push_front(T data);
    void push_back(T data);
    void pop_front();
    void pop_back();
    T& operator[](int k);
    void erase(int k);
    void resize(int newSize, T value = T());
    int getSize() const;
    T& getAt(int k);
    void print();
};

template<typename T>
void LinkedList<T>::push_front(T data) {
    Node<T>* newNode = new Node<T>(data);
    newNode->next = head;
    head = newNode;
    if (tail == nullptr) {
        tail = newNode;
    }
    size++;
}

template<typename T>
void LinkedList<T>::push_back(T data) {
    Node<T>* newNode = new Node<T>(data);
    if (tail == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

template<typename T>
void LinkedList<T>::pop_front() {
    if (head == nullptr) {
        throw std::runtime_error("List is empty");
    }
    Node<T>* temp = head;
    head = head->next;
    if (head == nullptr) {
        tail = nullptr;
    }
    delete temp;
    size--;
}

template<typename T>
void LinkedList<T>::pop_back() {
    if (tail == nullptr) {
        throw std::runtime_error("List is empty");
    }
    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else {
        Node<T>* current = head;
        while (current->next != tail) {
            current = current->next;
        }
        delete tail;
        current->next = nullptr;
        tail = current;
    }
    size--;
}

template<typename T>
T& LinkedList<T>::operator[](int k) {
    return getAt(k);
}

template<typename T>
void LinkedList<T>::erase(int k) {
    if (k < 0 || k >= size) {
        throw std::out_of_range("Index out of range");
    }
    if (k == 0) {
        pop_front();
        return;
    }
    Node<T>* current = head;
    for (int i = 0; i < k - 1; i++) {
        current = current->next;
    }
    Node<T>* temp = current->next;
    current->next = temp->next;
    if (temp == tail) {
        tail = current;
    }
    delete temp;
    size--;
}

template<typename T>
void LinkedList<T>::resize(int newSize, T value) {
    if (newSize < 0) {
        throw std::invalid_argument("New size must be non-negative");
    }
    while (size < newSize) {
        push_back(value);
    }
    while (size > newSize) {
        pop_back();
    }
}

template<typename T>
int LinkedList<T>::getSize() const {
    return size;
}

template<typename T>
T& LinkedList<T>::getAt(int k) {
    if (k < 0 || k >= size) {
        throw std::out_of_range("Index out of range");
    }
    Node<T>* current = head;
    for (int i = 0; i < k; i++) {
        current = current->next;
    }
    return current->data;
}

template<typename T>
void LinkedList<T>::print() {
    Node<T>* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
