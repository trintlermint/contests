#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    
    while (t--)
    {
        int n, k; cin >> n >> k;
        
        vector<int> as(n);
        set<int> a_set;
        for (int i = 0; i < n; i++)
        {
            cin >> as[i];
            a_set.insert(as[i]);
        }
        
        set<int> cs;
        for (int i = 0; i < n; i++)
        {
            for (int d = 1; d * d <= as[i]; d++)
            {
                if (as[i] % d == 0)
                {
                    cs.insert(d);
                    cs.insert(as[i] / d);
                }
            }
        }
        
        auto v = [&](int b) -> bool {
            for (int x : a_set)
            {
                if (x % b == 0)
                {
                    for (int mul = x + b; mul <= k; mul += b)
                    {
                        if (a_set.find(mul) == a_set.end())
                        {
                            return false;
                        }
                    }
                }
            }
            return true;
        };
        
        vector<int> vcs;
        for (int c : cs)
        {
            if (v(c))
            {
                vcs.push_back(c);
            }
        }
        
        if (vcs.empty()) { cout << -1 << "\n"; continue; }
        
        sort(vcs.begin(), vcs. end());
        
        vector<int> bs;
        set<int> covered;
        bool possible = true;
        
        for (int i = 0; i < n; i++)
        {
            if (covered.find(as[i]) != covered.end()) continue;
            
            int bdiv = -1;
            for (int c : vcs)
            {
                if (as[i] % c == 0)
                {
                    bdiv = c;
                    break;
                }
            }
            
            if (bdiv == -1) { possible = false; break; }
            
            bs.push_back(bdiv);
            for (int j = 0; j < n; j++)
            {
                if (as[j] % bdiv == 0) covered.insert(as[j]);
            }
        }
        
        if (!possible) { cout << -1 << "\n"; }
        else {
            cout << bs.size() << '\n';
            for (int i = 0; i < (int)bs.size(); i++) {
                if (i > 0) cout << " ";
                cout << bs[i];
            }
            cout << '\n';
        }
    }
    return 0;
}
