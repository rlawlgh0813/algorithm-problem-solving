#include <bits/stdc++.h>
using namespace std;
int n,m;
struct node{
    string name;
    node* next;
};

void solve(){
    node root;

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> m;
        node prev = root;
        for(int j=0; j<m; j++){
            node temp; scanf("%s",temp.name);
            prev.next = &temp;
            prev = temp;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    solve();
    return 0;
}