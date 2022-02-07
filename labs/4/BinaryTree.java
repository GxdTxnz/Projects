public class BinaryTree <Data extends Comparable <Data>>
{
    private TreeBranch <Data> data;
    private int len;
    public BinaryTree()
    {
        this.len = 0;
        this.data = null;
    }
    public BinaryTree(Data a)
    {
        this.data = new TreeBranch <Data> (a);
        this.len = 1;
    }
    public BinaryTree (BinaryTree<Data> a) {}
    public void addElement (Data a)
    {
        TreeBranch <Data> b = new TreeBranch<Data>(a);
        TreeBranch <Data> c = this.data;
        TreeBranch <Data> d = this.data;
        int cmp=0;
        while(c!=null)
        {
            d = c;
            cmp = c.compareTo(b);
            if (cmp < 0)
            {
                c = c.more;
            }
            else if (cmp > 0)
            {
                c = c.less;
            }
            else
            {
                return;
            }
        }
        if (cmp < 0)
        {
            d.more = b;
        }
        else if(cmp > 0)
        {
            d.less = b;
        }
        else 
        {
            c = b;
        }
        this.len++;
    }
    public boolean findElement(Data a)
    {
        TreeBranch <Data> b = new TreeBranch <Data> (a);
        TreeBranch <Data> c = this.data;
        int cmp;
        while(c!=null)
        {
            cmp = c.compareTo(b);
            if(cmp < 0) 
            {
                c = c.more;
            }
            else if(cmp > 0)
            {
                c = c.less;
            }
            else 
            {
                return true;
            }
        }
        return false;
    }
    public void clean()
    {
        this.data = null;
        this.len = 0;
    }
    public String toString()
    {
        return this.len + ":" + this.toString (this.data.less) + this.data.data.toString() + this.toString(this.data.more);
    }
    private String toString(TreeBranch<Data> a)
    {
        if(a!=null)
        {
            return this.toString(a.less) + "(" + a.data.toString()+ ")" +this.toString(a.more);
        }
        return "";
    }
}

class TreeBranch<Data extends Comparable<Data>> implements Comparable<TreeBranch<Data>>
{
    public Data data;
    public TreeBranch <Data> less;
    public TreeBranch <Data> more;
    public TreeBranch (Data a)
    {
        this.data = a;
        this.less = null;
        this.more = null;
    }
    public int compareTo(TreeBranch<Data> a)
    {
        return this.data.compareTo(a.data);
    }
}
