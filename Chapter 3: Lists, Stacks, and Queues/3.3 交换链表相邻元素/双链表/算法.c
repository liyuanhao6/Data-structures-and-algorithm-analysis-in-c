typedef struct Node
{
    struct Node* Previous;
    struct Node* Next;
    int Element;
} *List;

void Swap( struct Node* PNode, struct Node* QNode )
{
    struct Node* temp = NULL;

    temp->Previous = PNode->Previous;
    temp->Next = QNode->Next;
    PNode->Previous = QNode;
    PNode->Next = temp->Next;
    QNode->Previous = temp->Previous;
    QNode->Next = PNode;
}