/*Name : PRAGYAN BANERJEE
Roll. : 200123080
Write a program that takes as input a fully parenthesized, arithmetic ex-
pression and converts it to a binary expression tree. Your program should
display the tree in the following way and also print the value associated
with the root.*/
#include <bits/stdc++.h>
#include <cmath>
using namespace std;
typedef struct node
{
    char data;
    struct node *left, *right;
} * nptr;
nptr newNode(char c)
{
    nptr n = new node;
    n->data = c;
    n->left = n->right = nullptr;
    return n;
}
nptr build(string& s)
{
    stack<nptr> stN;
    stack<char> stC;
    nptr t, t1, t2;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(') 
        {
            stC.push(s[i]);
        }
        else if (isdigit(s[i]))
        {
            t = newNode(s[i]);
            stN.push(t);
        }
        else if ((s[i] == '+') || (s[i] == '-') || (s[i] == '*') || (s[i] == '/') || (s[i] == '^'))
        {
            stC.push(s[i]);
        }
        else if (s[i] == ')') {
            while (!stC.empty() && stC.top() != '(')
            {
                t = newNode(stC.top());
                stC.pop();
                t1 = stN.top();
                stN.pop();
                t2 = stN.top();
                stN.pop();
                t->left = t2;
                t->right = t1;
                stN.push(t);
            }
            stC.pop();
        }
    }
    t = stN.top();
    return t;
}
int findDepth(struct node* root, char x)
{
    if (root == NULL)
    {
        return -1;
    }        
    int dist = -1;
    if ((root->data == x)
        || (dist = findDepth(root->left, x)) >= 0
        || (dist = findDepth(root->right, x)) >= 0)
        {
            if(root->data == x)
            {
                root->data = '?';
            }
            return dist + 1;
        }
    return dist;
}
int i = 0;
void printPreorder(struct node* root, struct node* nod, char (&x)[100][100])
{
    if (nod == NULL)
    {
        return;
    }
    char dt = nod->data;
    int h = findDepth(root, dt);
    x[i][h] = dt;
    i++;
    printPreorder(root, nod->left, x);
    printPreorder(root, nod->right, x);
}
int toInt(char x)
{
    return x - '0';
}
int eval(struct node* root) 
{ 
    if (!root) 
    {
        return 0; 
    }
    if (!root->left && !root->right) 
    {
        return toInt(root->data); 
    }
    int l_val = eval(root->left); 
    int r_val = eval(root->right); 
    if (root->data=='+') 
    {
        return l_val+r_val; 
    }
    if (root->data=='-') 
    {
        return l_val-r_val; 
    } 
    if (root->data=='*') 
    {
        return l_val*r_val; 
    }
    if (root->data=='^') 
    {
        return pow(l_val, r_val);  
    }
    return l_val/r_val; 
} 
int main()
{
    string s = "((((3+1)*3)/((9-5)+2))-((3*(7-4))+6))";
    s = "(" + s;
    s += ")";
    nptr root = build(s);
    cout << "VALUE = " << eval(root) << endl;
    char x[100][100];
    printPreorder(root, root, x);
    for (int yy = 0; yy < 25; yy++)
    {
        for (int xx = 0; xx < 25; xx++)
        {
            cout << x[xx][yy] << "  ";
        }
        cout << endl;
    }
    cout << "END";
    return 0;
}