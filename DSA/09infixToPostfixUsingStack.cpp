#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

#define MAX 50

char infix[MAX], postfix[MAX];
int stack[MAX];
int tos;

void push(int symbol)
{
    if (tos >= MAX - 1)
    {
        cout << "Stack overflow!\n";
    }
    else
    {
        stack[++tos] = symbol;
    }
}

int pop()
{
    if (tos == -1)
    {
        cout << "Stack underflow!\n";
        return -1;
    }
    return stack[tos--];
}

int prec(char symbol)
{
    switch (symbol)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}

void infixToPostfix()
{
    int p = 0;
    char next;
    tos = -1;
    push('$');

    int len = strlen(infix);

    for (int i = 0; i < len; i++)
    {
        char ch = infix[i];

        if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while ((next = pop()) != '(')
            {
                if (next == -1)
                    return;
                postfix[p++] = next;
            }
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^')
        {
            int precedence = prec(ch);
            while (stack[tos] != '$' && precedence <= prec(stack[tos]))
            {
                next = pop();
                if (next == -1)
                    return;
                postfix[p++] = next;
            }
            push(ch);
        }
        else
        {
            // pushing digit or alphabet
            postfix[p++] = ch;
        }
    }

    while (stack[tos] != '$')
    {
        next = pop();
        if (next == -1)
            return;
        postfix[p++] = next;
    }
    postfix[p] = '\0';
}

bool isNumericPostfix()
{
    for (int i = 0; postfix[i] != '\0'; i++)
    {
        if (isalpha(postfix[i]))
        {
            return false; // if any alphabet is found, return false
        }
    }
    return true;
}

int evaluatePostfix()
{
    tos = -1;

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        char ch = postfix[i];

        // If the character is a digit, push it onto the stack
        if (isdigit(ch))
        {
            push(ch - '0'); // Convert char digit to integer and push
        }
        else
        {
            // It's an operator, pop the top two elements
            int operand2 = pop();
            int operand1 = pop();

            switch (ch)
            {
            case '+':
                push(operand1 + operand2);
                break;
            case '-':
                push(operand1 - operand2);
                break;
            case '*':
                push(operand1 * operand2);
                break;
            case '/':
                push(operand1 / operand2);
                break;
            case '%':
                push(operand1 % operand2);
                break;
            case '^':
                push((int)pow(operand1, operand2));
                break;
            default:
                cout << "Unknown operator: " << ch << endl;
                return -1;
            }
        }
    }

    // The final result is the top element of the stack
    return pop();
}

int main()
{
    char choice = 'y';
    while (choice == 'y' || choice == 'Y')
    {
        cout << "\nEnter infix expression (with single digits and no spaces): ";
        cin >> infix;

        infixToPostfix();
        cout << "\n\tPostfix expression: " << postfix << endl;

        if (isNumericPostfix())
        {
            int result = evaluatePostfix();
            if (tos != -1)
            {
                cout << "\n\t[Error in expression evaluation!]" << endl;
            }
            else
            {
                cout << "\n\tResult of the expression: " << result << endl;
            }
        }
        else
        {
            cout << "\n\t[Expression is not in numeric form, cannot evaluate!]" << endl;
        }

        cout << "\n\n\tWant to continue (y/n)? ";
        cin >> choice;
    }

    return 0;
}
