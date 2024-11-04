#ifndef S21_LIST_H
#define S21_LIST_H

#include <iostream>

namespace s21 {
template <typename T>
class list {
 private:
  class Node {
   public:
    T data;
    Node *next;
    Node *prev;

    Node(T data) {
      this->data = data;
      this->next = nullptr;
      this->prev = nullptr;
    }
  };

  void create_fake() {
    fake = new Node(0);
    fake->next = fake;
    fake->prev = fake;
  }

  Node *head;
  Node *tail;
  Node *fake;
  size_t size_;

 public:
  list() : head(nullptr), tail(nullptr), size_(0) { create_fake(); }

  list(size_t N) : head(nullptr), tail(nullptr), size_(0) {
    if (N <= 0) throw std::out_of_range("Index out of range");
    create_fake();
    for (size_t i = 0; i < N; i++) {
      push_front(0);
    }
  }

  list(std::initializer_list<T> const &items)
      : head(nullptr), tail(nullptr), size_(0) {
    create_fake();
    for (T i : items) push_back(i);
  }

  list(const list<T> &other) : head(nullptr), tail(nullptr), size_(0) {
    create_fake();
    size_t i = 0;
    Node *ptr = other.head;
    while (i < other.size_) {
      push_back(ptr->data);
      ptr = ptr->next;
      i++;
    }
  }

  list(list<T> &&other) : head(nullptr), tail(nullptr), size_(0) {
    create_fake();
    swap(other);
  }

  ~list() {
    clear();
    delete fake;
  }

  list &operator=(const list<T> &other) {
    if (fake) {
      while (size_ >= 1) {
        pop_front();
      }
      delete fake;
    }
    head = nullptr;
    tail = nullptr;
    size_ = 0;
    create_fake();
    size_t i = 0;
    Node *ptr = other.head;
    while (i < other.size_) {
      push_back(ptr->data);
      ptr = ptr->next;
      i++;
    }
    return *this;
  }

  list &operator=(list<T> &&other) {
    if (fake) {
      while (size_ >= 1) {
        pop_front();
      }
      delete fake;
    }
    head = nullptr;
    tail = nullptr;
    size_ = 0;
    create_fake();
    swap(other);
    return *this;
  }

  void push_front(const T &data) {
    Node *new_ptr = new Node(data);
    if (size_ == 0) {
      head = new_ptr;
      head->next = fake;
      head->prev = fake;
      fake->next = head;
      fake->prev = head;
    } else if (size_ == 1) {
      tail = head;
      head = new_ptr;
      head->next = tail;
      head->prev = fake;
      tail->prev = head;
      tail->next = fake;
      fake->prev = tail;
      fake->next = head;
    } else {
      new_ptr->next = head;
      new_ptr->prev = fake;
      head->prev = new_ptr;
      fake->next = new_ptr;
      head = new_ptr;
    }
    size_++;
    fake->data++;
  }

  void push_back(const T &data) {
    Node *new_ptr = new Node(data);
    if (size_ == 0) {
      head = new_ptr;
      head->next = fake;
      head->prev = fake;
      fake->next = head;
      fake->prev = head;
    } else if (size_ == 1) {
      tail = new_ptr;
      head->next = tail;
      fake->prev = tail;
      tail->next = fake;
      tail->prev = head;
    } else {
      new_ptr->next = fake;
      new_ptr->prev = tail;
      tail->next = new_ptr;
      tail = new_ptr;
      fake->prev = tail;
    }
    size_++;
    fake->data++;
  }

  void pop_front() {
    if (size_ > 2) {
      Node *rm = head;
      head = head->next;
      fake->next = head;
      head->prev = fake;
      size_--;
      fake->data--;
      delete rm;
    } else if (size_ == 2) {
      Node *rm = head;
      head = tail;
      fake->next = head;
      fake->prev = head;
      head->prev = fake;
      head->next = fake;
      tail = nullptr;
      size_--;
      fake->data--;
      delete rm;
    } else if (size_ == 1) {
      Node *rm = head;
      head = nullptr;
      delete rm;
      fake->prev = fake;
      fake->next = fake;
      size_--;
      fake->data--;
    }
  }

