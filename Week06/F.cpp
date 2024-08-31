#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second
#define pb push_back
#define dbg(x) cout << #x << " = " << x << endl
#define FOR(i, a, n) for(int i = a; i < n; i++)

typedef unsigned long long ll;

int n;
int caminho[200001];
int caminhofinal[200001];

vector<vector<int>> grafo(200001);


int dfs(int no){
    if (no == n) return 1;
    if (caminho[no] != -1) return caminho[no];
    int atual = -2;
    for (auto el: grafo[no]){
        int tam = dfs(el);
        atual = max(tam, atual);
        if (atual == tam) caminhofinal[no] = el;
    }
    if(atual == -2) return caminho[no] = -2;
    atual++;
    return caminho[no] = atual;
}
void solve(){
    FOR(i,0,200001) caminho[i] = -1;
    dfs(1);
    if (caminho[1] == -2){
        cout<<"IMPOSSIBLE";
        return;
    }
    cout<<caminho[1]<<endl;
    int no = 1;
    while(no != n){
        cout<<no<<' ';
        no = caminhofinal[no];
    }
    cout<<n<<endl;
    
}

int main(){ _
    cout<<fixed;
    int m; 
    cin>>n>>m;
    int beg = 0;
    int fim = 0;
    int a, b;
    
    FOR(i,0,m){
        cin>>a>>b;
        grafo[a].pb(b);

        if(a == 1) beg++;
        if(b == n) fim++;
    }

    if(beg == 0 || fim == 0){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    solve();
    //grafo[200000].pb(1);
    //dbg(caminhoatual[74999]);
    return 0;
}
