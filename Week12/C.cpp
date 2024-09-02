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

ll n, m;

multiset<ll> comeco;
multiset<ll> fim;
//multiset<ll> todos;
set<ll> resposta;


void solve(){

}

int main(){ _
    cin>>n>>m;
    ll r, l;
    FOR(i,0,n){
        cin>>r>>l;
        comeco.insert(r);
        fim.insert(l);
    }
    ll curr = 0;
    FOR(i, 1, m+1){
        curr+=comeco.count(i);
        if(curr < 1){
            resposta.insert(i);
        }
        curr-=fim.count(i);
    }
    cout<<resposta.size()<<'\n';
    for(auto el : resposta){
        cout<<el<<' ';
    }
    cout<<'\n';

    return 0;
}
