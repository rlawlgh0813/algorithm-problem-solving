#include <bits/stdc++.h>
using namespace std;
#define MOD 1000007
int n,m,c,ret;
int a[51][51], dp[52][52][52][52];
vector<pair<int,int>> v;

void solve(){
    cin >> n >> m >> c;
    for(int i=1; i<=c; i++){  
        int p,q; cin >> p >> q;
        a[p][q] = i;
    }

    if(a[1][1]) dp[1][1][1][a[1][1]] = 1;
    else dp[1][1][0][0] = 1;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(i==1 && j==1) continue;
            if(a[i][j] == 0){
                for(int k=0; k<=c; k++){
                    for(int prev=0; prev<=c; prev++){
                        dp[i][j][k][prev] += dp[i-1][j][k][prev] + dp[i][j-1][k][prev];
                        dp[i][j][k][prev] %= MOD;
                    }
                }
            }else{
                for(int k=1; k<=c; k++){
                    for(int prev=0; prev<a[i][j]; prev++){
                        dp[i][j][k][a[i][j]] += dp[i-1][j][k-1][prev] + dp[i][j-1][k-1][prev];
                        dp[i][j][k][a[i][j]] %= MOD;
                    }
                }
            }
        }
    }

    for(int i=0; i<=c; i++){
        int ret = 0;
        for(int j=0; j<=c; j++) ret += dp[n][m][i][j] % MOD;
        cout << ret % MOD << " ";
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}