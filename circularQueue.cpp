#include<iostream>
using namespace std;

class Queue
{
public:
    int front,rear;
    int size;
    int *arr;


Queue(int s=0) 
    { 
       front = rear = -1; 
       size = s; 
       arr = new int[s]; 
    } 

virtual void enQueue(int value)
{
    if ((front == 0 && rear == size-1) || 
            (rear == (front-1)%(size-1))) 
    { 
        printf("\nQueue is Full"); 
        return; 
    } 
  
    else if (front == -1)
    { 
        front = rear = 0; 
        arr[rear] = value; 
    } 
  
    else if (rear == size-1 && front != 0) 
    { 
        rear = 0; 
        arr[rear] = value; 
    } 
  
    else
    { 
        rear++; 
        arr[rear] = value; 
    } 
}


virtual int deQueue()
{
    if (front == -1) 
    { 
        printf("\nQueue is Empty"); 
        return 0; 
    } 
  
    int data = arr[front]; 
    arr[front] = -1; 
    if (front == rear) 
    { 
        front = -1; 
        rear = -1; 
    } 
    else if (front == size-1) 
        front = 0; 
    else
        front++; 
  
    return data; 
}
virtual void displayQueue() 
{
    if (front == -1) 
    { 
        printf("\nQueue is Empty"); 
        return; 
    } 
    printf("\nElements in Circular Queue are: "); 
    if (rear >= front) 
    { 
        for (int i = front; i <= rear; i++) 
            printf("%d ",arr[i]); 
    } 
    else
    { 
        for (int i = front; i < size; i++) 
            printf("%d ", arr[i]); 
  
        for (int i = 0; i <= rear; i++) 
            printf("%d ", arr[i]); 
    } 
}

};



class doubleQueue : public Queue
{


    bool compare(const Queue *q)
    {
        if(q->front == this->front && q->rear == this->front )
            return true;
        return false;
    }

    doubleQueue(int size =0)
    {
        this->front = -1;
        this->rear = 0;
        this->size = size;
    }
    void enQueue(int val)
    {
        if (front == -1) 
        { 
            front = 0; 
            rear = 0; 
        } 
        else if (front == 0) 
            front = size - 1 ; 
  
        else 
           Queue::enQueue(val);
    

    }

    
    int deQueue()
    {
        if (front == -1) 
        { 
            front = 0; 
            rear = 0; 
        } 
  
        else if (rear == size-1) 
            rear = 0; 

        else 
            return Queue::deQueue();   
    }


};