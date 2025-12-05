#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		string s; cin >> s;

		int res = 0, awake = -1;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '1')
			{
				awake= i + k;
			} else
			{
				if (i > awake)
				{
					++res;
				}
			}
		}
		cout << res << "\n";
	}
	return 0;
}
