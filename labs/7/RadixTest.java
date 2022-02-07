
import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

public class RadixTest
{
	private static Integer[] toIntArr(ArrayList<Integer> arrlist)
	{
		Integer[] res = new Integer[arrlist.size()];
		for (int i = 0; i < res.length; i++)
		{
			res[i] = arrlist.get(i);
		}
		return res;
	}

	private static Integer[] genIntegerArr(int len)
	{
		Random rnd = new Random();
		Integer[] arr = new Integer[len];
		for (int i = 0; i < len; i++)
		{
			arr[i] = rnd.nextInt(1000000);
		}
		return arr;
	}
	private static ArrayList<Integer> genArrList(int len)
	{
		Random rnd = new Random();
		ArrayList<Integer> arr = new ArrayList<>(len);
		for (int i = 0; i < len; i++)
		{
			arr.add(rnd.nextInt(1_000_000_000));
		}
		return arr;
	}

	public static void main(String[] args)
	{
		System.out.println ("Выберите сортировку(L - LSD, M - MSD, C - Counting):");
		Scanner sc = new Scanner (System.in);  //сканер ввода с клавиатуры
		String z = sc.next();  //сканнер до пробела
		char c = z.charAt(0); //Возвращаем значение по индексу 
		if (c == 'L') 
		{
			Integer[] arr = genIntegerArr(1000000);
			for(Integer i: arr)
			{
				System.out.println(i + " ");
			}
			System.out.println();
			Radix.LSD_Sort(arr);
			for(Integer i: arr)
			{
				System.out.println(i + " ");
			}
			System.out.println(); 
		}
		else if (c == 'M')
		{
			ArrayList<Integer> arr = genArrList(1000000);
			for(Integer i: arr)
			{
				System.out.println(i + " ");
			}
			System.out.println();
			Radix.MSD_Sort(arr);
			for(Integer i: arr)
			{
				System.out.println(i + " ");
			}
			System.out.println();
		}
		else if (c == 'C')
		{
			ArrayList<Integer> arr = genArrList(100000);
			for(Integer i: arr)
			{
				System.out.println(i + " ");
			}
			System.out.println();
			Radix.CountingSort(arr);
			for(Integer i: arr)
			{
				System.out.println(i + " ");
			}
			System.out.println();
		}
	}
}
