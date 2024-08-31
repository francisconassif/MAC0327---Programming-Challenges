#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define dbg(x) cout << #x << " = " << x << endl
#define FOR(i, a, n) for(int i = a; i < n; i++)

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;



void dfs(int i, vector<bool> & visit, vector<vector<int>> &grafo){
    visit[i]=true;
    for(auto filho : grafo[i]) if(!visit[filho]) dfs(filho,visit,grafo);
    return;
}

int main(){ _
    int m, n;
    vector<pair<int,int>> resposta;
    cin>>n>>m;
    int a,b;
    vector<bool> visit(n+1,false);
    vector<vector<int>> grafo(n+1);
    FOR(i,0,m){
        cin>>a>>b;
        grafo[a].pb(b);
        grafo[b].pb(a);
    }
    dfs(1,visit,grafo);
    FOR(i,2,n+1){
        if(!visit[i]){
            pair<int,int> rua = {i-1, i};
            resposta.pb(rua);
            dfs(i,visit,grafo);
        }
    }
    int tam = resposta.size();
    cout<<tam<<endl;
    for(auto rua : resposta){
        cout<<rua.f<<' '<<rua.s<<endl;
    }
    return 0;
}
