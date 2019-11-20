# define True  1
# define False 0

struct List
{
    struct List* node;
    int data;
} p, head ;

// O( N )

struct List* CreatList( int ct )
{
    struct List *head = NULL, *p = NULL, *q = NULL;
    int temp, i;

    for ( i = 0; i < ct; i++ )
    {
        p = ( struct List* )malloc( sizeof( struct List ) );

        scanf("%d", &temp);
        p->data = temp;
        p->node = NULL;

        if ( head == NULL )
            head->node = p;
        else
            q->node = p;

        q = p;
    }

    return head;
}

// O( 1 )

int IsEmpty( struct List* head )
{
    if ( head->node == NULL )
        return True;
    else    
        return False;
}

// O( 1 )

int IsLast( struct List* p )
{
    if ( p->node == NULL )
        return True;
    else    
        return False;
}

// O( N )

struct List* Find( struct List* head, int num )
{
    struct List *p = NULL;

    p = head->node;

    while ( p != NULL && p->data != num )
        p = p->node;
    
    return p;

}

// O( N )

struct List* FindPrevious( struct List* head, int num )
{
    struct List *p = NULL;

    p = head;

    while ( p->node != NULL && p->node->data != num )
        p = p->node;
    
    return p;


}

// O( N )

struct List* Delect( struct List* head, int num )
{
    struct List *p = NULL *q = NULL;

    p = FindPrevious( head, num );

    if ( IsLast(p) )
        return head;
    else
    {
        q = p->node;
        p->node = p->node->node;
        free( q );
        return head;
    }
        
}

// O( N )

struct List* Insert( struct List* head, int num, int pos)
{
    struct List *p = head, *temp = NULL;
    int i;

    temp = ( struct List* )malloc( sizeof( struct List ) );
    if ( pos == 1)
    {
        temp->node = p->node;
        temp->data = num;
        head->node = temp;
    }
    else
    {
        for ( i = 1; i < pos; i++ )
            p = p->node;
        
        temp->node = p->node;
        temp->data = num;
        p->node = temp;
    }

    return head;
}
