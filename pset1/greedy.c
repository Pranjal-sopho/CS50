#include<stdio.h>
#include<cs50.h>
#include<math.h>

int main()
{
    float cent;
    int counter=0,x;
    
    while(true)
    {
        printf("How much change is owed?\n");
        cent= GetFloat();
        
        if(cent > 0.00)
            break;
    }
    
    x=(int) round(cent*100);
    
    if(x >= 25)
    {
        counter=counter+x/25;
        x = x%25;
    }
    
    if(x >= 10)
    {
        counter=counter+x/10;
        x = x%10;
    }
    
    if(x >= 5)
    {
        counter=counter+x/5;
        x = x%5;
    }
    
    if(x >= 1)
    {
        counter=counter+x/1;
        x = x%1;
    }
   
    printf("%d\n",counter);
    return 0;
    
}