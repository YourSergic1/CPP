#include "RBTree.h"

// Конструкторы

template <typename Key, typename Value>
RBTree<Key, Value>::RBTree(RBTree&& other) noexcept {
  root = other.root;
  other.root = nullptr;
}

// Операторы копирования и перемещения
template <typename Key, typename Value>
RBTree<Key, Value>& RBTree<Key, Value>::operator=(const RBTree& other) {
  if (this != &other) {
    root = CopyNodes(other.root);
  }
  return *this;
}

template <typename Key, typename Value>
RBTree<Key, Value>& RBTree<Key, Value>::operator=(RBTree&& other) noexcept {
  if (this != &other) {
    this->clear();
    root = other.root;
    other.root = nullptr;
  }
  return *this;
}

// Определение размера и проверка на пустоту

template <typename Key, typename Value>
bool RBTree<Key, Value>::empty() {
  return root == nullptr;
}

template <typename Key, typename Value>
size_t RBTree<Key, Value>::size() {
  return Size(root);
}

// Вставка новой ноды в дерево
template <typename Key, typename Value>
void RBTree<Key, Value>::insert(Key key, Value value) {
  Node* z = new Node(key, value, RED);
  insert(root, z);
}

template <typename Key, typename Value>
void RBTree<Key, Value>::insert(Node*& root, Node* node) {
  Node* x = root;
  Node* y = nullptr;
  bool OK = true;
  while (x != nullptr) {
    y = x;
    if (node->key > x->key)
      x = x->right_son;
    else if (node->key < x->key)
      x = x->left_son;
    else {
      throw std::out_of_range("Нода с таким ключом уже существует");
      OK = false;
      break;
    }
  }
  if (OK) {
    node->father = y;
    if (y != nullptr) {
      if (node->key > y->key)
        y->right_son = node;
      else
        y->left_son = node;
      if (y->color == RED) insert_balance(node);
    } else {
      root = node;
      node->color = BLACK;
    }
  }
  root->color = BLACK;
}

// Балансировка при втсавке
template <typename Key, typename Value>
void RBTree<Key, Value>::insert_balance(Node* node) {
  Node* grandfather = node->father->father;
  if (grandfather->left_son && grandfather->right_son &&
      grandfather->left_son->color == RED &&
      grandfather->right_son->color == RED) {
    grandfather->color = RED;
    grandfather->left_son->color = BLACK;
    grandfather->right_son->color = BLACK;
    if (grandfather->father && grandfather->father->color == RED) {
      insert_balance(grandfather);
    }
  } else {
    if (node->father == grandfather->left_son) {
      if (node == node->father->right_son) {
        small_left_rotation(node);
        big_right_rotation(node);
      } else {
        big_right_rotation(node->father);
      }
    } else {
      if (node == node->father->left_son) {
        small_right_rotation(node);
        big_left_rotation(node);
      } else {
        big_left_rotation(node->father);
      }
    }
  }
}

// Удаление ноды
template <typename Key, typename Value>
void RBTree<Key, Value>::remove(Key key) {
  root = remove(root, key);
}

template <typename Key, typename Value>
typename RBTree<Key, Value>::Node* RBTree<Key, Value>::remove(Node*& root,
                                                              Key key) {
  Node* z = nullptr;
  int position;
  bool balance_need;
  z = find(root, key);
  if (z->father) {
    position = (z == z->father->left_son ? LEFT : RIGHT);
  } else {
    position = ROOT;
  }
  if (!z->left_son && !z->right_son) {
    erase_case1(z, root);
    if (root != nullptr)
      balance_need = true;
    else
      balance_need = false;
  } else if (!z->left_son != !z->right_son) {
    erase_case2(z, root);
    if (z->color == BLACK) {
      if (z->left_son && z->left_son->color == RED) {
        z->left_son->color = BLACK;
        balance_need = false;
      } else if (z->right_son && z->right_son->color == RED) {
        z->right_son->color = BLACK;
        balance_need = false;
      } else {
        balance_need = true;
      }
    } else {
      balance_need = false;
    }
  } else {
    erase_case3(z, root);
    balance_need = false;
  }
  if (z->color == BLACK && balance_need == true) balance_fix(z, position);
  if (z) {
    delete z;
    z = nullptr;
  }
  return root;
}

