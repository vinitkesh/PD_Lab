> Write a program to create a Special Binary Search Tree T with distinct keys (with values in therange [1, 106]) and perform related operations. A Special BST is organized as a binary tree in which
 each node is an object that contains a key value. In addition to a key, each node contains three attributes left, right, and parent that point to the nodes corresponding to its left child, right child, and parent, respectively. If a child or the parent is missing, the appropriate attribute contains the value NIL. The root node is the only node in the tree whose parent is NIL. The keys in a special binary search tree are always stored in such a way as to satisfy the following property:
- Let x be a node in a special binary search tree. If y is a node in the left subtree
of x, then y.key ≥ x.key. If y is a node in the right subtree of x, then y.key ≤ x.key.
Your program should include the following functions.

- Main() - repeatedly reads a character ‘a’, ‘s’, ‘x’, ‘n’, ‘i’, ‘p’, ‘t’ or ‘e’ from the console and
calls the sub-functions appropriately until character ‘e’ is entered.
- Create-Node(k) - creates a new node of the tree with the key value ’k’ and returns a pointer
to the new node. All the pointer attributes of the new node are set to NIL.
- Insert(T, k) - inserts the node with key value ’k’ into the BST T.
Note: The caller of this function is assumed to create the node using the Create-Node()
function with key value ’k’.
- Search(T, k) - searches for a node with key ’k’ in T, and returns a pointer to a node with
key ’k’ if one exists; otherwise, it returns NIL.
- Find-Max(T ) - return the maximum among all the key values in T.
- Find-Min(T ) - return the minimum among all the key values in T.
- Inorder(T ) - performs recursive inorder traversal of the Special BST T and prints the key
value in the nodes of T in inorder.
- Preorder(T ) - performs recursive preorder traversal of the Special BST T and prints the
key value in the nodes of T in preorder.
- Postorder(T ) - performs recursive postorder traversal of the Special BST T and prints the
key value in the nodes of T in postorder.
### Input format:
- Each line contains a character from ‘a’, ‘s’, ‘x’, ‘n’, ‘i’, ‘p’, ‘t’ or ‘e’ followed by at most one
integer. The integers, if given, are in the range [1, 106].
- Character ‘a’ is followed by an integer separated by space. In this operation, a node with this
integer as key is created and inserted into T by calling the function Insert().
- Character ‘s’ is followed by an integer separated by space. This operation is to find the node
with this integer as key in T by calling the function Search().
- Character ‘x’ is to call the function Find-Max().
- Character ‘n’ is to call the function Find-Min().
- Character ‘i’ is to perform inorder traversal of T by calling the function Inorder().
- Character ‘p’ is to perform preorder traversal of T by calling the function Preorder().
- Character ‘t’ is to perform postorder traversal of T by calling the function Postorder().
- Character ‘e’ is to exit the program.
### Output Format:
- The output (if any) of each command should be printed on a separate line.
- For option ‘s’, if the key is present in T, then print ’F’. If the key is not present in T, then print ’N’. Print NIL if T is empty.
- For option ‘x’, print the maximum among all the key values in T.
- For option ‘n’, print the minimum among all the key values in T.
- For option ‘i’, print the key value in the nodes of T obtained from inorder traversal.
- For option ‘p’, print the key value in the nodes of T obtained from preorder traversal.
- For option ‘t’, print the key value in the nodes of T obtained from postorder traversal.
Note: Print NIL if T is empty. (Note: NIL means nothing is to be printed
