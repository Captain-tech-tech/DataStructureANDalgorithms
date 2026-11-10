// Expression tree: An expression tree is a binary tree used to represent an arithmetic or logical expression.
// ---> it represents an expression in a hierarchical structure where:
// 1) Internal nodes contain operators such as +, -, *, /.
// 2) Leaf nodes contain operands such as variables (a, b, c) or constants (5, 10, 20).
// An expression tree represents the structure and order of operations, not just the symbols of an expression.


// Why the operator is a parent node, and its operands are its children.
// e.g: the + operator needs two values:
// One value from the left side (a).
// One value from the right side (b).


// Why is an expression tree binary
// An expression tree for ordinary arithmetic operations is binary because the basic arithmetic operators are binary operators.



// Before constructing an expression tree, we commonly convert an infix expression into postfix notation.
// We use a stack to temporarily store operators while converting infix into postfix.
// We need a stack because operators must be output in the correct precedence and associativity order.Higher precedence operators are processed before lower precedence operators.

// Algorithm: Infix to postfix
// Read the infix expression from left to right.
// 1) If the symbol is an operand, add it directly to the postfix expression.
// 2) If the symbol is (, push it onto the stack.
// 3) If the symbol is ), pop operators into the postfix expression until ( is found. Remove the (.
// 4) If the symbol is an operator:
// -- Compare its precedence with the operator at the top of the stack.
// -- Pop higher-precedence operators.
// -- Also pop equal-precedence operators when the current operator is left-associative.
// -- Push the current operator.
// 5) After reading the entire expression, pop all remaining operators into the postfix expression.





// Postfix expression to expression tree
// Now we have a postfix expression.
// We can construct an expression tree from it using another stack.
// 
// The idea is simple:
// Every operand becomes a new one-node tree.
// Every operator combines two existing trees.
// The operator becomes the root of the new tree.

// Algorithm : read the postfix expression from left to right.

// Case 1: Symbol is an operand
// 1) Create a new tree node containing the operand.
// 2) Push that node onto the stack.

// Case 2: Symbol is an operator
// 1) Pop the top tree from the stack. This becomes the right subtree.
// 2) Pop the next tree from the stack. This becomes the left subtree.
// 3) Create a new node containing the operator.
// 4) Attach the left and right subtrees to the operator node.
// 5) Push the newly created tree onto the stack.

// At the end, the remaining tree on the stack is the complete expression tree.



// How does expression tree execution work?
// After constructing the expression tree, we can execute it using postorder traversal.
// Postorder traversal follows this sequence: Visit the left subtree, visit the right subtree, process the root operator.
// why postorder because we must calculate the operands before performing the operation.

// e.g:  (5+3)∗2
//        *
//       / \
//      +   2
//     / \
//    5   3

// Postorder execution:
// Visit 5.
// Visit 3.
// Calculate 5 + 3 = 8.
// Visit 2.
// Calculate 8 * 2 = 16.
// final result is 16


// Algorithm                    Technique                                     Data structure
// Infix → Postfix              Operator precedence and associativity         Stack
// Postfix → Expression tree    Pop two trees and combine                     Stack of trees
// Expression tree → Result     Recursive postorder evaluation                Binary tree and recursion





// Q1. Why do we use a stack for infix-to-postfix conversion?
// Because operators must be temporarily stored and processed according to their precedence and associativity.

// Q2. Why do we use a stack for postfix-to-expression-tree conversion?
// Because operands and previously constructed subtrees must be stored until an operator combines them.

// Q3. Why do we pop the right child first?
// Because the first popped element represents the right operand, while the second popped element represents the left operand.

// Q4. Why are operators internal nodes?
// Because operators perform operations on operands, so they need child nodes representing those operands.

// Q5. Why are operands leaf nodes?
// Because operands provide values and do not need further children in an ordinary binary arithmetic expression tree.

// Q6. Which traversal is used to evaluate an expression tree?
// Postorder traversal (Left, Right, Root).

// Q7. How does an expression tree help compiler optimization?
// It makes the structure of expressions explicit, allowing the compiler to identify constant expressions, simplify operations, and detect repeated computations










// The provided code supports binary operators and does not directly support unary minus (such as -5 or -a). 
// You can represent a negative value using 0-5 or 0-a.












#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <memory>
#include <unordered_map>
#include <cmath>
#include <cctype>
#include <stdexcept>
#include <sstream>

