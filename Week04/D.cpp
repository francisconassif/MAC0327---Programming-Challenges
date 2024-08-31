#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second
#define pb push_back
#define dbg(x) cout << #x << " = " << x << endl
#define FOR(i, a, n) for(int i = a; i < n; i++)

typedef long long ll;

void solve(int v, vector<int> & a, vector<pair<int,int>> & maximo){
    int soma=0;
    int temp=0;
    FOR(i,1,v+1){
        FOR(j,1,10){
            soma = i - a[j];
            if(soma>=0){
                temp = 1 + maximo[soma].f;
                if(temp>=maximo[i].f){
                    maximo[i].f = temp;
                    maximo[i].s = j;
                    //dbg(maximo[i].f);
                    //dbg(maximo[i].s);
                }
            }
        }
    }
    vector<int> resp;
    int maior = maximo[v].f;
    //dbg(maior);
    FOR(i, 0, maior){
        temp = v - a[maximo[v].s];
        resp.pb(maximo[v].s);
        //dbg(maximo[v].s);
        v = temp;
        //dbg(v);
    }
    sort(resp.begin(),resp.end());
    int tam = resp.size();
    FOR(i, 0, tam) cout<<resp[tam-i-1];
    cout<<endl;
    return;

}

int main(){ _
    int v; cin>>v;
    bool testa_entrada = false;
    vector<int> a(10,0);
    FOR(i,1,10){
        cin>>a[i];
        if (a[i] <= v) testa_entrada = true;
        //dbg(a[i]);
    }
    //dbg(a[5]);
    if (!testa_entrada){
        cout<<"-1"<<endl;
        return 0;
    }
    else{
        vector<pair<int,int>> maximo(v+1, {0, 0});
        solve(v, a, maximo);
    }
    return 0;
}
