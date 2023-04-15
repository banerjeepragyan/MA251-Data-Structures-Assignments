/*Name : PRAGYAN BANERJEE
Roll no. : 200123080
Lab no. : 4
Date : 06.09.2021
Write a program Tail that takes two command line arguments k and in-
put.txt and prints the last k lines of the le input.txt. Use appropriate
data structure.*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <bits/stdc++.h>
#define FILENAME "tail.txt"
#define MAX 100
#define K 5
using namespace std;
void push1 (string);
string pop1 ();
void push2 (string);
string pop2 ();
string stk1[100];
int top1 = -1;
string stk2[100];
int top2 = -1;
int main ()
{
    std::ifstream file(FILENAME);
    if (file.is_open()) 
    {
        int i = 0;
        std::string line;
        while (std::getline(file, line)) 
        {
            // using printf() in all tests for consistency
            //printf("%s", line.c_str());
            push1 (line.c_str());
        }
        file.close();
    }
    for (int i = 0; i < K; i++)
    {
        push2 (pop1());
    }
    for (int i = 0; i < K; i++)
    {
        cout << pop2() << endl;
    }
}
void push1 (string oper)
{
    if (top1 == (MAX-1))
    {
        cout << "STACK IS FULL";
    }
    else
    {
        top1++;
        stk1[top1] = oper;
    }
}
string pop1 ()
{
    string ch;
    if (top1 == -1)
    {
        cout << "STACK IS EMPTY";
    }
    else
    {
        ch = stk1[top1];
        stk1[top1] = '\0';
        top1--;
        return (ch);
    }
    return 0;
}
void push2 (string oper)
{
    if (top2 == (MAX-1))
    {
        cout << "STACK IS FULL";
    }
    else
    {
        top2++;
        stk2[top2] = oper;
    }
}
string pop2 ()
{
    string ch;
    if (top2 == -1)
    {
        cout << "STACK IS EMPTY";
    }
    else
    {
        ch = stk2[top2];
        stk2[top2] = '\0';
        top2--;
        return (ch);
    }
    return 0;
}