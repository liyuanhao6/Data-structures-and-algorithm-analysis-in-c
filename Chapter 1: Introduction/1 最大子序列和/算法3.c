// O( N * logN )

static int MaxSubSum( const int A[], int Left, int Right )
{
    int MaxLeftSum, MaxRightSum;
    int MaxLeftBorderSum, MaxRightBorderSum;
    int LeftBorderSum, RightBorderSum;
    int Center, i;

    if ( Left == Right) // Base Case
        if ( A[ Left ] > 0 )
            return A[ Left ];
        else
            return 0;

    /* Divide-And-Conquer method */
    Center = ( Left + Right ) / 2;
    MaxLeftSum = MaxSubSum( A, Left, Center );
    MaxRightSum = MaxSubSum( A, Center + 1, Right );

    MaxLeftBorderSum = 0;
    LeftBorderSum = 0;
    for ( i = Center; i >= Left; i--) // From A[Left] to A[Center]
    {
        LeftBorderSum += A[i];
        if ( LeftBorderSum > MaxLeftBorderSum )
            MaxLeftBorderSum = LeftBorderSum;
    }

    MaxRightBorderSum = 0;
    RightBorderSum = 0;
    for ( i = Center + 1; i <= Right; i++ ) // From A[Center+1] to A[Right]
    {
        RightBorderSum += A[i];
        if ( RightBorderSum > MaxRightBorderSum )
            MaxRightBorderSum = RightBorderSum;
    }

    return Max3( MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum );

}

int MaxSubsequenceSum( const int A[], int N )
{
    return MaxSubSum( A, 0, N-1 );
}

int Max3( int num1, int num2, int num3 )
{
    int Max;

    Max = ( num1 >= num2 ) ? num1 : num2;
    Max = ( num3 >= Max ) ? num3 : Max;

    return Max;

}