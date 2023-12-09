#include<iostream>
using namespace std;

class node{
  public:
    node *next;
    int data;
  
    node(int data)
    {
         this->data=data;
         next=NULL;
    }
      
};

class dequeue{

  private:
      node *head;
      node *tail;
  public:
      dequeue()
      {
        head=NULL;
        tail=NULL;
      }



      bool is_empty()
      {
        return head==NULL;
      }



      void addatfront(int data)
      {
        node *newnode= new node(data);
      
        newnode->next=NULL;
        if (is_empty())
        {
         head=tail=newnode;
        }
        else{
          newnode->next=head;
          head=newnode;
        }
        
      }
      
      void addatrear(int data)
      {
        node *newnode=new node(data);
        newnode->next=NULL;
        if (is_empty())
        {
          head=tail=newnode;
        }
        else{
          tail->next=newnode;
          tail=newnode;
        }
      } 



      int deleteatfront()
      {
        if (is_empty())
        {
          cout<<"dequeue is empty"<<endl;
        }
        
        node *temp=head;
        head=head->next;
         if (head==NULL)
         {
           tail= NULL;
         }
        
        free(temp);
  
      }


      int deleteatrear()
      {
        if (is_empty())
        {
          cout<<"dequeue is empty"<<endl;
        }


        if (head==tail)
        {
          node *temp=head;
          free(temp);
          head=tail=NULL;
        }

        else{
          node *second_last=head;

          while (second_last->next!=NULL)
          {
            second_last=second_last->next;
          }

          node *temp=second_last;
          free(temp);
        }
      }

      void display()
      {
        node *temp=head;
        while (temp!=NULL)
        {
          cout<<temp->data<<" ->";
          temp=temp->next;
        }
        

      }


};

int main(){
  dequeue obj;
  obj.addatfront(3);
  obj.addatfront(4);
  obj.addatfront(5);
  obj.addatfront(6);
  obj.addatfront(7);
  obj.addatfront(8);
  obj.addatfront(9);
  obj.addatrear(10);
  obj.deleteatfront();
  obj.deleteatfront();
  obj.deleteatfront();
  // obj.deleteatfront();
  // obj.deleteatrear();
  // obj.deleteatrear();
  // obj.deleteatrear();
  // obj.deleteatrear();
  // obj.deleteatrear();
  obj.display();


    
    return 0;
}