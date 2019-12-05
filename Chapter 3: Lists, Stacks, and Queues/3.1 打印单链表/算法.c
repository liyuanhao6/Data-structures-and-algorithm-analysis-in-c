struct List
{
    struct List* node;
    int data;
};

void PrintList( struct List* L )
{
    struct List* P;

    P = L->node;
    printf( "%d ", P->data );

    while ( P->node != NULL )
    {
        P = P->node;
        printf( "%d ", P->data );
    }

}