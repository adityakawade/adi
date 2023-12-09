#include<iostream>
using namespace std;

# define n 5
class circularqueueu{

private:
    int *arr;
    int front;
    int rear;
public:
    circularqueueu()
    {
        front=-1;
        rear=-1;
        arr=new int[n];   
    }

    bool is_full()
    {
       return   ((front==0 && rear==n-1) ||(rear==front-1));
    }

    bool is_empty()
    {
        return  (front==-1 && rear==-1);
    }




    void enqueue(int x)
    {


        if (is_full())
        {
           cout<<"queue is overflow"<<endl;
           return;
        }
        if (front==-1)
        {
            front=0;
            rear=0;
        }
        else{
            if (rear==n-1)
            {
                rear=0;
            }
            else{
                rear++;
            }
        }  
        arr[rear]=x;
        // cout<<"your "<<rear<<" pizza order is"<<arr[rear]<<endl;
        
    }

    void dequeue()
    {

        // cout<<"your"<<"  "<<front <<" "<<"pizza order is deleted"<<endl;
        if (is_empty())
        {
            cout<<"queue is empty"<<endl;
            return;
        }
        else if (front==rear)
        {
            front=-1;
            rear=-1;
        }

        else{
            if (front==n-1)
            {
                front=0;
            }
            else{
                front++;
            }
        }

        
        
    }



    void display()
    {
        if(front<rear){
        for (int i = front; i <= rear; i++)
        {
           cout<<arr[i]<<" ";
        }
        }
        else if (front==rear)
        {
           cout<<arr[front];
        }

        else{
            for (int i = front; i < n; i++)
            {
                cout<<arr[i]<<" ";
            }

            for (int i = 0; i <= rear; i++)
            {
                cout<<arr[i]<<" ";
            }   
        }
    }


};
int main(){
    circularqueueu obj;
    obj.enqueue(1);
    obj.enqueue(2);
    obj.enqueue(3);
    obj.enqueue(4);
    obj.enqueue(5);
    obj.dequeue();

    obj.display();
    return 0;
}