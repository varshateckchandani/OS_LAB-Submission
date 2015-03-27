/* Memory Management
Referenced with Shikhar Pandya(121050)*/
#include<stdio.h>
void first_fit(int ps[],int np,int ms[],int nm)
{
	int i,j,int_frag,ext_frag,flag[30]={0};
	int_frag=ext_frag=0;
	for(i=0;i<np;i++)
	{
		for(j=0;j<nm;j++)
		{
			if(flag[j]==0 && ms[j]>=ps[i])
			{
				flag[j]=1;
				int_frag=int_frag+ms[j]-ps[i];
				break;
			}
		}
		if(j==nm)
			printf("\n\nTHERE IS NO SPACE FOR PROCESS %d ",i);
	}
	for(i=0;i<nm;i++)
	{
		if(flag[i]==0)
			ext_frag=ext_frag+ms[i];
	}
	
	printf("\nTotal Internal Fragmentation = %d ",int_frag);
	printf("\nTotal External Fragmentation = %d ",ext_frag);

}
void best_fit(int ps[],int np,int ms[],int nm)
{
	int i,j,ivar=0,int_frag=0,ext_frag=0,temp[30],flag[30]={0};
	
	for(i=0;i<nm;i++)
		temp[i]=ms[i];
	for(i=0;i<nm-1;i++)
	{
		for(j=0;j<nm-1;j++)
		{
			if(temp[j]>temp[j+1])
			{
				ivar=temp[j];
				temp[j]=temp[j+1];
				temp[j+1]=ivar;
			}
		}
	}
	for(i=0;i<np;i++)
	{
		for(j=0;j<nm;j++)
		{
			if(flag[j]==0 && temp[j]>=ps[i])
			{
				flag[j]=1;
				int_frag=int_frag+temp[j]-ps[i];
				break;
			}
		}
		if(j==nm)
			printf("\n\nTHERE IS NO SPACE FOR PROCESS %d ",i);
	}
	for(i=0;i<nm;i++)
	{
		if(flag[i]==0)
			ext_frag=ext_frag+temp[i];
	}

	printf("\nTotal Internal Fragmentation = %d ",int_frag);
	printf("\nTotal External Fragmentation = %d ",ext_frag);
}
void main()
{
	int ichoice,np,nm,ps[30],ms[30],i;
	printf("\nEnter number of memory blocks available:");
	scanf("%d",&nm);
	printf("\nEnter sizes of memory blocks available:");
	for(i=0;i<nm;i++)
	{
		scanf("%d",&ms[i]);
	}
	printf("\nEnter number of Processes:");
	scanf("%d",&np);
	printf("\nEnter sizes of Processes:");
	for(i=0;i<np;i++)
	{
		scanf("%d",&ps[i]);
	}
	while(1)
	{
		printf("\n1.Best FIT");
		printf("\n2.First FIT");
		printf("\n3.Exit");

		printf("\n\nEnter your choice:");
		scanf("%d",&ichoice);
		switch(ichoice)
		{
			case 1:
				printf("\nBest Fit:\n");
				best_fit(ps,np,ms,nm);
				break;
			case 2:
				printf("\nFirst Fit:\n");
				first_fit(ps,np,ms,nm);
				break;
			case 3:
				exit(0);
			default:
				printf("\nInvalid choice!!!");
		}
		
	}
}
