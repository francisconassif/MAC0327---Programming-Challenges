#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dbg(x) cout << #x << " = " << x << endl
#define FOR(i, a, n) for(int i = a; i < n; i++)

char matriz[1001][1001];
vector<vector<int>> visita(1001, vector<int>(1001));
int m,n;

void buraco(int i, int j){
    if(0 <= i && i < n){
        if(0 <= j && j < m){
            if(matriz[i][j] == '.' && visita[i][j]==0){
                visita[i][j] = 1;
                buraco(i-1,j);
                buraco(i+1,j);
                buraco(i,j-1);
                buraco(i,j+1);

            }
        }
    }

}

int main(){ _
    cin>>n>>m;
    FOR(i,0,n) FOR(j,0,m) cin>>matriz[i][j];
    int count = 0;
    FOR(i,0,n) FOR(j,0,m){
        if(visita[i][j]==0 && matriz[i][j] == '.'){
            count++;
            buraco(i,j);
        }
        visita[i][j]=1;
    }
    cout<<count<<endl;
    return 0;
}
