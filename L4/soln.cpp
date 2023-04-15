/*Name : PRAGYAN BANERJEE
Roll no. : 200123080
Lab no. : 4
Date : 06.09.2021
Write a program to convert an infix expression to postfix expression and
evaluate the postfix expression and prints the value. The given infix ex-
pression need not be fully paranthesized. So your program should handle
the precedence of operators.*/

#include<iostream>
#include<string>
#include<cmath>
#define MAX 100
using namespace std;
char stk[100];
int top=-1;
int stke[100];
int tope=-1;
void pushe(int);
int pope();
void push(char);
char pop();
int priority (char);
string convert(string);
float evaluate(string);
int main()
{
    int cont;
    string infix, postfix;
    cout << "ENTER INFIX EXPRESSION" << endl;
    cin >> infix;
    postfix = convert(infix);
    cout << "POSTFIX :" << postfix << endl;
    float res;
    res = evaluate(postfix);
    cout << "VALUE = " << res << endl;
    return 0;
}
void push (char oper)
{
    if (top == (MAX-1))
    {
        cout << "STACK IS FULL";
    }
    else
    {
        top++;
        stk[top] = oper;
    }
}
char pop ()
{
    char ch;
    if (top == -1)
    {
        cout << "STACK IS EMPTY";
    }
    else
    {
        ch = stk[top];
        stk[top] = '\0';
        top--;
        return (ch);
    }
    return 0;
}
void pushe (int oper)
{
    if (tope == (MAX-1))
    {
        cout << "STACK IS FULL";
    }
    else
    {
        tope++;
        stke[tope] = oper;
    }
}
int pope ()
{
    char ch;
    if (tope == -1)
    {
        cout << "STACK IS EMPTY";
    }
    else
    {
        ch = stke[tope];
        tope--;
        return (ch);
    }
    return 0;
}
int priority (char chr)
{
    if (chr == '+' || chr =='-')
    {
        return (1);
    }
    if (chr == '*' || chr =='/')
    {
        return (2);
    }
    if (chr == '^')
    {
        return (3);
    }
    return 0;
}
string convert (string infix)
{
    int i = 0;
    string postfix = "";   
    while (infix[i]!='\0')
    {       
        if (infix[i]>='a' && infix[i]<='z'|| infix[i]>='A'&& infix[i]<='Z' || infix[i]>='0' && infix[i]<='9')          
        {
            postfix.insert (postfix.end(), infix[i]);
            i++;
        }       
        else if (infix[i]=='(')
        {
            push (infix[i]);
            i++;
        }        
        else if (infix[i]==')')
        {
            if (infix[i]==')')
            {
                while (stk[top]!='(')
                {               
                    postfix.insert(postfix.end(),pop());
                }
                pop();
                i++;
            }
        }
        else            
        {
            if(top==-1)
            {
                push(infix[i]);
                i++;
            }
            else if (priority(infix[i]) <= priority(stk[top])) 
            {
                postfix.insert(postfix.end(),pop());
                while (priority(stk[top]) == priority(infix[i]))
                {
                    postfix.insert (postfix.end(),pop());
                    if (top < 0) 
                    {
                        break;
                    }
                }
                push (infix[i]);
                i++;
            }
            else if(priority(infix[i]) > priority(stk[top])) 
            {
                push(infix[i]);
                i++;
            }
        }
    }
    while (top!=-1)
    {
        postfix.insert(postfix.end(),pop());
    }
    return postfix;
}
float evaluate (string postfix)
{
    float result;
    for (int i = 0 ; i < postfix.length() ; i++)
    {
        if (postfix[i] == '*')
        {
            int operand1 = pope ();
            int operand2 = pope ();
            result = operand1 * operand2;
            pushe (result);
        }
        else if (postfix[i] == '/')
        {
            int operand1 = pope ();
            int operand2 = pope ();
            result = operand2 / operand1;
            pushe (result);
        }
        else if (postfix[i] == '+')
        {
            int operand1 = pope ();
            int operand2 = pope ();
            result = operand1 + operand2;
            pushe (result);
        }
        else if (postfix[i] == '-')
        {
            int operand1 = pope ();
            int operand2 = pope ();
            result = operand2 - operand1;
            pushe (result);
        }
        else if (postfix[i] == '^')
        {
            int operand1 = pope ();
            int operand2 = pope ();
            result = pow(operand2, operand1);
            pushe (result);
        }
        else
        {
            result = postfix[i] - '0';
            pushe (result);
        }
    }
    return result;
}