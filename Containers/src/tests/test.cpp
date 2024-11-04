#include <gtest/gtest.h>

#include <array>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

#include "../containers/s21_containers.h"
#include "../containers_plus/s21_containersplus.h"

struct test_struct {
  int num;
  char letter;
};

TEST(QUEUE, DefaultConstructor) {
  s21::queue<int> our_queue;
  std::queue<int> std_queue;
  EXPECT_EQ(our_queue.empty(), std_queue.empty());
}

TEST(QUEUE, ListConstructor) {
  std::initializer_list<int> il = {1, 2, 3, 4, 5};
  s21::queue<int> our_queue{il};
  std::queue<int> std_queue{il};
  EXPECT_EQ(our_queue.front(), std_queue.front());
  our_queue.pop();
  std_queue.pop();
  EXPECT_EQ(our_queue.front(), std_queue.front());
  our_queue.pop();
  std_queue.pop();
  EXPECT_EQ(our_queue.front(), std_queue.front());
  our_queue.pop();
  std_queue.pop();
  EXPECT_EQ(our_queue.front(), std_queue.front());
  our_queue.pop();
  std_queue.pop();
  EXPECT_EQ(our_queue.front(), std_queue.front());
  our_queue.pop();
  std_queue.pop();
  EXPECT_EQ(our_queue.empty(), std_queue.empty());
}

TEST(QUEUE, CopyConstructor) {
  std::initializer_list<int> il = {1, 2, 3};
  s21::queue<int> our_queue{il};
  std::queue<int> std_queue{il};
  s21::queue<int> our_queue_copy(our_queue);
  std::queue<int> std_queue_copy(std_queue);

  EXPECT_EQ(our_queue_copy.front(), std_queue_copy.front());
  our_queue_copy.pop();
  std_queue_copy.pop();
  EXPECT_EQ(our_queue_copy.front(), std_queue_copy.front());
  our_queue_copy.pop();
  std_queue_copy.pop();
  EXPECT_EQ(our_queue_copy.front(), std_queue_copy.front());
  our_queue_copy.pop();
  std_queue_copy.pop();
  EXPECT_EQ(our_queue_copy.empty(), std_queue_copy.empty());
}

TEST(QUEUE, MoveConstructor) {
  std::initializer_list<int> il = {1, 2, 3};
  s21::queue<int> our_queue{il};
  std::queue<int> std_queue{il};
  s21::queue<int> our_queue_copy(std::move(our_queue));
  std::queue<int> std_queue_copy(std::move(std_queue));
  EXPECT_EQ(our_queue.empty(), std_queue.empty());

  EXPECT_EQ(our_queue_copy.front(), std_queue_copy.front());
  our_queue_copy.pop();
  std_queue_copy.pop();
  EXPECT_EQ(our_queue_copy.front(), std_queue_copy.front());
  our_queue_copy.pop();
  std_queue_copy.pop();
  EXPECT_EQ(our_queue_copy.front(), std_queue_copy.front());
  our_queue_copy.pop();
  std_queue_copy.pop();
  EXPECT_EQ(our_queue_copy.empty(), std_queue_copy.empty());
}

TEST(QUEUE, CopyEqualConstructor) {
  std::initializer_list<int> il = {1, 2, 3};
  std::initializer_list<int> il2 = {1, 1, 1};
  s21::queue<int> our_queue{il};
  std::queue<int> std_queue{il};
  s21::queue<int> our_queue_copy{il2};
  our_queue_copy = our_queue;
  std::queue<int> std_queue_copy{il2};
  std_queue_copy = std_queue;

  EXPECT_EQ(our_queue_copy.front(), std_queue_copy.front());
  our_queue_copy.pop();
  std_queue_copy.pop();
  EXPECT_EQ(our_queue_copy.front(), std_queue_copy.front());
  our_queue_copy.pop();
  std_queue_copy.pop();
  EXPECT_EQ(our_queue_copy.front(), std_queue_copy.front());
  our_queue_copy.pop();
  std_queue_copy.pop();
  EXPECT_EQ(our_queue_copy.empty(), std_queue_copy.empty());
}

TEST(QUEUE, MoveEqualConstructor) {
  std::initializer_list<int> il = {1, 2, 3};
  std::initializer_list<int> il2 = {1, 1, 1};
  s21::queue<int> our_queue{il};
  std::queue<int> std_queue{il};
  s21::queue<int> our_queue_copy{il2};
  our_queue_copy = std::move(our_queue);
  std::queue<int> std_queue_copy{il2};
  std_queue_copy = std::move(std_queue);
  EXPECT_EQ(our_queue.empty(), std_queue.empty());

  EXPECT_EQ(our_queue_copy.front(), std_queue_copy.front());
  our_queue_copy.pop();
  std_queue_copy.pop();
  EXPECT_EQ(our_queue_copy.front(), std_queue_copy.front());
  our_queue_copy.pop();
  std_queue_copy.pop();
  EXPECT_EQ(our_queue_copy.front(), std_queue_copy.front());
  our_queue_copy.pop();
  std_queue_copy.pop();
  EXPECT_EQ(our_queue_copy.empty(), std_queue_copy.empty());
}

TEST(QUEUE, Size) {
  std::initializer_list<int> il = {};
  std::initializer_list<int> il2 = {1, 1};
  std::initializer_list<int> il3 = {1, 1, 1};
  s21::queue<int> our_queue{il};
  std::queue<int> std_queue{il};
  s21::queue<int> our_queue2{il2};
  std::queue<int> std_queue2{il2};
  s21::queue<int> our_queue3{il3};
  std::queue<int> std_queue3{il3};

  EXPECT_EQ(our_queue.size(), std_queue.size());
  EXPECT_EQ(our_queue2.size(), std_queue2.size());
  EXPECT_EQ(our_queue3.size(), std_queue3.size());
}

TEST(QUEUE, Empty) {
  s21::queue<int> our_queue;
  std::queue<int> std_queue;

  EXPECT_EQ(our_queue.empty(), std_queue.empty());
}

TEST(QUEUE, NotEmpty) {
  s21::queue<int> our_queue;
  our_queue.push(1);
  std::queue<int> std_queue;
  std_queue.push(1);
  EXPECT_EQ(our_queue.empty(), std_queue.empty());
}

TEST(QUEUE, PushAndPop) {
  s21::queue<int> our_queue;
  our_queue.push(1);
  std::queue<int> std_queue;
  std_queue.push(1);
  EXPECT_EQ(our_queue.front(), std_queue.front());
  std_queue.pop();
  our_queue.pop();
  EXPECT_EQ(our_queue.empty(), std_queue.empty());
}

TEST(QUEUE, FrontAndBack) {
  s21::queue<int> our_queue;
  our_queue.push(1);
  our_queue.push(2);
  our_queue.push(3);
  std::queue<int> std_queue;
  std_queue.push(1);
  std_queue.push(2);
  std_queue.push(3);
  EXPECT_EQ(our_queue.front(), std_queue.front());
  EXPECT_EQ(our_queue.back(), std_queue.back());
}

TEST(QUEUE, InsertManyBack) {
  s21::queue<int> our_queue;
  our_queue.insert_many_back(1, 2, 3);
  std::queue<int> std_queue;
  std_queue.push(1);
  std_queue.push(2);
  std_queue.push(3);

  EXPECT_EQ(our_queue.front(), std_queue.front());
  our_queue.pop();
  std_queue.pop();
  EXPECT_EQ(our_queue.front(), std_queue.front());
  our_queue.pop();
  std_queue.pop();
  EXPECT_EQ(our_queue.front(), std_queue.front());
  our_queue.pop();
  std_queue.pop();
  EXPECT_EQ(our_queue.empty(), std_queue.empty());
}

TEST(QUEUE, Swap) {
  std::initializer_list<int> il = {1, 1, 1};
  std::initializer_list<int> il2 = {2, 2, 2};
  s21::queue<int> our_queue{il};
  std::queue<int> std_queue{il};
  s21::queue<int> our_queue2{il2};
  std::queue<int> std_queue2{il2};
  our_queue.swap(our_queue2);
  std_queue.swap(std_queue2);

  EXPECT_EQ(our_queue.front(), std_queue.front());
  our_queue.pop();
  std_queue.pop();
  EXPECT_EQ(our_queue.front(), std_queue.front());
  our_queue.pop();
  std_queue.pop();
  EXPECT_EQ(our_queue.front(), std_queue.front());
  our_queue.pop();
  std_queue.pop();
  EXPECT_EQ(our_queue.empty(), std_queue.empty());
}

TEST(STACK, DefaultConstructor) {
  s21::stack<int> our_stack;
  std::queue<int> std_stack;
  EXPECT_EQ(our_stack.empty(), std_stack.empty());
}

TEST(STACK, ListConstructor) {
  std::initializer_list<int> il = {1, 2, 3, 4, 5};
  s21::stack<int> our_stack{il};
  std::stack<int> std_stack{il};
  EXPECT_EQ(our_stack.top(), std_stack.top());
  our_stack.pop();
  std_stack.pop();
  EXPECT_EQ(our_stack.top(), std_stack.top());
  our_stack.pop();
  std_stack.pop();
  EXPECT_EQ(our_stack.top(), std_stack.top());
  our_stack.pop();
  std_stack.pop();
  EXPECT_EQ(our_stack.top(), std_stack.top());
  our_stack.pop();
  std_stack.pop();
  EXPECT_EQ(our_stack.top(), std_stack.top());
  our_stack.pop();
  std_stack.pop();
  EXPECT_EQ(our_stack.empty(), std_stack.empty());
}

TEST(STACK, CopyConstructor) {
  std::initializer_list<int> il = {1, 2, 3};
  s21::stack<int> our_stack{il};
  std::stack<int> std_stack{il};
  s21::stack<int> our_stack_copy(our_stack);
  std::stack<int> std_stack_copy(std_stack);

  EXPECT_EQ(our_stack_copy.top(), std_stack_copy.top());
  our_stack_copy.pop();
  std_stack_copy.pop();
  EXPECT_EQ(our_stack_copy.top(), std_stack_copy.top());
  our_stack_copy.pop();
  std_stack_copy.pop();
  EXPECT_EQ(our_stack_copy.top(), std_stack_copy.top());
  our_stack_copy.pop();
  std_stack_copy.pop();
  EXPECT_EQ(our_stack_copy.empty(), std_stack_copy.empty());
}

TEST(STACK, MoveConstructor) {
  std::initializer_list<int> il = {1, 2, 3};
  s21::stack<int> our_stack{il};
  std::stack<int> std_stack{il};
  s21::stack<int> our_stack_copy(std::move(our_stack));
  std::stack<int> std_stack_copy(std::move(std_stack));

  EXPECT_EQ(our_stack_copy.top(), std_stack_copy.top());
  our_stack_copy.pop();
  std_stack_copy.pop();
  EXPECT_EQ(our_stack_copy.top(), std_stack_copy.top());
  our_stack_copy.pop();
  std_stack_copy.pop();
  EXPECT_EQ(our_stack_copy.top(), std_stack_copy.top());
  our_stack_copy.pop();
  std_stack_copy.pop();
  EXPECT_EQ(our_stack_copy.empty(), std_stack_copy.empty());
}

TEST(STACK, CopyEqualConstructor) {
  std::initializer_list<int> il = {1, 2, 3};
  s21::stack<int> our_stack{il};
  std::stack<int> std_stack{il};
  s21::stack<int> our_stack_copy;
  our_stack_copy = our_stack;
  std::stack<int> std_stack_copy;
  std_stack_copy = std_stack;

  EXPECT_EQ(our_stack_copy.top(), std_stack_copy.top());
  our_stack_copy.pop();
  std_stack_copy.pop();
  EXPECT_EQ(our_stack_copy.top(), std_stack_copy.top());
  our_stack_copy.pop();
  std_stack_copy.pop();
  EXPECT_EQ(our_stack_copy.top(), std_stack_copy.top());
  our_stack_copy.pop();
  std_stack_copy.pop();
  EXPECT_EQ(our_stack_copy.empty(), std_stack_copy.empty());
}

TEST(STACK, MoveEqualConstructor) {
  std::initializer_list<int> il = {1, 2, 3};
  s21::stack<int> our_stack{il};
  std::stack<int> std_stack{il};
  s21::stack<int> our_stack_copy;
  our_stack_copy = std::move(our_stack);
  std::stack<int> std_stack_copy;
  std_stack_copy = std::move(std_stack);

  EXPECT_EQ(our_stack_copy.top(), std_stack_copy.top());
  our_stack_copy.pop();
  std_stack_copy.pop();
  EXPECT_EQ(our_stack_copy.top(), std_stack_copy.top());
  our_stack_copy.pop();
  std_stack_copy.pop();
  EXPECT_EQ(our_stack_copy.top(), std_stack_copy.top());
  our_stack_copy.pop();
  std_stack_copy.pop();
  EXPECT_EQ(our_stack_copy.empty(), std_stack_copy.empty());
}

TEST(Stack, Size) {
  std::initializer_list<int> il = {};
  std::initializer_list<int> il2 = {1, 1};
  std::initializer_list<int> il3 = {1, 1, 1};
  s21::stack<int> our_stack{il};
  std::stack<int> std_stack{il};
  s21::stack<int> our_stack2{il2};
  std::stack<int> std_stack2{il2};
  s21::stack<int> our_stack3{il3};
  std::stack<int> std_stack3{il3};

  EXPECT_EQ(our_stack.size(), std_stack.size());
  EXPECT_EQ(our_stack2.size(), std_stack2.size());
  EXPECT_EQ(our_stack3.size(), std_stack3.size());
}

TEST(STACK, Empty) {
  s21::stack<int> our_stack;
  std::stack<int> std_stack;

  EXPECT_EQ(our_stack.empty(), std_stack.empty());
}

TEST(STACK, NotEmpty) {
  s21::stack<int> our_stack;
  our_stack.push(1);
  std::stack<int> std_stack;
  std_stack.push(1);
  EXPECT_EQ(our_stack.empty(), std_stack.empty());
}

TEST(STACK, PushAndPop) {
  s21::stack<int> our_stack;
  our_stack.push(1);
  std::stack<int> std_stack;
  std_stack.push(1);
  EXPECT_EQ(our_stack.top(), std_stack.top());
  std_stack.pop();
  our_stack.pop();
  EXPECT_EQ(our_stack.empty(), std_stack.empty());
}

TEST(STACK, Top) {
  s21::stack<int> our_stack;
  our_stack.push(1);
  our_stack.push(2);
  our_stack.push(3);
  std::stack<int> std_stack;
  std_stack.push(1);
  std_stack.push(2);
  std_stack.push(3);
  EXPECT_EQ(our_stack.top(), std_stack.top());
}

