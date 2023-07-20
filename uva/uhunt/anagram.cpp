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
    char s[1000100];
    int c=0;
    while(scanf("%s",&s))
    { c++;
      int cnt=0,cnt1=0;
      int f[26];
      if(strcmp(s,"end")==0)break;
      for(int i=0;i<strlen(s)-1;i++)
      {
            if(s[i]<s[i+1])cnt++;
      }
      for(int i=0;i<strlen(s);i++)f[s[i]-'A'];
      for(int i=0;i<26;i++)if(f[i]>0)cnt1++;
            if(cnt1<cnt)cnt=cnt1;
      printf("Case %d: %d\n",c,cnt);
}
}
