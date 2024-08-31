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

int main(){ _
    int n, m, b, mod;
    cin >> n >> m >> b >> mod;
    vector<vector<int>> dp(m+1, vector<int>(b+1,0));
    dp[0][b] = 1;
    vector<int> a(n);
    FOR(i,0,n) cin >> a[i];
    FOR(i,0,n){
        FOR(j,1,m+1){
            FOR(k,0,b+1){
                if (k >= a[i]){
                    dp[j][k - a[i]] += dp[j - 1][k];
                    dp[j][k - a[i]] = dp[j][k - a[i]]%mod;
                }
            }
        }
    }
    int soma = 0;
    FOR(i, 0, b+1) soma = (soma+dp[m][i])%mod;
    cout << soma << endl;
    return 0;
}
