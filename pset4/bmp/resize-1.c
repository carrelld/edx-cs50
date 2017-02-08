/**
 * resize.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, and resizes it based on a user-supplied factor
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./resize n infile outfile\n");
        return 1;
    }

    // remember inputs
    int factor = atoi(argv[1]);
    char* infile = argv[2];
    char* outfile = argv[3];
    
    // Check factor meets requirements
    if (factor > 100 || factor < 1)
    {
        printf("Error: Factor must be [1,100]");
        return 1;
    }

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
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);


    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);


    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // Psuedocode for image size calculations
        // Calculate new image size and file size
        // new image size = (image - padding) * factor + padding
        // image = height * width
        // width = 3 bytes * number of pixels wide + padding
    
    // Set new height and width
    BITMAPFILEHEADER rbf = bf;
    BITMAPINFOHEADER rbi = bi;
    rbi.biHeight = bi.biHeight * factor;
    rbi.biWidth = bi.biWidth * factor;
    
    // determine padding for scanlines
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int newpadding = (4 - (rbi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    // Set new calculated header size values
    rbi.biSizeImage = abs(rbi.biHeight) * (rbi.biWidth * sizeof(RGBTRIPLE) + newpadding);
    rbf.bfSize += rbi.biSizeImage - bi.biSizeImage;

    // write outfile's BITMAPFILEHEADER
    fwrite(&rbf, sizeof(BITMAPFILEHEADER), 1, outptr);
    // write outfile's BITMAPINFOHEADER
    fwrite(&rbi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        for (int vrep = 0; vrep < factor; vrep++)
        {
            // iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;
    
                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
    
                // write RGB triple to outfile
                for (int hrep = 0; hrep < factor; hrep++)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }
    
            // jump back to beginning of line if needed or skip over padding, if any
            if (vrep < factor - 1)
            {
                fseek(inptr, -bi.biWidth * sizeof(RGBTRIPLE), SEEK_CUR);
            }
            else
            {
                fseek(inptr, padding, SEEK_CUR);
            }
    
            // then add it back (to demonstrate how)
            for (int k = 0; k < newpadding; k++)
            {
                fputc(0x00, outptr);
            }
    
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
