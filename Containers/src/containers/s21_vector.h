#ifndef S21_VECTOR_H
#define S21_VECTOR_H

#include <iostream>

namespace s21 {
template <typename T>
class vector {
 private:
  T *arr;
  size_t capacity_;
  size_t size_;

 public:
  vector() : arr(nullptr), capacity_(0), size_(0) {}

  vector(size_t n) : arr(new T[n]), capacity_(n), size_(n) {
    if (arr == nullptr)
      throw std::bad_alloc();
    else {
      for (size_t i = 0; i < n; i++) arr[i] = T();
    }
  };

  vector(std::initializer_list<T> const &items)
      : arr(new T[items.size()]), capacity_(items.size()), size_(items.size()) {
    for (size_t i = 0; i < size_; i++) {
      arr[i] = *(items.begin() + i);
    }
  }

  vector(const vector &v)
      : arr(new T[v.size_]), capacity_(v.capacity_), size_(v.size_) {
    for (size_t i = 0; i < size_; i++) {
      arr[i] = v.arr[i];
    }
  }

  vector(vector &&v) : arr(v.arr), capacity_(v.capacity_), size_(v.size_) {
    v.size_ = 0;
    v.capacity_ = 0;
    v.arr = nullptr;
  }

  ~vector() {
    delete[] arr;
    arr = nullptr;
    size_ = 0;
    capacity_ = 0;
  }

  vector &operator=(vector &v) {
    if (arr != nullptr) delete[] arr;
    arr = new T[v.size_];
    capacity_ = v.capacity_;
    size_ = v.size_;
    for (size_t i = 0; i < size_; i++) {
      arr[i] = v.arr[i];
    }
    return *this;
  }

  vector &operator=(vector &&v) {
    if (arr != nullptr) delete[] arr;
    arr = v.arr;
    capacity_ = v.capacity_;
    size_ = v.size_;
    v.size_ = 0;
    v.capacity_ = 0;
    v.arr = nullptr;
    return *this;
  }

  T &operator[](size_t i) { return arr[i]; }

  T &at(size_t pos) {
    if (pos >= size_ || size_ == 0)
      throw std::out_of_range("Index out of range");
    else {
      return arr[pos];
    }
  }

  const T &front() {
    if (size_ == 0)
      throw std::out_of_range("Index out of range");
    else {
      return arr[0];
    }
  }

  const T &back() {
    if (size_ == 0)
      throw std::out_of_range("Index out of range");
    else {
      return arr[size_ - 1];
    }
  }

  T *data() { return arr; }

  class iterator {
    friend class vector<T>;

   private:
    T *ptr;

   public:
    iterator() : ptr(nullptr){};
    iterator(T *ptr_) : ptr(ptr_){};
    iterator(const iterator &other) : ptr(other.ptr){};
    ~iterator() = default;

    T &operator*() { return *ptr; }

    bool operator==(const iterator &other) { return ptr == other.ptr; }

    bool operator!=(const iterator &other) { return ptr != other.ptr; }

    iterator &operator=(const iterator &other) noexcept {
      if (this != &other) ptr = other.ptr;
      return *this;
    }

    iterator &operator++() {
      ptr++;
      return *this;
    }

    iterator operator++(int) {
      iterator tmp(*this);
      ptr++;
      return tmp;
    }

    iterator &operator--() {
      ptr--;
      return *this;
    }

    iterator operator--(int) {
      iterator tmp(*this);
      ptr--;
      return tmp;
    }

    iterator operator+(size_t n) {
      iterator tmp(*this);
      while (n-- > 0) tmp++;
      ;
      return tmp;
    }

    iterator operator-(int n) {
      iterator tmp(*this);
      while (n-- > 0) tmp--;
      return tmp;
    }

    iterator &operator+=(size_t n) {
      while (n-- > 0) ptr++;
      return *this;
    }

    iterator &operator-=(size_t n) {
      while (n-- > 0) ptr--;
      return *this;
    }

    ptrdiff_t operator-(const iterator &other) { return ptr - other.ptr; }
  };

  class const_iterator {
    friend class vector<T>;

   private:
    T *ptr;

   public:
    const_iterator() : ptr(nullptr){};
    const_iterator(T *ptr_) : ptr(ptr_){};
    const_iterator(const const_iterator &other) : ptr(other.ptr){};
    const_iterator(const iterator &other) : ptr(other.ptr){};
    ~const_iterator() = default;

    const T &operator*() { return *ptr; }

    bool operator==(const const_iterator &other) { return ptr == other.ptr; }

    bool operator!=(const const_iterator &other) { return ptr != other.ptr; }

