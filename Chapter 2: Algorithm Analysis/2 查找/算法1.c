// O( N )

# define NotFound -1

int LineSearch( const ElementType A[], ElementType X, int N) // The Line Search
{
    int i;

    for ( i = 0; i < N; i++ )
        if ( A[i] == X )
            return i;
    
    return NotFound;
        
}