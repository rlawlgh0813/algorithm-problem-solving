#include <bits/stdc++.h>
using namespace std;
int n,m;
map<string,string> mp;

void solve(){
    cin >> n >> m;

    for(int i=0; i<n; i++){
        string a,b; cin >> a >> b;
        mp[a] = b;
    }
    
    for(int i=0; i<m; i++){
        string a; cin >> a;
        cout << mp[a] << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}