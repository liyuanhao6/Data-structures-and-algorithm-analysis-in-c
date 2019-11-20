// O( N^3 )

int MaxSubsequenceSum( const int A[], int N )
{
    int ThisSum, MaxSum, i, j, k;

    MaxSum = 0;
    for ( i = 0; i < N; i++ ) // 基准
        for ( j = i; j< N; j++ ) // 结尾
        {
            ThisSum = 0;
            for ( k = i; k <= j; k++ ) // 清点i到j
                ThisSum += A[k];
            
            if ( ThisSum > MaxSum )
                MaxSum = ThisSum;
        }
    
    return MaxSum;
}
