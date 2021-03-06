typedef struct Node
{
    struct Node* Next;
    int Element;
} *List;

List ListIntersection( List L1, List L2 )
{
    List L = NULL;
    struct Node *L1temp = L1, *L2temp = L2, *Ltemp = L;

    L1temp = L1temp->Next;
    L2temp = L2temp->Next;

    while ( L1temp != NULL && L2temp != NULL )
        if ( L1temp->Element > L2temp->Element )
            L2temp = L2temp->Next;
        else if ( L1temp->Element < L2temp->Element )
            L1temp = L1temp->Next;
        else
        {
            Ltemp->Next = L1temp;
            Ltemp = Ltemp->Next;
            L1temp = L1temp->Next;
            L2temp = L2temp->Next;
        }
}