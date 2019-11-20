// O( N^2 )

int SelectMax( const int A[] , int N, int k )
{
    int *B = ( int* )malloc( N * sizeof( int ) ); // 分配 N*int 的内存
    int i;

    for ( i = 0; i < N; i++ )
        B[i] = A[i]; // B数组与A数组一致

    Bubble( B, N );

    return B[k-1];
}

void Bubble( int A[], int N ) // 冒泡排序
{
    int i, j;

    for ( i = 0; i < N - 1; i++ )
        for ( j = N - 1; j > i; j-- )
            if ( A[j-1] < A[j] )
                Swap( &A[j-1], &A[j] );
}

void Swap( int *a, int *b ) // 交换函数
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
