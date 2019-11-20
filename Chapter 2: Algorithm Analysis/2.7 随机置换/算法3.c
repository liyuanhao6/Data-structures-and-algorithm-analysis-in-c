// O( N )

int *RandArray ( int i, int j )
{
    int *array = NULL;
    int p;

    array =  ( int* ) malloc( sizeof( int ) * ( j - i + 1 ) ); // The flag array to store used number
    
    for ( p = i; p < j + 1; p++ ) // Initialize the array
        array[p-i] = p;

    for ( p = 0; p < j - i + 1; p++ )
        Swap( &array[p], &array[RandInt(0, j - i + 1)] ); // random exchange
    
    return array;
}

int RandInt( int i, int j )
{
    return rand() % (j - i) + i;
}

void Swap( int* num1, int* num2) // The function of swap
{
    int temp;

    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}