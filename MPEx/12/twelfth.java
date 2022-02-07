import java.util.Scanner;

public class twelfth
{
	public static void main(String args[])
	{
		Scanner in = new Scanner(System.in);
		System.out.println("Введите разер массива: ");
		int size = in.nextInt();
		int[] array = new int[size];
		System.out.println("Введите "+ size + " элементов: ");
		for(int i = 0; i < size; i++)
		{
			array[i] = in.nextInt();
		}
		System.out.print("Получившийся массив:");
		for (int i = 0; i < size; i++) 
		{
			System.out.print (" " + array[i]); 
		}
		System.out.println();
		int min1 = array[0];
		int min2 = 0;
		int min3 = 0;
		int m1 = 0;
		int m2 = 0;
		int m3 = 0;
		for (int i = 1; i < size; i++) 
		{
			if(array[i] < min1) 
			{
				min3 = min2;
				min2 = min1;
				min1 = array[i];
				m3 = m2;
				m2 = m1;
				m1 = i;
			}
			else if(array[i] < min2)
			{
				min3 = min2;
				min2 = array[i];
				m3 = m2;
				m2 = i;
			}
			else if(array[i] < min3)
			{
				min3 = array[i];
				m3 = i;
			}
		}
		System.out.println("Три минимальных числа в массиве: " + min1 + " " + min2 + " " + min3);
	}
}
