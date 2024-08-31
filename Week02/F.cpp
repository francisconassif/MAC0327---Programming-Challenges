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
    ll n,q;cin>>n>>q;
    cout<<fixed;
    vector<ll> a(n);
    vector<ll> qtd(n+1,0);
    vector<ll> l(q);
    vector<ll> r(q);
    FOR(i,0,n) cin>>a[i];
    sort(a.begin(),a.end());
    ll soma=0;
    FOR(i,0,q) cin>>l[i]>>r[i];
    FOR(i,0,q){
        qtd[l[i]-1]++; qtd[r[i]]--;
        //dbg(qtd[l[i]]);
        //dbg(qtd[r[i]]);
    }
    FOR(i,1,n) qtd[i]+=qtd[i-1];
    sort(qtd.begin(),qtd.end()-1);
    FOR(i,0,n) soma+=qtd[i]*a[i];
    cout<<soma<<endl;
    return 0;
}
