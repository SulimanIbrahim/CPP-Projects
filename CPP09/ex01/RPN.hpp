#pragma once
#include <iostream>
#include <exception>
#include <algorithm>
#include <stack>
#include <string>
#include <sstream>
#include <cctype>

enum Operator {
    ADD,
    SUB,
    MUL,
    DIV
};


class RPN {
    private:
        std::stack<std::string> _rpn;
        
    public:
        RPN();
        ~RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        void tokenizeRPN(const std::string& rpn);
        bool parseRPNtoken(const std::string& token);
        bool parseNumbersInStack();
        Operator specifyOperator(char op);
};