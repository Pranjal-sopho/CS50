#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
int main(){
    int x=1;
    string name= GetString();
    
    char*p,*q;
   
    for(int i=0,n=strlen(name);i<n;i++)
    {
        p= &name[x];
        q= &name[i];
        if(*q==' ')
        {
            strcpy(p,q+1);
            x++;
        }    
    }
    for(int j=0;j<x;j++)
    {
        if(islower(name[j]))
           printf("%c", toupper(name[j]));
            
        else printf("%c",name[j]);
    }
    printf("\n");
    return 0;
    
}