#include<stdio.h>
#include<stdlib.h>
struct node
{
char usn[10];
char name[30];
char branch[20];
int sem;
char phno[10];
struct node* llink;
struct node* rlink;
};

struct node* front = NULL;


void pushF()
{
struct node* newnode;

newnode = (struct node*) malloc(sizeof(struct node));
newnode->llink = NULL;
newnode->rlink = NULL;
printf("\nEnter the SNN,Name,Department,Salary,Phone Number\n");
scanf("%s %s %s %d %s",newnode->usn,newnode->name,newnode->branch,&newnode->sem,newnode->phno);

if(front == NULL)
  {
  front = newnode;
  }
else{
front->llink = newnode;
newnode->rlink = front;
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
   front = front->rlink;
   free(front->llink);
   front->llink = NULL;
  return  ele; 
 }

}

void pushR()
{
struct node* newnode;
struct node* temp=front;

newnode = (struct node*) malloc(sizeof(struct node));
newnode->llink = NULL;
newnode->rlink = NULL;
printf("\nEnter the SNN,Name,Department,Salary,Phone Number\n");
scanf("%s %s %s %d %s",newnode->usn,newnode->name,newnode->branch,&newnode->sem,newnode->phno);

if(front == NULL)
  {
  front = newnode;
  }
else{
   while(temp->rlink!=NULL)
    temp = temp->rlink;
 temp->rlink=newnode;
newnode->llink=temp;
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
   while(temp->rlink!=NULL)
    {
     temp = temp->rlink;
     }
   //free(temp->link);
   temp=temp->llink;
   temp->rlink=NULL;  
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
              printf("SNN: %s\nName: %s\nDepartment: %s\nSalary: %d\nPhone: %s\n\n",temp->usn,temp->name,temp->branch,temp->sem,temp->phno);  
             temp = temp->rlink;
           }

    }
}

void doubleQueue()
{
   int choice;
struct node* ele=NULL;

printf("	Demonstration as Queue\n	1.Enqueue at front\n	2.Dequeue at front\n	3.Enqueue at rear\n	4.Dequeue at rear\n	5.Display\n 	6.Exit Queue");
while(1)
 {
  printf("Enter your choice: ");
  scanf("%d",&choice);
    switch(choice)
     {         
       case 1: pushF();
               break;
       case 2: ele=popF();
               break;
       case 3: pushR();
               break;
       case 4: popR();
               break;
       case 5: display();
               break;
       case 6: return ;        
     }

 } 


}

int main()
{
struct node* ele=NULL;
int choice;
printf("1.Insert Front\n2.Delete Front\n3.Insert Rear\n4.Delete Rear\n5.Display\n6.Demonstrate as Double Ended Queue\n7.Exit");
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
              case 6 : doubleQueue();
                       break;
              case 7 : exit(0);
         
              default : printf("\nInvalid Choice");

          }

   }
return 0;
}

