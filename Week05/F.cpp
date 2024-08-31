#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define dbg(x) cout << #x << " = " << x << endl
#define FOR(j, x, k) for(ll j = x; j < k; i++)

typedef unsigned long long ll;

const int INF = 0x3f3f3f3f;
const ll mod = 1000000007;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll exp(ll a, ll b){
	if(b == 0) return 1;
	ll tmp = exp(a, b/2)%mod;
	tmp = (tmp%mod)*(tmp%mod);
	if(b%2 == 1){
		tmp = ((tmp%mod)*(a%mod))%mod;
	}
	return tmp%mod;
}

ll inv_mod(int a){
    return exp(a, mod-2);
}

ll denominador_mod(vector<ll>&qtd){
    ll resposta=1;
    for(ll i : qtd){
        if (i==0)continue;
        while(i>0){
            resposta=((resposta%mod)*(i%mod))%mod;
            i--;
        }
    }
    return resposta%mod;
}

ll fatorialmod(ll x){
    ll resposta = 1;
    ll a = x;
    while(a>0){
        resposta = ((resposta%mod)*(a%mod));
        a--;
    }
    return resposta%mod;
}


int main(){ _
    string t; cin>>t;
    //int a = 1;
    //cout<<a<<endl;
    vector<ll> qtd(26,0);
    ll tam = t.size();
    for(char c : t){
        qtd[c-'a']++;
    }
    ll d = denominador_mod(qtd);
    //dbg(d);
    ll e = inv_mod(d);
    //dbg(e);
    ll n = fatorialmod(tam);
    //dbg(n);
    ll ans = (e*n)%mod;

    cout<<ans<<endl;
    return 0;
}
