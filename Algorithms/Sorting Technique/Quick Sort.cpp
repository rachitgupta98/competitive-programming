// Tutorial --> https://www.hackerearth.com/practice/algorithms/sorting/quick-sort/tutorial/

/* The worst case time complexity of this algorithm is o(n^2) when array is already sorted ,
best case time complexity is o(nlogn) when we use middle element as pivot 
averaeg case time complexity also o(logn)
but as this is randomized algorithm, 
its time complexity fluctuates between o(n^2) and o(nlogn) and mostly it comes out to be o(nlogn) */

#include <bits/stdc++.h>
using namespace std;

int partition(int a[], int l, int h)
{
    int piv = a[l]; //pivot element
    int i, j;
    i = l;
    j = h; // l is index of first element and h is index of last element
    while (i < j)
    {
        do
        {
            i++;
        } while (a[i] <= piv);
        do
        {
            j--;
        } while (a[j] > piv);
        if (i < j)
        {
            swap(a[i], a[j]);
        }
    }
    swap(a[j], a[l]);
    return j;
}

void quickSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int j = partition(arr, l, h);
        quickSort(arr, l, j);
        quickSort(arr, j + 1, h);
    }
}

int main()
{
    int n = 6;
    int arr[6] = {2, 56, 34, 12, 76, 21};
    quickSort(arr, 0, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}