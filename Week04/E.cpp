#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dbg(x) cout << #x << " = " << x << endl
#define FOR(i, a, n) for(ll i = a; i < n; i++)

typedef unsigned long long ll;

const ll mod = 1000000007;


ll conta(vector<string> & matriz, ll n){
    if (matriz[0][0] == '*' || matriz[n-1][n-1] == '*') return 0;
    vector<vector<ll>> resp(n, vector<ll>(n, 0));
    resp[0][0]=1;
    FOR(i,1,n) if(matriz[i][0] == '.') resp[i][0] = resp[i-1][0]%mod;
    FOR(i,1,n) if(matriz[0][i] == '.') resp[0][i] = resp[0][i-1]%mod;
    FOR(i,1,n) FOR(j,1,n) if (matriz[i][j] == '.') resp[i][j] = resp[i-1][j]%mod+resp[i][j-1]%mod;
    //FOR(i,0,n) FOR(j,0,n) dbg(resp[i][j]);
    return resp[n-1][n-1]%mod;
}

int main(){ _
    cout<<fixed;
    ll n; cin>>n;
    vector<string> matriz(n,"");
    FOR(i,0,n){
        cin>>matriz[i];
    }
    //FOR(i,0,n) dbg(matriz[i]);
    ll resposta = conta(matriz,n)%mod;
    cout<<resposta<<endl;
    return 0;
}
