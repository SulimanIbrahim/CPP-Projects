#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& other) {
    _rpn = other._rpn;
}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        _rpn = other._rpn;
    }
    return *this;
}

bool RPN::parseRPNtoken(const std::string& token) {
    if (token.empty()) {
        return false;
    }
    if (token.length() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')) {
        return true;
    }
    if (token.find_first_not_of("0123456789") != std::string::npos) {
        return false;
    }
    return true;
}

bool RPN::parseNumbersInStack() {
    if (_rpn.size() < 2) {
        return false;
    }
    return true;   
}

Operator RPN::specifyOperator(char op) {
    
    if (op == '+') {
        return ADD;
    } else if (op == '-') {
        return SUB;
    } else if (op == '*') {
        return MUL;
    } else if (op == '/') {
        return DIV;
    } else {
        throw std::runtime_error("Error: invalid operator");
    }
}

void RPN::tokenizeRPN(const std::string& rpn) {
    std::string token;
    std::istringstream iss(rpn);
    std::stack<int> calcStack;
    
    while (std::getline(iss, token, ' ')) {
        if (token.empty()) {
            continue; // Skip empty tokens
        }
        
        if (!parseRPNtoken(token)) {
            throw std::runtime_error("Error: invalid token: " + token);
        }
        
        // If token is an operator
        if (token.length() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')) {
            if (calcStack.size() < 2) {
                throw std::runtime_error("Error: not enough operands for operator: " + token);
            }
            
            int b = calcStack.top();
            calcStack.pop();
            int a = calcStack.top();
            calcStack.pop();
            
            switch (token[0]) {
                case '+':
                    calcStack.push(a + b);
                    break;
                case '-':
                    calcStack.push(a - b);
                    break;
                case '*':
                    calcStack.push(a * b);
                    break;
                case '/':
                    if (b == 0) {
                        throw std::runtime_error("Error: division by zero");
                    }
                    calcStack.push(a / b);
                    break;
            }
        }
        else {
            std::istringstream numStream(token);
            int number;
            if (!(numStream >> number)) {
                throw std::runtime_error("Error: invalid number: " + token);
            }
            calcStack.push(number);
        }
    }
    
    if (calcStack.size() != 1) {
        throw std::runtime_error("Error: invalid RPN expression (too many values left on stack)");
    }
    
    std::cout << calcStack.top() << std::endl;
}

