#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int create(int);
void linear_prob(int [],int,int);
void display(int []);
void main()
{
	int a[MAX],empno, key,i;
	int ch;
	printf("\n Collision Handling By Linear Probing");
	for(i=0;i<MAX;i++)
	a[i]=-1;
	FILE *fp;
	fp = fopen("employee.txt","r");
	if(fp==NULL)
	{
          printf("File can not be opened");
	        return;
	}
		while(fscanf(fp,"%d",&empno) != EOF)
	{
		key=create(empno);
		linear_prob(a,key,empno);
	}

    fclose(fp);
	display(a);
	return;
}

int create(int empno)
{
	int key;
	key=empno%100;
	return key;
}

void linear_prob(int a[MAX],int key,int empno)
{
	int flag,i,count=0;
	flag=0;
	if(a[key]==-1)
	a[key]=empno;
	else
	{
		i=0;
		for(i=key+1;i<MAX;i++)
		{
          if (a[i]==-1)
	      {
			a[i]=empno;
			flag=1;
			break;
          }
		}
		if (flag==0) printf("\n\n Hash Table is Full\nCannot add %d\n",empno);
	}
}

void display(int a[MAX])
{
	int i;
    printf("\n\n The Hash Table is....\n");
	for(i=0;i<MAX;i++)
    if (a[i]!=-1)
	printf("\n %d %d",i,a[i]);
}
