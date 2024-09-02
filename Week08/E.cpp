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
typedef pair<ll,ll> pll;
typedef tuple<ll,ll,ll> tll;

//const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;
ll n,k;
vector<ll> pai;
vector<ll> tam;
vector<tll> arestas;
vector<ll> grau;
//ll comp;

ll find(ll x){
    if(x != pai[x]){
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
    //comp--;
    return;
}

ll exp(ll base, ll exp) {
    ll resp = 1;
    base = base%MOD;
    while(exp>0){
        if(exp%2 == 1){
            resp=(resp*base)%MOD;
        }
        exp = exp/2;
        base = (base*base)%MOD;
    }
    return resp;
}

void solve(){

}

int main(){ _
    cin>>n>>k;
    tam.resize(n,1);
    arestas.resize(n-1);
    pai.resize(n);
    iota(pai.begin(),pai.end(),0);
    ll a,b,c;
    ll j = 0;
    //comp = n;
    FOR(i,0,n-1){
        cin>>a>>b>>c;
        a--;
        b--;
        if(c == 0){
            arestas[j] = {a,b,c};
            j++;
        }    
    }
    if(j == n-1){
        cout<<"0\n";
        return 0;
    }
    ll maximo = exp(n,k)-n;
    //ll graumin = 0;
    FOR(i,0,j){
        a = get<0>(arestas[i]);
        b = get<1>(arestas[i]);
        //graumin = min(grau[a], grau[b]);
        une(a,b);
    }
    vector<bool> visi(n,false);
    ll subtotal = 0;
    FOR(i,0,n){
        ll paii = find(i);
        if(visi[paii]) continue;
        visi[paii]=true;
        ll sub = exp(tam[paii],k) - tam[paii];
        subtotal = (subtotal%MOD+sub%MOD)%MOD;
    }
    if(subtotal <= maximo) maximo -= subtotal;
    else{
        subtotal = MOD - subtotal;
        maximo = (maximo + subtotal)%MOD;
    }
    cout<<maximo<<endl;
    return 0;
}
