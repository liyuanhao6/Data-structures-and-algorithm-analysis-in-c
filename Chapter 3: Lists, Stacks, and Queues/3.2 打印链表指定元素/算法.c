typedef struct Node
{
    struct Node* Next;
    int Element;
} *List;

void PrintLots( List L, List P )
{
    struct Node* Ltemp = L, *Ptemp = P->Next;
    int index = 0;

    while ( Ptemp->Next != NULL)
    {
        Ltemp = Ltemp->Next;
        index++;

        if ( index == Ptemp->Element )
        {
            print( "%d ", Ltemp->Element );
            Ptemp = Ptemp->Next;
        }
    }
}