#include <bits/stdc++.h>
using namespace std;
int found;
int a[10][10];

void go(int x, int y){
    if(found) return;
    if(x > 8){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++) cout << a[i][j];
            cout << '\n';
        }
        found = 1;
        return;
    }

    if(a[x][y]) (y < 8) ? go(x,y+1) : go(x+1,0);
    for(int num=1; num<=9; num++){
        int flag = 0;
        for(int i=0; i<9; i++) if(a[i][y] == num || a[x][i] == num) flag = 1;
        for(int i=0; i<3; i++) for(int j=0; j<3; j++) if(a[i + 3*(x/3)][j + 3*(y/3)] == num) flag = 1;
        if(flag) continue;

        a[x][y] = num;
        (y < 8) ? go(x,y+1) : go(x+1,0);
        a[x][y] = 0;
    }
}

void solve(){
    for(int i=0; i<9; i++){
        string s; cin >> s;
        for(int j=0; j<9; j++) a[i][j] = s[j] - '0';
    }

    go(0,0);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    solve();
    return 0;
}