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
            usleep(50000);
        }

        // sleep thread for animation's sake
        // usleep(500000);
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
    usleep(1000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    int tilecount = d * d - 1;
    bool switch1and2 = tilecount % 2 != 0 ? true : false;
    
    for (int row = 0; row < d; row++)
    {
        for (int col = 0; col < d; col++)
        {
            board[row][col] = tilecount--;
        }
    }
    
    // Switch 1 and 2 tiles if there are an odd number of tiles
    if (switch1and2)
    {
        board[d - 1][d - 3] = 1;
        board[d - 1][d - 2] = 2;
    }
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    for (int row = 0; row < d; row++)
    {
        for (int col = 0; col < d; col++)
        {
            string spacing = board[row][col] < 10 ? "  " : " ";
            if (board[row][col] == 0)
            {
                printf("  _");
            }
            else
            {
                printf("%s%d", spacing, board[row][col]);
            }
        }
        printf("\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    // Find the tile value and zero in the 2D array
    int row_tile = -1, col_tile = -1;
    int row_zero = -1, col_zero = -1;
    for (int row = 0; row < d; row++)
    {
        for (int col = 0 ; col < d; col++)
        {
            if (board[row][col] == tile)
            {
                row_tile = row;
                col_tile = col;
            }
            else if (board[row][col] == 0)
            {
                row_zero = row;
                col_zero = col;
            }
        }
    }
    
    // Illegal move if tile or 0 not found in the array
    if (row_tile == -1 || row_zero == -1)
    {
        return false;
    }
    
    // Determine if tiles are adjacent and not diagonal to eachother
    int row_dif = abs(row_tile - row_zero);
    int col_dif = abs(col_tile - col_zero);
    bool adjacent = (row_dif <= 1) && (col_dif <= 1) && (row_dif != col_dif);
    
    // Perform Move
    if (adjacent)
    {
        board[row_tile][col_tile] = 0;
        board[row_zero][col_zero] = tile;
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    int cor_tile = 1;
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (cor_tile == d * d)
            {
                return true;
            }
            else if (board[i][j] != cor_tile++)
            {
                return false;
            }
        }
    }
    return false;
}