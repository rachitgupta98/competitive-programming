//Tutorial --> https://www.hackerearth.com/practice/algorithms/sorting/merge-sort/tutorial/
/* 
Time complexity of Merge Sort is (nLogn) in all 3 cases (worst, average and best) 
as merge sort always divides the array into two halves and take linear time to merge two halves. */

#include <bits/stdc++.h>
using namespace std;

void merge(int a[], int l, int mid, int r)
{

    int start1 = l;
    int start2 = mid + 1;
    int Arr[r - l + 1];
    int k = 0;

    while (start1 <= mid && start2 <= r)
    {
        if (a[start1] < a[start2])
        {
            Arr[k++] = a[start1++];
        }
        else
        {
            Arr[k++] = a[start2++];
        }
    }
    for (; start1 <= mid; start1++)
    {
        Arr[k++] = a[start1];
    }
    for (; start2 <= r; start2++)
    {
        Arr[k++] = a[start2];
    }
    for (int start1 = l; start1 <= r; start1++)
    {
        a[start1] = Arr[start1 - l];
    }
}

void mergeSort(int a[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, r);
        merge(a, l, mid, r);
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    mergeSort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}