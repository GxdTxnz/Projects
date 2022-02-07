
public class MyVector<E> 
{
	E[] array;
	int size = 0;
	int max;

    //Конструктор
    public MyVector(int maximum)
    {
        array = (E[]) new Object[maximum];
        max = maximum;
    }
    //Конструктор копирования

    public MyVector(MyVector copying)
    {
        this.array = (E[]) new Object[copying.array.length];
        for(int i = 0; i < copying.array.length; i++) 
        {
            this.array[i] = (E) copying.array[i];
        }
        this.max = copying.max;
        this.size = copying.size;
    }
    //Метод добавления элемента в конец
    public void add(E el)
    {
        if(this.size == this.max)
            changeMax();
        this.array[this.size] = el;
        this.size++;
    }
    //Удаление последнего элемента
    public void removeLast() throws Exception 
    {
        if(this.array[this.size - 1] == null)
        {
            throw new Exception("Последний элемент не найден");
        }
        this.array[this.size - 1] = null;
        this.size--;
    } 
    //Удаление элемента по индексу
    public void removeAt(int i) throws Exception 
    {
        if(this.array[i] == null)
        {
            throw new Exception("Отстутвтует элемент под указанным индексом");
        }
        for(; i < this.size; i++)
        {
            this.array[i] = this.array[i + 1];
        }
        this.size--;
    } 

    //Вставка элемента по индексу
	public void insert(int i, E el)
	{
        int j = this.size;
        for(; i - 1 != j; j--)
        {
            this.array[j+1] = this.array[j];
        }
        this.array[i] = el;
        size++;
    }  
    //Изменение размера массива
    public void changeMax()
    {
        E[] changedArray = (E[]) new Object[this.max + 10];
        for(int i = 0; i < this.max; i++)
        {
            changedArray[i] = this.array[i];
        }
        this.array = changedArray;
        this.max = changedArray.length;
    }
    //Очистка массива
    public void clear()
    {
        for(int i = 0; i < this.size; i++)
        {
            this.array[i] = null;
        }
        this.size = 0;
    }

    //Текущий размер массива
    public int getSize()
    {
        return size;
    }

    //Максимальный размер
    public int getMax()
    {
        return max;
    }
}    
    //Можно переопределить метод toString(), чтобы увидев null закрывалась скобка. Пример вывода [2, 6, 125, null, null]
                                                                          //Вместо этого сделать [2, 6, 125]

