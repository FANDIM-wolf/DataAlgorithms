/*
Stack realization

Authour : Shishov Mikhail
*/
#include <iostream>

struct StackNode {
    
    int data;
    StackNode* prev;
};

class Stack {
private:
    StackNode* top_; // top element of stack

public:
    Stack() {
        
        top_ = nullptr;
    }
    //add element in stack
    void push(int element ) {
        StackNode* newNode = new StackNode{ element , top_  };
        if (top_ == nullptr) {
            newNode->prev = top_;
        }
        newNode->prev = top_;
        top_ = newNode;
       
    }
    //remove element from stack
    void pop() {
        if (top_ != nullptr) {
            StackNode* top = top_;
            top_ = top_->prev;
            delete top;
        }
    }
   
    //print all elements in forward
    void printForward() const {
        
        if (top_ == nullptr) {
            std::cout << "Stack is empty" << std::endl;
            return;
        }
        StackNode* current_node = top_;
        while (current_node != nullptr) {
            std::cout << "->";
            std::cout << current_node->data << std::endl;
            current_node = current_node->prev;
        }
       
    }
   
};

int main() {
    
    Stack s;
    s.push(2);
    s.push(4);
    s.push(5);
    s.printForward();
    std::cout << "After removing" << std::endl;
    s.pop();
    s.printForward();
    return 0;
}
