#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define dbg(x) cout << #x << " = " << x << endl
#define FOR(i, a, n) for(int i = a; i < n; i++)

typedef unsigned long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    cout<<fixed;
    ll n,h;cin>>n>>h;
    ll inicio = 1;
    ll sol;
    ll chuva;
    ll total_sol=0;
    ll total_chuva=0;
    ll sol_ate_h=0;
    ll chuva_ate_h=0;
    vector<ll> sois;
    vector<ll> chuvas;
    ll hi = n-1;
    ll com, fim; cin>>com>>fim;
    sol = com - inicio;
    chuva = fim - com;
    sois.pb(sol);
    chuvas.pb(chuva);
    inicio = fim;
    total_chuva = chuva;
    chuva_ate_h = chuva;
    hi = 1;
    FOR(i,1,n){
        int com, fim; cin>>com>>fim;
        sol = com - inicio;
        chuva = fim - com;
        total_sol += sol;
        total_chuva += chuva;
        sois.pb(sol);
        chuvas.pb(chuva);
        inicio=fim;
        if (total_sol<h){
            sol_ate_h = total_sol;
            chuva_ate_h = total_chuva;
            hi = i+1;
            //dbg(hi);
        }
    }
    
    //chuva_ate_h+=chuvas[hi-1];
    //dbg(chuva_ate_h);
    ll tam = chuvas.size();
    //dbg(tam);
    ll lo = 1;
    ll max = chuva_ate_h+h;
    //dbg(max);
    while (hi<=tam-1 && lo<tam){
        //dbg(chuva_ate_h);
        //dbg(hi);
        //dbg(lo);
        //dbg(sol_ate_h);

        if (chuva_ate_h+h>max){
            max = chuva_ate_h+h;
            //dbg(max);
        }
        
        
        if (sol_ate_h + sois[hi] < h){
            //cout<<'a';
            chuva_ate_h += chuvas[hi];
            sol_ate_h += sois[hi];
            hi++;
        }
        else{
            chuva_ate_h -= chuvas[lo-1];
            sol_ate_h -= sois[lo];
            lo++;
        }
    }
    if (chuva_ate_h+h>max){
            max = chuva_ate_h+h;
            //dbg(max);
        }
    cout<<max<<endl;

    return 0;
}
