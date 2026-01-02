// Step 1: Define the Abstract Expression
#include <iostream>
#include <string>
#include <map>

// Abstract Expression
class Expression {
public:
    virtual int interpret() const = 0;
    virtual ~Expression() = default;
};


// Step 2: Define the Terminal Expressions
// Terminal Expression: Number
class Number : public Expression {
private:
    int value;
    
public:
    Number(int value) : value(value) {}
    
    int interpret() const override {
        return value;
    }
};


// Step 3: Define the Non-Terminal Expressions
// Non-Terminal Expression: Addition
class AddExpression : public Expression {
private:
    Expression* left;
    Expression* right;
    
public:
    AddExpression(Expression* left, Expression* right) : left(left), right(right) {}

    int interpret() const override {
        return left->interpret() + right->interpret();
    }
    
    ~AddExpression() {
        delete left;
        delete right;
    }
};

// Non-Terminal Expression: Subtraction
class SubtractExpression : public Expression {
private:
    Expression* left;
    Expression* right;
    
public:
    SubtractExpression(Expression* left, Expression* right) : left(left), right(right) {}

    int interpret() const override {
        return left->interpret() - right->interpret();
    }
    
    ~SubtractExpression() {
        delete left;
        delete right;
    }
};

// Step 4: Using the Interpreter
int main() {
    // Create expressions
    Expression* three = new Number(3);
    Expression* five = new Number(5);
    
    // Create an addition expression (3 + 5)
    Expression* addExpr = new AddExpression(three, five);
    
    std::cout << "Result of 3 + 5: " << addExpr->interpret() << std::endl; // Outputs 8

    // Create expressions for subtraction (10 - 2)
    Expression* ten = new Number(10);
    Expression* two = new Number(2);
    
    Expression* subtractExpr = new SubtractExpression(ten, two);
    
    std::cout << "Result of 10 - 2: " << subtractExpr->interpret() << std::endl; // Outputs 8

    // Clean up memory
    delete addExpr;
    delete subtractExpr;

    return 0;
}


/*
OUTPUT:

Result of 3 + 5: 8
Result of 10 - 2: 8

*/
