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

int busca_distancia(vector<int>& x, int c,int n){
    int imin=0;
    int imax=x.back()-x.front();
    while(imin<=imax){
        int imed=imin+(imax-imin)/2;
        int posicao=x[0];
        int vacas=1;
        FOR(i,1,n){
            if(x[i]-posicao>=imed){
                vacas++;
                posicao=x[i];
            }
        }
        if(vacas>=c){
            imin=imed+1;
        }
        else{
            imax=imed-1;
        }
    }
    return imin-1;
}

int main(){ _
    int t;cin>>t;
    int resp;
    FOR(i,0,t){
        int n,c;cin>>n>>c;
        vector<int>x(n);
        FOR(j,0,n){
            cin>>x[j];
        }
        sort(x.begin(),x.end());
        resp=busca_distancia(x,c,n);
        cout<<resp<<endl;
    }
    return 0;
}
