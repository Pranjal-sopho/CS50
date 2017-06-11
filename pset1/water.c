#include<stdio.h>
#include<cs50.h>

int main()
{
    printf("minutes: ");
    
    int x= GetInt();
    
    printf("bottles: %d",12*x);
    
    return 0;
}