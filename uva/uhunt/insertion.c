#include<stdio.h>
#include<stdlib.h>
int isprime(int x){
    int y=x/2;
    int z=1;
    for(int i=2;i<=y;i++)
        if(x%i==0)z=0;
    return z;
}
int main(){
    int a;
    while(scanf("%d",&a)==1){
        if(isprime(a))printf("YES\n");
        else printf("NO\n");
    }
}     


    	

