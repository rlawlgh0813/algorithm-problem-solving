#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
int n, ret = 1e9;
int val[1004][4], dp[1004][4];

void solve(){
    cin >> n;
    for(int i=0; i<n; i++) for(int j=0; j<3; j++) cin >> val[i][j];

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++) dp[0][j] = ((j == i) ? val[0][j] : INF);

        for(int i=1; i<n; i++){
            dp[i][0] = dp[i][0] + min(dp[i-1][1], dp[i-1][2]);
            dp[i][0] = dp[i][1] + min(dp[i-1][0], dp[i-1][2]);
            dp[i][2] = dp[i][2] + min(dp[i-1][0], dp[i-1][1]);
        }

        for(int j=0; j<3; j++) if(j != i) ret = min(ret, dp[n-1][j]);
    }
    cout << ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    solve();
    return 0;
}