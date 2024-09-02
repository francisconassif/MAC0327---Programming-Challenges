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

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ll MOD = 998244353;

ll n, k;
map<ll, pair<ll, ll>> eventos;
map<ll, ll> inv;
vector<ll> fat(1000001), ifat(1000001);

ll inv_mod(ll a, ll m){
    if(inv.find(a) != inv.end()) return inv[a];
    ll m0 = m, t, q;
    ll x0 = 0, x1 = 1, ori = a;
    while (a > 1){
        q = a / m;
        t = m; m = a % m; a = t;
        t = x0; x0 = x1 - q * x0; x1 = t;
    }
    if (x1 < 0) x1 += m0;
    return inv[ori] = x1;
}

void precomputa(){
    fat[0] = 1;
    FOR(i,1,1000001){
        fat[i] = (fat[i-1] * i) % MOD;
    }
    ifat[1000000] = inv_mod(fat[1000000], MOD);
    ROR(i,999999,-1){
        ifat[i] = (ifat[i+1] * (i+1)) % MOD;
    }
}

ll binomial(ll n, ll k){
    if (k > n) return 0;
    return (fat[n] * ifat[k] % MOD) * ifat[n-k] % MOD;
}

int main(){ _
    precomputa();
    cin>>n>>k;
    ll l, r;
    FOR(i, 0, n){
        cin >> l >> r;
        eventos[l].f++;
        eventos[r].s++;
    }
    ll curr = 0;
    ll poss = 0;
    ll prev = 0;
    for(auto &el : eventos){
        prev = curr;
        curr += el.s.f;
        if (prev >= k) 
            poss = (poss + binomial(curr, k) - binomial(prev, k) + MOD) % MOD;
        else if (curr >= k) 
            poss = (poss + binomial(curr, k)) % MOD;
        curr -= el.s.s;
    }
    cout<<poss<<'\n';
    return 0;
}