    const_iterator &operator=(const const_iterator &other) noexcept {
      if (this != &other) ptr = other.ptr;
      return *this;
    }

    const_iterator &operator++() {
      ptr++;
      return *this;
    }

    const_iterator operator++(int) {
      const_iterator tmp(*this);
      ptr++;
      return tmp;
    }

    const_iterator &operator--() {
      ptr--;
      return *this;
    }

    const_iterator operator--(int) {
      const_iterator tmp(*this);
      ptr--;
      return tmp;
    }

    const_iterator operator+(size_t n) {
      const_iterator tmp(*this);
      while (n-- > 0) tmp++;
      ;
      return tmp;
    }

    const_iterator operator-(size_t n) {
      const_iterator tmp(*this);
      while (n-- > 0) tmp--;
      return tmp;
    }

    const_iterator &operator+=(size_t n) {
      while (n-- > 0) ptr++;
      return *this;
    }

    const_iterator &operator-=(size_t n) {
      while (n-- > 0) ptr--;
      return *this;
    }

    ptrdiff_t operator-(const const_iterator &other) { return ptr - other.ptr; }
  };

  iterator begin() { return iterator(arr); }

  iterator end() { return iterator(arr + size_); }

  const_iterator cbegin() { return const_iterator(arr); }

  const_iterator cend() { return const_iterator(arr + size_); }

  bool empty() { return size_ == 0; }

  size_t size() { return size_; }

  size_t max_size() {
    return (std::numeric_limits<std::size_t>::max() / sizeof(T) / 2);
  }

  size_t capacity() { return capacity_; }

  void reserve(size_t n) {
    if (n <= capacity_ || n == 0) return;
    if (n > max_size()) {
      throw std::out_of_range("Too large size for a new capacity");
    }
    T *newarr = new T[n];
    std::copy(arr, arr + size_, newarr);
    delete[] arr;
    arr = newarr;
    capacity_ = n;
  }

  void push_back(const T &value) {
    if (size_ == capacity_) {
      if (capacity_ == 0)
        reserve(1);
      else if (capacity_ * 2 < max_size())
        reserve(capacity_ * 2);
      else
        throw std::out_of_range(
            "The size of capacity is greater then memory for this type");
    }
    arr[size_++] = value;
  }

  void pop_back() {
    if (size_ > 0) {
      size_--;
      arr[size_] = 0;
    }
  }

  void shrink_to_fit() {
    if (size_ <= capacity_) {
      T *newarr = new T[size_];
      std::copy(arr, arr + size_, newarr);
      delete[] arr;
      arr = newarr;
      capacity_ = size_;
    }
  }

  void clear() {
    while (size_ != 0) {
      pop_back();
    }
  }

  void swap(vector &other) {
    T *arr_box = other.arr;
    size_t size_box = other.size_;
    size_t capacity_box = other.capacity_;
    other.arr = arr;
    other.size_ = size_;
    other.capacity_ = capacity_;
    arr = arr_box;
    size_ = size_box;
    capacity_ = capacity_box;
  }

  iterator insert(iterator pos, const T &value) {
    size_t iter_pos = pos - arr;
    if (iter_pos > size_)
      throw std::out_of_range("Iterator position is out of arr");
    if (size_ == capacity_) {
      if (capacity_ == 0)
        reserve(1);
      else if (capacity_ * 2 < max_size())
        reserve(capacity_ * 2);
      else
        throw std::out_of_range(
            "The size of capacity is greater then memory for this type");
    }
    iterator pos_copy = end();
    pos_copy = begin() + iter_pos;
    for (iterator i = end(); i != pos_copy; --i) {
      *i = *(i - 1);
    }
    *pos_copy = value;
    size_++;
    return pos_copy;
  }

  void erase(iterator pos) {
    if (size_ != 0) {
      size_t iter_pos = pos - begin();
      if (iter_pos > size_)
        throw std::out_of_range("Iterator position is out of arr");
      for (iterator i = pos; i != end() - 1; ++i) {
        if (i == (end() - 1)) *i = 0;
        *i = *(i + 1);
      }
      size_--;
    }
  }

  template <typename... Args>
  void insert_many_back(Args... args) {
    for (auto elem : {(args)...}) {
      push_back(elem);
    }
  }

  template <typename... Args>
  iterator insert_many(const_iterator pos, Args &&...args) {
    size_t iter_pos = pos - cbegin();
    iterator copy = begin() + iter_pos;
    for (auto elem : {(args)...}) {
      insert(copy, elem);
      copy++;
    }
    return begin() + iter_pos;
  }
};
}  // namespace s21
#endif  // !S21_VECTOR_H
