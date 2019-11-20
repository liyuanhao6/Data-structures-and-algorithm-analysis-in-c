// O( N * log ( log ( N ) ) )

# define True  1
# define False 0

void ArrayPrime ( int N )
{
    int i, j;
    int *array = ( int* )malloc( ( N + 1 ) * sizeof( int ) );

    /* True isn't Prime, False is Prime */
    
    for ( i = 0; i <= 1; i++ ) // Initialize the array from 0 to 1 by True
        array[i] = True;
    for ( i = 2; i <= N; i++ ) // Initialize the array from 2 to N by False
        array[i] = False;
    for ( i = 2; i <= N; i++ )
        if ( array[i] == False )
        {
            printf("%d ", i);
            for ( j = 2 * i; j <= N; j += i) // assign n * Prime by True
                array[j] = True;
        }
}
