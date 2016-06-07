class node 
{
    int data;
    node* left;
    node* right;
}

void preOrder(node *root) 
{
    if (root)
    {
        cout <<root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(node *root) 
{
    if (root)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout <<root->data << " ";
    }
}

void inOrder(node *root) 
{
    if (root)
    {
        inOrder(root->left);
        cout <<root->data << " ";
        inOrder(root->right);
    }
}

int height(node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    return max(height(root->left) + 1, height(root->right) + 1);
}

void top_view(node * root)
{
    node *r = root;
    stack<int> s;
    while(r)
    {
        s.push(r->data);
        r = r->left;
    }
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    r = root->right;
    while(r)
    {
        cout << r->data << " ";
        r = r->right;
    }
}

