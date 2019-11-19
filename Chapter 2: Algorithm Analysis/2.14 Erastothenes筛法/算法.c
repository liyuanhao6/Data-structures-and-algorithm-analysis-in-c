// O( N * log ( log ( N ) ) )

# define True  1
# define False 0

void ArrayPrime ( int N )
{
    int i, j;
    int *array = ( int* )malloc( ( N + 1 ) * sizeof( int ) );

    for ( i = 0; i <= 1; i++ )
        array[i] = True;
    for ( i = 2; i <= N; i++ )
        array[i] = False;
    for ( i = 2; i <= N; i++ )
        if ( array[i] == False )
        {
            printf("%d ", i);
            for ( j = 2 * i; j <= N; j += i)
                array[j] = True;
        }
}
