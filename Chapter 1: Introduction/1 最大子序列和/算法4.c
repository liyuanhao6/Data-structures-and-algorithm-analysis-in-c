// O( N )

int MaxSubsequenceSum( const int A[], int N )
{
    int ThisSum, MaxSum, i;

    ThisSum = MaxSum = 0;
    for ( i = 0; i < N; i++ )
    {
        /* ThisSum is negative so ThisSum is equal to 0 */
        ThisSum += A[i];

        if ( ThisSum > MaxSum )
            MaxSum = ThisSum;
        else if ( ThisSum < 0 )
            ThisSum = 0;
    }
    
    return MaxSum;
}