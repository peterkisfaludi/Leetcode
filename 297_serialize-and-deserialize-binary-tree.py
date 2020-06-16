class Codec:

    def serialize(self, root):
        Q1, Q2=[root], []
        ser=''
        while len(Q1)>0:
            for e in Q1:
                e_val='None'
                if e is not None:
                    Q2.extend([e.left, e.right])
                    e_val=e.val
                ser+=str(e_val) + ','
            Q1=Q2
            Q2=[]
        return ser

    def deserialize(self, data):
        if len(data)==0: return None
        data=data.split(',')[:-1]
        if data[0]=='None': return None
        root=TreeNode(int(data[0]))
        level=[root]
        state='L'
        lp=0
        N=len(data)
        i=1
        while True:
            new_level=[]
            print([x.val for x in level])
            if len(level)==0: return root
            for j in range(i,i+2*len(level)):
                node=None
                parent=level[lp]
                if data[j]!='None':
                    node=TreeNode(int(data[j]))
                    new_level.append(node)
                if state=='L':
                    state='R'
                    if parent is not None:
                        parent.left=node
                else:
                    state='L'
                    if parent is not None:
                        parent.right=node
                        lp+=1
            i=j+1
            level=new_level
            lp=0
            state='L'
