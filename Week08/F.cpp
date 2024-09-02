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
typedef tuple<ll,ll,ll> tll;


const ll INF = 0x3f3f3f3f;

ll n,r,t;
ll caso = 0;
vector<ll> pai;
vector<ll> tam;
vector<tll> voos;
//map<pll,ll> memo;

ll find(ll x){
    //if(x == 0);
    if (x != pai[x]){
        pai[x]=find(pai[x]);
    }
    return pai[x];
}

void une(ll a, ll b){
    ll paia = find(a);
    ll paib = find(b);
    if(paia == paib) return;
    if(tam[paia] > tam[paib]) pai[paib]=paia;
    else if(tam[paib] > tam[paia]) pai[paia] = paib;
    else{
        pai[paib]=paia;
        tam[paia]++;
    }
    return;
}

void possivel(ll limite){
    iota(pai.begin(),pai.end(),0);
    fill(tam.begin(),tam.end(),1);
    if(limite == 0) return;
    for(auto &[a,b,l]: voos){
        if(l > limite) return;
        une(a-1,b-1);
    }
    return;
}

void solve(vector<pll> &cons){
    caso++;
    cout<<"Case "<<caso<<endl;
    sort(voos.begin(), voos.end(), [](tll& t1, tll& t2){
        return get<2>(t1) < get<2>(t2);
    });
    for(pll co: cons){
        //if(memo.find(co)!=memo.end()){
            //cout<<memo[co]<<endl;
            //continue;
        //}
        ll lo = 0;
        ll hi = r-1;
        ll ans = get<2>(voos[hi]);
        //dbg(ans);
        ll med = 1;
        while(lo<=hi){
            med = (lo+hi)/2;
            //dbg(med);
            possivel(get<2>(voos[med]));
            if(find(co.f-1) == find(co.s-1)){
                ans = get<2>(voos[med]);
                if(med == 0) break;
                hi = med-1;
            }
            else{
                lo = med+1;
            }
        }
        //memo[co] = ans;
        cout<<ans<<endl;
    }


}

int main(){ _
    cin>>t;
    ll a,b,l,q;
    FOR(i,1,t+1){
        //memo.clear();
        voos.clear();
        tam.clear();
        pai.clear();
        cin>>n>>r;
        voos.resize(r);
        pai.resize(n);
        tam.resize(n,1);
        //FOR(j,0,n) pai[j]=j;
        FOR(j,0,r){
            cin>>a>>b>>l;
            voos[j] = {a,b,l};
        }
        cin>>q;
        vector<pll> cons(q);
        FOR(j,0,q) cin>>cons[j].f>>cons[j].s;
        solve(cons);
        cout<<endl;
        //cons.clear();
    }
    return 0;
}
