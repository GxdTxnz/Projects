public class Complex //Название класса (всегда соответсвует названию файла)
{
	double re;  //тип данных, хранящий число с плав. точкой (занимает 8 байт)
	double im;  //re - вещ. часть, im - мнимая
	
	public Complex() 
	{
		this(0.0, 0.0);  //вызов конструктора
	}
	
	public Complex(double r, double i) 
	{
		this.re = r; //метод ссылается на вызвавший его объект
		this.im = i; //испоьзуем, т.к. параметры имеют одинаковые названия с переменными класа
	}
	
	public double getMod() 
	{
		return (Math.sqrt (Math.pow (re, 2) + Math.pow (im,2) ) );  //функция вычисления модуля
	}
	
	public double getArg() 
	{
		return (Math.atan (im / re) ); //функция вычисления аргумента
	}
	
	public Complex getSum (Complex c1, Complex c2) //функция вычисления суммы
	{
		Complex result = new Complex();
		result.re = (c1.re + c2.re);
		result.im = (c1.im + c2.im);
		return (result);
	}
	
	public Complex getSub(Complex c1, Complex c2) //функиця вычисления разности
	{
		Complex result = new Complex();
		result.re = (c1.re - c2.re);
		result.im = (c1.im - c2.im);
		return (result);
	}
}
