#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; 
    cin >> tc;
    while(tc--)
    {
        string s, t; 
        cin >> s >> t;
        
        vector<int> count_s(26, 0);
        vector<int> count_t(26, 0);

        for(char c : s) count_s[c - 'a']++;
        for(char c : t) count_t[c - 'a']++;

        bool p = true;
        for(int i = 0; i < 26; ++i) {
            if(count_t[i] < count_s[i]) {
                p = false;
                break;
            }
        }
        if(!p) {
            cout << "Impossible\n";
            continue;
        }

        string res = "";
        int ptr_s = 0;
        int n = t.length();

        for(int i = 0; i < n; ++i) {
            for(int c = 0; c < 26; ++c) {
                if(count_t[c] > 0) {
                    bool mcase = (ptr_s < s.length()) && (s[ptr_s] - 'a' == c);
                    bool ss = count_t[c] > count_s[c];

                    if (mcase || ss) {
                        res += (char)('a' + c);
                        count_t[c]--;
                        // omg os proud of this
                        if (mcase) {
                            count_s[c]--; 
                            ptr_s++;
                        }
                        break; 
                    }
                }
            }
        }
        cout << res << "\n";
    }
    return 0;
}