// Удаление всех нод в дереве
template <typename Key, typename Value>
void RBTree<Key, Value>::clear() {
  clear(root);
}

template <typename Key, typename Value>
void RBTree<Key, Value>::clear(Node*& root) {
  Node* node = root;
  if (node != nullptr) {
    clear(node->left_son);
    clear(node->right_son);
    delete node;
  }
  root = nullptr;
}

// Случаи, возникающие при удалении
template <typename Key, typename Value>
void RBTree<Key, Value>::erase_case1(Node* node, Node*& root) {
  if (node->father) {
    if (node == node->father->left_son) {
      node->father->left_son = nullptr;
    } else {
      node->father->right_son = nullptr;
    }
  } else {
    root = nullptr;
  }
}

template <typename Key, typename Value>
void RBTree<Key, Value>::erase_case2(Node* node, Node*& root) {
  if (node->father) {
    if (node == node->father->left_son) {
      node->father->left_son =
          (node->left_son ? node->left_son : node->right_son);
      if (node->left_son)
        node->left_son->father = node->father;
      else
        node->right_son->father = node->father;
    } else {
      node->father->right_son =
          (node->left_son ? node->left_son : node->right_son);
      if (node->left_son)
        node->left_son->father = node->father;
      else
        node->right_son->father = node->father;
    }
  } else {
    root = (node->left_son ? node->left_son : node->right_son);
    if (node->left_son) node->left_son->father = nullptr;
    if (node->right_son) node->right_son->father = nullptr;
  }
}

template <typename Key, typename Value>
void RBTree<Key, Value>::erase_case3(Node* node, Node*& root) {
  Node *x, *y = node;
  y = y->right_son;
  while (y != nullptr) {
    x = y;
    y = y->left_son;
  }
  remove(root, x->key);
  if (node->father) {
    if (node == node->father->left_son)
      node->father->left_son = x;
    else
      node->father->right_son = x;
    x->father = node->father;
    if (node->right_son) x->right_son = node->right_son;

  } else {
    root = x;
    x->father = nullptr;
  }
  if (node->left_son) {
    x->left_son = node->left_son;
    x->left_son->father = x;
  }
  if (node->right_son) {
    x->right_son = node->right_son;
    node->right_son->father = x;
  }
  x->color = node->color;
}

// Корректировка балансировки после удаления ноды
template <typename Key, typename Value>
void RBTree<Key, Value>::balance_fix(Node* node, int position) {
  Node* brother =
      (position == LEFT ? node->father->right_son : node->father->left_son);
  Node* inner_nephew = (position == LEFT ? node->father->right_son->left_son
                                         : node->father->left_son->right_son);
  Node* outer_nephew = (position == LEFT ? node->father->right_son->right_son
                                         : node->father->left_son->left_son);
  Node* father = node->father;
  if (brother->color == RED) {  // case 1 (брат удаляемой ноды красный)
    position == LEFT ? big_left_rotation(brother) : big_right_rotation(brother);
    father->color = RED;
    brother->color = BLACK;
    father->color = BLACK;
    inner_nephew->color = RED;
    if (inner_nephew->left_son && inner_nephew->left_son->color == RED)
      insert_balance(inner_nephew->left_son);
    else if (inner_nephew->right_son && inner_nephew->right_son->color == RED)
      insert_balance(inner_nephew->right_son);
  } else {  // case 2 (брат удаляемой ноды черный)
    if ((inner_nephew && outer_nephew && inner_nephew->color == RED &&
         outer_nephew->color == BLACK) ||
        (inner_nephew && !outer_nephew)) {  // case 2.1 (внутренний племянник
                                            // красный, а наружний черный)
      position == LEFT ? small_right_rotation(inner_nephew)
                       : small_left_rotation(inner_nephew);
      inner_nephew->color = BLACK;
      brother->color = RED;
      bool f_color = father->color;
      position == LEFT ? big_left_rotation(inner_nephew)
                       : big_right_rotation(inner_nephew);
      inner_nephew->color = f_color;
      father->color = BLACK;
      brother->color = BLACK;
    } else if (outer_nephew &&
               outer_nephew->color ==
                   RED) {  // case 2.2 (правый племянник красный)
      bool father_color = father->color;
      position == LEFT ? big_left_rotation(brother)
                       : big_right_rotation(brother);
      outer_nephew->color = BLACK;
      brother->color = father_color;
      father->color = BLACK;
    } else {  // case 2.3 (оба племянника черные потомки или листья)
      brother->color = RED;
      if (father->color == BLACK) {
        if (father != root) {
          if (father == father->father->right_son) {
            balance_fix(father, RIGHT);
          } else {
            balance_fix(father, LEFT);
          }
        }
      } else {
        father->color = BLACK;
      }
    }
  }
}

