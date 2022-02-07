class EffectiveSortsTest
{
	public static void printarray(int[] arr)
	{
		for(int i: arr)
		{
			System.out.print(i + " " );
		}
	}

	public static void main(String[] args)
	{
		int[] arr1 = {2, 1024, 4, 32, 256, 8, 16, 512, 32, 64, 64, 128};
		printarray(arr1);
		System.out.println("\nБыстрый метод сортировки:");
		int s = 0, e = arr1.length - 1;
		int[] quick = EffectiveSorts.quickSort(arr1, s, e);
		printarray(quick);
		System.out.println("\n-----------------------------------------");
		
		int[] arr2 = {3, 59049, 9, 9, 19683, 27, 6561, 6561, 81, 2187, 243, 729};
		printarray(arr2);
		int[] heap = EffectiveSorts.heapSort(arr2);
		System.out.println("\nПирамидальный метод сортировки:");
		printarray(heap);
		System.out.println("\n-----------------------------------------");
		
		int[] arr3 = {4, 1048576, 16, 262144, 64, 65536, 256, 65536, 65536, 1024, 1024, 16384, 4096};
		printarray(arr3);
		System.out.println("\nСортировка методом слияния:");
		int[] merge = EffectiveSorts.mergeSort(arr3);
		printarray(merge);
		System.out.println("\n-----------------------------------------");
	}
}
