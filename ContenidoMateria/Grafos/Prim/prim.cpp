#include <stdio.h>
#define n 100 //maximo numero de vertices del grafo
#define max 9999 //valor muy superior al que puede tomar el grafo ponderado
struct arista {
	//estructura con la que definimos las aristas resultantes del arbol generador de coste minimo
	int ver1;
	int ver2;
}
;
struct arista T[n];
void prim (int L[n][n]) //la funcion requiere como parametro la matriz de adyacencia
	{
	//Te devolvera la tabla T[n] compuesta por aristas.
	int masproximo[n];
	int distmin[n];
	int min;
	int i, j;
	int c, k;
	int x;
	c=0;
	for(i=0;
	i<n;
	i++) {
		T[i].ver1=0;
		T[i].ver2=0;
	}
	for(i=0;
	i<n;
	i++) {
		masproximo[i]=1;
		distmin[i]=L[i][0];
	}
	printf("n");
	for (i=1;
	i<n;
	i++) {
		min=max;
		for (j=1;
		j<n;
		j++) {
			if(0<=distmin[j]<min) {
				min=distmin[j];
				k=j;
			}
			T[c].ver1=masproximo[k];
			T[c].ver2=k;
			c++;
			distmin[k]=-1;
		}
		for (j=1;
		j<n;
		j++) {
			x=L[j][k];
			if(x<distmin[j]) {
				distmin[k]=L[j][k];
				masproximo[j]=k;
			}
		}
	}
}