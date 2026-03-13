#include <bits/stdc++.h>
using namespace std;
int n;
int dp[15];

void solve(){
    cin >> n;
    memset(dp,0,sizeof(dp));

    dp[1] = 1; dp[2] = 1; dp[3] = 1;
    for(int i=2; i<=n; i++){
        if(i-1 >= 0) dp[i] += dp[i-1];
        if(i-2 >= 0) dp[i] += dp[i-2];
        if(i-3 >= 0) dp[i] += dp[i-3];
    }
    cout << dp[n] << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int tc; cin >> tc;
    while(tc--) solve();

    return 0;
}