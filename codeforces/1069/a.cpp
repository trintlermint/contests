/*
pres[ai] = T 1->n
dist = diff ai
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        set<ll> present;
        for (int i = 0; i < n; ++i) present.insert(a[i]);

        ll distinct = (ll)present.size();
        ll res = -1;
        ll maxs = n + 5000;

        for (ll i = n + 1; i <= maxs; ++i) {
            ll ci = distinct;
            if (present.find(ci) == present.end()) {
                present.insert(ci);
                distinct++;
            } else {
                res = ci;
                break;
            }
        }
        cout << res << '\n';
    }

    return 0;
}
