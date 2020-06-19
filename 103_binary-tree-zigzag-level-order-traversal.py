class Solution:
    def zigzagLevelOrder(self, root: TreeNode):
        if root is None: return []
        Q=[[root],[]]
        ret=[]
        flip=False
        while Q[0]:
            print([x.val for x in Q[0]])
            for x in Q[0]:
                if x.left is not None:
                    Q[1].append(x.left)
                if x.right is not None:
                    Q[1].append(x.right)
            if flip:
                ret.append([x.val for x in Q[0][::-1]])
            else: 
                ret.append([x.val for x in Q[0]])
            flip=flip ^ True
            Q[0]=Q[1]
            Q[1]=[]
        return ret
