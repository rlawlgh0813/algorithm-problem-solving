#include <bits/stdc++.h>
using namespace std;
int n, ret = 1000000;
int val[1004][4];
int dp[1004][4];

void solve(){
    cin >> n;
    for(int i=0; i<n; i++) for(int j=0; j<3; j++) cin >> val[i][j];

    for(int i=0; i<3; i++) dp[0][i] = val[0][i];
    for(int i=1; i<n; i++){
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + val[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + val[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + val[i][2];
    }
    cout << min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2]));
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    solve();
    return 0;
}