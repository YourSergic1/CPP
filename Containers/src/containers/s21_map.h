#ifndef S21_MAP_H
#define S21_MAP_H

#include "../RedBlackTreeForMap/RBTree.h"

namespace s21 {

template <typename Key, typename T>
class map : public RBTree<Key, T> {
 public:
  class MapIterator;
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = MapIterator;
  using size_type = size_t;

  // Конструкторы и деструктор
  map() : RBTree<Key, T>(){};
  map(std::initializer_list<value_type> const &items);
  map(const map &other) : RBTree<Key, T>(other){};
  map(map &&other) noexcept : RBTree<Key, T>(std::move(other)){};
  ~map() = default;

  // Операторы копирования и перемещения
  map &operator=(const map &other);
  map &operator=(map &&other) noexcept;

  // Map Element Access (методы для доступа к элементам класса)
  T &at(const Key &key);
  T &operator[](const Key &key);

  // Map Modifiers (методы для изменения контейнера)
  std::pair<iterator, bool> insert(const value_type &value);
  std::pair<iterator, bool> insert(const Key &key, const T &mapped);
  std::pair<iterator, bool> insert_or_assign(const Key &key, const T &obj);

  // Map Lookup (методы, осуществляющие просмотр контейнер)
  bool contains(const Key &key);
  iterator find(const Key &key);

  class MapIterator : public RBTree<Key, T>::Iterator {
   public:
    friend class map;
    MapIterator() : RBTree<Key, T>::Iterator(){};
    MapIterator(typename RBTree<Key, T>::Node *node)
        : RBTree<Key, T>::Iterator(node){};
  };
};

}  // namespace s21

#include "s21_map.tpp"

#endif  // S21_MAP_H
