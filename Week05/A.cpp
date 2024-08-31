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

ll maximo(ll c){
    if (c==0) return 0;
    if (c==1) return 1;
    if (c%2 == 0){
        return (c/2)*(c+1);
    }
    return ((c+1)/2)*c;
}


ll solve(set<ll> &a, ll c){
    ll maxi = maximo(c+1);
    ll somas = 0;
    ll subs = 0;
    ll repetidos=0;
    ll pares = 0;
    ll impares = 0;
    ll agregado = 0;
    for(auto elem : a){
        repetidos = 1;
        if (elem%2 == 0){
            repetidos+=pares;
            pares++;
        }
        else{
            repetidos+=impares;
            impares++;
        }
        //for (auto elem2 : a){
            //if (elem == elem2) break;
            //if ((elem > elem2 && (elem - elem2)%2 == 0)) repetidos++;
        //}
        agregado+=repetidos;
        somas += elem/2 + 1;
        subs += c - elem+1;
    }
    if(maxi>somas){
        maxi-=somas;
        maxi+=agregado;
        maxi-=subs;
    }
    else if (maxi>subs){
        maxi-=subs;
        maxi+=agregado;
        maxi-=somas;
    }
    else{
        maxi+=agregado;
        maxi-=somas;
        maxi-=subs;
    }
    return maxi;
}

int main(){ _
    int t; cin>>t;
    ll n=0, c=0;
    ll elem=0;
    ll resposta=0;
    while(t>0){
        cin>>n>>c;
        set<ll> a;
        FOR(i,0,n){
            cin>>elem;
            a.insert(elem);
        }
        resposta = solve(a,c);
        t--;
        cout<<resposta<<endl;
    }
    
    return 0;
}
