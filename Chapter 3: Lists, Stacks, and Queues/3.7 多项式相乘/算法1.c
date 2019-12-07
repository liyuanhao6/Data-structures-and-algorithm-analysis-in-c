// O( M^2 * N^2)

typedef struct Node
{
    int Coefficient;
    int Exponent;
    struct Node* Next;
} *Polynomial;

Polynomial Multiply_Polynomial( Polynomial poly1, Polynomial poly2 )
{
    Polynomial poly = NULL;
    struct Node *P1temp = poly1, *P2temp = poly2, *Ptemp = poly;

    while ( P1temp != NULL )
    {
        Ptemp = poly;
        P2temp = poly2;

        int Exponent = P1temp->Exponent * P2temp->Exponent;
        int Coefficient = P1temp->Coefficient * P2temp->Coefficient;

        while ( Ptemp->Next != NULL )
        {
            Ptemp = Ptemp->Next;

            if ( Ptemp->Next->Exponent <= Exponent )
                continue;
            else if ( Ptemp->Exponent < Exponent )
            {
                struct Node* Temp = NULL;
                Temp->Coefficient = Coefficient;
                Temp->Exponent = Exponent;
                Add_Node( Temp, Ptemp );
                break;
            }
            else if ( Ptemp->Exponent == Exponent )
            {
                Ptemp->Coefficient += Coefficient;
                break;
            }
        }

        if ( Ptemp->Next == NULL )
        {
            struct Node* Temp = NULL;
            Temp->Coefficient = Coefficient;
            Temp->Exponent = Exponent;
            Add_Node( Temp, Ptemp );
        }
    }

}

void Add_Node( struct Node* N, struct Node* PNode )
{
    N->Next = PNode->Next;
    PNode->Next = N;
}