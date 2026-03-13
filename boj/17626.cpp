#include <bits/stdc++.h>
using namespace std;
int n;
int dp[50004];

void solve(){
    cin >> n;
    
    for(int i=1; i<=50000; i++) dp[i] = 1e9;
    for(int i=0; i<=50000; i++){
        for(int j=1; j<=240; j++) if(i+(j*j) <= 50000) dp[i+(j*j)] = min(dp[i+(j*j)], dp[i]+1);
    }
    cout << dp[n];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}