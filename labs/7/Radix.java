import java.util.ArrayList;
import java.util.Arrays;

public class Radix 
{
	public static int getMaxLen(Integer[] arr)
	{
		int max = 0;
		for (int i : arr) 
		{
			String si = String.valueOf(i);
			if (si.length() > max) 
			{
				max = si.length();
			}
		}
		return max;
	}

public static void CountingSort(ArrayList<Integer> arr)
	{
		Integer min = Integer.MAX_VALUE;
		Integer max = 0;
		for (int i: arr)
		{
			if (i < min)
			{
				min = i;
			}
			if (i > max)
			{
				max = i;
			}
		}
		Integer[] datad = new Integer[max - min + 1];
		for (int i = 0; i < (max - min + 1); i++)
		{
			datad[i] = 0;
		}
		for (int i : arr)
		{
			datad[i-min]++;
		}
		arr.clear();
		for (int i = 0; i < datad.length; i++)
		{
			if (datad[i] != 0)
			{
				for (int n = 0; n < datad[i]; n++)
				{
					arr.add(i+min);
				}
			}
		}
	}

	public static int getDigit(int n, int radix)
	{
		int del = (int) Math.floor(Math.pow(10.0, (double) (radix - 1)));
		return (n / del) % 10;
	}

	public static void LSD_Sort(Integer[] arr)
	{
		int max = getMaxLen(arr);
		Integer[] b = Arrays.copyOf(arr, arr.length);
		for (int m = 1; m <= max; m++)
		{
			Integer[] c = {0,0,0,0,0,0,0,0,0,0};
			for (int i = 0; i < arr.length; i++)
			{
				c[getDigit(arr[i], m)]++;
			}
			int count = 0;
			for (int j = 0; j <= 9; j++)
			{
				int tmp = c[j];
				c[j] = count;
				count+=tmp;
			}
			for (int j = 0; j < arr.length; j++)
			{
				int d = getDigit(arr[j], m);
				b[c[d]] = arr[j];
				c[d]++;
			}
			for (int i = 0; i < b.length; i++)
			{
				arr[i] = b[i];
			}
		}
	}

	public static void MSD_Sort(ArrayList<Integer> arr) 
	{
		int max = 0;
		for (int i : arr) 
		{
			String si = String.valueOf(i);
			if (si.length() > max) 
			{
				max = si.length();
			}
		}
		ArrayList<Integer> res_arr = new ArrayList<>();
		sortByDigit(arr, max ,res_arr);
		arr.clear();
		for (Integer nw : res_arr)
		{
			arr.add(nw);
		}
	}

	private static void sortByDigit(ArrayList<Integer> arr, int n, ArrayList<Integer> res_arr) 
	{
		if (arr.size() == 0) 
		{
			return;
		}

		if (n == 0)
		{
			for (Integer el : arr)
			{
				res_arr.add(el);
			}
			return;
		}
		ArrayList<ArrayList<Integer>> digits_arrays = new ArrayList<>(10);
		for (int i = 0; i <= 9; i++) 
		{
			digits_arrays.add(new ArrayList<>());
		}
		for (int c : arr) 
		{
			int num = getDigit(c, n);
			digits_arrays.get(num).add(c);
		}
		for (ArrayList<Integer> subarr: digits_arrays)
		{
			sortByDigit(subarr, n-1, res_arr);
		}
	}

	
}
