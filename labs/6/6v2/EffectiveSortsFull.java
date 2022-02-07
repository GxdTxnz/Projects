import java.util.ArrayList;
import java.util.List;

public class EffectiveSortsFull
{
	private static void swap(int[] arr, int i, int j) 
	{
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}

	private static int partition(int[] arr, int begin, int end) 
	{
		int pivot = arr[end];
		int i = begin - 1;
		for (int j = begin; j < end; j++) 
		{
			if (arr[j] <= pivot) 
			{
				i++;
				swap(arr, i, j);
			}
		}
		swap(arr, i + 1, end);
		return i + 1;
	}

	public static void QuickSort(int[] arr) 
	{
		QuickSort(arr, 0, arr.length - 1);
	}

	public static void QuickSort(int[] arr, int begin, int end) 
	{
		if (begin < end) 
		{
			int partitionIdx = partition(arr, begin, end);
			QuickSort(arr, begin, partitionIdx - 1);
			QuickSort(arr, partitionIdx + 1, end);
		}
	}
	
	private static <T extends Comparable<T>> void swap(T[] arr, int i, int j) 
	{
		T t = arr[i];
		arr[i] = arr[j];
		arr[j] = t;
	}

	private static <T extends Comparable<T>> int partition(T[] arr, int begin, int end) 
	{
		T pivot = arr[end];
		int i = begin - 1;
		for (int j = begin; j < end; j++) 
		{
			if (arr[j].compareTo(pivot) <= 0) 
			{
				i++;
				swap(arr, i, j);
			}
		}
		swap(arr, i + 1, end);
		return i + 1;
	}

	public static <T extends Comparable<T>> void QuickSort(T[] arr) 
	{
		QuickSort(arr, 0, arr.length - 1);
	}

	public static <T extends Comparable<T>> void QuickSort(T[] arr, int begin, int end) 
	{
		if (begin < end) 
		{
			int partitionIdx = partition(arr, begin, end);
			QuickSort(arr, begin, partitionIdx - 1);
			QuickSort(arr, partitionIdx + 1, end);
		}
	}
	
	public static void MergeSort(int[] arr) 
	{
		MergeSort(arr, 0, arr.length - 1);
	}

	public static void MergeSort(int[] arr, int begin, int end) 
	{
		if (begin < end) 
		{
			int mid = (begin + end) / 2;
			MergeSort(arr, begin, mid);
			MergeSort(arr, mid + 1, end);
			merge(arr, begin, mid, end);
		}
	}

	public static void merge(int[] arr, int begin, int mid, int end) 
	{
		int n1 = mid - begin + 1;
		int n2 = end - mid;
		int[] L = new int[n1];
		int[] M = new int[n2];

		for (int i = 0; i < n1; i++)
		{
			L[i] = arr[begin + i];
		}
		for (int j = 0; j < n2; j++)
		{
			M[j] = arr[mid + 1 + j];
		}

		int i, j, k;
		i = 0;
		j = 0;
		k = begin;
		while (i < n1 && j < n2) 
		{
			if (L[i] <= M[j]) 
			{
				arr[k] = L[i];
				i++;
			} 
			else 
			{
				arr[k] = M[j];
				j++;
			}
			k++;
		}

		while (i < n1) 
		{
			arr[k] = L[i];
			i++;
			k++;
		}

		while (j < n2) 
		{
			arr[k] = M[j];
			j++;
			k++;
		}
	}

	public static <T extends Comparable<T>> void MergeSort(T[] arr) 
	{
		MergeSort(arr, 0, arr.length - 1);
	}

    public static <T extends Comparable<T>> void MergeSort(T[] arr, int begin, int end) 
    {
		if (begin < end) 
		{
			int mid = (begin + end) / 2;
			MergeSort(arr, begin, mid);
			MergeSort(arr, mid + 1, end);
			merge(arr, begin, mid, end);
		}
	}

	public static <T extends Comparable<T>> void merge(T[] arr, int begin, int mid, int end) 
	{
		int n1 = mid - begin + 1;
		int n2 = end - mid;
		Object[] L = new Object[n1];
		Object[] M = new Object[n2];

		for (int i = 0; i < n1; i++)
		{
			L[i] = arr[begin + i];
		}
		for (int j = 0; j < n2; j++)
		{
			M[j] = arr[mid + 1 + j];
		}

		int i, j, k;
		i = 0;
		j = 0;
		k = begin;
		while (i < n1 && j < n2) 
		{
			if (((T) L[i]).compareTo((T) M[j]) <= 0) 
			{
				arr[k] = (T) L[i];
				i++;
			} 
			else 
			{
				arr[k] = (T) M[j];
				j++;
			}
			k++;
		}

		while (i < n1) 
		{
			arr[k] = (T) L[i];
			i++;
			k++;
		}

		while (j < n2) 
		{
			arr[k] = (T) M[j];
			j++;
			k++;
		}
	}

	public static void HeapSort(int[] arr, int begin, int end) 
	{
		for (int i = begin; i < end; i++)
		{
			arr[i] = arr[i - begin];
		}
	}
	
	public static void HeapSort(int[] arr)
	{
		int len = arr.length;
		for (int i = len / 2-1; i >= 0; i--)
		{
			heapify(arr, len, i);
		}
		for (int i = len - 1; i >= 0; i--)
		{
			swap(arr, 0, i);
			heapify(arr, i, 0);
		}
	}
	

	private static void heapify(int[] arr, int len, int idx) 
	{
		int biggestIdx = idx;
		int left = 2 * idx + 1;
		int right = 2 * idx + 2;
		if (left < len && arr[left] > arr[biggestIdx])
		{
			biggestIdx = left;
		}
		if (right < len && arr[right] > arr[biggestIdx])
		{
			biggestIdx = right;
		}
		if (biggestIdx != idx) 
		{
			swap(arr, idx, biggestIdx);
			heapify(arr, len, biggestIdx);
		}
	}

	public static <T extends Comparable<T>> void HeapSort(T[] arr, int begin, int end) 
	{
		for (int i = begin; i < end; i++)
		{
			arr[i] = arr[i - begin];
		}
	}

	public static <T extends Comparable<T>> void HeapSort(T[] arr) 
	{
		int len = arr.length;
		for (int i = len / 2 - 1; i >= 0; i--)
		{
			heapify(arr, len, i);
		}
		for (int i = len - 1; i >= 0; i--) 
		{
			swap(arr, 0, i);
			heapify(arr, i, 0);
		}
	}

	public static <T extends Comparable<T>> void heapify(T[] arr, int len, int idx) 
	{
		int biggestIdx = idx;
		int left = 2 * idx + 1;
		int right = 2 * idx + 2;
		if (left < len && arr[left].compareTo(arr[biggestIdx]) > 0)
		{
			biggestIdx = left;
		}
		if (right < len && arr[right].compareTo(arr[biggestIdx]) > 0)
		{
			biggestIdx = right;
		}
		if (biggestIdx != idx) 
		{
			swap(arr, idx, biggestIdx);
			heapify(arr, len, biggestIdx);
		}
	}
}

