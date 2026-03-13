#include <bits/stdc++.h>
using namespace std;
#define INF 1000
typedef long long ll;
int n;
ll m;
int a[6][6], ret[6][6], t[6][6];

void go(int a[][6], int b[][6]){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                t[i][j] += (a[i][k] * b[k][j]) % INF;
                t[i][j] %= INF;
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            b[i][j] = t[i][j];
            t[i][j] = 0;
        }
    }
}

void solve(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
            ret[i][j] = a[i][j] % INF;
        }
    }
    
    for(ll i = m - 1; i > 0; i /= 2){
        if(i & 1) go(a,ret);
        go(a,a);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cout << ret[i][j] << " ";
        cout << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    solve();
    return 0;
}