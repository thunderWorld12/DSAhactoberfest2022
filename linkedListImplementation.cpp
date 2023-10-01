#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    char data;
    Node* next;
};

class LinkedListStack {
private:
    Node* top;

public:
    LinkedListStack() : top(nullptr) {}

    ~LinkedListStack() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    bool isEmpty() const {
        return top == nullptr;
    }

    void push(char data) {
        Node* newNode = new Node{data, top};
        top = newNode;
    }

    char pop() {
        if (isEmpty()) {
            std::cerr << "Error: Stack is empty." << std::endl;
            return '\0';
        }
        char data = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return data;
    }

    char peek() const {
        if (isEmpty()) {
            std::cerr << "Error: Stack is empty." << std::endl;
            return '\0';
        }
        return top->data;
    }
};

bool isValidParentheses(string s) {
    LinkedListStack stack;
    std::unordered_map<char, char> bracket_pairs = {{')', '('}, {']', '['}, {'}', '{'}};

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            stack.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (stack.isEmpty() || stack.peek() != bracket_pairs[c]) {
                return false;
            }
            stack.pop();
        }
    }

    return stack.isEmpty();
}

int main() {
    cout << isValidParentheses("()") << endl;  // true
    cout << isValidParentheses("()[]{}") << endl;  // true
    cout << isValidParentheses("(]") << endl;  // false
    cout << isValidParentheses("([)]") << endl;  // false
    cout << isValidParentheses("{[]}") << endl;  // true

    return 0;
}
