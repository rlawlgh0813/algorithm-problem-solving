#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
int n;
vector<pair<int,int>> v;
int dp[504][504];

void solve(){
    cin >> n;
    for(int i=0; i<n; i++){
        int a,b; cin >> a >> b;
        v.push_back({a,b});
    }
    
    for(int gap=1; gap<n; gap++){
        for(int i=0; i<n-gap; i++){
            dp[i][i+gap] = INF;
            for(int j=i; j<i+gap; j++){
                dp[i][i+gap] = min(dp[i][i+gap], dp[i][j] + dp[j+1][i+gap] + v[i].first * v[j].second * v[i+gap].second);
            }
        }
    }
    cout << dp[0][n-1];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    solve();
    return 0;
}