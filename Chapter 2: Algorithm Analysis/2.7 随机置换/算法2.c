// O( N )

int *RandArray ( int i, int j )
{
    int *array = NULL, *UsedArray = NULL;
    int p, num;

    array =  ( int* ) malloc( sizeof( int ) * ( j - i + 1 ) );
    UsedArray = ( int* ) malloc( sizeof( int ) * ( j - i + 1 ) ); // The flag array to store used number
    for ( p = 0; p < j - i + 1; p++ ) // Initialize the used array
        UsedArray[p] = 0;

    for ( p = 0; p < j - i + 1; p++ )
    {
        num = RandInt( i, j ); // The random number for i to j

        if ( UsedArray[num - i] ) // The number is used
            p--;
        else // The number isn't used
        {
            array[p] = num;
            UsedArray[num - i] = 1;
        }
    }
    
    free(UsedArray); // free the memory
    
    return array;
}

int RandInt( int i, int j )
{
    return rand() % (j - i + 1) + i;
}