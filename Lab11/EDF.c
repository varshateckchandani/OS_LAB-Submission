/*Inputs:Number of processes,Release time, Deadline, Execution time of each process.*/

/*Referenced with Shikhar Pandya - 121050*/

#include<stdio.h>

int n,p_bt[100],p_id[100],p_dt[100];

void time()
{
     int wt[n],tat[n];
     float totalWait=0,totalTat=0;
     int i;
     wt[0]=0;
     tat[-1]=0;
     printf("***************  WAITING TIME FOR EACH JOB  ***************\n");
     for( i=1; i<n; i++)
     {
	printf("Job %d: %d\n",i, wt[i-1]);
           wt[i]=p_bt[i-1]+wt[i-1];
           
           totalWait=wt[i]+totalWait;
     }
    printf("Job %d: %d\n",i, wt[i-1]);
      for( i=0; i<n; i++)
     {
             tat[i]=p_bt[i]+tat[i-1];               
             totalTat=totalTat+tat[i];
     }
     printf("\nTotal Waiting time = %f",totalWait);
     printf("\nTotal Turn Around Time= %f\n",totalTat);
}


void sortByDeadlineTime(){
	
    int i, j, temp;
    
    for (i = 0; i < (n - 1); ++i)
     {
          for (j = 0; j < (n - 1 - i); ++j )
          {
               if (p_dt[j] > p_dt[j+1])
               {
                    temp=p_bt[j+1];
                    p_bt[j+1] = p_bt[j];
                    p_bt[j] = temp;
                    
                    temp=p_dt[j+1];
                    p_dt[j+1] = p_dt[j];
                    p_dt[j] = temp;
                    
                    temp=p_id[j+1];
                    p_id[j+1] = p_id[j];
                    p_id[j] = temp;
                    
               }
          }
     }
}


int main()
{
    int i;
    printf("***************  SHORTEST JOB FIRST SCHEDULING  ***************\n\n");

    printf("Enter the number of process: ");
    scanf("%d",&n);  
    for( i=0; i<n; i++)
    {
          printf("Enter process %d execution time: ",i+1);
          scanf("%d",&p_bt[i]);
          printf("Enter process %d Deadline: ",i+1);
          scanf("%d",&p_dt[i]);
       	  p_id[i]=i;
         
    }
    sortByDeadlineTime();
    printf("\nProcess ExecutionTime \n");
    for( i=0; i<n; i++)
     {
             printf("   %d   \t%d\n",p_id[i]+1,p_bt[i]);
     }
    time();
 }
