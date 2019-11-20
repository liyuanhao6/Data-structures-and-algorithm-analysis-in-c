// O( N^2 )

int SelectMax( const int A[] , int N, int k )
{
    int *B = ( int* )malloc( N * sizeof( int ) ); // Allocate memory for N * int
    int i;

    for ( i = 0; i < N; i++ ) // B is equal to A
        B[i] = A[i]; 

    Bubble( B, N ); // The Bubble Sort

    return B[k-1]; // The Kth number
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