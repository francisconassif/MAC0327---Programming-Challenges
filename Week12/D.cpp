#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define dbg(x) cout << #x << " = " << x << endl
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define x f
#define y s

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ponto;
typedef pair<ponto, ll> completo;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<ponto> pontos;
map<ponto,ll> indices;

ld dist(ponto A, ponto B) {
    ll xis = A.x - B.x;
    xis *= xis;
    ll ips = A.y - B.y;
    ips *= ips;
    return sqrt(xis + ips);
}



int main() { 
    cout << fixed << setprecision(6);
    ll n;
    ld distmin = 1000000000.0;
    cin >> n;
    pontos.resize(n);
    ll index = 0;
    ponto A, B;
    set<ponto> pontos_considerados;
    for(ponto & pt: pontos){
        cin>>pt.f>>pt.s;
        indices[pt]=index;
        index++;
    }
    index = 0;
    sort(pontos.begin(),pontos.end());
    
    for(ponto & pt : pontos){
        ld xo = pt.f;
        ld yo = pt.s;
        while(xo - pontos[index].f > distmin){
            ld xi = pontos[index].f;
            ld yi = pontos[index].s;
            pontos_considerados.erase({yi,xi});
            index++;
            if(index == n){
                cout<<distmin<<endl;
                return 0;
            }
            //dbg(index);
        }
        set<ponto>::iterator inferior, superior;
        inferior = pontos_considerados.lower_bound({yo-distmin, -500000.0});
        superior = pontos_considerados.lower_bound({yo+distmin, +500000.0});
        for(set<ponto>::iterator i = inferior; i!=superior; ++i){
            ld xi = i->s;
            ld yi = i->f;
            ld curr_dist = hypot(xo-xi,yo-yi);
            if(curr_dist < distmin){
                distmin = curr_dist;
                A = {xo,yo};
                B = {xi,yi};
            }
        }
        pontos_considerados.insert({yo,xo});
    }
    cout<<min(indices[A],indices[B])<<' '<<max(indices[A],indices[B])<<' ';
    cout<<distmin<<'\n';
    return 0;
}
