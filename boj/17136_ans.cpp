#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
int ret=INF,flag;
int a[12][12], block_cnt[6];

int check(int x, int y, int sz){
    if(x + sz > 10 || y + sz > 10) return 0;
    for(int i=0; i<sz; i++){
        for(int j=0; j<sz; j++){
            if(!a[x+i][y+j]) return 0;
        }
    }
    return 1;
}

void go(int x, int y, int sz, int val){
    for(int i=0; i<sz; i++){
        for(int j=0; j<sz; j++){
            a[x+i][y+j] = val;
        }
    }
}

void dfs(int x, int y, int cnt){
    if(cnt > ret) return;
    if(y > 9){ dfs(x+1,0,cnt); return; }
    if(x > 9){ ret = min(ret,cnt); return; }
    if(!a[x][y]){ dfs(x,y+1,cnt); return; }

    for(int sz=5; sz>0; sz--){
        if(check(x,y,sz) && block_cnt[sz] < 5){
            go(x,y,sz,0);
            block_cnt[sz]++;
            dfs(x,y+1,cnt+1);
            block_cnt[sz]--;
            go(x,y,sz,1);
        }
    }
}

void solve(){
    for(int i=0; i<10; i++) for(int j=0; j<10; j++) cin >> a[i][j];
    dfs(0,0,0);
    cout << (ret == INF ? -1 : ret);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}