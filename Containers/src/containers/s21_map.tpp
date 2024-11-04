#include "s21_map.h"

namespace s21 {

// Конструкторы
template <typename Key, typename T>
map<Key, T>::map(const std::initializer_list<value_type> &items) {
  for (auto i = items.begin(); i != items.end(); ++i) {
    insert(*i);
  }
}

// Copy and Move operators (операторы копирования и перемещения)
template <typename Key, typename T>
map<Key, T> &map<Key, T>::operator=(const map &other) {
  if (this != &other) {
    RBTree<Key, T>::operator=(other);
  }
  return *this;
}

template <typename Key, typename T>
map<Key, T> &map<Key, T>::operator=(map &&other) noexcept {
  if (this != &other) {
    this->clear();
    RBTree<Key, T>::root = other.RBTree<Key, T>::root;
    other.RBTree<Key, T>::root = nullptr;
  }
  return *this;
}

// Map Element Access (методы для доступа к элементам класса)
template <typename Key, typename T>
T &map<Key, T>::at(const Key &key) {
  typename RBTree<Key, T>::Node *node =
      RBTree<Key, T>::find(RBTree<Key, T>::root, key);
  if (!node) {
    throw std::out_of_range("map не содержит элемент с таким ключом");
  }
  return node->value;
}

template <typename Key, typename T>
T &map<Key, T>::operator[](const Key &key) {
  typename RBTree<Key, T>::Node *node =
      RBTree<Key, T>::find(RBTree<Key, T>::root, key);
  if (!node) {
    this->insert(key, T());
    node = RBTree<Key, T>::find(RBTree<Key, T>::root, key);
  }
  return node->value;
}

// Map Modifiers (методы очистки, вставки, удаления, обмена и обхединения
// контейнеров)
template <typename Key, typename T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert(
    const value_type &value) {
  return insert(value.first, value.second);
}

template <typename Key, typename T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert(
    const Key &key, const T &mapped) {
  std::pair<iterator, bool> return_value;
  auto it = this->find(key);
  if (it != this->end()) {
    return_value.first = it;
    return_value.second = false;
  } else {
    RBTree<Key, T>::insert(key, mapped);
    return_value.first = find(key);
    return_value.second = true;
  }
  return return_value;
}

template <typename Key, typename T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert_or_assign(
    const Key &key, const T &mapped) {
  auto it = this->find(key);
  if (it != this->end()) {
    //    it->second = mapped;
    return {it, false};
  } else {
    return insert(key, mapped);
  }
}

template <typename Key, typename T>
bool map<Key, T>::contains(const Key &key) {
  return (this->find(key) != nullptr);
}

template <typename Key, typename T>
typename map<Key, T>::iterator map<Key, T>::find(const Key &key) {
  typename RBTree<Key, T>::Node *node =
      RBTree<Key, T>::find(RBTree<Key, T>::root, key);
  return MapIterator(node);
}
}  // namespace s21
