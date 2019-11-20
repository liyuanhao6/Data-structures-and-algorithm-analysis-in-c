# define True  1
# define False 0

struct List
{
    struct List* node;
    int data;
} p, head ;

struct List* CreatList( int ct );
int IsEmpty( struct List* head );
int IsLast( struct List* p );
struct List* Find( struct List* head, int num );
struct List* FindPrevious( struct List* head, int num );
struct List* Delect( struct List* head, int num );
struct List* Insert( struct List* head, int num, int pos);

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

void DelectList( struct List* head )
{
    struct List *temp = NULL, *p = NULL;

    p = head->node;
    free ( head );

    while ( p != NULL )
    {
        temp = p;
        p = temp->node;
        free( temp );
    }
}

void TraverseList( struct List* head )
{
    int index = 0;
    struct List *p = NULL;

    p = head->node;

    while ( p != NULL )
    {
        printf("%d ", p->data);
        index++;
        if ( index / 5 == 0 )
            putchar('\n');
    }
}

int IsEmpty( struct List* head )
{
    if ( head->node == NULL )
        return True;
    else    
        return False;
}

int IsLast( struct List* p )
{
    if ( p->node == NULL )
        return True;
    else    
        return False;
}

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
