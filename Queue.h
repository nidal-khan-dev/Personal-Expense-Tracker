#pragma once

template <typename T>
class Queue {
    T* data_;
    int cap_, head_, size_;

    void grow() {
        T* nd = new T[cap_ * 2];
        for (int i = 0; i < size_; ++i) nd[i] = data_[(head_ + i) % cap_];
        delete[] data_;
        data_ = nd;
        cap_ *= 2;
        head_ = 0;
    }
public:
    Queue() : data_(new T[8]), cap_(8), head_(0), size_(0) {}
    ~Queue() { delete[] data_; }
    Queue(const Queue&) = delete;
    Queue& operator=(const Queue&) = delete;

    void enqueue(const T& v) {                    
        if (size_ == cap_) grow();
        data_[(head_ + size_) % cap_] = v;
        ++size_;
    }
    bool dequeue(T& out) {                       
        if (size_ == 0) return false;
        out = data_[head_];
        head_ = (head_ + 1) % cap_;
        --size_;
        return true;
    }
    const T& at(int i) const { return data_[(head_ + i) % cap_]; }  
    int size() const { return size_; }
    bool empty() const { return size_ == 0; }
    void clear() { head_ = 0; size_ = 0; }
};
