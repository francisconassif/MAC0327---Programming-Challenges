#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dbg(x) cout << #x << " = " << x << endl
#define FOR(i, a, n) for(int i = a; i < n; i++)

typedef long long ll;

const int INF = 0x3f3f3f3f;

int solve(int m, int n, vector<vector<int>> & matriz){
    if (m == n){
        matriz[m][n] = 0;
        return 0;
    }
    if (m == 1){
        matriz[m][n] = n-1;
        return matriz[m][n];
    }
    if (n == 1){
        matriz[m][n] = m-1;
        return matriz[m][n];
    }
    if (matriz[m][n] != -1) return matriz[m][n];
    int maximo = max(m,n);
    int minimo = min(m,n);
    if (maximo%minimo == 0){
        matriz[m][n] = maximo/minimo - 1;
        return matriz[m][n];
    } 
    int ans = INF;
    FOR(i,1,m/2 + 1) ans = min(ans, solve(i, n, matriz) + solve(m-i,n, matriz) + 1);
    FOR(i,1,n/2 + 1) ans = min(ans, solve(m, i, matriz) + solve(m,n-i, matriz) + 1);
    matriz[m][n] = ans;
    return matriz[m][n];
}

int main(){ _
    cout<<fixed;
    int m,n;
    cin>>m>>n;
    vector<vector<int>> matriz(m+1, vector<int>(n+1, -1));
    int ans = solve(m,n, matriz);
    cout<<ans<<endl;
    return 0;
}
