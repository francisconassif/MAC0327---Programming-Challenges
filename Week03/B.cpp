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



int low_prime(int n){
    if (n % 2 == 0) return 2;
    for (int i = 3; i * i <= n; i = i +2) if (n % i == 0) return i;
    return n;
}

int main(){ _
    int t; cin>>t;
    FOR(i,0,t){
        int n;cin>>n;
        int p = low_prime(n);
        cout << n/p << " " << n - (n/p) << endl;
    }
    return 0;
}
