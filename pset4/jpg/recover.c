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

#define SECTOR_SIZE 512

typedef struct {
    uint8_t h1;
    uint8_t h2;
    uint8_t h3;
    uint8_t h4;
} JPEGSIG;

bool IsJPEGSignature(JPEGSIG sig);

int main(int argc, char** argv)
{
    // // Psuedocode
    // Open card file
    // repeat until end of card
    //     read SECTOR_SIZE bytes into buffer
    //     check for jpeg signature at first 4 bytes of block
    //     if new jpeg
    //         close previous jpeg file
    //         open new jpeg file
    //     if a jpeg is open
    //         write buffer to file
    // Close final output file
    // Close input file
    
    
    // open and check input file
    FILE* infile = fopen("card.raw", "r");
    if (infile == NULL)
    {
        printf("Error: File not found\n");
        return 1;
    }
    
    // Struct to store first 4 bytes to check for header
    JPEGSIG jp;
    
    // Buffer for file i/o
    uint8_t buffer[SECTOR_SIZE];
    
    // Image output related variables
    int imgcount = 0;
    char outname[8];
    FILE* outfile;
    bool outfileopen = false;
    
    // Iterate through the sectors
    while (fread(&buffer, SECTOR_SIZE, 1, infile) > 0)
    {
        // copy first 8 bytes to jpeg checking struct
        memcpy(&jp, &buffer, sizeof(JPEGSIG));
        
        if (IsJPEGSignature(jp))
        {
            // Output file creation and opening
            sprintf(outname, "%03d.jpg", imgcount);
            
            if (outfileopen)
            {
                fclose(outfile);
            }

            outfile = fopen(outname, "a");
            if (outfile == NULL)
            {
                fclose(infile);
                printf("Error: Output file creation failed\n");
                return 2;
            }
            imgcount++;
            outfileopen = true;
        }
        
        // Write sector to outfile
        if (outfileopen)
        {
            fwrite(buffer, SECTOR_SIZE, 1, outfile);
        }
    }


    // Close remaining open files
    
    if (outfile)
    {
        fclose(outfile);
    }
    fclose(infile);
    
    return 0;
}

bool IsJPEGSignature(JPEGSIG sig)
{
    if (sig.h1 == 0xff && sig.h2 == 0xd8 && sig.h3 == 0xff && sig.h4 >= 0xe0 && sig.h4 <= 0xef)
    {
        return true;
    }
    
    return false;
}
