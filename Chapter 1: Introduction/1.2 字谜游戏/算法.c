//

# define isFound     1
# define isNotFound  0
# define LETTERSIZE  21
# define DICTSIZE    5

char letter[4][4] = {    
            { 't', 'h', 'i', 's' },
            { 'w', 'a', 't', 's' },
            { 'o', 'a', 'h', 'g' },
            { 'f', 'g', 'd', 't' } 
};

char* dict[DICTSIZE] = { "this", "two", "fat", "that", "of" };

void Crossword( char letter[][4], char **dict )
{
    int i, j, k, max;
    char word[LETTERSIZE];
    
    for ( i = 0; i < 4; i++ )
        for ( j = 0; j < 4; j++ )
            for ( k = 0; k < 8; k++ ) // 8个方向
                for ( max = 1; max < 5; max++ )
                    if ( wordExist( i, j, k, max, word, letter, dict ) )
                    {
                        printf("%s\n", word);
                        break;
                    }
}

int wordExist( int x, int y, int dir, int maxchars, char * retword, char letter[][4], char** dict )
{
    char str[LETTERSIZE];
    int ct = 0;
    int i, j;

    for ( i = 0; i < maxchars; i++ )
    {
        str[ct] = letter[x][y];
        str[ct + 1] = '\0';
        for ( j = 0; j < DICTSIZE; j++ )
            if ( strcmp( str, dict[j] ) == 0 )
            {
                strcpy( retword, dict[j] );
                return isFound;
            }
        ct++;

        switch ( dir )
        {
            case 0:
                y++;
                break;
            case 1:
                x++;
                y--;
                break;
            case 2:
                x--;
                break;
            case 3:
                x--;
                y--;
                break;
            case 4:
                y--;
                break;
            case 5:
                x--;
                y++;
                break;
            case 6:
                x++;
                break;
            case 7:
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
