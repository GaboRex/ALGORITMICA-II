#include<bits/stdc++.h>
using namespace std;

struct prefijo{
    prefijo *x[26];
    prefijo()
    {
      for(int i=0; i<26;i++)
      x[i]= NULL;
    }
    ~ prefijo(){
        for(int i=0; i<26; i++)
        if(x[i]==NULL)delete x[i];
}
}*rootp;

struct sufijo{
    sufijo *y[26];
    sufijo(){
    for(int i=0; i<26;i++)
    y[i]=NULL;
}
~ sufijo(){
    for(int i=0; i<26; i++)
    if(y[i]==NULL)delete y[i];
}
}*roots;


long long int pre[26], suf[26], pcn, scn;
char s[1009];

void addp(prefijo *cur, int n){
    int i, a;
    for(i=0; i<n; i++){
        a=s[i]-'a';
        if(cur->x[a]==NULL){
            cur ->x[a] = new prefijo();
            if(i!=0) pre[a]++;
            pcn++;
        }
        cur=cur->x[a];
    }
}

void adds(sufijo *cur, int n){
    int i,a;
    for(i= n-1; i>=0;i--){
        a=s[i]-'a';
        if(cur -> y[a]==NULL){
            cur->y[a]= new sufijo();
            if(i!=n-1) suf[a]++;
            scn++;
        }
        cur=cur->y[a];
    }
}

int main(){
    int m, n, i, v;
    long long int ans;
    while(scanf("%d%d", &m, &n)&&m &&n){
        pcn=scn=0;
        for(i=0; i<26;i++)
        pre[i]=suf[i]=0;
        rootp=new prefijo();
        roots=new sufijo();
        
        while(m--){
            scanf("%s", s);
            v=strlen(s);
            addp(rootp,v);
        }
        while(n--){
            scanf("%s", s);
            v=strlen(s);
            adds(roots, v);
        }
        
        ans=pcn*scn;
        
        for(i=0; i<26; i++)
        ans-=(pre[i]*suf[i]);
        
        printf("%lld\n", ans);
        
        delete rootp;
        delete roots;
    }
    return 0;
}