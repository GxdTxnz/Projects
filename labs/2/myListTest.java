


public class myListTest {
    public static void main(String[] args) throws Exception {
        myList testList = new myList();             //создаём список
        testList.add(5);                            //заполняем значениями
        testList.add(10);
        testList.add(15);
        testList.add(20);
        testList.add(25);
        testList.addLast(2);                //добавление элемента в конец списка

        System.out.print("Тестовый список: ");
        System.out.println(testList);              //вывод списка в консоль для проверки
        myList copy = new myList(testList);        //применение конструктора копирования
        System.out.print("Копия тестового списка: ");
        System.out.println(copy);                   //вывод скопированного списка

        testList.removeFirst();                     //применение метода удаления первого элемента списка

        System.out.print("Тестовый список, после удаления первого элемента: ");
        System.out.println(testList);              //вывод списка после удаления из него элемента
        System.out.print("Копия списка для сравнения: ");
        System.out.println(copy);                   //вывод скопированного списка

        testList.removeAtValue(10);    //удаление элемента по значению
        System.out.print("Тестовый список, после удаления элемента по значению(10): ");
        System.out.println(testList);              //список после удаления выбранного нами элемента

        System.out.println("Длина тестового списка: " + testList.getLength());      //вывод количества элементов в обоих списках
        System.out.println("Длина копии: " + copy.getLength());
        testList.clear();                                                       //очистка списка

        //для проверки выброса исключений раскомментировать ниже
        //testList.removeAtValue(10);
        //testList.removeFirst();

    }
}
