/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 * JPEG is block agligned, so only the first four bytes need testing for each block
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <cs50.h>

typedef struct {
    unsigned int h1:8;
    unsigned int h2:8;
    unsigned int h3:8;
    unsigned int h4:8;
} JPEGSIG;

bool IsJPEGSignature(JPEGSIG sig);

int main(int argc, char* argv[])
{
    // // Psuedocode
    // Open card file
    // repeat until end of card
    //     read 512 bytes into buffer
    //     check for jpeg signature at first 4 bytes of block
    //     if new jpeg
    //         close previous jpeg file
    //         open new jpeg file
    //     if a jpeg is open
    //         write buffer to file
    // Close final output file
    // Close input file
    
    FILE* infile = fopen("card.raw", "r");
    if (infile == NULL)
    {
        printf("Error: File not found\n");
        return 1;
    }
    
    char buffer[512];
    JPEGSIG jp;
    int imgcount = 0;
    FILE* outfile = NULL;
    char* outname = "000.jpg";
    int sectorcount = 0;
    
    while (fread(&buffer, 1, 512, infile) > 0)
    {
        memcpy(&jp, &buffer, 4);
        if (IsJPEGSignature(jp))
        {
            // Close output file if open
            if (outfile != NULL)
            {
                fclose(outfile);
            }
            sprintf(outname, "%d.jpg", imgcount++);
            printf("%s\n",outname);
            outfile = fopen(outname, "a");
            if (outfile == NULL)
            {
                printf("Error: File Creation failed\n");
                return 2;
            }
        }
        if (imgcount > 0)
        {
            fwrite(&buffer, 512, 1, outfile);
        }
        sectorcount++;
        printf("%i\n", imgcount);
    }
    printf("%i\n", sectorcount);
    
    // Close remaining open files
    if (outfile != NULL)
        fclose(outfile);
    fclose(infile);
    
}

bool IsJPEGSignature(JPEGSIG sig)
{
    if (sig.h1 == 0xff && sig.h2 == 0xd8 && sig.h3 == 0xff && sig.h4 >= 0xe0 && sig.h4 <= 0xef)
    {
        return true;
    }
    
    return false;
}
