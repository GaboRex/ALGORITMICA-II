// aqui vamos de nuevoooo
#include <bits/stdc++.h>
using namespace std;
const int INF=1<<30;
const int maxn=105;
int p[maxn], g[maxn][maxn];
int s, t, n, m;
int bfs() {
	memset(p, -1, sizeof(p));
	p[s]=s;
	queue<int>q;
	q.push(s);
	while(!q.empty()) {
		int u=q.front();
		q.pop();
		for(int i=0;
		i<n;
		++i) {
			if(g[u][i]>0&&p[i]==-1) {
				p[i]=u;
				q.push(i);
			}
		}
	}
	if(p[t]==-1) return 0;
	int a=INF, u=t;
	while(p[u]!=u) {
		a=min(a, g[p[u]][u]);
		u=p[u];
	}
	u=t;
	while(p[u]!=u) {
		g[p[u]][u]-=a;
		g[u][p[u]]+=a;
		u=p[u];
	}
	return a;
}
int maxFlow() {
	int flow=0, f;
	while(1) {
		f=bfs();
		if(f<=0) break;
		flow+=f;
	}
	return flow;
}
int main() { //empezamos a rezar y lo lanzamos
	int a, b, c, cas=0;
	while(scanf("%d", &n)&&n) {
		scanf("%d%d%d", &s, &t, &m);
		--s, --t;
		memset(g, 0, sizeof(g));
		while(m--) {
			scanf("%d%d%d", &a, &b, &c);
			--a, --b;
			g[a][b]+=c;
			g[b][a]+=c;
		}
		printf("Network %d\n", ++cas);
		printf("The bandwidth is %d.\n\n", maxFlow());
	}
	return 0;
}