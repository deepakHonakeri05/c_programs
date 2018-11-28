#include<stdio.h>

void toh(int n,char s,char a,char d)
{
if(n==0)
   return ;
else {
   toh(n-1,s,d,a);
   printf("%d from %c source to %c destination\n",n,s,d);
   toh(n-1,a,s,d);
 }
}

int main()
{
int n;
printf("Enter no.of disks ");
scanf("%d",&n);
toh(n,'A','B','C');
return 0;

}
