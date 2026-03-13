#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,ret;

void solve(){
    cin >> a >> b;

    ret = 1;
    while(b > 0){
        if(b == a) break;
        if(b == 0 || b < a){ ret = -1; break; }
        
        if(b % 2 == 0){ b /= 2; ret++; }
        else if((b % 10) == 1){ b /= 10; ret++; }
        else{ ret = -1; break;}
    }
    cout << ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    solve();
    return 0;
}