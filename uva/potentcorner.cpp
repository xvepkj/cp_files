#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
#include<cstring>
#include<vector>
#include<bitset>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000
using namespace std;
/* ---------------------------------------------- */
#define DBGMODE
#ifdef DBGMODE
	#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
	#define debug(...)
#endif

int main() {
      int n,m;
      while(scanf("%d","%d",&n,&m)==2 && (n+m)!=0)
      {     int tr=0;
            bitset<1000000> ha(0);
            int s,e,r;
            for(int i=0;i<n;i++)
            {
                  scanf("%d",&s);
                  scanf("%d",&e);
                  for(int j=s+1;j<e;j++)
                        if(ha.test(j)){printf("CONFLICT");tr=1;break;}
                        else ha.set(j);
            }
            for(int i=0;i<m;i++)
            {
                  scanf("%d",&s);
                  scanf("%d",&e);
                  scanf("%d",&r);
                  int h=0;
                  while(h<e)
                  {
                        for(int j=s+1;j<e;j++)
                        {
                              if(ha.test(h+j)){printf("CONFLICT");tr=1;break;}
                              else ha.set(h+j);
                        }
                        h+=r;
                  }
            }
            if(tr==0)printf("NO CONFLICT");
      }     
}
