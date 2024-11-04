#ifndef S21_ARRAY_H
#define S21_ARRAY_H

#include <iostream>

namespace s21 {
template <typename T, size_t N>
class array {
 private:
  T arr[N];
  size_t size_;

 public:
  array() : size_(N) {
    for (size_t i = 0; i < N; ++i) {
      arr[i] = 0;
    }
  }

  array(std::initializer_list<T> const &items) : size_(N) {
    for (size_t i = 0; i < N; ++i) {
      arr[i] = 0;
    }
    for (size_t i = 0; i < items.size(); i++) {
      arr[i] = *(items.begin() + i);
    }
  }

  array(const array<T, N> &a) : size_(N) { std::copy(a.arr, a.arr + N, arr); }

  array(array &&a) : size_(N) {
    std::move(a.arr, a.arr + N, arr);
    a.size_ = 0;
  }

  ~array() = default;

  array &operator=(array &a) {
    std::copy(a.arr, a.arr + N, arr);
    size_ = a.size_;
    return *this;
  }

  array &operator=(array &&a) {
    std::move(a.arr, a.arr + N, arr);
    size_ = a.size_;
    a.size_ = 0;
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
    friend class array<T, N>;

   private:
    T *ptr;

   public:
    iterator() : ptr(nullptr){};
    iterator(T *ptr_) : ptr(ptr_){};
    iterator(const iterator &other) : ptr(other.ptr){};
    ~iterator() = default;

    const T &operator*() { return *ptr; }

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
    friend class array<T, N>;

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

  size_t max_size() { return size_; }

  void swap(array &other) {
    T arr_box[N];
    for (size_t i = 0; i < N; i++) arr_box[i] = other.arr[i];
    size_t size_box = other.size_;
    for (size_t i = 0; i < N; i++) other.arr[i] = arr[i];
    other.size_ = size_;
    for (size_t i = 0; i < N; i++) arr[i] = arr_box[i];
    size_ = size_box;
  }

  void fill(const T &value) {
    for (size_t i = 0; i < N; ++i) {
      arr[i] = value;
    }
  }
};
}  // namespace s21
#endif  // !S21_ARRAY_H
