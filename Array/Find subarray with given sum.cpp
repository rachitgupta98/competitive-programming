//https://www.geeksforgeeks.org/find-subarray-with-given-sum/;

/* Test Case 
    
    Input :                                                      Input : 
            v[] = {3,1,5,7,12,9};
            sum=13;                                                  v[] = {3,1,5,7,12,9};
                                                                      sum=44;
            
            
    Output :                                                     Output :
            Sum exist with subarray range   1  3                      No Subarray exist equals given sum
 */

// Time Complexity  O(n)   Space Complexity O(1)

// Note : All numbers in an array should be positive
#include <bits/stdc++.h>
using namespace std;
#define pb push_back

int main()
{
    vector<int> v = {3, 6, 1, 7, 12, 15};
    int len = v.size();
    int sum;
    cin >> sum;

    int curSum = v[0], index = 0, i;
    bool isSumExist = false;
    for (i = 1; i <= len; i++)
    {
        while (curSum > sum && index < i)
        {
            curSum -= v[index];
            index++;
        }
        if (curSum == sum)
        {
            isSumExist = true;
            break;
            //cout << index << " " << i;
        }
        if (i < len)
            curSum += v[i];
    }
    !isSumExist ? cout << "No Subarray exist equals given sum" : cout << "Sum exist with subarray range " << index << " " << i - 1;
    return 0;
}