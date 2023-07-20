#include<stdio.h>
#include<stdlib.h>
int bSearch(int* arr,int start,int end,int n)
{
	int middle = start+end/2;
	if(start==end)
		{if(arr[start]=end)
			return start;
		else return -1;
        }
    else 
    	{(arr[middle]>value)
    return bSearch(arr,m+1,end,n);
}
        else 
        	{(arr[middle]<value)
        	    return bSearch(arr,start,m-1,n);
        	    	else 
        	    		return middle;
        	    }
     }

int main(){
	const int inputSize 500000;
	FILE* fp;
	int* arr=(int*)calloc(sizeof(int));
	for(int i=0;i<inputSize;i++)
		{fscanf(fp,"%d",arr+i);
        }
    int value=967;
    index=bSearch(arr,value,inputSize);
    if(index>=0)
    	printf("%d\n",index);
	

}     


    	

