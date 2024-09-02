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
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
//const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ll MAXN = 100001;
const ll MAXLOG = 17;

ll n, k;
ll altura[MAXN];
ll sobe[MAXN][MAXLOG];
ll maximo[MAXN][MAXLOG];
ll minimo[MAXN][MAXLOG];
vector<vector<pll>> grafo;


ll exp(ll base, ll exp){
    ll res = 1;  
    while (exp > 0){
        if (exp%2 == 1){  
            res = res*base;
        }
        base = base*base;  
        exp = exp/2;       
    }
    return res; 
}

void preenche(ll no, ll pai, ll comp){
    sobe[no][0] = pai;
    if (pai != -1){
        altura[no]=altura[pai]+1;
        maximo[no][0] = comp;
        minimo[no][0] = comp;
    }
    else altura[no]=0;
    FOR(i,1,MAXLOG){
        if(sobe[no][i-1] != -1){
            sobe[no][i] = sobe[sobe[no][i-1]][i-1];
            maximo[no][i] = max(maximo[no][i-1], maximo[sobe[no][i-1]][i-1]);
            minimo[no][i] = min(minimo[no][i-1], minimo[sobe[no][i-1]][i-1]);
        }
    }
    for(auto &fi : grafo[no]){
        if(fi.f != pai){
            preenche(fi.f, no, fi.s);
        }
    }
}

ll lca(ll x, ll y, ll &menor, ll &maior){
    if(altura[x]<altura[y]) swap(x,y);
    menor = INF;
    maior = -1;
    ROR(i,MAXLOG-1,-1){
        if(altura[x]-exp(2,i) >= altura[y]){
            maior = max(maior,maximo[x][i]);
            menor = min(menor,minimo[x][i]);
            x = sobe[x][i];
        }
    }
    if(x == y) return x;
    ROR(i, MAXLOG-1, -1){
        if(sobe[x][i] != sobe[y][i]){
            maior = max({maior, maximo[x][i], maximo[y][i]});
            menor = min({menor, minimo[x][i], minimo[y][i]});
            x = sobe[x][i];
            y = sobe[y][i];
        }
    }
    maior = max({maior, maximo[x][0], maximo[y][0]});
    menor = min({menor, minimo[x][0], minimo[y][0]});
    return sobe[x][0];
}

pll dist(ll x, ll y){
    ll menor, maior;
    lca(x, y, menor, maior);
    return {menor,maior};
}

int main(){ _
    cin >> n;
    grafo.resize(n+1);
    memset(sobe, -1, sizeof sobe);
    //memset(maximo, -1, sizeof maximo);
    //memset(minimo, INF, sizeof minimo);
    FOR(i, 0, n-1){
        ll a,b,c;
        cin>>a>>b>>c;
        grafo[a].pb({b,c});
        grafo[b].pb({a,c});
    }
    preenche(1,-1,0);
    cin>>k;
    FOR(i,0,k){
        ll d,e;
        cin>>d>>e;
        auto [ans1, ans2] = dist(d,e);
        cout<<ans1<<' '<<ans2<<'\n';
    }
    return 0;
}
