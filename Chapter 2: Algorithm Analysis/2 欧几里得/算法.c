// O( logN )

unsigned int Gcd ( unsigned int M, unsigned int N )
{
    unsigned int Rem;

    while ( N > 0 )
    {
        Rem = M % N;
        M = N;
        N = Rem;
    }
    
    return M;
}
