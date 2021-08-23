#include <bits/stdc++.h> 

using namespace std; 

string number = "307";
int dp[20][2][20];
int solve_dp(int pos,int mayor,int pares){
    if(pos > number.size()){
        return 0;
    }
  if(pos == number.size()){
    if(pares==2){ // cambiar
return 1;
        }else{
            return 0;
        }
    }
 if(dp[pos][mayor][pares] ==-1){
     int tope= 9;
     if(mayor == true){
         int tope = number[pos]-'0';

     }
     for (int digito = 0; digito < tope; digito++){
         if (digito ==tope){
             dp[pos][mayor][pares ]+= solve_dp(pos+1,true,pares + digito %2 == 0 + pares); // modificar tercer parametro

         }else{
             dp[pos][mayor][pares] += solve_dp(pos+1,false,pares +  digito %2 == 0 + pares);
         }
     }
    }
    return dp[pos][mayor][pares];
 }   
 int main(){
     int a = 20;
     int b = 30;
     number = to_string(a-1);
     memset(dp,-1,sizeof(dp));
     int pares_hasta_a = solve_dp(0,false,0);
     //b
     memset(dp,-1, sizeof(dp));
     number = to_string(b);
      int pares_hasta_b = solve_dp(0,false,0);
    cout<< pares_hasta_b-pares_hasta_a;
     return 0;
 }
