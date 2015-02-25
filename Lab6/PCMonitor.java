/*Referenced with - Shikhar Pandya 121050*/
//Solution to Producer Consumer problem using Monitor.

class get_put {
int n;
 
synchronized int get() {
    try {
        notify(); //consumer notifies producer that it is getting the resource 
        wait();   // Wait signal sent for mutual exclusion
    } catch (InterruptedException e) {
        System.out.println("InterruptedException found"); //In case of exception i.e. notif and wait not sent
    }
    System.out.println("Got: " + n); // Printing for checking purpose
    return n; 
}
 
synchronized void put(int n) {
    try {
        notify(); //producer notifies the consumer that it is putting the resource
        wait();  // Wait signal to ensure mutual exclusion
    } catch (InterruptedException e) {
        System.out.println("InterruptedException found"); //In case of exception i.e. notif and wait not sent
    }
    this.n = n;
    System.out.println("Put: " + n); //Printing for checking purpose
    }
}
 
class Producer implements Runnable {
get_put q;
 
Producer(get_put q) {
    this.q = q;
    new Thread(this, "Producer").start(); //start the producer i.e. will initialize threads and cal run function
}
 
public void run() {
    int i = 10;
    while (i<15) {
    q.put((i++) % 3); //call put function to put the values in it when producer wants
    }
}
}
 
class Consumer implements Runnable {
get_put q;
 
Consumer(get_put q) {
    this.q = q;
    new Thread(this, "Consumer").start(); //start the consumer i.e. will initialize the threads and call the rn function
}
 
public void run() {
    while (true) {
    q.get(); //call the get function to get the values inserted by producer
    }
}
}
 
class PCMonitor {
public static void main(String args[]) {
    get_put q = new get_put();
    new Producer(q); //call producer
    new Consumer(q); //call consumer
  
}
}
