#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n; cin >> n; 
        vector<ll> a(n), b(n);
        for (size_t i = 0; i < n; i++) cin >> a[i];
        for (size_t i = 0; i < n; i++) cin >> b[i];
        ll mins = 0, maxs = 0;
        
        for (int i = 0; i < n; i++) {
            ll rmin = mins - a[i];
            ll rmax = maxs - a[i];
            ll bmin = b[i] - maxs;
            ll bmax = b[i] - mins;
            mins = min({rmin, rmax, bmin, bmax});
            maxs = max({rmin, rmax, bmin, bmax});
        }
        
        cout << maxs << "\n";
    }
    
    return 0;
}
