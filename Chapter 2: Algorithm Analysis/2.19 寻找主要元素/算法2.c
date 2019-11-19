// O( N )

# define isNotFound 0

int FindPivot( const int A[] , int N )
{
    int i;
    int Base = A[0], BaseCount = 0, Count = 0;

    for ( i = 0; i < N; i++ )
    {
        if ( Base == A[i] )
            BaseCount++;
        else
            BaseCount--;
        
        if ( BaseCount == 0 )
        {
            Base = A[i--];
            BaseCount = 0;
        }
    }


    for ( i = 0; i < N; i++ )
        if ( Base == A[i] )
            Count++;
    
    if ( Count > N / 2 )
        return Base;
    else
        return isNotFound;

}
