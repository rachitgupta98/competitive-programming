/*
Problem link:
https://www.codingninjas.com/codestudio/problems/set-matrix-zeros_3846774?leftPanelTab=0

Problem Statement:

Given an ‘N’ x ‘M’ integer matrix, if an element is 0, set its entire row and column to 0's, and return the matrix. In particular, your task is to modify it in such a way that if a cell has a value 0 (matrix[i][j] == 0), then all the cells of the ith row and jth column should be changed to 0.
You must do it in place.

For Example:
If the given grid is this:
[7, 19, 3]
[4, 21, 0]

Then the modified grid will be:
[7, 19, 0]
[0, 0,  0]

*/

#include <bits/stdc++.h>
using namespace std;

bool isThere(string str, int c)
{
    if (str.find((c + '0')) != string::npos)
    {
        return true;
    }
    return false;
}

void setZeros(vector<vector<int>> &matrix)
{
    // Write your code here.
    string secret_i = "";
    string secret_j = "";
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                secret_i += (i + '0');
                secret_j += (j + '0');
            }
        }
    }

    for (int i = 0; i < matrix.size(); i++)
    {
        bool isThere_i = isThere(secret_i, i);
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (isThere_i)
            {
                matrix[i][j] = 0;
                continue;
            }
            bool isThere_j = isThere(secret_j, j);
            if (isThere_j)
            {
                matrix[i][j] = 0;
                continue;
            }
        }
    }
}