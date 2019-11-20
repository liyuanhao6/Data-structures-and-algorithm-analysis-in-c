// O( N )

long int Pow( long int X, unsigned int N ) // The Product in proper order
{
    if ( N == 1 )
        return 1;
    else
        return Pow( X, N-1 );
}