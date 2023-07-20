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
char s[1000100];
vector<stack<char>> tops;
stack<char> empty;
int ats(char a)
{
      for(int j=0;j<tops.size();j++)
      {
            if(a<=tops[j].top()){
                  tops[j].push(a); 
                  return 0;
            }
      }
      tops.push_back(empty);
      tops[tops.size()-1].push(a);
      return 1;
}
int main() {
    int c=0;
    while(scanf("%s",s))
    { c++;
      tops.clear();
      int cnt=0;
      if(strcmp(s,"end")==0)break;
      for(int i=0;i<strlen(s);i++)
      {     
                  cnt+=ats(s[i]);
      }
      printf("Case %d: %d\n",c,cnt);
}
}

