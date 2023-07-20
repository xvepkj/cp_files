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
/* ---------------------------------------------- */
#define DBGMODE
#ifdef DBGMODE
	#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
	#define debug(...)
#endif
bitset<1000001> ha;
int main() {
      int n,m;
      while(true)
      {     scanf("%d %d",&n,&m);
            if((n+m)==0)break;
            ha.reset();
            int tr=0;
            int s[n],e[n],r1[m],s1[m],e1[m];
            for(int i=0;i<n;i++)
            {
                  scanf("%d",&s[i]);
                  scanf("%d",&e[i]);
            }
            for(int i=0;i<n;i++){
                    for(int j=s[i]+1;j<=e[i];j++)
                        {if(ha.test(j)){printf("CONFLICT\n");tr=1;break;}
                        else ha.set(j);}
                        if(tr==1)break;
            }
            for(int i=0;i<m;i++)
            {
                  scanf("%d",&s1[i]);
                  scanf("%d",&e1[i]);
                  scanf("%d",&r1[i]);
            }
            if(tr==0){
            for(int i=0;i<m;i++)
            {
                  while(s1[i]<1000000)
                  {
                        for(int j=s1[i]+1;j<=e1[i];j++)
                        {
                              if(ha.test(j)){printf("CONFLICT\n");tr=1;}
                              else ha.set(j);
                              if(tr==1)break;
                        }
                        if(tr==1)break;
                        s1[i]+=r1[i];
                        e1[i]=min(e1[i]+r1[i],1000000);
                  }
                  if(tr==1)break;
            }}
            if(tr==0)printf("NO CONFLICT\n");
      }     
}
