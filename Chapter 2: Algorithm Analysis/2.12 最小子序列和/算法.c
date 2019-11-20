// O( N )

int MinSubsequenceSum( const int A[], int N )
{
    int ThisSum, MinSum, i;

    ThisSum = MinSum = 0;
    for ( i = 0; i < N; i++ )
    {
        /* ThisSum is positive so ThisSum is equal to 0 */
        ThisSum += A[i];
            
        if ( ThisSum < MinSum )
            MinSum = ThisSum;
        else if ( ThisSum > 0 )
            ThisSum = 0;
    }
    
    return MinSum;
}