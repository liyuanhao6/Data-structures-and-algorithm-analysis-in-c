// O( logN )


# define True  1
# define False 0

long int Pow( int X, int N )
{
    long int temp = 1;

    while ( N > 1 )
    {
        if ( N % 2 )
            temp *= X;
        else
            ;
        temp *= temp;
        N /= 2;
    }
    if ( N )
        return temp * X;
    else
        return 0;
    
}