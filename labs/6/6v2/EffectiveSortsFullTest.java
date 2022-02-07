import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;

public class EffectiveSortsFullTest
{
	public static void main(String[] args)
	{
		//Закидываем данные
		
		int[] arr1 = {-2, 1024, -4, 32, 256, 8, 16, 512, -32, -64, 64, -128};
		int[] newarr = Arrays.copyOfRange(arr1, 0, 5);
		Character[] arr2 = {'x', 'f', 'a', 'z', 'j', 'l', 'm', 'y', 'b', 'e', 'i', 'q'};
		Character[] newarr2 = Arrays.copyOfRange(arr2, 1, 7);
		int[] arr3 = {-4, 1048576, -16, 262144, -64, 65536, 256, -65536, 65536, 1024, 1024, 16384, 4096};
		int[] newarr3 = Arrays.copyOfRange(arr3, 3, 9);
		String[] arr4 = { "xyz", "ijk", "efg", "abc", "qwr", "vuo" };
		String[] newarr4 = Arrays.copyOfRange(arr4, 1, 5);
		int[] arr5 = {-4, 1048576, -16, 262144, -64, 65536, 256, -65536, 65536, 1024, 1024, 16384, 4096};
		int[] newarr5 = Arrays.copyOfRange(arr5, 5, 9);
		Character[] arr6 = { 'd', 'b', 'a', 'c', 'f', 'h', 'e', 'g' };
		Character[] newarr6 = Arrays.copyOfRange(arr6, 2, 7);
		
		//Вывод быстрой
		
		for (int i: arr1)
		{
			System.out.print(i + " ");
		}
		System.out.println();
		System.out.println("\n-----------------------------------------\nБыстрая сортировка массива:");
		EffectiveSortsFull.QuickSort(arr1);
		for (int i: arr1)
		{
			System.out.print(i + " ");
		}
		System.out.println();
		System.out.println("-----------------------------------------\nБыстрая сортировка подпоследовательности массива(1-5):");
		EffectiveSortsFull.QuickSort(newarr);
		for (int i: newarr)
		{
			System.out.print(i + " ");
		}
		System.out.println();
		System.out.println("-----------------------------------------\n ");

		for (Character k: arr2)
		{
			System.out.print(k + " ");
		}
		System.out.println();
		System.out.println("\n-----------------------------------------\nБыстрая сортировка массива:");
		EffectiveSortsFull.QuickSort(arr2);
		for (Character k: arr2)
		{
			System.out.print(k + " ");
		}
		System.out.println();
		System.out.println("-----------------------------------------\nБыстрая сортировка подпоследовательности массива(2-7):");
		EffectiveSortsFull.QuickSort(newarr2);
		for (Character k: newarr2)
		{
			System.out.print(k + " ");
		}
		System.out.println();
		System.out.println("-----------------------------------------\n ");
		
		//Вывод слияния
		
		for(int i: arr3)
		{
			System.out.print(i + " ");
		}
		System.out.println();
		System.out.println("\n-----------------------------------------\nСортировка массива слиянием:");
		EffectiveSortsFull.MergeSort(arr3);
		for(int i: arr3)
		{
			System.out.print(i + " ");
		}
		System.out.println();
		System.out.println("-----------------------------------------\nCортировка подпоследовательности массива слиянием(4-9):");
		EffectiveSortsFull.MergeSort(newarr3);
		for(int i: newarr3)
		{
			System.out.print(i + " ");
		}
		System.out.println();
		System.out.println("-----------------------------------------\n ");
		
		for(String j: arr4)
		{
			System.out.print(j + " ");
		}
		System.out.println();
		System.out.println("\n-----------------------------------------\nСортировка массива слиянием:");
		EffectiveSortsFull.MergeSort(arr4);
		for(String j: arr4)
		{
			System.out.print(j + " ");
		}
		System.out.println();
		System.out.println("-----------------------------------------\nCортировка подпоследовательности массива слиянием(2-5):");
		EffectiveSortsFull.MergeSort(newarr4);
		for(String j: newarr4)
		{
			System.out.print(j + " ");
		}
		System.out.println();
		System.out.println("-----------------------------------------\n "); 
		
		//Вывод пирамидальной
		
		for(int i: arr5)
		{
			System.out.print(i + " ");
		}
		System.out.println();
		System.out.println("\n-----------------------------------------\nПирамидальная сортировка массива:");
		EffectiveSortsFull.HeapSort(arr5);
		for(int i: arr5)
		{
			System.out.print(i + " ");
		}
		System.out.println();
		System.out.println("-----------------------------------------\nПирамидальная сортировка подпоследовательности массива(6-9):");
		EffectiveSortsFull.HeapSort(newarr5);
		for(int i: newarr5)
		{
			System.out.print(i + " ");
		}
		System.out.println();
		System.out.println("-----------------------------------------\n ");
		
		
		for(Character k: arr6)
		{
			System.out.print(k + " ");
		}
		System.out.println();
		System.out.println("\n-----------------------------------------\nПирамидальная сортировка массива:");
		EffectiveSortsFull.HeapSort(arr6);
		for(Character k: arr6)
		{
			System.out.print(k + " ");
		}
		System.out.println(); 
		System.out.println("-----------------------------------------\nПирамидальная сортировка подпоследовательности массива(3-7):");
		EffectiveSortsFull.HeapSort(newarr6);
		for(Character k: newarr6)
		{
			System.out.print(k + " ");
		}
		System.out.println();
		System.out.println("-----------------------------------------\n "); 
		
	}
}
