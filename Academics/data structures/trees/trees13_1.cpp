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









