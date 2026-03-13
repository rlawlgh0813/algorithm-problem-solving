#include <bits/stdc++.h>
using namespace std;
int n,m,ret;
int dp[1104];
vector<pair<int,int>> v;

void solve(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int p,q; cin >> p >> q;
        v.push_back({p,q});
    }

    for(int i=1; i<=1100; i++) dp[i] = 100000;
    for(int i=1; i<=1100; i++){
        for(auto x : v){
            if(i - x.second < 0) continue;
            dp[i] = min(dp[i], dp[i-x.second] + x.first);
        }
    }
    
    ret = dp[n];
    for(int i=n+1; i<=1100; i++) ret = min(ret, dp[i]);
    cout << ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    solve();
    return 0;
}