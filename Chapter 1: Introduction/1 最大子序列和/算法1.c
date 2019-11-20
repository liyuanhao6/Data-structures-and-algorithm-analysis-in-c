// O( N^3 )

int MaxSubsequenceSum( const int A[], int N )
{
    int ThisSum, MaxSum, i, j, k;

    MaxSum = 0;
    for ( i = 0; i < N; i++ ) // Base
        for ( j = i; j< N; j++ ) // Tail
        {
            ThisSum = 0;
            for ( k = i; k <= j; k++ ) // From A[i] to A[j]
                ThisSum += A[k];
            
            if ( ThisSum > MaxSum )
                MaxSum = ThisSum;
        }
    
    return MaxSum;
}