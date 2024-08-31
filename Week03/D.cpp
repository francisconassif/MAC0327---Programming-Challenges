#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dbg(x) cout << #x << " = " << x << endl
#define FOR(i, a, n) for(int i = a; i < n; i++)

typedef long long ll;

set<int> primos(int n) {
    vector<bool> prime(n+1, true);
    set<int> primes; 
    for (int i = 2; i*i<=n; i++) {
        if (prime[i]) {
            for (int j = i*i; j <= n; j += i)
                prime[j] = false;
        }
    }
    for (int i = 2; i <= n; i++) {
        if (prime[i]) primes.insert(i);
    }
    return primes;
}

int main(){ _
    int n; cin>>n;
    set<int> primosn = primos(n);
    int count = 0;
    FOR(i,6,n+1){
        int div = 0;
        //dbg(i);
        for (auto elem : primosn){
            //dbg(elem);
            if (div > 2) break;
            if (elem > i) break;
            if (i%elem == 0) div++;
        }
        //dbg(div);
        if (div == 2) count++;
    }

    cout<<count<<endl;

    return 0;
}
