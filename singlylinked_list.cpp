#include <iostream>
using namespace std;
class node
{

public:
  int prn;
  char name[10];
  node *next;
};
class pinacle
{
  node *head;

public:
  void create();
  void display();
  void insret_Atbegin();
  void insert_Atend();
  void insert_Atpos();
};

void pinacle::create()
{
  int n;
  cout << "how many member you want to add" << endl;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    node *newnode = new node;
    cout << "enter prn" << endl;
    cin >> newnode->prn;
    cout << "enter name of member" << endl;
    cin >> newnode->name;
    newnode->next = NULL;
    if (head == NULL)
    {
      head = newnode;
    }
    else
    {
      node *temp = head;
      while (temp->next != NULL)
      {
        temp = temp->next;
        temp->next = newnode;
      }
    }
  }
}

void pinacle::display()
{
  node *temp=head;
  cout<<"member of the club are"<<endl;
  while (temp!=NULL)
  {
    cout<<temp->prn<<"    "<<temp->name<<endl;
    temp=temp->next;   
  }
  
}
int main()
{

  return 0;
}