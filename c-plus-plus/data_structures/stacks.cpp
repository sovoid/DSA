#include <cassert>
#include <iostream>

struct node {
  int data;
  node *next;
};

class stack {
private:
  node *top;
  int len;

public:
  stack() {
    top = nullptr;
    len = 0;
  }

  ~stack() {}

  bool empty() { return (top == nullptr); }

  void push(int val) {
    node *newNode = new node();
    newNode->data = val;
    newNode->next = top;
    top = newNode;
    len++;
  }

  void pop() {
    if (empty()) {
      std::cout << "Empty stack. Nothing to pop !"
                << "\n";
    } else {
      node *temp = top;
      top = top->next;
      delete temp;
      len--;
    }
  }

  int peek() {
    assert(top != nullptr);
    return top->data;
  }

  void clear() {
    node *temp;
    while (top) {
      temp = top;
      top = top->next;
      delete temp;
      len--;
    }
  }

  int size() { return len; }
};

int main() {
    stack test_st;
    test_st.push(1);
    test_st.push(2);
    test_st.push(3);
    std::cout << "Number of elements in stack: " << test_st.size() << "\n";
    test_st.pop();
    std::cout << "Top element of the stack is: " << test_st.peek() << "\n";
    assert(test_st.size() == 2);
    return 0;
}