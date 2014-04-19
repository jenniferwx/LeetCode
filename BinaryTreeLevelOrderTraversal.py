class Solution:
    # @param root, a tree node
    # @return a list of lists of integers
    def levelOrder(self, root):
        res = []
        if not root:
            return res
        level = []    
        level.append(root)
        ind = 0
        while(level):
            Next = []
            L = []
            for Node in level:
               L.append(Node.val)
               if(Node.left):
                   Next.append(Node.left)
               if(Node.right):
                   Next.append(Node.right)
            level = Next
            res.append(L)
            ind = ind+1
            
        return res    