// Поиск значения по ключу
template <typename Key, typename Value>
Value RBTree<Key, Value>::find_value(Key key) {
  Node* node = find(root, key);
  return node->value;
}

template <typename Key, typename Value>
typename RBTree<Key, Value>::Node* RBTree<Key, Value>::find(Node* root,
                                                            Key key) {
  Node* node = root;
  Node* z = nullptr;
  while (node != nullptr) {
    if (node->key == key) {
      z = node;
      break;
    } else if (node->key < key) {
      node = node->right_son;
    } else {
      node = node->left_son;
    }
  }
  return z;
}

// COPYNODES (копирование нод)
template <typename Key, typename Value>
typename RBTree<Key, Value>::Node* RBTree<Key, Value>::CopyNodes(Node* node) {
  Node* result;
  if (!node) {
    result = nullptr;
  } else {
    Node* new_node = new Node(node->key, node->value, node->color);
    new_node->left_son = CopyNodes(node->left_son);
    new_node->right_son = CopyNodes(node->right_son);
    if (new_node->left_son) {
      new_node->left_son->father = new_node;
    }
    if (new_node->right_son) {
      new_node->right_son->father = new_node;
    }
    result = new_node;
  }
  return result;
}

// Iterator increment prefix
template <typename Key, typename Value>
typename RBTree<Key, Value>::Iterator&
RBTree<Key, Value>::Iterator::operator++() {
  if (!current) {
    throw std::out_of_range("Итератор вышел за пределы дерева");
  }

  if (current->right_son) {
    current = minimum(current->right_son);
  } else {
    Node* parent = current->father;
    while (parent && current == parent->right_son) {
      current = parent;
      parent = parent->father;
    }
    current = parent;
  }
  return *this;
}

// Iterator increment postfix
template <typename Key, typename Value>
typename RBTree<Key, Value>::Iterator RBTree<Key, Value>::Iterator::operator++(
    int) {
  Iterator temp = *this;
  ++(*this);
  return temp;
}

// Iterator decrement prefix
template <typename Key, typename Value>
typename RBTree<Key, Value>::Iterator&
RBTree<Key, Value>::Iterator::operator--() {
  if (!current) {
    throw std::out_of_range("Итератор вышел за пределы дерева");
  }
  if (current->left_son) {
    current = maximum(current->left_son);
  } else {
    Node* parent = current->father;
    while (parent && current == parent->left_son) {
      current = parent;
      parent = parent->father;
    }
    current = parent;
  }
  return *this;
}

// Iterator increment postfix
template <typename Key, typename Value>
typename RBTree<Key, Value>::Iterator RBTree<Key, Value>::Iterator::operator--(
    int) {
  Iterator temp = *this;
  --(*this);
  return temp;
}

template <typename Key, typename Value>
bool RBTree<Key, Value>::Iterator::operator==(const Iterator& other) const {
  return this->current == other.current;
}

template <typename Key, typename Value>
bool RBTree<Key, Value>::Iterator::operator!=(const Iterator& other) const {
  return !(*this == other);
}

// MINIMUM (находит ноду с минимальным ключом)
template <typename Key, typename Value>
typename RBTree<Key, Value>::Node* RBTree<Key, Value>::Iterator::minimum(
    Node* node) const {
  while (node && node->left_son) {
    node = node->left_son;
  }
  return node;
}

// MAXIMUM (находит ноду с максимальным ключом)
template <typename Key, typename Value>
typename RBTree<Key, Value>::Node* RBTree<Key, Value>::Iterator::maximum(
    Node* node) const {
  while (node && node->right_son) {
    node = node->right_son;
  }
  return node;
}

