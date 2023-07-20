#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include<queue>
using namespace std;
typedef long long int ll;
typedef vector< int > vi;
typedef pair< int, int > ii;
typedef vector< ii > vii;
typedef vector< ll > vll;
// #define DEBUG_MODE
#ifdef DEBUG_MODE
    #define errp(...) fprintf(stderr, __VA_ARGS__)
    #define dbg(x) fprintf(stderr, "[%s = %d]\n", #x, x)
#else
    #define errp(...)
    #define dbg(x) 
#endif

int main () { 
#ifdef DEBUG_MODE
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
#endif
    int tst;
    scanf("%d",&tst);
    for(int x=0;x<tst;x++)
    { dbg(x);
      if(x)printf("\n");
      int n,m,t;
      scanf("%d %d %d",&n,&t,&m);
      vector<queue<ii>> c(2);
      int d;
      int arrt[m];
      char s[100];
      for(int i=0;i<m;i++)
      {
            scanf("%d %s",&d,s);
            if(s[0]=='l')c[0].push(ii(i,d));
            else c[1].push(ii(i,d));
      }
      int time=0;
      int flg=0;
      while(!(c[0].empty() && c[1].empty()))
      {     
            int et=numeric_limits<int>::max();
            if(!c[0].empty())
            {
                  et=c[0].front().second;
            }
            if(!c[1].empty())
            {
                  et=min(et,c[1].front().second);
            }
            int carcount=0;
            dbg(et);
            time=max(time,et);
            while(!c[flg].empty() && carcount<n && c[flg].front().second<=time)
            {
                  arrt[c[flg].front().first]=time+t;
                  c[flg].pop();
                  carcount++;
            }
            flg=1-flg;
            time+=t;
      }
      for(int i=0;i<m;i++)
      printf("%d\n",arrt[i]);
    }
}


