#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dbg(x) cout << #x << " = " << x << endl
#define FOR(i, a, n) for(int i = a; i < n; i++)

typedef long long ll;

int main(){ _
    int t; cin>>t;
    int x,n;
    int ans=1;
    
    FOR(i,0,t){
        cin>>x>>n;
        ans = 1;
        if (n==1) ans = x;
        else{
            for(int i=2;i*i<=x;i++){
                if(x%i==0){
                    //dbg(x);
                    //dbg(i);
                    if(i>=n){
                        ans = x/i;
                        break;
                    }
                    else if(x/i>=n){
                        ans = i;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
