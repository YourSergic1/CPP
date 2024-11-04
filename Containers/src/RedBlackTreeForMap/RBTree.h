#ifndef CPP2_S21_CONTAINERS_SRC_RBTREE_H_
#define CPP2_S21_CONTAINERS_SRC_RBTREE_H_

#include <iostream>

enum color { RED, BLACK };
enum position { LEFT, RIGHT, ROOT };

template <typename Key, typename Value>
class RBTree {
 protected:
  struct Node;
  Node* root;

 public:
  class Iterator;
  // Переопределение типов
  using key_type = Key;
  using value_type = Value;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = Iterator;
  using size_type = size_t;
  // Конструкторы и деструктор
  RBTree() : root(nullptr){};
  RBTree(const RBTree& other) { root = CopyNodes(other.root); };
  RBTree(RBTree&& other) noexcept;
  ~RBTree() { clear(root); };
  // Операторы копирования и перемещения
  RBTree& operator=(const RBTree& other);
  RBTree& operator=(RBTree&& other) noexcept;
  // EMPTY / SIZE
  bool empty();
  size_type size();
  size_type max_size() const {
    return std::numeric_limits<size_type>::max() / sizeof(Node) / 2;
  }
  // Втсавка и удаление в дерево
  void clear();
  void insert(Key key, Value value);
  void remove(Key key);
  void print();
  // Поиск
  Value find_value(Key key);
  RBTree<Key, Value>* search(Key key);
  Node* find(Node* root, Key key);
  Node* get_min(Node* root);
  Iterator begin() { return Iterator(root); }
  Iterator end() { return Iterator(nullptr); }
  void swap(RBTree<Key, Value>& other);
  void merge(RBTree<Key, Value>& other);
  void erase(iterator pos);

 private:
  Node* remove(Node*& root, Key key);
  void print(Node* node) const;
  void erase_case1(Node* node, Node*& root);
  void erase_case2(Node* node, Node*& root);
  void erase_case3(Node* node, Node*& root);
  void balance_fix(Node* x, int position);
  void mergeNodes(Node* node);
  void insert_balance(Node* node);
  void small_left_rotation(Node* node);
  void small_right_rotation(Node* node);
  void big_left_rotation(Node* node);
  void big_right_rotation(Node* node);
  void insert(Node*& root, Node* node);
  size_t Size(Node* node) const;
  void clear(Node*& root);
  Node* CopyNodes(Node* node);

 protected:
  struct Node {
    Key key;
    Value value;
    bool color;
    Node *left_son, *right_son, *father;
    Node(Key k, Value v, bool c)
        : key(k),
          value(v),
          color(c),
          left_son(nullptr),
          right_son(nullptr),
          father(nullptr){};
    friend class RBTree<Key, Value>;
  };

 public:
  class Iterator {
   private:
    Node* current;
    Node* minimum(Node* node) const;
    Node* maximum(Node* node) const;

   public:
    Iterator() : current(nullptr){};
    Iterator(Node* root) : current(minimum(root)){};
    Iterator& operator++();
    Iterator operator++(int);
    Iterator& operator--();
    Iterator operator--(int);
    bool operator==(const Iterator& other) const;
    bool operator!=(const Iterator& other) const;
    friend class RBTree<Key, Value>;
    Node* getCurrent() const { return this->current; };
  };
};

#include "RBTree.tpp"
#endif  // CPP2_S21_CONTAINERS_SRC_RBTREE_H_
