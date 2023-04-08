#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define itr iterator
#define ritr reverse_iterator
#define pint pair<int, int>
#define pll pair<ll, ll>
#define S second
#define F first
#define v(a) vector<a>
#define mk(a, b) make_pair(a, b)
#define psh(a) push_back(a)
#define mem(arr, a) memset(arr, a, sizeof(arr))
#define pr(n) printf("%d\n", n)
#define sc(n) scanf ("%d", &n)
#define scll(n) scanf ("%lld", &n)
#define prll(n) printf("%lld\n", n)
#define MOD 1000000007ll
#define inf 1000000000ll

int n, m;
int g[1000][1000];

bool isSafe (int v, int * color, int c) {
	int i;
	for (i = 0; i < n; i++) {
		if (g[v][i] && c == color[i]) {
			return false;
		}
	}	
	return true;
}

bool graphColoring (int * color, int v) {
	if (v == n) {
		return true;
	}

	int i;

	for (i = 1; i <= m; i++) {
		if (isSafe(v, color, i)) {
			color[v] = i;
			if (graphColoring(color, v+1)){
				return true;
			}
			color[v] = 0;
		}
	}
	return false;
}

int main (void) {
	int i, j;
	sc (n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			sc (g[i][j]);
		}
	}
	sc (m);
	int color[n] = {0};
	if (graphColoring(color, 0) ) {
		for (i = 0; i < n; i++) {
			cout<<color[i]<<" ";
		}
	}else {
		cout<<"No Solution Found"<<endl;
	}

	return 0;
}
