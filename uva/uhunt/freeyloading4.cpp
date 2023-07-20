#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
#include<cstring>
#include<vector>
#include<bitset>
#include<stack>
#include<queue>
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
int main() {
    int n,m;
    int t;
    scanf("%d",&t);
    for(int x=0;x<t;x++)
    { char s[100];
      int a; 
      scanf("%d %d",&n,&m);
      n=n*100;    
      queue<int> l,r;
      for(int i=0;i<m;i++)
      {
            scanf("%d %s",&a,s);
            if(s[0]=='l')
                  l.push(a);
            else r.push(a);
      }
      int sum=0,cnt=0;
      int tgl=1;
      while(!l.empty() || !r.empty())
      {     cnt++;
            sum=0;
            if(tgl)
            {
                  while(!l.empty() && sum+l.front()<=n)
                        {sum+=l.front();l.pop();}
            }
            else{
                  while(!r.empty() && sum+r.front()<=n)
                        {sum+=r.front();r.pop();}
            }
            tgl=1-tgl;
      }
      printf("%d\n",cnt);
}
}

