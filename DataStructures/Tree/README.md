## TODO
https://www.geeksforgeeks.org/tree-data-structure/

## Type of tree
Binary tree
    Based on the  number of children
        - Full Binary Tree - Every node has 0 or 2 children. 
        - Degenerate Binary Tree. - Every internal node has one child.
        - Skewed Binary Tree - The tree is either dominated by the left nodes or the right nodes. There are left-skewed binary tree and right-skewed binary tree
    Based on the basis of completion of levels
        - Complete Binary Tree
            All the levels of the tree are filled completely except the lowest level nodes which are filled from as left as possible. All   leaves have the same depth.
        - Perfect Binary Tree 
            The tree is completely filled with no gaps.
                       1 
                2           3
            4       5   6       7
        - Balanced Binary Tree
            The absolute difference in heights of the left and right subtrees is at most 1 for every node in the tree.
    Base on the basis of node values.
        Binary Search Tree

## Basic Operations Of Tree Data Structure:
    Create 
    Insert 
    Search 
    Traversal - https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/
        DFS Depth-First-Search Traversal
            Inorder traversal
            Preoder traversal
            Postorder traversal
        BFS Breadth-First-Search/Level Order Traversal https://www.geeksforgeeks.org/level-order-tree-traversal/
            Stack Recursive
            Queue Iterative
        Other
            Boundary Traversal
            Diagonal Traversal