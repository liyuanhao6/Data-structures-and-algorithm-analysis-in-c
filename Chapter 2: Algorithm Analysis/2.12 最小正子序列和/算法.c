// O( N^2 )

int MinSubsequencePositiveSum( const int A[], int N )
{
    int ThisSum, MinPositiveSum, i, j;

    for ( i = 0; i < N; i++ )
        if ( A[i] > 0 )
            MinPositiveSum = A[i];

    for ( i = 0; i < N; i++ )
    {
        ThisSum = 0;
        for ( j = i; j < N; j++ )
        {
            ThisSum += A[j];
            if ( ThisSum < MinPositiveSum && ThisSum > 0 )
                MinPositiveSum = ThisSum;
        }
    }

    return MinPositiveSum;
}