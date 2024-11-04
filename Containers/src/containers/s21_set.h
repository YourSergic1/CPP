#ifndef S21_SET_H
#define S21_SET_H

#include "../RedBlackTreeForSet/RedBlackTreeSet.h"

namespace s21 {
template <typename Key>
class set {
  using key_type = Key;
  using value_type = Key;
  using reference = value_type &;
  using const_reference = const value_type &;
  using RedBlackTreeType = RedBlackTree<Key>;
  using size_type = std::size_t;

 public:
  using iterator = typename RedBlackTreeType::const_iterator;
  using const_iterator = typename RedBlackTreeType::const_iterator;

 public: /* Member functions */
  set() = default;

  explicit set(std::initializer_list<value_type> const &items) {
    for (const auto &item : items) insert(item);
  };

  set(const set &s) { copy_from(s); }

  set(set &&s) noexcept { this->RBT_ = std::move(s.RBT_); }

  ~set() = default;

  set<Key> &operator=(const set &s) {
    if (this != &s) copy_from(s);
    return *this;
  }

  set<Key> &operator=(set &&s) noexcept {
    if (this != &s) {
      this->RBT_.Clear();
      this->RBT_ = std::move(s.RBT_);
    }
    return *this;
  }

 public: /* Set Iterators */
  iterator begin() { return RBT_.begin(); }

  const_iterator begin() const { return RBT_.begin(); }

  iterator end() { return RBT_.end(); }

  const_iterator end() const { return RBT_.end(); }

 public: /* Set Capacity */
  [[nodiscard]] bool empty() const { return RBT_.IsEmpty(); }

  [[nodiscard]] size_t size() const { return RBT_.GetSize(); }

  [[nodiscard]] size_t max_size() const { return RBT_.GetMaxSize(); }

 public: /* Modifiers */
  void clear() { RBT_.Clear(); }

  std::pair<iterator, bool> insert(const value_type &value) {
    std::pair<iterator, bool> result{};
    result.first = this->find(value);
    if (result.first == this->end()) {
      result.first = this->RBT_.Insert(value);
      result.second = true;
    }
    return result;
  }

  void erase(const value_type &value) { RBT_.Remove(value); }

  void swap(set &other) { std::swap(RBT_, other.RBT_); }

  void merge(set &other) {
    for (const auto &item : other) insert(item);
    other.clear();
  }

  template <typename... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args &&...args) {
    std::initializer_list<value_type> items = {std::forward<Args>(args)...};
    std::vector<std::pair<iterator, bool>> result(items.size());
    std::transform(items.begin(), items.end(), result.begin(),
                   [this](const_reference item) { return this->insert(item); });
    return result;
  }

 public: /* Set Lookup */
  [[nodiscard]] iterator find(const value_type &value) const {
    Node<Key> *node = RBT_.Search(value);
    return (node == nullptr) ? end() : iterator(node, RBT_.GetNil());
  }

  [[nodiscard]] bool contains(const value_type &value) const {
    return RBT_.Search(value) != nullptr;
  }

 private: /* Helper */
  void copy_from(const set &other) {
    for (iterator cur = other.begin(); cur != other.end(); ++cur) insert(*cur);
  }

 protected:
  RedBlackTreeType RBT_;
};

}  // namespace s21

#endif  // S21_SET_H
