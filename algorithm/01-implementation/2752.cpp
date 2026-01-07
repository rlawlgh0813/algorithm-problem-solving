#include <bits/stdc++.h>
using namespace std;
vector<int> v;

void solve(){
    for(int i=0; i<3; i++){
        int t; cin >> t;
        v.push_back(t);
    }
    sort(v.begin(),v.end());
    for(auto x : v) cout << x << " ";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}