#include <bits/stdc++.h>
using namespace std;
int n;
int a[304], dp[304][2];

void solve(){
    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];

    dp[0][0] = a[0]; dp[1][0] = a[1];
    for(int i=0; i<n; i++){
        dp[i+1][1] = max(dp[i+1][1], dp[i][0]+a[i+1]);
        dp[i+2][0] = max(dp[i+2][0], max(dp[i][0],dp[i][1])+a[i+2]);
    }
    cout << max(dp[n-1][0],dp[n-1][1]);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}