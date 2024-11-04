#ifndef S21_QUEUE_H
#define S21_QUEUE_H

#include <iostream>

namespace s21 {
template <typename T>
class queue {
 private:
  class Node {
   public:
    T data;
    Node *next;

    Node(T data) {
      this->data = data;
      this->next = nullptr;
    }
  };

  Node *head;
  Node *tail;
  size_t size_;

 public:
  queue() : head(nullptr), tail(nullptr), size_(0) {}

  queue(std::initializer_list<T> const &items)
      : head(nullptr), tail(nullptr), size_(0) {
    for (T i : items) push(i);
  }

  queue(const queue<T> &other) : head(nullptr), tail(nullptr), size_(0) {
    size_t i = other.size_;
    if (i > 0) {
      Node *next = other.head;
      push(next->data);
      i--;
      while (i > 0) {
        next = next->next;
        push(next->data);
        i--;
      }
    }
  }

  queue(queue<T> &&other) : head(nullptr), tail(nullptr), size_(0) {
    swap(other);
  }

  ~queue() {
    while (head) pop();
  }

  queue &operator=(const queue<T> &other) {
    if (size_ != 0) {
      while (head) pop();
    }
    size_t i = other.size_;
    if (i > 0) {
      Node *next = other.head;
      push(next->data);
      i--;
      while (i > 0) {
        next = next->next;
        push(next->data);
        i--;
      }
    }
    return *this;
  }

  queue &operator=(queue<T> &&other) {
    if (size_ != 0) {
      while (head) pop();
    }
    swap(other);
    return *this;
  }

  void pop() {
    if (head == tail) {
      delete tail;
      tail = head = nullptr;
      size_--;
    } else if (head != nullptr) {
      Node *node = head;
      head = node->next;
      delete node;
      size_--;
    }
  }

  void push(const T &data) {
    Node *node = new Node(data);
    if (head == nullptr) head = node;
    if (tail != nullptr) tail->next = node;
    tail = node;
    size_++;
  }

  bool empty() {
    bool flag = false;
    if (size_ == 0) flag = true;
    return flag;
  }

  size_t size() { return size_; }

  const T &front() {
    if (head == nullptr)
      throw std::logic_error("queue is empty");
    else
      return head->data;
  }

  const T &back() {
    if (tail == nullptr)
      throw std::logic_error("queue is empty");
    else
      return tail->data;
  }

  void swap(queue<T> &other) {
    Node *head_box = head;
    Node *tail_box = tail;
    size_t size_box = size_;
    head = other.head;
    tail = other.tail;
    size_ = other.size_;
    other.head = head_box;
    other.tail = tail_box;
    other.size_ = size_box;
  }

  template <typename... Args>
  void insert_many_back(Args... args) {
    for (auto elem : {(args)...}) {
      push(elem);
    }
  }
};
}  // namespace s21
#endif  // !S21_QUEUE_H