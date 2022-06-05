/*
    Problem link: 
    https://www.codingninjas.com/codestudio/problems/pascal-s-triangle_1089580?leftPanelTab=0

    Problem Statement
    You are given an integer N. Your task is to return a 2-D ArrayList containing the pascal’s triangle till the row N.
    A Pascal's triangle is a triangular array constructed by summing adjacent elements in preceding rows

    Sample Input 1 :
    3
    1
    2
    3
    Sample Output 1 :
    1
    1 
    1 1 
    1 
    1 1 
    1 2 1 
*/

#include <bits/stdc++.h>
using namespace std;
vector<vector<long long int>> printPascal(int n)
{
    // Write your code here.

    vector<vector<long long int>> trio = {{1}};
    for (int i = 1; i < n; i++)
    {
        vector<long long int> sub;
        sub.push_back(1);
        for (int j = 0; j < i; j++)
        {
            if (j + 1 == i)
            {
                break;
            }
            sub.push_back((trio[i - 1][j]) + (trio[i - 1][j + 1]));
        }
        sub.push_back(1);
        trio.push_back(sub);
    }
    return trio;
}
