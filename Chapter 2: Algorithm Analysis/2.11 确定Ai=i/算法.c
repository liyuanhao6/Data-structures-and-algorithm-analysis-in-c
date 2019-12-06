// O( logN )

# define isNotFound -1

int Judge( const int A[], int N )
{
    int min, max, mid;

    min =  0;
    max = N - 1;

    while ( min <= max )
    {
        mid = ( min + max ) / 2;

        if ( mid < A[mid] )
            max = mid-1;
        else if ( mid > A[mid] )
            min = mid+1;
        else
            return mid;
    }

    return isNotFound;
    
}