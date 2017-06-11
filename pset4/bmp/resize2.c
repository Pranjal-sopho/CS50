 ⁠⁠⁠/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./resize factor infile outfile\n");
        return 1;
    }

    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];
    char* factor = argv[1];
    //get the factor an integer
    int FACTOR = atoi(factor);
    
    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf,bfO;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    bfO=bf;

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi,biO;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    biO=bi;

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    
    biO.biHeight =   bi.biHeight*FACTOR ; 
    biO.biWidth  =   bi.biWidth*FACTOR  ;  
  
    
    // determine padding (OF INFILE) for scanlines
    int paddingI =  (4 - (bi.biWidth* sizeof(RGBTRIPLE)) % 4) % 4;
    // determine padding (OF OUTFILE) for scanlines
    int paddingO =  (4 - (biO.biWidth*sizeof(RGBTRIPLE)) % 4) % 4;
    
    // updating biO and updating bfO
    biO.biSizeImage   =   abs(biO.biHeight)*(biO.biWidth*sizeof(RGBTRIPLE)+paddingO);  
    bfO.bfSize   =    biO.biSizeImage - bi.biSizeImage + bf.bfSize  ;  
    
    
   
    // write outfile's BITMAPINFOHEADER
    fwrite(&biO, sizeof(BITMAPINFOHEADER), 1, outptr);
    // write outfile's BITMAPFILEHEADER
    fwrite(&bfO, sizeof(BITMAPFILEHEADER), 1, outptr);
    

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {   
        //iterate over each scanline for (FACTOR) number of times
        for(int j = 0;j < FACTOR; j++)
        {
            // iterate over pixels in scanline
            for (int k = 0; k < bi.biWidth; k++)
            {   
            
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            // write RGB triple to outfile(FACTOR) number of times
            for(int l = 0;l < FACTOR; l++)
            {
                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
            }
                
           
            }    
                 for (int l = 0; l < paddingO; l++)
                {
                  fputc(0x00, outptr);
                }
                
                if(j < FACTOR-1)
                fseek(inptr, -bi.biWidth*sizeof(RGBTRIPLE),SEEK_CUR);
                
        }
       
        // skip over padding, if any
        fseek(inptr, paddingI, SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}