/* 
problem : https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1/?page=1

solution:

my approach:

We have to find the 1st an last occurences of a number lets say 'K' in the given sorted array;

As array is sorted we can apply binary search

TC - O(logn)

 */
#include <bits/stdc++.h>
using namespace std;

int getOccurence(int a[], int n, int x, int option)
{
    int l = 0, h = n - 1;
    int occ = -1;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (a[mid] > x)
        {
            h = mid - 1;
        }
        else if (a[mid] < x)
        {
            l = mid + 1;
        }
        else
        {
            occ = mid;
            option == 1 ? h = mid - 1 : l = mid + 1;
        }
    }
    return occ;
}

int main()
{
    int n, x;
    cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int first = -1, last = -1;
    first = getOccurence(a, n, x, 1);
    last = getOccurence(a, n, x, 0);
    cout << first << " " << last;
    return 0;
}