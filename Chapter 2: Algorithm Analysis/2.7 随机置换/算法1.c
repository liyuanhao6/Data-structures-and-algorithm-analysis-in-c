// O( N^2 )

int *RandArray ( int i, int j )
{
    int *array = NULL;
    int p, q, num, flag;

    array =  ( int* ) malloc( sizeof( int ) * ( j - i + 1 ) ); // Allocate memory for ( j - i + 1 ) * int
    for ( p = 0; p < j - i + 1; p++ )
    {
        flag = 1; // The flag value
        num = RandInt( i, j ); // The random number for i to j
        for ( q = 0; q < p; q++ )
            if ( array[q] == num )
            {
                flag = 0;
                break;
            }

        if ( flag )
            array[p] = num; // num in the array
        else
            p--; // go back
    }
    
    return array;
}

int RandInt( int i, int j )
{
    return rand() % (j - i + 1) + i;
}