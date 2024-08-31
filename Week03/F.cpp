#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dbg(x) cout << #x << " = " << x << endl
#define FOR(i, a, n) for(ll i = a; i < n; i++)

typedef unsigned long long ll;

int mdc(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
bool potencia2(ll n) {
    return (n & (n - 1)) == 0;
}

int main(){ _
    cout<<fixed;
    ll t,m,n; cin>>t;
    ll resto;
    ll r;
    ll denominador;
    FOR(i,0,t){
        cin>>m>>n;
        ll soma = 0;
        resto = m%n;
        r = resto;
        long long ans=0;
        denominador = n/mdc(n,m);
        //dbg(n);
        //dbg(m);
        //dbg(mdc(n,m));
        //dbg(denominador);
        if (!potencia2(denominador)){
            r = 0;
            ans = -1;
        }
        while (r != 0){
            soma += r;
            r = r*2;
            r = r%n;
            if (r == resto){
                ans = -1;
                break;
            }
        }
        if (ans==0) cout<<soma<<endl;
        else cout<<ans<<endl;
        
    }
    return 0;
}
