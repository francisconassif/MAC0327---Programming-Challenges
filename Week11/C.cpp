#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define dbg(x) cout << #x << " = " << x << endl
#define FOR(i, a, n) for(int i = a; i < n; i++)

typedef long double ld;
typedef long long ll;
typedef pair<ll,ll> ponto;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<ponto> pontos;

int main(){ _
    int n; cin>>n;
    ll x, y;
    pontos.resize(n);
    FOR(i,0,n){
        cin>>x>>y;
        pontos[i] = {x,y};
    }
    ponto O = pontos[0];
    ponto A = pontos[n-1];
    ll ar = 0;
    FOR(i,0,n-1){
        ponto B = pontos[i];
        ponto C = pontos[i+1];
        ar += B.f * C.s - B.s * C.f;
    }
    ar += A.f * O.s - A.s * O.f;
    ar = abs(ar); 
    cout<<fixed;
    cout<<ar<<'\n';
    return 0;
}
