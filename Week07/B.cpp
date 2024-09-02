#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define dbg(x) cout << #x << " = " << x << endl
#define FOR(i, a, n) for(ll i = a; i < n; i++)

typedef unsigned long long ll;

const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 100001;
vector<vector<pair<ll,ll>>> grafo(MAX);
vector<ll> dist(MAX, LINF);
vector<ll> dist2(MAX, LINF);

ll n, m;

void bfs(ll v) {
    dist[v] = 0;
    set<pair<ll, pair<ll, bool>>> q;
    q.insert({0, {v, false}}); 

    while (!q.empty()) {
        ll atual = (*q.begin()).f;
        ll u = (*q.begin()).s.f;
        bool cupom = (*q.begin()).s.s;
        q.erase(q.begin());
        for(auto [w, custo] : grafo[u]){
            if(!cupom && atual + custo < dist[w]){
                q.erase({dist[w], {w, false}});
                dist[w] = atual + custo;
                q.insert({dist[w], {w, false}});
            }
            if(!cupom){
                ll desc = atual+custo/2;
                if (desc < dist2[w]){
                    q.erase({dist2[w],{w,true}});
                    dist2[w] = desc;
                    q.insert({dist2[w],{w,true}});
                }
            }
            if(cupom && atual + custo < dist2[w]){
                q.erase({dist2[w],{w,true}});
                dist2[w] = atual + custo;
                q.insert({dist2[w],{w,true}});
            }
        }
    }
    return;
}

int main(){ _
    cout<<fixed;
    cin>>n>>m;
    ll a,b,c;
    FOR(i,0,m){
        cin>>a>>b>>c;
        grafo[a].pb({b,c});
    }

    bfs(1);
    ll ans = min(dist[n], dist2[n]);
    cout<<ans<<endl;
    return 0;
}
