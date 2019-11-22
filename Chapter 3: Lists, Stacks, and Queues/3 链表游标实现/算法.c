# define SpaceSize 10
# define True  1
# define False 0

struct Node
{
    int Element;
    int Next;
};

struct Node CursorSpace[ SpaceSize ];

void InitCursorSpace( struct Node CursorSpace[] );
int LocateCursor( int data, int L );
int CursorMalloc( void );
void CursorFree( int Position );
int IsEmpty( int L );
int IsLast( int Position, int L );
int Find( int data, int L );
int FindPrevious( int data, int L );
void CursorDelete( int data, int L );
void CursorInsert( int Position, int num, int L );
int CursorLength( int L );
void print_Cursor( int L );

void InitCursorSpace( struct Node CursorSpace[] )
{
    int i;

    for ( i = 0; i < SpaceSize; i++ )
        CursorSpace[i].Next = i == SpaceSize - 1 ? 0 : i + 1;
}

int LocateCursor( int data, int L )
{
    int i = CursorSpace[L].Next;

    while ( i != 0 && CursorSpace[i].Element != data )
        i = CursorSpace[i].Next;

    return i;
}

int CursorMalloc( void )
{
    int Position;

    Position = CursorSpace[0].Next;
    CursorSpace[0].Next = CursorSpace[Position].Next;

    return Position;
}

void CursorFree( int Position )
{
    CursorSpace[Position].Next = CursorSpace[0].Next;
    CursorSpace[0].Next = Position;
}

int IsEmpty( int L )
{
    if ( CursorSpace[L].Next == 0 )
        return True;
    else   
        return False;
}

int IsLast( int Position, int L )
{
    if ( CursorSpace[Position].Next == 0 )
        return True;
    else
        return False;
}

int Find( int data, int L )
{
    int P;

    P = CursorSpace[L].Next;

    while ( P != 0 && CursorSpace[P].Element == data )
        P = CursorSpace[P].Next;

    return P;
}

int FindPrevious( int data, int L )
{
    int P, Q;

    Q = L;
    P = CursorSpace[L].Next;
    
    while ( P != 0 && CursorSpace[P].Element == data )
    {
        Q = P;
        P = CursorSpace[P].Next;
    }

    return Q;
}

void CursorDelete( int data, int L )
{
    int P, Q;

    P = FindPrevious( data, L );
    if ( !IsLast( P, L ) )
        Q = CursorSpace[P].Next;

    CursorSpace[P].Next = CursorSpace[Q].Next;
    CursorFree( Q );
}

void CursorInsert( int Position, int num, int L )
{
    int P;

    P = CursorMalloc();

    if ( P == 0 )
        printf("Out of space!\n");

    CursorSpace[P].Element = num;
    CursorSpace[P].Next = CursorSpace[Position].Next;
    CursorSpace[Position].Next = P;
}

int CursorLength( int L )
{
    int index = 0;
    int j = CursorSpace[L].Next;

    while ( j )
    {
        j = CursorSpace[j].Next;
        index++;
    }

    return index;
}

void print_Cursor( int L )
{
    int P;

    P = CursorSpace[L].Next;

    while ( P != 0 )
    {
        printf("%d ", CursorSpace[P].Element);
        P = CursorSpace[P].Next;
    }

    putchar('\n');
}