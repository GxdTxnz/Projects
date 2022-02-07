import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;


public class SortsTest 
{    
	
	public static void main(String[] args)
	{
		System.out.println("Пузырьковая сортировка:");
		//1//
		
		System.out.println("-----------------------------------------");
		int[] arr1 = { -2, 1024, -4, 32, 256, 8, 16, 512, -32, -64, 64, -128 };
		for (int i: arr1)
		{
			System.out.print(i + " ");
		}
		System.out.println();
		Sorts.BubbleSort(arr1);
		for (int i: arr1)
		{
			System.out.print(i + " ");
		}
		System.out.println();
		System.out.println("-----------------------------------------");
		
		//2//
		
		
		int[] arr2 = {-3, 59049, 9, 9, 19683, 27, 6561, 6561, 81, 2187, 243, 729};
		System.out.println("Сортировка подпоследовательности(1-5):");
		int[] newarr = Arrays.copyOfRange(arr2, 0, 5);
		for (int i: arr2)
		{
			System.out.print(i + " ");
		}
		System.out.println();
		Sorts.BubbleSort(newarr);
		for (int i: newarr)
		{
			System.out.print(i + " ");
		}
		System.out.println();
		System.out.println("-----------------------------------------");
		
		//3//
		
        String[] arr3 = { "xyz", "ijk", "efg", "abc" };
        for ( String j: arr3)
		{
			System.out.print(j + " ");
		}
		System.out.println();
        Sorts.BubbleSortStr(arr3);
        for ( String j: arr3)
		{
			System.out.print(j + " ");
		}
		System.out.println();
        System.out.println("-----------------------------------------");
		
		
		System.out.println("Сортировка вставкой:");
		
		//1//
		
		int[] arr4 = { 0x20, 0xA, 0x7, 0x1C, 0x1B };
		for (int i: arr4)
		{
			System.out.print(i + " ");
		}
		System.out.println();
        Sorts.InsertionSort(arr4);
        for (int i: arr4)
		{
			System.out.print(i + " ");
		}
		System.out.println();
		System.out.println("-----------------------------------------");
		
		//2//
		
		int[] arr5 = {-4, 1048576, -16, 262144, -64, 65536, 256, 65536, 65536, 1024, 1024, 16384, 4096};
		System.out.println("Сортировка подпоследовательности(3-9):");
		int[] newarr1 = Arrays.copyOfRange(arr5, 2, 9);
		for (int i: arr5)
		{
			System.out.print(i + " ");
		}
		System.out.println();
		Sorts.InsertionSort(newarr1);
		for (int i: newarr1)
		{
			System.out.print(i + " ");
		}
		System.out.println();
		System.out.println("-----------------------------------------");
		
		//3//
		
		Character[] arr6 = { 'd', 'b', 'a', 'c', 'f', 'h', 'e', 'g' };
        for ( Character k: arr6)
		{
			System.out.print(k + " ");
		}
		System.out.println();
        Sorts.InsertionSortStr(arr6);
        for ( Character k: arr6)
		{
			System.out.print(k + " ");
		}
		System.out.println();
        System.out.println("-----------------------------------------");
        
        
        //4//
        
        Character[] arr7 = {'x', 'f', 'a', 'z', 'j', 'l', 'm', 'y', 'b', 'e', 'i', 'q'};
		System.out.println("Сортировка подпоследовательности():");
		Character[] newarr2 = Arrays.copyOfRange(arr7, 0, 7);
		for ( Character k: arr7)
		{
			System.out.print(k + " ");
		}
		System.out.println();
        Sorts.InsertionSortStr(newarr2);
        for ( Character k: newarr2)
		{
			System.out.print(k + " ");
		}
		System.out.println();
        System.out.println("-----------------------------------------");
        
        System.out.println("Сортировка выбором:");
		
		//1//
		
		System.out.println("-----------------------------------------");
		int[] arr8 = { 8, 5, 2, 9, 7, 6, 3, 4, 1, 0 };
		for (int i: arr8)
		{
			System.out.print(i + " ");
		}
		System.out.println();
		Sorts.SelectionSort(arr8);
		for (int i: arr8)
		{
			System.out.print(i + " ");
		}
		System.out.println();
		System.out.println("-----------------------------------------");
        
        //2//
        
        int[] arr9 = {-20, 40, 1, 8, 2, 150, -13, 228, 34, 21, 1000, 550, 782, 345, 111, -169, 324, 441, 196,};
		System.out.println("Сортировка подпоследовательности():");
		int[] newarr3 = Arrays.copyOfRange(arr9, 4, 12);
		for (int i: arr9)
		{
			System.out.print(i + " ");
		}
		System.out.println();
		Sorts.SelectionSort(newarr1);
		for (int i: newarr3)
		{
			System.out.print(i + " ");
		}
		System.out.println();
		System.out.println("-----------------------------------------");
		
		//3//
		
		Character[] arr10 = { 'i', 'l', 'p', 'k', 'm', 'j', 'n', 'o' };
        for ( Character k: arr10)
		{
			System.out.print(k + " ");
		}
		System.out.println();
        Sorts.SelectionSortStr(arr10);
        for ( Character k: arr10)
		{
			System.out.print(k + " ");
		}
		System.out.println();
        System.out.println("-----------------------------------------");
        
        
        //4//
        
        Character[] arr11 = {'t', 'w', 'm', 'z', 'c', 'a', 'd', 's', 'u', 'o', 'p', 'n'};
		System.out.println("Сортировка подпоследовательности():");
		Character[] newarr4 = Arrays.copyOfRange(arr11, 3, 6);
		for ( Character k: arr11)
		{
			System.out.print(k + " ");
		}
		System.out.println();
        Sorts.SelectionSortStr(newarr4);
        for ( Character k: newarr4)
		{
			System.out.print(k + " ");
		}
		System.out.println();
        System.out.println("-----------------------------------------");

	}
}
