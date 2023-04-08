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

int xmove[8] = {2, 1, -1, -2, -2, -1,  1,  2};
int ymove[8] = {1, 2,  2,  1, -1, -2, -2, -1};
int board[8][8];

bool knight (int x, int y, int n) {
	if (n > 64){
		return true;
	}
	int i;
	int xx, yy;
	for (i = 0; i < 8; i++) {
		xx = x+xmove[i];
		yy = y+ymove[i];
		if (0 <= xx && xx < 8 && 0 <= yy && yy < 8) {
			if (board[xx][yy] == 0) {
				board[xx][yy] = n;
				if (knight (xx, yy, n+1)) {
					return true;
				}else {
					board[xx][yy] = 0;
				}
			}
		}
	}
	return false;
}

int main (void) {
	mem(board, 0);
	board[0][0] = 1;
	if(knight(0, 0, 2)){
		int i, j;
		for (i = 0; i < 8; i++) {
			for (j = 0; j < 8; j++) {
				cout<<board[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}
