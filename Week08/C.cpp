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

ll n;
vector<ll> pai;
//vector<ll> tam;
vector<pll> estradas;
vector<pll> inuteis;
//ll comp;
//ll maxtam;

ll find(ll x){
    if (x != pai[x]){
        pai[x]=find(pai[x]);
    }
    return pai[x];
}

void une(ll paia, ll paib){
    if(paia == paib) return;
    pai[paib] = paia;
    return;
}

void solve(){
    ll tam = inuteis.size();
    cout<<tam<<endl;
    if(tam==0) return;
    ll paii, paiv;
    for(auto &inu : inuteis){
        cout<<inu.f<<' '<<inu.s<<' ';
        paii = find(inu.f);
        FOR(v,1,n+1){
            paiv = find(v);
            if(v == inu.f) continue;
            if(paii == paiv) continue;
            une(paii, paiv);
            cout<<inu.f<<' '<<v<<endl;
            break;
        }
    }

}

int main(){ _
    cin>>n;
    ll paia, paib;
    ll a,b;
    estradas.resize(n-1);
    pai.resize(n+1);
    FOR(i,0,n+1) pai[i]=i;
    FOR(i,0,n-1){
        cin>>a>>b;
        estradas[i].f = a;
        estradas[i].s = b;
        paia = find(a);
        paib = find(b);
        if(paia == paib) inuteis.pb({a,b});
        else une(paia, paib);
    }
    solve();
    return 0;
}
