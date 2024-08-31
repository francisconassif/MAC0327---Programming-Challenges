#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second
#define pb push_back
#define FOR(i, a, n) for(int i = a; i < n; i++)

char lab[501][501];
bool vis[502][502];

int n,m,k;

void dfs(int a, int b){
    vis[a][b]=true;
    k--;
    if(k<=0) return;
    if(a+1>=0 && a+1<n && b>=0 && b<m){
        if(lab[a+1][b]=='.') if(!vis[a+1][b]) dfs(a+1,b);
    }
    if(k<=0) return;
    if(a-1>=0 && a-1<n && b>=0 && b<m){
        if(lab[a-1][b]=='.') if(!vis[a-1][b]) dfs(a-1,b);
    }
    if(k<=0) return;
    if(a>=0 && a<n && b+1>=0 && b+1<m){
        if(lab[a][b+1]=='.') if(!vis[a][b+1]) dfs(a,b+1);
    }
    if(k<=0) return;
    if(a>=0 && a<n && b-1>=0 && b-1<m){
        if(lab[a][b-1]=='.') if(!vis[a][b-1]) dfs(a,b-1);
    }
    return;
}

void solve(){
    vector<pair<int,int>> caminho;

    FOR(i,0,n+1) FOR(j,0,m+1) vis[i][j]=false;

    FOR(i,0,n) FOR(j,0,m)
        if(lab[i][j]=='.') 
            caminho.pb({i,j});

    int tam = caminho.size();
    k = tam-k;

    dfs(caminho[0].f, caminho[0].s);

    FOR(i,0,tam)
        if(!vis[caminho[i].f][caminho[i].s]) 
            lab[caminho[i].f][caminho[i].s] = 'X';
}   

int main(){
    cin>>n>>m>>k;
    FOR(i,0,n) cin>>lab[i];
    solve();
    FOR(i,0,n){
        FOR(j,0,m) cout<<lab[i][j];
        cout<<endl;
    }
    return 0;
}
