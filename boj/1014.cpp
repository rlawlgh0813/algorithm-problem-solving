#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[11], dp[11][1<<11];

void solve(){
    cin >> n >> m;
    memset(dp, 0, sizeof(dp));
    
    for(int i=1; i<=n; i++){
        string s; cin >> s;
        int mask = 0;
        for(int j=0; j<m; j++) if(s[j] == 'x') mask |= (1<<j);
        a[i] = mask;
    }

    for(int row=1; row<=n; row++){
        for(int mask=0; mask<(1<<m); mask++){
            if(a[row] & mask || mask & (mask << 1)) continue;
            
            for(int pmask=0; pmask<(1<<m); pmask++){
                if(a[row-1] & pmask || pmask & (pmask << 1)) continue;
                if(mask & (pmask<<1) || mask & (pmask>>1)) continue; 
                dp[row][mask] = max(dp[row][mask], dp[row-1][pmask] + __builtin_popcount(mask));
            }
        }
    }

    int ret = 0;
    for(int mask=0; mask<(1<<m); mask++) ret = max(ret, dp[n][mask]);
    cout << ret << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int tc; cin >> tc;
    while(tc--) solve();
    return 0;
}