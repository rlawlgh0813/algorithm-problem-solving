#include <bits/stdc++.h>
using namespace std;
int found;
int a[10][10], ret[10][10];

void go(int num, int idx){
    if(found) return;
    if(num > 9){
        for(int i=0; i<9; i++) for(int j=0; j<9; j++) ret[i][j] = a[i][j];
        found = 1;
        return;
    }

    for(int i=0; i<9; i++){
        if(a[idx][i] == num){
            (idx == 8) ? go(num+1, 0) : go(num, idx+1);
            return;
        }
    }

    for(int i=0; i<9; i++){
        if(a[idx][i]) continue;

        int flag = 0;
        for(int j=0; j<9; j++) if(a[j][i] == num) flag = 1;
        for(int x=0; x<3; x++) for(int y=0; y<3; y++) if(a[x + 3*(idx/3)][y + 3*(i/3)] == num) flag = 1;
        if(flag) continue;

        a[idx][i] = num;
        (idx == 8) ? go(num+1, 0) : go(num, idx+1);
        a[idx][i] = 0;
    }
}

void solve(){
    for(int i=0; i<9; i++){
        string s; cin >> s;
        for(int j=0; j<9; j++) a[i][j] = s[j] - '0';
    }

    go(1,0);
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++) cout << ret[i][j];
        cout << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    solve();
    return 0;
}