#include<stdio.h>
#include<stdlib.h>
int selsort(int *a, int n)
{
	int i,j,min,tmp,count=0;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			count++;
			if(*(a+j)<*(a+min))
			{
				min=j;
			}
			tmp=*(a+min);
			*(a+min)=*(a+i);
			*(a+i)=tmp;
		}
	}
	return count;
}

int main()
{
	int *a,n,i;
	FILE *f;
	f=fopen("selsort.txt","a");
	printf("Enter array size: ");
	scanf("%d",&n);
	a=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		*(a+i)=rand()%(n*10);
	}
	fprintf(f,"%d %d\n",n,selsort(a,n));
	fclose(f);
	free(a);
	return 0;
}
