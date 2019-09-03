/* Below are the permutations of string ABC.
ABC ACB BAC BCA CBA CAB */

/* printing lexicographically permutation of string using "next_permutation" 
that is built in function which return true if further modification of string is possible
 and return false if not */

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s = "ABC";

    // first sort the string
    sort(s.begin(), s.end());
    do
    {
        cout << s << " ";
    } while (next_permutation(s.begin(), s.end()));

    return 0;
}