using namespace std;

// ==========================================
// 1. CHECK OPERATORS
// ==========================================

bool isOperator(const string& s) 
{
    return s == "+" || s == "-" || s == "*" || s == "/" || s == "^";
}

// ==========================================
// 2. OPERATOR PRECEDENCE
// ==========================================

int precedence(const string& op) {

    if (op == "^")
        return 3;

    if (op == "*" || op == "/")
        return 2;

    if (op == "+" || op == "-")
        return 1;

    return 0;
}

// ==========================================
// 3. CHECK RIGHT ASSOCIATIVITY
// ==========================================

bool isRightAssociative(const string& op) {
    return op == "^";
}

// ==========================================
// 4. TOKENIZE INFIX EXPRESSION
// ==========================================

vector<string> tokenize(const string& expr) {

    vector<string> tokens;

    int i = 0;

    while (i < (int)expr.size()) {

        if (isspace((unsigned char)expr[i])) {
            i++;
            continue;
        }

        // Read numbers (including decimals)
        if (isdigit((unsigned char)expr[i]) ||
            (expr[i] == '.' && i + 1 < (int)expr.size()
             && isdigit((unsigned char)expr[i + 1]))) {

            string number;
            bool hasDot = false;

            while (i < (int)expr.size() &&
                  (isdigit((unsigned char)expr[i]) ||
                   expr[i] == '.')) {

                if (expr[i] == '.') {
                    if (hasDot)
                        throw runtime_error("Invalid number");

                    hasDot = true;
                }

                number += expr[i];
                i++;
            }

            tokens.push_back(number);
        }

        // Read identifiers / variables
        else if (isalpha((unsigned char)expr[i]) ||
                 expr[i] == '_') {

            string identifier;

            while (i < (int)expr.size() &&
                  (isalnum((unsigned char)expr[i]) ||
                   expr[i] == '_')) {

                identifier += expr[i];
                i++;
            }

            tokens.push_back(identifier);
        }

        // Read operators and parentheses
        else if (string("+-*/^()").find(expr[i])
                 != string::npos) {

            tokens.push_back(string(1, expr[i]));
            i++;
        }

        else {
            throw runtime_error("Invalid character");
        }
    }

    return tokens;
}

// ==========================================
// 5. INFIX TO POSTFIX CONVERSION
// ==========================================

vector<string> infixToPostfix(const string& expr) {

    vector<string> tokens = tokenize(expr);

    vector<string> postfix;

    stack<string> operators;

    bool expectingOperand = true;

    for (const string& token : tokens) {

        // CASE 1: Operand
        if (!isOperator(token) &&
            token != "(" && token != ")") {

            if (!expectingOperand)
                throw runtime_error("Missing operator");

            postfix.push_back(token);
            expectingOperand = false;
        }

        // CASE 2: Opening parenthesis
        else if (token == "(") {

            if (!expectingOperand)
                throw runtime_error("Missing operator");

            operators.push(token);
            expectingOperand = true;
        }

        // CASE 3: Closing parenthesis
        else if (token == ")") {

            if (expectingOperand)
                throw runtime_error("Invalid expression");

            while (!operators.empty() &&
                   operators.top() != "(") {

                postfix.push_back(operators.top());
                operators.pop();
            }

            if (operators.empty())
                throw runtime_error("Mismatched parentheses");

            operators.pop(); // Remove '('

            expectingOperand = false;
        }

        // CASE 4: Operator
        else {

            if (expectingOperand)
                throw runtime_error("Missing operand");

            while (!operators.empty() &&
                   operators.top() != "(") {

                string top = operators.top();

                bool shouldPop;

                if (isRightAssociative(token)) {

                    shouldPop =
                        precedence(top) > precedence(token);
                }
                else {

                    shouldPop =
                        precedence(top) >= precedence(token);
                }

                if (!shouldPop)
                    break;

                postfix.push_back(top);
                operators.pop();
            }

            operators.push(token);
            expectingOperand = true;
        }
    }

    if (expectingOperand && !tokens.empty())
        throw runtime_error("Expression ends with an operator");

    // Pop remaining operators
    while (!operators.empty()) {

        if (operators.top() == "(")
            throw runtime_error("Mismatched parentheses");

        postfix.push_back(operators.top());
        operators.pop();
    }

    return postfix;
}

// ==========================================
// 6. EXPRESSION TREE NODE
// ==========================================

