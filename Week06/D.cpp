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

vector<vector<int>> grafo(100001);
vector<int> pocas(100001,0);


void solve(int i, int pai, int m, int consec, int & resposta){
    if(pocas[i]==1){
        consec++;
        if(consec>m) return;
    }
    else consec = 0;
    bool ext = true;
    for (auto filho : grafo[i]){
        if(filho != pai){
            ext = false;
            solve(filho,i,m,consec,resposta);
        }
    }
    if(ext) resposta++;
    return;
}

int main(){ _
    cout<<fixed;
    int n,m; cin>>n>>m;
    int a;
    FOR(i,1,n+1){
        cin>>a;
        if(a==1) pocas[i] = a;
    }
    int b;
    FOR(i,1,n){
        cin>>a>>b;
        grafo[a].pb(b);
        grafo[b].pb(a);
    }
    int resposta = 0;
    solve(1,0,m,0,resposta);
    cout<<resposta<<endl;
    return 0;
}
