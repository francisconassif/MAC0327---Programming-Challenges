#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define dbg(x) cout << #x << " = " << x << endl
#define FOR(i, a, n) for(ll i = a; i < n; i++)

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ll MINF = (-1)*LINF;


int main(){ _
    ll n; cin>>n;

    vector<ll> x1(n), y1(n), x2(n), y2(n);
    
    cin>>x1[0]>>y1[0]>>x2[0]>>y2[0];
    ll x1_max = x1[0];
    ll y1_max = y1[0];
    ll x2_min = x2[0];
    ll y2_min = y2[0];

    set<ll> possiveis;

    ll index = -1; 
    ll mud = 0;

    FOR(i,1,n){
        cin>>x1[i]>>y1[i]>>x2[i]>>y2[i];
        if(true){
            ll x1_max2 = max(x1_max, x1[i]);
            ll y1_max2 = max(y1_max, y1[i]);
            ll x2_min2 = min(x2_min, x2[i]);
            ll y2_min2 = min(y2_min, y2[i]);

            if(x1_max2<=x2_min2 && y1_max2<=y2_min2){
                x1_max = x1_max2;
                y1_max = y1_max2;
                x2_min = x2_min2;
                y2_min = y2_min2;
            }
            else{
                index = i;
                possiveis.insert(i);
                possiveis.insert(i-1);
                //dbg(index);

                mud++;
            }
        }
    }
    //dbg(mud);
    //dbg(index);
    if(mud > 1){
        index = 0;
        //cout<<x1_max<<' '<<y1_max<<'\n';
        //return 0;
    }
    x1_max = MINF;
    //dbg(index);
    //dbg(mud);
    y1_max = MINF;
    x2_min = LINF;
    y2_min = LINF;
    FOR(i,0,n){
        if (i == index) continue; 
        x1_max = max(x1_max, x1[i]);
        y1_max = max(y1_max, y1[i]);
        x2_min = min(x2_min, x2[i]);
        y2_min = min(y2_min, y2[i]);
    }
    ll guarda1 = x1_max;
    ll guarda2 = y1_max;
    bool solved = false;
    if(x1_max <= x2_min && y1_max <= y2_min){
        cout<<x1_max<<" "<<y1_max<<'\n';
        solved = true;
    }
    else{
        for(auto pos: possiveis){
            x1_max = MINF;
            y1_max = MINF;
            x2_min = LINF;
            y2_min = LINF; 
            FOR(i,0,n){
                if(i == pos) continue;
                x1_max = max(x1_max, x1[i]);
                y1_max = max(y1_max, y1[i]);
                x2_min = min(x2_min, x2[i]);
                y2_min = min(y2_min, y2[i]);
            }
            if(x1_max <= x2_min && y1_max <= y2_min){
                cout<<x1_max<<' '<<y1_max<<'\n';
                solved = true;
                break;
            }
        }
    }
    if(!solved){
        cout<<guarda1<<' '<<guarda2<<'\n';
    }

    return 0;
}
