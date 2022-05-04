#include <iostream>
using namespace std;

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
}

int partition (int a[], int beg, int end) 
{ 
    int pivot = a[beg]; 
    int i = (end - 1);
  
    for (int j = beg; j <= end - 1; j++) 
    { 
         
        if (a[j] < pivot) 
        { 
            i++; 
            swap(&a[i], &a[j]); 
        } 
    } 
    swap(&a[i + 1], &a[beg]); 
    return (i + 1); 
} 

void quickSort(int a[], int end, int beg) 
{ 
    if (end < beg) 
    { 
        int pi = partition(a, end, beg); 
        quickSort(a, end, pi - 1); 
        quickSort(a, pi + 1, beg); 
    } 
} 

int main() 
{ 
    int a[10];
    int n;
    cout<<"Enter the number of elements\n";
    cin>>n;
    for (int j=0; j<n;j++)
    cin>>a[j];
    quickSort(a, 0, n - 1); 
    cout << "Sorted array: \n"; 
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<endl;
    }
    
    return 0; 
} 