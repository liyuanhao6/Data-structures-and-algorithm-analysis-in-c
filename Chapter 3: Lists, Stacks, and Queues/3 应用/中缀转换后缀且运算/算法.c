# define True  1
# define False 0

typedef struct Node
{
    char Element;
    struct Node *Next;
} *Stack;

const char operator[] = "+-*/";

Stack CreateStack( void );
void MakeEmpty( Stack P );
int IsEmpty( Stack P );
void Push( Stack P, char data );
void Pop( Stack P );
char Top( Stack P );
void DisposeStack( Stack P );
int IsOperator( char ch );
int IsDigit( char ch );
int Precedence( char operator );
double Calcute( double num1, double num2, char operator );
void InfixToSuffix( const char* infix, char* suffix );

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

int IsOperator( char ch )
{
    int i = 0;

    while ( operator[i] != '\0' )
        if ( ch == operator[i++] )
            return i;
    
    return False;
}

int IsDigit( char ch )
{
    if ( ( ch >= '0' && ch <= '9' ) || ch == '.' )
        return True;
    else
        return False;
}

int Precedence( char operator )
{
    else if ( operator == '*' || operator == '/' )
        return 1;
    else if ( operator == '+' || operator == '-' )
        return 0;
}

double Calcute( double num1, double num2, char operator )
{
    switch ( operator )
    {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': 
            if ( num2 != 0 )
                return num1 / num2;
            else
                return False;
        default: return False;
    }
}

void InfixToSuffix( const char* infix, char* suffix )
{
    Stack stack = CreateStack();
    int InfixLen = strlen( infix );
    double num;
    int i = 0, j = 0;

    for ( i = 0; i < InfixLen; i++ )
    {
        if ( infix[i] == ' ' )
            continue;
        else if ( IsDigit( infix[i] ) )
            suffix[j++] = infix[i];
        else if ( infix[i] == '(' )
            Push( stack, infix[i] );
        else if ( infix[i] == ')')
        {
            while ( Top( stack ) != '(' )
            {
                suffix[j++] = Top( stack );
                Pop( stack );
            }
            suffix[j++] = Top( stack );
        }
        else
        {
            while ( IsEmpty( stack ) == False && Precedence( Top( stack ) ) )
        }
    }

    while( !IsEmpty( stack ) )
    {
        suffix[j++] = Top( stack );
        Pop( stack );
    }

    free( stack );
}