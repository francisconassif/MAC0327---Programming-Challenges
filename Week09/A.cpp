#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define FOR(i, a, n) for(ll i = a; i < n; i++)

typedef long long ll;

vector<ll> pai,esquerda,direita;
//vector<bool> vis;
string dir;
ll t, n;
ll ans = 0;
//vector<ll> minimo;
set<ll> folhas;

ll solve(ll no){
    if(folhas.find(no)!=folhas.end()) return 0;
    if(no == 0) return 300001;
    ll prox;
    ll alt;
    ll caminho1;
    ll caminho2;
    //ll ret;
    if(dir[no-1] == 'R'){
        prox = direita[no];
        alt = esquerda[no];
        caminho1 = solve(prox);
        caminho2 = 1+solve(alt);
        return min(caminho1,caminho2);
    }
    else if(dir[no-1] == 'L'){
        prox = esquerda[no];
        alt = direita[no];
        caminho1 = solve(prox);
        caminho2 = 1+solve(alt);
        return min(caminho1,caminho2);
    }
    else{
        prox = esquerda[no];
        alt = direita[no];
        caminho1 = solve(prox);
        caminho2 = solve(alt);
        return 1+min(caminho1,caminho2);
    }

}

int main(){ _
    cin>>t;
    while(t--){
        cin>>n;
        cin>>dir;
        ans = 0;
        pai.resize(n+1,0);
        esquerda.resize(n+1,0);
        direita.resize(n+1,0);
        //minimo.resize(n+1,INF);
        FOR(i,1,n+1){
            cin>>esquerda[i]>>direita[i];
            pai[esquerda[i]]=i;
            pai[direita[i]]=i;
            if(esquerda[i]==direita[i]) folhas.insert(i);
        }
        pai[0]=0;
        esquerda[0]=0;
        direita[0]=0;
        pai[1]=0;
        ans = solve(1);
        folhas.clear();
        pai.clear();
        direita.clear();
        esquerda.clear();
        //minimo.clear();
        cout<<ans<<endl;
    }

    return 0;
}
