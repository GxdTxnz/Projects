import java.util.Arrays;

//Тестирование и проверка возможностей класса
public class MyVectorTest {
    public static void main(String[] args) throws Exception 
    {
        //Создаём объект динамического массива
        MyVector<Integer> vector = new MyVector<Integer>(10);

        //Добалвяем элементы
        vector.add(5);
        vector.add(10);

        //Оставшееся место заполняем случайными элементами
        for(int i = vector.size; i < vector.max; i++)
        {
            vector.add((int) (Math.random() * 100));
        }

        //Проверяем метод копирования
        MyVector<Integer> copy = new MyVector<Integer>(vector);


        //Вставка элемента по индексу
        vector.insert(0, 15);

        //Вывод результата работы над основным массивом
        System.out.println(Arrays.toString(vector.array));
        System.out.println("Размер основного массива: " + vector.getSize());
        System.out.println("Вместимость основного массива: " + vector.getMax());
        System.out.println();

        //Добавление элемента в заполненый массив копию для проверки изменения размера массива
        //по достижении максимального кол-ва элементов
        copy.add(1);
        //Вывод результата работы над массивом копией
        System.out.println(Arrays.toString(copy.array));
        System.out.println("Размер копии массива: " + copy.getSize());
        System.out.println("Вместимость массива копии " + copy.getMax());
    }
}
