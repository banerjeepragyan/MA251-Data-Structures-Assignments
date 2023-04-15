#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
long long int cntfirst = 0;
long long int cntlast = 0;
long long int cntmedian = 0;
long long int partitionfirst (long long int[], long long int, long long int);
void quickSortfirst (long long int[], long long int, long long int);
long long int partitionlast (long long int[], long long int, long long int);
void quickSortlast (long long int[], long long int, long long int);
long long int partitionmedian (long long int[], long long int, long long int);
void quickSortmedian (long long int[], long long int, long long int);
long long int median(long long int,long long int,long long int, long long int, long long int, long long int);
int main ()
{
    string line;
    ifstream fin;
    long long int i = 0;
    long long int arr1[10000];
    long long int arr2[10000];
    long long int arr3[10000];
    fin.open("a3challenge.txt");
    while (fin) 
    {
        getline(fin, line);
        std::istringstream ( line ) >> arr1[i];
        std::istringstream ( line ) >> arr2[i];
        std::istringstream ( line ) >> arr3[i];
        i++;
    }
    fin.close();
    quickSortfirst(arr1, 0, 10000-1); 
    cout << "Sorted array: \n"; 
    for (int i = 0; i < 10; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl << cntfirst << endl;
    quickSortlast(arr2, 0, 10000-1); 
    cout << "Sorted array: \n"; 
    for (int i = 0; i < 10; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl << cntlast << endl;
    quickSortmedian(arr3, 0, 10000-1); 
    cout << "Sorted array: \n"; 
    for (int i = 0; i < 10; i++)
    {
        cout << arr3[i] << " ";
    }
    cout << endl << cntmedian << endl;
    return 0; 
}
long long int partitionfirst (long long int arr1[], long long int low, long long int high) 
{ 
    long long int pivot = arr1[low]; 
    long long int i = low;  
    for (long long int j = low + 1; j <= high; j++) 
    { 
        cntfirst++;
        if (arr1[j] < pivot) 
        { 
            i++;
            long long int temp = arr1[i];
            arr1[i] = arr1[j];
            arr1[j] = temp;
        } 
    } 
    long long int temp = arr1[i];
    arr1[i] = arr1[low];
    arr1[low] = temp;
    return i; 
}
void quickSortfirst (long long int arr1[], long long int low, long long int high) 
{ 
    if (low < high) 
    { 
        long long int pi = partitionfirst(arr1, low, high); 
        quickSortfirst(arr1, low, pi - 1); 
        quickSortfirst(arr1, pi + 1, high); 
    } 
}
long long int partitionlast (long long int arr2[], long long int low, long long int high) 
{ 
    long long int t = arr2[low];
    arr2[low] = arr2[high];
    arr2[high] = t;
    long long int pivot = arr2[low]; 
    long long int i = low;  
    for (long long int j = low + 1; j <= high; j++) 
    { 
        cntlast++;
        if (arr2[j] < pivot) 
        { 
            i++;
            long long int temp = arr2[i];
            arr2[i] = arr2[j];
            arr2[j] = temp;
        } 
    } 
    long long int temp = arr2[i];
    arr2[i] = arr2[low];
    arr2[low] = temp;
    return i; 
}
void quickSortlast (long long int arr2[], long long int low, long long int high) 
{ 
    if (low < high) 
    { 
        long long int pi = partitionlast(arr2, low, high); 
        quickSortlast(arr2, low, pi - 1); 
        quickSortlast(arr2, pi + 1, high); 
    } 
}
long long int median(long long int a,long long int b,long long int c, long long int i, long long int j, long long int k)
{
    if ((a < b && b < c) || (c < b && b < a))
       return j;
    else if ((b < a && a < c) || (c < a && a < b))
       return i;
    else
       return k;
}
long long int partitionmedian (long long int arr3[], long long int low, long long int high) 
{ 
    long long int m = (low + high)/2;
    long long int med = median (arr3[low], arr3[m], arr3[high], low, m, high);
    long long int t = arr3[low];
    arr3[low] = arr3[med];
    arr3[med] = t;
    
    long long int pivot = arr3[low]; 
    long long int i = low;  
    for (long long int j = low + 1; j <= high; j++) 
    { 
        cntmedian++;
        if (arr3[j] < pivot) 
        { 
            i++;
            long long int temp = arr3[i];
            arr3[i] = arr3[j];
            arr3[j] = temp;
        } 
    } 
    long long int temp = arr3[i];
    arr3[i] = arr3[low];
    arr3[low] = temp;
    return i; 
}
void quickSortmedian (long long int arr3[], long long int low, long long int high) 
{ 
    if (low < high) 
    { 
        long long int pi = partitionmedian(arr3, low, high); 
        quickSortmedian(arr3, low, pi - 1); 
        quickSortmedian(arr3, pi + 1, high); 
    } 
}