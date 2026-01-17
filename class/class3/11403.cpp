#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
int n;
int a[104][104];

void solve(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
            if(!a[i][j]) a[i][j] = INF;
        }
    }

    for(int k=0; k<n; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                a[i][j] = min(a[i][j], a[i][k]+a[k][j]);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cout << ((a[i][j] == INF) ? 0 : 1) << " ";
        cout << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}