TEST(STACK, InsertManyBack) {
  s21::stack<int> our_stack;
  our_stack.insert_many_back(1, 2, 3);
  std::stack<int> std_stack;
  std_stack.push(1);
  std_stack.push(2);
  std_stack.push(3);

  EXPECT_EQ(our_stack.top(), std_stack.top());
  our_stack.pop();
  std_stack.pop();
  EXPECT_EQ(our_stack.top(), std_stack.top());
  our_stack.pop();
  std_stack.pop();
  EXPECT_EQ(our_stack.top(), std_stack.top());
  our_stack.pop();
  std_stack.pop();
  EXPECT_EQ(our_stack.empty(), std_stack.empty());
}

TEST(STACK, Swap) {
  std::initializer_list<int> il = {1, 1, 1};
  std::initializer_list<int> il2 = {2, 2, 2};
  s21::stack<int> our_stack{il};
  std::stack<int> std_stack{il};
  s21::stack<int> our_stack2{il2};
  std::stack<int> std_stack2{il2};
  our_stack.swap(our_stack2);
  std_stack.swap(std_stack2);

  EXPECT_EQ(our_stack.top(), std_stack.top());
  our_stack.pop();
  std_stack.pop();
  EXPECT_EQ(our_stack.top(), std_stack.top());
  our_stack.pop();
  std_stack.pop();
  EXPECT_EQ(our_stack.top(), std_stack.top());
  our_stack.pop();
  std_stack.pop();
  EXPECT_EQ(our_stack.empty(), std_stack.empty());
}

TEST(LIST, EmptyConstructor) {
  s21::list<int> our_list;
  std::list<int> std_list;

  EXPECT_EQ(our_list.empty(), std_list.empty());
}

TEST(LIST, SizedConstructor) {
  s21::list<int> our_list(4);
  std::list<int> std_list(4);

  EXPECT_EQ(our_list.size(), std_list.size());
}

TEST(LIST, ListConstructor) {
  std::initializer_list<int> box = {1, 2, 3, 4, 5};
  s21::list<int> our_list(box);
  std::list<int> std_list(box);

  EXPECT_EQ(our_list.size(), std_list.size());
  while (our_list.size() > 0) {
    EXPECT_EQ(our_list.front(), std_list.front());
    our_list.pop_front();
    std_list.pop_front();
  }
}

TEST(LIST, CopyConstructor) {
  std::initializer_list<int> box = {1, 2, 3, 4, 5};
  s21::list<int> our_list1(box);
  std::list<int> std_list1(box);
  s21::list<int> our_list2(our_list1);
  std::list<int> std_list2(std_list1);

  EXPECT_EQ(our_list2.size(), std_list2.size());
  while (our_list2.size() > 0) {
    EXPECT_EQ(our_list2.front(), std_list2.front());
    our_list2.pop_front();
    std_list2.pop_front();
  }
}

TEST(LIST, MoveConstructor) {
  std::initializer_list<int> box = {1, 2, 3, 4, 5};
  s21::list<int> our_list1(box);
  std::list<int> std_list1(box);
  s21::list<int> our_list2(std::move(our_list1));
  std::list<int> std_list2(std::move(std_list1));

  EXPECT_EQ(our_list1.empty(), std_list1.empty());
  EXPECT_EQ(our_list2.size(), std_list2.size());
  while (our_list2.size() > 0) {
    EXPECT_EQ(our_list2.front(), std_list2.front());
    our_list2.pop_front();
    std_list2.pop_front();
  }
}

TEST(LIST, EqualListCopy) {
  std::initializer_list<int> box = {1, 2, 3, 4, 5};
  s21::list<int> our_list1(box);
  std::list<int> std_list1(box);
  s21::list<int> our_list2(2);
  our_list2 = our_list1;
  std::list<int> std_list2(2);
  std_list2 = std_list1;

  EXPECT_EQ(our_list2.size(), std_list2.size());
  while (our_list2.size() > 0) {
    EXPECT_EQ(our_list2.front(), std_list2.front());
    our_list2.pop_front();
    std_list2.pop_front();
  }
}

TEST(LIST, EqualListMove) {
  std::initializer_list<int> box = {1, 2, 3, 4, 5};
  s21::list<int> our_list1(box);
  std::list<int> std_list1(box);
  s21::list<int> our_list2(2);
  our_list2 = std::move(our_list1);
  std::list<int> std_list2(2);
  std_list2 = std::move(std_list1);

  EXPECT_EQ(our_list1.empty(), std_list1.empty());
  EXPECT_EQ(our_list2.size(), std_list2.size());
  while (our_list2.size() > 0) {
    EXPECT_EQ(our_list2.front(), std_list2.front());
    our_list2.pop_front();
    std_list2.pop_front();
  }
}

TEST(LIST, PushFront_PopFront) {
  s21::list<int> our_list1;
  std::list<int> std_list1;
  our_list1.push_front(0);
  std_list1.push_front(0);
  our_list1.push_front(1);
  std_list1.push_front(1);
  our_list1.push_front(2);
  std_list1.push_front(2);

  EXPECT_EQ(our_list1.size(), std_list1.size());
  while (our_list1.size() > 0) {
    EXPECT_EQ(our_list1.front(), std_list1.front());
    our_list1.pop_front();
    std_list1.pop_front();
  }
}

TEST(LIST, PushBack_PopBack) {
  s21::list<int> our_list1;
  std::list<int> std_list1;
  our_list1.push_back(0);
  std_list1.push_back(0);
  our_list1.push_back(1);
  std_list1.push_back(1);
  our_list1.push_back(2);
  std_list1.push_back(2);

  EXPECT_EQ(our_list1.size(), std_list1.size());
  while (our_list1.size() > 0) {
    EXPECT_EQ(our_list1.back(), std_list1.back());
    our_list1.pop_back();
    std_list1.pop_back();
  }
}

TEST(LIST, Swap) {
  s21::list<int> our_list1;
  std::list<int> std_list1;
  s21::list<int> our_list2 = {1, 2, 3};
  std::list<int> std_list2 = {1, 2, 3};
  our_list2.swap(our_list1);
  std_list2.swap(std_list1);

  EXPECT_EQ(our_list1.size(), std_list1.size());
  EXPECT_EQ(our_list2.empty(), std_list2.empty());
  while (our_list1.size() > 0) {
    EXPECT_EQ(our_list1.front(), std_list1.front());
    our_list1.pop_front();
    std_list1.pop_front();
  }
}

TEST(LIST, Front) {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};

  EXPECT_EQ(our_list.front(), 1);
  EXPECT_EQ(std_list.front(), our_list.front());
}

TEST(LIST, Back) {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};

  EXPECT_EQ(our_list.back(), 3);
  EXPECT_EQ(std_list.back(), our_list.back());
}

TEST(LIST, Empty) {
  s21::list<int> our_list;
  std::list<int> std_list;

  EXPECT_EQ(our_list.empty(), 1);
  EXPECT_EQ(std_list.empty(), our_list.empty());
}

TEST(LIST, Size) {
  s21::list<int> our_list1;
  std::list<int> std_list1;
  s21::list<int> our_list2(5);
  std::list<int> std_list2(5);

  EXPECT_EQ(our_list1.size(), 0);
  EXPECT_EQ(our_list2.size(), 5);
  EXPECT_EQ(std_list1.size(), our_list1.size());
  EXPECT_EQ(std_list2.size(), our_list2.size());
}

TEST(LIST, MaxSize) {
  s21::list<int> our_list;
  std::list<int> std_list;

  EXPECT_EQ(std_list.max_size(), our_list.max_size());
}

TEST(LIST, Clear) {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  our_list.clear();
  std_list.clear();

  EXPECT_EQ(0, our_list.size());
  EXPECT_EQ(std_list.size(), our_list.size());
}

TEST(LIST, Reverse) {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  our_list.reverse();
  std_list.reverse();

  while (our_list.size() > 0) {
    EXPECT_EQ(our_list.front(), std_list.front());
    our_list.pop_front();
    std_list.pop_front();
  }
}

TEST(LIST, Merge) {
  s21::list<int> our_list1 = {1, 2, 3};
  std::list<int> std_list1 = {1, 2, 3};
  s21::list<int> our_list2 = {1, 4, 5};
  std::list<int> std_list2 = {1, 4, 5};
  our_list1.merge(our_list2);
  std_list1.merge(std_list2);

  EXPECT_EQ(our_list2.empty(), std_list2.empty());
  while (our_list2.size() > 0) {
    EXPECT_EQ(our_list2.front(), std_list2.front());
    our_list2.pop_front();
    std_list2.pop_front();
  }
}

TEST(LIST, Unique) {
  s21::list<int> our_list = {1, 2, 3, 6, 7, 1, 2, 3, 4, 6, 7, 3,
                             2, 1, 1, 1, 2, 2, 2, 3, 3, 4, 5, 6};
  std::list<int> std_list = {1, 2, 3, 6, 7, 1, 2, 3, 4, 6, 7, 3,
                             2, 1, 1, 1, 2, 2, 2, 3, 3, 4, 5, 6};
  our_list.unique();
  std_list.unique();

  while (our_list.size() > 0) {
    EXPECT_EQ(our_list.front(), std_list.front());
    our_list.pop_front();
    std_list.pop_front();
  }
}

TEST(LIST, Sort) {
  s21::list<int> our_list = {1, 2, 3,  6,  7, 1, 2, 3, 4, 6, 7, 3,
                             2, 1, 10, 91, 2, 2, 2, 3, 3, 4, 5, 6};
  std::list<int> std_list = {1, 2, 3,  6,  7, 1, 2, 3, 4, 6, 7, 3,
                             2, 1, 10, 91, 2, 2, 2, 3, 3, 4, 5, 6};
  our_list.sort();
  std_list.sort();

  while (our_list.size() > 0) {
    EXPECT_EQ(our_list.front(), std_list.front());
    our_list.pop_front();
    std_list.pop_front();
  }
}

TEST(LIST_ITERATOR, Constructor) {
  s21::list<int> our_list = {1, 2, 3, 6, 7};
  std::list<int> std_list = {1, 2, 3, 6, 7};
  s21::list<int>::iterator our_it1;
  std::list<int>::iterator std_it1;

  s21::list<int>::iterator our_it2(our_list.begin());
  std::list<int>::iterator std_it2(std_list.begin());
  EXPECT_EQ(*our_it2, *std_it2);

  s21::list<int>::iterator our_it3(our_it2);
  std::list<int>::iterator std_it3(std_it2);
  EXPECT_EQ(*our_it2, *std_it2);
}

TEST(LIST_ITERATOR, ChangeData) {
  s21::list<int> our_list = {1, 2, 3, 6, 7};
  std::list<int> std_list = {1, 2, 3, 6, 7};
  s21::list<int>::iterator our_it(our_list.begin());
  std::list<int>::iterator std_it(std_list.begin());
  *our_it = 100;
  *std_it = 100;

  EXPECT_EQ(*our_it, *std_it);
}

TEST(LIST_ITERATOR, Equal) {
  s21::list<int> our_list = {1, 2, 3, 6, 7};
  std::list<int> std_list = {1, 2, 3, 6, 7};
  s21::list<int>::iterator our_it2(our_list.begin());
  std::list<int>::iterator std_it2(std_list.begin());
  s21::list<int>::iterator our_it3(our_it2);
  std::list<int>::iterator std_it3(std_it2);

  EXPECT_EQ(our_it2 == our_it3, 1);
  EXPECT_EQ(our_it2 == our_it3, std_it2 == std_it3);
}

TEST(LIST_ITERATOR, NotEqual) {
  s21::list<int> our_list = {1, 2, 3, 6, 7};
  std::list<int> std_list = {1, 2, 3, 6, 7};
  s21::list<int>::iterator our_it2(our_list.begin());
  std::list<int>::iterator std_it2(std_list.begin());
  s21::list<int>::iterator our_it3(our_list.end());
  std::list<int>::iterator std_it3(std_list.end());

  EXPECT_EQ(our_it2 != our_it3, 1);
  EXPECT_EQ(our_it2 != our_it3, std_it2 != std_it3);
}

TEST(LIST_ITERATOR, EqualCopy) {
  s21::list<int> our_list = {1, 2, 3, 6, 7};
  std::list<int> std_list = {1, 2, 3, 6, 7};
  s21::list<int>::iterator our_it2(our_list.begin());
  std::list<int>::iterator std_it2(std_list.begin());
  s21::list<int>::iterator our_it3(our_list.end());
  std::list<int>::iterator std_it3(std_list.end());
  our_it2 = our_it3;
  std_it2 = std_it3;

  EXPECT_EQ(our_it2 == our_it3, 1);
  EXPECT_EQ(our_it2 == our_it3, std_it2 == std_it3);
}

TEST(LIST_ITERATOR, Iterations) {
  s21::list<int> our_list = {1, 2, 3, 6, 7};
  std::list<int> std_list = {1, 2, 3, 6, 7};
  s21::list<int>::iterator our_it1(our_list.begin());
  std::list<int>::iterator std_it1(std_list.begin());
  our_it1++;
  std_it1++;
  EXPECT_EQ(*our_it1, 2);
  EXPECT_EQ(*std_it1, 2);

  ++our_it1;
  ++std_it1;
  EXPECT_EQ(*our_it1, 3);
  EXPECT_EQ(*std_it1, 3);

  our_it1 += 2;
  EXPECT_EQ(*our_it1, 7);

  our_it1 -= 2;
  EXPECT_EQ(*our_it1, 3);

  our_it1--;
  std_it1--;
  EXPECT_EQ(*our_it1, 2);
  EXPECT_EQ(*std_it1, 2);

  --our_it1;
  --std_it1;
  EXPECT_EQ(*our_it1, 1);
  EXPECT_EQ(*std_it1, 1);

  s21::list<int>::iterator our_it2;
  our_it2 = our_it1 + 1;
  EXPECT_EQ(*our_it2, 2);

  s21::list<int>::iterator our_it3;
  our_it3 = our_it1 - 1;
  EXPECT_EQ(*our_it3, 5);
}

TEST(LIST_CONST_ITERATOR, Constructor) {
  s21::list<int> our_list = {1, 2, 3, 6, 7};
  std::list<int> std_list = {1, 2, 3, 6, 7};
  s21::list<int>::const_iterator our_it1;
  std::list<int>::const_iterator std_it1;

  s21::list<int>::const_iterator our_it2(our_list.begin());
  std::list<int>::const_iterator std_it2(std_list.begin());
  EXPECT_EQ(*our_it2, *std_it2);

  s21::list<int>::const_iterator our_it3(our_it2);
  std::list<int>::const_iterator std_it3(std_it2);
  EXPECT_EQ(*our_it2, *std_it2);
}

