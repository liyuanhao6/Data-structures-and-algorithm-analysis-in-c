typedef struct Node
{
    int Coefficient;
    int Exponent;
    struct Node* Next;
} *Polynomial;

Polynomial Add_Polynomial( Polynomial poly1, Polynomial poly2 )
{
    Polynomial poly = NULL;
    struct Node *poly1temp = poly1, *poly2temp = poly2, *polytemp = poly;

    poly1temp = poly1temp->Next;
    poly2temp = poly2temp->Next;

    while ( poly1temp != NULL || poly2temp != NULL )
    {
        if ( poly1temp->Exponent > poly2temp->Exponent)
        {
            polytemp->Next = poly2temp;
            polytemp = polytemp->Next;
            poly2temp = poly2temp->Next;
        }
        else if ( poly1temp->Exponent < poly2temp->Exponent )
        {
            polytemp->Next = poly1temp;
            polytemp = polytemp->Next;
            poly1temp = poly1temp->Next;
        }
        else
        {
            struct Node* temp = NULL;

            temp = ( struct Node* )malloc( sizeof( struct Node ) );
            temp->Coefficient = poly1temp->Coefficient + poly2temp->Coefficient;
            temp->Exponent = poly1temp->Exponent;
            polytemp->Next = temp;
            polytemp = polytemp->Next;
            poly1temp = poly1temp->Next;
            poly2temp = poly2temp->Next;
        }
    }

    return poly;
}