#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)

int t, n, m, i, j, parent[30005], sum[30005], ans;
int a, b;

int find(int x) {
	if (x == parent[x])
		return parent[x];
	else
		return find(parent[x]);
}
int main() {
	scanf("%d", &t);
	while (t --) {
		ans = 0;
		scanf("%d%d", &n, &m);
		for (i = 1; i <= n; i ++) {
			parent[i] = i;
			sum[i] = 1;
		}
		for (i = 0; i < m; i ++) {
			scanf("%d%d", &a, &b);
			int pa = find(a);
			int pb = find(b);
			if (pa != pb) {
				parent[pa] = pb;
				sum[pb] += sum[pa];
				if (ans < sum[pb])
					ans = sum[pb];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}