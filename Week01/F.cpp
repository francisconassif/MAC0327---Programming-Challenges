#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define dbg(x) cout << #x << " = " << x << endl
#define FOR(i, a, n) for(long long i = a; i < n; i++)

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


int main(){ _
    cout<<fixed;
    ll n,m,k;cin>>n>>m>>k;
    ll max=n*m;
    ll min=1;
    ll med,qtd;
    while(min<=max){
        med = min+(max-min)/2;
        qtd = 0;
        FOR(i,1,n+1){
            if(m >= med/i){
                qtd+=med/i;
            }
            else{
                qtd+=m;
            }
        }
        if(qtd>=k){
            max=med-1;
        }
        else{
            min=med+1;
        }
    }
    cout<<min<<endl;
    return 0;
}
