class Node:
    def __init__(self):
        self.key = 0
        self.left = None
        self.right = None

def createNode(x):
    newNode = Node()
    newNode.key = x
    return newNode

def insertNode(root, x) -> Node:
    if root == None:
        return createNode(x)
    if x < root.key:
        root.left = insertNode(root.left, x)
    else:
        root.right = insertNode(root.right, x)
    return root

def createBST(a, n):
    root = None
    for i in range(n):
        root = insertNode(root, a[i])
    return root

def searchNode(root, x):
    if root == None or root.key == x:
        return root
    if x < root.key:
        return searchNode(root.left, x)
    else:
        return searchNode(root.right, x)
    

def minNode(node):
    cur = node
    while cur.left != None:
        cur = cur.left
    return cur

def deleteNode(root, x):
    if root == None:
        return root
    if x < root.key:
        root.left = deleteNode(root.left, x)
    elif x > root.key:
        root.right = deleteNode(root.right, x)
    else:
        if root.left == None:
            tmp = root.right
            del root
            return tmp
        elif root.right == None:
            tmp = root.left
            del root
            return tmp
        else:
            tmp = minNode(root.right)
            root.key = tmp.key
            root.right = deleteNode(root.right, tmp.key)
    return root

def LNRtravesal(root):
    if root != None:
        LNRtravesal(root.left)
        print(root.key, end=' ')
        LNRtravesal(root.right)

def size(root):
    if root == None:
        return 0
    return size(root.left) + 1 + size(root.right)

def deleteTree(root):
    if root == None:
        return
    deleteNode(root.left)
    deleteNode(root.right)
    del root