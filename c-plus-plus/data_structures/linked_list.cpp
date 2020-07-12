#include <cassert>
#include <iostream>

struct node {
  int data;
  node *next;
};

class linked_list {
private:
  node *head;
  int len;

public:
  linked_list() {
    head = nullptr;
    len = 0;
  }

  ~linked_list() {}

  void insert(int val) {
    node *newNode = new node();
    newNode->data = val;
    newNode->next = head;
    head = newNode;
    len++;
  }

  void remove(int val) {
    if (!head) {
      std::cout << "Empty linked list. Nothing to remove !"
                << "\n";
    } else if (head->data == val) {
      node *temp = head;
      head = head->next;
      delete temp;
      len--;
    } else {
      node *previous, *current;

      current = head;
      while (current && current->data != val) {
        previous = current;
        current = current->next;
      }

      if (current) {
        previous->next = current->next;
        delete current;
        len--;
      } else {
        std::cout << "Value not found in the linked list !"
                  << "\n";
      }
    }
  }

  int mid() {
    node *slow, *fast;
    slow = head;
    fast = head->next;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    return slow->data;
  }

  void clear() {
    node *temp;
    while (head) {
      temp = head;
      head = head->next;
      delete temp;
      len--;
    }
  }

  int size() { return len; }
};

int main() {
  linked_list test_list;
  test_list.insert(4);
  test_list.insert(3);
  test_list.insert(2);
  test_list.insert(1);
  std::cout << "Size of linked list is: " << test_list.size() << "\n";
  std::cout << "Middle element of linked list is: " << test_list.mid() << "\n";
  test_list.remove(2);
  assert(test_list.size() == 3);
  return 0;
}
