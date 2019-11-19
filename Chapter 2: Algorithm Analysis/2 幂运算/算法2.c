// O( logN )

unsigned int Pow ( long int X, unsigned int N )
{
    if ( N == 0 )
        return 1;
    else if ( N == 1 )
        return X;
    else if ( N % 2 == 0)
        return Pow ( X * X, N / 2 );
    else 
        return Pow ( X * X, N / 2 ) * X;
}