TEST(LIST_CONST_ITERATOR, Equal) {
  s21::list<int> our_list = {1, 2, 3, 6, 7};
  std::list<int> std_list = {1, 2, 3, 6, 7};
  s21::list<int>::const_iterator our_it2(our_list.begin());
  std::list<int>::const_iterator std_it2(std_list.begin());
  s21::list<int>::const_iterator our_it3(our_it2);
  std::list<int>::const_iterator std_it3(std_it2);

  EXPECT_EQ(our_it2 == our_it3, 1);
  EXPECT_EQ(our_it2 == our_it3, std_it2 == std_it3);
}

TEST(LIST_CONST_ITERATOR, NotEqual) {
  s21::list<int> our_list = {1, 2, 3, 6, 7};
  std::list<int> std_list = {1, 2, 3, 6, 7};
  s21::list<int>::const_iterator our_it2(our_list.begin());
  std::list<int>::const_iterator std_it2(std_list.begin());
  s21::list<int>::const_iterator our_it3(our_list.end());
  std::list<int>::const_iterator std_it3(std_list.end());

  EXPECT_EQ(our_it2 != our_it3, 1);
  EXPECT_EQ(our_it2 != our_it3, std_it2 != std_it3);
}

TEST(LIST_CONST_ITERATOR, EqualCopy) {
  s21::list<int> our_list = {1, 2, 3, 6, 7};
  std::list<int> std_list = {1, 2, 3, 6, 7};
  s21::list<int>::const_iterator our_it2(our_list.begin());
  std::list<int>::const_iterator std_it2(std_list.begin());
  s21::list<int>::const_iterator our_it3(our_list.end());
  std::list<int>::const_iterator std_it3(std_list.end());
  our_it2 = our_it3;
  std_it2 = std_it3;

  EXPECT_EQ(our_it2 == our_it3, 1);
  EXPECT_EQ(our_it2 == our_it3, std_it2 == std_it3);
}

TEST(LIST_CONST_ITERATOR, Iterations) {
  s21::list<int> our_list = {1, 2, 3, 6, 7};
  std::list<int> std_list = {1, 2, 3, 6, 7};
  s21::list<int>::const_iterator our_it1(our_list.begin());
  std::list<int>::const_iterator std_it1(std_list.begin());
  our_it1++;
  std_it1++;
  EXPECT_EQ(*our_it1, 2);
  EXPECT_EQ(*std_it1, 2);

  ++our_it1;
  ++std_it1;
  EXPECT_EQ(*our_it1, 3);
  EXPECT_EQ(*std_it1, 3);

  our_it1 += 2;
  EXPECT_EQ(*our_it1, 7);

  our_it1 -= 2;
  EXPECT_EQ(*our_it1, 3);

  our_it1--;
  std_it1--;
  EXPECT_EQ(*our_it1, 2);
  EXPECT_EQ(*std_it1, 2);

  --our_it1;
  --std_it1;
  EXPECT_EQ(*our_it1, 1);
  EXPECT_EQ(*std_it1, 1);

  s21::list<int>::const_iterator our_it2;
  our_it2 = our_it1 + 1;
  EXPECT_EQ(*our_it2, 2);

  s21::list<int>::const_iterator our_it3;
  our_it3 = our_it1 - 1;
  EXPECT_EQ(*our_it3, 5);
}

TEST(LIST, BeginEnd) {
  s21::list<int> our_list1 = {1, 2, 3, 6, 7};
  std::list<int> std_list1 = {1, 2, 3, 6, 7};
  s21::list<int> our_list2;
  std::list<int> std_list2;
  s21::list<int> our_list3 = {3};
  std::list<int> std_list3 = {3};

  s21::list<int>::iterator our_it1(our_list1.begin());
  std::list<int>::iterator std_it1(std_list1.begin());
  EXPECT_EQ(*our_it1, *std_it1);

  s21::list<int>::iterator our_it2(our_list2.begin());
  std::list<int>::iterator std_it2(std_list2.begin());
  EXPECT_EQ(*our_it2, *std_it2);

  s21::list<int>::iterator our_it3(our_list1.end());
  std::list<int>::iterator std_it3(std_list1.end());
  EXPECT_EQ(*our_it3, *std_it3);

  s21::list<int>::iterator our_it4(our_list2.end());
  std::list<int>::iterator std_it4(std_list2.end());
  EXPECT_EQ(*our_it4, *std_it4);

  s21::list<int>::iterator our_it5(our_list3.end());
  std::list<int>::iterator std_it5(std_list3.end());
  EXPECT_EQ(*our_it5, *std_it5);
}

TEST(LIST, CbeginCend) {
  s21::list<int> our_list1 = {1, 2, 3, 6, 7};
  std::list<int> std_list1 = {1, 2, 3, 6, 7};
  s21::list<int> our_list2;
  std::list<int> std_list2;
  s21::list<int> our_list3 = {3};
  std::list<int> std_list3 = {3};

  s21::list<int>::const_iterator our_it1(our_list1.cbegin());
  std::list<int>::const_iterator std_it1(std_list1.cbegin());
  EXPECT_EQ(*our_it1, *std_it1);

  s21::list<int>::const_iterator our_it2(our_list2.cbegin());
  std::list<int>::const_iterator std_it2(std_list2.cbegin());
  EXPECT_EQ(*our_it2, *std_it2);

  s21::list<int>::const_iterator our_it3(our_list1.cend());
  std::list<int>::const_iterator std_it3(std_list1.cend());
  EXPECT_EQ(*our_it3, *std_it3);

  s21::list<int>::const_iterator our_it4(our_list2.cend());
  std::list<int>::const_iterator std_it4(std_list2.cend());
  EXPECT_EQ(*our_it4, *std_it4);

  s21::list<int>::const_iterator our_it5(our_list3.cend());
  std::list<int>::const_iterator std_it5(std_list3.cend());
  EXPECT_EQ(*our_it5, *std_it5);
}

TEST(LIST, Insert) {
  s21::list<int> our_list1 = {1, 2, 3, 6, 7};
  std::list<int> std_list1 = {1, 2, 3, 6, 7};
  our_list1.insert(our_list1.begin(), 33);
  std_list1.insert(std_list1.begin(), 33);
  while (our_list1.size() > 0) {
    EXPECT_EQ(our_list1.front(), std_list1.front());
    our_list1.pop_front();
    std_list1.pop_front();
  }

  s21::list<int> our_list2 = {1, 2, 3, 6, 7};
  std::list<int> std_list2 = {1, 2, 3, 6, 7};
  our_list2.insert((our_list2.end())++, 33);
  std_list2.insert((std_list2.end())++, 33);
  while (our_list2.size() > 0) {
    EXPECT_EQ(our_list2.front(), std_list2.front());
    our_list2.pop_front();
    std_list2.pop_front();
  }

  s21::list<int> our_list3 = {1, 2, 3, 6, 7};
  std::list<int> std_list3 = {1, 2, 3, 6, 7};
  s21::list<int>::iterator our_it1(our_list3.begin());
  std::list<int>::iterator std_it1(std_list3.begin());
  our_it1++;
  std_it1++;
  our_list3.insert(our_it1, 33);
  std_list3.insert(std_it1, 33);
  while (our_list3.size() > 0) {
    EXPECT_EQ(our_list3.front(), std_list3.front());
    our_list3.pop_front();
    std_list3.pop_front();
  }
}

TEST(LIST, Erase) {
  s21::list<int> our_list1 = {1, 2, 3, 6, 7};
  std::list<int> std_list1 = {1, 2, 3, 6, 7};
  our_list1.erase(our_list1.begin());
  std_list1.erase(std_list1.begin());
  while (our_list1.size() > 0) {
    EXPECT_EQ(our_list1.front(), std_list1.front());
    our_list1.pop_front();
    std_list1.pop_front();
  }

  s21::list<int> our_list2 = {1, 2, 3, 6, 7};
  std::list<int> std_list2 = {1, 2, 3, 6, 7};
  s21::list<int>::iterator our_it1(our_list2.end());
  std::list<int>::iterator std_it1(std_list2.end());
  our_it1--;
  std_it1--;
  our_list2.erase(our_it1);
  std_list2.erase(std_it1);
  while (our_list2.size() > 0) {
    EXPECT_EQ(our_list2.front(), std_list2.front());
    our_list2.pop_front();
    std_list2.pop_front();
  }

  s21::list<int> our_list3 = {1, 2, 3, 6, 7};
  std::list<int> std_list3 = {1, 2, 3, 6, 7};
  s21::list<int>::iterator our_it2(our_list3.end());
  std::list<int>::iterator std_it2(std_list3.end());
  our_it2--;
  std_it2--;
  our_it2--;
  std_it2--;
  our_list3.erase(our_it2);
  std_list3.erase(std_it2);
  while (our_list3.size() > 0) {
    EXPECT_EQ(our_list3.front(), std_list3.front());
    our_list3.pop_front();
    std_list3.pop_front();
  }
}

TEST(LIST, SPLICE) {
  s21::list<int> our_list1 = {1, 2, 3};
  std::list<int> std_list1 = {1, 2, 3};
  s21::list<int> our_list2 = {4, 5};
  std::list<int> std_list2 = {4, 5};
  s21::list<int>::iterator our_it(our_list1.begin());
  std::list<int>::iterator std_it(std_list1.begin());
  our_it++;
  std_it++;
  our_list1.splice(our_it, our_list2);
  std_list1.splice(std_it, std_list2);

  EXPECT_EQ(our_list2.empty(), std_list2.empty());
  while (our_list1.size() > 0) {
    EXPECT_EQ(our_list1.front(), std_list1.front());
    our_list1.pop_front();
    std_list1.pop_front();
  }
}

TEST(VECTOR, EmptyConstructor) {
  s21::vector<int> our_vector;
  std::vector<int> std_vector;

  EXPECT_EQ(our_vector.empty(), std_vector.empty());
}

TEST(VECTOR, SziedConstructor) {
  s21::vector<int> our_vector(3);
  std::vector<int> std_vector(3);

  EXPECT_EQ(our_vector.empty(), std_vector.empty());
}

TEST(VECTOR, ListConstructor) {
  std::initializer_list<int> box = {1, 2, 3, 4, 5};
  s21::vector<int> our_vector(box);
  std::vector<int> std_vector(box);

  for (size_t i = 0; i < std_vector.size(); i++) {
    EXPECT_EQ(our_vector[i], std_vector[i]);
  }
}

TEST(VECTOR, CopyConstructor) {
  s21::vector<int> our_vector1 = {1, 23, 0};
  std::vector<int> std_vector1 = {1, 23, 0};
  s21::vector<int> our_vector2(our_vector1);
  std::vector<int> std_vector2(std_vector1);

  EXPECT_EQ(0, our_vector1.empty());
  for (size_t i = 0; i < std_vector2.size(); i++) {
    EXPECT_EQ(our_vector2[i], std_vector2[i]);
  }
}

TEST(VECTOR, MoveConstructor) {
  s21::vector<int> our_vector1 = {1, 23, 0};
  std::vector<int> std_vector1 = {1, 23, 0};
  s21::vector<int> our_vector2(std::move(our_vector1));
  std::vector<int> std_vector2(std::move(std_vector1));

  EXPECT_EQ(1, our_vector1.empty());
  for (size_t i = 0; i < std_vector2.size(); i++) {
    EXPECT_EQ(our_vector2[i], std_vector2[i]);
  }
}

TEST(VECTOR, CopyEqualConstructor) {
  s21::vector<int> our_vector1 = {1, 23, 0};
  std::vector<int> std_vector1 = {1, 23, 0};
  s21::vector<int> our_vector2 = {1};
  std::vector<int> std_vector2 = {1};
  our_vector2 = our_vector1;
  std_vector2 = std_vector1;

  EXPECT_EQ(0, our_vector1.empty());
  for (size_t i = 0; i < std_vector2.size(); i++) {
    EXPECT_EQ(our_vector2[i], std_vector2[i]);
  }
}

TEST(VECTOR, MoveEqualConstructor) {
  s21::vector<int> our_vector1 = {1, 23, 0};
  std::vector<int> std_vector1 = {1, 23, 0};
  s21::vector<int> our_vector2 = {1};
  std::vector<int> std_vector2 = {1};
  our_vector2 = std::move(our_vector1);
  std_vector2 = std::move(std_vector1);

  EXPECT_EQ(1, our_vector1.empty());
  for (size_t i = 0; i < std_vector2.size(); i++) {
    EXPECT_EQ(our_vector2[i], std_vector2[i]);
  }
}

TEST(VECTOR, At) {
  s21::vector<int> our_vector = {1, 23, 0};

  EXPECT_THROW(our_vector.at(3), std::out_of_range);
  EXPECT_EQ(1, our_vector.at(0));
  EXPECT_EQ(23, our_vector.at(1));
  EXPECT_EQ(0, our_vector.at(2));
}

TEST(VECTOR, ElementIteration) {
  s21::vector<int> our_vector = {1, 23, 0};

  EXPECT_EQ(1, our_vector[0]);
  EXPECT_EQ(23, our_vector[1]);
  EXPECT_EQ(0, our_vector[2]);
}

TEST(VECTOR, FrontBack) {
  s21::vector<int> our_vector1 = {1, 23, 0};
  s21::vector<int> our_vector2;

  EXPECT_THROW(our_vector2.front(), std::out_of_range);
  EXPECT_THROW(our_vector2.back(), std::out_of_range);
  EXPECT_EQ(1, our_vector1.front());
  EXPECT_EQ(0, our_vector1.back());
}

TEST(VECTOR_ITERATOR, Consrtuctor) {
  s21::vector<int> our_vector = {1, 23, 0};
  std::vector<int> std_vector = {1, 23, 0};
  s21::vector<int>::iterator our_it1;
  std::vector<int>::iterator std_it1;

  s21::vector<int>::iterator our_it2{our_vector.begin()};
  std::vector<int>::iterator std_it2{std_vector.begin()};
  EXPECT_EQ(*our_it2, *std_it2);

  s21::vector<int>::iterator our_it3{our_it2};
  std::vector<int>::iterator std_it3{std_it2};
  EXPECT_EQ(*our_it3, *std_it3);
}

TEST(VECTOR_ITERATOR, ChangeData) {
  s21::vector<int> our_vector = {1, 23, 0};
  std::vector<int> std_vector = {1, 23, 0};
  s21::vector<int>::iterator our_it{our_vector.begin()};
  std::vector<int>::iterator std_it{std_vector.begin()};
  *our_it = 100;
  *std_it = 100;

  EXPECT_EQ(*our_it, 100);
  EXPECT_EQ(*our_it, *std_it);
}

