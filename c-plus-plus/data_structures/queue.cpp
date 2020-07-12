#include <cassert>
#include <iostream>

struct node {
  int data;
  node *next;
};

class queue {
private:
  node *head;
  node *tail;
  int len;

public:
  queue() {
    head = nullptr;
    tail = nullptr;
    len = 0;
  }

  ~queue() {}

  bool empty() { return (head == nullptr); }

  void enQueue(int item) {
    node *newNode = new node();
    newNode->data = item;
    newNode->next = nullptr;

    if (empty()) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
    len++;
  }

  void deQueue() {
    if (empty()) {
      std::cout << "Empty queue. Nothing to dequeue !"
                << "\n";
    } else {
        node *temp = head;
        head = head->next;
        delete temp;
        len--;
    }
  }

  int front() {
      assert(head != nullptr);
      return head->data;
  }

  int back() {
      assert(tail != nullptr);
      return tail->data;
  }

  void clear() {
      node *temp;
      while(head) {
          temp = head;
          head = head->next;
          delete temp;
          len--;
      }
  }

  int size() {
      return len;
  }
};

int main() {
    queue test_q;
    test_q.enQueue(1);
    test_q.enQueue(2);
    test_q.enQueue(3);
    assert(test_q.size() == 3);
    test_q.deQueue();
    assert(test_q.size() == 2);
    std::cout << "Top element of the queue is: " << test_q.front() << "\n";
    std::cout << "Rear element of the queue is: " << test_q.back() << "\n";
}