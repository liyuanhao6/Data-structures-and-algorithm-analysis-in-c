# define True  1
# define False 0
# define MaxSize 10

typedef struct Node
{
    int Element;
    struct Node *Next;
} *Stack;

int IsEmpty( Stack S );
void Pop( Stack S );
void Push( int data, Stack S );
int Top( Stack S );
void MakeEmpty( Stack S );
void DisposeStack( Stack S );
Stack CreateStack( void );

int IsEmpty( Stack S )
{
    if ( S->Next == NULL )
        return True;
    else
        return False;
}

void Pop( Stack S )
{
    struct Node *Temp;

    if ( IsEmpty( S ) )
        printf("Empty stack!\n");
    else
    {
        Temp = S->Next;
        S->Next = Temp->Next;
        free( Temp );
    }
}

void Push( int data, Stack S )
{
    struct Node *Temp;

    Temp = ( Stack )malloc( sizeof( struct Node ) );

    if ( Temp == NULL )
        printf("Out of space!\n");
    else
    {
        Temp->Next = S->Next;
        Temp->Element = data;
        S->Next = Temp;
    }
}

int Top( Stack S )
{
    if ( !IsEmpty( S ) )
        return S->Next->Element;

    printf("Empty Stack!\n");
    return False;
}

void MakeEmpty( Stack S )
{
    if ( S == NULL )
        printf("Must use CreateStack first !\n");
    else
        while( !IsEmpty( S ) )
            Pop( S );
}

void DisposeStack( Stack S )
{
    while ( !IsEmpty( S ) )
        MakeEmpty( S );
    
    free( S );
}

Stack CreateStack( void )
{
    Stack P;

    P = ( Stack )malloc( sizeof( struct Node ) );

    P->Next = NULL;

    return P;
}



