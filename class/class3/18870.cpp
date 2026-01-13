#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n;
pii a[1000004];
int b[1000004];

bool cmp(pii a, pii b){
    if(a.first < b.first) return true;
    return false;
}

void solve(){
    cin >> n;
    
    for(int i=0; i<n; i++){
        int t; cin >> t;
        a[i] = {t,i};
    }
    sort(a,a+n,cmp);

    for(int i=0,cnt=0; i<n; i++){
        if(i > 0 && a[i].first == a[i-1].first) b[a[i].second] = b[a[i-1].second];
        else b[a[i].second] = cnt++;
    }
    for(int i=0; i<n; i++) cout << b[i] << " ";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}