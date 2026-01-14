#include <bits/stdc++.h>
using namespace std;
int a,b;
int dp[19][19];
double ret = 0;
double r[2];

int check(int n){
    if(n == 2 || n == 3 || n == 5 || n == 7 || n == 11 || n == 13) return 1;
    return 0;
}

void solve(){
    for(int i=0; i<2; i++){
        int t; cin >> t;
        r[i] = t / 100;
    }

    for(int i=0; i<19; i++){
        if(check(i)) continue;
        double temp = 
        for(int j=0; j<19; j++){
            if(check(j)) continue;
        }
    }
    cout << 1 - ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}