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




void solve(){

}

int main(){ _
    int t; cin>>t;
    while(t--){
        int xmin, ymin, xmax, ymax;
        xmin = 1001;
        ymin = 1001;
        xmax = -1001;
        ymax = -1001;

        int n; cin>>n;
        FOR(i,0,n){
            char tipo;
            cin>>tipo;
            if(tipo == 'p'){
                int x0, yo;
                cin>>x0>>yo;
                xmin = min(xmin,x0);
                ymin = min(ymin,yo);
                xmax = max(xmax, x0);
                ymax = max(ymax, yo);
            }
            else if(tipo == 'c'){
                int x0,yo,r;
                cin>>x0>>yo>>r;
                xmin = min(xmin, x0-r);
                xmax = max(xmax, x0+r);
                ymin = min(ymin, yo-r);
                ymax = max(ymax, yo+r);
            }  
            else{
                int x1, yi, x2, y2;
                cin>>x1>>yi>>x2>>y2;
                xmin = min(xmin,min(x1,x2));
                ymin = min(ymin,min(yi,y2));
                xmax = max(xmax, max(x1,x2));
                ymax = max(ymax, max(yi,y2));
            }
        }
        cout<<xmin<<' '<<ymin<<' '<<xmax<<' '<<ymax<<'\n';
    }

    return 0;
}
