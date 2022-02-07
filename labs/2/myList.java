
//package Labs;


import java.io.IOException;

class Node<E>{                   //класс узлов, которые буду храниться в списке
    E value;                    //данные
    Node next;                  //ссылка на следующий узел (также элемент списка)

    public Node(){}            //пустой конструктор

    public Node(E value){      //конструктор с параметром значения, если следующий элемент списка не известен
        this.value = value;    //присваиваем переданное значение
        this.next = null;      //ссылку оставляем пустой
    }

    public Node(E value, Node next){  //конструктор с двумя параметрами (значение и ссылка на следующий элемент(узел))
        this.value = value;           //
        this.next = next;             //присваиваем полю next переданную в параметре ссылку на следующий элемент списка
    }

    public E getValue(){                //геттер для получения значения элемента(узла) списка
        return value;
    }

    public void setValue(E value){      //сеттер - задаем значение элементу
        this.value = value;

    }

    public Node getNext(){      //геттер - получаем ссылку на следующий элемент
        return next;
    }

    public void setNext(Node next){ //сеттер - задаём ссылку на следующий элемент
        this.next = next;
    }
}

public class myList<E> {   //наш список, который будет состоять из элементов класса Node
    private Node fe;              //первый элемент списка (head)
    private Node le;              //последний элемент списка (tail)
    int length = 0;       //число элементов списка

    public myList(){    //пустой конструктор

    }


    public myList (myList copying){
        this.fe = copying.fe;
        this.le = copying.le;
        this.length = copying.length;
    }

    public void add (E element){                 //метод добавления элемента в начало списка
        if(fe != null) {                           //если список не пустой
            Node newNode = new Node(element);      //создаём новый узел с пустой ссылкой на следующий элемент и переданным значением
            newNode.setNext(fe);                   //присваиваем ему ссылку на первый узел
            fe = newNode;                          //делаем наш узел первым элементом списка (т.к добавляем в начало)
            length++;                              //увеличиваем значение длины списка на 1
        }
        else {                                     //если же список пустой
            Node newNode = new Node(element);
            fe = newNode;                          //полю "первый элемент" присваиваем значение переданного параметра
            le = newNode;                          //т.к это пока единственный эелемент, он также является и последним
            length++;
        }

    }

    public void addLast(E element){
        if(le != null){
            Node newNode = new Node(element);
            le.setNext(newNode);
            le = newNode;
            length++;
        }
        else{
            le = new Node(element);
            length++;
        }
    }

    public void removeFirst() throws Exception {
        if(fe == null) {
            throw new Exception("List is empty");
        }
        else {
            fe = fe.getNext();
            length--;
        }
    }

    public void removeAtValue(E valueToRemove) throws Exception{
        Node tmp = fe;
        int exc = length;
        while(tmp != null){
            if(tmp.getNext().value == valueToRemove) {
                tmp.setNext(tmp.getNext().getNext());
                length--;
                break;
            }
            tmp = tmp.next;
        }
        if(exc == length)
            throw new Exception("Value to remove not found");
    }

    public int getLength(){
        return length;
    }

    public void clear(){
        fe = null;
        le = null;
        length = 0;
    }


    @Override                                       //перопределение toString, который неявно вызывается при вызове
    public String toString(){                       //System.out.println(> вот здесь вызывается toString() <)
        String str = "";                                            // Если сюда ↑↑↑ передать объект класса myList(),
        Node tmp = fe;                                          //то он будет преобразован в строку при помощи метода,
        while(tmp != null){                                     //который мы описали слева
            str += tmp.value + " ";
            tmp = tmp.next;
        }
        return str;
    }


}


