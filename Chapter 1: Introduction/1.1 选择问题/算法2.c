// O( N )

int SelectMax( const int A[], int N, int k )
{
    int i, j, p;
    int *B = ( int* )malloc( k * sizeof( int ) );

    for ( i = 0; i < k; i++ )
        B[i] = A[i];

    Bubble( B, k );

    for ( i = k; i < N; i++ )
    {
        if ( A[i] > B[k-1] )
            for ( j = 0; j <= k; j++ )
                if ( A[i] > B[j] )
                {
                    for ( p = k; p > j; p-- )
                        B[p] = B[p-1];
                    B[j] = A[i];
                    break;
                }
    }

    return B[k-1];
}

void Bubble( int A[], int N )
{
    int i, j;

    for ( i = 0; i < N - 1; i++ )
        for ( j = N - 1; j > i; j-- )
            if ( A[j-1] < A[j] )
                Swap( &A[j-1], &A[j] );
}

void Swap( int *a, int *b )
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}