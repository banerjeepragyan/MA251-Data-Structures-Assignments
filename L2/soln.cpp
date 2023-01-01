#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
long long int merge(long long int [], long long int [], long long int, long long int, long long int);
long long int mergeSort(long long int [], long long int[], long long int, long long int);
long long int inversionCount(long long int [], long long int);
int main ()
{
    string line1;
    ifstream fin1;
    long long int i = 0;
    long long int arr1[10];
    fin1.open("tstcase1.txt");
    while (fin1) 
    {
        getline(fin1, line1);
        std::istringstream ( line1 ) >> arr1[i];
        i++;
    }
    fin1.close();  
    string line2;
    ifstream fin2;
    i = 0;
    long long int arr2[100000];
    fin2.open("tstcase2.txt");
    while (fin2) 
    {
        getline(fin2, line2);
        std::istringstream ( line2 ) >> arr2[i];
        i++;
    }
    fin2.close();
    string line3;
    ifstream fin3;
    i = 0;
    long long int arr3[10];
    fin3.open("revsorted.txt");
    while (fin2) 
    {
        getline(fin3, line3);
        std::istringstream ( line3 ) >> arr3[i];
        i++;
    }
    fin3.close();
    string line4;
    ifstream fin4;
    i = 0;
    long long int arr4[10];
    fin4.open("sorted.txt");
    while (fin4) 
    {
        getline(fin4, line4);
        std::istringstream ( line4 ) >> arr4[i];
        i++;
    }
    fin4.close();
    long long int ans1 = inversionCount(arr1, 10);
    cout << " Number of inversions are for test case 1 : " << ans1 << endl;
    long long int ans2 = inversionCount(arr2, 100000);
    cout << " Number of inversions are for test case 2 : " << ans2 << endl;
    long long int ans3 = inversionCount(arr3, 10);
    cout << " Number of inversions are for reverse sorted case (size = 10) : " << ans3 << endl;
    long long int ans4 = inversionCount(arr4, 10);
    cout << " Number of inversions are for sorted case (size = 10) : " << ans4 << endl;
    return 0;
}
long long int merge(long long int arr[], long long int temp[], long long int start, long long int mid, long long int end)
{
    long long int i = start;
    long long int j = mid;
    long long int k = start;
    long long int inversion_count = 0;
    while(i <= mid-1 && j<= end)
    {
        if(arr[i]< arr[j])
        {
            temp[k++] = arr[i++];
        }            
        else
        {
            inversion_count += mid-i;
            temp[k++] = arr[j++];
        }
    }
    while(i <= mid-1)
    {
        temp[k++] = arr[i++];
    }
        
    while(j <= end)
    {
        temp[k++] = arr[j++];
    }
        
    for(long long int i = start; i <= end; i++)
    {
        arr[i] = temp[i];
    }
        
    return inversion_count;
}
long long int mergeSort(long long int arr[], long long int temp[], long long int start, long long int end)
{
    long long int inversion_count = 0;
    if(start < end) 
    {
        long long int mid = (start+end)/2;
        inversion_count += mergeSort(arr, temp, start, mid);
        inversion_count += mergeSort(arr, temp, mid+1, end);
        inversion_count += merge(arr, temp, start, mid+1, end);
    }
    return inversion_count;
        
}
long long int inversionCount(long long int A[], long long int sz)
{
    long long int temp[sz];
    return mergeSort(A, temp, 0, sz-1);
}