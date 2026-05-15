#include <bits/stdc++.h>
using namespace std;
int sum,l,r;
vector<int> v;

void solve(){
    for(int i=0; i<9; i++){
        int t; cin >> t;
        v.push_back(t);
        sum += t;
    }
    sort(v.begin(), v.end());

    for(int i=0; i<9; i++){
        for(int j=i+1; j<9; j++){
            if(sum - v[i] - v[j] == 100){
                l = i; r = j;
            }
        }
    }

    for(int i=0; i<9; i++) if(i != l && i != r) cout << v[i] << '\n'; 
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}