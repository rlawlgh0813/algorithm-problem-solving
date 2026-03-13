#include <bits/stdc++.h>
using namespace std;
int n,m,cnt = 1;
int order[10004], low[10004];
vector<int> v[10004];
set<int> ret;

void go(int here, int parent){
    order[here] = low[here] = cnt++;

    int child = 0;
    for(auto there : v[here]){
        if(there == parent) continue;
        if(!order[there]){
            child++;
            go(there, here);
            if(!parent && child > 1) ret.insert(here);
            else if(parent && low[there] >= order[here]) ret.insert(here);
            low[here] = min(low[here], low[there]);
        }else{
            low[here] = min(low[here], order[there]);
        }
    }
}

void solve(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int p,q; cin >> p >> q;
        v[p].push_back(q);
        v[q].push_back(p);
    }
    for(int i=1; i<=n; i++) if(!order[i]) go(i, 0);

    cout << ret.size() << '\n';
    for(auto x : ret) cout << x << " ";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}