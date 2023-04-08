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

string s;
int N;
void permute (int n, int * state, v(int) v) {
	if (n == 0) {
		v(int)::itr iit = v.begin();
		while (iit != v.end()) {
			cout<<s[*iit];
			iit++;
		}
		cout<<endl;
		return ;
	}
	for (int i = 0; i < N; i++) {
		if (state[i] == 0) {
			state[i] = 1;
			v.psh(i);
			permute (n-1, state, v);
			state[i] = 0;
			v.pop_back();
		}
	}
	return ;
}


int main (void) {
	cin>>s;
	N = s.size();
	int state[N];
	mem(state, 0);
	v(int) v;
	permute (N, state, v);
	return 0;
}
