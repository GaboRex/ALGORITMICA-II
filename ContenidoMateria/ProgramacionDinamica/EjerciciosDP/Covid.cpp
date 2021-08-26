#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

int v[10000];
int padre[10000];
int cont[10000];
int rango[10000];

int n;
void init() {
    for(int i=0;  i<= n; i++) {
        padre[i] = i;
        rango[i] = 0;
        cont[i] = 1;
    }
}

int encontrar(int x) {
    if(x == padre[x]) {
        return x;
    }
    else {
        padre[x] = encontrar(padre[x]);
        
        return padre[x];
    }
}

void unionRango(int x,int y) { 
    int xRaiz = encontrar(x);
    int yRaiz = encontrar(y);
    if(rango[xRaiz] > rango[yRaiz]) {
        padre[yRaiz] = xRaiz;
        cont[yRaiz] += cont[xRaiz];

    } else {
        padre[xRaiz] = yRaiz;
        cont[xRaiz] += cont[yRaiz];
        if(rango[xRaiz] == rango[yRaiz]) {
            rango[yRaiz]++;
        }
    }
}

int main() {
    input;
    cin>>n;
    init();
    int nrounionRangoes; 
    cin>>nrounionRangoes;
    while(nrounionRangoes--) {
        int x,y;
        cin>>x>>y; 
        unionRango(x,y);
    }
    for(int i=0;i<=n;i++){ 
        cout<<"["<<i<<"] ";
    }
    cout<<endl;
    for(int i=0;i<=n;i++){ 
        cout<<"[" <<padre[i]<<"] ";
    }
    cout<<endl;
    for(int i=0;i<=n;i++){ 
        cout<<"[" <<rango[i]<<"] ";
    }
    cout<<endl;
    int sol = -1;
    for(int i=0;i<=n;i++){
        if(i == padre[i]) {
            sol = max(sol,cont[i]);
        }
    }
    cout<<sol<<endl;

    return 0;
}
