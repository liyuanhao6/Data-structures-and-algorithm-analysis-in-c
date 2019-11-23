// O( N )

struct Node
{
    int Element;
    struct Node* Next;
};

struct Node* NodeCreat( void );
void ListDelete( struct Node* List );
void NodeInsert( struct Node* P, int data );
void ListPrint( struct Node* List );
int GetPosition( int Radix, int data, int NowLength );
void RadixSort( struct Node *List, int Length, int Radix );
void test(void);

struct Node* NodeCreat( void )
{
    struct Node* temp = NULL;

    temp = ( struct Node* )malloc( sizeof( struct Node ) );
    temp->Next = NULL;

    return temp;
}

void ListDelete( struct Node* List )
{
    struct Node *P = NULL, *Q = NULL;

    P = List->Next;
    List->Next = NULL;

    while ( P != NULL )
    {
        Q = P;
        P = P->Next;
        free( Q );
    }

}

void NodeInsert( struct Node* P, int data )
{
    struct Node *temp = NULL;

    temp = ( struct Node* )malloc( sizeof( struct Node ) );

    temp->Next = NULL;
    temp->Element = data;
    P->Next = temp;
}

void ListPrint( struct Node* List )
{
    struct Node* P = NULL;

    P = List->Next;

    while ( P != NULL )
    {
        printf("%d ", P->Element);
        P = P->Next;
    }

    putchar('\n');
}

int GetPosition( int Radix, int data, int NowLength )
{
    int temp = 1;
    int i;

    for ( i = 0; i < NowLength - 1; i++ )
        temp *= Radix;
    
    return ( data / temp ) % Radix;
}

void RadixSort( struct Node *List, int Length, int Radix )
{
    struct Node *Array[Radix], *temp = NULL, *P = NULL, *Q = NULL;
    int i, j;

    for ( i = 0; i < Radix; i++ )
        Array[i] = NodeCreat();
    
    for ( i = 0; i < Length; i++ )
    {
        P = List;
        while( P->Next != NULL )
        {
            Q = P->Next;
            P->Next = Q->Next;
            Q->Next = NULL;
            
            int Position = GetPosition( Radix, Q->Element, i + 1 );
            temp = Array[Position];
            while ( temp->Next != NULL )
                temp = temp->Next;
            temp->Next = Q;
        }

        printf("%dth Allocation\n", i+1);
        for ( j = 0; j < Radix; j++ )
        {
            printf("N-%d ", j);
            ListPrint(Array[j]);
        }

        P = List;
        for ( j = 0; j < Radix; j++ )
        {
            Q = Array[j];
            while ( Q->Next != NULL )
            {
                temp = Q->Next;
                Q->Next = temp->Next;
                temp->Next = NULL;
                P->Next = temp;
                P = P->Next;
            }
        }

        printf("%dth Collection\n", i+1);
        ListPrint(List);
    }

    for ( i = 0; i < Radix; i++ )
        ListDelete(Array[i]);
}