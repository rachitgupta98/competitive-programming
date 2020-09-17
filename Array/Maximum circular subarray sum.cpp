//https://www.geeksforgeeks.org/maximum-contiguous-circular-sum/

/* Test Case 
    
    Input :  
            n=5;
            v[n] ={ 2, -4, 5, -1, 3}
    Output :
            9
 */

#include <bits/stdc++.h>
using namespace std;
#define pb push_back

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    int allSum = 0;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        v.pb(t);
        allSum += t;
    }
    int maxSum = INT_MIN, minSum = INT_MAX, bc = 0, ab = 0;
    for (int i = 0; i < n; i++)
    {
        ab += v[i];
        bc += v[i];
        if (ab < 0)
        {
            ab = 0;
        }
        if (bc > 0)
        {
            bc = 0;
        }
        maxSum = max(ab, maxSum);
        minSum = min(bc, minSum);
    }
    if (allSum == minSum)
    {
        cout << maxSum;
    }
    else
    {
        cout << max(maxSum, allSum - minSum);
    }
    return 0;
}