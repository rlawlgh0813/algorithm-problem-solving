#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
int n, ret = INF;
int dp[5004];

void solve(){
    cin >> n;

    for(int i=1; i<=5000; i++) dp[i] = INF;
    for(int i=0; i<5000; i++){
        if(i+3 <= 5000) dp[i+3] = min(dp[i+3], dp[i]+1);
        if(i+5 <= 5000) dp[i+5] = min(dp[i+5], dp[i]+1);
    }
    cout << (dp[n] == INF ? -1 : dp[n]);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}