// SIZE (определение размера дерева)
template <typename Key, typename Value>
size_t RBTree<Key, Value>::Size(Node* node) const {
  if (node == nullptr) return 0;
  size_t left_joints = Size(node->left_son);
  size_t right_joints = Size(node->right_son);
  return 1 + left_joints + right_joints;
}

// SWAP
template <typename Key, typename Value>
void RBTree<Key, Value>::swap(RBTree<Key, Value>& other) {
  std::swap(root, other.root);
}

// MERGE
template <typename Key, typename Value>
void RBTree<Key, Value>::merge(RBTree<Key, Value>& other) {
  if (this == &other) return;
  mergeNodes(other.root);
  other.clear();
}

template <typename Key, typename T>
void RBTree<Key, T>::erase(iterator pos) {
  Key key = pos.getCurrent()->key;
  remove(key);
}
template <typename Key, typename T>
void RBTree<Key, T>::mergeNodes(Node* node) {
  if (node == nullptr) return;
  mergeNodes(node->left_son);
  insert(node->key, node->value);
  mergeNodes(node->right_son);
}

// Повороты
template <typename Key, typename Value>
void RBTree<Key, Value>::small_left_rotation(Node* node) {
  Node* n = node->father;
  if (n->father) {
    n->father->left_son = node;
    node->father = n->father;
  } else {
    node->father = nullptr;
    root = node;
  }
  n->father = node;
  if (node->left_son) {
    n->right_son = node->left_son;
    node->left_son->father = n;
  } else {
    n->right_son = nullptr;
  }
  node->left_son = n;
}

template <typename Key, typename Value>
void RBTree<Key, Value>::small_right_rotation(Node* node) {
  Node* n = node->father;
  if (n->father) {
    n->father->right_son = node;
    node->father = n->father;
  } else {
    node->father = nullptr;
  }
  n->father = node;
  if (node->right_son) {
    n->left_son = node->right_son;
    node->right_son->father = n;
  } else {
    n->left_son = nullptr;
  }
  node->right_son = n;
}

template <typename Key, typename Value>
void RBTree<Key, Value>::big_left_rotation(Node* node) {
  Node* n = node->father;
  if (n->father) {
    if (n == n->father->left_son)
      n->father->left_son = node;
    else
      n->father->right_son = node;
    node->father = n->father;
  } else {
    node->father = nullptr;
    root = node;
  }
  n->father = node;
  if (node->left_son) {
    n->right_son = node->left_son;
    node->left_son->father = n;
  } else {
    n->right_son = nullptr;
  }
  node->left_son = n;
  node->color = BLACK;
  n->color = RED;
}

template <typename Key, typename Value>
void RBTree<Key, Value>::big_right_rotation(Node* node) {
  Node* n = node->father;
  if (n->father) {
    if (n == n->father->left_son)
      n->father->left_son = node;
    else
      n->father->right_son = node;
    node->father = n->father;
  } else {
    node->father = nullptr;
    root = node;
  }
  n->father = node;
  if (node->right_son) {
    n->left_son = node->right_son;
    node->right_son->father = n;
  } else {
    n->left_son = nullptr;
  }
  node->right_son = n;
  node->color = BLACK;
  n->color = RED;
}

// Вывод содержимого дерева в cout
template <typename Key, typename Value>
void RBTree<Key, Value>::print() {
  if (root == nullptr) {
    std::cout << "empty RBtree\n";
  } else {
    print(root);
  }
}

template <typename Key, typename Value>
void RBTree<Key, Value>::print(Node* node) const {
  if (node) {
    if (node->father == nullptr) {
      std::cout << node->key << "(" << node->value << " "
                << (node->color == RED ? "RED" : "BLACK") << ") is root"
                << std::endl;
    } else if (node->father->left_son == node) {
      std::cout << node->key << "(" << node->value << " "
                << (node->color == RED ? "RED" : "BLACK") << ") is "
                << node->father->key << "'s "
                << "left child" << std::endl;
    } else {
      std::cout << node->key << "(" << node->value << " "
                << (node->color == RED ? "RED" : "BLACK") << ") is "
                << node->father->key << "'s "
                << "right child" << std::endl;
    }
    print(node->left_son);
    print(node->right_son);
  }
}