TEST(VECTOR_ITERATOR, Equal) {
  s21::vector<int> our_vector = {1, 2, 3, 6, 7};
  std::vector<int> std_vector = {1, 2, 3, 6, 7};
  s21::vector<int>::iterator our_it2(our_vector.begin());
  std::vector<int>::iterator std_it2(std_vector.begin());
  s21::vector<int>::iterator our_it3(our_it2);
  std::vector<int>::iterator std_it3(std_it2);

  EXPECT_EQ(our_it2 == our_it3, 1);
  EXPECT_EQ(our_it2 == our_it3, std_it2 == std_it3);
}

TEST(VECTOR_ITERATOR, NotEqual) {
  s21::vector<int> our_vector = {1, 2, 3, 6, 7};
  std::vector<int> std_vector = {1, 2, 3, 6, 7};
  s21::vector<int>::iterator our_it2(our_vector.begin());
  std::vector<int>::iterator std_it2(std_vector.begin());
  s21::vector<int>::iterator our_it3(our_vector.end());
  std::vector<int>::iterator std_it3(std_vector.end());

  EXPECT_EQ(our_it2 != our_it3, 1);
  EXPECT_EQ(our_it2 != our_it3, std_it2 != std_it3);
}

TEST(VECTOR_ITERATOR, EqualCopy) {
  s21::vector<int> our_vector = {1, 2, 3, 6, 7};
  std::vector<int> std_vector = {1, 2, 3, 6, 7};
  s21::vector<int>::iterator our_it2(our_vector.begin());
  std::vector<int>::iterator std_it2(std_vector.begin());
  s21::vector<int>::iterator our_it3(our_vector.end());
  std::vector<int>::iterator std_it3(std_vector.end());
  our_it2 = our_it3;
  std_it2 = std_it3;

  EXPECT_EQ(our_it2 == our_it3, 1);
  EXPECT_EQ(our_it2 == our_it3, std_it2 == std_it3);
}

TEST(VECTOR_ITERATOR, Iterations) {
  s21::vector<int> our_vector = {1, 2, 3, 6, 7};
  std::vector<int> std_vector = {1, 2, 3, 6, 7};
  s21::vector<int>::iterator our_it1(our_vector.begin());
  std::vector<int>::iterator std_it1(std_vector.begin());
  our_it1++;
  std_it1++;
  EXPECT_EQ(*our_it1, 2);
  EXPECT_EQ(*std_it1, 2);

  ++our_it1;
  ++std_it1;
  EXPECT_EQ(*our_it1, 3);
  EXPECT_EQ(*std_it1, 3);

  our_it1 += 2;
  EXPECT_EQ(*our_it1, 7);

  our_it1 -= 2;
  EXPECT_EQ(*our_it1, 3);

  our_it1--;
  std_it1--;
  EXPECT_EQ(*our_it1, 2);
  EXPECT_EQ(*std_it1, 2);

  --our_it1;
  --std_it1;
  EXPECT_EQ(*our_it1, 1);
  EXPECT_EQ(*std_it1, 1);

  s21::vector<int>::iterator our_it2;
  our_it2 = our_it1 + 1;
  EXPECT_EQ(*our_it2, 2);

  s21::vector<int>::iterator our_it3;
  our_it3 = our_it2 - 1;
  EXPECT_EQ(*our_it3, 1);

  s21::vector<int>::iterator our_it4 = our_vector.begin();
  EXPECT_EQ(our_it4 - our_vector.begin(), 0);
}

TEST(VECTOR_CONST_ITERATOR, Consrtuctor) {
  s21::vector<int> our_vector = {1, 23, 0};
  std::vector<int> std_vector = {1, 23, 0};
  s21::vector<int>::const_iterator our_it1;
  std::vector<int>::const_iterator std_it1;

  s21::vector<int>::const_iterator our_it2{our_vector.cbegin()};
  std::vector<int>::const_iterator std_it2{std_vector.cbegin()};
  EXPECT_EQ(*our_it2, *std_it2);

  s21::vector<int>::const_iterator our_it3{our_it2};
  std::vector<int>::const_iterator std_it3{std_it2};
  EXPECT_EQ(*our_it3, *std_it3);

  s21::vector<int>::iterator our_it4{our_vector.begin()};
  std::vector<int>::iterator std_it4{std_vector.begin()};
  s21::vector<int>::const_iterator our_it5{our_it4};
  std::vector<int>::const_iterator std_it5{std_it4};
  EXPECT_EQ(*our_it5, *std_it5);
}

TEST(VECTOR_CONST_ITERATOR, Equal) {
  s21::vector<int> our_vector = {1, 2, 3, 6, 7};
  std::vector<int> std_vector = {1, 2, 3, 6, 7};
  s21::vector<int>::const_iterator our_it2(our_vector.cbegin());
  std::vector<int>::const_iterator std_it2(std_vector.cbegin());
  s21::vector<int>::const_iterator our_it3(our_it2);
  std::vector<int>::const_iterator std_it3(std_it2);

  EXPECT_EQ(our_it2 == our_it3, 1);
  EXPECT_EQ(our_it2 == our_it3, std_it2 == std_it3);
}

TEST(VECTOR_CONST_ITERATOR, NotEqual) {
  s21::vector<int> our_vector = {1, 2, 3, 6, 7};
  std::vector<int> std_vector = {1, 2, 3, 6, 7};
  s21::vector<int>::const_iterator our_it2(our_vector.cbegin());
  std::vector<int>::const_iterator std_it2(std_vector.cbegin());
  s21::vector<int>::const_iterator our_it3(our_vector.cend());
  std::vector<int>::const_iterator std_it3(std_vector.cend());

  EXPECT_EQ(our_it2 != our_it3, 1);
  EXPECT_EQ(our_it2 != our_it3, std_it2 != std_it3);
}

TEST(VECTOR_CONST_ITERATOR, EqualCopy) {
  s21::vector<int> our_vector = {1, 2, 3, 6, 7};
  std::vector<int> std_vector = {1, 2, 3, 6, 7};
  s21::vector<int>::const_iterator our_it2(our_vector.cbegin());
  std::vector<int>::const_iterator std_it2(std_vector.cbegin());
  s21::vector<int>::const_iterator our_it3(our_vector.cend());
  std::vector<int>::const_iterator std_it3(std_vector.cend());
  our_it2 = our_it3;
  std_it2 = std_it3;

  EXPECT_EQ(our_it2 == our_it3, 1);
  EXPECT_EQ(our_it2 == our_it3, std_it2 == std_it3);
}

TEST(VECTOR_CONST_ITERATOR, Iterations) {
  s21::vector<int> our_vector = {1, 2, 3, 6, 7};
  std::vector<int> std_vector = {1, 2, 3, 6, 7};
  s21::vector<int>::const_iterator our_it1(our_vector.cbegin());
  std::vector<int>::const_iterator std_it1(std_vector.cbegin());
  our_it1++;
  std_it1++;
  EXPECT_EQ(*our_it1, 2);
  EXPECT_EQ(*std_it1, 2);

  ++our_it1;
  ++std_it1;
  EXPECT_EQ(*our_it1, 3);
  EXPECT_EQ(*std_it1, 3);

  our_it1 += 2;
  EXPECT_EQ(*our_it1, 7);

  our_it1 -= 2;
  EXPECT_EQ(*our_it1, 3);

  our_it1--;
  std_it1--;
  EXPECT_EQ(*our_it1, 2);
  EXPECT_EQ(*std_it1, 2);

  --our_it1;
  --std_it1;
  EXPECT_EQ(*our_it1, 1);
  EXPECT_EQ(*std_it1, 1);

  s21::vector<int>::const_iterator our_it2;
  our_it2 = our_it1 + 1;
  EXPECT_EQ(*our_it2, 2);

  s21::vector<int>::const_iterator our_it3;
  our_it3 = our_it2 - 1;
  EXPECT_EQ(*our_it3, 1);

  s21::vector<int>::const_iterator our_it4 = our_vector.cbegin();
  EXPECT_EQ(our_it4 - our_vector.cbegin(), 0);
}

TEST(VECTOR, BeginEnd) {
  s21::vector<int> our_vector1 = {1, 2, 3, 6, 7};
  std::vector<int> std_vector1 = {1, 2, 3, 6, 7};
  s21::vector<int> our_vector3 = {3};
  std::vector<int> std_vector3 = {3};

  s21::vector<int>::iterator our_it1(our_vector1.begin());
  std::vector<int>::iterator std_it1(std_vector1.begin());
  EXPECT_EQ(*our_it1, *std_it1);

  s21::vector<int>::iterator our_it3((our_vector1.end() - 1));
  std::vector<int>::iterator std_it3(std_vector1.end() - 1);
  EXPECT_EQ(*our_it3, *std_it3);

  s21::vector<int>::iterator our_it5(our_vector3.end() - 1);
  std::vector<int>::iterator std_it5(std_vector3.end() - 1);
  EXPECT_EQ(*our_it5, *std_it5);
}

TEST(VECTOR, CbeginCend) {
  s21::vector<int> our_vector1 = {1, 2, 3, 6, 7};
  std::vector<int> std_vector1 = {1, 2, 3, 6, 7};
  s21::vector<int> our_vector3 = {3};
  std::vector<int> std_vector3 = {3};

  s21::vector<int>::const_iterator our_it1(our_vector1.cbegin());
  std::vector<int>::const_iterator std_it1(std_vector1.cbegin());
  EXPECT_EQ(*our_it1, *std_it1);

  s21::vector<int>::const_iterator our_it3(our_vector1.cend() - 1);
  std::vector<int>::const_iterator std_it3(std_vector1.cend() - 1);
  EXPECT_EQ(*our_it3, *std_it3);

  s21::vector<int>::const_iterator our_it5(our_vector3.cend() - 1);
  std::vector<int>::const_iterator std_it5(std_vector3.cend() - 1);
  EXPECT_EQ(*our_it5, *std_it5);
}

TEST(VECTOR, Empty) {
  s21::vector<int> our_vector1 = {1, 2, 3, 6, 7};
  std::vector<int> std_vector1 = {1, 2, 3, 6, 7};
  s21::vector<int> our_vector2;
  std::vector<int> std_vector2;
  s21::vector<int> our_vector3(5);
  std::vector<int> std_vector3(5);

  EXPECT_EQ(our_vector1.empty(), std_vector1.empty());
  EXPECT_EQ(our_vector2.empty(), std_vector2.empty());
  EXPECT_EQ(our_vector3.empty(), std_vector3.empty());
}

TEST(VECTOR, Size) {
  s21::vector<int> our_vector1 = {1, 2, 3, 6, 7};
  std::vector<int> std_vector1 = {1, 2, 3, 6, 7};
  s21::vector<int> our_vector2;
  std::vector<int> std_vector2;
  s21::vector<int> our_vector3(5);
  std::vector<int> std_vector3(5);

  EXPECT_EQ(our_vector1.size(), std_vector1.size());
  EXPECT_EQ(our_vector2.size(), std_vector2.size());
  EXPECT_EQ(our_vector3.size(), std_vector3.size());
}

TEST(VECTOR, MaxSize) {
  s21::vector<int> our_vector1 = {1, 2, 3, 6, 7};
  std::vector<int> std_vector1 = {1, 2, 3, 6, 7};
  s21::vector<int> our_vector2;
  std::vector<int> std_vector2;
  s21::vector<int> our_vector3(5);
  std::vector<int> std_vector3(5);

  EXPECT_EQ(our_vector1.max_size(), std_vector1.max_size());
  EXPECT_EQ(our_vector2.max_size(), std_vector2.max_size());
  EXPECT_EQ(our_vector3.max_size(), std_vector3.max_size());
}

TEST(VECTOR, Capacity) {
  s21::vector<int> our_vector1{1, 2};
  s21::vector<int> our_vector2{1};
  s21::vector<int> our_vector3;
  s21::vector<int> our_vector4{1, 23};
  our_vector4.pop_back();

  EXPECT_EQ(our_vector1.capacity(), 2);
  EXPECT_EQ(our_vector2.capacity(), 1);
  EXPECT_EQ(our_vector3.capacity(), 0);
  EXPECT_EQ(our_vector4.capacity(), 2);
}

TEST(VECTOR, Reserve) {
  s21::vector<int> our_vector1{1, 2};
  our_vector1.reserve(1);
  s21::vector<int> our_vector2{1};
  our_vector2.reserve(3);
  s21::vector<int> our_vector3;
  our_vector3.reserve(1);

  EXPECT_EQ(our_vector1.capacity(), 2);
  EXPECT_EQ(our_vector2.capacity(), 3);
  EXPECT_EQ(our_vector3.capacity(), 1);
}

TEST(VECTOR, PushBack) {
  s21::vector<int> our_vector1{1, 2};
  our_vector1.push_back(3);
  s21::vector<int> our_vector2{1};
  our_vector2.push_back(2);
  s21::vector<int> our_vector3;
  our_vector3.push_back(1);

  EXPECT_EQ(our_vector1.back(), 3);
  EXPECT_EQ(our_vector2.back(), 2);
  EXPECT_EQ(our_vector3.back(), 1);
}

TEST(VECTOR, PopBack) {
  s21::vector<int> our_vector1{1, 2};
  our_vector1.pop_back();

  EXPECT_EQ(our_vector1.back(), 1);
}

TEST(VECTOR, ShrinkToFit) {
  s21::vector<int> our_vector1{1, 2};
  our_vector1.shrink_to_fit();
  s21::vector<int> our_vector2{1};
  our_vector2.reserve(3);
  our_vector2.shrink_to_fit();
  s21::vector<int> our_vector3;
  our_vector3.shrink_to_fit();

  EXPECT_EQ(our_vector1.capacity(), 2);
  EXPECT_EQ(our_vector2.capacity(), 1);
  EXPECT_EQ(our_vector3.capacity(), 0);
}

TEST(VECTOR, Clear) {
  s21::vector<int> our_vector1{1, 2};
  s21::vector<int> our_vector2{1};
  s21::vector<int> our_vector3;
  our_vector1.clear();
  our_vector2.clear();
  our_vector3.clear();

  EXPECT_EQ(our_vector1.empty(), 1);
  EXPECT_EQ(our_vector2.empty(), 1);
  EXPECT_EQ(our_vector3.empty(), 1);
}

