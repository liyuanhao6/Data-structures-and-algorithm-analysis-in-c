// O( logN )


int quick_algorithm(a,b,c)
{
    int i;
    int ans = 1;

    a = a % c;
    while ( b != 0 )
    {
        if ( b & 1 )
            ans = ( ans * a ) % c;
        b >>= 1;
        a = ( a * a ) % c;
    }

    return ans;
}