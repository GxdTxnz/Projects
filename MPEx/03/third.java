import java.util.Scanner;

public class third
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in); 
		System.out.println("Введите длинну:");
		int size = input.nextInt(); 
		int array[] = new int[size]; 
		System.out.println("Получившийся массив:");
		for (int i = 0; i < size; i++) 
		{
			array[i] = i + 1;
			System.out.print(array[i] + " ");
		}
		System.out.println();
		System.out.println("Степени двойки:");
		for (int i = 0; i < size; i++)
		{
			if((array[i] > 0) && ((array[i] & (array[i] - 1)) == 0))
			{
				System.out.print(array[i] + " ");
			}
		}
	}
}
