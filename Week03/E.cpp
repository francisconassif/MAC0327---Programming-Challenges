#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dbg(x) cout << #x << " = " << x << endl
#define FOR(i, a, n) for(ll i = a; i < n; i++)

typedef unsigned long long ll;

int main(){ _
    cout<<fixed;
    ll n, k; cin>>n>>k;
    set<ll> a;
    ll ai;
    FOR(i,0,n){
        cin>>ai;
        a.insert(ai);
    }
    if (k == 1){
        cout << n << endl;
        return 0;
    }
    ll ans = 0;
    for(auto ai : a){
        ll prod = ai*k;
        auto elem = a.find(prod);
        if (elem != a.end()) a.erase(elem);
    }
    cout<<a.size()<<endl;
    return 0;
}
