public class BinaryTreeTest 
{
    public static void main(String[] args)
    {
        BinaryTree<Integer> a=new BinaryTree<Integer>(3);
        System.out.println(a.toString()+"    "+a.findElement(2));
        a.addElement(2);
        a.addElement(3);
        a.addElement(7);
        System.out.println(a.toString()+"    "+a.findElement(2));
    }
}
