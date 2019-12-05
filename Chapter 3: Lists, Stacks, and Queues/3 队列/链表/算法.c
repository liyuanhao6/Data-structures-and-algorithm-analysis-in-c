# define True  1
# define False 0

struct Node
{
    int Element;
    struct Node *Next;
};

struct Queue
{
    struct Node* Front;
    struct Node* Rear;
};

int IsEmpty( struct Queue* Q );
struct Queue* CreateQueue( void );
void Dequeue( struct Queue* Q );
void Enqueue( struct Queue* Q, int data );
int Front( struct Queue* Q );
int FrontAndDequeue( struct Queue* Q );
void MakeEmpty( struct Queue* Q );
void DisposeQueue( struct Queue* Q );

int IsEmpty( struct Queue* Q )
{
    if ( Q->Front == Q->Rear )
        return True;
    else
        return False;
}

struct Queue* CreateQueue( void )
{
    struct Queue* Q = NULL;

    Q = ( struct Queue* )malloc( sizeof( struct Queue ) );

    Q->Front = Q->Rear = ( struct Node* )malloc( sizeof( struct Node ) );

    Q->Front->Next = NULL;

    return Q;
}

void Dequeue( struct Queue* Q )
{
    if ( !IsEmpty( Q ) )
    {
        struct Node* temp = NULL;

        temp = ( struct Node* )malloc( sizeof( struct Node ) );

        temp = Q->Front->Next;
        Q->Front->Next = temp->Next;

        free( temp );

        if ( Q->Rear == temp )
            Q->Rear = Q->Front;
    }
}

void Enqueue( struct Queue* Q, int data )
{
    struct Node* temp = NULL;

    temp = ( struct Node* )malloc( sizeof( struct Node ) );

    temp->Element = data;
    temp->Next = NULL;

    Q->Rear->Next = temp;
    Q->Rear = temp;
}
void MakeEmpty( struct Queue* Q )
{

    while ( !IsEmpty( Q ) )
        Dequeue( Q );
}

void DisposeQueue( struct Queue* Q )
{
    while ( !IsEmpty( Q ) )
        Dequeue( Q );
    free( Q );
}

int Front( struct Queue* Q )
{
    if ( !IsEmpty( Q ) )
        return Q->Front->Next->Element;
    
    return False;
}

int FrontAndDequeue( struct Queue* Q )
{
    if ( !IsEmpty( Q ) )
    {
        struct Node* temp = NULL;
        int data;

        temp = ( struct Node* )malloc( sizeof( struct Node ) );

        temp = Q->Front->Next;
        data = temp->Element;
        Q->Front->Next = temp->Next;
        free( temp );

        if ( Q->Rear == temp )
            Q->Rear = Q->Front;

        return data;
    }

    return False;
}