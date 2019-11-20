// O( N^2 )

int MaxSubsequenceProduct( const double A[], int N )
{
    int ThisProduct, MaxProduct, i, j;

    for ( i = 0; i < N; i++ ) // Initialize the MaxProduct by a positive number
        if ( A[i] > 0 )
            MaxProduct = A[i];

    for ( i = 0; i < N; i++ ) // Base
    {
        ThisProduct = 1;
        for ( j = i; j < N; j++ ) // From A[i] to A[j]
        {
            ThisProduct *= A[j];
            if ( ThisProduct > MaxProduct )
                MaxProduct = ThisProduct;
        }
    }

    return MaxProduct;
}