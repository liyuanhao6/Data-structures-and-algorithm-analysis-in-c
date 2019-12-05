typedef struct Node
{
    struct Node* Next;
    int Element;
} *List;

void PrintList( List L )
{
    struct Node* P = NULL;

    P = L->Next;
    printf( "%d ", P->Element );

    while ( P->Next != NULL )
    {
        P = P->Next;
        printf( "%d ", P->Element );
    }

}