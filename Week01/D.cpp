#include <bits/stdc++.h>
#include <vector>

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
const ll LINF = 18446744073709551615;


ll verifica(ll med, ll  n, vector<ll> &k){ 
    ll qtd=0;
    FOR(i,0,n){
        qtd+=med/k[i];
    }
    return qtd;
}

int main(){ _
    cout<<fixed;
    ll n,t;cin>>n>>t;
    vector<ll> k(n);
    ll min=LINF;
    FOR(i,0,n){
        cin>>k[i];
        if(k[i]<min) min=k[i];
    } 
    ll menor = 1;
    ll max = min*t;
    ll med;
    ll resp;
    while (menor<=max){
        med = menor+(max-menor)/2;
        ll qtd = verifica(med, n, k);
        if(qtd>=t){
            max=med-1;
            resp=med;
        }
        else{
            menor=med+1;
        }
    }
    cout<<resp<<endl;
}
