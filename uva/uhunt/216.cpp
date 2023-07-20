/*So for this problem,it's travelling salesman problem but we also have to find the order that the 
computers are connected in.
As the number of computer is-> 2<=n<=8.
So we can always try all possible orders as 8!=40K which is not that big.Even for 10 test cases that is
400K.
So a brute force solution will do.PKJ out.*/
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
int x[10];
int y[10];
int p[10];
int t,n;
int a[10];
int main() { 
#ifdef DEBUG_MODE
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
#endif
    t=0;
    while(scanf("%d",&n),n){
        t++;
        for(int i=0;i<n;i++){
            scanf("%d %d",&x[i],&y[i]);
            p[i]=i;
        }
        double tmp;
        double mn=200000000;
        do{
            double sum=0;
            for(int i=1;i<n;i++){
                tmp=sqrt((x[p[i]]-x[p[i-1]])*(x[p[i]]-x[p[i-1]])+(y[p[i]]-y[p[i-1]])*(y[p[i]]-y[p[i-1]]));
                sum+=tmp;
            }
            if(sum<mn){
                mn=sum;
                for(int i=0;i<n;i++)a[i]=p[i];
            }
        }while(next_permutation(p,p+n));
        printf("**********************************************************\n");
        printf("Network #%d\n",t);
        for(int i=1;i<n;i++){
            tmp=sqrt((x[a[i]]-x[a[i-1]])*(x[a[i]]-x[a[i-1]])+(y[a[i]]-y[a[i-1]])*(y[a[i]]-y[a[i-1]]));
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n",x[a[i-1]],y[a[i-1]],x[a[i]],y[a[i]],tmp+16);
        }
        printf("Number of feet of cable required is %.2f.\n",mn+(16*(n-1)));
    }

}
