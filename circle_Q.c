#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX 10
int n;
char a[MAX];
int front=0,rear=0;
n=n+1;
void push()
{
 char ele[2];
 if((rear+1)%n==front)
   {
     printf("\nQueue Overflow");
     return;
   }
printf("\nEnter element ");
scanf("%s",ele);
//fgetc(ele);
rear=(rear+1)%n;
a[rear]=ele[0];
}

void pop()
{
if(front==rear)
 {
  printf("\nQueue Underflow ");
  return;
  }
front = (front+1)%n;
char ele[10]; 

ele[0]= a[front];
//front = (front+1)%n;
printf("\n %c deleted ",ele[0]);
}

void display()
{
int i;
if(front==rear)
 {
  printf("\nQueue Underflow ");
  return;
  }


printf("Queue Contains ");
if(front<rear)
 {
  int fr=(front+1) %n;
  for(i=fr;i<=rear;i++)
    printf(" %c ",a[i]);
  }  
else
  {
   int fr=(front+1) %n;
   for(i=fr;i<n;i++)
    printf(" %c ",a[i]);
  for(i=0;i<=rear;i++)
    printf(" %c ",a[i]);
  }
}

void main()
{
int choice;
printf("Enter queue size ");
scanf("%d",&n);
printf("1.Insert Element\n2.Delete Element\n3.display\n4.Exit");
 
 while(1)
   {
    printf("\nEnter choice ");
    scanf("%d",&choice);
      switch(choice)
         {
              case 1 : push();
                       break;
              case 2 : pop();
                       break; 
              case 3 : display();
                       break;
              case 4: exit(0);
                
              default : printf("\nInvalid");         

          } 

   }
}
