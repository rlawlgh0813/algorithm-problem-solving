#include <bits/stdc++.h>
using namespace std;
int n, m, ret;
int parent[54];
vector<int> v, a[54];

int Find(int n){
    if(parent[n] == n) return n;
    return parent[n] = Find(parent[n]);
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    parent[a] = b;
}

void solve(){
    cin >> n >> m;
    for(int i=1; i<=n; i++) parent[i] = i;

    int t; cin >> t;
    for(int i=0; i<t; i++){
        int temp; cin >> temp;
        v.push_back(temp);
    }

    for(int i=0; i<m; i++){
        int temp; cin >> temp;
        int s,e;
        for(int j=0; j<temp; j++){
            cin >> e;
            a[i].push_back(e);
            if(j) Union(s,e);
            s = e;
        }
    }

    if(t == 0) ret = m;
    else{
        for(int i=0; i<m; i++){
            int check = 0;
            for(auto cur : a[i]){
                for(auto x : v){
                    if(Find(cur) == Find(x)){
                        check = 1;
                        break;
                    }
                }
                if(check) break;
            }
            if(check == 0) ret++;
        }
    }
    cout << ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    solve();
    return 0;
}