#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define dbg(x) cout << #x << " = " << x << endl
#define FOR(i, a, n) for(ll i = a; i < n; i++)
#define ROR(i, n, a) for(ll i = n; i > a; i--)

typedef int ll;

const int INF = 0x3f3f3f3f;
//const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ll MAXN = 200001;
const ll MAXLOG = 18;

ll n,q,a,b;
vector<vector<ll>> grafo;
ll altura[MAXN];
ll sobe[MAXN][MAXLOG];

void preenche(ll no, ll pai){
    sobe[no][0]=pai;
    FOR(i,1,MAXLOG){
        if(sobe[no][i-1]!=-1){
            sobe[no][i]=sobe[sobe[no][i-1]][i-1];
        }
    }
    for(auto fi : grafo[no]){
        if(fi != pai){
            altura[fi] = altura[no]+1;
            preenche(fi,no);
        }
    }
}

ll lca(ll x, ll y){
    if(altura[x]<altura[y]) swap(x,y);
    ROR(i,MAXLOG-1,-1){
        if(sobe[x][i]!=-1 && altura[sobe[x][i]] >= altura[y]){
            x = sobe[x][i];
        }
    }
    if(x == y) return x;
    ROR(i,MAXLOG-1,-1){
        if(sobe[x][i] != sobe[y][i]){
            x = sobe[x][i];
            y = sobe[y][i];
        }
    }
    return sobe[x][0];
}

ll dist(ll x, ll y){
    ll anc = lca(x,y);
    return altura[x]+altura[y]-2*altura[anc];
}

int main(){ _
    cin>>n>>q;
    grafo.resize(n+1);
    memset(sobe, -1, sizeof sobe);
    memset(altura,0,sizeof altura);
    FOR(i,1,n){
        cin>>a>>b;
        grafo[a].pb(b);
        grafo[b].pb(a);
    }
    preenche(1,-1);
    ll ans;
    FOR(i,0,q){
        cin>>a>>b;
        ans = dist(a,b);
        cout<<ans<<'\n';
    }

    return 0;
}
