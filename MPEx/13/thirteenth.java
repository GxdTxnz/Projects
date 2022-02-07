import java.util.Scanner;
 
public class thirteenth 
{
	public static void main(String args[]) 
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
		System.out.println("\nЧисла, которые представимы в виде произведение простых чисел: ");
		for(int i = 0; i < size; i++)
		{
			boolean Prostoe = true;
			for (int j = 2; j < array[i]; j++)
			{
				if(array[i] % j == 0)
				{
					Prostoe = false;
					break;
				}
			}
			if(Prostoe){}
			else
			{
				System.out.print(array[i] + " ");
			}
		}
	}
}
