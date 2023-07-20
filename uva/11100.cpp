#include <cstdio>
#include<iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include<stack>
#include <map>
#include <set>
#include<queue>
#include<bitset>
using namespace std;
typedef long long int ll;
typedef vector< int > vi;
typedef pair< int, int > ii;
typedef vector< ii > vii;
typedef vector< ll > vll;
#define isOn(S, j) (S & (1 << j))
#define DEBUG_MODE
#ifdef DEBUG_MODE
    #define errp(...) fprintf(stderr, __VA_ARGS__)
    #define dbg(x) fprintf(stderr, "[%s = %d]\n", #x, x)
#else
    #define errp(...)
    #define dbg(x) 
#endif
int numbers[10];          
void genNumbers() {
    memset(numbers, 0, sizeof numbers);
    // Zero
    for (int i=0 ; i<6 ; i++)
        numbers[0] |= (1 << i);
    // One
    numbers[1] |= (1 << 1);
    numbers[1] |= (1 << 2);
    // Two 
    numbers[2] |= (1 << 0);
    numbers[2] |= (1 << 1);
    numbers[2] |= (1 << 3);
    numbers[2] |= (1 << 4);
    numbers[2] |= (1 << 6);
    // Three
    for (int i=0 ; i<4 ; i++)
        numbers[3] |= (1 << i);
    numbers[3] |= (1 << 6);
    // Four
    numbers[4] |= (1 << 1);
    numbers[4] |= (1 << 2);
    numbers[4] |= (1 << 5);
    numbers[4] |= (1 << 6);
    // Five
    numbers[5] |= (1 << 0);
    numbers[5] |= (1 << 2);
    numbers[5] |= (1 << 3);
    numbers[5] |= (1 << 5);
    numbers[5] |= (1 << 6);
    // Six
    numbers[6] |= (1 << 0);
    for (int i=2 ; i<7 ; i++)
        numbers[6] |= (1 << i);
    // Seven
    numbers[7] |= (1 << 0);
    numbers[7] |= (1 << 1);
    numbers[7] |= (1 << 2);
    // Eight
    for (int i=0 ; i<7 ; i++)
        numbers[8] |= (1 << i);
    // Nine
    for (int i=0 ; i<4 ; i++)
        numbers[9] |= (1 << i);
    numbers[9] |= (1 << 5);
    numbers[9] |= (1 << 6);
}
int main () { 
  genNumbers();
  int n;
  while(scanf("%d",&n)==1 && n){
    int a[n];
    memset(a,0,sizeof a);
    char x[7];
    for(int i=0;i<n;i++)
    { 
      scanf("%s",x);
      for(int j=0;j<7;j++){
        if(x[j]=='Y')
        a[i] |= (1 << j);
      }
    }
    int bad[10];
    memset(bad,0,sizeof bad);
    bool tog=false;
    for(int i=9;i>=n-1;i--)
    {
      int bad[10];
      memset(bad,0,sizeof bad);
      int j;
      for(j=0;j<n;j++){
          int k;
          for(k=0;k<7;k++){
            if(isOn(a[j],k) && bad[k])
              break;
            if(isOn(numbers[i-j],k) && !isOn(a[j],k))
              bad[k]=1;
            else if(!isOn(numbers[i-j],k) && isOn(a[j],k))
              break;
          }
          if(k!=7)break;
      }
      if(j==n){tog=true;break;}
    }
    if(!tog)
        printf("MIS");
    puts("MATCH");
  }
}


