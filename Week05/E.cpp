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

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ll mod = 1000000007;

ll factorialmod(int a, vector<ll> &fatoriais){
    if(fatoriais[a]!=0) return fatoriais[a];
    fatoriais[a] = (a*(factorialmod(a-1, fatoriais)))%mod;
    //dbg(a);
    //dbg(x);
    //dbg(fatoriais[a]);
    return fatoriais[a];
}

ll exp(ll a, ll b){
	if(b == 0) return 1;
	ll tmp = exp(a, b/2)%mod;
	tmp = (tmp%mod)*(tmp%mod);
	if(b%2 == 1){
		tmp = ((tmp%mod)*(a%mod))%mod;
	}
	return tmp%mod;
}

ll inv_mod(ll a){
    return exp(a, mod-2);
}

int main(){ _
    cout<<fixed;
    ll t; cin>>t;
    ll a, b;
    ll maxa = 0;
    vector<ll> fatorial(1,0);
    fatorial[0]=1;
    FOR(i,0,t){
        cin>>a>>b;
        if(a>maxa){
            maxa = a;
            fatorial.resize(a+1, 0);
        }
        ll n = factorialmod(a,fatorial);
        ll d = factorialmod(b, fatorial);
        ll d2 = factorialmod(a-b, fatorial);
        d = inv_mod(d);
        d2 = inv_mod(d2);
        ll df = (d*d2)%mod;
        ll resp = (n*df)%mod;
        cout<<resp<<endl;
    }


    return 0;
}