TEST(VECTOR, Swap) {
  s21::vector<int> our_vector1{1, 1, 1, 1};
  s21::vector<int> our_vector2{2, 2, 2, 2};
  our_vector1.swap(our_vector2);

  while (our_vector1.size()) {
    EXPECT_EQ(our_vector1.back(), 2);
    EXPECT_EQ(our_vector2.back(), 1);
    our_vector1.pop_back();
    our_vector2.pop_back();
  }
}

TEST(VECTOR, Insert) {
  s21::vector<int> our_vector1;
  s21::vector<int>::iterator it = our_vector1.begin();
  our_vector1.insert(it, 7);
  s21::vector<int> our_vector2{1, 1, 1, 1};
  s21::vector<int>::iterator it2 = our_vector2.begin();
  it2++;
  our_vector2.insert(it2, 7);
  s21::vector<int> our_vector3{1, 1, 1, 1};
  s21::vector<int>::iterator it3 = our_vector3.begin();
  it3++;
  it3++;
  it3++;
  our_vector3.insert(it3, 7);

  EXPECT_EQ(our_vector1.front(), 7);
  EXPECT_EQ(our_vector2[1], 7);
  EXPECT_EQ(our_vector3[3], 7);
}

TEST(VECTOR, Erase) {
  s21::vector<int> our_vector1{1, 2, 3, 4};
  our_vector1.erase(our_vector1.begin());
  EXPECT_EQ(our_vector1.front(), 2);

  s21::vector<int> our_vector2{1, 2, 3, 4};
  our_vector2.erase(our_vector2.end() - 1);
  EXPECT_EQ(our_vector2.back(), 3);

  s21::vector<int> our_vector3{1, 2, 3, 4};
  our_vector3.erase(our_vector3.end() - 2);
  EXPECT_EQ(our_vector3.back() - 2, 2);
}

TEST(VECTOR, InsertManyBack) {
  s21::vector<int> our_vector;
  our_vector.insert_many_back(0, 1, 2, 3, 4);
  for (size_t i = 0; i < our_vector.size(); i++) {
    EXPECT_EQ(our_vector[i], i);
  }
}

TEST(VECTOR, InsertMany) {
  s21::vector<int> our_vector;
  our_vector.insert_many_back(0, 3, 4);
  s21::vector<int>::const_iterator it = our_vector.cbegin();
  it++;
  s21::vector<int>::iterator it2 = our_vector.insert_many(it, 1, 2);
  EXPECT_EQ(*it2, 1);
  for (size_t i = 0; i < our_vector.size(); i++) {
    EXPECT_EQ(our_vector[i], i);
  }
}

TEST(LIST, InsertManyBack) {
  s21::list<int> our_list = {0};
  our_list.insert_many_back(1, 2, 3, 4);

  EXPECT_EQ(our_list.front(), 0);
  our_list.pop_front();
  EXPECT_EQ(our_list.front(), 1);
  our_list.pop_front();
  EXPECT_EQ(our_list.front(), 2);
  our_list.pop_front();
  EXPECT_EQ(our_list.front(), 3);
  our_list.pop_front();
  EXPECT_EQ(our_list.front(), 4);
  our_list.pop_front();
}

TEST(LIST, InsertManyFront) {
  s21::list<int> our_list = {3, 4};
  our_list.insert_many_front(0, 1, 2);

  EXPECT_EQ(our_list.front(), 0);
  our_list.pop_front();
  EXPECT_EQ(our_list.front(), 1);
  our_list.pop_front();
  EXPECT_EQ(our_list.front(), 2);
  our_list.pop_front();
  EXPECT_EQ(our_list.front(), 3);
  our_list.pop_front();
  EXPECT_EQ(our_list.front(), 4);
  our_list.pop_front();
}

TEST(LIST, InsertMany) {
  s21::list<int> our_list;
  our_list.insert_many_back(0, 3, 4);
  s21::list<int>::const_iterator it = our_list.cbegin();
  it++;
  s21::list<int>::iterator it2 = our_list.insert_many(it, 1, 2);

  EXPECT_EQ(*it2, 1);
  EXPECT_EQ(our_list.front(), 0);
  our_list.pop_front();
  EXPECT_EQ(our_list.front(), 1);
  our_list.pop_front();
  EXPECT_EQ(our_list.front(), 2);
  our_list.pop_front();
  EXPECT_EQ(our_list.front(), 3);
  our_list.pop_front();
  EXPECT_EQ(our_list.front(), 4);
  our_list.pop_front();
}

TEST(ARRAY, DefaultConstructor) {
  s21::array<int, 5> our_array;
  std::array<int, 5> std_array;

  EXPECT_EQ(our_array.size(), std_array.size());
}

TEST(ARRAY, ListConstructor) {
  s21::array<int, 5> our_array{0, 1, 2, 3, 4};

  EXPECT_EQ(our_array.size(), 5);
  for (size_t i = 0; i < our_array.size(); i++) EXPECT_EQ(our_array[i], i);
}

TEST(ARRAY, CopyConstructor) {
  s21::array<int, 5> our_array1{0, 1, 2, 3, 4};
  s21::array<int, 5> our_array2{our_array1};

  EXPECT_EQ(our_array1.size(), 5);
  for (size_t i = 0; i < our_array2.size(); i++) EXPECT_EQ(our_array2[i], i);
}

TEST(ARRAY, MoveConstructor) {
  s21::array<int, 5> our_array1{0, 1, 2, 3, 4};
  s21::array<int, 5> our_array2{std::move(our_array1)};

  EXPECT_EQ(our_array1.empty(), 1);
  for (size_t i = 0; i < our_array2.size(); i++) EXPECT_EQ(our_array2[i], i);
}

TEST(ARRAY, EqualCopyConstructor) {
  s21::array<int, 5> our_array1{0, 1, 2, 3, 4};
  s21::array<int, 5> our_array2;
  our_array2 = our_array1;

  EXPECT_EQ(our_array1.size(), 5);
  for (size_t i = 0; i < our_array2.size(); i++) EXPECT_EQ(our_array2[i], i);
}

TEST(ARRAY, EqualMoveConstructor) {
  s21::array<int, 5> our_array1{0, 1, 2, 3, 4};
  s21::array<int, 5> our_array2;
  our_array2 = std::move(our_array1);

  EXPECT_EQ(our_array1.empty(), 1);
  for (size_t i = 0; i < our_array2.size(); i++) EXPECT_EQ(our_array2[i], i);
}

TEST(ARRAY, At) {
  s21::array<int, 5> our_array{0, 1, 2, 3, 4};

  EXPECT_EQ(our_array.at(0), 0);
  EXPECT_THROW(our_array.at(10), std::out_of_range);
}

TEST(ARRAY, Front) {
  s21::array<int, 5> our_array1{0, 1, 2, 3, 4};
  s21::array<int, 0> our_array2;

  EXPECT_EQ(our_array1.front(), 0);
  EXPECT_THROW(our_array2.front(), std::out_of_range);
}

TEST(ARRAY, Back) {
  s21::array<int, 5> our_array1{0, 1, 2, 3, 4};
  s21::array<int, 0> our_array2;

  EXPECT_EQ(our_array1.back(), 4);
  EXPECT_THROW(our_array2.back(), std::out_of_range);
}

TEST(ARRAY_ITERATOR, Consrtuctor) {
  s21::array<int, 3> our_vector = {1, 23, 0};
  std::array<int, 3> std_vector = {1, 23, 0};
  s21::array<int, 3>::iterator our_it1;

  s21::array<int, 3>::iterator our_it2{our_vector.begin()};
  std::array<int, 3>::iterator std_it2{std_vector.begin()};
  EXPECT_EQ(*our_it2, *std_it2);

  s21::array<int, 3>::iterator our_it3{our_it2};
  std::array<int, 3>::iterator std_it3{std_it2};
  EXPECT_EQ(*our_it3, *std_it3);
}

TEST(ARRAY_ITERATOR, Equal) {
  s21::array<int, 5> our_vector = {1, 2, 3, 6, 7};
  std::array<int, 5> std_vector = {1, 2, 3, 6, 7};
  s21::array<int, 5>::iterator our_it2(our_vector.begin());
  std::array<int, 5>::iterator std_it2(std_vector.begin());
  s21::array<int, 5>::iterator our_it3(our_it2);
  std::array<int, 5>::iterator std_it3(std_it2);

  EXPECT_EQ(our_it2 == our_it3, 1);
  EXPECT_EQ(our_it2 == our_it3, std_it2 == std_it3);
}

TEST(ARRAY_ITERATOR, NotEqual) {
  s21::array<int, 5> our_vector = {1, 2, 3, 6, 7};
  std::array<int, 5> std_vector = {1, 2, 3, 6, 7};
  s21::array<int, 5>::iterator our_it2(our_vector.begin());
  std::array<int, 5>::iterator std_it2(std_vector.begin());
  s21::array<int, 5>::iterator our_it3(our_vector.end());
  std::array<int, 5>::iterator std_it3(std_vector.end());

  EXPECT_EQ(our_it2 != our_it3, 1);
  EXPECT_EQ(our_it2 != our_it3, std_it2 != std_it3);
}

TEST(ARRAY_ITERATOR, EqualCopy) {
  s21::array<int, 5> our_vector = {1, 2, 3, 6, 7};
  std::array<int, 5> std_vector = {1, 2, 3, 6, 7};
  s21::array<int, 5>::iterator our_it2(our_vector.begin());
  std::array<int, 5>::iterator std_it2(std_vector.begin());
  s21::array<int, 5>::iterator our_it3(our_vector.end());
  std::array<int, 5>::iterator std_it3(std_vector.end());
  our_it2 = our_it3;
  std_it2 = std_it3;

  EXPECT_EQ(our_it2 == our_it3, 1);
  EXPECT_EQ(our_it2 == our_it3, std_it2 == std_it3);
}

TEST(ARRAY_ITERATOR, Iterations) {
  s21::array<int, 5> our_vector = {1, 2, 3, 6, 7};
  std::array<int, 5> std_vector = {1, 2, 3, 6, 7};
  s21::array<int, 5>::iterator our_it1(our_vector.begin());
  std::array<int, 5>::iterator std_it1(std_vector.begin());
  our_it1++;
  std_it1++;
  EXPECT_EQ(*our_it1, 2);
  EXPECT_EQ(*std_it1, 2);

  ++our_it1;
  ++std_it1;
  EXPECT_EQ(*our_it1, 3);
  EXPECT_EQ(*std_it1, 3);

  our_it1 += 2;
  EXPECT_EQ(*our_it1, 7);

  our_it1 -= 2;
  EXPECT_EQ(*our_it1, 3);

  our_it1--;
  std_it1--;
  EXPECT_EQ(*our_it1, 2);
  EXPECT_EQ(*std_it1, 2);

  --our_it1;
  --std_it1;
  EXPECT_EQ(*our_it1, 1);
  EXPECT_EQ(*std_it1, 1);

  s21::array<int, 5>::iterator our_it2;
  our_it2 = our_it1 + 1;
  EXPECT_EQ(*our_it2, 2);

  s21::array<int, 5>::iterator our_it3;
  our_it3 = our_it2 - 1;
  EXPECT_EQ(*our_it3, 1);

  s21::array<int, 5>::iterator our_it4 = our_vector.begin();
  EXPECT_EQ(our_it4 - our_vector.begin(), 0);
}

TEST(ARRAY_CONST_ITERATOR, Consrtuctor) {
  s21::array<int, 3> our_vector = {1, 23, 0};
  std::array<int, 3> std_vector = {1, 23, 0};

  s21::array<int, 3>::const_iterator our_it2{our_vector.cbegin()};
  std::array<int, 3>::const_iterator std_it2{std_vector.cbegin()};
  EXPECT_EQ(*our_it2, *std_it2);

  s21::array<int, 3>::const_iterator our_it3{our_it2};
  std::array<int, 3>::const_iterator std_it3{std_it2};
  EXPECT_EQ(*our_it3, *std_it3);

  s21::array<int, 3>::iterator our_it4{our_vector.begin()};
  std::array<int, 3>::iterator std_it4{std_vector.begin()};
  s21::array<int, 3>::const_iterator our_it5{our_it4};
  std::array<int, 3>::const_iterator std_it5{std_it4};
  EXPECT_EQ(*our_it5, *std_it5);
}

TEST(ARRAY_CONST_ITERATOR, Equal) {
  s21::array<int, 5> our_vector = {1, 2, 3, 6, 7};
  std::array<int, 5> std_vector = {1, 2, 3, 6, 7};
  s21::array<int, 5>::const_iterator our_it2(our_vector.cbegin());
  std::array<int, 5>::const_iterator std_it2(std_vector.cbegin());
  s21::array<int, 5>::const_iterator our_it3(our_it2);
  std::array<int, 5>::const_iterator std_it3(std_it2);

  EXPECT_EQ(our_it2 == our_it3, 1);
  EXPECT_EQ(our_it2 == our_it3, std_it2 == std_it3);
}

TEST(ARRAY_CONST_ITERATOR, NotEqual) {
  s21::array<int, 5> our_vector = {1, 2, 3, 6, 7};
  std::array<int, 5> std_vector = {1, 2, 3, 6, 7};
  s21::array<int, 5>::const_iterator our_it2(our_vector.cbegin());
  std::array<int, 5>::const_iterator std_it2(std_vector.cbegin());
  s21::array<int, 5>::const_iterator our_it3(our_vector.cend());
  std::array<int, 5>::const_iterator std_it3(std_vector.cend());

  EXPECT_EQ(our_it2 != our_it3, 1);
  EXPECT_EQ(our_it2 != our_it3, std_it2 != std_it3);
}

TEST(ARRAY_CONST_ITERATOR, EqualCopy) {
  s21::array<int, 5> our_vector = {1, 2, 3, 6, 7};
  std::array<int, 5> std_vector = {1, 2, 3, 6, 7};
  s21::array<int, 5>::const_iterator our_it2(our_vector.cbegin());
  std::array<int, 5>::const_iterator std_it2(std_vector.cbegin());
  s21::array<int, 5>::const_iterator our_it3(our_vector.cend());
  std::array<int, 5>::const_iterator std_it3(std_vector.cend());
  our_it2 = our_it3;
  std_it2 = std_it3;

  EXPECT_EQ(our_it2 == our_it3, 1);
  EXPECT_EQ(our_it2 == our_it3, std_it2 == std_it3);
}

