import java.util.Arrays;
//import java.util.List;
public class SortsTest 
{
	public static void main(String[] args) 
	{
		System.out.println("До сортировок:");
		
		int[] arr1 = {-2, 1024, -4, 32, 256, 8, 16, 512, -32, -64, 64, -128};
		int[] newarr1 = Arrays.copyOfRange(arr1, 0, 5);
		
		int[] arr2 = {3, 59049, -9, 9, 19683, 27, 6561, 6561, 81, 2187, 243, 729};
		int[] newarr2 = Arrays.copyOfRange(arr2, 0, 4);
		
		int[] arr3 = {-4, 1048576, -16, 262144, -64, 65536, 256, 65536, 65536, 1024, 1024, 16384, 4096};
		int[] newarr3 = Arrays.copyOfRange(arr3, 0, 6);
		
		String arr4[] = { "Ajeet", "Steve", "Rick", "Becky", "Mohan"};
		
		System.out.println("-----------------------------------------");
		for (int i : arr1) 
		{
			System.out.print(i + " ");
		}
		System.out.println();
		for (int i : arr2) 
		{
			System.out.print(i + " ");
		}
		System.out.println();
		for (int i : arr3) 
		{
			System.out.print(i + " ");
		}
		System.out.println();
		/*for (int i : arr4) 
		{
			System.out.print(i + " ");
		}
		System.out.println(); */
		System.out.println("-----------------------------------------");
		Sorts test1 = new Sorts(arr1);
		Sorts test2 = new Sorts(newarr1);
		//Sorts test7 = new Sorts(arr4);
		
		Sorts test3 = new Sorts(arr2);
		Sorts test4 = new Sorts(newarr2);
		
		Sorts test5 = new Sorts(arr3);
		Sorts test6 = new Sorts(newarr3); 
		
		
		
		
		test1.bubbleSort();
		//test2.bubbleSort();
		//test7.bubbleSort();
		
		test3.insertionSort();
		//test4.insertionSort();
		
		test5.selectionSort();
		//test6.selectionSort();
		
		
		
		System.out.println("После сортировок:");
		System.out.println("-----------------------------------------");
		System.out.println("Пузырьковая:");
		
		for (int j : arr1) 
		{
			System.out.print(j + " ");
		}
		System.out.println();
		System.out.println("Сортировка подпоследовательности:");
		for (int i : newarr1) 
		{
			System.out.print(i + " ");
		}
		System.out.println();
		
		test2.bubbleSort();
		
		for (int j : newarr1) 
		{
			System.out.print(j + " ");
		}
		System.out.println();
		
		/*System.out.println("Сортировка говна:");
		for (int j : arr4) 
		{
			System.out.print(j + " ");
		}
		System.out.println(); */
		
		
		
		//////////////////////////////////////////////////////

		
		
		
		
		System.out.println("Вставка:");
		for (int j : arr2) 
		{
			System.out.print(j + " ");
		}
		System.out.println();
		System.out.println("Сортировка подпоследовательности:");
		for (int i : newarr2) 
		{
			System.out.print(i + " ");
		}
		System.out.println();
		
		test4.insertionSort();
		
		for (int j : newarr2) 
		{
			System.out.print(j + " ");
		}
		System.out.println();
		
		System.out.println("Выборка:");
		for (int j : arr3) 
		{
			System.out.print(j + " ");
		}
		System.out.println();
		System.out.println("Сортировка подпоследовательности:");
		for (int i : newarr3) 
		{
			System.out.print(i + " ");
		}
		System.out.println();
		
		test6.selectionSort();
		
		for (int j : newarr3) 
		{
			System.out.print(j + " ");
		}
		System.out.println();
		
		System.out.println("-----------------------------------------");
	}
}
