#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

typedef long double ld;

int main(){ _
    int t; cin>>t;
    while(t--){
        ld x0, yo, x1, yi, x2, y2;
        cin>>x0>>yo>>x1>>yi>>x2>>y2;
        if(x0 == x1){
            if(x2 == x0) cout<<"TOUCH\n";
            else if(yo < yi){
                if(x2 > x0) cout<<"RIGHT\n";
                else cout<<"LEFT\n";
            }
            else{
                if(x2 < x0) cout<<"RIGHT\n";
                else cout<<"LEFT\n";
            }
            continue;
        }
        ld m1 = (ld) (x2-x0)*(y2-yi); 
        ld m2 = (ld) (x2-x1)*(y2-yo);
        ld m = m1-m2;
        if(m == 0) cout<<"TOUCH\n";
        else if(m > 0) cout<<"LEFT\n";
        else cout<<"RIGHT\n";

    }
    return 0;
}
