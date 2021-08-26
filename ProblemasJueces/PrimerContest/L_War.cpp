#include <bits/stdc++.h>
using namespace std;
const int maxn=10001;
int padre[maxn],offset[maxn];
int encontrar(int x){
    if(x!=padre[x]){
        int tmp=padre[x];
        padre[x]=encontrar(padre[x]);
        offset[x]=(offset[x]+offset[tmp])%2;
    }
    return padre[x];
}
int Union(int x,int y,int d){
    int fx=encontrar(x);
    int fy=encontrar(y);
    if(fx==fy){

        if((offset[x]-offset[y]+2)%2!=d)
            return -1;
        else
            return 1;
    }
    padre[fy]=fx;
    offset[fy]=(offset[x]-offset[y]+d+2)%2;
    return 0;
}
void init(int n)
{
    for(int i=0;i<=n;i++)
        padre[i]=i;
    memset(offset,0,sizeof(offset));
}
int main(){
        //VAMOS A LANZARLO Y A REZAR
    ios::sync_with_stdio(false);
    int n;
    while(cin>>n)
    {
        int x,y,d;
        init(n);
        while(cin>>d>>x>>y,x+y+d)
        {
            if(d<=2){
                d--;
                if(Union(x,y,d)==-1){
                    cout<<-1<<endl;
                }
            }
            else {
                d-=3;
                padre[y]=encontrar(y);
                padre[x]=encontrar(x);

                if(padre[x]==padre[y]&&(offset[x]-offset[y]+2)%2==d)
                    cout<<1<<endl;
                else
                    cout<<0<<endl;
            }
        }
    }
    return 0;
}