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











