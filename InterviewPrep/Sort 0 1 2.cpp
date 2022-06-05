/*
Problem link: 
https://www.codingninjas.com/codestudio/problems/sort-0-1-2_631055?leftPanelTab=0

Problem Statement
You have been given an integer array/list(ARR) of size 'N'. It only contains 0s, 1s and 2s. Write a solution to sort this array/list.

Sample Input 1 :
2
6
0 1 2 2 1 0
7
0 1 2 1 2 1 2
Sample Output 1 :
0 0 1 1 2 2
0 1 1 1 2 2 2

*/

#include <bits/stdc++.h>
using namespace std;

void sort012(int *arr, int n)
{
    //   Write your code here
    int cnt_0 = 0;
    int cnt_1 = 0;
    int cnt_2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            cnt_0++;
        }
        if (arr[i] == 1)
        {
            cnt_1++;
        }
        if (arr[i] == 2)
        {
            cnt_2++;
        }
    }
    int i = 0;
    while (cnt_0-- > 0)
    {
        arr[i++] = 0;
    }
    while (cnt_1-- > 0)
    {
        arr[i++] = 1;
    }
    while (cnt_2-- > 0)
    {
        arr[i++] = 2;
    }
}