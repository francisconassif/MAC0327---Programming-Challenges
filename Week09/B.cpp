#include <bits/stdc++.h>
#include <sstream>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define dbg(x) cout << #x << " = " << x << endl
#define FOR(i, a, n) for(ll i = a; i < n; i++)

typedef unsigned long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll n,m;
vector<vector<ll>> grafo;
vector<bool> vis;
vector<ll> pai;
ll comp;
ll nofinal = 0;


ll find(ll x){
    if (x != pai[x]){
        pai[x]=find(pai[x]);
    }
    return pai[x];
}

void une(ll paia, ll paib){
    pai[paia]=paib;
    comp--;
    return;
}

bool caminha(ll no, ll pai, vector<ll> &ans){
    //dbg(pai);
    //dbg(no);
    if(vis[no]){
        nofinal = no;
        return true;
    }
    //cout<<"here\n";
    vis[no]=true;
    if(grafo[no].size()==1) return false;
    ans.pb(no);
    ll tam = ans.size();
    for(auto filho: grafo[no]){
        bool caso = false;
        if (filho!=pai){
            if(vis[filho]){
                nofinal = filho;
                return true;
            }
            else{
                //cout<<"aqui\n";
                //dbg(no);
                caso = caminha(filho,no,ans);
                if(caso){
                    //nofinal = filho;
                    return true;
                }
                else if(tam<ans.size()) ans.resize(tam);
            }
        }
    }
    return false;
}

bool dfs(ll no){
    ll paino = find(no);
    //dbg(paino);
    //ll arestas = 0;
    if(vis[paino]) return false;
    vis[paino]=true;
    vector<ll> ans;
    bool poss;
    comp=n;
    ans.pb(paino);
    for(auto filho: grafo[paino]){
        poss = caminha(filho,paino,ans);
        if(poss){
            if(ans.size()<3){
                ans.clear();
                ans.pb(paino);
                continue;
            }
            stringstream ss;
            ll taman = 0;
            //cout<<ans.size()+1<<endl;
            //for(auto el: ans) cout<<el<<' ';
            //cout<<endl;
            ss<<nofinal<<' ';
            taman++;
            FOR(i,0,ans.size()){
                ss<<ans[ans.size()-1-i]<<' ';
                taman++;
                if(ans[ans.size()-1-i]==nofinal) break;
            }
            cout<<taman<<endl<<ss.str()<<endl;
            return true;
        }
        else{
            ans.clear();
            ans.pb(paino);
        }
    }
    ans.clear();
    return false;
}

int main(){ _
    cout<<fixed;
    cin>>n>>m;
    grafo.resize(n+1);
    vis.resize(n+1,false);
    pai.resize(n+1);
    iota(pai.begin(),pai.end(),0);
    ll a,b;
    ll paia, paib;
    FOR(i,0,m){
        cin>>a>>b;
        grafo[a].pb(b);
        grafo[b].pb(a);
        paia = find(a);
        paib = find(b);
        if(paia!=paib) une(paia,paib);
    }
    bool solved=false;
    FOR(i,1,n+1){
        //if(comp>n-2) break;
        //ll paii = find(i);
        if(vis[i]) continue;
        ll paii = find(i);
        solved = dfs(paii);
        if(solved) break;
    }
    if(!solved) cout<<"IMPOSSIBLE\n";

    return 0;
}
