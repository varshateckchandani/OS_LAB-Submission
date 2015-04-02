/*First Cum First Serve Scheduling*/
/*Referenced with Shikhar Pandya - 121050*/

#include<stdio.h>

int n, p_at[100],p_bt[100],p_id[100];

void time()
{
     int wt[n],tat[n];
     float totalWait=0,totalTat=0;
     int i;
     wt[0]=0;
     tat[-1]=0;
     for( i=1; i<n; i++)
     {

           wt[i]=p_bt[i-1]-p_at[i]+wt[i-1];
           totalWait=wt[i]+totalWait;
     }
      for( i=0; i<n; i++)
     {
             tat[i]=p_bt[i]-p_at[i]+tat[i-1];               
             totalTat=totalTat+tat[i];
     }
     printf("\nTotal Waiting time = %f",totalWait);
     printf("\nTotal Turn Around Time= %f\n",totalTat);
}


void sortByArrivalTime(){
	
    int i, j, temp;
    
    for (i = 0; i < (n - 1); ++i)
     {
          for (j = 0; j < (n - 1 - i); ++j )
          {
               if (p_at[j] > p_at[j+1])
               {
                    temp = p_at[j+1];
                    p_at[j+1] = p_at[j];
                    p_at[j] = temp;
                    
                    temp=p_bt[j+1];
                    p_bt[j+1] = p_bt[j];
                    p_bt[j] = temp;
                    
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
    printf("***************  FIRST COME FIRST SERVE SCHEDULING  ***************\n\n");

    printf("Enter the number of process: ");
    scanf("%d",&n);  
    for( i=0; i<n; i++)
    {
          printf("Enter process %d arrival time: ",i+1);
          scanf("%d",&p_at[i]);
          printf("Enter process %d burst time: ",i+1);
          scanf("%d",&p_bt[i]);
       	  p_id[i]=i;
         
    }
    sortByArrivalTime();
    time();
    printf("\nProcess  Arrival Time  Burst Time\n");
    for( i=0; i<n; i++)
     {
             printf("   %d   \t\t%d \t%d\n",p_id[i]+1,p_at[i],p_bt[i]);
     }
    
 }