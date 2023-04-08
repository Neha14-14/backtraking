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

int board[1000][1000];
int N;

bool is_safe (int x, int y) {
	int i, j;
	for (i = 0; i < N; i++) {
		if (board[x][i] == 1) {
			return false;
		}
	}
	for (i = 0; i < N; i++) {
		if (board[i][y] == 1) {
			return false;
		}
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
				if (i+j == x + y && board[i][j] == 1) {
					return false;
				}
				if (i-j == x-y && board[i][j] == 1) { // not abs(i-j) == abs(x-y) remember why?
					return false;
				}
		}
	}
	return true;
}

bool n_queens (int n) {
	if (n <= 0) {
		return true;
	}
	int i, j;
	i = N-n;
	//for (i = 0; i < N; i++)
	for (j = 0; j < N; j++) {
		if (is_safe(i, j)) {
			board[i][j] = 1;
			if (n_queens(n-1)){
				return true;
			}
			board[i][j] = 0;
		}
	}
	return false;
}



int main (void) {

	sc (N);
	//N = n;
	//int board[n][n];
	mem(board, 0);

	int i, j;
	if (n_queens(N))
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
				cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}else {
		cout<<"Not Possible"<<endl;
	}
	return 0;
}
