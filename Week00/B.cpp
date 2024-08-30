#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    int n;
    for (int i = 0; i<t; i++){
        cin>>n;
        int x;
        int zeros=0;
        int positivos=0;
        int negativos=0;
        int movimentos=0;
        int indice=0;
        int max=1000000000;
        int modificado = 1;
        bool negatividade=false;
        for (int j = 0; j<n; j++){
            cin>>x;
            if (x>0){
                positivos++;
            }
            else if (x==0){
                zeros++;
            }
            else{
                negativos++;
                negatividade=true;
                if (abs(x)<max){
                    max = abs(x);
                    indice = j;
                }
            }
        }
        if (zeros!=0){
            movimentos=0;
        }
        else if (!negatividade){
            movimentos=1;
            indice=0;
            modificado=0;
        }
        else if(negativos%2==0){
            movimentos=1;
            modificado=0;
        }
        else{
            movimentos=0;
        }
        cout<<movimentos<<endl;
        if (movimentos!=0){
            indice++;
            cout<<indice<<" "<<modificado<<endl;
        }
    }
}
