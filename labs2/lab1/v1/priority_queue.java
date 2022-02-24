import java.util.ArrayList;


public class priority_queue <T extends Comparable<T>> 
{
	
	
	private final ArrayList<T> list;
	priority_queue() 
	{
		list = new ArrayList<T>();
	}
	
	int size = 0;
	public boolean empty()
	{ 
		if (size == 0)
		{
			throw new IllegalArgumentException("В очереди нет элементов");
		}
		return true;
	}
	
	private void swap(int i, int j) 
	{
		T temp = list.get(i);
		list.set(i, this.list.get(j));
		list.set(j, temp);
    }
	
	private void goBelow(int i) 
	{
		while ((2 * i + 1) < size) 
		{
			int leftChild = 2 * i + 1;
			int rightChild = 2 * i + 2;
			int j = leftChild;
			if (rightChild < size && list.get(rightChild).compareTo(list.get(leftChild)) > 0)
			{
				j = rightChild;
			}
			if (list.get(i).compareTo(list.get(j)) >= 0)
			{
				break;
			}
			swap(i, j);
			i = j;
		}
	}
	
	private void goUpper(int i) 
	{
		while (list.get(i).compareTo(list.get((i - 1) / 2)) > 0) 
		{
			swap(i, (i - 1) / 2);
			i = (i - 1) / 2;
		}
	}
	
	public void addNumber(T num)
	{ 
		list.add(num);
		size++;
		goUpper(size - 1);
	}
	
	public T delNumber() 
	{ 
		if(size == 0)
		{
			throw new IllegalArgumentException("Здесь пусто");
		}
		
		T temp;
		temp = (T) list.get(0);
		list.set(0, list.get(--size));
		goBelow(0);
		return temp;
	}
	
	public T getMax() 
	{
		return list.get(0);
	}
	
	public int getSize()
	{
		return size;
	}
	
	public void prepare()
	{ 
		for (int i = 0; i < size; i++)
		{
			System.out.print(list.get(i) + " ");
		}
		System.out.print("\n");
	}
	
}
