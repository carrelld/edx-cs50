#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define LimitRequestLine 8190

bool parse(const char* line, char* path, char* query)
{
    // Copy of line so that changes can be made
    char temp[LimitRequestLine];
    memcpy(temp, line, strlen(line) + 1);
    
    // Make sure string doesn't start with white space
    if (temp[0] == ' ')
    {
        printf("error400");
        //error(400);
        return false;
    }
    
    // Split on white spaces and validate only 3 arguments exist
    int tokenInd[4];
    tokenInd[0] = 0; // First token always starts at 0
    for (int i = 1, j = 1, n = strlen(temp) + 1; i < n; i++)
    {
        // Check for delimiter; set offset and place null terminator
        if (temp[i] == ' ')
        {
            tokenInd[j++] = i + 1;
            temp[i] = '\0';
        }
        // Check for CRLF aka \r\n and replace with null terminator
        if (strcmp((temp + i), "\r\n") == 0)
        {
            temp[i] = '\0';
            break;
        }
        // If j is greater than 3, too many spaces are present in the request
        if (j > 3)
        {
            printf("error400");
            //error(400);
            return false;
        }
    }
    
    // Make individual variables for each token using acquired offsets
    char* method = temp + tokenInd[0];
    char* request_target = temp + tokenInd[1];
    char* http_version = temp + tokenInd[2];
    
    // Debug parsing
    printf("method\t%s\n",method);
    printf("request_t\t%s\n", request_target);
    printf("http_v\t%s\n", http_version);

    
    // Validate method is GET, case-sensitive per 3.1.1
    if (strcmp(method, "GET") != 0)
    {
        printf("error405\n");
        //error(405);
        return false;
    }
    
    // Validate request-target starts with forward slash
    if (request_target[0] != '/')
    {
        printf("error501\n");
        //error(501);
        return false;
    }
    
    // Validate request-target doesn't contain any double-quotes
    if (strchr(request_target, '\"'))
    {
        printf("error400\n");
        //error(400);
        return false;
    }
    
    // Validate HTTP-version
    if (strcmp(http_version, "HTTP/1.1"))
    {
        printf("error505\n");
        //error(505);
        return false;
    }
    
    // After validation, store abs_path and query
    // Parse request_target for abs_path and query strings
    int queryInd = -1;
    for (int i = 0, n = strlen(request_target); i < n; i++)
    {
        if (request_target[i] == '?')
        {
            queryInd = i;
            break;
        }
    }
    // No query found in request_target
    if (queryInd == -1)
    {
        memcpy(path, request_target, strlen(request_target));
        query[0] = '\0';
        return true;
    } 
    else if (queryInd > -1)
    {
        memcpy(path, request_target, queryInd);
        memcpy(query, request_target + queryInd + 1, strlen(request_target) - queryInd - 1);
        return true;
    }
    
    printf("error501\n");
    //error(501);
    return false;
}

int main(void)
{
    char temp1[8190];
    char temp2[8190];
    char* line = "GET /cat.html HTTP/1.1\r\n";
    
    parse(line,temp1,temp2);
    printf("temp1\t%s\n", temp1);
    printf("temp2\t%s\n", temp2);
}


