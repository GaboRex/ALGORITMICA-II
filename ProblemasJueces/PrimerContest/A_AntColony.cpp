#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)

using namespace std;
const int maxn=100100;
typedef pair<int,int> pII;
pII b[maxn];
int n,s[maxn];
int g[maxn<<2];
 
int gcd(int x,int y){
	if(x==0) return y;
	return gcd(y%x,x);
}
 
void build(int l,int r,int rt){
	if(l==r)
	{
		g[rt]=s[l];
		return ;
	}
	int mid=(l+r)/2;
	build(l,mid,rt<<1); build(mid+1,r,rt<<1|1);
	g[rt]=gcd(g[rt<<1],g[rt<<1|1]);
}
 
int query(int L,int R,int l,int r,int rt){
	if(r<L||l>R) return 0;
	if(L<=l&&r<=R)
	{
		return g[rt];
	}
	int mid=(l+r)/2;
	int u=query(L,R,l,mid,rt<<1);
	int v=query(L,R,mid+1,r,rt<<1|1);
	return gcd(u,v);
}
 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",s+i);
		b[i]=(make_pair(s[i],i));
	}
	sort(b+1,b+1+n);
	build(1,n,1);
	int m;
	scanf("%d",&m);
	while(m--){
		int Left,Right;
		scanf("%d%d",&Left,&Right);
		int G=query(Left,Right,1,n,1);
		int from=lower_bound(b+1,b+n+1,make_pair(G,Left))-(b+1);
		int to=lower_bound(b+1,b+1+n,make_pair(G,Right+1))-(b+1);
		printf("%d\n",(Right-Left+1)-(to-from));
	}
	return 0;
}