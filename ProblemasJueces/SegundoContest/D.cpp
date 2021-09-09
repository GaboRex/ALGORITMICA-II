#include <bits/stdc++.h>
using namespace std;
unsigned int a[31270], s[31270], b[100];
void reset() {
	int i;
	a[1]=1;
	s[1]=1;
	for(i=2;
	i<31270;
	i++) {
		a[i]=a[i-1]+(int)log10((double)i)+1;
		s[i]=s[i-1]+a[i];
	}
}
int main() {
	int T;
	int n;
	int i;
	scanf("%d", &T);
	reset();
	while(T--) {
		scanf("%d", &n);
		i=1;
		int v=1;
		while(s[i]<n) i++;
		int pos=n-s[i-1];
		int tmp=0;
		int y;
		for(int i=1;
		tmp<pos;
		i++) {
			tmp+=(int)log10((double)i)+1;
			y=i;
		}
		tmp=tmp-(int)log10((double)y)-1;
		int x=pos-tmp;
		while(y) {
			b[v]=y%10;
			y=y/10;
			v++;
		}
		cout<<b[v-x]<<endl;
	}
	return 0;
}