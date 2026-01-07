#include <bits/stdc++.h>
using namespace std;
int n,m,k,ret;
int a[12][12],w[12][12];
int dx[] = {-1,-1,-1,0,0,1,1,1}, dy[] = {-1,0,1,-1,1,-1,0,1};
typedef struct tree{
    int age,x,y;
    bool flag;
}tree;
deque<tree> v,temp;

bool cmp(tree a, tree b){
    if(a.age == b.age) return false;
    return a.age < b.age;
}

void solve(){
    cin >> n >> m >> k;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) a[i][j] = 5;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin >> w[i][j];
    for(int i=0; i<m; i++){
        tree t; cin >> t.x >> t.y >> t.age; t.flag = 0; t.x--; t.y--;
        v.push_back(t);
    }
    sort(v.begin(), v.end(), cmp);

    while(k--){
        // Spring
        for(int i=0; i<v.size(); i++){
            if(v[i].flag) continue;
            if(a[v[i].x][v[i].y] < v[i].age) v[i].flag = 1;
            else a[v[i].x][v[i].y] -= v[i].age++;
        }
        
        // Summer
        for(int i=0; i<v.size(); i++) if(v[i].flag) a[v[i].x][v[i].y] += (v[i].age / 2);
        
        // Fall
        for(int i=0; i<v.size(); i++){
            if(v[i].flag) continue;
            else temp.push_back(v[i]); 

            if (v[i].age % 5) continue;
            for(int j=0; j<8; j++){
                int nx = v[i].x + dx[j];
                int ny = v[i].y + dy[j];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                tree tt; tt.x = nx; tt.y = ny; tt.age = 1; tt.flag = 0;
                temp.push_front(tt);
            }
        }
        v = temp; temp.clear();
        
        // Winter
        for(int i=0; i<n; i++) for(int j=0; j<n; j++) a[i][j] += w[i][j];
    }

    for(auto t : v) if(!t.flag) ret++;
    cout << ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}