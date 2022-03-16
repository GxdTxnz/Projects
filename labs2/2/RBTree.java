public class RBTree<T extends Comparable<T>> 
{

    private RBTNode<T> mRoot;    
    
    private static final boolean RED   = false;
    private static final boolean BLACK = true;
    

    public RBTree() 
    {
        mRoot=null;
    }

    private RBTNode<T> parentOf(RBTNode<T> node)
    {
        return node!=null ? node.parent : null;
    }
    private boolean colorOf(RBTNode<T> node) 
    {
        return node!=null ? node.color : BLACK;
    }
    private boolean isRed(RBTNode<T> node)
    {
        return ((node!=null)&&(node.color==RED)) ? true : false;
    }
    private boolean isBlack(RBTNode<T> node)
    {
        return !isRed(node);
    }
    private void setBlack(RBTNode<T> node) 
    {
        if (node!=null)
            node.color = BLACK;
    }
    private void setRed(RBTNode<T> node) 
    {
        if (node!=null)
            node.color = RED;
    }
    private void setParent(RBTNode<T> node, RBTNode<T> parent)
    {
        if (node!=null)
            node.parent = parent;
    }
    private void setColor(RBTNode<T> node, boolean color) 
    {
        if (node!=null)
            node.color = color;
    }
    private void preOrder(RBTNode<T> tree)
    {
        if(tree != null) 
        {
            System.out.print(tree.key+" ");
            preOrder(tree.left);
            preOrder(tree.right);
        }
    }

    public void preOrder() 
    {
        preOrder(mRoot);
    }
    private void inOrder(RBTNode<T> tree) 
    {
        if(tree != null) 
        {
            inOrder(tree.left);
            System.out.print(tree.key+" ");
            inOrder(tree.right);
        }
    }

    public void inOrder() 
    {
        inOrder(mRoot);
    }

    public int inorderCoounter = 0;
    public int inorderCoounter2 = 0;
    public void inOrderDo() {
    	inorderCoounter = 0;
    	inorderCoounter2 = 0;
        inOrderDo(mRoot);
    }
    public void SetInOrderDo(inOrderDo ido)
    {
    	mInOrderDo = ido;
    }

    public interface inOrderDo
    {
    	void dothis(RBTNode node);
    }
    private inOrderDo mInOrderDo;

    private void inOrderDo(RBTNode<T> node) 
    {
        if(node != null) 
        {
        	inorderCoounter2+=1;
        	inOrderDo(node.left);
        	mInOrderDo.dothis(node);
        	inorderCoounter+=1;
          inOrderDo(node.right);
          inorderCoounter2-=1;
        }
    }
    public RBTNode<T> xxing(T val)
    {
    	RBTNode<T> tmpnode =downwardNeighbour(this.mRoot,val);
    	if (tmpnode!=null) return tmpnode;
    	else return this.maximum(this.mRoot);
    }
 
    private RBTNode<T> downwardNeighbour(RBTNode<T> du,T val) 
    {
        int cmp;
        RBTNode<T> x = du;
        RBTNode<T> tmpnode = null;
        if (x==null)
            return null;
        cmp = val.compareTo(x.key);
        if (cmp < 0)
            return downwardNeighbour(x.left, val);
        else
        	{
        	if(x.right==null ) return x;
        	tmpnode = downwardNeighbour(x.right, val);
        	if (tmpnode==null) return x;
        	else return tmpnode;
        	}
    }
    public RBTNode<T> sxing(T val)
    {
    	RBTNode<T> tmpnode =upwardNeighbour(this.mRoot,val);
    	if (tmpnode!=null) return tmpnode;
    	else return this.minimum(this.mRoot);
    }
    private RBTNode<T> upwardNeighbour(RBTNode<T> du,T val) 
    {
        int cmp;
        RBTNode<T> x = du;
        RBTNode<T> tmpnode = null;
        
        if (x==null)
            return null;

        cmp = val.compareTo(x.key); 
        if (cmp > 0)//情况一
            return upwardNeighbour(x.right, val);
        else
        	{
        	if(x.left==null ) return x;
        	tmpnode = upwardNeighbour(x.left, val);
        	if (tmpnode==null) return x;
        	else return tmpnode;
        	}
    }  

    private void postOrder(RBTNode<T> tree) 
    {
        if(tree != null)
        {
            postOrder(tree.left);
            postOrder(tree.right);
            System.out.print(tree.key+" ");
        }
    }

    public void postOrder() 
    {
        postOrder(mRoot);
    }

    private RBTNode<T> search(RBTNode<T> x, T key) 
    {
        if (x==null)
            return x;

        int cmp = key.compareTo(x.key);
        if (cmp < 0)
            return search(x.left, key);
        else if (cmp > 0)
            return search(x.right, key);
        else
            return x;
    }

    public RBTNode<T> search(T key) 
    {
        return search(mRoot, key);
    }

    private RBTNode<T> iterativeSearch(RBTNode<T> x, T key) 
    {
        while (x!=null) 
        {
            int cmp = key.compareTo(x.key);

            if (cmp < 0) 
                x = x.left;
            else if (cmp > 0) 
                x = x.right;
            else
                return x;
        }

        return x;
    }

    public RBTNode<T> iterativeSearch(T key) {
        return iterativeSearch(mRoot, key);
    }
    private RBTNode<T> minimum(RBTNode<T> tree) 
    {
        if (tree == null)
            return null;

        while(tree.left != null)
            tree = tree.left;
        return tree;
    }

    public T minimum() 
    {
        RBTNode<T> p = minimum(mRoot);
        if (p != null)
            return p.key;

        return null;
    }
     
    private RBTNode<T> maximum(RBTNode<T> tree) 
    {
        if (tree == null)
            return null;

        while(tree.right != null)
            tree = tree.right;
        return tree;
    }

    public T maximum() 
    {
        RBTNode<T> p = maximum(mRoot);
        if (p != null)
            return p.key;

        return null;
    }
    public RBTNode<T> successor(RBTNode<T> x) 
    {
        if (x.right != null)
            return minimum(x.right);
        RBTNode<T> y = x.parent;
        while ((y!=null) && (x==y.right)) 
        {
            x = y;
            y = y.parent;
        }

        return y;
    }
     

    public RBTNode<T> predecessor(RBTNode<T> x) 
    {
        if (x.left != null)
            return maximum(x.left);
        RBTNode<T> y = x.parent;
        while ((y!=null) && (x==y.left)) 
        {
            x = y;
            y = y.parent;
        }

        return y;
    }

    private void leftRotate(RBTNode<T> x) 
    {
        RBTNode<T> y = x.right;
        x.right = y.left;
        if (y.left != null)
            y.left.parent = x;
        y.parent = x.parent;

        if (x.parent == null) 
        {
            this.mRoot = y;            
        } 
        else 
        {
            if (x.parent.left == x)
                x.parent.left = y;    
            else
                x.parent.right = y;  
        }
        
        y.left = x;
        x.parent = y;
    }

    public void rrt()
    {
    	rightRotate(mRoot);
    }
    private void rightRotate(RBTNode<T> y) 
    {
        RBTNode<T> x = y.left;
        y.left = x.right;
        if (x.right != null)
            x.right.parent = y;
        x.parent = y.parent;

        if (y.parent == null) 
        {
            this.mRoot = x;   
        } 
        else 
        {
            if (y == y.parent.right)
                y.parent.right = x;    
            else
                y.parent.left = x;    
        }
        x.right = y;
        y.parent = x;
    }

    private void insertFixUp(RBTNode<T> node) {
        RBTNode<T> parent, gparent;
        while (((parent = parentOf(node))!=null) && isRed(parent)) 
        {
            gparent = parentOf(parent);
            if (parent == gparent.left) 
            {
                RBTNode<T> uncle = gparent.right;
                if ((uncle!=null) && isRed(uncle)) 
                {
                    setBlack(uncle);
                    setBlack(parent);
                    setRed(gparent);
                    node = gparent;
                    continue;
                }
                if (parent.right == node) 
                {
                    RBTNode<T> tmp;
                    leftRotate(parent);
                    tmp = parent;
                    parent = node;
                    node = tmp;
                }
                setBlack(parent);
                setRed(gparent);
                rightRotate(gparent);
            } 
            else 
            {   
                RBTNode<T> uncle = gparent.left;
                if ((uncle!=null) && isRed(uncle)) 
                {
                    setBlack(uncle);
                    setBlack(parent);
                    setRed(gparent);
                    node = gparent;
                    continue;
                }
                if (parent.left == node) 
                {
                    RBTNode<T> tmp;
                    rightRotate(parent);
                    tmp = parent;
                    parent = node;
                    node = tmp;
                }
                setBlack(parent);
                setRed(gparent);
                leftRotate(gparent);
            }
        }
        setBlack(this.mRoot);
    }


    private void insert(RBTNode<T> node) 
    {
        int cmp;
        RBTNode<T> y = null;
        RBTNode<T> x = this.mRoot;

        while (x != null) 
        {
            y = x;
            cmp = node.key.compareTo(x.key);
            if (cmp < 0)
                x = x.left;
            else
                x = x.right;
        }

        node.parent = y;
        if (y!=null)
        {
            cmp = node.key.compareTo(y.key);
            if (cmp < 0)
                y.left = node;
            else
                y.right = node;
        } 
        else 
        {
            this.mRoot = node;
        }
        node.color = RED;
        insertFixUp(node);
    }

    public void insert(T key) 
    {
        RBTNode<T> node=new RBTNode<T>(key,BLACK,null,null,null);
        if (node != null)
            insert(node);
    }
    private void removeFixUp(RBTNode<T> node, RBTNode<T> parent) 
    {
        RBTNode<T> other;

        while ((node==null || isBlack(node)) && (node != this.mRoot)) 
        {
            if (parent.left == node) {
                other = parent.right;
                if (isRed(other)) 
                {  
                    setBlack(other);
                    setRed(parent);
                    leftRotate(parent);
                    other = parent.right;
                }

                if ((other.left==null || isBlack(other.left)) &&
                    (other.right==null || isBlack(other.right))) 
                    {  
                    setRed(other);
                    node = parent;
                    parent = parentOf(node);
                } 
                else 
                {
                    if (other.right==null || isBlack(other.right)) 
                    {  
                        setBlack(other.left);
                        setRed(other);
                        rightRotate(other);
                        other = parent.right;
                    }
                    setColor(other, colorOf(parent));
                    setBlack(parent);
                    setBlack(other.right);
                    leftRotate(parent);
                    node = this.mRoot;
                    break;
                }
            }
            else 
            {
                other = parent.left;
                if (isRed(other)) 
                {
                    setBlack(other);
                    setRed(parent);
                    rightRotate(parent);
                    other = parent.left;
                }

                if ((other.left==null || isBlack(other.left)) && (other.right==null || isBlack(other.right))) 
                {
                    setRed(other);
                    node = parent;
                    parent = parentOf(node);
                } 
                else
                {
                    if (other.left==null || isBlack(other.left)) 
                    { 
                        setBlack(other.right);
                        setRed(other);
                        leftRotate(other);
                        other = parent.left;
                    }
                    setColor(other, colorOf(parent));
                    setBlack(parent);
                    setBlack(other.left);
                    rightRotate(parent);
                    node = this.mRoot;
                    break;
                }
            }
        }

        if (node!=null)
            setBlack(node);
    }
    private void remove(RBTNode<T> node) 
    {
        RBTNode<T> child, parent;
        boolean color;
        if ( (node.left!=null) && (node.right!=null) ) 
        {
            RBTNode<T> replace = node;
            replace = replace.right;
            while (replace.left != null)
                replace = replace.left;
            if (parentOf(node)!=null) 
            {
                if (parentOf(node).left == node)
                    parentOf(node).left = replace;
                else
                    parentOf(node).right = replace;
            } 
            else 
            {
                this.mRoot = replace;
            }
            child = replace.right;
            parent = parentOf(replace);
            color = colorOf(replace);
            if (parent == node) 
            {
                parent = replace;
            } 
            else 
            {
                if (child!=null)
                    setParent(child, parent);
                parent.left = child;
                replace.right = node.right;
                setParent(node.right, replace);
            }

            replace.parent = node.parent;
            replace.color = node.color;
            replace.left = node.left;
            node.left.parent = replace;
            if (color == BLACK)
                removeFixUp(child, parent);
            node = null;
            return ;
        }

        if (node.left !=null) 
        {
            child = node.left;
        } 
        else 
        {
            child = node.right;
        }
        parent = node.parent;
        color = node.color;

        if (child!=null)
            child.parent = parent;
        if (parent!=null) 
        {
            if (parent.left == node)
                parent.left = child;
            else
                parent.right = child;
        } 
        else 
        {
            this.mRoot = child;
        }

        if (color == BLACK)
            removeFixUp(child, parent);
        node = null;
    }
    public void remove(T key) 
    {
        RBTNode<T> node; 

        if ((node = search(mRoot, key)) != null)
            remove(node);
    }

    private void destroy(RBTNode<T> tree) 
    {
        if (tree==null)
            return ;

        if (tree.left != null)
            destroy(tree.left);
        if (tree.right != null)
            destroy(tree.right);

        tree=null;
    }

    public void clear() 
    {
        destroy(mRoot);
        mRoot = null;
    }

    private void print(RBTNode<T> tree, T key, int direction) 
    {

        if(tree != null) 
        {

            if(direction==0)    
                System.out.printf("%2d(B) is root\n", tree.key);
            else                // tree是分支节点
                System.out.printf("%2d(%s) is %2d's %6s child\n", tree.key, isRed(tree)?"R":"B", key, direction==1?"right" : "left");

            print(tree.left, tree.key, -1);
            print(tree.right,tree.key,  1);
        }
    }

    public void print()
    {
        if (mRoot != null)
            print(mRoot, mRoot.key, 0);
    }
}