TEST(ARRAY_CONST_ITERATOR, Iterations) {
  s21::array<int, 5> our_vector = {1, 2, 3, 6, 7};
  std::array<int, 5> std_vector = {1, 2, 3, 6, 7};
  s21::array<int, 5>::const_iterator our_it1(our_vector.cbegin());
  std::array<int, 5>::const_iterator std_it1(std_vector.cbegin());
  our_it1++;
  std_it1++;
  EXPECT_EQ(*our_it1, 2);
  EXPECT_EQ(*std_it1, 2);

  ++our_it1;
  ++std_it1;
  EXPECT_EQ(*our_it1, 3);
  EXPECT_EQ(*std_it1, 3);

  our_it1 += 2;
  EXPECT_EQ(*our_it1, 7);

  our_it1 -= 2;
  EXPECT_EQ(*our_it1, 3);

  our_it1--;
  std_it1--;
  EXPECT_EQ(*our_it1, 2);
  EXPECT_EQ(*std_it1, 2);

  --our_it1;
  --std_it1;
  EXPECT_EQ(*our_it1, 1);
  EXPECT_EQ(*std_it1, 1);

  s21::array<int, 5>::const_iterator our_it2;
  our_it2 = our_it1 + 1;
  EXPECT_EQ(*our_it2, 2);

  s21::array<int, 5>::const_iterator our_it3;
  our_it3 = our_it2 - 1;
  EXPECT_EQ(*our_it3, 1);

  s21::array<int, 5>::const_iterator our_it4 = our_vector.cbegin();
  EXPECT_EQ(our_it4 - our_vector.cbegin(), 0);
}

TEST(ARRAY, BeginEnd) {
  s21::array<int, 5> our_vector1 = {1, 2, 3, 6, 7};
  std::array<int, 5> std_vector1 = {1, 2, 3, 6, 7};
  s21::array<int, 5> our_vector3 = {3};
  std::array<int, 5> std_vector3 = {3};

  s21::array<int, 5>::iterator our_it1(our_vector1.begin());
  std::array<int, 5>::iterator std_it1(std_vector1.begin());
  EXPECT_EQ(*our_it1, *std_it1);

  s21::array<int, 5>::iterator our_it3(our_vector1.end());
  std::array<int, 5>::iterator std_it3(std_vector1.end());
  our_it3--;
  std_it3--;
  EXPECT_EQ(*our_it3, *std_it3);

  s21::array<int, 5>::iterator our_it5(our_vector3.end());
  std::array<int, 5>::iterator std_it5(std_vector3.end());
  our_it5--;
  std_it5--;
  EXPECT_EQ(*our_it5, *std_it5);
}

TEST(ARRAY, CbeginCend) {
  s21::array<int, 5> our_vector1 = {1, 2, 3, 6, 7};
  std::array<int, 5> std_vector1 = {1, 2, 3, 6, 7};
  s21::array<int, 5> our_vector3 = {3};
  std::array<int, 5> std_vector3 = {3};

  s21::array<int, 5>::const_iterator our_it1(our_vector1.cbegin());
  std::array<int, 5>::const_iterator std_it1(std_vector1.cbegin());
  EXPECT_EQ(*our_it1, *std_it1);

  s21::array<int, 5>::const_iterator our_it3(our_vector1.cend());
  std::array<int, 5>::const_iterator std_it3(std_vector1.cend());
  our_it3--;
  std_it3--;
  EXPECT_EQ(*our_it3, *std_it3);

  s21::array<int, 5>::const_iterator our_it5(our_vector3.cend());
  std::array<int, 5>::const_iterator std_it5(std_vector3.cend());
  our_it5--;
  std_it5--;
  EXPECT_EQ(*our_it5, *std_it5);
}

TEST(ARRAY, SWAP) {
  s21::array<int, 5> our_array1{1, 1, 1, 1, 1};
  s21::array<int, 5> our_array2{2, 2, 2, 2, 2};
  our_array2.swap(our_array1);

  for (size_t i = 0; i < our_array2.size(); i++) {
    EXPECT_EQ(our_array2[i], 1);
    EXPECT_EQ(our_array1[i], 2);
  }
}

TEST(ARRAY, MaxSize) {
  s21::array<int, 5> our_array{1, 1, 1, 1, 1};
  std::array<int, 5> std_array{1, 1, 1, 1, 1};

  EXPECT_EQ(our_array.max_size(), std_array.max_size());
}

TEST(ARRAY, Fill) {
  s21::array<int, 5> our_array{1, 1, 1, 1, 1};
  std::array<int, 5> std_array{1, 1, 1, 1, 1};
  our_array.fill(100);
  std_array.fill(100);

  for (size_t i = 0; i < our_array.size(); i++) {
    EXPECT_EQ(our_array[i], std_array[i]);
  }
}

TEST(SET, DefaultConstructor) {
  std::set<int> our_set{};
  s21::set<int> std_set{};
  EXPECT_EQ(our_set.size(), std_set.size());
}

TEST(SET, ListConstructor) {
  std::set<int> std_set{1, 2, 3, 4, 5, 4, 3, 2, 1};
  s21::set<int> our_set{1, 2, 3, 4, 5, 4, 3, 2, 1};
  s21::set<int>::iterator our_it(our_set.begin());
  std::set<int>::iterator std_it(std_set.begin());

  EXPECT_EQ(our_set.size(), std_set.size());
  for (size_t i = 0; i < our_set.size(); i++) {
    EXPECT_EQ(*std_it, *our_it);
    std_it++;
    our_it++;
  }
}

TEST(SET, ListConstructor2) {
  std::set<std::string> std_set{"Here", "is", "some", "random", "words"};
  s21::set<std::string> our_set{"Here", "is", "some", "random", "words"};
  s21::set<std::string>::iterator our_it(our_set.begin());
  std::set<std::string>::iterator std_it(std_set.begin());

  EXPECT_EQ(our_set.size(), std_set.size());
  for (size_t i = 0; i < our_set.size(); i++) {
    EXPECT_EQ(*std_it, *our_it);
    std_it++;
    our_it++;
  }
}

TEST(SET, CopyConstructor) {
  std::set<std::string> std_set1{"Here", "is", "some", "random", "words"};
  s21::set<std::string> our_set1{"Here", "is", "some", "random", "words"};
  std::set<std::string> std_set2{std_set1};
  s21::set<std::string> our_set2{our_set1};
  s21::set<std::string>::iterator our_it(our_set2.begin());
  std::set<std::string>::iterator std_it(std_set2.begin());

  EXPECT_EQ(our_set2.size(), std_set2.size());
  for (size_t i = 0; i < our_set2.size(); i++) {
    EXPECT_EQ(*std_it, *our_it);
    std_it++;
    our_it++;
  }
}

TEST(SET, MoveConstructor) {
  std::set<std::string> std_set1{"Here", "is", "some", "random", "words"};
  s21::set<std::string> our_set1{"Here", "is", "some", "random", "words"};
  std::set<std::string> std_set2{std::move(std_set1)};
  s21::set<std::string> our_set2{std::move(our_set1)};
  s21::set<std::string>::iterator our_it(our_set2.begin());
  std::set<std::string>::iterator std_it(std_set2.begin());

  EXPECT_EQ(our_set2.size(), std_set2.size());
  EXPECT_EQ(our_set1.size(), 0);
  for (size_t i = 0; i < our_set2.size(); i++) {
    EXPECT_EQ(*std_it, *our_it);
    std_it++;
    our_it++;
  }
}

TEST(SET, EqualCopyConstructor) {
  std::set<std::string> std_set1{"Here", "is", "some", "random", "words"};
  s21::set<std::string> our_set1{"Here", "is", "some", "random", "words"};
  std::set<std::string> std_set2;
  s21::set<std::string> our_set2;
  std_set2 = std_set1;
  our_set2 = our_set1;
  s21::set<std::string>::iterator our_it(our_set2.begin());
  std::set<std::string>::iterator std_it(std_set2.begin());

  EXPECT_EQ(our_set2.size(), std_set2.size());
  for (size_t i = 0; i < our_set2.size(); i++) {
    EXPECT_EQ(*std_it, *our_it);
    std_it++;
    our_it++;
  }
}

TEST(SET, EqualMoveConstructor) {
  std::set<std::string> std_set1{"Here", "is", "some", "random", "words"};
  s21::set<std::string> our_set1{"Here", "is", "some", "random", "words"};
  std::set<std::string> std_set2;
  s21::set<std::string> our_set2;
  std_set2 = std::move(std_set1);
  our_set2 = std::move(our_set1);
  s21::set<std::string>::iterator our_it(our_set2.begin());
  std::set<std::string>::iterator std_it(std_set2.begin());

  EXPECT_EQ(our_set2.size(), std_set2.size());
  EXPECT_EQ(our_set1.size(), 0);
  for (size_t i = 0; i < our_set2.size(); i++) {
    EXPECT_EQ(*std_it, *our_it);
    std_it++;
    our_it++;
  }
}

TEST(SET, End) {
  std::set<std::string> std_set{"Here", "is", "some", "random", "words"};
  s21::set<std::string> our_set{"Here", "is", "some", "random", "words"};

  EXPECT_EQ(*std::prev(our_set.end()), *std::prev(std_set.end()));
}

TEST(SET, Begin) {
  std::set<std::string> std_set{"Here", "is", "some", "random", "words"};
  s21::set<std::string> our_set{"Here", "is", "some", "random", "words"};
  s21::set<std::string>::iterator our_it(our_set.begin());
  std::set<std::string>::iterator std_it(std_set.begin());

  EXPECT_EQ(*our_it, *std_it);
}

TEST(SET, Empty) {
  std::set<int> std_set{1};
  s21::set<int> our_set{1};

  EXPECT_EQ(std_set.empty(), our_set.empty());
}

TEST(SET, Empty2) {
  std::set<int> std_set{};
  s21::set<int> our_set{};

  EXPECT_EQ(std_set.empty(), our_set.empty());
}

TEST(SET, Clear) {
  std::set<int> std_set{1, 2, 3, 4, 5};
  s21::set<int> our_set{1, 2, 3, 4, 5};
  std_set.clear();
  our_set.clear();

  EXPECT_EQ(std_set.empty(), our_set.empty());
}

TEST(SET, Clear2) {
  std::set<int> std_set{};
  s21::set<int> our_set{};
  std_set.clear();
  our_set.clear();

  EXPECT_EQ(std_set.empty(), our_set.empty());
}

TEST(SET, EraseBegin) {
  std::set<int> std_set{1, 2, 3, 4, 5};
  s21::set<int> our_set{1, 2, 3, 4, 5};
  std_set.erase(*std_set.begin());
  our_set.erase(*our_set.begin());
  s21::set<int>::iterator our_it(our_set.begin());
  std::set<int>::iterator std_it(std_set.begin());

  EXPECT_EQ(our_set.size(), std_set.size());
  for (size_t i = 0; i < our_set.size(); i++) {
    EXPECT_EQ(*std_it, *our_it);
    std_it++;
    our_it++;
  }
}

TEST(SET, EraseEnd) {
  std::set<int> std_set{1, 2, 3, 4, 5};
  s21::set<int> our_set{1, 2, 3, 4, 5};
  std_set.erase(*std::prev(std_set.end()));
  our_set.erase(*std::prev(our_set.end()));
  s21::set<int>::iterator our_it(our_set.begin());
  std::set<int>::iterator std_it(std_set.begin());

  EXPECT_EQ(our_set.size(), std_set.size());
  for (size_t i = 0; i < our_set.size(); i++) {
    EXPECT_EQ(*std_it, *our_it);
    std_it++;
    our_it++;
  }
}

TEST(SET, Insert) {
  std::set<int> std_set{1, 2, 3, 4, 5};
  s21::set<int> our_set{1, 2, 3, 4, 5};
  std_set.insert(9);
  our_set.insert(9);
  s21::set<int>::iterator our_it(our_set.begin());
  std::set<int>::iterator std_it(std_set.begin());

  EXPECT_EQ(our_set.size(), std_set.size());
  for (size_t i = 0; i < our_set.size(); i++) {
    EXPECT_EQ(*std_it, *our_it);
    std_it++;
    our_it++;
  }
}

TEST(SET, InsertMany) {
  std::set<int> std_set{1, 2, 3, 4, 5};
  s21::set<int> our_set{1, 2, 3, 4, 5};
  std_set.insert(-1);
  std_set.insert(9);
  our_set.insert_many(9, -1);
  s21::set<int>::iterator our_it(our_set.begin());
  std::set<int>::iterator std_it(std_set.begin());

  EXPECT_EQ(our_set.size(), std_set.size());
  for (size_t i = 0; i < our_set.size(); i++) {
    EXPECT_EQ(*std_it, *our_it);
    std_it++;
    our_it++;
  }
}

TEST(SET, InsertMany2) {
  std::set<int> std_set{1, 2, 3, 4, 5};
  s21::set<int> our_set{1, 2, 3, 4, 5};
  our_set.insert_many();
  s21::set<int>::iterator our_it(our_set.begin());
  std::set<int>::iterator std_it(std_set.begin());

  EXPECT_EQ(our_set.size(), std_set.size());
  for (size_t i = 0; i < our_set.size(); i++) {
    EXPECT_EQ(*std_it, *our_it);
    std_it++;
    our_it++;
  }
}

TEST(SET, InsertMany3) {
  std::set<int> std_set{1, 2, 3, 4, 5};
  s21::set<int> our_set{1, 2, 3, 4, 5};
  our_set.insert_many(5);
  s21::set<int>::iterator our_it(our_set.begin());
  std::set<int>::iterator std_it(std_set.begin());

  EXPECT_EQ(our_set.size(), std_set.size());
  for (size_t i = 0; i < our_set.size(); i++) {
    EXPECT_EQ(*std_it, *our_it);
    std_it++;
    our_it++;
  }
}

TEST(SET, Merge) {
  std::set<int> std_set1{1, 2, 3, 4, 5};
  s21::set<int> our_set1{1, 2, 3, 4, 5};
  std::set<int> std_set2{6};
  s21::set<int> our_set2{6};
  our_set1.merge(our_set2);
  std_set1.merge(std_set2);
  s21::set<int>::iterator our_it(our_set1.begin());
  std::set<int>::iterator std_it(std_set1.begin());

  EXPECT_EQ(our_set1.size(), std_set1.size());
  EXPECT_EQ(our_set2.size(), std_set2.size());
  for (size_t i = 0; i < our_set1.size(); i++) {
    EXPECT_EQ(*std_it, *our_it);
    std_it++;
    our_it++;
  }
}

TEST(SET, Swap) {
  std::set<int> std_set1{1, 2, 3, 4, 5};
  s21::set<int> our_set1{1, 2, 3, 4, 5};
  std::set<int> std_set2{6};
  s21::set<int> our_set2{6};
  our_set1.swap(our_set2);
  std_set1.swap(std_set2);
  s21::set<int>::iterator our_it(our_set1.begin());
  std::set<int>::iterator std_it(std_set1.begin());

  EXPECT_EQ(our_set1.size(), std_set1.size());
  EXPECT_EQ(our_set2.size(), std_set2.size());
  for (size_t i = 0; i < our_set1.size(); i++) {
    EXPECT_EQ(*std_it, *our_it);
    std_it++;
    our_it++;
  }
}

