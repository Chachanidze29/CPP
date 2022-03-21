#pragma once
#include "Node.h"
template <typename DataType>
class BST
{
    typedef Node<DataType>* BinNodePointer;
    typedef Node<DataType> BinNode;
    BinNodePointer myRoot;
    void search2(const DataType& , bool& , BinNodePointer& , BinNodePointer& )const;
    void preorderAux(ostream& , BinNodePointer ) const;
    void inorderAux(ostream& , BinNodePointer ) const;
    void postorderAux(ostream& , BinNodePointer ) const;
public:
    BST()
        : myRoot(0) {}
    bool empty() const;
    bool search(const DataType& ) const;
    void insert(const DataType& );
    void remove(const DataType& );
    void preorder(ostream& ) const;
};
template <typename DataType>
void BST<DataType>::search2(const DataType& item, bool& found, BinNodePointer& locptr, BinNodePointer& parent) const
{
    locptr = myRoot;
    parent = 0;
    found = false;
    while (!found && locptr != 0)
    {
        if (item < locptr->data)       // descend left
        {
            parent = locptr;
            locptr = locptr->left;
        }
        else if (locptr->data < item)  // descend right
        {
            parent = locptr;
            locptr = locptr->right;
        }
        else                           // item found
            found = true;
    }
}
template <typename DataType>
void BST<DataType>::preorderAux(ostream& out, BinNodePointer subtreeRoot) const
{
    if (subtreeRoot != 0)
    {
        out << subtreeRoot->data << "  ";      // V operation
        inorderAux(out, subtreeRoot->left);    // L operation
        inorderAux(out, subtreeRoot->right);   // R operation
    }
}
template <typename DataType>
void BST<DataType>::inorderAux(ostream& out, BinNodePointer subtreeRoot) const
{
    if (subtreeRoot != 0)
    {
        inorderAux(out, subtreeRoot->left);    // L operation
        out << subtreeRoot->data << "  ";      // V operation
        inorderAux(out, subtreeRoot->right);   // R operation
    }
}
template <typename DataType>
void BST<DataType>::postorderAux(ostream& out, BinNodePointer subtreeRoot) const
{
    if (subtreeRoot != 0)
    {
        inorderAux(out, subtreeRoot->left);    // L operation
        inorderAux(out, subtreeRoot->right);   // R operation
        out << subtreeRoot->data << "  ";      // V operation
    }
}
template <typename DataType>
bool BST<DataType>::empty() const {
    return myRoot == 0;
}
template <typename DataType>
bool BST<DataType>::search(const DataType& item) const
{
    BinNodePointer locptr = myRoot;
    bool found = false;
    while (!found && locptr != 0)
    {
        if (item < locptr->data)       // descend left
            locptr = locptr->left;
        else if (locptr->data < item)  // descend right
            locptr = locptr->right;
        else                           // item found
            found = true;
    }
    return found;
}
template <typename DataType>
void BST<DataType>::insert(const DataType& item)
{
    BinNodePointer
        locptr = myRoot,   // search pointer
        parent = 0;        // pointer to parent of current node
    bool found = false;     // indicates if item already in BST
    while (!found && locptr != 0)
    {
        parent = locptr;
        if (item < locptr->data)       // descend left
            locptr = locptr->left;
        else if (locptr->data < item)  // descend right
            locptr = locptr->right;
        else                           // item found
            found = true;
    }
    if (!found)
    {                                 // construct node containing item
        locptr = new BinNode(item);
        if (parent == 0)               // empty tree
            myRoot = locptr;
        else if (item < parent->data)  // insert to left of parent
            parent->left = locptr;
        else                           // insert to right of parent
            parent->right = locptr;
    }
    else
        cout << "Item already in the tree\n";
}
template <typename DataType>
void BST<DataType>::remove(const DataType& item)
{
    bool found;                      // signals if item is found
    BST<DataType>::BinNodePointer
        x,                            // points to node to be deleted
        parent;                       //    "    " parent of x and xSucc
    search2(item, found, x, parent);

    if (!found)
    {
        cout << "Item not in the BST\n";
        return;
    }
    //else
    if (x->left != 0 && x->right != 0)
    {                                // node has 2 children
        BST<DataType>::BinNodePointer xSucc = x->right;
        parent = x;
        while (xSucc->left != 0)       // descend left
        {
            parent = xSucc;
            xSucc = xSucc->left;
        }
        x->data = xSucc->data;
        x = xSucc;
    } // end if node has 2 children
    BST<DataType>::BinNodePointer
        subtree = x->left;             // pointer to a subtree of x
    if (subtree == 0)
        subtree = x->right;
    if (parent == 0)                  // root being removed
        myRoot = subtree;
    else if (parent->left == x)       // left child of parent
        parent->left = subtree;
    else                              // right child of parent
        parent->right = subtree;
    delete x;
}
template <typename DataType>
void BST<DataType>::preorder(ostream& out) const
{
    preorderAux(out, myRoot);
}