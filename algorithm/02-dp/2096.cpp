#include <bits/stdc++.h>
using namespace std;
int n,cur,pre;
int dp[2][4],dp2[2][4];

void solve(){
    cin >> n;
    for(int i=1; i<=n; i++){
        int a,b,c; cin >> a >> b >> c;
        cur = i&1, pre = cur^1;
        dp[cur][0] = max(dp[pre][0],dp[pre][1]) + a;
        dp[cur][1] = max(max(dp[pre][0],dp[pre][1]),dp[pre][2]) + b;
        dp[cur][2] = max(dp[pre][1],dp[pre][2]) + c;
        dp2[cur][0] = min(dp2[pre][0],dp2[pre][1]) + a;
        dp2[cur][1] = min(min(dp2[pre][0],dp2[pre][1]),dp2[pre][2]) + b;
        dp2[cur][2] = min(dp2[pre][1],dp2[pre][2]) + c;
    }

    cout << max(max(dp[cur][0],dp[cur][1]),dp[cur][2]) << " " << min(min(dp2[cur][0],dp2[cur][1]),dp2[cur][2]);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}