#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define dbg(x) cout << #x << " = " << x << endl
#define FOR(i, a, n) for(int i = a; i < n; i++)

typedef long double ld;
typedef long long ll;
typedef pair<ld,ld> ponto;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;




ld dist(ponto A, ponto B){
    ld dx = A.f - B.f;
    ld dy = A.s - B.s;
    dx = dx * dx;
    dy = dy * dy;
    return sqrt(dy+dx);
}

int main(){ _
    ld x0, yo, x1, yi, x2, y2;
    cin>>x0>>yo>>x1>>yi>>x2>>y2;
    ponto A = {x0,yo};
    ponto B = {x1,yi};
    ponto C = {x2,y2};
    cout<<fixed<<setprecision(4);
    ld a,b,c;
    a = dist(B,C);
    b = dist(A,C);
    c = dist(A,B);
    ld perimetro = a+b+c;
    cout<<perimetro<<' ';
    perimetro /= 2.0;
    ld area = (perimetro-a)*(perimetro-b)*(perimetro-c)*perimetro;
    area = sqrt(area);
    cout<<area<<'\n';
    return 0;
}
