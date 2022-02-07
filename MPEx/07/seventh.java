import java.util.Scanner;

public class seventh
{
	public static void main(String args[])
	{
		System.out.print("Введите число k: ");
		Scanner sc = new Scanner(System.in);
		int k = sc.nextInt();
		Scanner input = new Scanner(System.in); 
		System.out.println("Введите длину массива: ");
		int size = input.nextInt(); 
		int array[] = new int[size];
		int count = 0;
		int max = 1;
		System.out.println("Введите числа:");
		
		for (int i = 0; i < size; i++) 
		{
			array[i] = input.nextInt(); 
		}
		System.out.print ("Получившийся массив:");
		for (int i = 0; i < size; i++) 
		{
			System.out.print (" " + array[i]); 
		}
		System.out.println();
		
		System.out.print ("Делители числа k: ");
		for (int i = 0; i < size; i++)
		{
			if (k % array[i] == 0)
			{
				System.out.print(" " + array[i]);  //Уберите эту строку, если нужно только кол-во делитей числа k
				count++;
			}
		}
		System.out.print("\nКоличество делителей: " + count);
	}
}


