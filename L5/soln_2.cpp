/*Name : PRAGYAN BANERJEE
Roll. : 200123080
Find all solutions to the equation a+2b2 = 3c3+4d4 for which a; b; c; and
d are less than 100,000. Hint: use one min heap and one max heap.*/
#include <iostream>
#include <queue>
using namespace std;
# define N 100
 
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
struct Num2 
{
    long long int c;
    long long int a;
    long long int b;
    Num2(long long int c, long long int a, long long int b)
        : c(c), a(a), b(b)
    {
    }
};
struct CompareCube2
{
    bool operator()(Num2 const& p1, Num2 const& p2)
    {
        return p1.c > p2.c;
    }
};
struct Num3
{
    long long int c;
    long long int a;
    long long int b;
    Num3(long long int c, long long int a, long long int b)
        : c(c), a(a), b(b)
    {
    }
};
struct CompareCube3
{
    bool operator()(Num3 const& p1, Num3 const& p2)
    {
        return p1.c > p2.c;
    }
};

int main()
{
    priority_queue<Num2, vector<Num2>, CompareCube2> Q1;
    priority_queue<Num3, vector<Num3>, CompareCube3> R1;
    priority_queue<Num, vector<Num>, CompareCube> Q;
    for (long long int i = 0; i < N; ++i) 
    {
        Q.push(Num(i, i, 0));
    }
    while (!Q.empty()) 
    {
        Num p = Q.top();
        Q1.push(Num2(p.c, p.a, p.b));
        Q.pop();
        //cout << p.c << " " << p.a << " " << p.b << "\n";
        if (p.b < N)
        {
            long long int i = p.a;
            long long int j = p.b;
            Q.push(Num((i + (2*(j+1)*(j+1))), i, (j+1)));
        }
    }
    priority_queue<Num1, vector<Num1>, CompareCube1> R;
    for (long long int i = 0; i < N; ++i) 
    {
        R.push(Num1((3*i*i*i), i, 0));
    }
    while (!R.empty()) 
    {
        Num1 p = R.top();
        R.pop();
        R1.push(Num3(p.c, p.a, p.b));
        //cout << p.c << " " << p.a << " " << p.b << "\n";
        if (p.b < N)
        {
            long long int i = p.a;
            long long int j = p.b;
            R.push(Num1(((3*i*i*i) + (4*(j+1)*(j+1)*(j+1)*(j+1))), i, (j+1)));
        }
    }
    cout << endl;
    while ((!R1.empty())&&(!Q1.empty()))
    {
        //Num1 p = R1.top();
        //R1.pop();
        //cout << p.c << " " << p.a << " " << p.b << "\n";
        Num2 pl = Q1.top();
        Num3 pr = R1.top();
        if(pl.c == pr.c)
        {
            Q1.pop();
            R1.pop();
            cout << pl.a << " : " << pl.b << " : " << pr.a << " : " << pr.b << endl;
            
        }
        if(pl.c > pr.c)
        {
            R1.pop();
        }
        if(pl.c < pr.c)
        {
            Q1.pop();
        }
    }
    return 0;
}