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

const ll INF = 0x3f3f3f3f;
const ll MAXN = 100001;
const ll MAXM = 200001;

ll n,m;
vector<ll> pai;
vector<ll> tam;
vector<tll> estradas;
ll comp;
ll total;

ll find(ll x){
    if (x != pai[x]){
        pai[x]=find(pai[x]);
    }
    return pai[x];
}

void une(ll paia, ll paib){
    if(tam[paia] > tam[paib]) pai[paib] = paia;
    else if(tam[paib] > tam[paia]) pai[paia] = paib;
    else{
        pai[paib] = paia;
        tam[paia]++;
    }
    return;
}

void solve(){
    ll paia, paib;
    for(auto &estrada: estradas){
        paia = find(get<0>(estrada));
        paib = find(get<1>(estrada));
        if(paia != paib){
            une(paia, paib);
            total += get<2>(estrada);
            comp++;
            if(comp == n-1) break;
        }
    }
    if(comp < n-1){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    cout<<total<<endl;

}

int main(){ _
    cout<<fixed;
    cin>>n>>m;
    estradas.resize(m);
    ll a,b,c;
    FOR(i,0,m){
        cin>>a>>b>>c;
        a--; b--;
        estradas[i] = {a,b,c};
    }
    sort(estradas.begin(), estradas.end(), [](const auto& tp1, const auto& tp2) {
        return get<2>(tp1) < get<2>(tp2);
    });
    pai.resize(n);
    FOR(i,0,n) pai[i]=i;
    tam.resize(n,0);
    total = 0;
    comp = 0;
    
    solve();
    return 0;
}
