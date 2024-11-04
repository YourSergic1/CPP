#ifndef S21_MULTISET_H
#define S21_MULTISET_H

#include "../RedBlackTreeForSet/RedBlackTreeSet.h"

namespace s21 {
template <typename Key>
class multiset {
  using key_type = Key;
  using value_type = Key;
  using reference = value_type &;
  using const_reference = const value_type &;
  using RedBlackTreeType = RedBlackTree<Key>;
  using size_type = std::size_t;

 public:
  using iterator = typename RedBlackTreeType::const_iterator;
  using const_iterator = typename RedBlackTreeType::const_iterator;

 public: /* Set Member functions */
  multiset() = default;

  explicit multiset(std::initializer_list<value_type> const &items) {
    for (const auto &item : items) insert(item);
  };

  multiset(const multiset &s) { copy_from(s); }

  multiset(multiset &&s) noexcept { this->RBT_ = std::move(s.RBT_); }

  multiset<Key> &operator=(const multiset &s) {
    if (this != &s) copy_from(s);
    return *this;
  }

  multiset<Key> &operator=(multiset &&s) noexcept {
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

 public: /* Capacity */
  [[nodiscard]] bool empty() const { return RBT_.IsEmpty(); }

  [[nodiscard]] size_t size() const { return RBT_.GetSize(); }

  [[nodiscard]] size_t max_size() const { return RBT_.GetMaxSize(); }

 public: /* Modifiers */
  void clear() { RBT_.Clear(); }

  iterator insert(const value_type &value) { return this->RBT_.Insert(value); }

  void erase(const value_type &value) { RBT_.Remove(value); }

  void swap(multiset &other) { std::swap(RBT_, other.RBT_); }

  void merge(multiset &other) {
    for (const auto &item : other) insert(item);
    other.clear();
  }

  template <typename... Args>
  std::vector<iterator> insert_many(Args &&...args) {
    std::initializer_list<value_type> items = {std::forward<Args>(args)...};
    std::vector<iterator> result(items.size());
    std::transform(items.begin(), items.end(), result.begin(),
                   [this](const_reference item) { return insert(item); });
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

 public: /* Helper */
  std::pair<iterator, iterator> equal_range(const value_type &data) const {
    auto lower = lower_bound(data);
    auto upper = upper_bound(data);
    return {lower, upper};
  }

  iterator lower_bound(const value_type &data) const {
    return this->RBT_.GetLowerBoundIterator(data);
  }

  iterator upper_bound(const value_type &data) const {
    return this->RBT_.GetUpperBoundIterator(data);
  }

  void copy_from(const multiset &other) {
    for (iterator cur = other.begin(); cur != other.end(); ++cur) insert(*cur);
  }

 protected:
  RedBlackTreeType RBT_;
};
}  // namespace s21
#endif  // S21_MULTISET_H