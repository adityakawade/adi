#include<iostream>
using namespace std;
#define SIZE 10
class job_queue{
private:
     int q[SIZE];
     int front;
     int rear;
public:
     job_queue()
     {
        front=0;
        rear=-1;
     }

     bool is_empty()
     {
        if (rear<front)
        {
          cout<<"job queue is empty"<<endl;
        }
      
        
     }

     bool is_full()
     {
        if (rear==SIZE-1)
        {
           cout<<"job queue is full"<<endl;
        }
        

     }

     void enqueue(int id)
     {
        if (!is_full())
        {
           rear++;
           q[rear]=id;
           cout<<"job addad to queue"<<endl;
        }
        else{
            cout<<"job queue is full cant be addad"<<endl;
        }
        
     }

     int dequeue()
     {
        int x;

       if (!is_empty())
       {
           x=q[front];
           front++;
           return x;
       }
       else{
        cout<<"job queue is empty"<<endl;
       }
       
     }

     void display()
     {
        for (int i = front; i <rear-1; i++)
        {
            cout<<q[i]<<endl;
        }
        
     }
};

int main(){
    job_queue jq;
    int id;
    cout<<"enter job id to insert"<<endl;
    cin>>id;
    jq.enqueue(id);
    cout<<"enter job id to insert"<<endl;
    cin>>id;
    jq.enqueue(id);
    cout<<"enter job id to insert"<<endl;
    cin>>id;
    jq.enqueue(id);
    jq.display();
    id=jq.dequeue();
    cout<<"\n deleted id is"<<id;
    jq.display();
    id=jq.dequeue();
    cout<<"\n deleted id is"<<id;
    jq.display();

    id=jq.dequeue();
    cout<<"\n deleted id is"<<id;
    return 0;
}