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

int g[1000][1000];
int n;

bool is_safe(int v, v(int) path) {

	if (path.empty()) {
		return true;
	}

	v(int)::itr it = path.begin();
	while (it != path.end()) {
		if (*it == v) {
			return false;
		}
		it++;
	}
	int i;
	int vv = path.back();
	if (g[vv][v] == 1) {
		return true;
	}
	return false;
}

bool hamCycle (int v, v(int) &path) {
	if (v == n) {
		if (g[path.front()][path.back()] == 1){
			path.psh(path.front());
			return true;
		}
		else
			return false;
	}
	int i;
	for (i = 0; i < n; i++) {
		if (is_safe(i, path)) {
			path.psh(i);
			if (hamCycle(v+1, path)) {
				return true;
			}
			path.pop_back();
		}
	}
	return false;
}

int main (void) {
	freopen("input.in", "r", stdin);
	sc (n);
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			sc (g[i][j]);
		}
	}
	v(int) path;
	hamCycle (0, path);
	v(int)::itr it = path.begin();
	while (it != path.end()) {
		cout<<*it<<" ";
		it++;
	}
	cout<<endl;
	return 0;
}
