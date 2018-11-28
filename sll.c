#include<stdio.h>
#include<stdlib.h>
struct node
{
char usn[10];
char name[30];
char branch[20];
int sem;
char phno[10];
struct node* link;
};

struct node* front = NULL;


void pushF()
{
struct node* newnode;

newnode = (struct node*) malloc(sizeof(struct node));
newnode->link = NULL;
printf("\nEnter the USN,Name,Branch,Sem,Phone Number\n");
scanf("%s %s %s %d %s",newnode->usn,newnode->name,newnode->branch,&newnode->sem,newnode->phno);

if(front == NULL)
  {
  front = newnode;
  }
else{
newnode->link = front;
front = newnode;
 }
}

struct node* popF()
{
if(front==NULL){
  printf("\nList underflow ");
 return NULL;
  }
else{
  struct node*  ele = front ;
   front = front->link;
  return  ele; 
 }

}

void pushR()
{
struct node* newnode;
struct node* temp=front;

newnode = (struct node*) malloc(sizeof(struct node));
newnode->link = NULL;
printf("\nEnter the element");
scanf("%s %s %s %d %s",newnode->usn,newnode->name,newnode->branch,&newnode->sem,newnode->phno);

if(front == NULL)
  {
  front = newnode;
  }
else{
   while(temp->link!=NULL)
    temp = temp->link;
temp->link=newnode;
 }
}

void  popR()
{

struct node* temp=front;

if(front == NULL)
 {
  printf("\nList Underflow");
  }
else{
   while(temp->link!=NULL)
    {
     temp = temp->link;
     }
   //free(temp->link);
   temp->link=NULL;  
 } 
}


void display()
{

struct node* temp=front;
if(front==NULL)
  printf("\nList Empty ");
else{
        while(temp!=NULL)
            {
              printf("USN: %s\nName: %s\nBranch: %s\nSem: %d\nPhone: %s\n",temp->usn,temp->name,temp->branch,temp->sem,temp->phno);  
             temp = temp->link;
           }
//         printf("USN: %s\nName: %s\nBranch: %s\nSem: %d\nPhone: %s\n",temp->usn,temp->name,temp->branch,temp->sem,temp->phno);
}
}


void stack()
{ 
   int choice;
struct node* ele=NULL;

printf("1.Push\n2.Pop\n3.Display\n4.Exit stack");
while(1)
 {
  printf("Enter your choice: ");
  scanf("%d",&choice);
    switch(choice)
     {
       case 1: pushF();
               break;
       case 2: ele= popF();
               break;
       case 3: display();
               break;
       case 4: return ;

     }

 } 
}

void queue()
{
   int choice;
struct node* ele=NULL;

printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit stack");
while(1)
 {
  printf("Enter your choice: ");
  scanf("%d",&choice);
    switch(choice)
     {         
       case 1: pushR();
               break;
       case 2: ele= popF();
               break;
       case 3: display();
               break;
       case 4: return ;

     }

 } 


}

int main()
{
struct node* ele=NULL;
int choice;
printf("1.Insert Front\n2.Delete Front\n3.Insert Rear\n4.Delete Rear\n5.Display\n6.Demonstrate as Stack\n7.Demonstrate as queue\n8.Exit");
 while(1)
   {
    printf("\nEnter choice ");
    scanf("%d",&choice);
      switch(choice)
         {
              case 1 : pushF();
                       break;
              case 2 : ele = popF();
                       break;
              case 3 : pushR();
                       break;
              case 4 :  popR();
                       break;
              case 5 : display(); 
                       break;
              case 6 : stack();
                       break; 
              case 7 : queue();
                       break;
              case 8 : exit(0);
         
              default : printf("\nInvalid Choice");

          }

   }
return 0;
}

