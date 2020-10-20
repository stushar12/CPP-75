Node * abc(Node *root,Node * &prev)
{
    if(root==NULL)
    return root;
    Node * head=abc(root->left,prev);
    if(prev==NULL)
    head=root;
    else
    {
        root->left=prev;
        prev->right=root;
    }
    prev=root;
    abc(root->right,prev);
    return head;
    
}
Node * bToDLL(Node *root)
{
    Node *prev=NULL;
    Node *a=abc(root,prev);
    return a;
}
