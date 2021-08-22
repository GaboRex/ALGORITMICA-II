#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

struct dom{
    int x,h,num,id;
}
    d[100010];
    int ans[100010];

int cmp1(const dom d1,const dom d2){
    if(d1.x<d2.x)
        return 1;
    else
        return 0;
}

int main(){
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
        ans[i]=1;
    for(i=0;i<n;i++){
        cin>>d[i].x>>d[i].h;
        d[i].id=i;
        d[i].num=1;
    }
    sort(d,d+n,cmp1);
    for(i=n-2;i>=0;i--) {
        int j=i+1;
        while(j!=n&&d[j].x<d[i].x+d[i].h){
            d[i].num+=d[j].num;
            j=d[j].num+j;
        }
        ans[d[i].id]=d[i].num;
    }
    for(i=0;i<n;i++)
        cout<<ans[i]<<' ';
    cout<<endl;
    return 0;
}