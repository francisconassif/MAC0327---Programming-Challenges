#include <bits/stdc++.h>
#include <sstream>

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

char a[3];
char t[3];
int resp = 0;
stringstream resposta;

void solve(int dh, int dv){
    resp = max(abs(dh),abs(dv));
    FOR(i,0,resp){
        if(dh<0){
            resposta<<"R";
            dh++;
        }
        else if(dh>0){
            resposta<<"L";
            dh--;
        }
        if(dv==0 && dh==0) resposta<<'\n';
        if(dv<0){
            resposta<<"U\n";
            dv++;
        }
        else if(dv>0){
            resposta<<"D\n";
            dv--;
        }
        else if(dh!=0) resposta<<"\n";
    }
    //resposta<<'\n';
}

int main(){ 
    cin>>a>>t;
    int hs = a[0]-'a';
    int vs = a[1]-'0';
    int ht = t[0]-'a';
    int vt = t[1]-'0';
    int dh = hs - ht;
    int dv = vs - vt;
    solve(dh,dv);
    //dbg(dh);
    //dbg(dv);
    string x = resposta.str();
    //resp = max(dv,dh);
    //int tam = x.size();
    cout<<resp<<endl;
    //FOR(i,0,tam-1){
      //  cout<<x[i];
    //}
    cout<<x;
    return 0;
}
