#ifndef S21_STACK_H
#define S21_STACK_H

#include <iostream>

namespace s21 {
template <typename T>
class stack {
 private:
  class Node {
   public:
    T data;
    Node *prev;

    Node(T data) {
      this->data = data;
      this->prev = nullptr;
    }
  };

  Node *top_;
  size_t size_;

 public:
  stack() : top_(nullptr), size_(0) {}

  stack(std::initializer_list<T> const &items) : top_(nullptr), size_(0) {
    for (T i : items) push(i);
  }

  stack(const stack<T> &other) : top_(nullptr), size_(0) {
    stack<T> temp;
    Node *current = other.top_;
    while (current != nullptr) {
      temp.push(current->data);
      current = current->prev;
    }
    while (!temp.empty()) {
      push(temp.top());
      temp.pop();
    }
  }

  stack(stack<T> &&other) : top_(nullptr), size_(0) { swap(other); }

  ~stack() {
    while (top_) pop();
  }

  stack &operator=(const stack<T> &other) {
    if (size_ != 0) {
      while (top_) pop();
    }
    stack<T> temp;
    Node *current = other.top_;
    while (current != nullptr) {
      temp.push(current->data);
      current = current->prev;
    }
    while (!temp.empty()) {
      push(temp.top());
      temp.pop();
    }
    return *this;
  }

  stack &operator=(stack<T> &&other) {
    if (size_ != 0) {
      while (top_) pop();
    }
    swap(other);
    return *this;
  }

  const T &top() {
    if (!top_) throw std::logic_error("queue is empty");
    return top_->data;
  }

  bool empty() {
    bool flag = false;
    if (size_ == 0) flag = true;
    return flag;
  }

  size_t size() { return size_; }

  void push(const T &data) {
    Node *node = new Node(data);
    if (!top_)
      top_ = node;
    else {
      node->prev = top_;
      top_ = node;
    }
    ++size_;
  }

  void pop() {
    if (top_ != nullptr) {
      Node *node = top_->prev;
      delete top_;
      top_ = node;
      --size_;
    }
  }

  void swap(stack<T> &other) {
    Node *top = top_;
    size_t size = size_;
    top_ = other.top_;
    size_ = other.size_;
    other.top_ = top;
    other.size_ = size;
  }

  template <typename... Args>
  void insert_many_back(Args... args) {
    for (auto elem : {(args)...}) {
      push(elem);
    }
  }
};

}  // namespace s21
#endif  // !S21_STACK_H