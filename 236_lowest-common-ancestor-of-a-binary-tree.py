class Solution:
    def dfs(self, n, t, path):
        if n is None: return
        path.append(n)
        if n==t: 
            self.paths.append(path.copy())
            return
        self.dfs(n.left,t,path)
        self.dfs(n.right,t,path)
        path.pop()
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        self.paths=[]
        self.dfs(root,p,[])
        self.dfs(root,q,[])
        lca=root
        for i in range(1, min(len(self.paths[0]), len(self.paths[1]))):
            if self.paths[0][i]!=self.paths[1][i]:
                break
            lca=self.paths[0][i]
        return lca
