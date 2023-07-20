/*PKJ*/
// #define DEBUG_MODE
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
#ifdef DEBUG_MODE
    #define errp(...) fprintf(stderr, __VA_ARGS__)
#else
    #define errp(...)
#endif
#define dbg(x) errp("[%s = %s]\n", #x, to_string(x).data())
int INF=1e8;
char a[105][105];
int t;
int n;
void dfs(int x,int y){
    if(x<0 || y<0 || x>=n || y>=n)return;
    if(a[x][y]=='.')return;
    a[x][y]='.';
    dfs(x-1,y);
    dfs(x,y-1);
    dfs(x+1,y);
    dfs(x,y+1);
}
int main() { 
#ifdef DEBUG_MODE
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
#endif
    scanf("%d",&t);
    int l=0;
    while(t--){
        l++;
        scanf("%d",&n);
        int tots=0;
        for(int i=0;i<n;i++)scanf("%s",a[i]);
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                {
                    if(a[i][j]=='x'){tots++;
                    dfs(i,j);}
                }
        printf("Case %d: %d\n",l,tots);
    }
}