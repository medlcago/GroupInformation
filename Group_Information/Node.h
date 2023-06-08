#pragma once

template<typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T data) : data(data), next(nullptr) {}
};
