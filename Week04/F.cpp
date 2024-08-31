#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define FOR(i, a, n) for(ll i = a; i < n; i++)

typedef long long ll;

ll conta(ll a, ll b, ll c, ll n){
    ll mini = min(a,b);
    mini = min(mini,c);
    if (n%mini == 0) return n/mini;
    ll maxi = 0;
    if (n%a == 0) maxi = max(maxi, n/a);
    //dbg(maxi);
    if (n%b == 0) maxi = max(maxi, n/b);
    //dbg(maxi);
    if (n%c == 0) maxi = max(maxi, n/c);
    //dbg(maxi);
    if (n == 0 || a == 1 || b == 1 || c == 1) return n;
    FOR(i,0,n/a+1){
        FOR(j,0,n/b+1){
            ll soma = i*a + j*b;
            if (soma == n){
                maxi = max(maxi, i+j);
                //dbg(maxi);
            }
            else if (soma < n && (n-soma)%c == 0){
                maxi = max(maxi, i+j+(n-soma)/c);
                //dbg(maxi);
            }
            else if(soma > n) break;
        }
    }
    return maxi;
}

int main(){ _
    cout<<fixed;
    ll n,a,b,c;
    cin>>n>>a>>b>>c;
    ll total = conta(a,b,c,n);
    cout<<total<<endl;
    return 0;
}
