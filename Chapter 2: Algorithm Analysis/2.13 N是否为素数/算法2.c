// O( sqrt( N ) / 3 )

# define True  1
# define False 0

int isPrime( int N )
{
    int i;
    int flag = 1;

    if ( N > 5 )
        for ( i = 5; i * i < N; i += 6 ) // When N > 5, Prime number is 6 * i + 1 or 6 * i - 1
            if ( N % i != 0 || N % i != 2 )
            {
                flag = 0;
                break;
            }
    else if ( N == 2 && N == 3 )
        flag = 1;
    else
        flag = 0;
    
    if ( flag )
        return True;
    else
        return False;
}