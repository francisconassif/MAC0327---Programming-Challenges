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

int n;
vector<vector<int>> grafo(100001);
int times[100001];

bool part(int i, int timepai, int timefilho){
    times[i]=timepai;
    for(auto j : grafo[i]){
        bool solvable = true;
        if(times[j] == timepai) return false;
        if(times[j] == -1) solvable = part(j,timefilho,timepai);
        if (!solvable) return false;
    }
    return true;
}

void solve(){
    bool solvable = true;
    FOR(i,1,n+1) times[i] = -1;
    FOR(i,1,n+1){
        if(times[i] == -1) solvable = part(i,1,2);
        if (!solvable) break;
    }
    if (!solvable){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    FOR(i,1,n+1) cout<<times[i]<<' ';
    cout<<endl;
    return;
}

int main(){ _
    int m;
    cin>>n>>m;
    int a, b;
    while(m--){
        cin>>a>>b;
        grafo[a].pb(b);
        grafo[b].pb(a);
    }
    solve();

    return 0;
}
