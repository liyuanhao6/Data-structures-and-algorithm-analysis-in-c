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
int IsFull( struct QueueRecord* Q );
void MakeEmpty( struct QueueRecord* Q );
struct QueueRecord* CreatQueue( int Size );
void DisposeQueue( struct QueueRecord* Q );
int Succ( struct QueueRecord* Q, int Position );
void Enqueue( struct QueueRecord* Q, int data );
void Dequeue( struct QueueRecord* Q );
int Front( struct QueueRecord* Q );


int IsEmpty( struct QueueRecord* Q )
{
    if ( Q->Size == 0 )
        return TRUE;
    else
        return FALSE;
}

int IsFull( struct QueueRecord* Q )
{
    if ( Q->Capacity == Q->Size )
        return TRUE;
    else
        return FALSE;
}

void MakeEmpty( struct QueueRecord* Q )
{
    Q->Size = 0;
    Q->Front = 1;
    Q->Rear = 0;
}

struct QueueRecord* CreatQueue( int ArraySize )
{
    struct QueueRecord* Q = NULL;

    Q = ( struct QueueRecord* )malloc( sizeof( struct QueueRecord ) );
    Q->Capacity = ArraySize;
    MakeEmpty( Q );
    Q->Array = ( int* )malloc( sizeof( int ) * ArraySize );

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
    int data;

    if ( !IsEmpty( Q ) )
    {
        data = Q->Array[Q->Front];
        Q->Front = Succ( Q, Q->Front );
        Q->Size--;
        return data;
    }
    else
        return FALSE;
}