#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define FOR(i, a, n) for(ll i = a; i < n; i++)

typedef unsigned long long ll;

int main(){ _
    cout<<fixed;
    int t; cin>>t;
    ll n, x, y;
    while(t--){
        cin>>n>>x>>y;
        vector<ll> a(n);
        map<pair<ll,ll>,ll> ans;
        FOR(i,0,n){
            cin>>a[i];
            pair<ll,ll> par = {a[i]%x, a[i]%y};
            if(ans.find(par)==ans.end()) ans[par] = 1;
            else ans[par]++;
        }
        ll soma = 0;
        FOR(i, 0, n){
            pair<ll,ll> par = {a[i]%x, a[i]%y};
            pair<ll,ll> impar = {(x-a[i]%x)%x, a[i]%y};
            if (par == impar && ans[par]!=-1){
                if(ans[par]>1) soma+=(ans[par]*(ans[par]-1))/2;
                ans[par]=-1;
            }
            if(ans[par]!=-1){
                if(ans.find(impar)!=ans.end() && ans[impar]!=-1){
                    soma+=ans[par]*ans[impar];
                    ans[par]=-1;
                    ans[impar]=-1;
                }
                ans[par]=-1;
            }
        }
        //resp = solve(n,x,y,a);
        cout<<soma<<endl;
    }
    return 0;
}
