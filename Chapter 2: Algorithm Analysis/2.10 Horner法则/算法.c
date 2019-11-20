// O( N )

int Horner( const int A[] , int N , int x )
{
    int Poly = 0;
    int i;

    for ( i = N - 1; i >= 0; i-- )
        Poly = Poly * x + A[i]; // Polynomial

    return Poly;
}