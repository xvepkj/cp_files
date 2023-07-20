#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef long long int ll;
typedef vector< int > vi;
typedef pair< int, int > ii;
typedef vector< ii > vii;
typedef vector< ll > vll;
 // #define DEBUG_MODE
#ifdef DEBUG_MODE
	#define errp(...) fprintf(stderr, __VA_ARGS__)
#else
	#define errp(...)
#endif
#define dbg(x) errp("[%s = %s]\n", #x, to_string(x).data())

ll n, tc, q;
vll a, seg, upd;

inline int left (int x) { return (x << 1); }
inline int right (int x) { return (x << 1) + 1; }

ll rsq (int i, int j, int L, int R, int k) {
	if (i <= L && j >= R) return seg[k];
	if (i > R || j < L) return 0;
	return upd[k] * (min(j, R) - max(i, L) + 1) +
		rsq(i, j, L, (L + R) / 2, left(k)) + 
		rsq(i, j, (L + R) / 2 + 1, R, right(k));
}

void update (int i, int j, int L, int R, int k, ll x) {
	if (i <= L && j >= R) {
		upd[k] += x;
		seg[k] = seg[k] + x * (R - L + 1);
		return;
	}
	if (i > R || j < L) return;
	update(i, j, L, (L + R) / 2, left(k), x);
	update(i, j, (L + R) / 2 + 1, R, right(k), x);
	seg[k] += (min(j, R) - max(i, L) + 1) * x;
}

ll rsq (int i, int j) {
	return rsq(i, j, 0, n - 1, 1);
}
void update (int i, int j, ll x) {
	update(i, j, 0, n - 1, 1, x);
}

int main () { 
#ifdef DEBUG_MODE
	freopen("inp.txt", "r", stdin);
	freopen("oup.txt", "w", stdout);
#endif
	scanf("%lld", &tc);

	while (tc--) {
		scanf("%lld%lld", &n, &q);
		a.assign(n, 0);
		seg.assign(4 * n, 0);
		upd.assign(4 * n, 0);
		ll t, x, y, val;
		while (q--) {
			scanf("%lld", &t);
			if (t) {
				scanf("%lld%lld", &x, &y);
				printf("%lld\n", rsq(x - 1, y - 1));
			}
			else {
				scanf("%lld%lld%lld", &x, &y, &val);
				update(x - 1, y - 1, val);
			}
		}
	}
	
}
