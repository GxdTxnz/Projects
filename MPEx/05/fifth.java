import java.util.Scanner;

public class fifth
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
		int max = getMax(array);
		System.out.println("Максимальное число: " + max);
	}
	public static int getMax(int[] inputArray)
	{ 
		int maxValue = inputArray[0]; 
		for(int i = 1; i < inputArray.length; i++)
		{ 
			if (inputArray[i] > maxValue)
			{ 
				maxValue = inputArray[i];
			} 
		} 
		return maxValue; 
	}
}
