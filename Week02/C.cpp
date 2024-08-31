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

bool verifica(map<ll,ll> &qtd, vector<ll> &b, ll n){
    FOR(i,0,n){
        if(qtd[b[i]] > 1){
            return false;
        }
    }
    return true;
}

int main(){ 
    cout<<fixed;
    ll n; 
    cin >> n;
    vector<ll> b(n);
    map<ll,ll> qtd;

    for (ll i = 0; i < n; ++i) {
        qtd[b[i]] = 0;
    }

    FOR(i,0,n){
        cin >> b[i];
        qtd[b[i]]++;
    }

    ll lo = 0;
    ll hi = 0;
    ll comprimento = n;
    while(hi <= n){
        bool valido = verifica(qtd, b, n);
        if (valido){
            qtd[b[lo]]++;
            lo++;
            if (comprimento > (hi-lo+1)) comprimento = hi-lo+1;
        }
        else{
            qtd[b[hi]]--;
            hi++;
        }
    }
    if (comprimento > (hi-lo+1)) comprimento = hi-lo+1;

    cout << comprimento << endl;


    return 0;
}
