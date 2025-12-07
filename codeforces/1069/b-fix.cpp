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
        vector<int> p(n + 1);
        for (int i = 0; i <= n; ++i) {
            p[i] = i;
        }
        p[r] = l - 1; 
        for (int i = 1; i <= n; ++i) {
            a[i] = p[i] ^ p[i-1];
        }
        for (int i = 1; i <= n; ++i) {
            cout << a[i] << (i == n ?  '\n' : ' ');
        }
    }
    return 0;
}
