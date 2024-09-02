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
typedef pair<ll,ll> pll;

ll n,m,q;
vector<ll> pai;
vector<ll> cortado;
vector<ll> ord_cort;
vector<pair<pll,ll>> estradas;
ll comp;

vector<ll> ans;

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
    pai[paib] = paia;
    comp--;
    return;
}

void solve(){
    ll x, y;
    for(auto &estrada : estradas){
        if(cortado[estrada.s]==1){
            continue;
        }
        x = estrada.f.f;
        y = estrada.f.s;
        une(x,y);
    }
    FOR(k,0,q){
        ans.pb(comp);
        x = estradas[ord_cort[q-1-k]].f.f;
        y = estradas[ord_cort[q-1-k]].f.s;
        une(x,y);   
    }
    ll t = ans.size();
    FOR(j,0,t) cout<<ans[t-j-1]<<' ';
    cout<<endl;
}

int main(){ _
    cin>>n>>m;
    ll a,b;
    estradas.resize(m);
    pai.resize(n);
    cortado.resize(m,0);
    comp = n;
    FOR(i,0,n) pai[i]=i;
    FOR(i,0,m){
        cin>>a>>b;
        estradas[i].f.f = a-1;
        estradas[i].f.s = b-1;
        estradas[i].s = i;
    }
    cin>>q;
    ord_cort.resize(q);
    FOR(i,0,q){
        cin>>ord_cort[i];
        ord_cort[i]--;
        cortado[ord_cort[i]]=1;
    }
    solve();
    return 0;
}
