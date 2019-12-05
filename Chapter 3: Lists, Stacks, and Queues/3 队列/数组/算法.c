# define MAXSIZE 100
# define TRUE  1
# define FALSE 0

struct QueueRecord
{
    int Capacity;
    int Front;
    int Rear;
    int Size;
    int *Array;
};

int IsEmpty( struct QueueRecord* Q );
int IsFULL( struct QueueRecord* Q );
void MakeEmpty( struct QueueRecord* Q );
struct QueueRecord* CreatQueue( void );
void DisposeQueue( struct QueueRecord* Q );
int Succ( struct QueueRecord* Q, int Position );
void Enqueue( struct QueueRecord* Q, int data );
void Dequeue( struct QueueRecord* Q );
int Front( struct QueueRecord* Q );


int IsEmpty( struct QueueRecord* Q )
{
    if ( Q->Front == Q->Rear )
        return TRUE;
    else
        return FALSE;
}

int IsFULL( struct QueueRecord* Q )
{
    if ( Q->Front - Q->Rear == 1 && Q->Front + Q->Rear + 1 == Q->Size )
        return TRUE;
    else
        return FALSE;
}

void MakeEmpty( struct QueueRecord* Q )
{
    Q->Size = 0;
    Q->Front = 0;
    Q->Rear = Q->Capacity - 1;
}

struct QueueRecord* CreatQueue( void )
{
    struct QueueRecord* Q;

    Q = ( struct QueueRecord* )malloc( sizeof( struct QueueRecord ) );
    Q->Capacity = MAXSIZE;
    MakeEmpty( Q );
    Q->Array = ( int* )malloc( sizeof( int ) );

    return Q;
}

void DisposeQueue( struct QueueRecord* Q )
{
    free( Q->Array );
    free( Q );
}

int Succ( struct QueueRecord* Q, int Position )
{
    if ( ++Position == Q->Capacity )
        Position = 0;

    return Position;
}

void Enqueue( struct QueueRecord* Q, int data )
{
    Q->Rear = Succ( Q, Q->Rear );
    
    Q->Size++;
    Q->Array[Q->Rear] = data;
}

void Dequeue( struct QueueRecord* Q )
{
    Q->Front = Succ( Q, Q->Front );

    Q->Size--;
}

int Front( struct QueueRecord* Q )
{
    if ( !IsEmpty( Q ) )
        return Q->Array[Q->Front];
    else
        return FALSE;
}

int FrontAndDequeue( struct QueueRecord* Q )
{
    if ( !IsEmpty( Q ) )
    {
        Q->Front = Succ( Q, Q->Front );
        Q->Size--;
        return Q->Array[Q->Front];
    }
    else
        return FALSE;
}