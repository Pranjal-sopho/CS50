#include<stdio.h>
#include<cs50.h>

int main()
{
    int h,i,j;
   
    do
    {
        printf("Enter height:");
        h= GetInt();
    
    }while(h<0 || h>23);
    
    for(i=0; i<h; i++)
    {
        for(j=h; j>=0; j--)
        {
            if(j <= i+1)
                printf("#");
            
            else printf(" ");
        }
        
        printf("\n");
    }
    
    return 0;
}