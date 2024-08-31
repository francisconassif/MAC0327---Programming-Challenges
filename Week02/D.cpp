#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dbg(x) cout << #x << " = " << x << endl
#define FOR(i, a, n) for(int i = a; i < n; i++)



int main(){ _
    string s; cin>>s;
    int n = s.length();
    vector<int> resp(n,0);
    char anterior = s[0];
    FOR(i,1,n){
        if (s[i] == anterior) resp[i]=resp[i-1]+1;
        else resp[i]=resp[i-1];
        anterior = s[i];
    }
    int m; cin>>m;
    int soma;
    FOR(i,0,m){
        int l,r;cin>>l>>r;
        soma=resp[r-1]-resp[l-1];
        cout<<soma<<endl;
    }


    return 0;
}
