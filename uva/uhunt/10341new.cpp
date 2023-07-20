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

int n, m;
vi seg, upd;

inline int left (int x) { return (x << 1); }
inline int right (int x) { return (x << 1) + 1; }

int rsq (int i, int j, int L, int R, int k) {
	if (i <= L && j >= R) {
		if (upd[k]) return (R - L + 1) - seg[k];
		return seg[k];
	}
	if (i > R || j < L) return 0;
	upd[left(k)] = (upd[left(k)] + upd[k]) % 2;
	upd[right(k)] = (upd[right(k)] + upd[k]) % 2;
	if (upd[k]) seg[k] = (R - L + 1) - seg[k];
	upd[k] = 0;
	return rsq(i, j, L, (L + R) / 2, left(k)) + rsq(i, j, (L + R) / 2 + 1, R, right(k));
}

int update (int i, int j, int L, int R, int k) {
	if (i <= L && j >= R) {
		upd[k] = (upd[k] + 1) % 2;
		return (R - L + 1) - 2 * seg[k];
	}
	if (i > R || j < L) return 0;
	int r1 = update(i, j, L, (L + R) / 2, left(k));
	int r2 = update(i, j, (L + R) / 2 + 1, R, right(k));
	seg[k] += r1 + r2;
	return r1 + r2;
}

int rsq (int i, int j) {
	return rsq(i, j, 0, n - 1, 1);
}
void update (int i, int j) {
	update(i, j, 0, n - 1, 1);
}

int main () { 
#ifdef DEBUG_MODE
	freopen("inp.txt", "r", stdin);
	freopen("oup.txt", "w", stdout);
#endif

	scanf("%d%d", &n, &m);
	seg.assign(4 * n, 0);
	upd.assign(4 * n, 0);
	int s, e, t;
	while (m--) {
		scanf("%d", &t);
		scanf("%d%d", &s, &e);
		if (t) {
			printf("%d\n", rsq(s - 1, e - 1));
		}
		else {
			update(s - 1, e - 1);
		}
	}
}
