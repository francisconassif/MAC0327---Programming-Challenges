#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define dbg(x) cout << #x << " = " << x << endl
#define FOR(i, a, n) for(unsigned long long i = a; i < n; i++)

typedef unsigned long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll factorial(ll n){
    ll fac = 1;
    FOR(i,2,n+1) fac*=i;
    return fac;
}

ll bin2(ll n){
    ll bin = n*(n-1);
    bin = bin/2;
    return bin;
}

int main(){ _
    int t; cin>>t;
    FOR(i,0,t){
        ll n;cin>>n;
        vector<ll> h(n);
        ll soma = 0;
        FOR(j,0,n){
            cin>>h[j];
            soma+=h[j];
        }
        sort(h.begin(),h.end());
        ll count = 1;
        vector<pair<ll,ll>> pares;
        FOR(k,1,n){
            if(h[k]==h[k-1]) count++;
            else{
                pares.pb(make_pair(h[k-1],count));
                count = 1;
            }
        }
        pares.pb(make_pair(h[n-1], count));

        ll p = 0;
        ll q = pares.size()-1;
        ll r = 0;

        while(p<q){
            if(2*soma==n*(pares[p].f+pares[q].f)){
                r += pares[p].s*pares[q].s;
                p++;
                q--;
            }
            else if (2*soma>n*(pares[p].f+pares[q].f)) p++;
            else q--;
        }
        if((soma==n*(pares[q].f)))r += bin2(pares[p].s);
        cout<<r<<endl;



    }

    return 0;
}
