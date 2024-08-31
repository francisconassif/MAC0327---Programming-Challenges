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

int main(){ _
    cout<<fixed;
    int n,k;cin>>n>>k;
    vector<ll>x(n);
    vector<ll>copia(n);
    FOR(i,0,n){
        cin>>x[i];
    }
    int min=0;
    int max=n;
    ll med,custo,custof=0;
    while(min<=max){
        med = min + (max-min)/2;
        custo = 0;
        copy(x.begin(),x.end(),copia.begin());
        FOR(i,0,n){
            copia[i]+=(i+1)*med;
        }
        sort(copia.begin(),copia.end());
        FOR(i,0,med){
            custo+=copia[i];
        }
        if (custo>k){
            max=med-1;
        }
        else{
            min=med+1;
            custof=custo;
        }
    }
    cout<<min-1<<" "<<custof<<endl;
    return 0;
}
