#include <stdio.h>
#include <ctype.h>
#define SIZE 50
char s[SIZE];
int top=-1;      
void push(char elem)
{                       
    s[++top]=elem;
}
 
char pop()
{                      
    return(s[top--]);
}
 
int pr(char elem)
{            
  if(elem=='#')
    return 0;     
 else if(elem=='(')
    return 1;
 else if(elem=='+'||elem=='-')
    return 2;
 else if(elem=='*'||elem=='/')
    return 3;
 else 
    return 4;
}
 
int main()
{                        
    char infx[50],pofx[50],ch,elem;
    int i=0,k=0;
    
    printf("\n\nRead the Infix Expression ? ");
    scanf("%s",infx);
    push('#');
    while( (ch=infx[i++]) != '\0')
    {
    if( ch == '(') push(ch);
    else
    if(isalnum(ch)) pofx[k++]=ch;
      else
    if( ch == ')')
    {
        while( s[top] != '(')
      pofx[k++]=pop();
        elem=pop(); 
    }
    else
    {       
        while( pr(s[top]) >= pr(ch) )
      pofx[k++]=pop();
        push(ch);
    }
    }
    while( s[top] != '#')     
  pofx[k++]=pop();
    pofx[k]='\0';          
    printf("\n\nGiven Infix Expn: %s  Postfix Expn: %s\n",infx,pofx);
return 0;
}
