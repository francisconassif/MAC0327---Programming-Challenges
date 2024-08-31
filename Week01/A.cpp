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



int buscabinaria(vector<int>& x, int m, int n){
    int a = 0;
    int b = n-1;
    int index;
    int resposta=-1;
    while (a<=b){
        index=(a+b)/2;
        if(x[index]<=m){
            resposta=index;
            a=index+1;
        } 
        else{
            b=index-1;
        }
    }
    resposta++;
    return resposta;
}

int main(){ _
    int n;cin>>n;
    vector<int>x(n);
    FOR(i,0,n){
        cin>>x[i];
    }
    int q;cin>>q;
    sort(x.begin(),x.end());
    vector<int>m(q);
    FOR(i,0,q){
        cin>>m[i];
    }
    int r;
    FOR(i,0,q){
        r = buscabinaria(x,m[i],n);
        cout<<r<<endl;
    }
    return 0;
}
