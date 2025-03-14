# Structure of a Binary Tree Node
class Node:
    def __init__(self, v):
        self.data = v
        self.left = None
        self.right = None

# Function to print inorder traversal
def printInorder(node):
    if node is None:
        return

    # First recur on left subtree
    printInorder(node.left)

    # Now deal with the node
    print(node.data, end=' ')

    # Then recur on right subtree
    printInorder(node.right)

# Driver code
if __name__ == '__main__':
    """
            1
           / \
          2   3
         / \   \
        4   5   6
    """
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)
    root.right.right = Node(6)
    print("Inorder traversal of binary tree is:")
    printInorder(root) # 4 2 5 1 3 6

    """
            3
           / \
          1   4
          \    \
           2    5
                 \
                  6
    """
    BST = Node(3)
    BST.left = Node(1)
    BST.left.right = Node(2)
    BST.right = Node(4)
    BST.right.right = Node(5)
    BST.right.right.right = Node(6)
    print("Inorder traversal of binary search tree is:")
    printInorder(BST) # 1 2 3 4 5 6
    
