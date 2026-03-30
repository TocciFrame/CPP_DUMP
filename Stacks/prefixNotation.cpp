#include <iostream>
#include <string>
#include <stack>
#include <cctype>

// Function to determine the precedence of an operator.
// Higher return value means higher precedence.
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    return 0; // For anything else, like parentheses
}

// Function to convert an infix expression to a postfix expression.
// Uses a stack to handle operator precedence.
std::string infixToPostfix(const std::string& infix) {
    std::string postfix = "";
    std::stack<char> opStack;

    // Iterate through the infix expression character by character.
    for (char c : infix) {
        if (std::isspace(c)) {
            continue; // Skip spaces
        }
        
        // If the character is a digit (operand), append it directly to the postfix string.
        if (std::isdigit(c)) {
            postfix += c;
            postfix += ' '; // Add a space for readability and easy parsing later
        } 
        // If the character is an opening parenthesis, push it onto the stack.
        else if (c == '(') {
            opStack.push(c);
        } 
        // If the character is a closing parenthesis, pop operators from the stack
        // and append to the postfix string until an opening parenthesis is found.
        else if (c == ')') {
            while (!opStack.empty() && opStack.top() != '(') {
                postfix += opStack.top();
                postfix += ' ';
                opStack.pop();
            }
            if (!opStack.empty()) {
                opStack.pop(); // Pop the '('
            }
        } 
        // If the character is an operator.
        else {
            // While the stack is not empty and the top operator has higher or equal
            // precedence, pop it and append to the postfix string.
            while (!opStack.empty() && precedence(opStack.top()) >= precedence(c)) {
                postfix += opStack.top();
                postfix += ' ';
                opStack.pop();
            }
            // Push the current operator onto the stack.
            opStack.push(c);
        }
    }

    // After the loop, pop any remaining operators from the stack and append to postfix.
    while (!opStack.empty()) {
        postfix += opStack.top();
        postfix += ' ';
        opStack.pop();
    }

    return postfix;
}

// Function to evaluate a postfix expression.
// Uses a stack to hold operands for calculations.
double evaluatePostfix(const std::string& postfix) {
    std::stack<double> operandStack;
    std::string currentNum = "";

    // Iterate through the postfix expression.
    for (char c : postfix) {
        if (std::isspace(c)) {
            // If we have a number string, convert it to a double and push to stack.
            if (!currentNum.empty()) {
                operandStack.push(std::stod(currentNum));
                currentNum = ""; // Reset the number string
            }
            continue;
        }

        // If the character is a digit, build the number string.
        if (std::isdigit(c)) {
            currentNum += c;
        } 
        // If the character is an operator.
        else {
            // Pop the top two operands from the stack. The order is crucial:
            // The second-to-last item pushed is the left operand.
            double val2 = operandStack.top();
            operandStack.pop();
            double val1 = operandStack.top();
            operandStack.pop();

            // Perform the operation and push the result back onto the stack.
            switch (c) {
                case '+':
                    operandStack.push(val1 + val2);
                    break;
                case '-':
                    operandStack.push(val1 - val2);
                    break;
                case '*':
                    operandStack.push(val1 * val2);
                    break;
                case '/':
                    if (val2 != 0) {
                        operandStack.push(val1 / val2);
                    } else {
                        std::cerr << "Error: Division by zero" << std::endl;
                        return 0.0;
                    }
                    break;
            }
        }
    }

    // The final result is the single item left on the stack.
    return operandStack.top();
}

int main() {
    std::string infix_expression;
    std::cout << "Enter an infix expression: ";
    std::getline(std::cin, infix_expression);

    std::cout << "Infix expression: " << infix_expression << std::endl;
    
    // Step 1: Convert infix to postfix
    std::string postfix_expression = infixToPostfix(infix_expression);
    std::cout << "Postfix expression: " << postfix_expression << std::endl;
    
    // Step 2: Evaluate the postfix expression
    double result = evaluatePostfix(postfix_expression);
    std::cout << "Result: " << result << std::endl;

    return 0;
}
