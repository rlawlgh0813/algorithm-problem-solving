#include <bits/stdc++.h>
using namespace std;
int n,m,ret;
int parent[100004];
vector<int> v;
struct cmp{
    bool operator()(tuple<int,int,int> a, tuple<int,int,int> b){
        return get<2>(a) > get<2>(b);
    }
};
priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>, cmp> pq;

int Find(int n){
    if(parent[n] == n) return n;
    return parent[n] = Find(parent[n]);
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a == b) return;
    parent[b] = a;
}

void solve(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int s,e,w; cin >> s >> e >> w;
        pq.emplace(s,e,w);
    }
    for(int i=1; i<=n; i++) parent[i] = i;

    while(pq.size()){
        int s,e,w;
        tie(s,e,w) = pq.top(); pq.pop();

        if(Find(s) != Find(e)){
            Union(s,e);
            v.push_back(w);
        }
    }

    for(int i=0; i<v.size()-1; i++) ret += v[i];
    cout << ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    solve();
    return 0;
}