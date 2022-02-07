import java.util.Scanner;

public class ninth
{
	public static void main(String[] args) 
	{
		Scanner input = new Scanner(System.in); 
		System.out.println("Введите длинну:");
		int size = input.nextInt(); 
		int array[] = new int[size]; 
		System.out.println("Массив:");
		for (int i = 0; i < size; i++) 
		{
			array[i] = i + 1;
			System.out.print(array[i] + " ");
		}
		System.out.println();
		System.out.println("Числа, у которых кубический корень является натуральным числом:");
		for (int i = 0; i < size; i++) 
		{
			if (Math.cbrt(array[i]) % 1 == 0) 
			{
				System.out.print(array[i] + " ");
			}
		}
	}
}
