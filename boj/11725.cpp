#include <bits/stdc++.h>
using namespace std;
vector<int> v[100004];
int n;
int ret[100004];

void go(int a, int parent){
    if(v[a].empty()) return;
    for(auto x : v[a]){
        if(x == parent) continue;
        go(x, a);
        ret[x] = a;
    }
}

void solve(){
    cin >> n;
    for(int i=0; i<n-1; i++){
        int a,b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    go(1, 0);
    for(int i=2; i<=n; i++) cout << ret[i] << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    solve();
    return 0;
}