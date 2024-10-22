// Implement the conversion of infix notation to postfix notation and 
// evaluation of postfix notation using stacks. 

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
    bool flag = false;
    int len = strlen(infix);

    for (int i = 0; i < len; i++)
    {
        char ch = infix[i];

        if (ch == '(')
        {
            flag = true;
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

int evaluatePostfix()
{
    tos = -1;

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        char ch = postfix[i];

        if (isalpha(ch))
        {
            cout << "\tEnter the value of " << ch << ": ";
            cin >> ch;
            push(ch - '0');
        }
        else if (isdigit(ch))
        {
            push(ch - '0');
        }
        else
        {
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

        int result = evaluatePostfix();
        if (tos != -1)
        {
            cout << "\n\t[Error in expression evaluation!]" << endl;
        }
        else
        {
            cout << "\n\tResult of the expression: " << result << endl;
        }

        cout << "\n\n\tWant to continue (y/n)? ";
        cin >> choice;
    }

    return 0;
}
