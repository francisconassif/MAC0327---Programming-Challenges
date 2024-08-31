#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dbg(x) cout << #x << " = " << x << endl
#define FOR(i, a, n) for(int i = a; i < n; i++)

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;



int tamanho(string sa){
    map<char,int> count;
    int resp = INF;
    int lo = 0;
    int caracteres = 0;
    int n = sa.length();
    FOR(i,0,n){
        if (count[sa[i]]==0) caracteres++;
        count[sa[i]]++;
        if (caracteres==3){
            while (count[sa[lo]] > 1){
                count[sa[lo]]--;
                lo++;
            }
            int tam = i-lo+1;
            //dbg(lo);
            //dbg(i);
            if (tam < resp){
                resp = tam;
            }
        }
    }
    if (caracteres<3) return 0;
    return resp;
}

int main(){ _
    int t; cin>>t;
    int resp;
    FOR(i,0,t){
        string a; cin>>a;
        resp = tamanho(a);
        cout<<resp<<endl;
    }
    return 0;
}
