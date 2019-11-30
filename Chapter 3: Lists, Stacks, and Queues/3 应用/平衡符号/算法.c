
# define True  1
# define False 0

typedef struct Node
{
    char Element;
    struct Node *Next;
} *Stack;

const char CloseSymbol[] = ")]}";
const char OpenSymbol[] = "([{";

Stack CreateStack( void );
void MakeEmpty( Stack P );
int IsEmpty( Stack P );
void Push( Stack P, char data );
void Pop( Stack P );
char Top( Stack P );
void DisposeStack( Stack P );
int IsCloseSymbol( char ch );
int IsOpenSymbol( char ch );
int IsMatch( char Clop, char Clch );

Stack CreateStack( void )
{
    Stack P;

    P = ( Stack )malloc( sizeof( Stack ) );
    P->Next = NULL;

    return P;
}

void MakeEmpty( Stack P )
{
    while( P->Next != NULL )
        Pop( P );
}

int IsEmpty( Stack P )
{
    if ( P->Next == NULL )
        return True;
    else
        return False;
}

void Push( Stack P, char data )
{
    struct Node* temp;

    temp = ( struct Node* )malloc( sizeof( struct Node ) );
    temp->Element = data;
    temp->Next = P->Next;
    P->Next = temp;
}

void Pop( Stack P )
{
    struct Node* temp;

    temp = P->Next;
    P->Next = temp->Next;
    free( temp );
}

char Top( Stack P )
{
    char data;

    return data = P->Next->Element;
}

void DisposeStack( Stack P )
{
    MakeEmpty( P );
    free( P );
}

int IsCloseSymbol( char ch )
{
    int i = 0;

    while ( CloseSymbol[i] != '\0' )
        if ( ch == CloseSymbol[i++] )
            return i;
    
    return False;
}

int IsOpenSymbol( char ch )
{
    int i = 0;

    while ( OpenSymbol[i] != '\0' )
        if ( ch == OpenSymbol[i++] )
            return i;

    return False;
}

int IsMatch( char Clop, char Clch )
{
    return IsOpenSymbol( Clop ) == IsCloseSymbol( Clch );
}

int CheckSymbol( char* FilePath )
{
    FILE *fp = NULL;

    char ch;
    Stack stack;
    stack = CreateStack();

    fp = fopen( FilePath, "r+" );

    while ( ( ch = fgetc( fp ) ) != EOF )
    {
        printf( "%c", ch );

        if ( IsOpenSymbol( ch ) != False )
            Push( stack, ch );
        else if ( IsCloseSymbol( ch ) != False )
        {
            if ( IsEmpty( stack ) )
            {
                printf("Empty Stack!\n");
                return False;
            }

            if ( IsMatch( Top( stack ), ch ) == False )
            {
                printf("Not Match!\n");
                return False;
            }

            Pop( stack );
        }

    }

    if ( IsEmpty( stack ) != True )
    {
        printf("Not Match!\n");
        return False;
    }

    fclose(fp);
    DisposeStack( stack );
    return True;
}
