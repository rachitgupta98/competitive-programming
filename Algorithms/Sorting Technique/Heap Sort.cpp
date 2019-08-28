//tutorial ---> https://www.hackerearth.com/practice/algorithms/sorting/heap-sort/tutorial/

/* Time complexity of heapify is O(Logn).
Time complexity of createAndBuildHeap() is O(n) and 
overall time complexity of Heap Sort is O(nLogn) */

#include <bits/stdc++.h>
using namespace std;

void heapify(int b[], int i, int n)
{
    int large = i;
    int l = 2 * i + 1; //left child
    int r = 2 * i + 2; //right child
    if (l < n && b[l] >= b[large])
    {
        large = l;
    }
    if (r < n && b[r] >= b[large])
    {
        large = r;
    }
    if (large != i)
    {
        swap(b[i], b[large]);
        heapify(b, large, n);
    }
}

void heapSort(int a[], int n)
{
    int l = n / 2 - 1;
    //first create max /min heap(anyone heap)
    for (int i = l; i >= 0; i--)
    {
        heapify(a, i, n);
    }

    //delete heap
    for (int i = n - 1; i >= 0; i--)
    {
        swap(a[0], a[i]);
        n = n - 1;
        heapify(a, 0, n);
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
    heapSort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}