#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 100005;
const int MAXK = 365;

int nxt[MAXN][MAXK]; 
int min_idx[MAXK][MAXK];
ll max_score[MAXK][MAXK];
int a[MAXN];

void solve()
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int v = 1; v <= k; ++v)
	{
		nxt[n][v] = n + 1;// n+1 => no fr.
	}
	for (int i = n - 1; i >= 0; --i)
	{
		for (int v = 1; v <= k; ++v)
		{
			a[i + 1] >= v
			? nxt[i][v] = i + 1
			: nxt[i][v] = nxt[i + 1][v];
		}
	}

	for (int c = 0; c <= k; ++c)
	{
		for (int v = 0; v <= k; ++v)
		{
			min_idx[c][v] = n + 2;
			max_score[c][v] = -1;
		}
	}
	min_idx[0][0] = 0;
	max_score[0][0] = 0;
	ll res = 0;

	for (int c = 0; c <= k; ++c)
	{
		for (int v = 0; v <= c; ++v)
		{
			if (min_idx[c][v] > n) continue;
			int current_i = min_idx[c][v];
			ll current_s = max_score[c][v];
			if (current_s > res) res = current_s;

			for (int next_v = v + 1; next_v <= k; ++next_v)
			{
				int next_c = c + next_v;
                                if (next_c > k) break;
				int next_i = nxt[current_i][next_v];
				if (next_i > n) continue;
				ll added_score = (ll)(next_v - v) * (n - next_i + 1);
				ll new_s = current_s + added_score;
				if (next_i < min_idx[next_c][next_v])
				{
					min_idx[next_c][next_v] = next_i;
					max_score[next_c][next_v] = new_s;
				} else if (next_i == min_idx[next_c][next_v])
				{
					if (new_s > max_score[next_c][next_v])
					{
						max_score[next_c][next_v] = new_s;
					}
				}
			}
		}
	}
	cout << res << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while(t--)
	{
		solve();
	}
	return 0;
}
