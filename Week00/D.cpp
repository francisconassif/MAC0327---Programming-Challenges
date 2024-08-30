#include <iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    string entrada;
    int x=0;
    for (int i = 0; i<t;i++){
        cin>>entrada;
        char primeiro=entrada[1];
        if (primeiro == '+'){
            x++;
        }
        else{
            x--;
        }
    }
    cout<<x<<endl;
    return 0;
}
