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

int maze[100][100];
int N;

bool f[1000][1000];
v(string) v;

int xmove[4] = {-1, 0, 1, 0};
int ymove[4] = {0, -1, 0, 1};

bool isRight (int x, int y) {
	if (0<= x && x < N && 0<= y && y < N && maze[x][y] == 1 && !f[x][y]) {
		return true;
	}
	return false;
}

void allpaths (int x, int y, string s) {
	if (x >= N || x < 0) {
		return ;
	}
	if (y >= N || y < 0) {
		return ;
	}
	if (x == N-1 && y == N-1) {
		v.psh(s);
	}
	int xx, yy;
	for (int i = 0; i < 4; i++) {
		xx = x + xmove[i];
		yy = y + ymove[i];
		if (isRight (xx, yy)) {
			f[x][y] = true;
			switch (i) {
				case 0:
					s = s + "U";
					break;
				case 1:
					s = s + "L";
					break;
				case 2:
					s = s + "D";
					break;
				case 3:
					s = s + "R";
					break;
			}
			allpaths (xx, yy, s);
			f[x][y] = false;
		}
	}
}

int main (void) {
	sc (N);
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			sc (maze[i][j]);
		}
	}
	string s;
	allpaths(0, 0, s);
	v(string) :: itr iit;
	iit = v.begin();
	while (iit != v.end()) {
		cout<<*iit<<endl;
		iit++;
	}
	return 0;
}
