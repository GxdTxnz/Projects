public class Sorts 
{
	int[] a;
	public Sorts(int[] a) 
	{
		this.a = a;
	}

	public void bubbleSort() 
	{
		boolean needNextPass = true;
		for (int i = a.length - 1; i > 0 && needNextPass; i--) 
		{
			needNextPass = false;
			for (int j = 0; j < i; j++) 
			{
				if (a[j] > a[j+1]) 
				{
					int temp = a[j];
					a[j] = a[j+1];
					a[j+1] = temp;
					needNextPass = true;
				}
			}
		}
	}
	
	//public void bubbleSortString()
	//{
		
	
	
	
	
	
	
	
	
	
	
	
	/*public void sortStrings(String[] a, int n)
	{
		String temp;
  
        // Sorting strings using bubble sort
        for (int j = 0; j < n - 1; j++)
        {
            for (int i = j + 1; i < n; i++) 
            {
                if (a[j].compareTo(a[i]) > 0)
                {
                    temp = a[j];
                    a[j] = a[i];
                    a[i] = temp;
				}
			}
		}
	} */
	
	public void insertionSort() 
	{
		for (int i = 1; i < a.length; i++) 
		{
			int temp = a[i];
			int j;
			for (j = i - 1; j >= 0 && temp < a[j]; j --) 
			{
				a[j + 1] = a[j];
			}
			a[j+1] = temp;
		}
	}
	public void selectionSort() 
	{
		for (int i = 0; i < a.length - 1; i ++)
		{
			int currenMinIndex = i;
			for (int j = i + 1; j < a.length; j++)
			{
				if (a[currenMinIndex] > a[j])
				{
					currenMinIndex = j;
				}
			}
			if (currenMinIndex != i)
			{
				int temp = a[i];
				a[i] = a[currenMinIndex];
				a[currenMinIndex] = temp;
			}
		}
	}
}
