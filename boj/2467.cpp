#include <bits/stdc++.h>
using namespace std;
int n, idx, ret1 = 1000000001, ret2 = 1000000001;
vector<int> a,b;

int go(int num){
    int l = 0, r = b.size()-1, m;
    while(l <= r){
        m = (l+r) / 2;
        if(num == b[m]) break;
        if(b[m] < num) l = m+1;
        else r = m-1;
    }
    return l;
}

void solve(){
    cin >> n;
    for(int i=0; i<n; i++){
        int t; cin >> t;
        (t < 0) ? a.push_back(t) : b.push_back(t);
    }

    if(a.size() > 1){ 
        ret1 = a[a.size()-2]; 
        ret2 = a[a.size()-1]; 
    }
    if(b.size() > 1 && (abs(b[0]+b[1]) < abs(ret1+ret2))){ 
        ret1 = b[0]; 
        ret2 = b[1];
    }
    if(b.size() == 0 || a.size() == 0){
        cout << ret1 << " " << ret2;
        return;
    }
    
    for(int cur : a){
        idx = go(-cur);

        if(idx == 0){
            if(abs(ret1 + ret2) <= abs(cur + b[idx])) continue;
            ret1 = cur; ret2 = b[idx];
            continue;
        }
        if(abs(cur + b[idx]) < abs(cur + b[idx-1])){
            if(abs(ret1 + ret2) <= abs(cur + b[idx])) continue;
            ret1 = cur; ret2 = b[idx];
        }else{
            if(abs(ret1 + ret2) <= abs(cur + b[idx-1])) continue;
            ret1 = cur; ret2 = b[idx-1];
        }
    }

    cout << ret1 << " " << ret2;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    solve();
    return 0;
}