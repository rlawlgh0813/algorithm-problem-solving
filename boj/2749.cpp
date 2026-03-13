#include <bits/stdc++.h>
using namespace std;
#define INF 1500000
#define MOD 1000000
typedef long long ll;
ll n;
ll dp[INF+4];

void solve(){
    cin >> n;

    dp[0] = 0; dp[1] = 1;
    for(int i=2; i<INF+4; i++) dp[i] = (dp[i-1] + dp[i-2]) % MOD;

    cout << ((n % INF) ? dp[(n % INF)] : dp[INF]);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}