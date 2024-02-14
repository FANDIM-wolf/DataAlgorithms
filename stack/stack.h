#include <iostream>

struct StackNode {
    int data;
    StackNode* prev;
    StackNode* next;
};

class Stack {
 private:
  StackNode* top_;

 public:
  Stack() : top_(nullptr) {}

  void push(int element) {
    StackNode* newNode = new StackNode{element, nullptr, top_};
    if (top_ != nullptr) {
      top_->prev = newNode;
    }
    top_ = newNode;
  }

  void pop() {
    if (top_ != nullptr) {
      StackNode* top = top_;
      top_ = top_->next;
      if (top_ != nullptr) {
        top_->prev = nullptr;
      }
      delete top;
    }
  }

  int top() const {
    if (top_ != nullptr) {
      return top_->data;
    }
    throw std::runtime_error("Stack is empty");
  }

  void printForward() const {
    if (top_ == nullptr) {
      std::cout << "Stack is empty" << std::endl;
      return;
    }
    for (const auto& node : {top_, top_->next}) {
      if (node != nullptr) {
        std::cout << " -> ";
        
      }
      std::cout << node->data;
     
    }
    std::cout << std::endl;
  }

  void printReverse() const {
    if (top_ == nullptr) {
      std::cout << "Stack is empty" << std::endl;
      return;
    }
    for (auto it = top_; it != nullptr; it = it->prev) {
      if (it->next != nullptr) {
        std::cout << " -> ";
      }
      std::cout << it->data;
    }
    std::cout << std::endl;
  }
};

int main() {
    Stack s;
    s.push(2);
    s.push(4);
    s.printForward();
    return 0;
}
