/*Name : PRAGYAN BANERJEE
Roll. : 200123080
Implement the hash table-based solution to the 2-SUM problem discussed
in the class. Use the division method for your hash function and resolve
the collision by linear probing.*/

#include <bits/stdc++.h>
using namespace std;
int sz = 9;
int n = 9;
int a[9];
pair<int, int> HT[9]; 

int hash_function(int n) 
{
    return ((n % sz) + sz) % sz;
}
void insert (int x)
{
   int index = hash_function(x);
   if(HT[index].first == 1) 
   {
      int Count = 0;
      while(Count < sz && HT[index].first == 1 && HT[index].first != x) 
      {
         index++;
         Count++;
         index %= sz;
      }
      if(Count < sz) HT[index] = {1, x};
   }
   else 
   {
      HT[index] = {1, x};
   }
}
main() 
{
   int sum;
   int k=0;
   string FILENAME = "test.txt";
   ifstream Fin(FILENAME,ios::in);
   while (Fin >> a[k]&&k<1000) 
   {
      k++;
   }
   Fin.close();  
   for(int i=0; i<sz; i++) HT[i] = {0, 0}; 
   for(int i=0; i<n; i++)
   {
      insert (a[i]);
   }
   int cnt = 0;
   for(sum = 3; sum <= 10; sum++)
   {
      for(int j=0; j < n; j++) 
      {
         int temp = sum - a[j];   
         int index = hash_function(temp);
         if(HT[index].first == 1 && HT[index].second == temp) 
         {
            cnt++;
            break;      
         }
         else 
         {
            int c = 0;
            while(c  < sz && (HT[index].first == 1 && HT[index].second != temp)) 
            {
               index++;
               c++;
               index %= sz;
            }

            if(c  < sz && HT[index].first == 1 && HT[index].second == temp) 
            {
               cnt++;
               break;         
            }      
         }   
      }
   }
   cout << cnt << endl;
}