#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dbg(x) cout << #x << " = " << x << endl
#define FOR(i, a, n) for(ll i = a; i <= n; i++)

typedef unsigned long long ll;

string lcs(string s, string t){
    ll a = s.length();
    ll b = t.length();
    vector<vector<ll>> matriz(a+1, vector<ll>(b+1, 0));
    FOR(i,1,a){
        FOR(j,1,b){
            if(s[i-1] == t[j-1]){
                matriz[i][j] = matriz[i-1][j-1]+1;
            }
            else{
                matriz[i][j] = max(matriz[i-1][j], matriz[i][j-1]);
            }
        }
    }
    string ans = "";
    ll i = a;
    ll j = b;
    while (i > 0 && j > 0){
        if (s[i-1] == t[j-1]){
            ans = t[j-1] + ans;
            i--;
            j--;
        }
        else if(matriz[i-1][j] > matriz[i][j-1]) i--;
        else j--;
    }
    return ans;
}

int main(){ _
    cout<<fixed;
    string s;
    string t;
    cin>>s>>t;
    string ans = lcs(s,t);
    cout<<ans<<endl;
    return 0;
}
