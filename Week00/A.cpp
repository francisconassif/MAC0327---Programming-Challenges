#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t; cin>>t;
    bool paridade;
    bool coluna;
    long long resposta=1;
    long long max=1;
    long long diagonal =1;
    long long lin,col;
    for (long long i=0;i<t;i++){
        coluna=false;
        max=1;
        cin>>lin>>col;
        if (lin>col){
            max = lin;
            coluna=false;
        }
        else{
            max = col;
            coluna=true;
        }
        if (max%2==0){
            paridade=true;
        }
        else{
            paridade=false;
        }
        diagonal = 1+((2+2*(max-1))*(max-1))/2;
        long long dec=max-lin;
        long long del=max-col;
        if (coluna){
            if (paridade){
                resposta=diagonal-dec;
            }
            else{
                resposta=diagonal+dec;
            }
        }
        else{
            if (paridade){
                resposta=diagonal+del;
            }
            else{
                resposta=diagonal-del;
            }
        }
        if (lin == col){
            cout<<diagonal<<endl;
        }
        else{
            cout<<resposta<<endl;
        }

    }
    return 0;
}
