#include<math.h>
#include<iostream>
using namespace std;
class Node
{
	public:
	int digit;
	Node *next,*back;

};
class DLL
{
	Node *head;
	public:
	DLL()
	{
		head=NULL;
	}
	void create();
	void display();
	DLL ones_complement();
	DLL twos_complement();
	DLL add(DLL);
	void insert_at_end(Node*);
	void insert_at_beg(Node *);
	void convert_dec();
};
void DLL::create()
{
	int no;
	cout<<"\nEnter Number:";
	cin>>no;
	while(no>0)
	{
		int r=no%2;
		no=no/2;
		Node *newnode=new Node;
		newnode->digit=r;
		newnode->next=NULL;
		newnode->back=NULL;
		insert_at_beg(newnode);
	}
}
void DLL::display()
{
	if(head==NULL)
		cout<<"\nList is empty!";
	else
	{
		Node *temp=head;
		while(temp!=NULL)
		{
			cout<<temp->digit;
			temp=temp->next;
		}
	}
}
void DLL::insert_at_end(Node *newnode)
{
	if(head==NULL)
		head=newnode;
	else
	{
		Node *temp=head;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=newnode;
		newnode->back=temp;
	}
}

void DLL::insert_at_beg(Node *newnode)
{
	if(head==NULL)
		head=newnode;
	else
	{
		newnode->next=head;
		head->back=newnode;
		head=newnode;
	}
}
DLL DLL::add(DLL list)
{
	DLL res;
	Node *temp1=head;
	while(temp1->next!=NULL)
		temp1=temp1->next;
	Node *temp2=list.head;
	while(temp2->next!=NULL)
		temp2=temp2->next;
	int carry=0,ans=0;
	while(temp1!=NULL && temp2!=NULL)
	{
		if(carry==0 && temp1->digit==0 && temp2->digit==0)
		{
			ans=0;
			carry=0;
		}
		else if(carry==0 && temp1->digit==0 && temp2->digit==1)
		{
			ans=1;
			carry=0;
		}
		else if(carry==0 && temp1->digit==1 && temp2->digit==0)
		{
			ans=1;
			carry=0;
		}
		else if(carry==0 && temp1->digit==1 && temp2->digit==1)
		{
			ans=0;
			carry=1;
		}
		else if(carry==1 && temp1->digit==0 && temp2->digit==0)
		{
			ans=1;
			carry=0;
		}
		else if(carry==1 && temp1->digit==0 && temp2->digit==1)
		{
			ans=0;
			carry=1;
		}
		else if(carry==1 && temp1->digit==1 && temp2->digit==0)
		{
			ans=0;
			carry=1;
		}
		else if(carry==1 && temp1->digit==1 && temp2->digit==1)
		{
			ans=1;
			carry=1;
		}
		temp1=temp1->back;
		temp2=temp2->back;

		Node *newnode=new Node;
		newnode->digit=ans;
		newnode->next=NULL;
		newnode->back=NULL;
		res.insert_at_beg(newnode);
	}
	while(temp1!=NULL)
	{
		if(carry==1 && temp1->digit==0)
		{
			ans=1;
			carry=0;
		}
		else if(carry==1 && temp1->digit==1)
		{
			ans=0;
			carry=1;
		}
		else
		{
			ans=temp1->digit;
		}
		temp1=temp1->back;

		Node *newnode=new Node;
		newnode->digit=ans;
		newnode->next=NULL;
		newnode->back=NULL;
		res.insert_at_beg(newnode);
	}
	while(temp2!=NULL)
	{
		if(carry==1 && temp2->digit==0)
		{
			ans=1;
			carry=0;
		}
		else if(carry==1 && temp2->digit==1)
		{
			ans=0;
			carry=1;
		}
		else
		{
			ans=temp2->digit;
		}
		temp2=temp2->back;
		Node *newnode=new Node;
		newnode->digit=ans;
		newnode->next=NULL;
		newnode->back=NULL;
		res.insert_at_beg(newnode);
	}
	if(temp1==NULL && temp2==NULL && carry==1)
	{
		ans=1;
			Node *newnode=new Node;
		newnode->digit=ans;
		newnode->next=NULL;
		newnode->back=NULL;
		res.insert_at_beg(newnode);
	}
	return res;
}
DLL DLL::ones_complement()
{
	Node *newnode,*temp;
	DLL res;
	temp=head;
	while(temp!=NULL)
	{
		if(temp->digit==1)
		{
			newnode=new Node;
			newnode->digit=0;
			newnode->next=NULL;
			newnode->back=NULL;
		}
		else if(temp->digit==0)
		{
			newnode=new Node;
			newnode->digit=1;
			newnode->next=NULL;
			newnode->back=NULL;
		}
		temp=temp->next;
		res.insert_at_end(newnode);
	}
	return res;
}
DLL DLL::twos_complement()
{
 //	int carry=0;
	DLL ones_c,one,res;
	Node *temp=head;
	while(temp->next!=NULL)
	{
		Node *newnode=new Node;
		newnode->digit=0;
		newnode->next=NULL;
		newnode->back=NULL;
		temp=temp->next;
		one.insert_at_end(newnode);
	}
	Node *newnode=new Node;
		newnode->digit=1;
		newnode->next=NULL;
		newnode->back=NULL;
	one.insert_at_end(newnode);
	ones_c=ones_complement();
	res=ones_c.add(one);
	return res;
}
void DLL::convert_dec()
{
int i=0;
Node *temp=head;
while(temp->next!=NULL)
temp=temp->next;
int t;
int sum=0;
while(temp!=NULL)
{

int p=pow(2,i);
sum=sum+temp->digit*p;
i++;
temp=temp->back;
}
cout<<"\nSum in Decimal "<<sum;
}
int main()
{
	DLL l1,l2,res;
	
	cout<<"\nFirst number\n";
	l1.create();
	l1.display();
	res=l1.ones_complement();
	cout<<"\nOne's complementn:";
	res.display();
	res=l1.twos_complement();
	cout<<"\nTwo's complement:";
	res.display();
	l2.create();
	l2.display();
	res=l1.add(l2);
	cout<<"\nAddition is:\n";
	res.display();
	res.convert_dec();
	
	return 0;
}