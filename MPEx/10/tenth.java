import java.util.Scanner;

public class tenth
{
	public static void main(String args[])
	{
		Scanner input = new Scanner(System.in); 
		System.out.println("Введите длину массива: ");
		int size = input.nextInt(); 
		int array[] = new int[size];
		int max1 = array[0];
		int max2 = array[0];
		int max3 = array[0];
		System.out.println("Введите числа:");
		
		for (int i = 0; i < size; i++) 
		{
			array[i] = input.nextInt(); 
		}
		System.out.print("Получившийся массив:");
		for (int i = 0; i < size; i++) 
		{
			System.out.print (" " + array[i]); 
		}
		System.out.println();
		
		System.out.print("Три максимальных числа в массиве:");
		
		for(int i = 0; i < size; i++) 
		{
			if(array[i] > max1)
			{
				max1 = array[i];
			}
			if(array[i] < max1 && array[i] > max2)
			{
				max2 = array[i];
			}
			if(array[i] < max1 && array[i] < max2 && array[i] > max3)
			{
				max3 = array[i];
			}
		}
		System.out.println(" " + max1 + " " + max2 + " " + max3);
	}
}
