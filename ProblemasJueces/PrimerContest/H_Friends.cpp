#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
#define N 100000

static int padreArray[N];
static int rangoArray[N];
static int elementosArray[N];

int maximo;

void MakeSet(int n){
    for(int i = 0; i < n; ++i){
        padreArray[i]  = i;
        rangoArray[i] = 0;
        elementosArray[i] = 1;
    }
}

int FindSet(int x){
    if( x != padreArray[x] )
        padreArray[x] = FindSet( padreArray[x] );
    return padreArray[x];
}

bool SameSet(int x, int y){
    return FindSet(x) == FindSet(y);
}

void Link(int x, int y){

    if( !SameSet(x, y) ){

        if( rangoArray[x] > rangoArray[y] ){
            padreArray[y] = x;
            elementosArray[x] += elementosArray[y];
            maximo = ( maximo < elementosArray[x] ) ? elementosArray[x] : maximo;
        }
        else{
            padreArray[x] = y;
            elementosArray[y] += elementosArray[x];
            maximo = ( maximo < elementosArray[y] ) ? elementosArray[y] : maximo;

            if(rangoArray[x] == rangoArray[y])
                rangoArray[y] = rangoArray[y] + 1;
        }

    }
}

void Union(int x, int y){
    Link( FindSet(x), FindSet(y) );
}

int main(){

    int n, m;
    int i, j;
    int times;
    scanf("%d", &times);
    while( times-- ){

        scanf("%d%d", &n, &m);

            MakeSet(n);

            maximo = 1;

            while(m--){
                scanf("%d%d", &i, &j);
                --i, --j;
                Union(i, j);
            }

            printf("%d\n", maximo);

        }


    return 0;
}