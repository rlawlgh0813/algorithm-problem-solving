#include <bits/stdc++.h>
using namespace std;
int n,ret;
int w[100], v[100], dp[100];

void solve(){
    cin >> n;
    for(int i=0; i<n; i++) cin >> w[i];
    for(int i=0; i<n; i++) cin >> v[i];
    
    for(int i=0; i<n; i++){
        for(int j=100; j>=w[i]; j--){
            dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
        }
    }

    for(int i=1; i<100; i++) ret = max(ret, dp[i]);
    cout << '\n' << ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}