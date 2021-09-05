#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)


int busquedaBinariaRecursiva(int arreglo[], int busqueda, int izquierda, int derecha){
    if (izquierda > derecha) return -1;

    int indiceDeLaMitad = floor((izquierda + derecha) / 2);

    int valorQueEstaEnElMedio = arreglo[indiceDeLaMitad];
    if (busqueda == valorQueEstaEnElMedio){
        return indiceDeLaMitad;
    }
    
    if (busqueda < valorQueEstaEnElMedio){

        derecha = indiceDeLaMitad - 1;
    }else{

        izquierda = indiceDeLaMitad + 1;
    }
    return busquedaBinariaRecursiva(arreglo, busqueda, izquierda, derecha);
}

int main(){
    int numeros[] = {1, 2, 4, 8, 15, 16, 20, 30, 40, 50};
    int busqueda = 40;
    int longitudDelArreglo = sizeof(numeros) / sizeof(numeros[0]);
    int resultadoBusquedaRecursiva = busquedaBinariaRecursiva(numeros, busqueda, 0, longitudDelArreglo - 1);
    printf("Si buscamos %d recursivamente, el resultado es %d\n", busqueda, resultadoBusquedaRecursiva);
}
