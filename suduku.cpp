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

int board[9][9];

bool is_safe (int x, int y, int num) {
	int i = x/3;
	int j = y/3;
	int cnt[10] = {0};

	for (int b = i; b < i+3; b++) {
		for (int a = j; a < j+3; a++) {
			cnt[board[b][a]]++;
		}
	}
	for (i = 1; i <= 9; i++) {
		if (cnt[i] > 1) {
			return false;
		}
	}

	mem(cnt, 0);
	for (i = 0; i < 9; i++) {
		cnt[board[x][i]]++;
	}
	for (i = 1; i <= 9; i++) {
		if (cnt[i] > 1) {
			return false;
		}
	}

	mem(cnt, 0);
	for (i = 0; i < 9; i++) {
		cnt[board[i][y]]++;
	}
	for (i = 1; i <= 9; i++) {
		if (cnt[i] > 1) {
			return false;
		}
	}

	return true;
}

bool solve (int x, int y) {
	int i, j;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			if (board[i][j] == 0) {
				for (int k = 1; k <= 9; k++) {
					if (is_safe(i,j,k)) {
						board[i][j] = k;
						if (solve(i, j)) {
							return true;
						}
						board[i][j] = 0;
					}
				}
			}
		}
	}
	return false;
}

int main (void) {
	freopen("input.in", "r", stdin);
	solve(0, 0);

	return 0;
}
