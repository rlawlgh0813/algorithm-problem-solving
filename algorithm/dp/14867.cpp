#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
int a,b,c,d,cur,ret=INF;
int dp[2][1004][1004]; // dp[이전용][a의 양][b의 양] = 횟수

void solve(){
    cin >> a >> b >> c >> d;
    dp[0][0][0] = 1;
    for(int k=0; k<1004; k++){
        for(int i=0; i<1004; i++){
            for(int j=0; j<1004; j++){
                if(dp[cur][c][d]) ret = min(ret, dp[cur][c][d]);
                if(dp[cur][i][j]){
                    dp[cur^1][a][j] = min(dp[cur][i][j]+1, dp[cur^1][a][j]);
                    dp[cur^1][i][b] = min(dp[cur][i][j]+1, dp[cur^1][i][b]);
                    dp[cur^1][0][j] = min(dp[cur][i][j]+1, dp[cur^1][0][j]);
                    dp[cur^1][i][0] = min(dp[cur][i][j]+1, dp[cur^1][i][0]);
                    if(i+j > a) dp[cur^1][a][j+i-a] = min(dp[cur][i][j]+1, dp[cur^1][a][i+j-a]);
                    else dp[cur^1][i+j][0] = min(dp[cur][i][j]+1, dp[cur^1][i+j][0]);
                    if(i+j > b) dp[cur^1][i+j-b][b] = min(dp[cur][i][j]+1, dp[cur^1][i+j-b][b]);
                    else dp[cur^1][0][i+j] = min(dp[cur][i][j]+1, dp[cur^1][0][i+j]);
                }
            }
        }
        cur ^= 1;
    }
    cout << (ret == INF ? -1 : ret);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}