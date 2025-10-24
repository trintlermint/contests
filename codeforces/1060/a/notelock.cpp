#include <bits/stdc++.h>
using namespace std;

int main() {    
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        int p_count = 0;
        vector<bool> p_pos(n, false);
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                bool chang = true;
                int st = max(0, i - k + 1);
                for (int j = st; j < i; j++) {
                    if (s[j] == '1' && p_pos[j]) {
                        chang = false;
                        break;
                    }
                }
                bool w = false;
                for (int j = st; j < i; j++) {
                    if (s[j] == '1') {
                        w = true;
                        break;
                    }
                }
                
                if (!w) {
                    p_pos[i] = true;
                    ++p_count;
                }
            }
        }
        
        cout << p_count << endl;
    }
}
