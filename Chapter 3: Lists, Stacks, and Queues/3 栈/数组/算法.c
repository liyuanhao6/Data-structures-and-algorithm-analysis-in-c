# define True      1
# define False     0
# define EmptyTOS  -1
# define MaxSize   100

struct StackRecord
{
    int Capocity;
    int TopOfStack;
    int *Array;
};

int IsEmpty( struct StackRecord* R );
int IsFull( struct StackRecord* R );
void MakeEmpty( struct StackRecord* R );
struct StackRecord* CreatStack( int Size );
void DisposeStack( struct StackRecord* R );
void Push( struct StackRecord* R, int Element );
int Top( struct StackRecord* R );
void Pop( struct StackRecord* R );
int TopAndPop( struct StackRecord* R );

int IsEmpty( struct StackRecord* R )
{
    if ( R->TopOfStack == -1 )
        return True;
    else
        return False;
} 

int IsFull( struct StackRecord* R )
{
    if ( R->TopOfStack == MaxSize - 1 )
        return True;
    else
        return False;
}

void MakeEmpty( struct StackRecord* R )
{
    R->TopOfStack = EmptyTOS;
}

struct StackRecord* CreatStack( int Size )
{
    struct StackRecord *P;

    if ( Size > MaxSize )
    {
        printf("Stack size is too small!\n");
        return NULL;
    }
    
    P = ( struct StackRecord* )malloc( sizeof( struct StackRecord ) );
    if ( P == NULL )
        printf("Out of space!\n");
    
    P->Array = ( int* )malloc( sizeof( int ) * Size );
    if ( P->Array == NULL )
        printf("Out of space!\n");

    P->Capocity = Size;
    MakeEmpty( P );

    return P;
}

void DisposeStack( struct StackRecord* R )
{
    if ( R != NULL )
    {
        free( R->Array );
        free( R );
    }
}

void Push( struct StackRecord* R, int Element )
{
    if ( IsFull( R ) )
        printf("Full Stack");
    else
        R->Array[++R->TopOfStack] = Element;
} 

int Top( struct StackRecord* R )
{
    if ( IsEmpty( R ) )
    {
        printf("Empty Stack\n");
        return 0;
    }
    else
        return R->Array[R->TopOfStack];
}

void Pop( struct StackRecord* R )
{
    if ( IsEmpty( R ) )
        printf("Empty Stack\n");
    else
        R->TopOfStack--;
}

int TopAndPop( struct StackRecord* R )
{
    if ( IsEmpty( R ) )
    {
        printf("Empty Stack\n");
        return 0;
    }
    else    
        return R->Array[R->TopOfStack--];
}