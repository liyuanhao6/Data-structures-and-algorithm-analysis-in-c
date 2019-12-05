# define True  1
# define False 0

typedef struct Node
{
    struct Node* Next;
    int Element;
} *List;

List CreatList( int ct );
int IsEmpty( List head );
int IsLast( List p );
List Find( List head, int num );
List FindPrevious( List head, int num );
List Delete( List head, int num );
List Insert( List head, int num, int pos);

List CreatList( int ct )
{
    struct Node *head = NULL, *p = NULL, *q = NULL;
    int temp, i;

    for ( i = 0; i < ct; i++ )
    {
        p = ( struct List* )malloc( sizeof( struct Node ) );

        scanf("%d", &temp);
        p->Element = temp;
        p->Next = NULL;

        if ( head == NULL )
            head->Next = p;
        else
            q->Next = p;

        q = p;
    }

    return head;
}

void DelectList( List head )
{
    struct Node *temp = NULL, *p = NULL;

    p = head->Next;
    free ( head );

    while ( p != NULL )
    {
        temp = p;
        p = temp->Next;
        free( temp );
    }
}

void TraverseList( List head )
{
    int index = 0;
    struct Node *p = NULL;

    p = head->node;

    while ( p != NULL )
    {
        printf("%d ", p->Element);
        index++;
        if ( index / 5 == 0 )
            putchar('\n');
    }
}

int IsEmpty( List head )
{
    if ( head->Next == NULL )
        return True;
    else    
        return False;
}

int IsLast( List p )
{
    if ( p->Next == NULL )
        return True;
    else    
        return False;
}

List Find( List head, int num )
{
    struct Node *p = NULL;

    p = head->Next;

    while ( p != NULL && p->Element != num )
        p = p->Next;
    
    return p;
}

// O( N )

List FindPrevious( List head, int num )
{
    struct Node *p = NULL;

    p = head;

    while ( p->Next != NULL && p->Next->Element != num )
        p = p->Next;
    
    return p;
}

List Delete( List head, int num )
{
    struct Node *p = NULL, *q = NULL;

    p = FindPrevious( head, num );

    if ( IsLast(p) )
        return head;
    else
    {
        q = p->Next;
        p->Next = p->Next->Next;
        free( q );
        return head;
    }  
}

List Insert( List head, int num, int pos)
{
    struct Node *p = head, *temp = NULL;
    int i;

    temp = ( struct List* )malloc( sizeof( struct Node ) );
    if ( pos == 1)
    {
        temp->Next = p->Next;
        temp->Element = num;
        head->Next = temp;
    }
    else
    {
        for ( i = 1; i < pos; i++ )
            p = p->Next;
        
        temp->Next = p->Next;
        temp->Element = num;
        p->Next = temp;
    }

    return head;
}
