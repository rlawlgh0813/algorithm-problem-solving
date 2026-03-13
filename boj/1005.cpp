#include <bits/stdc++.h>
using namespace std;
int n,m,target;
int indeg[1004], weight[1004];
vector<int> v[1004];

void solve(){
    memset(indeg,0,sizeof(indeg));
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> weight[i];
        v[i].clear();
    }
    for(int i=0; i<m; i++){
        int p,q; cin >> p >> q;
        v[q].push_back(p);
        indeg[p]++;
    }
    cin >> target;

    queue<int> temp;
    for(int i=1; i<=n; i++) if(!indeg[i] && i != target) temp.push(i);

    while(temp.size()){
        int here = temp.front(); temp.pop();
        for(auto there : v[here]) if(!(--indeg[there]) && there != target) temp.push(there);
    }

    int ret = 0, cnt = 0;
    queue<int> Q,q;
    Q.push(target);
    while(1){
        if(Q.empty()){
            ret += cnt;
            if(q.empty()) break;
            Q.swap(q);
            cnt = 0;
        }
        int here = Q.front(); Q.pop();
        for(auto there : v[here]) if(!(--indeg[there])) q.push(there);
        cnt = max(cnt, weight[here]);
    }
    cout << ret << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    int tc; cin >> tc;
    while(tc--) solve();
    return 0;
}