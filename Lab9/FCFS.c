/*First Cum First Serve Scheduling*/
/*Referenced with Shikhar Pandya - 121050 */

#include<stdio.h>

int n, a[100],b[100],p_id[100];

void getdata()
{   
    char c;
    int i;
    printf("Enter the number of process: ");
    scanf("%d",&n);
    
    for( i=0; i<n; i++)
    {
          printf("Enter the %d process arrival time: ",i+1);
          scanf("%d",&a[i]);
          printf("Enter the %d process burst time: ",i+1);
          scanf("%d",&b[i]);
       	  p_id[i]=i;
         
    }
}

void display()
{
     int i;
     printf("\nPROCESS  \tBURST TIME\tARRIVAL TIME\n");
     for( i=0; i<n; i++)
     {
             printf("    %d\t\t   %d\t\t      %d\n",p_id[i]+1,b[i],a[i]);
     }
}

void waitTime()
{
     int wt[n];
     float totalWait=0;
     int i;
     wt[0]=0;
     for( i=1; i<n; i++)
     {
           wt[i]=b[i-1]-a[i]+wt[i-1];
           totalWait=wt[i]+totalWait;
     }
     printf("\nTotal Waiting time = %f",totalWait);
}

void turnAroundTime()
{
     int tat[n];
     float totalTat=0;
     int i;
     tat[-1]=0;
     for( i=0; i<n; i++)
     {
             tat[i]=b[i]-a[i]+tat[i-1];               
             totalTat=totalTat+tat[i];
     }
     printf("\nTotal Turn Around Time= %f\n",totalTat);
}

void sortByArrivalTime(){
	
    int i, j, temp;
    
    for (i = 0; i < (n - 1); ++i)
     {
          for (j = 0; j < (n - 1 - i); ++j )
          {
               if (a[j] > a[j+1])
               {
                    temp = a[j+1];
                    a[j+1] = a[j];
                    a[j] = temp;
                    
                    temp=b[j+1];
                    b[j+1] = b[j];
                    b[j] = temp;
                    
                    temp=p_id[j+1];
                    p_id[j+1] = p_id[j];
                    p_id[j] = temp;
                    
               }
          }
     }
}


int main()
{
    printf("***************  FIRST COME FIRST SERVE SCHEDULING  ***************\n\n");

    getdata();
    sortByArrivalTime();
    display();
    waitTime();
    turnAroundTime();
 }
