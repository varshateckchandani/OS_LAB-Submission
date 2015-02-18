/*
 * C Program to Implement a Queue using an Array
 * Reference : Juhi Maheshwari Erali Shah Shikhar Pandya
 */
 // status_id = 1 for blocked process
#include <stdio.h>
#define MAX 50


int queue_elements[MAX];
int queue_process[MAX];
int rear = - 1,rear_process=-1;
int front = - 1, front_process=-1;
int status_id = 1;
int item;

typedef struct{
    int value;
}binary_semaphore;

binary_semaphore s;

void semWaitB(){
    if(s.value == 1){
        s.value = 0;
        printf("In if of wait %d\n",s.value);
    }
    else{
        printf("In else of wait \n");
        insert_process(rand());
        display_process();
        
    }
}

void semSignalB(){
    int ready_process;
    if(front_process == - 1 || front_process > rear_process){ // queue is empty
        s.value = 0;
        printf("In if of signal %d\n",s.value);
    }
    else{
            printf("in else of signal\n");
            ready_process = delete_process();
            display_process();
            
    }
}

/*Producer consumer problem*/
int n;
//binary_semaphore s = 1,delay = 0;
void producer( binary_semaphore delay){
    int item;
   
    
        item=rand();
        semWaitB(s);
        if(s.value == 0){
            insert(item);
            printf("in if");
            display();
        }
        n++;
        if(n==1)
        semSignalB(delay);
        semSignalB(s);
     
    

}

void consumer(binary_semaphore delay){
    int m;
    semWaitB(s);
    delete();
    n--;
    m=n;
    semSignalB(s);
    if(m==0)
    semWaitB(delay);
}

/*Producer consumer end*/

insert(int add_item)
{
    
    if (rear == MAX - 1)
    printf("Queue Overflow \n");
    else
    {
        if (front == - 1)
        /*If queue is initially empty */
        front = 0;
        
        rear = rear + 1;
        queue_elements[rear] = add_item;
    }
} /*End of insert()*/
delete()
{
    int ready_element;
    if (front == - 1 || front > rear)
    {
        printf("Queue Underflow \n");
        return ;
    }
    else
    {
        ready_element = queue_elements[front];   
        printf("Element deleted from queue is : %d\n", queue_elements[front]);
        front = front + 1;
    }
    return ready_element;
} /*End of delete() */
display()
{
    int i;
    if (front == - 1)
        printf("Queue of element is empty \n");
    else
    {
        printf("Element Queue is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue_elements[i]);
        printf("\n");
    }
} /*End of display() */


/*for process*/
insert_process(int add_item)
{
    
    if (rear_process == MAX - 1)
    printf("Queue Overflow \n");
    else
    {
        if (front_process == - 1)
        /*If queue is initially empty */
        front_process = 0;
        
        rear_process = rear_process + 1;
        queue_process[rear_process] = add_item;
    }
} /*End of insert()*/
delete_process()
{
    int ready_process;
    if (front_process == - 1 || front_process > rear_process)
    {
        printf("Queue Underflow \n");
        return ;
    }
    else
    {
        ready_process = queue_process[front_process];   
        printf("_process deleted from queue is : %d\n", queue_process[front_process]);
        front_process = front_process + 1;
    }
    return ready_process;
} /*End of delete() */
display_process()
{
    int i;
    if (front_process == - 1 || front_process > rear_process)
        printf("Process Queue is empty \n");
    else
    {
        printf("Process Queue is : \n");
        for (i = front_process; i <= rear_process; i++)
            printf("%d ", queue_process[i]);
        printf("\n");
    }
} /*End of display() */


/**/






main()
{
    n=0;
    //binary_semaphore s;
    binary_semaphore d;
    s.value=1;
    int i=1;
    insert(555);
    while(i<6){
        if(i%2==1){
            printf("producer\n");
            producer(d);
        }
        else if((front_process != - 1 || front_process > rear_process) && front != -1){
            printf("Consumer\n");
            consumer(d);
        }
        else{
            printf("do nothing\n");
        } 
        i++;    
    }    
    //exit(1);
    
    
} /*End of main()*/
