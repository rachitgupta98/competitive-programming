
//https://leetcode.com/problems/reorganize-string/

#include <bits/stdc++.h>
using namespace std;
int main()
{
	string S;
	cin >> S;
	int len = S.length();
	map<char, int> m;
	int max = INT_MIN;
	char k;
	for (char x : S)
	{
		m[x]++;
		if (m[x] > max)
		{
			max = m[x];
			k = x;
		}
	}
	if (max - 1 > len - max)
		cout << "";
	int j = 0;
	while (max--)
	{
		S[j] = k;
		j += 2;
	}
	for (int e = 0; e < 26; e++)
	{

		while ('a' + e != k && m['a' + e]-- > 0)
		{
			if (j >= S.size())
				j = 1;
			S[j] = 'a' + e;
			j += 2;
		}
	}

	cout << S;
}