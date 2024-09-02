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
const ll MAXN = 200001;
ll n, a, b;

set<ll> comeco;
set<ll> fim;
set<ll> todos;

void solve(){

}

int main(){ _
    cin>>n;
    FOR(i, 0, n){
        cin>>a>>b;
        comeco.insert(a);
        fim.insert(b);
        todos.insert(a);
        todos.insert(b);
    }
    ll maior = 0;
    ll curr = 0;
    for(auto el: todos){
        if(comeco.find(el)!=comeco.end()){
            curr++;
        }
        if(fim.find(el)!=fim.end()){
            curr--;
        }
        maior = max(maior,curr);
    }
    cout<<maior<<endl;

    return 0;
}
