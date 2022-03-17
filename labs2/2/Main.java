//СПизженный main с сайта 
import java.util.HashMap;
import java.util.Map;
import java.util.Random;

public class Main 
{
    public static void main(String[] args) 
    {
        AVLTree<Integer, String> tree = new AVLTree<>(Integer::compareTo);
        Random random = new Random();
        long timestamp = System.nanoTime();
        for (int i = 0; i < 100000; i++) tree.add(i, String.valueOf(2 << i));
        System.out.println(System.nanoTime() - timestamp);
        timestamp = System.nanoTime();
        for(int i = 0; i < 10000; i++) 
        {
            int key = random.nextInt(100000);
            tree.get(key);
        }
        System.out.println(System.nanoTime() - timestamp);
        Map<Integer, String> map = new HashMap<>();
        timestamp = System.nanoTime();
        for (int i = 0; i < 100000; i++) map.put(i, String.valueOf(2 << i));
        System.out.println(System.nanoTime() - timestamp);
        timestamp = System.nanoTime();
        for(int i = 0; i < 10000; i++) 
        {
            int key = random.nextInt(100000);
            map.get(key);
        }
        System.out.println(System.nanoTime() - timestamp);
    }
}
