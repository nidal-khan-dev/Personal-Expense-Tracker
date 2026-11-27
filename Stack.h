#pragma once

template <typename T>
class Stack {
    struct Node { T data; Node* next; Node(const T& d, Node* n) : data(d), next(n) {} };
    Node* top_;
    int size_;
public:
    Stack() : top_(nullptr), size_(0) {}
    ~Stack() { clear(); }
    Stack(const Stack&) = delete;
    Stack& operator=(const Stack&) = delete;

    void push(const T& v) { top_ = new Node(v, top_); ++size_; }   
    bool pop(T& out) {                                             
        if (!top_) return false;
        Node* n = top_;
        out = n->data;
        top_ = n->next;
        delete n;
        --size_;
        return true;
    }
    bool empty() const { return top_ == nullptr; }
    int size() const { return size_; }
    void clear() { T tmp; while (pop(tmp)) {} }
};