TEST(SET, Iterations) {
  s21::set<int> our_set{1, 2, 3, 6, 7};
  std::set<int> std_set{1, 2, 3, 6, 7};
  s21::set<int>::const_iterator our_it1(our_set.begin());
  std::set<int>::const_iterator std_it1(std_set.begin());
  our_it1++;
  std_it1++;
  EXPECT_EQ(*our_it1, 2);
  EXPECT_EQ(*std_it1, 2);

  ++our_it1;
  ++std_it1;
  EXPECT_EQ(*our_it1, 3);
  EXPECT_EQ(*std_it1, 3);

  our_it1--;
  std_it1--;
  EXPECT_EQ(*our_it1, 2);
  EXPECT_EQ(*std_it1, 2);

  --our_it1;
  --std_it1;
  EXPECT_EQ(*our_it1, 1);
  EXPECT_EQ(*std_it1, 1);
}

TEST(MULTISET, DefaultConstructor) {
  std::multiset<int> our_multiset{};
  s21::multiset<int> std_multiset{};
  EXPECT_EQ(our_multiset.size(), std_multiset.size());
}

TEST(MULTISET, ListConstructor) {
  std::multiset<int> std_multiset{1, 2, 3, 4, 5, 4, 3, 2, 1};
  s21::multiset<int> our_multiset{1, 2, 3, 4, 5, 4, 3, 2, 1};
  s21::multiset<int>::iterator our_it(our_multiset.begin());
  std::multiset<int>::iterator std_it(std_multiset.begin());

  EXPECT_EQ(our_multiset.size(), std_multiset.size());
  for (size_t i = 0; i < our_multiset.size(); i++) {
    EXPECT_EQ(*std_it, *our_it);
    std_it++;
    our_it++;
  }
}

TEST(MULTISET, ListConstructor2) {
  std::multiset<std::string> std_multiset{"Here", "is", "some", "random",
                                          "words"};
  s21::multiset<std::string> our_multiset{"Here", "is", "some", "random",
                                          "words"};
  s21::multiset<std::string>::iterator our_it(our_multiset.begin());
  std::multiset<std::string>::iterator std_it(std_multiset.begin());

  EXPECT_EQ(our_multiset.size(), std_multiset.size());
  for (size_t i = 0; i < our_multiset.size(); i++) {
    EXPECT_EQ(*std_it, *our_it);
    std_it++;
    our_it++;
  }
}

TEST(MULTISET, CopyConstructor) {
  std::multiset<std::string> std_multiset1{"Here", "is", "some", "random",
                                           "words"};
  s21::multiset<std::string> our_multiset1{"Here", "is", "some", "random",
                                           "words"};
  std::multiset<std::string> std_multiset2{std_multiset1};
  s21::multiset<std::string> our_multiset2{our_multiset1};
  s21::multiset<std::string>::iterator our_it(our_multiset2.begin());
  std::multiset<std::string>::iterator std_it(std_multiset2.begin());

  EXPECT_EQ(our_multiset2.size(), std_multiset2.size());
  for (size_t i = 0; i < our_multiset2.size(); i++) {
    EXPECT_EQ(*std_it, *our_it);
    std_it++;
    our_it++;
  }
}

TEST(MULTISET, MoveConstructor) {
  std::multiset<std::string> std_multiset1{"Here", "is", "some", "random",
                                           "words"};
  s21::multiset<std::string> our_multiset1{"Here", "is", "some", "random",
                                           "words"};
  std::multiset<std::string> std_multiset2{std::move(std_multiset1)};
  s21::multiset<std::string> our_multiset2{std::move(our_multiset1)};
  s21::multiset<std::string>::iterator our_it(our_multiset2.begin());
  std::multiset<std::string>::iterator std_it(std_multiset2.begin());

  EXPECT_EQ(our_multiset2.size(), std_multiset2.size());
  EXPECT_EQ(our_multiset1.size(), 0);
  for (size_t i = 0; i < our_multiset2.size(); i++) {
    EXPECT_EQ(*std_it, *our_it);
    std_it++;
    our_it++;
  }
}

TEST(MULTISET, EqualCopyConstructor) {
  std::multiset<std::string> std_multiset1{"Here", "is", "some", "random",
                                           "words"};
  s21::multiset<std::string> our_multiset1{"Here", "is", "some", "random",
                                           "words"};
  std::multiset<std::string> std_multiset2;
  s21::multiset<std::string> our_multiset2;
  std_multiset2 = std_multiset1;
  our_multiset2 = our_multiset1;
  s21::multiset<std::string>::iterator our_it(our_multiset2.begin());
  std::multiset<std::string>::iterator std_it(std_multiset2.begin());

  EXPECT_EQ(our_multiset2.size(), std_multiset2.size());
  for (size_t i = 0; i < our_multiset2.size(); i++) {
    EXPECT_EQ(*std_it, *our_it);
    std_it++;
    our_it++;
  }
}

TEST(MULTISET, EqualMoveConstructor) {
  std::multiset<std::string> std_multiset1{"Here", "is", "some", "random",
                                           "words"};
  s21::multiset<std::string> our_multiset1{"Here", "is", "some", "random",
                                           "words"};
  std::multiset<std::string> std_multiset2;
  s21::multiset<std::string> our_multiset2;
  std_multiset2 = std::move(std_multiset1);
  our_multiset2 = std::move(our_multiset1);
  s21::multiset<std::string>::iterator our_it(our_multiset2.begin());
  std::multiset<std::string>::iterator std_it(std_multiset2.begin());

  EXPECT_EQ(our_multiset2.size(), std_multiset2.size());
  EXPECT_EQ(our_multiset1.size(), 0);
  for (size_t i = 0; i < our_multiset2.size(); i++) {
    EXPECT_EQ(*std_it, *our_it);
    std_it++;
    our_it++;
  }
}

TEST(MULTISET, End) {
  std::multiset<std::string> std_multiset{"Here", "is", "some", "random",
                                          "words"};
  s21::multiset<std::string> our_multiset{"Here", "is", "some", "random",
                                          "words"};

  EXPECT_EQ(*std::prev(our_multiset.end()), *std::prev(std_multiset.end()));
}

TEST(MULTISET, Begin) {
  std::multiset<std::string> std_multiset{"Here", "is", "some", "random",
                                          "words"};
  s21::multiset<std::string> our_multiset{"Here", "is", "some", "random",
                                          "words"};
  s21::multiset<std::string>::iterator our_it(our_multiset.begin());
  std::multiset<std::string>::iterator std_it(std_multiset.begin());

  EXPECT_EQ(*our_it, *std_it);
}

TEST(MULTISET, Empty) {
  std::multiset<int> std_multiset{1};
  s21::multiset<int> our_multiset{1};

  EXPECT_EQ(std_multiset.empty(), our_multiset.empty());
}

TEST(MULTISET, Empty2) {
  std::multiset<int> std_multiset{};
  s21::multiset<int> our_multiset{};

  EXPECT_EQ(std_multiset.empty(), our_multiset.empty());
}

TEST(MULTISET, Clear) {
  std::multiset<int> std_multiset{1, 2, 3, 4, 5};
  s21::multiset<int> our_multiset{1, 2, 3, 4, 5};
  std_multiset.clear();
  our_multiset.clear();

  EXPECT_EQ(std_multiset.empty(), our_multiset.empty());
}

TEST(MULTISET, Clear2) {
  std::multiset<int> std_multiset{};
  s21::multiset<int> our_multiset{};
  std_multiset.clear();
  our_multiset.clear();

  EXPECT_EQ(std_multiset.empty(), our_multiset.empty());
}

TEST(MULTISET, EraseBegin) {
  std::multiset<int> std_multiset{1, 2, 3, 4, 5};
  s21::multiset<int> our_multiset{1, 2, 3, 4, 5};
  std_multiset.erase(*std_multiset.begin());
  our_multiset.erase(*our_multiset.begin());
  s21::multiset<int>::iterator our_it(our_multiset.begin());
  std::multiset<int>::iterator std_it(std_multiset.begin());

  EXPECT_EQ(our_multiset.size(), std_multiset.size());
  for (size_t i = 0; i < our_multiset.size(); i++) {
    EXPECT_EQ(*std_it, *our_it);
    std_it++;
    our_it++;
  }
}

TEST(MULTISET, EraseEnd) {
  std::multiset<int> std_multiset{1, 2, 3, 4, 5};
  s21::multiset<int> our_multiset{1, 2, 3, 4, 5};
  std_multiset.erase(*std::prev(std_multiset.end()));
  our_multiset.erase(*std::prev(our_multiset.end()));
  s21::multiset<int>::iterator our_it(our_multiset.begin());
  std::multiset<int>::iterator std_it(std_multiset.begin());

  EXPECT_EQ(our_multiset.size(), std_multiset.size());
  for (size_t i = 0; i < our_multiset.size(); i++) {
    EXPECT_EQ(*std_it, *our_it);
    std_it++;
    our_it++;
  }
}

TEST(MULTISET, Insert) {
  std::multiset<int> std_multiset{1, 2, 3, 4, 5};
  s21::multiset<int> our_multiset{1, 2, 3, 4, 5};
  std_multiset.insert(9);
  our_multiset.insert(9);
  s21::multiset<int>::iterator our_it(our_multiset.begin());
  std::multiset<int>::iterator std_it(std_multiset.begin());

  EXPECT_EQ(our_multiset.size(), std_multiset.size());
  for (size_t i = 0; i < our_multiset.size(); i++) {
    EXPECT_EQ(*std_it, *our_it);
    std_it++;
    our_it++;
  }
}

TEST(MULTISET, InsertMany) {
  std::multiset<int> std_multiset{1, 2, 3, 4, 5};
  s21::multiset<int> our_multiset{1, 2, 3, 4, 5};
  std_multiset.insert(-1);
  std_multiset.insert(9);
  our_multiset.insert_many(9, -1);
  s21::multiset<int>::iterator our_it(our_multiset.begin());
  std::multiset<int>::iterator std_it(std_multiset.begin());

  EXPECT_EQ(our_multiset.size(), std_multiset.size());
  for (size_t i = 0; i < our_multiset.size(); i++) {
    EXPECT_EQ(*std_it, *our_it);
    std_it++;
    our_it++;
  }
}

TEST(MULTISET, InsertMany2) {
  std::multiset<int> std_multiset{1, 2, 3, 4, 5};
  s21::multiset<int> our_multiset{1, 2, 3, 4, 5};
  our_multiset.insert_many();
  s21::multiset<int>::iterator our_it(our_multiset.begin());
  std::multiset<int>::iterator std_it(std_multiset.begin());

  EXPECT_EQ(our_multiset.size(), std_multiset.size());
  for (size_t i = 0; i < our_multiset.size(); i++) {
    EXPECT_EQ(*std_it, *our_it);
    std_it++;
    our_it++;
  }
}

TEST(MULTISET, Merge) {
  std::multiset<int> std_multiset1{1, 2, 3, 4, 5};
  s21::multiset<int> our_multiset1{1, 2, 3, 4, 5};
  std::multiset<int> std_multiset2{6};
  s21::multiset<int> our_multiset2{6};
  our_multiset1.merge(our_multiset2);
  std_multiset1.merge(std_multiset2);
  s21::multiset<int>::iterator our_it(our_multiset1.begin());
  std::multiset<int>::iterator std_it(std_multiset1.begin());

  EXPECT_EQ(our_multiset1.size(), std_multiset1.size());
  EXPECT_EQ(our_multiset2.size(), std_multiset2.size());
  for (size_t i = 0; i < our_multiset1.size(); i++) {
    EXPECT_EQ(*std_it, *our_it);
    std_it++;
    our_it++;
  }
}

TEST(MULTISET, Swap) {
  std::multiset<int> std_multiset1{1, 2, 3, 4, 5};
  s21::multiset<int> our_multiset1{1, 2, 3, 4, 5};
  std::multiset<int> std_multiset2{6};
  s21::multiset<int> our_multiset2{6};
  our_multiset1.swap(our_multiset2);
  std_multiset1.swap(std_multiset2);
  s21::multiset<int>::iterator our_it(our_multiset1.begin());
  std::multiset<int>::iterator std_it(std_multiset1.begin());

  EXPECT_EQ(our_multiset1.size(), std_multiset1.size());
  EXPECT_EQ(our_multiset2.size(), std_multiset2.size());
  for (size_t i = 0; i < our_multiset1.size(); i++) {
    EXPECT_EQ(*std_it, *our_it);
    std_it++;
    our_it++;
  }
}

TEST(MULTISET, Iterations) {
  s21::multiset<int> our_multiset{1, 2, 3, 6, 7};
  std::multiset<int> std_multiset{1, 2, 3, 6, 7};
  s21::multiset<int>::const_iterator our_it1(our_multiset.begin());
  std::multiset<int>::const_iterator std_it1(std_multiset.begin());
  our_it1++;
  std_it1++;
  EXPECT_EQ(*our_it1, 2);
  EXPECT_EQ(*std_it1, 2);

  ++our_it1;
  ++std_it1;
  EXPECT_EQ(*our_it1, 3);
  EXPECT_EQ(*std_it1, 3);

  our_it1--;
  std_it1--;
  EXPECT_EQ(*our_it1, 2);
  EXPECT_EQ(*std_it1, 2);

  --our_it1;
  --std_it1;
  EXPECT_EQ(*our_it1, 1);
  EXPECT_EQ(*std_it1, 1);
}

// DEFAULT CONSTRUCTOR
TEST(s21_map, ConstructorNoParams) {
  s21::map<int, double> first_map;
  s21::map<char, std::string> second_map;
  s21::map<bool, test_struct> third_map;
  EXPECT_EQ(first_map.size(), 0);
  EXPECT_EQ(second_map.size(), 0);
  EXPECT_EQ(third_map.size(), 0);
}

// STD INITIALIZER CONSTRUCTOR
TEST(s21_map, StdInitConstructor) {
  s21::map<int, std::string> first_map = {
      {1, "Anna Asti"}, {2, "Bruno Mars"}, {18, "Rihanna"}};
  EXPECT_EQ(first_map.size(), 3);
}