  void pop_back() {
    if (size_ > 2) {
      Node *rm = tail;
      tail = tail->prev;
      tail->next = fake;
      fake->prev = tail;
      size_--;
      fake->data--;
      delete rm;
    } else if (size_ == 2) {
      Node *rm = tail;
      tail = nullptr;
      head->next = fake;
      head->prev = fake;
      fake->prev = fake;
      fake->next = head;
      size_--;
      fake->data--;
      delete rm;
    } else if (size_ == 1) {
      Node *rm = head;
      head = nullptr;
      delete rm;
      fake->prev = fake;
      fake->next = fake;
      size_--;
      fake->data--;
    }
  }

  void swap(list<T> &other) {
    Node *head_box = head;
    Node *tail_box = tail;
    Node *fake_box = fake;
    size_t size_box = size_;
    head = other.head;
    tail = other.tail;
    fake = other.fake;
    size_ = other.size_;
    other.head = head_box;
    other.tail = tail_box;
    other.size_ = size_box;
    other.fake = fake_box;
  }

  const T &front() { return head ? head->data : fake->data; }

  const T &back() { return tail ? tail->data : front(); }

  bool empty() { return (size_ == 0); }

  size_t size() { return size_; }

  size_t max_size() {
    return (std::numeric_limits<std::size_t>::max() / sizeof(Node) / 2);
  }

  void clear() {
    while (size_ >= 1) {
      pop_front();
    }
  }

  void reverse() {
    if (size_ > 1) {
      list<T> box;
      Node *ptr = head;
      size_t i = 0;
      while (i < size_) {
        box.push_front(ptr->data);
        ptr = ptr->next;
        i++;
      }
      swap(box);
    }
  }

  void merge(list<T> &other) {
    while (other.size_ > 0) {
      push_back(other.head->data);
      other.pop_front();
    }
    sort();
  }

  void unique() {
    if (size_ > 1) {
      list<T> box;
      Node *elem = head;
      Node *elem_next = head->next;
      size_t i = 0;
      while (i != size_) {
        if (elem->data == elem_next->data && elem_next != fake) {
          elem = elem_next;
          elem_next = elem_next->next;
        } else {
          box.push_back(elem->data);
          elem = elem_next;
          elem_next = elem_next->next;
        }
        i++;
      }
      *this = std::move(box);
    }
  }

  void sort() {
    if (size_ > 1) {
      list<T> box;
      while (size_ > 0) {
        Node *ptr = head;
        T min = head->data;
        Node *rm = head;
        Node *prev_min = head->prev;
        Node *next_min = head->next;
        size_t i = 0;
        while (i < size_) {
          if (ptr->data < min) {
            min = ptr->data;
            rm = ptr;
            prev_min = ptr->prev;
            next_min = ptr->next;
          }
          ptr = ptr->next;
          i++;
        }
        box.push_back(min);
        if (rm == head) {
          pop_front();
        } else if (rm == tail) {
          pop_back();
        } else {
          prev_min->next = next_min;
          next_min->prev = prev_min;
          delete rm;
          size_--;
          fake->data--;
        }
      }
      swap(box);
    }
  }

  class iterator {
    friend class list<T>;

   private:
    Node *ptr;

    void iteration(bool Plus) {
      if (Plus == true)
        ptr = ptr->next;
      else
        ptr = ptr->prev;
    }

   public:
    iterator() : ptr(nullptr){};
    iterator(Node *node) : ptr(node){};
    iterator(const iterator &other) : ptr(other.ptr){};
    ~iterator() = default;

    Node *get_node() { return ptr; }

    T &operator*() { return ptr->data; }

    bool operator==(const iterator &other) { return this->ptr == other.ptr; }

    bool operator!=(const iterator &other) { return this->ptr != other.ptr; }

    iterator &operator=(const iterator &other) noexcept {
      if (this != &other) ptr = other.ptr;
      return *this;
    }

    iterator &operator++() {
      iteration(true);
      return *this;
    }

    iterator operator++(int) {
      iterator tmp(*this);
      iteration(true);
      return tmp;
    }

    iterator &operator--() {
      iteration(false);
      return *this;
    }

    iterator operator--(int) {
      iterator tmp(*this);
      iteration(false);
      return tmp;
    }

    iterator operator+(size_t n) {
      iterator tmp(*this);
      while (n-- > 0) tmp.iteration(true);
      return tmp;
    }

    iterator operator-(size_t n) {
      iterator tmp(*this);
      while (n-- > 0) tmp.iteration(false);
      return tmp;
    }

    iterator &operator+=(size_t n) {
      while (n-- > 0) iteration(true);
      return *this;
    }

