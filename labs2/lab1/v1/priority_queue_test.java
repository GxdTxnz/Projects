import java.util.Random;
import java.util.Scanner;

public class priority_queue_test
{
	public static void main(String[] args) 
	{
		priority_queue<Integer> list = new priority_queue<>();
		System.out.print("Очередь уже прописана в коде. Хотите сгенерировать новую?(y/n) ");
		Scanner sc = new Scanner (System.in);
		String z = sc.next();
		char c = z.charAt(0); 
		if(c == 'y')
		{
			for(int i = 0; i < 10; i++)
			{
				int num = new Random().nextInt(60);
				list.addNumber(num);
			}
			list.prepare();
			if (list.empty() == true)
			{
				System.out.println("Очередь не пуста");
			}
			else
			{
				System.out.println("Очередь пуста");
			}
			
			System.out.println("Количество элементов: " + list.getSize());
			System.out.println("Максимальный элемент: " + list.getMax());
			System.out.println("Удалим максимальный элемент из очереди: " + list.delNumber());
			list.prepare();
			
			
		}
		else if(c == 'n')
		{
			list.addNumber(15);
			list.addNumber(65);
			list.addNumber(5);
			list.addNumber(35);
			list.addNumber(45);
			list.addNumber(25);
			list.prepare();
			if (list.empty() == true)
			{
				System.out.println("Очередь не пуста");
			}
			else
			{
				System.out.println("\nОчередь пуста");
			}
			
			System.out.println("Количество элементов: " + list.getSize());
			System.out.println("Максимальный элемент: " + list.getMax());
			System.out.println("Удалим максимальный элемент из очереди " + list.delNumber());
			list.prepare();
		}
	}
}
