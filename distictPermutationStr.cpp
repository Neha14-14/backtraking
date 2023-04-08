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

void swap (string &s, int i, int j) {
	char c;
	c = s[i];
	s[i] = s[j];
	s[j] = c;
	return ;
}
int N;

void permute (string &s, int l, int r) {

	if (l == r) {
		cout<<s<<endl;
		return ;
	}

	int i;
	bool flag[26];
	mem(flag, false);
	for (i = l; i <= r; i++) {
		if(!flag[s[i]-'A']){
					swap (s, i, l);
					permute(s, l+1, r);
					swap (s, i, l);
		}
		flag[s[i]-'A'] = true;
	}
	return ;
}

int main (void) {
	cin>>s;
	N = s.size();
	permute (s, 0, N-1);
	return 0;
}
