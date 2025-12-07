#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;
        vector<ll> a(n + 1);
        int bit = 20;
        for (int i = 1; i <= n; ++i) {
            if (i < l || i > r) {
                a[i] = (1LL << bit);
                bit++;
            }
        }
        ll sum = 0;
        for (int i = l; i < r; ++i) {
            a[i] = (1 << 19) + (i - l + 1);
            sum ^= a[i];
        }
        a[r] = sum;
 
        for (int i = 1; i <= n; ++i) {
            cout << a[i] << (i == n ?  '\n' : ' ');
        }
    }
    return 0;
}
