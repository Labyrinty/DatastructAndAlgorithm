#pragma once

#include <string>
#include <iostream>
#include <unordered_map>
#include <cmath>    
#include "MyStack.h"

namespace {
    std::unordered_map<char, int> precedence = {
        {'+', 1},
        {'-', 1},
        {'*', 2},
        {'/', 2},
        {'^', 3},
        {'(', 0},
        {')', 0}
    };
}

double calculate(double left, double right, char op) {
    switch (op) {
    case '+': return left + right;
    case '-': return left - right;
    case '*': return left * right;
    case '/':
        if (right == 0) {
            throw std::runtime_error("Division by zero"); 
        }
        return left / right;
    case '^': return pow(left, right);
    default: throw std::invalid_argument(std::string("Unknown operator: ") + op);
    }
}

double RunProject() {
    LinkListBasedStack<char> opChar;
    LinkListBasedStack<double> opNum;
    char op;

    while ((op = getchar()) != '\n' && op != EOF) {
        if (op == ' ') {
            continue;
        }

        if (isdigit(op) || op == '.') {
            ungetc(op, stdin); 
            double num;
            if (!(std::cin >> num)) {
                throw std::invalid_argument("Invalid number in expression");
            }
            opNum.Push(num);
        }
        else if (op == '(') {
            opChar.Push(op);
        }
        else if (op == ')') {
            while (!opChar.IsEmpty() && opChar.Top() != '(') {
                if (opNum.Size() < 2) {
                    throw std::invalid_argument("Mismatched parentheses (insufficient operands)");
                }
                char oper = opChar.Top();
                opChar.Pop();
                double right = opNum.Top(); opNum.Pop();
                double left = opNum.Top(); opNum.Pop();
                opNum.Push(calculate(left, right, oper));
            }
            if (opChar.IsEmpty()) {
                throw std::invalid_argument("Mismatched parentheses (no matching '(')");
            }
            opChar.Pop();
        }
        else if (precedence.count(op)) {
            if (op == '-' && (opNum.IsEmpty() || opChar.Top() == '(' || precedence[opChar.Top()] > 0)) {
                opNum.Push(0.0);    
                opChar.Push('-');      
                continue;
            }

            while (!opChar.IsEmpty()) {
                char topOp = opChar.Top();
           
                if (op == '^') {
                    if (precedence[topOp] > precedence[op]) {
                        break;
                    }
                }
               
                else {
                    if (precedence[topOp] >= precedence[op]) {
                        break;
                    }
                }

                if (opNum.Size() < 2) {
                    throw std::invalid_argument("Insufficient operands for operator");
                }
                opChar.Pop();
                double right = opNum.Top(); opNum.Pop();
                double left = opNum.Top(); opNum.Pop();
                opNum.Push(calculate(left, right, topOp));
            }
            opChar.Push(op); 
        }
        else {
            if (op != '=') {
                throw std::invalid_argument(std::string("Invalid character: ") + op);
			}
        }
    }

    while (!opChar.IsEmpty()) {
        char topOp = opChar.Top();
        if (topOp == '(') {
            throw std::invalid_argument("Mismatched parentheses (no matching ')')");
        }

        if (opNum.Size() < 2) {
            throw std::invalid_argument("Insufficient operands for remaining operators");
        }
        opChar.Pop();
        double right = opNum.Top(); opNum.Pop();
        double left = opNum.Top(); opNum.Pop();
        opNum.Push(calculate(left, right, topOp));
    }

    if (opNum.Size() != 1) {
        throw std::invalid_argument("Invalid expression (mismatched operands and operators)");
    }

    return opNum.Top();
}