#include <iostream>
#include <string>

using namespace std;

int substr(string s)
{
	auto score = []( char c )
	{
		return c - 'a' + 1;
	};
	int n = s.length(), l = 0, sum = 0;
	for ( char c : s)
	{
		sum += score(c);
	}
	for (int i = 0; i < n-1; ++i)
	{
		l += score(s[i]);
		int r = sum - l;
		if (l == r)
		{
			return 1;
		}
	}
    
    return 0;
}

int main()
{
	string s;
	cin >> s;
	cout << (substr(s) ? "true" : "false") << endl;    
	return 0;
}
