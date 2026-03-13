#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
int dp[200004];
vector<pair<int,int>> v;

void solve(){
    cin >> n >> k;
    for(int i=0; i<n; i++){
        int a,b; cin >> a >> b;
        v.push_back({a,b});
    }

    for(auto o : v){
        for(int i=k; i>=o.first; i--){
            dp[i] = max(dp[i],dp[i-o.first] + o.second);
        }
    }
    cout << dp[k];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}