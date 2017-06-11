#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main( int argc, string argv[])
{   
    if(argc==1)
    {
        printf("Key not found");
        return 1;
    }
    
    else
    {
        int k= strlen(argv[1]),result,x=0,i,n;
        for( i=0; i<k; i++ )
        {
            if(isalpha(argv[1][i]))
                continue;
                
            else 
            {
                printf("Invalid key");
                return 1;
            }
        }
        string message = GetString();
        for(i=0, n= strlen(message); i<n; i++)
        {
            if( isalpha(message[i]))
            {   
                    if( isupper(message[i]))
                    {
                       if( isupper(argv[1][x%k]))
                       {
                           result = message[i]%65 + argv[1][x%k]%65;
                           if(result>25)
                           printf("%c",result+39);
                          
                           else printf("%c",result+65);
                       }
                       else
                       {
                           result = message[i]%65 + argv[1][x%k]%97;
                             if(result>25)
                           printf("%c",result+39);
                          
                           else printf("%c",result+65);
                       }
                       x++;
                    }
                    else
                    {
                        if( isupper(argv[1][x%k]))
                       {
                           result = message[i]%97 + argv[1][x%k]%65;
                           if(result>25)
                              printf("%c",result+71);
                           
                           else printf("%c",result+97);
                       }
                       else
                       {
                           result = message[i]%97 + argv[1][x%k]%97;
                             if(result>25)
                               printf("%c",result+71);
                           
                           else printf("%c",result+97);  
                       } 
                       x++;
                    }
               
            }
            
            else printf("%c",message[i]);
        }
        printf("\n");
        return 0;
    }
}