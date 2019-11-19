// O( sqrt( N ) )

# define True  1
# define False 0

int isPrime( int N )
{
    int i;
    int flag = 1;

    if ( N == 1 )
        flag = 0;
    else if ( N <= 3)
        flag = 1;
    else
    {
        for ( i = 2; i*i <= N; i++ )
            if ( N % i == 0 )
            {
                flag = 0;
                break;
            }
    }
    
    if ( flag )
        return True;
    else
        return False;
}