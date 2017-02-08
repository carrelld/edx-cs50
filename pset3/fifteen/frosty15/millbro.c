/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        //usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    int number = (d*d)-1;
    for (int row=0; row<d; row++)
        {
             for (int col=0; col<d ; col++)
            {
                 board[row][col] = number;
                 number--;
            }
        }
    if (board[0][0] % 2 ==1)
    {
        board[d-1][d-2]=2;
        board[d-1][d-3]=1;
    }
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    // TODO
   
    for (int row=0; row<d; row++)
    {
        for (int col=0; col<d ; col++)
        {
            if (board[row][col]==0)
            {
                printf ("_ ");
            }
            else
            {
                printf("%2d", board[row][col]);
                printf (" ");
            }
        }
    printf ("\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    int blankRow=0, blankCol=0, tileRow=0, tileCol=0, temp = 0;
    
    // Find coordinates for zero in array
    for (int row=0; row<d; row++)
    {
        for (int col=0; col<d ; col++)
        {
            if (board[row][col]==0)
            {
                blankRow = row;
                blankCol =col;
            }
        }
    }
    
    // Find coordinates for tile in array    
    for (int row=0; row<d; row++)
    {
        for (int col=0; col<d ; col++)
        {
            if (board[row][col]==tile)
            {
                tileRow = row;
                tileCol = col;
            }
        }
    }
    
    // Check each adjacent index for 0 and swap
    if (board[blankRow][blankCol] == board[tileRow][tileCol-1])
        {
            temp = board[tileRow][tileCol];
            board[tileRow][tileCol] = board[tileRow][tileCol-1];
            board[tileRow][tileCol-1] = temp;
            return true;
        }
    
    if (board[blankRow][blankCol] == board[tileRow][tileCol+1])
        {
            board[tileRow][tileCol] = 0;
            printf("%i, %i\n",tileRow,tileCol+1);
            usleep(1000000);
            board[tileRow][tileCol+1] = tile;
            return true;
        }
    
    if (board[blankRow][blankCol] == board[tileRow-1][tileCol])
        {
            temp = board[tileRow][tileCol];
            board[tileRow][tileCol] = board[tileRow-1][tileCol];
            board[tileRow-1][tileCol] = temp;
            return true;
        }
    
    if (board[blankRow][blankCol] == board[tileRow+1][tileCol])
        {
            temp = board[tileRow][tileCol];
            board[tileRow][tileCol] = board[tileRow+1][tileCol];
            board[tileRow+1][tileCol] = temp;
            return true;
        }
    
    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    // TODO
    return false;
}