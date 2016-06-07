struct Node
{
    int data;
    struct Node *next;
}

void Print(Node *head)
{
    Node *r = new Node();
    r = head;

    while (r!=NULL)
    {
        cout << r->data << endl;
        r = r->next;
    }
   
}

Node* InsertLast(Node *head,int data)
{
    Node *r = new Node();
    r->data = data;
    
    if(head == NULL)
    {
        return r;
    }
    
    Node *c = head;
    while (c->next) 
    {
        c = c->next;
    }
    c->next = r;
    return head;
}

Node* InsertFirst(Node *head,int data)
{
    Node *r = new Node();
    r->data = data;
    
    if (head == NULL) 
    {
        return r;
    }
    
    Node *c = head;
    r->next = c;
    
    return r;
}

Node* InsertNth(Node *head, int data, int position)
{
    Node *r = new Node();
    r->data = data;
    
    if (head == NULL)
        return r;
    
    if (position == 0){
        r->next = head;
        return r;
    }
    
    Node *c = head;
    while (c!=NULL && position > 1)
    {
        c = c->next;
        position--;
    }
    
    r->next = c->next;
    c->next = r;
    
    return head; 
}

Node* Delete(Node *head, int position)
{
    if (position == 0)
    { 
        return head->next; 
    }

    head->next = Delete(head->next, position-1);
    return head;
}

void ReversePrint(Node *head)
{ 
    if (head == NULL)
    {
        return ;
    }

    ReversePrint(head->next);
    cout << head->data << endl;
}

Node* Reverse(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *newHead = Reverse(head->next); 
    head->next->next = head; 
    head->next = NULL; 

    return newHead;
}

int CompareLists(Node *headA, Node* headB)
{
    if (headA == NULL && headB == NULL) 
    {   
        return 1;
    } 
    else if (headA == NULL || headB == NULL) 
    {
        return 0;
    }

    return (headA->data == headB->data) && CompareLists(headA->next, headB->next);
}

Node* MergeLists(Node *headA, Node* headB)
{
    if (headA == NULL && headB == NULL)
    { 
        return NULL;
    }
    else if (headA == NULL) 
    {
        return headB;
    }
    else if (headB == NULL) 
    {
        return headA;
    }

    if(headA->data <= headB->data)
    {
        headA->next = MergeLists(headA->next, headB);
    }

    else 
    {
        Node* temp = headB;
        headB = headB->next;
        temp->next = headA;
        headA = temp;
        headA->next = MergeLists(headA->next, headB);
    }

    return headA;
}

int GetNode(Node *head,int positionFromTail)
{
    int index = 0;
    Node* current = head;
    Node* result = head;
    while(current!=NULL)
    {
        current=current->next;
        if (index++>positionFromTail)
        {
            result=result->next;
        }
    }

    return result->data;
}

Node* RemoveDuplicates(Node *head)
{
    if (!head) 
    {
        return head;
    }

    Node* res = head;
    while (head->next) {
        if (head->next->data == head->data) {
            head->next = head->next->next;
        }
        else {
            head = head->next;
        }
    }

    return res;
}

bool has_cycle(Node* head) 
{
    if (head == NULL)
    {
        return 0;
    }

    Node *f = head, *s = head;
    while (f && f->next)
    {
        if (f->next->next == s)
            return 1;
        f = f->next->next;
        s = s->next;
    }

    return 0;
}

int FindMergeNode(Node *headA, Node *headB)
{
    Node *a = headA;
    Node *b = headB;

    while(a != b)
    {
        if(a->next == NULL)
        {
            a = headB;
        }
        else
        {
            a = a->next;
        }
        
        if(b->next == NULL)
        {
            b = headA;
        }
        else
        {
            b = b->next;
        }
    }

    return b->data;
}

Node* SortedInsert(Node *head,int data)
{
    if (head == NULL)
    {
        Node *n = new Node();
        n->data = data;
        return n;
    }
    
    if (head->data <= data)
    {
        head->next = SortedInsert(head->next, data);
        head->next->prev = head;
    }

    else if (head->data > data)
    {
        Node *n = new Node();
        n->data = data;
        
        n->next = head;
        n->prev = head->prev;
        
        head->prev = n;
        head = n;
    }

    return head;
}

Node* ReverseDouble(Node* head)
{
    if (head == NULL)
    {
        return head;
    }
    
    Node *t = head->next;
    head->next = head->prev;
    head->prev = t;
    
    if (!head->prev)
    {
        return head;
    }
    
    return ReverseDouble(head->prev);
}