#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define FOR(i, a, n) for(int i = a; i < n; i++)

typedef long long ll;
const int MAX = 200001;
pair<int,int> pontos[MAX];
map<pair<int,int>,int> indices;
queue<pair<pair<int,int>,pair<int,int>>> q;
bool vis[MAX];
pair<int,int> ans[MAX];

int main() { _
    int n;
    cin>>n;

    FOR(i,1,n+1){
        cin>>pontos[i].f>>pontos[i].s;
        indices[pontos[i]]=i;
    }
    
    vector<pair<int,int>> dist_inicial = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    FOR(i,1,n+1){
        FOR(j,0,4){
            pair<int,int> p = {pontos[i].f+dist_inicial[j].f, pontos[i].s+dist_inicial[j].s};
            if(indices[p]==0){
                q.push({p,p});
                break;
            }
        }
    }

    while(!q.empty()){
        auto u = q.front();
        q.pop();
        FOR(i,0,4){
            pair<int,int> v = {u.f.f + dist_inicial[i].f, u.f.s + dist_inicial[i].s};
            int ind = indices[v];
            if(ind!=0 && !vis[ind]){
                vis[ind]=true;
                ans[ind]=u.s;
                q.push({v,u.s});
            }
        }
    }
    FOR(i,1,n+1) cout<<ans[i].f<<' '<<ans[i].s<<endl;
    return 0;
}
