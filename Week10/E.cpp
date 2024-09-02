#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define dbg(x) cout << #x << " = " << x << endl
#define FOR(i, a, n) for(ll i = a; i < n; i++)
#define ROR(i,n,a) for(ll i = n; i > a; i--)

typedef int ll;

const int INF = 0x3f3f3f3f;
const ll MAXN = 200001;
const ll MAXLOG = 18; 
//const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll n,q;
ll sobe[MAXN][MAXLOG];
vector<ll> pai;


ll exp(ll base, ll exp){
    ll res = 1;  
    while (exp > 0){
        if (exp%2 == 1){  
            res = res*base;
        }
        base = base*base;  
        exp = exp/2;       
    }
    return res; 
}


void preenche(){
    FOR(i,2,n+1){
        sobe[i][0]=pai[i];
    }
    FOR(i,1,MAXLOG){
        FOR(j,1,n+1){
            if(sobe[j][i-1]!=-1){
                sobe[j][i]=sobe[sobe[j][i-1]][i-1];
            }
            else sobe[j][i] = -1;
        }
    }
}

ll solve(ll x, ll k){
    ROR(i,MAXLOG-1,-1){
        if(k>=exp(2,i)){
            x = sobe[x][i];
            k-=exp(2,i);
            if(x==-1)break;
        }
    }
    return x;
    
}

int main(){ _
    cin>>n>>q;
    pai.resize(n+1,-1);
    FOR(i,2,n+1) cin>>pai[i];
    preenche();
    ll x, k, ans;
    FOR(i,0,q){
        cin>>x>>k;
        ans = solve(x,k);
        if(ans == 0) ans--;
        cout<<ans<<'\n';
    }
    return 0;
}
