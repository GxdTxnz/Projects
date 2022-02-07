public class EffectiveSorts
{
	public static void printarray(int[] arr)
	{
		for (int i: arr)
		{
			System.out.print(i + " ");
		}
	}
	
	////////////////////////////////////////////////////////////////////
	
	public static int partition(int[] arr, int s, int e)
	{
		if (s >= e)
		{
			return s;
		}
		else
		{
			int pivot = arr[e];
			int pindex = s;
			int temp, temp1;
			for (int i = s; i < e; i++)
			{
				if (arr[i] <= pivot)
				{
					temp = arr[i];
					arr[i] = arr[pindex];
					arr[pindex] = temp;
					pindex++;
				}
			}
			temp1 = arr[e];
			arr[e] = arr[pindex];
			arr[pindex] = temp1;
			return pindex; 
		}
	}
	public static int[] quickSort(int[] arr, int s, int e)
	{
		if (s >= e)
		{
			return arr;
		}
		else
		{
			int pindex = partition(arr, s, e);
			quickSort(arr, s, pindex - 1);
			quickSort(arr, pindex + 1, e);
		}
		return arr;
	}
	
	////////////////////////////////////////////////////////////////////
	
	static int n;
	public static int[] heapSort(int[] arr)
	{
		heapify(arr);
		for (int i = n; i > 0; i--)
		{
			swap(arr, 0, i);
			n--;
			maxheap(arr, 0);
		}
		return arr;
	}
	public static void heapify(int[] arr)
	{
		n = arr.length - 1;
		
		for (int i = n/2; i >= 0;i--)
		{
			maxheap(arr, i);
		}
	}
	public static void maxheap(int[] arr, int i)
	{
		int left = 2 * i;
		int right = (2 * i) + 1;
		int max = i;
		if (left <= n && arr[left] > arr[i])
		{
			max = left;
		}
		if (right <= n && arr[right] > arr[max])
		{
			max = right;
		}
		if(max != i)
		{
			swap(arr, i, max);
			maxheap(arr, max);
		}
	}
	public static void swap(int arr[], int i, int j)
	{
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	
	////////////////////////////////////////////////////////////////
	
	public static int[] merge(int[] left, int[] right, int[] arr)
	{
		int nl = left.length;
		int nr = right.length;
		int i = 0, j = 0, k = 0;
		while (i < nl && j < nr)
		{
			if (left[i] <= right[j])
			{
				arr[k++] = left[i++];
			}
			else
			{
				arr[k++] = right[j++];
			}
		}
		while (i < nl)
		{
			arr[k++] = left[i++];
		}
		while (j < nr)
		{
			arr[k++] = right[j++];
		}
		return arr;
	}
	public static int[] mergeSort(int[] arr)
	{
		int n = arr.length;
		if (n < 2)
		{
			return arr;
		}
		else
		{
			int mid = n/2;
			int[] left = new int[mid];
			int[] right = new int[n - mid];
			for (int i = 0; i < mid; i++)
			{
				left[i] = arr[i];
			}
			for (int j = mid; j < n; j++)
			{
				right [j - mid] = arr[j];
			}
			mergeSort(left);
			mergeSort(right);
			merge(left, right, arr);
		}
		return arr;
	}
}

