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
typedef long double ld;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ld calc_dist(ld xi, ld yi, ld x, ld y, ld r) {
    ld cat2 = (xi - x) * (xi - x) + (yi - y) * (yi - y);
    ld res = std::sqrt(r*r - cat2);
    return res;
}

vector<ld> solve(ld a11, ld a12, ld a21, ld a22, ld b1, ld b2){
    ld det = a11 * a22 - a12 * a21;
    ld inv_a11 = a22 / det;
    ld inv_a12 = -a12 / det;
    ld inv_a21 = -a21 / det;
    ld inv_a22 = a11 / det;

    vector<ld> result(2);
    result[0] = inv_a11 * b1 + inv_a12 * b2; 
    result[1] = inv_a21 * b1 + inv_a22 * b2; 
    return result;
}

int main(){
    ld r, x, y, a1, b1, a2, b2;
    cin >> r >> x >> y >> a1 >> b1 >> a2 >> b2;

    ld vx = a1 - a2;
    ld vy = b1 - b2;

    vector<ld> results = solve(vx, vy, vy, -vx, x - a1, y - b1);
    
    ld beta = results[1];

    ld xi = x - vy * beta;
    ld yi = y + vx * beta;

    ld cat = (xi - x) * (xi - x) + (yi - y) * (yi - y);

    if(cat > r * r) {
        cout << "-1\n";
    }
    else if (cat == r * r) {
        cout << "0\n";
    }
    else{
        ld res = calc_dist(xi, yi, x, y, r);
        res *= 2;
        cout << fixed << setprecision(5) << res << '\n';
    }

    return 0;
}
