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
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){
    ll m;cin>>m;
    ll k = 0;
    ll zeros = 0;
    ll pot5 = 1;
    while (zeros < m){
        k+=5;
        ll pot = 5;
        zeros = 0;
        while (k/pot >= 1){
            zeros += k/pot;
            
            
            pot*=5;
        }
        //dbg(k);
        //dbg(zeros);
    }
    if(zeros == m){
        cout<<5<<endl;
        cout<<k<<' '<<k+1<<' '<<k+2<<' '<<k+3<<' '<<k+4<<endl;
    }
    else
        cout << 0 << endl;
    return 0;
}
