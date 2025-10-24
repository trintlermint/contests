
#include <bits/stdc++.h>
using namespace std;

long long mincost(int n, vector<long long> as, bool isvalley)
{
    long long c = 0;
    
    for(int i = 0; i < n; ++i)
    {
        bool currvalley = (i % 2 == 0) ? isvalley : !isvalley;
        
        if(currvalley)
        {
            long long maxr = LLONG_MAX;
            
            if(i > 0) maxr = min(maxr, (long long)as[i-1] - 1);
            if(i + 1 < n) maxr = min(maxr, (long long)as[i+1] - 1);
            if(maxr > 0)
            {
                if(as[i] > maxr) c += as[i] - maxr; as[i] = maxr;
            }
        }
        else
        {
            long long minr = 0;
            
            if(i > 0) minr = max(minr, (long long)as[i-1] + 1);
            if(i + 1 < n) minr = max(minr, (long long)as[i+1] + 1);
            
            if(as[i] < minr)
            {            }
        }
    }
    for(int i = 0; i < n - 1; ++i)
    {
        bool v1 = (i % 2 == 0) ? isvalley : !isvalley;
        bool v2 = (i + 1) % 2 == 0 ? isvalley : !isvalley;
        
        if(v1 && !v2)
        {
            if(as[i] >= as[i+1]) return LLONG_MAX;
        }
        else if(!v1 && v2)
        {
            if(as[i] <= as[i+1]) return LLONG_MAX;
        }
    }
    
    return c;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<long long> as(n);
        for(int i = 0; i < n; ++i) cin >> as[i];
        
        long long r1 = mincost(n, as, true);
        long long r2 = mincost(n, as, false);
        
        cout << min(r1, r2) << endl;
    }
    
    return 0;
}
