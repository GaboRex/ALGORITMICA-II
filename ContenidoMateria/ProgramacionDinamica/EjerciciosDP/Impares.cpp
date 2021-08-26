/*Gabriel Neme Benitez
Ing. de Sistemas Computacionales
*/
#include <bits/stdc++.h>
using namespace std;

string numero = "500";
int dp[20][2][20];

int solveDp(int posicion, int mayor, int impares){ 
    if(posicion > numero.size()){ //excede al tope y retorna 
        return 0;
    }

    if(posicion == numero.size()){ //llega a tope
        if(impares >= 2){//preguntamos si tiene dos pares el numero
            return 1;
        }else{
            return 0;
        }
    }

    if(dp[posicion][mayor][impares] == -1){// preguntamos si no se ha calculado
        int tope = 9;
        if(mayor == true){ // el numero puede llegar a pasarse del tope? 
            tope = numero[posicion] - '0'; // condicionamos que solo se puede usar los numeros menores altope
        }
        dp[posicion][mayor][impares] = 0;
        for(int digito = 0; digito <= tope; digito++){
            if(digito == tope){//si estuviera en el tope
                dp[posicion][mayor][impares] += solveDp(posicion+1,true,impares + digito%2 == 1);
            }else{//si aun no llegara al tope
                dp[posicion][mayor][impares] += solveDp(posicion+1,false,impares + digito%2 == 1);
            }
        }
    }
    return dp[posicion][mayor][impares];
}

int main(){
    int a = 20;
    int b = 30;
    numero = to_string(a);
    memset(dp,-1,sizeof(dp));
    int paresHastaA = solveDp(0,false,0);
    memset(dp,-1,sizeof(dp));
    int paresHastaB = solveDp(0,false,0);
    cout << paresHastaB - paresHastaA;
    return 0;
}