// O( N )

# define isNotFound 0

int FindPivot( const int A[] , int N )
{
    int i;
    int index = 0, count = 0;
    int *B = ( int* )malloc( ( N + 1 ) / 2 ); // Could overlook the array B

    if ( N % 2 )
    {
        for ( i = 0; i < N - 1; i += 2 )
            if ( A[i] == A[i+1] )
                B[index++] = A[i];
        B[index++] = A[i];

        for ( i = 0; i < N; i++ )
            if ( A[N-1] == A[i] )
                count++;
        
        if ( count > N / 2 )
            index = 1;
        else
            index = 0;

    }
    else
    {
        for ( i = 0; i < N; i += 2 )
            if ( A[i] == A[i+1] )
                B[index++] = A[i];
    }


    if ( index == 1 )
        return B[--index];
    else if ( index == 0 )
        return isNotFound;
    else
        return FindPivot( B, index);
}

