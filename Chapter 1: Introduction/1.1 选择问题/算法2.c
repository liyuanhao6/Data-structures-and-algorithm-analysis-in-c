// O( N )

int SelectMax( const int A[], int N, int k )
{
    int i, j, p;
    int *B = ( int* )malloc( k * sizeof( int ) ); // Allocate memory for K * int

    for ( i = 0; i < k; i++ ) // B is equal to A which from 0 to K-1
        B[i] = A[i];

    Bubble( B, k ); // The Bubble Sort

    for ( i = k; i < N; i++ )
    {
        if ( A[i] > B[k-1] ) // A[i] and the Kth of B
            for ( j = 0; j <= k; j++ )
                if ( A[i] > B[j] )
                {
                    for ( p = k; p > j; p-- ) // Delete the min of B
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
                Swap( &A[j-1], &A[j] ); // The function of swap
}

void Swap( int *a, int *b )
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}