#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define dbg(x) cout << #x << " = " << x << endl
#define FOR(i, a, n) for(ll i = a; i < n; i++)

typedef long long ll;

const int MAX = 100001;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll n,m;
map<ll,vector<pair<ll,ll>>> grafo;
ll pai[MAX];
ll dist[MAX];

void dijkstra(ll v){
    set<pair<ll, ll>> q;
    q.insert({0, v});
    dist[v] = 0;

    while (!q.empty()) {
        ll no = (*q.begin()).s;
        q.erase(q.begin());
        for (auto &fi : grafo[no]) {
            if (dist[no] + fi.s < dist[fi.f]) {
                if (dist[fi.f] != LINF) {
                    q.erase({dist[fi.f], fi.f});
                }
                dist[fi.f] = dist[no] + fi.s;
                q.insert({dist[fi.f], fi.f});
                pai[fi.f] = no;
            }
        }
    }
}

int main(){ _
    cout<<fixed;
    cin>>n>>m;
    memset(pai, -1, sizeof pai);
    FOR(i, 1, n+1) dist[i] = LINF; 

    FOR(i, 0, m){
        ll a, b, w;
        cin >> a >> b >> w;
        grafo[a].pb({b, w});
        grafo[b].pb({a, w});
    }

    dijkstra(1);
    
    if (dist[n] == LINF){
        cout<<-1<<endl;
        return 0;
    }
    vector<ll> resposta;
    ll v = n;
    while(v!=-1){
        resposta.pb(v);
        v = pai[v];
    }
    ll tam = resposta.size();
    FOR(i,0,tam){
        cout<<resposta[tam-i-1]<<' ';
    }
    cout<<endl;

    return 0;
}
