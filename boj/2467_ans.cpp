#include <bits/stdc++.h>
using namespace std;
int n, ret = 2000000001, ret1, ret2;
int a[100004];

void solve(){
    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];
    
    int s = 0, e = n-1;
    while(s < e){
        int cur = a[s] + a[e];
        if(ret > abs(cur)){
            ret = abs(cur);
            ret1 = a[s];
            ret2 = a[e];
        }
        if(cur > 0) e--;
        else s++;
    }

    cout << ret1 << " " << ret2;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    solve();
    return 0;
}