struct Node {

    string value;

    unique_ptr<Node> left;
    unique_ptr<Node> right;

    Node(const string& val) {
        value = val;
    }
};

// ==========================================
// 7. POSTFIX TO EXPRESSION TREE
// ==========================================

unique_ptr<Node> postfixToTree(
    const vector<string>& postfix) {

    stack<unique_ptr<Node>> st;

    for (const string& token : postfix) {

        // CASE 1: Operand
        if (!isOperator(token)) {

            auto node = make_unique<Node>(token);

            st.push(move(node));
        }

        // CASE 2: Operator
        else {

            if (st.size() < 2)
                throw runtime_error("Invalid postfix expression");

            // First popped = RIGHT subtree
            auto right = move(st.top());
            st.pop();

            // Second popped = LEFT subtree
            auto left = move(st.top());
            st.pop();

            // Create operator node
            auto node = make_unique<Node>(token);

            node->left = move(left);
            node->right = move(right);

            // Push newly created tree
            st.push(move(node));
        }
    }

    if (st.size() != 1)
        throw runtime_error("Invalid postfix expression");

    return move(st.top());
}

// ==========================================
// 8. EVALUATE EXPRESSION TREE
// ==========================================

double evaluateTree(
    const Node* root,
    const unordered_map<string, double>& variables) {

    if (root == nullptr)
        throw runtime_error("Empty tree");

    // LEAF NODE: Return operand value
    if (!root->left && !root->right) {

        // Check whether it is a number
        try {
            size_t pos;

            double value = stod(root->value, &pos);

            if (pos == root->value.size())
                return value;
        }
        catch (...) {
            // It is a variable, not a number
        }

        // Look up variable value
        auto it = variables.find(root->value);

        if (it == variables.end())
            throw runtime_error(
                "Variable not found: " + root->value);

        return it->second;
    }

    // Evaluate left and right subtrees
    double leftValue =
        evaluateTree(root->left.get(), variables);

    double rightValue =
        evaluateTree(root->right.get(), variables);

    // Apply operator
    if (root->value == "+")
        return leftValue + rightValue;

    if (root->value == "-")
        return leftValue - rightValue;

    if (root->value == "*")
        return leftValue * rightValue;

    if (root->value == "/") {

        if (rightValue == 0)
            throw runtime_error("Division by zero");

        return leftValue / rightValue;
    }

    if (root->value == "^")
        return pow(leftValue, rightValue);

    throw runtime_error("Unknown operator");
}

// ==========================================
// 9. DISPLAY EXPRESSION TREE
// ==========================================

void printTree(
    const Node* root,
    int space = 0) {

    if (root == nullptr)
        return;

    space += 5;

    printTree(root->right.get(), space);

    cout << endl;

    for (int i = 5; i < space; i++)
        cout << " ";

    cout << root->value << endl;

    printTree(root->left.get(), space);
}

// ==========================================
// 10. MAIN FUNCTION
// ==========================================

int main() {

    try {

        string infix;

        cout << "Enter infix expression: ";

        getline(cin, infix);

        // STEP 1: Infix to postfix
        vector<string> postfix =
            infixToPostfix(infix);

        cout << "\nPostfix expression: ";

        for (const string& token : postfix)
            cout << token << " ";

        cout << endl;

        // STEP 2: Postfix to expression tree
        auto root = postfixToTree(postfix);

        cout << "\nExpression Tree:\n";

        printTree(root.get());

        // STEP 3: Enter variable values
        unordered_map<string, double> variables;

        for (const string& token : postfix) {

            if (!isOperator(token)) {

                // Check if token is a number
                bool isNumber = false;

                try {
                    size_t pos;
                    stod(token, &pos);

                    isNumber = (pos == token.size());
                }
                catch (...) {
                    isNumber = false;
                }

                if (!isNumber &&
                    variables.find(token) == variables.end()) {

                    double value;

                    cout << "\nEnter value of "
                         << token << ": ";

                    if (!(cin >> value))
                        throw runtime_error("Invalid variable value");

                    variables[token] = value;
                }
            }
        }

        // STEP 4: Evaluate expression tree
        double result =
            evaluateTree(root.get(), variables);

        cout << "\nFinal Result: " << result << endl;

    }
    catch (const exception& e) {

        cout << "\nError: " << e.what() << endl;
    }

    return 0;
}






