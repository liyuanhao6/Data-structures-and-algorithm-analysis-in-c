//

# define isFound     1
# define isNotFound  0
# define LETTERSIZE  21
# define DICTSIZE    5

char letter[4][4] = {               // Letter
            { 't', 'h', 'i', 's' },
            { 'w', 'a', 't', 's' },
            { 'o', 'a', 'h', 'g' },
            { 'f', 'g', 'd', 't' } 
};

char* dict[DICTSIZE] = { "this", "two", "fat", "that", "of" }; // Dictionary

void Crossword( char letter[][4], char **dict )
{
    int i, j, k, max;
    char word[LETTERSIZE];
    
    for ( i = 0; i < 4; i++ ) // The row
        for ( j = 0; j < 4; j++ ) // The column
            for ( k = 0; k < 8; k++ ) // 8 directions
                for ( max = 1; max < 5; max++ ) // The max of number of letter of word
                    if ( wordExist( i, j, k, max, word, letter, dict ) ) // Do or not word exist
                    {
                        printf("%s\n", word);
                        break;
                    }
}

int wordExist( int x, int y, int dir, int maxchars, char* retword, char letter[][4], char** dict )
{
    char str[LETTERSIZE]; // Get the word
    int ct = 0;
    int i, j;

    for ( i = 0; i < maxchars; i++ )
    {
        str[ct] = letter[x][y];
        str[ct + 1] = '\0';
        for ( j = 0; j < DICTSIZE; j++ )
            if ( strcmp( str, dict[j] ) == 0 ) // str is equal to dict[j]
            {
                strcpy( retword, dict[j] ); // return retword
                return isFound;
            }
        ct++;

        switch ( dir )
        {
            case 0: // East
                y++;
                break;
            case 1: // Northeast
                x++;
                y--;
                break;
            case 2: // North
                x--;
                break;
            case 3: // Northwest
                x--;
                y--;
                break;
            case 4: // West
                y--;
                break;
            case 5: // Southwest
                x--;
                y++;
                break;
            case 6: // South
                x++;
                break;
            case 7: // Southeast
                x++;
                y++;
                break;
            default:
                printf("Direction error!\n");
                return isNotFound;
        }
    }
    return isNotFound;
}
