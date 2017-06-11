/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
 #include<stdio.h>
 
 int main(void)
 {
    FILE* file = fopen("card.raw","r");
    int i=0,l=-1;
    
    unsigned char buffer[512];
    
    char image_name[8];
    
    do
    {
        fread(&buffer, 512, 1, file);
    }while( !(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff) );
    
    do
    {
        l++;
        
        sprintf(image_name, "%03d.jpg", l);
        
        FILE *output = fopen(image_name,"w");
        
        do
        {
            fwrite(&buffer, 512, 1, output);
            i=fread(&buffer, 512, 1, file);
            if(i!=1)
                break;
        } while( !(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff) );
        
        fclose(output);
        
    }while( i==1 ); 
    
    fclose(file);
    return 0;
}