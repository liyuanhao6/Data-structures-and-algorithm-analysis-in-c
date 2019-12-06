typedef struct Node
{
    struct Node* Next;
    int Element;
} *List;

void Swap( List L, struct Node* PNode, struct Node* QNode )
{
    struct Node *temp = L;

    while ( temp->Next != PNode )
        temp = temp->Next;

    PNode->Next = QNode->Next;
    QNode->Next = PNode;
    temp->Next = QNode;
}