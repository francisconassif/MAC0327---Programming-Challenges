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

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ll mod = 1000000007;

ll factorialmod(ll a, vector<ll> &fatoriais){
    if (a < 2) return 1;
    if(fatoriais[a]!=0) return fatoriais[a];
    fatoriais[a] = (a*(factorialmod(a-1, fatoriais)))%mod;
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

ll comb(ll a, ll b, vector<ll> &fatoriais){
    if (a<b) return 0;
    if (a == b) return 1;
    if(a-b == 1) return a;
    if (b == 1) return a;
    ll n = factorialmod(a, fatoriais);
    ll d1 = inv_mod(factorialmod(b, fatoriais));
    ll d2 = inv_mod(factorialmod(a-b,fatoriais));
    ll df = (d1*d2)%mod;
    n = (n*df)%mod;
    return n;
}



bool ehbom(ll x, ll a, ll b){
    ll p = x;
    ll dig = a;
    while (p>9){
        dig = p%10;
        if (dig != a && dig != b) return false;
        p /=10;
    }
    if (p == a || p == b) return true;
    return false;
}

int main(){ _
    cout<<fixed;
    ll a, b, n;
    cin>>a>>b>>n;
    ll x=0;
    ll soma=0;
    vector<ll>fatoriais(n+1, 0);
    fatoriais[0]=1;
    while(x<n+1){
        if(ehbom((a*x+b*(n-x))%mod, a, b)){
            //dbg((x*a)+((n-x)*b));
            //dbg(n);
            //dbg(b);
            //dbg(x);
            //dbg(comb(n,x,fatoriais));
            soma=(soma+comb(n, x, fatoriais))%mod;
        }
        x++;
    }
    cout<<soma<<endl;

    return 0;
}
