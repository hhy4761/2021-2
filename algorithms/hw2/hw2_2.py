class Node(object):
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
class BST:
    def __init__(self) -> None:
        self.root = None
    def Insert(self, key):
        self.root = self._insert(self.root, key)
        return self.root is not None

    def _insert(self,node,key):
        if node is None:
            node = Node(key)
        elif key < node.key:
                node.left = self._insert(node.left, key)
        elif key > node.key:
                node.right = self._insert(node.right, key)
        return node

    def Delete(self,key):
        self.root = self._delete(self.root, key)
        return self.root is not None

    def _delete(self,root, key):

        cur = root
        while cur and cur.key != key:
            parent = cur

            if key < cur.key:
                cur = cur.left
            else:
                cur = cur.right

        if cur is None:
            return root

        if cur.left is None and cur.right is None:
            if cur != root:
                if parent.left == cur:
                    parent.left = None
                else:
                    parent.right = None

            else:
                root = None

        elif cur.left and cur.right:
            node = cur
            cur = cur.right
            parent_succ = None

            while cur.left:
                parent_succ = cur
                cur = cur.left

            successor = cur
            data = successor.key
            if parent_succ is not None:
                parent_succ.left = successor.right
            else:
                node.right = None
            node.key = data

        else:
            if cur.left:
                child = cur.left
            else:
                child = cur.right
            if cur != root:
                if cur == parent.left:
                    parent.left = child
                else:
                    parent.right = child
            else:
                root = child
        return root

    def PrintPreorder(self):
        def _PrintPreorder(root):
            if root is None:
                pass
            else:
                print(root.key)
                _PrintPreorder(root.left)
                _PrintPreorder(root.right)
        _PrintPreorder(self.root)

    def Balance(self):
        arr = []
        arr = self.sorted_arr(self.root,arr)
        self.root = self.sorted_arr_to_BST(arr,0,len(arr)-1)
        

    def sorted_arr(self,root,arr):
        
        if root is None:
            pass
        else:
            self.sorted_arr(root.left,arr)
            arr.append(root.key)
            self.sorted_arr(root.right,arr)
        return arr

    def sorted_arr_to_BST(self,arr,start,end):
        if start>end:
            return None
        
        mid = (start + end)//2
        root = Node(arr[mid])

        root.left = self.sorted_arr_to_BST(arr,start,mid-1)
        root.right = self.sorted_arr_to_BST(arr,mid+1,end)

        return root
    
    def Merge(self,root1,root2):
        arr1 = []
        arr1 = root1.sorted_arr(root1.root,arr1)
        arr2 = []
        arr2 = root2.sorted_arr(root2.root,arr2)
        arr = arr1 + arr2
        arr.sort()
        self.root = self.sorted_arr_to_BST(arr,0,len(arr)-1)
    
root1 = BST()
root2 = BST()
root = BST()
root1.Insert(30), root1.Insert(20), root1.Insert(50), root1.Insert(10), root1.Insert(80), root1.Insert(40), root1.Insert(70)
root1.PrintPreorder()
root1.Delete(70), root1.Delete(20), root1.Delete(50)
root1.PrintPreorder()
root1.Insert(70), root1.Insert(20)
root1.PrintPreorder()
root1.Balance()
root1.PrintPreorder()

root2.Insert(50),root2.Insert(60),root2.Insert(90)
root2.PrintPreorder()
root2.Balance()
root2.PrintPreorder()

root.Merge(root1,root2)
root.PrintPreorder()
