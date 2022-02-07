import java.util.List;
import java.util.Arrays;
import java.util.ArrayList;

public class Sorts 
{
	public static void BubbleSort(int[] arr) 
	{
		for (int i = 0; i < arr.length; i++) 
		{
			for (int j = 0; j < arr.length - 1; j++) 
			{
				if (arr[j] > arr[j + 1]) 
				{
					int tmp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = tmp;
				}
			}
		}
	}

	public static <T extends Comparable<T>> void BubbleSortStr(T[] arr) 
	{
        for (int i = 0; i < arr.length; i++) 
        {
            for (int j = 0; j < arr.length - 1; j++) 
            {
                if (arr[j].compareTo(arr[j + 1]) > 0) 
                {
                    T tmp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = tmp;
                }
            }
        }
    }
    
	public static void InsertionSort(int[] arr) 
	{
        for (int j = 1; j < arr.length; j++) 
        {
            int key = arr[j];
            int i = j - 1;
            while (i >= 0 && arr[i] > key) 
            {
                arr[i + 1] = arr[i];
                i--;
            }
            arr[i + 1] = key;
        }
    }
    public static <T extends Comparable<T>> void InsertionSortStr(T[] arr) 
    {
        for (int j = 1; j < arr.length; j++) 
        {
            T key = arr[j];
            int i = j - 1;
            while (i >= 0 && arr[i].compareTo(key) > 0) 
            {
                arr[i + 1] = arr[i];
                i--;
            }
            arr[i + 1] = key;
        }
    }
    public static void SelectionSort(int[] arr) {
        for (int min = 0; min < arr.length; min++) {
            int least = min;
            for (int j = min + 1; j < arr.length; j++) {
                if (arr[j] < arr[least])
                    least = j;
            }
            int tmp = arr[min];
            arr[min] = arr[least];
            arr[least] = tmp;
        }
    }
    
    public static <T extends Comparable<T>> void SelectionSortStr(T[] arr) {
        for (int min = 0; min < arr.length; min++) 
        {
            int least = min;
            for (int j = min + 1; j < arr.length; j++) 
            {
                if (arr[j].compareTo(arr[least]) < 0)
                    least = j;
            }
            T tmp = arr[min];
            arr[min] = arr[least];
            arr[least] = tmp;
        }
    }
}
