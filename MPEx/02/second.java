import java.util.Scanner;

public class second
{
	public static void main(String args[])
	{
		Scanner input = new Scanner(System.in); 
		System.out.println("Введите длину массива: ");
		int size = input.nextInt(); 
		int array[] = new int[size];
		System.out.println("Введите числа:");
		
		for (int i = 0; i < size; i++) 
		{
			array[i] = input.nextInt(); 
			if (array[i] < 0)
			{
				array[i] = -array[i];
			}
		}
		System.out.print ("Получившийся массив(по модулю):");
		for (int i = 0; i < size; i++) 
		{
			System.out.print (" " + array[i]); 
		}
		System.out.println();
		int min = getMin(array);
		System.out.println("Минимальное число: " + min);
	}
	public static int getMin(int[] inputArray)
	{ 
		int minValue = inputArray[0]; 
		for(int i = 1; i < inputArray.length; i++)
		{ 
			if (inputArray[i] < minValue)
			{ 
				minValue = inputArray[i];
			} 
		} 
		return minValue; 
	}
}
