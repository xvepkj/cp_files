#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
#include<cstring>
#include<vector>
#include<bitset>
#include<stack>
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
     int n;
     while(true)
     {
      scanf("%d",&n);
      if(n==0)break;
      int a[n];
      while(true){
      scanf("%d",&a[0]);
      int ptr=0;
      stack<int> s;
      if(a[0]==0){printf("\n");break;}
      for(int i=1;i<n;i++)scanf("%d",&a[i]);
      for(int i=1;i<=n;i++)
      {
            s.push(i);
            while(!s.empty())
            {
                  if(s.top()==a[ptr])
                  {
                        s.pop();ptr++;
                  }
                  else break;
            }
            }
         if(s.empty())printf("%s\n","Yes");
         else printf("%s\n","No");
      }
      }
     
}
