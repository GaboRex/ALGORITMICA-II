#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std; 

int filas[8]; 
 
 bool esValido(int fila,int columna){
     // if(!esValido(solSiguiente))

     for (int prev = 0; prev < columna; prev++) {
         if(filas[prev] == fila || abs(filas[prev]-fila)== abs(prev-columna)){
           return false;  
         }
     }
     return true;
 }
 //TODO
 // f(posicion +1 , solSiguiente)