// COPY CONSTRUCTOR
TEST(s21_map, CopyConstructor) {
  s21::map<int, std::string> first_map;
  std::pair<int, std::string> intering_value1{1, "Anna Asti"};
  std::pair<int, std::string> intering_value2{2, "Bruno Mars"};
  std::pair<int, std::string> intering_value3{18, "Rihanna"};
  first_map.insert(intering_value1);
  first_map.insert(intering_value2);
  first_map.insert(intering_value3);
  s21::map<int, std::string> second_map(first_map);
  EXPECT_EQ(second_map.size(), 3);
}

// MOVE CONSTRUCTOR
TEST(s21_map, MoveConstructor) {
  s21::map<int, std::string> first_map;
  std::pair<int, std::string> intering_value1{1, "Anna Asti"};
  std::pair<int, std::string> intering_value2{2, "Bruno Mars"};
  std::pair<int, std::string> intering_value3{18, "Rihanna"};
  first_map.insert(intering_value1);
  first_map.insert(intering_value2);
  first_map.insert(intering_value3);
  s21::map<int, std::string> second_map(std::move(first_map));
  EXPECT_EQ(second_map.size(), 3);
  EXPECT_EQ(first_map.size(), 0);
}

// COPY OPERATOR
TEST(s21_map, CopyOperator) {
  s21::map<int, std::string> first_map;
  std::pair<int, std::string> intering_value1{1, "Anna Asti"};
  std::pair<int, std::string> intering_value2{2, "Bruno Mars"};
  std::pair<int, std::string> intering_value3{18, "Rihanna"};
  first_map.insert(intering_value1);
  first_map.insert(intering_value2);
  first_map.insert(intering_value3);
  s21::map<int, std::string> second_map = first_map;
  EXPECT_EQ(second_map.size(), 3);
}

// MOVE OPERATOR
TEST(s21_map, MoveOperator) {
  s21::map<int, std::string> first_map;
  std::pair<int, std::string> intering_value1{1, "Anna Asti"};
  std::pair<int, std::string> intering_value2{2, "Bruno Mars"};
  std::pair<int, std::string> intering_value3{18, "Rihanna"};
  first_map.insert(intering_value1);
  first_map.insert(intering_value2);
  first_map.insert(intering_value3);
  s21::map<int, std::string> second_map = std::move(first_map);
  EXPECT_EQ(second_map.size(), 3);
  EXPECT_EQ(first_map.size(), 0);
}

// AT (MAP ELEMENT ACCESS)
TEST(s21_map, AtPositive) {
  s21::map<int, std::string> first_map;
  std::pair<int, std::string> intering_value1{1, "Anna Asti"};
  std::pair<int, std::string> intering_value2{2, "Bruno Mars"};
  std::pair<int, std::string> intering_value3{18, "Rihanna"};
  first_map.insert(intering_value1);
  first_map.insert(intering_value2);
  first_map.insert(intering_value3);
  EXPECT_EQ(first_map.at(1), "Anna Asti");
  EXPECT_EQ(first_map.at(2), "Bruno Mars");
  EXPECT_EQ(first_map.at(18), "Rihanna");
}

TEST(s21_map, AtNegative) {
  s21::map<int, std::string> first_map;
  std::pair<int, std::string> intering_value1{1, "Anna Asti"};
  std::pair<int, std::string> intering_value2{2, "Bruno Mars"};
  std::pair<int, std::string> intering_value3{18, "Rihanna"};
  first_map.insert(intering_value1);
  first_map.insert(intering_value2);
  first_map.insert(intering_value3);
  EXPECT_THROW(first_map.at(3), std::out_of_range);
  EXPECT_THROW(first_map.at(0), std::out_of_range);
}

// OPERATOR[] (MAP ELEMENT ACCESS)
TEST(s21_map, OperatorBrackets) {
  s21::map<int, int> first_map;
  std::pair<int, int> intering_value1{1, 11};
  std::pair<int, int> intering_value2{2, 22};
  std::pair<int, int> intering_value3{18, 1818};
  first_map.insert(intering_value1);
  first_map.insert(intering_value2);
  first_map.insert(intering_value3);
  EXPECT_EQ(first_map[2], 22);
  EXPECT_EQ(first_map[3], 0);
}

// ITERATOR BEGIN()
TEST(s21_map, BeginEndEmpty) {
  s21::map<int, int> empty_map;
  EXPECT_EQ(empty_map.begin(), empty_map.end());
}

// ITERATOR BEGIN()
TEST(s21_map, Begin) {
  s21::map<int, int> first_map;
  std::pair<int, int> intering_value1{1, 11};
  std::pair<int, int> intering_value2{2, 22};
  std::pair<int, int> intering_value3{18, 1818};
  first_map.insert(intering_value1);
  first_map.insert(intering_value2);
  first_map.insert(intering_value3);
  auto it = first_map.begin();
  EXPECT_EQ(it.getCurrent()->value, 11);
}

// ITERATOR END()
TEST(s21_map, End) {
  s21::map<int, int> first_map;
  std::pair<int, int> intering_value1{1, 11};
  std::pair<int, int> intering_value2{2, 22};
  std::pair<int, int> intering_value3{18, 1818};
  first_map.insert(intering_value1);
  first_map.insert(intering_value2);
  first_map.insert(intering_value3);
  auto it = first_map.end();
  EXPECT_EQ(it.getCurrent(), nullptr);
}

// EMPTY
TEST(s21_map, EmptyMap) {
  s21::map<int, int> empty_map;
  EXPECT_EQ(empty_map.empty(), true);
}

TEST(s21_map, NotEmptyMap) {
  s21::map<int, int> first_map;
  std::pair<int, int> intering_value1{1, 11};
  std::pair<int, int> intering_value2{2, 22};
  std::pair<int, int> intering_value3{18, 1818};
  first_map.insert(intering_value1);
  first_map.insert(intering_value2);
  first_map.insert(intering_value3);
  EXPECT_EQ(first_map.empty(), false);
}

// SIZE
TEST(s21_map, SizeZeroMap) {
  s21::map<int, int> empty_map;
  EXPECT_EQ(empty_map.size(), 0);
}

TEST(s21_map, DifferentSizeMap) {
  s21::map<int, int> first_map;
  std::pair<int, int> intering_value1{1, 11};
  std::pair<int, int> intering_value2{2, 22};
  std::pair<int, int> intering_value3{18, 1818};
  first_map.insert(intering_value1);
  EXPECT_EQ(first_map.size(), 1);
  first_map.insert(intering_value2);
  EXPECT_EQ(first_map.size(), 2);
  first_map.insert(intering_value3);
  EXPECT_EQ(first_map.size(), 3);
}

// MAX SIZE
TEST(s21_map, MaxSize) {
  s21::map<int, double> first_map;
  s21::map<char, std::string> second_map;
  std::map<int, double> fourth_map;
  std::map<char, std::string> fith_map;
  EXPECT_EQ(first_map.max_size(), fourth_map.max_size());
  EXPECT_EQ(second_map.max_size(), fith_map.max_size());
}

// CLEAR
TEST(s21_map, Clear) {
  s21::map<int, int> first_map;
  std::pair<int, int> intering_value1{1, 11};
  std::pair<int, int> intering_value2{2, 22};
  std::pair<int, int> intering_value3{18, 1818};
  first_map.insert(intering_value1);
  first_map.insert(intering_value2);
  first_map.insert(intering_value3);
  EXPECT_EQ(first_map.size(), 3);
  first_map.clear();
  EXPECT_EQ(first_map.size(), 0);
}

// INSERT 1
TEST(s21_map, InsertType1NewNode) {
  s21::map<int, int> first_map;
  std::pair<int, int> intering_value1{1, 11};
  std::pair<int, int> intering_value2{2, 22};
  std::pair<int, int> intering_value3{18, 1818};
  first_map.insert(intering_value1);
  first_map.insert(intering_value2);
  first_map.insert(intering_value3);
  std::pair<int, int> intering_value4{23, 2323};
  EXPECT_EQ(first_map.insert(intering_value4).second, true);
}

TEST(s21_map, InsertType1ExistingNode) {
  s21::map<int, int> first_map;
  std::pair<int, int> intering_value1{1, 11};
  std::pair<int, int> intering_value2{2, 22};
  std::pair<int, int> intering_value3{18, 1818};
  first_map.insert(intering_value1);
  first_map.insert(intering_value2);
  first_map.insert(intering_value3);
  std::pair<int, int> intering_value4{2, 225};
  EXPECT_EQ(first_map.insert(intering_value4).second, false);
}

// INSERT 2
TEST(s21_map, InsertType2NewNode) {
  s21::map<int, int> first_map;
  std::pair<int, int> intering_value1{1, 11};
  std::pair<int, int> intering_value2{2, 22};
  std::pair<int, int> intering_value3{18, 1818};
  first_map.insert(intering_value1);
  first_map.insert(intering_value2);
  first_map.insert(intering_value3);
  EXPECT_EQ(first_map.insert(28, 2828).second, true);
}

TEST(s21_map, InsertType2ExistingNode) {
  s21::map<int, int> first_map;
  std::pair<int, int> intering_value1{1, 11};
  std::pair<int, int> intering_value2{2, 22};
  std::pair<int, int> intering_value3{18, 1818};
  first_map.insert(intering_value1);
  first_map.insert(intering_value2);
  first_map.insert(intering_value3);
  EXPECT_EQ(first_map.insert(2, 2828).second, false);
}

// INSERT OR ASSIGN
TEST(s21_map, InsertType3NewNode) {
  s21::map<int, int> first_map;
  std::pair<int, int> intering_value1{1, 11};
  std::pair<int, int> intering_value2{2, 22};
  std::pair<int, int> intering_value3{18, 1818};
  first_map.insert(intering_value1);
  first_map.insert(intering_value2);
  first_map.insert(intering_value3);
  EXPECT_EQ(first_map.insert_or_assign(28, 2828).second, true);
}

TEST(s21_map, InsertType3ExistingNode) {
  s21::map<int, int> first_map;
  std::pair<int, int> intering_value1{1, 11};
  std::pair<int, int> intering_value2{2, 22};
  std::pair<int, int> intering_value3{18, 1818};
  first_map.insert(intering_value1);
  first_map.insert(intering_value2);
  first_map.insert(intering_value3);
  EXPECT_EQ(first_map.insert_or_assign(2, 2828).second, false);
}

// SWAP
TEST(s21_map, SWAP) {
  s21::map<int, int> first_map;
  std::pair<int, int> intering_value1{1, 11};
  std::pair<int, int> intering_value2{2, 22};
  std::pair<int, int> intering_value3{18, 1818};
  first_map.insert(intering_value1);
  first_map.insert(intering_value2);
  first_map.insert(intering_value3);
  s21::map<int, int> second_map;
  second_map.swap(first_map);
  EXPECT_EQ(first_map.size(), 0);
  EXPECT_EQ(second_map.size(), 3);
}

// MERGE
TEST(s21_map, MergeNotEmpty) {
  s21::map<int, int> first_map;
  std::pair<int, int> intering_value1{1, 11};
  std::pair<int, int> intering_value2{2, 22};
  std::pair<int, int> intering_value3{18, 1818};
  first_map.insert(intering_value1);
  first_map.insert(intering_value2);
  first_map.insert(intering_value3);
  s21::map<int, int> second_map;
  std::pair<int, int> intering_value4{3, 33};
  std::pair<int, int> intering_value5{5, 55};
  std::pair<int, int> intering_value6{29, 2929};
  second_map.insert(intering_value4);
  second_map.insert(intering_value5);
  second_map.insert(intering_value6);
  first_map.merge(second_map);
  EXPECT_EQ(first_map.size(), 6);
  EXPECT_EQ(second_map.size(), 0);
}

TEST(s21_map, MergeEmpty) {
  s21::map<int, int> first_map;
  std::pair<int, int> intering_value1{1, 11};
  std::pair<int, int> intering_value2{2, 22};
  std::pair<int, int> intering_value3{18, 1818};
  first_map.insert(intering_value1);
  first_map.insert(intering_value2);
  first_map.insert(intering_value3);
  s21::map<int, int> second_map;
  first_map.merge(second_map);
  EXPECT_EQ(first_map.size(), 3);
}

// CONTAINS
TEST(s21_map, Contains) {
  s21::map<int, int> first_map;
  std::pair<int, int> intering_value1{1, 11};
  std::pair<int, int> intering_value2{2, 22};
  std::pair<int, int> intering_value3{18, 1818};
  first_map.insert(intering_value1);
  first_map.insert(intering_value2);
  first_map.insert(intering_value3);
  EXPECT_EQ(first_map.contains(1), true);
  EXPECT_EQ(first_map.contains(2), true);
  EXPECT_EQ(first_map.contains(18), true);
  EXPECT_EQ(first_map.contains(5), false);
}

// ERASE
TEST(s21_map, Erase) {
  s21::map<int, int> first_map;
  std::pair<int, int> intering_value1{1, 11};
  std::pair<int, int> intering_value2{2, 22};
  std::pair<int, int> intering_value3{18, 1818};
  first_map.insert(intering_value1);
  first_map.insert(intering_value2);
  first_map.insert(intering_value3);
  auto it = first_map.begin();
  first_map.erase(it);
  EXPECT_EQ(first_map.contains(1), false);
  EXPECT_EQ(first_map.size(), 2);
}

// RBTree insert existing key
/*TEST(RBTreeTest, InsertExistingKey) {
    RBTree<int, int> my_tree;
    my_tree.insert(1, 11);
    my_tree.insert(5, 55);
    my_tree.insert(9, 99);
    EXPECT_THROW(my_tree.insert(5, 66), std::out_of_range);
}*/

// Map insert and erase different cases
TEST(RBTree, InsertBalance) {
  RBTree<int, double> tree;
  tree.insert(10, 10);
  tree.insert(12, 12);
  tree.insert(11, 11);
  tree.insert(5, 5);
  tree.insert(9, 9);
  tree.insert(1, 1);
  tree.insert(15, 15);
  tree.insert(13, 13);
  tree.insert(8, 8);
  tree.insert(4, 4);
  tree.insert(14, 14);
  tree.insert(2, 2);
  tree.insert(6, 6);
  tree.insert(7, 7);
  tree.insert(3, 3);
  tree.insert(16, 16);
  tree.insert(17, 17);
  tree.insert(18, 18);
  tree.insert(19, 19);
  tree.insert(20, 20);
  tree.insert(21, 21);
  tree.insert(22, 22);
  tree.insert(23, 23);
  tree.insert(24, 24);
  tree.insert(25, 25);
  tree.insert(26, 26);
  tree.insert(27, 27);
  tree.insert(28, 28);
  tree.insert(29, 29);
  tree.insert(30, 30);
  for (int i = 0; i < 30; ++i) {
    tree.remove(i + 1);
  }
  EXPECT_EQ(tree.size(), 0);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}