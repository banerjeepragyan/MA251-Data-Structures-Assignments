#include <iostream>
#include <chrono>
using namespace std;
void array_random(int16_t [], int);
void array_sorted(int16_t [], int);
void array_reverse(int16_t [], int);
void insertion_sort(int16_t [], int);
void bubble_sort(int16_t [], int);
void selection_sort(int16_t [], int);
int main()
{
    int16_t arr1[10];
    int16_t arr2[100];
    int16_t arr3[1000];
    int16_t arr4[10000];
    int16_t arr5[100000];
    cout << endl << "RANDOM ARRAY" << endl;
    cout << "Size = 10" << endl;
    array_random(arr1, 10);
    cout << "Size = 100" << endl;
    array_random(arr2, 100);
    cout << "Size = 1000" << endl;
    array_random(arr3, 1000);
    cout << "Size = 10000" << endl;
    array_random(arr4, 10000);
    cout << "Size = 100000" << endl;
    array_random(arr5, 100000);
    cout << endl << "SORTED ARRAY" << endl;
    cout << "Size = 10" << endl;
    array_sorted(arr1, 10);
    cout << "Size = 100" << endl;
    array_sorted(arr2, 100);
    cout << "Size = 1000" << endl;
    array_sorted(arr3, 1000);
    cout << "Size = 10000" << endl;
    array_sorted(arr4, 10000);
    cout << "Size = 100000" << endl;
    array_sorted(arr5, 100000);
    cout << endl << "REVERSE SORTED ARRAY" << endl;
    cout << "Size = 10" << endl;
    array_reverse(arr1, 10);
    cout << "Size = 100" << endl;
    array_reverse(arr2, 100);
    cout << "Size = 1000" << endl;
    array_reverse(arr3, 1000);
    cout << "Size = 10000" << endl;
    array_reverse(arr4, 10000);
    cout << "Size = 100000" << endl;
    array_reverse(arr5, 100000);
    return 0;
}
void array_random(int16_t arr1[], int sz)
{
    for (int i = 0; i < sz; i++)
    {
        arr1[i] = rand();
    }
    /*for (int i = 0; i < sz; i++)
        cout << arr1[i] << " ";
    cout << endl;*/
    auto start1 = chrono::steady_clock::now();
    insertion_sort(arr1, sz);
    auto end1 = chrono::steady_clock::now();
    cout << chrono::duration_cast<chrono::microseconds>(end1-start1).count() << " microseconds" << endl;
    auto start2 = chrono::steady_clock::now();
    bubble_sort(arr1, sz);
    auto end2 = chrono::steady_clock::now();
    cout << chrono::duration_cast<chrono::microseconds>(end2-start2).count() << " microseconds" << endl;
    auto start3 = chrono::steady_clock::now();
    selection_sort(arr1, sz);
    auto end3 = chrono::steady_clock::now();
    cout << chrono::duration_cast<chrono::microseconds>(end3-start3).count() << " microseconds" << endl;
}
void array_sorted(int16_t arr1[], int sz)
{
    for (int i = 0; i < sz; i++)
    {
        arr1[i] = i;
    }
    /*for (int i = 0; i < sz; i++)
        cout << arr1[i] << " ";
    cout << endl;*/
    auto start1 = chrono::steady_clock::now();
    insertion_sort(arr1, sz);
    auto end1 = chrono::steady_clock::now();
    cout << chrono::duration_cast<chrono::microseconds>(end1-start1).count() << " microseconds" << endl;
    auto start2 = chrono::steady_clock::now();
    bubble_sort(arr1, sz);
    auto end2 = chrono::steady_clock::now();
    cout << chrono::duration_cast<chrono::microseconds>(end2-start2).count() << " microseconds" << endl;
    auto start3 = chrono::steady_clock::now();
    selection_sort(arr1, sz);
    auto end3 = chrono::steady_clock::now();
    cout << chrono::duration_cast<chrono::microseconds>(end3-start3).count() << " microseconds" << endl;
}
void array_reverse(int16_t arr1[], int sz)
{
    for (int i = 0; i < sz; i++)
    {
        arr1[i] = sz-i;
    }
    /*for (int i = 0; i < sz; i++)
        cout << arr1[i] << " ";
    cout << endl;*/
    auto start1 = chrono::steady_clock::now();
    insertion_sort(arr1, sz);
    auto end1 = chrono::steady_clock::now();
    cout << chrono::duration_cast<chrono::microseconds>(end1-start1).count() << " microseconds" << endl;
    auto start2 = chrono::steady_clock::now();
    bubble_sort(arr1, sz);
    auto end2 = chrono::steady_clock::now();
    cout << chrono::duration_cast<chrono::microseconds>(end2-start2).count() << " microseconds" << endl;
    auto start3 = chrono::steady_clock::now();
    selection_sort(arr1, sz);
    auto end3 = chrono::steady_clock::now();
    cout << chrono::duration_cast<chrono::microseconds>(end3-start3).count() << " microseconds" << endl;
    
}
void insertion_sort(int16_t arr[], int sz)
{
    int key, j;
    for(int i = 1; i < sz; i++) 
    {
        key = arr[i];
        j = i;
        while(j > 0 && arr[j-1]>key) 
        {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = key; 
    }
    cout << "Insertion Sort : ";
    /*for (int i = 0; i < sz; i++)
        cout << arr[i] << " ";
    cout << endl;*/
}
void bubble_sort(int16_t arr[], int sz)
{
    for(int i = 0; i < sz; i++) 
    {
        for(int j = 0; j < sz - i - 1; j++) 
        {
            if(arr[j] > arr[j+1]) 
            {      
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    cout << "Bubble Sort : ";
    /*for (int i = 0; i < sz; i++)
        cout << arr[i] << " ";
    cout << endl;*/
}
void selection_sort(int16_t arr[], int sz)
{
    int i, j, min_idx;
    for (i = 0; i < sz - 1; i++)
    {
        min_idx = i;
        for (j = i+1; j < sz; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
    cout << "Selection Sort : ";
    /*for (int i = 0; i < sz; i++)
        cout << arr[i] << " ";
    cout << endl;*/
}