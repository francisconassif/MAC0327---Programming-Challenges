#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define x first
#define y second
#define pb push_back
#define dbg(x) cout << #x << " = " << x << endl
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define a x 
#define b y

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ponto;
typedef pair<ponto,ponto> reta;
typedef pair<ld,ld> afim;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<ponto> p;

bool colineares(ponto A, ponto B, ponto C){
    return (A.x*(B.y-C.y)+B.x*(C.y-A.y)+C.x*(A.y-B.y)) == 0;
}

afim line(ponto A, ponto B){
    ld angular = (ld)(A.y-B.y)/(A.x-B.x);
    ld linear  = (ld) A.y - A.x*angular;
    return {angular, linear};
}


int main(){ _
    int n; cin>>n;
    int retas = 0;
    p.resize(n);
    reta origem = {{0,0},{0,0}};
    reta r=origem;
    reta s=origem;
    int pontos_s = 0;
    bool ans = true;
    bool seis_retas = false;
    vector<reta> possiveis;
    FOR(i,0,n){
        cin>>p[i].x>>p[i].y;
        if(n < 5) continue;
        if(n > 4 && i == 3){
            if(colineares(p[0],p[1],p[2]) && colineares(p[1],p[2],p[3])){
                retas = 1;
                r = {p[0],p[1]};
            }
            else if(colineares(p[0],p[1],p[2])){
                retas = 2;
                r = {p[0],p[1]};
                pontos_s = 1;
                s.x = p[3];
            }
            else if(colineares(p[1],p[2],p[3])){
                retas = 2;
                r = {p[1],p[2]};
                pontos_s = 1;
                s.x = p[0];
            }
            else if(colineares(p[0],p[2],p[3])){
                retas = 2;
                r = {p[0],p[2]};
                pontos_s = 1;
                s.x = p[1];
            }
            else if(colineares(p[1],p[0],p[3])){
                retas = 2;
                r = {p[1],p[0]};
                pontos_s = 1;
                s.x = p[2];
            }
            else{
                //aqui precisa descrever as 6 possiveis retas;
                seis_retas = true;
            }
            
        }
        else if(seis_retas && i==4){
            if(colineares(p[0],p[1],p[4]) || colineares(p[2],p[3],p[4])){
                r = {p[0],p[1]};
                retas = 2;
                s = {p[2],p[3]};
                pontos_s = 2;
            }
            else if(colineares(p[0],p[2],p[4]) || colineares(p[1],p[3],p[4])){
                r = {p[0],p[2]};
                retas = 2;
                s = {p[1],p[3]};
                pontos_s = 2;
            }
            else if(colineares(p[0],p[3],p[4]) || colineares(p[1],p[2],p[4])){
                r = {p[0],p[3]};
                retas = 2;
                s = {p[1],p[2]};
                pontos_s = 2;
            }
            else{
                ans = false;
            }
        }
        else if(retas == 1 && pontos_s == 0){
            if(!colineares(p[i], r.x, r.y)){
                retas = 2;
                pontos_s = 1;
                s.x = p[i];
            }
        }
        else if(retas == 2 && pontos_s == 1){
            if(!colineares(p[i],r.x,r.y)){
                pontos_s = 2;
                s.y = p[i];
            }
        }
        else if(retas == 2 && pontos_s == 2){
            if(!colineares(s.x, s.y, p[i]) && !colineares(r.x,r.y,p[i])) ans = false;
        }
    }
    if(ans || n < 5) cout<<"YES\n";
    else cout<<"NO\n";

    return 0;
}
