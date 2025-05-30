# 🧠 Intermediate Code Generator – Convert Infix Expressions to Three-Address Code in C++

This repository contains a C++ implementation for converting infix expressions into postfix form and generating corresponding three-address intermediate code, a key step in compiler construction.

---

## 📄 Objective

To convert an infix arithmetic expression to postfix notation and then generate its intermediate three-address code representation.

---

## ⚙️ Execution Logic

### 1. **Infix to Postfix Conversion**
- Converts human-readable infix expressions (e.g., `a+b*c`) to postfix (e.g., `abc*+`)
- Uses a stack to handle:
  - Operator precedence (`^ > * / > + -`)
  - Associativity (left or right)
  - Parentheses grouping

### 2. **Three-Address Code Generation**
- Evaluates the postfix expression using a stack.
- For each operator, pops two operands and generates:
  ```cpp
  t1 = operand1 OP operand2
  ```
- Intermediate results are pushed back as temporary variables (t1, t2, etc.).

---

## 🧪 Sample Input/Output

Input:
```yaml
Enter an infix expression: a+b*c
```

Output:
```yaml
Postfix Expression: abc*+
t1 = b * c
t2 = a + t1
```

---

## 🔍 Code Explanation

```yaml
prec(char c)
```
Returns the precedence of an operator.

```yaml
associativity(char c)
```
Returns the associativity of the operator (L or R).

```yaml
infixToPostfix(string s)
```
Implements the Shunting Yard Algorithm to convert infix to postfix.

```yaml
generateIntermediateCode(string postfix)
```
Generates three-address code from postfix expression.

---

## 🌐 Real-World Applications

- Compiler Design: Intermediate code is used in parsing, optimization, and target code generation phases.

- Expression Evaluators: Used in calculators and interpreters for parsing and computing expressions.

- Static Code Analyzers: Helpful in code transformation and optimization engines.

---





