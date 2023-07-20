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
int b[100100];
int c[100100];
int d[100100];
int main() { 
#ifdef DEBUG_MODE
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
#endif
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        memset(c,0,sizeof c);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)scanf("%d",&b[i]);
        for(int i=1;i<=n;i++){
            if((i-a[i])<1)x=1;
            else x=i-a[i];
            if((i+a[i])>n)y=n+1;
            else y=i+a[i]+1;
            c[x]++;
            c[y]--;
        }
        int s=0;
        for(int i=1;i<=n;i++)
        {
            s+=c[i];
            d[i]=s;
        }
        sort(d+1,d+n+1);
        sort(b+1,b+n+1);
        bool flg=true;
        for(int i=1;i<=n;i++){
            if(d[i]!=b[i]){flg=false;break;}
        }
        if(flg)printf("YES\n");
        else printf("NO\n");
    }
}
