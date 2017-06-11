#include<stdio.h>
#include<cs50.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(int argc, string argv[])
{
    if(argc!=2)
    {
        printf("Invalid Input");
         return 1;
    }
       
    else
    {
        int k= atoi(argv[1]), result;
        k= k%26;
        string message= GetString();
        for(int i=0,n=strlen(message); i<n; i++)
        {
            if( isalpha(message[i]) )
            {
                if( isupper(message[i]) )
                {
                     result= message[i]+k;
                    if( result> 'Z')
                        printf("%c",result-26);
                    
                    else printf("%c",result);
                }
                else
                {
                    result= message[i]+k;
                    if( result> 'z')
                        printf("%c",result-26);
                   
                    else printf("%c",result); 
                }
                
            }
            else printf("%c",message[i]);
        }
        printf("\n");
        return 0;
    }
}