    iterator &operator-=(size_t n) {
      while (n-- > 0) iteration(false);
      return *this;
    }
  };

  class const_iterator {
    friend class list<T>;

   private:
    void iteration(bool Plus) {
      if (Plus == true)
        ptr = ptr->next;
      else
        ptr = ptr->prev;
    }

    Node *ptr;

   public:
    const_iterator() : ptr(nullptr){};
    const_iterator(Node *node) : ptr(node){};
    const_iterator(const const_iterator &other) : ptr(other.ptr){};
    const_iterator(const iterator &other) : ptr(other.ptr){};
    ~const_iterator() = default;

    Node *get_node() { return ptr; }

    const T &operator*() { return ptr->data; }

    bool operator==(const const_iterator &other) {
      return this->ptr == other.ptr;
    }

    bool operator!=(const const_iterator &other) {
      return this->ptr != other.ptr;
    }

    const_iterator &operator=(const const_iterator &other) noexcept {
      if (this != &other) ptr = other.ptr;
      return *this;
    }

    const_iterator &operator++() {
      iteration(true);
      return *this;
    }

    const_iterator operator++(int) {
      const_iterator tmp(*this);
      iteration(true);
      return tmp;
    }

    const_iterator &operator--() {
      iteration(false);
      return *this;
    }

    const_iterator operator--(int) {
      const_iterator tmp(*this);
      iteration(false);
      return tmp;
    }

    const_iterator operator+(size_t n) {
      const_iterator tmp(*this);
      while (n-- > 0) tmp.iteration(true);
      return tmp;
    }

    const_iterator operator-(size_t n) {
      const_iterator tmp(*this);
      while (n-- > 0) tmp.iteration(false);
      return tmp;
    }

    const_iterator &operator+=(size_t n) {
      while (n-- > 0) iteration(true);
      return *this;
    }

    const_iterator &operator-=(size_t n) {
      while (n-- > 0) iteration(false);
      return *this;
    }
  };

  iterator begin() {
    iterator box;
    if (head != nullptr)
      box.ptr = head;
    else
      box.ptr = fake;
    return box;
  }

  iterator end() {
    iterator box;
    box.ptr = fake;
    return box;
  }

  const_iterator cbegin() {
    const_iterator box;
    if (head != nullptr)
      box.ptr = head;
    else
      box.ptr = fake;
    return box;
  }

  const_iterator cend() {
    const_iterator box;
    box.ptr = fake;
    return box;
  }

  void insert(iterator pos, const T &value) {
    if (pos.ptr == head)
      push_front(value);
    else if (pos.ptr == fake)
      push_back(value);
    else {
      Node *position = pos.get_node();
      Node *insert = new Node(value);
      Node *position_prev = position->prev;
      insert->prev = position_prev;
      position->prev = insert;
      insert->next = position;
      position_prev->next = insert;
      size_++;
      fake->data++;
    }
  }

  void erase(iterator pos) {
    if (pos.ptr == fake)
      return;
    else if (pos.ptr == head)
      pop_front();
    else if (pos.ptr == tail)
      pop_back();
    else {
      Node *to_erase = pos.get_node();
      to_erase->prev->next = to_erase->next;
      to_erase->next->prev = to_erase->prev;
      delete to_erase;
      size_--;
      fake->data--;
    }
  }

  void splice(const_iterator pos, list<T> &other) {
    iterator pos_copy = pos.ptr;
    while (other.size_ != 0) {
      insert(pos_copy, other.front());
      other.pop_front();
    }
  }

  template <typename... Args>
  void insert_many_back(Args... args) {
    for (auto elem : {(args)...}) {
      push_back(elem);
    }
  }

  template <typename... Args>
  void insert_many_front(Args... args) {
    int count = 0;
    for (auto elem : {(args)...}) {
      iterator pos = begin() + count;
      insert(pos, elem);
      pos++;
      count++;
    }
  }

  template <typename... Args>
  iterator insert_many(const_iterator pos, Args &&...args) {
    size_t count = 0;
    while (pos != cbegin()) {
      pos--;
      count++;
    }
    pos += count;
    size_t box = count;
    for (auto elem : {(args)...}) {
      iterator copy = begin() + count;
      insert(copy, elem);
      count++;
    }
    return begin() + box;
  }
};
}  // namespace s21
#endif  // !S21_LIST_H
