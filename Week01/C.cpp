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
    ll n,l; cin>>n>>l;
    vector<ll> postes(n);
    cout << fixed;
    cout << setprecision(5);
    ll max_dist=0;
    ll dist;
    FOR(i,0,n){
        cin>>postes[i];
    }
    sort(postes.begin(),postes.end());
    ll ext1=postes[0];
    ll ext2=l-postes[n-1];
    FOR(i,0,n-1){
        dist = postes[i+1]-postes[i];
        //dbg(dist);
        if (dist > max_dist){
            max_dist = dist;
        }
    }
    //dbg(max_dist);
    //dbg(ext1);
    //dbg(ext2);
    ext1 = ext1*2;
    ext2 = ext2*2;
    if (ext1 > max_dist){
        max_dist=ext1;
        //dbg(max_dist);
    }
    if (ext2 > max_dist){
        max_dist = ext2;
        //dbg(max_dist);
    }
    long double resposta = max_dist/2.0;
    cout<<resposta<<endl;

    return 0;
}
