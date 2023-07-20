#include <cstdio>
#include <cstring>
#include <cassert>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
#include <map>
#include <set>
using namespace std;
typedef long long int ll;
typedef vector< int > vi;
typedef pair< int, int > ii;
typedef vector< ii > vii;
typedef vector< ll > vll;
#ifdef XVENOM
	#define errp(...) fprintf(stderr, __VA_ARGS__)
#else
	#define errp(...)
#endif
#define dbg(x) errp("%s = %s\n", #x, to_string(x).data())
string to_string (string s) { return "\"" + s + "\""; }
template<typename T> string to_string (vector<T>);
template<typename U, typename V> string to_string (pair<U, V> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template<typename T> string to_string (vector<T> v) {
	string res = "["; for (int i = 0; i < (int)v.size()-1; i++) res += to_string(v[i]) + ", ";
	if (!v.empty()) res += to_string(v.back());	res += "]"; return res; }
int r,c,n,x,y,z,sx,sy,dx,dy;
int d[1010][1010];
int main () { 
#ifdef XVENOM
	freopen("inp.txt", "r", stdin);
	freopen("oup.txt", "w", stdout);
#endif
	while(scanf("%d %d",&r,&c),(r+c)){
        memset(d,-1,sizeof d);
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d %d",&x,&y);
            while(y--){
                scanf("%d",&z);
                d[x][z]=300000;
            }
        }
        scanf("%d %d",&sx,&sy);
        scanf("%d %d",&dx,&dy);
        queue<ii> Q;
        Q.push(ii(sx,sy));
        d[sx][sy]=0;
        while(!Q.empty()){
            ii h=Q.front();
            int u=h.first;
            int v=h.second;
            Q.pop();
            if(u>0 && d[u-1][v]<0){Q.push(ii(u-1,v));d[u-1][v]=d[u][v]+1;}
            if(v>0 && d[u][v-1]<0){Q.push(ii(u,v-1));d[u][v-1]=d[u][v]+1;}
            if(u<(r-1) && d[u+1][v]<0){Q.push(ii(u+1,v));d[u+1][v]=d[u][v]+1;}
            if(v<(c-1) && d[u][v+1]<0){Q.push(ii(u,v+1));d[u][v+1]=d[u][v]+1;}
        }
        printf("%d\n",d[dx][dy]);
    }
}