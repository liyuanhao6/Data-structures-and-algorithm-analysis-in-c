// O( N )

int *RandArray ( int i, int j )
{
    int *array = NULL, *UsedArray = NULL;
    int p, num;

    array =  ( int* ) malloc( sizeof( int ) * ( j - i + 1 ) );
    UsedArray = ( int* ) malloc( sizeof( int ) * ( j - i + 1 ) );
    for ( p = 0; p < j - i + 1; p++ )
        UsedArray[p] = 0;

    for ( p = 0; p < j - i + 1; p++ )
    {
        num = RandInt( i, j );

        if ( UsedArray[num - i] )
            p--;
        else
        {
            array[p] = num;
            UsedArray[num - i] = 1;
        }
    }
    
    free(UsedArray);
    
    return array;
}

int RandInt( int i, int j )
{
    return rand() % (j - i + 1) + i;
}