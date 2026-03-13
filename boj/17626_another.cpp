#include <bits/stdc++.h>
using namespace std;
int n;
int dp[50004];

void solve(){
    cin >> n;
    
    dp[0] = 0;
    for(int i=1; i<=n; i++){
        dp[i] = 1e9;;
        for(int j=1; j*j <= i; j++) dp[i] = min(dp[i], dp[i- j*j] + 1);
    }
    cout << dp[n];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}