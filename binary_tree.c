#include<stdio.h>
#include<stdlib.h>

struct node
{
int data;
struct node *llink;
struct node *rlink; 
};

typedef struct node* treePointer;
int flag = 0;

void push(treePointer *root)
{

int ele;

treePointer temp =  *root;
treePointer prev = NULL; 
struct node *newNode = (struct node *) malloc(sizeof(struct node));

newNode->llink=NULL;
newNode->rlink=NULL;

printf("Enter the element : ");
scanf("%d",&ele);

newNode->data = ele;

if(*root==NULL) 
 {
  *(root) = newNode;
   return;
 }
 
while(temp)
  {

   if(ele == temp->data)
      return;
   if(ele < temp->data)
        {
         prev = temp;
         temp = temp->llink;
        } 
   else
       {
        prev = temp;
        temp = temp->rlink; 
      } 
  }

 if(ele > prev->data)
 {
  prev->rlink = newNode;
  printf("%d inserted \n",ele);
 }
 else{
   prev->llink = newNode; 
   printf("%d inserted \n",ele);
  }
}

treePointer search(int key,treePointer root,treePointer *parent)
{
    treePointer temp = root;
    
    while(temp->llink!=NULL || temp->rlink!=NULL)
    {
        if(key == temp->data)
        {
            printf("Element found ");
            flag=1;
            return temp;
        }
        else
            if(key < temp->data){
                *(parent) = temp;
                temp = temp->llink;
            }
            else
            {
                *(parent) = temp;
                temp = temp->rlink;
            }
    }
    
    if(key == temp->data)
    {
        printf("Element found\n");
        flag=1;
        return temp;
    }
    
    
    if(flag == 0)
        printf("Element not found\n");
        return NULL;
}

void delete(treePointer root,int key)
{
treePointer temp = NULL;
treePointer succ = NULL;
treePointer parent = NULL;

    temp = search(key,root,&parent);

if(temp !=NULL)
    {
        if(temp->llink==NULL && temp->rlink == NULL)
          {
           if(parent->llink == temp)
               parent->llink = NULL;
           else
               parent->rlink = NULL;
          
           free(temp);
          }
        if(temp->llink==NULL && temp->rlink!=NULL)
          {
          if(parent->llink == temp)
             parent->llink = temp->rlink;

          else
             parent->rlink = temp->rlink;
         
          free(temp);
          }

    
        if(temp->llink != NULL && temp->rlink==NULL)
          {
              if(parent->llink== temp)
                    parent->llink = temp->llink;
              else
                    parent->rlink = temp->llink;
              free(temp);
           }
        if(temp->llink!=NULL && temp->rlink!=NULL)
          {
            succ = temp->rlink;
            while(succ->rlink != NULL)
               {
                parent = succ;
                succ = succ->llink;
               }
            
           temp->data = succ->data;
          parent->llink = succ->rlink;

        free(succ);
          }
    }
    
} 



void inorder(treePointer root)
{
if(root!=NULL)
   { 
	inorder(root->llink);
	printf(" %d ",root->data);
	inorder(root->rlink);
   }
}

void preorder(treePointer root)
{
 if(root!=NULL)
   {
    printf(" %d ",root->data);
    preorder(root->llink);
    preorder(root->rlink);
   }
}


void postorder(treePointer root)
{
  if(root!=NULL)
   {
    postorder(root->llink);
    postorder(root->rlink); 
    printf(" %d ",root->data);
   }

}
int main()
{
treePointer root=NULL;
    treePointer dummy = NULL;
int choice,key;

printf("1.Insert\n2.Delete\n3.Search\n4.InOrder\n5.PreOrder\n6.PostOrder\n7.Exit");
  while(1) 
     {
       printf("\nEnter choice ");
       scanf("%d",&choice);
        switch(choice)
                 {
                  case 1:  push(&root);
                           break;
                  case 2:  printf("Enter element to delete");
                           scanf("%d",&key);
                           delete(root,key);
                           break; 
                  case 3 : printf("Enter search element ");
                           scanf("%d",&key); 
                           search(key,root,&dummy);
                           break;
                  case 4:  inorder(root);
                           break;
       		  case 5:  preorder(root);
                           break;
		  case 6:  postorder(root);
                           break;
                  case 7:  exit(0);
                 }
    }
return 0;
}
