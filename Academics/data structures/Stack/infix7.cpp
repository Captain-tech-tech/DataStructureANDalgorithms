// Why Infix to Postfix

// Humans naturally like:
// A + B * C
// But a computer/parser can process postfix very conveniently using a stack.
// In postfix: A B C * +
// There is no need to repeatedly deal with: parentheses, precedence, associativity
// The order of operations is already encoded in the postfix sequence.
// That's the major idea.

// Postfix removes the ambiguity of infix by putting operators exactly where they need to be executed





























