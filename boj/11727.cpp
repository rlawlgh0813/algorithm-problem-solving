#include <bits/stdc++.h>
using namespace std;
#define MOD 10007
int n;
int dp[1004];

void solve(){
    cin >> n;

    dp[0] = 1;
    for(int i=0; i<=1000; i++){
        dp[i+1] = (dp[i+1] + dp[i]) % MOD;
        dp[i+2] = (dp[i+2] + 2*dp[i]) % MOD; 
    }
    cout << dp[n] % MOD;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}