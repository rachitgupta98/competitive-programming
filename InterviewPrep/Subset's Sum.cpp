/* 
    Problem link:
    https://www.codingninjas.com/codestudio/problems/subset-sum_3843086?topList=striver-sde-sheet-problems&leftPanelTab=1

    Problem Statement:
    You are given an array of ‘N’ integers. You have to find the sum of all the subsets in the non-decreasing order of the given array.

    Sample Input 1 :
    2
    2
    1 2
    1
    0
    Sample Output 1 :
    0 1 2 3
    0 0

 */

#include <bits/stdc++.h>
using namespace std;

vector<int> out;
int sum = 0;
void getSubSum(vector<int> &arr, int start, int len, int sum)
{
    if (start == len)
    {
        out.push_back(sum);
        return;
    }
    getSubSum(arr, start + 1, len, sum + arr[start]);
    getSubSum(arr, start + 1, len, sum);
}

vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    out.clear();
    int len = num.size();
    getSubSum(num, 0, len, sum);
    sort(out.begin(), out.end());
    return out;
}