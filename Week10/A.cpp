#include <bits/stdc++.h>

using namespace std;

#define NUUUU_ZEEE ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define po_pega_ai return
#define si if
#define trem_errado(x) cout << #x << " = " << x << endl
#define vai_toda_vida_ate_n(i, a, n) for(trem i = a; i < n; i++)
#define beaga_eh_quem(bh_eh_nois) cout<<bh_eh_nois<<'\n';
#define uai_le while

typedef int trem;
typedef void nadanao;

const trem NUUUUTREMZAO = 0x3f3f3f3f;
const trem NUUUUU = 200001;
const trem DRX = 30;

trem arreda[NUUUUU][DRX];
trem destino[NUUUUU];

trem uai, so;

trem tem_base_um_trem_desse_nao_so(trem base, trem exp){
    // no zz escrevi ess trem quia toa zz paia dmssss
    trem resposta_mil_grau_nu = 1;  
    uai_le (exp > 0){
        si (exp%2 == 1){  
            resposta_mil_grau_nu = resposta_mil_grau_nu*base;
        }
        base = base*base;  
        exp = exp/2;       
    }
    po_pega_ai resposta_mil_grau_nu;
}
nadanao bota_os_carro_nos_boi(){
    vai_toda_vida_ate_n(i,1,uai+1){
        arreda[i][0] = destino[i];
    }
    vai_toda_vida_ate_n(j,1,DRX){
        vai_toda_vida_ate_n(i,1,uai+1){
            si(arreda[i][j-1] != -1){
                arreda[i][j] = arreda[arreda[i][j-1]][j-1];
            }
        }
    }
}
trem vao_ve_esse_trem(trem um_trem, trem oto_trem){
    trem negoco = 0;
    uai_le(oto_trem > 0){
        si(oto_trem%2 == 1){
            um_trem = arreda[um_trem][negoco];
            //trem_errado(um_trem);
        }
        oto_trem = oto_trem/2;
        negoco++;
    }
    po_pega_ai um_trem;
}
trem main(){ NUUUU_ZEEE
    cin>>uai>>so;
    vai_toda_vida_ate_n(vei,1,uai+1) cin>>destino[vei];
    memset(arreda,-1,sizeof arreda);
    bota_os_carro_nos_boi();
    trem sem, brava;
    vai_toda_vida_ate_n(vei,0,so){
        cin>>sem>>brava;
        trem respostinha_maladeza = vao_ve_esse_trem(sem,brava);
        beaga_eh_quem(respostinha_maladeza);
    }

    po_pega_ai 0;
}
