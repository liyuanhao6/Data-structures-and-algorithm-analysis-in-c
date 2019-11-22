# define SpaceSize 10

struct Node
{
    int Element;
    int Next;
};

struct Node CursorSpace[ SpaceSize ];

void InitCursorSpace();
int LocateCursor( int data );

void InitCursorSpace()
{
    int i;

    for ( i = 0; i < SpaceSize; i++ )
        CursorSpace[i].Next = i == SpaceSize - 1 ? 0 : i + 1;
}

int LocateCursor( int data )
{
    int i = CursorSpace[0].Next;

    while ( i != 0 && CursorSpace[i].Element != data )
        i = CursorSpace[i].Next;

    return i;
}

int CursorCalloc( void )
{
    int p;

    p = CursorSpace[0].Next;
    CursorSpace[0].Next = CursorSpace[p].Next;

    return p;
}