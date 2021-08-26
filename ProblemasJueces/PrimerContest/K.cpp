#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)

using namespace std;
//Aqui vamos de nuevo gg
int padre[110];
int rango[110];

void init(int n) {
    for(int i=0;  i<= n; i++) {
        padre[i] = i;
        rango[i] = 0;
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
    if (xRaiz == yRaiz) return;
    if(rango[xRaiz] > rango[yRaiz]) {
        padre[yRaiz] = xRaiz;

    } else {
        padre[xRaiz] = yRaiz;
        if(rango[xRaiz] == rango[yRaiz]) {
            rango[yRaiz]++;
        }
    }
}
float euclidian(pair<float, float> a, pair<float, float> b) {
    float x = a.first - b.first;
    float y = a.second - b.second;
    return sqrt(x * x + y * y);
}

bool compare(pair<float, pair<int, int> > a, pair<float, pair<int, int> > b) {
    return a.first < b.first;
}
 

int main() {
    //casi me olvido comentar el input gg
    //VAMOS A LANZARLO Y A REZAR
   // input;
    //output;
 int cases, numberOfFreckers;
    float x, y;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d", &numberOfFreckers);
 
        vector<pair<float, float> > points;
        float matrix[numberOfFreckers][numberOfFreckers];
        float visited[numberOfFreckers], cost[numberOfFreckers], prev[numberOfFreckers];
 
        for (int i = 0; i < numberOfFreckers; i++) {
            scanf("%f %f", &x, &y);
            points.push_back(make_pair(x, y));
        }
 
        init(numberOfFreckers);
 
        vector<pair<float, pair<int, int> > > E;
        E.clear();
        vector<pair<float, pair<int, int> > > X;
        X.clear();
        for (int i = 0; i < numberOfFreckers; i++) {
            for (int j = i + 1; j < numberOfFreckers; j++) {
                E.push_back(make_pair(euclidian(points[i], points[j]), make_pair(i, j)));
            }
        }
        sort(E.begin(), E.end(), compare);
 
        for (int i = 0; i < E.size(); i++) {
            if (encontrar(E[i].second.first) != encontrar(E[i].second.second)) {
                X.push_back(E[i]);
                unionRango(E[i].second.first, E[i].second.second);
            }
        }
 
        float total = 0;
        for (int i = 0; i < X.size(); i++) total += X[i].first;
        printf("%.2f\n", total);
 
        if(cases > 0) printf("\n");
    }
}