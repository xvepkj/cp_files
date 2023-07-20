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
int t,n,x,y;
int a[100100];
int main() { 
#ifdef DEBUG_MODE
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
#endif
    scanf("%d",&t);
    while(t--){
        ll cnt=0;
        vector<vi> l;
        l.assign(1100000,vi(0));
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        int x=0;
        l[0].push_back(0);
        for(int i=1;i<=n;i++){
            x^=a[i];
            l[x].push_back(i);
        }
        for(int i=0;i<l.size();i++){
            if(l[i].size()>1){
                ll sum=l[i][0]+1;
                for(int j=1;j<l[i].size();j++)
                {
                    cnt+=(ll)(j)*l[i][j]-sum;
                    sum+=l[i][j]+1;
                }
            }
        }
        printf("%lld\n",cnt);
  }  
}
