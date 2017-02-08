#include <cs50.h>
#include <string.h>
#include <stdio.h>

#define CONSOLEWIDTH 255
#define BUFFER 2048

typedef struct {
    int* hashLocations;
    int length;
} csvLine;

csvLine extractNumbers(char* line);

int main(void)
{
    //You need to do the following:

    //Prompt the user for an input file
    printf("What is the name of the file I should read from?");
    char* inName = GetString();
    FILE* input = fopen(inName, "r");

    //Prompt the user for an output file and open
    printf("Waht is the name of the file I should write to?");
    char* outName = GetString();
    FILE* output = fopen(outName, "w");
    
    if (input == NULL || output == NULL)
    {
        printf("Error accessing files provided, exiting");
        return 1;
    }


    //For each line being read in from the input file:
    char line[BUFFER];
    while(fgets(line, BUFFER, input) != NULL)
    {
        csvLine numList = extractNumbers(line);

        // Check for blank line
        if (numList.length == 1) // blank lines in input have length 1??? so skip
        {
            fputc('\n', output);
            continue;
        }
    
        for (int i = 0, screenpos = 0; screenpos < CONSOLEWIDTH && i <= numList.length; screenpos++)
        {
            if (numList.hashLocations[i] == screenpos)
            {
                fputc('#', output);
                i++;
                continue;
            }
            else
            {
                fputc(' ', output);
            }
        }
        fputc('\n', output);
    }

    //Close both files
    fclose(input);
    fclose(output);

    //Insert the name of the output file in the print statement below
    printf("Done! If you open up %s you should now see a cool image!\n", outName);
    
    free(inName);
    free(outName);
}

csvLine extractNumbers(char* line)
{
    int count = 0;
    for(int i = 0; i < strlen(line); i++)
    {
        if(line[i] == ',')
        {
            count++;
        }
    }

    char* token;
    int* hV = malloc(sizeof(int) * (count+1));
    int i = 0;
    token = strtok(line, ",");
    hV[i] = atoi(token);
    i++;
    while ((token = strtok(NULL, ",")) != NULL)
    {
        hV[i] = atoi(token);
        i++;
    }
    csvLine result;
    result.hashLocations = hV;
    result.length = count + 1;
    return result;
}