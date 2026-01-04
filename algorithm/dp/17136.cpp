#include <bits/stdc++.h>
using namespace std;
int ret,flag;
int a[12], block[6], block_cnt[6];

int go(int sz, int x, int y){
    int mask = block[sz] << (y + 1 - sz);
    for(int i=0; i<sz; i++) if((a[x+i] & mask) != mask) return 0;
    if(block_cnt[sz] > 5) return 0;
    for(int i=0; i<sz; i++) a[x+i] &= ~mask;
    block_cnt[sz]++;
    return 1;
}

void solve(){
    for(int i=1; i<6; i++){
        for(int j=0; j<i; j++){
            block[i] *= 2; block[i] |= 1;
        }
    }

    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            int tt; cin >> tt;
            a[i] *= 2; a[i] |= tt;
        }
    }

    for(int sz=5; sz>0; sz--){
        for(int i=0; i<=10-sz; i++){
            for(int j=sz-1; j<10; j++){
                ret += go(sz,i,j);
            }
        }
    }

    for(int i=0; i<10; i++) if(a[i]) flag = 1;
    cout << (flag ? -1 : ret);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}