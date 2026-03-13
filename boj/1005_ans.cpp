#include <bits/stdc++.h>
using namespace std;
int n,m,target;
int indeg[1004], weight[1004], dp[1004];
vector<int> v[1004];

void solve(){
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> weight[i];
        v[i].clear();
        dp[i] = weight[i];
        indeg[i] = 0;
    }
    for(int i=0; i<m; i++){
        int p,q; cin >> p >> q;
        v[p].push_back(q);
        indeg[q]++;
    }
    cin >> target;

    queue<int> q;
    for(int i=1; i<=n; i++) if(!indeg[i]) q.push(i);
    while(q.size()){
        int here = q.front(); q.pop();
        
        for(auto there : v[here]){
            dp[there] = max(dp[there],dp[here]+weight[there]);
            if(!(--indeg[there])) q.push(there);
        }
    }
    cout << dp[target] << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    int tc; cin >> tc;
    while(tc--) solve();
    return 0;
}