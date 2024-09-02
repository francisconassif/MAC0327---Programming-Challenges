#include <bits/stdc++.h>
#include <sstream>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define FOR(i, a, n) for(ll i = a; i < n; i++)

typedef unsigned long long ll;
typedef pair<ll,ll> pll;

const ll MAXN = 100001;

ll n,m;
vector<ll> grafo[MAXN];
ll tempo[MAXN];
ll minimo[MAXN];
ll pai[MAXN];
vector<pll> estradas;
//bool crucial[MAXN];
ll rel = 0;

void dfs(ll v){
    ll filhos = 0;
    rel++;
    minimo[v] = rel;
    tempo[v]= rel;
    for(auto filho: grafo[v]){
        if(tempo[filho]==0){
            filhos++;
            pai[filho]=v;
            dfs(filho);
            minimo[v]=min(minimo[v],minimo[filho]);
            //if(pai[v] == -1 && filhos > 1) crucial[v]=true;
            //if(pai[v] != -1 && minimo[filho] >= tempo[v]) crucial[v]=true;
            if(minimo[filho]>tempo[v]) estradas.pb({v,filho});
        }
        else if(filho!=pai[v]){
            minimo[v]=min(minimo[v],tempo[filho]);
        }
    }


}

int main(){ _
    cout<<fixed;
    cin>>n>>m;
    ll a,b;
    FOR(i,0,m){
        cin>>a>>b;
        grafo[a].pb(b);
        grafo[b].pb(a);
    }
    memset(tempo, 0, sizeof tempo);
    memset(minimo, 0, sizeof minimo);
    memset(pai, -1, sizeof pai);
    //memset(crucial, false, sizeof crucial);
    FOR(i,1,n+1) if(tempo[i]==0) dfs(i);
    //stringstream ans;
    ll tam = estradas.size();
    cout<<tam<<endl;
    FOR(i,0,tam){ 
        cout<<estradas[i].f<<' '<<estradas[i].s<<endl;
    }
    //ans<<endl;
    //cout<<tam<<endl<<ans.str();

    return 0;
}
