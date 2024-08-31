#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define dbg(x) cout << #x << " = " << x << endl
#define FOR(i, a, n) for(int i = a; i < n; i++)

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int mod = 998244353;



void solve(int n, int m, int k, vector<vector<ll>> &dp){
    dp[1][0]=m;
    FOR(i,2,n+1){
        FOR(j,0,k+1){
            dp[i][j]=dp[i-1][j]%mod;
            if(j!=0) dp[i][j] = (dp[i][j]%mod +((dp[i-1][j-1]%mod)*((m-1)%mod))%mod)%mod;
        }
    }
}

int main(){ _
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<ll>>dp(n+1,vector<ll>(k+1,0));
    solve(n,m,k,dp);
    cout<<dp[n][k]<<endl;
    return 0;
}
