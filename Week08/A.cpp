#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define dbg(x) cout << #x << " = " << x << endl
#define FOR(i, a, n) for(ll i = a; i < n; i++)

typedef unsigned int ll;
typedef pair<ll,ll> pll;


const ll INF = 0x3f3f3f3f;
const ll MAXN = 100001;
const ll MAXM = 200001;

ll n,m;
vector<ll> pai;
vector<ll> tam;
vector<pll> estradas;
ll comp;
ll maxtam;

ll find(ll x){
    if (x != pai[x]){
        pai[x]=find(pai[x]);
    }
    return pai[x];
}

void une(ll a, ll b){
    ll paia = find(a);
    ll paib = find(b);
    if(paia == paib) return;
    if(tam[paia] < tam[paib]) swap(paia,paib);
    pai[paib] = paia;
    tam[paia] += tam[paib];
    comp--;
    maxtam = max(maxtam, tam[paia]);
    return;
}

void solve(){
    ll a, b;
    for(auto &estrada: estradas){
        a = estrada.f -1;
        b = estrada.s -1;
        une(a,b);
        cout<<comp<<' '<<maxtam<<endl;
    }

}

int main(){ _
    cin>>n>>m;
    estradas.resize(m);
    pai.resize(n);
    tam.resize(n,1);
    maxtam = 1;
    comp = n;
    FOR(i,0,n) pai[i]=i;
    FOR(i,0,m){
        cin>>estradas[i].f>>estradas[i].s;
    }
    solve();
    return 0;
}
