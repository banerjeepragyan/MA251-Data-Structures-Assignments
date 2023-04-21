/*Name : PRAGYAN BANERJEE
Roll. : 200123080
Write a program that prints out all integers of the form a3 + b3 where a
and b are integers between 0 and n in sorted order, without using excessive
space. That is, instead of computing an array of the n2 sums and sort-
ing them, build a minimum-oriented priority queue, initially containing
(03; 0; 0); (13; 1; 0); (23; 2; 0); : : : ; (n3; n; 0). Then, while the priority queue
is nonempty, remove the smallest item (i3 + j3; i; j), print it, and then, if
j < n, insert the item (i3 +(j +1)3; i; j +1). Use this program to nd all
distinct integers a; b; c, and d between 0 and 106 such that a3+b3 = c3+d3,
e.g., 1729 = 93 + 103 = 13 + 123.*/
#include <iostream>
#include <queue>
using namespace std;
# define N 100
# define M 1000
 
struct Num 
{
    long long int c;
    long long int a;
    long long int b;
    Num(long long int c, long long int a, long long int b)
        : c(c), a(a), b(b)
    {
    }
};
struct CompareCube
{
    bool operator()(Num const& p1, Num const& p2)
    {
        return p1.c > p2.c;
    }
};
struct Num1 
{
    long long int c;
    long long int a;
    long long int b;
    Num1(long long int c, long long int a, long long int b)
        : c(c), a(a), b(b)
    {
    }
};
struct CompareCube1
{
    bool operator()(Num1 const& p1, Num1 const& p2)
    {
        return p1.c > p2.c;
    }
};
int main()
{
    cout << "PRINTING IN SORTED ORDER" << endl;
    priority_queue<Num, vector<Num>, CompareCube> Q;
    for (long long int i = 0; i < N; ++i) 
    {
        Q.push(Num((i*i*i), i, 0));
    }
    while (!Q.empty()) 
    {
        Num p = Q.top();
        Q.pop();
        cout << p.c << " " << p.a << " " << p.b << "\n";
        if (p.b < N)
        {
            long long int i = p.a;
            long long int j = p.b;
            Q.push(Num(((i*i*i)+ ((j+1)*(j+1)*(j+1))), i, (j+1)));
        }
    }
    cout << endl;
    cout << "SOLVING FOR DISTINCT a, b, c, d" << endl;
    priority_queue<Num1, vector<Num1>, CompareCube1> R;
    for (long long int i = 0; i < M; ++i) 
    {
        R.push(Num1((i*i*i), i, 0));
    }
    Num1 prev = R.top();
    Num1 pprev = R.top();
    int flag = 0;
    while (!R.empty()) 
    {
        Num1 p1 = R.top();
        long long int sum = p1.c;
        if ((sum == pprev.c))
        {
            if ((pprev.a!=p1.b)||(pprev.b!=p1.a)||(prev.a!=p1.b)||(prev.b!=p1.a))
            {
                cout << sum << " = " << p1.a << " + " << p1.b << " == ";
                flag = 0;
            }
        }
        else if ((sum == prev.c))
        {
            if ((prev.a!=p1.b)||(prev.b!=p1.a))
            {
                cout << sum << " = " << p1.a << " + " << p1.b << " :: ";
                flag = 0;
            }
        }
        else
        {
            flag++;
        }
        if (flag == 1)
        {
            cout << endl;
        }
        pprev = prev;
        prev = p1;
        R.pop();
        if (p1.b < M)
        {
            long long int i = p1.a;
            long long int j = p1.b;
            R.push(Num1(((i*i*i)+ ((j+1)*(j+1)*(j+1))), i, (j+1)));
        }
    }
    return 0;
}