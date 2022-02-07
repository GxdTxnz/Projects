import java.util.Scanner;

public class ComplexTest 
{
	public static void main(String args[]) 
	{
		System.out.println ("!!!!!ВВОД НА АНГЛ. ЯЗЫКЕ!!!!!");
		System.out.println ("Введите кол-во элементов (не более двух)");
		Scanner sc = new Scanner (System.in);  //сканер ввода с клавиатуры
		int usl = sc.nextInt();  //сравниваем значение введенное с клавиатуры 
		if (usl == 1) 
		{
			System.out.println ("Введите вещественную часть:");
			int j = sc.nextInt(); //сканер числа
			System.out.println ("Введите мнимую часть (без i):");
			int k = sc.nextInt(); //сканер числа 
			Complex c1 = new Complex (j,k);
			System.out.println ("Выберите действие(A - вычислить аргумент, M - вычислить модуль)");
			String z = sc.next();  //сканнер до пробела
			char c = z.charAt(0); //Возвращаем значение по индексу 
			if (c == 'M') 
			{
				System.out.println (c1.getMod());
			}
			else if (c == 'A')
			{
				if (k < 0) 
				{
				System.out.println (c1.getArg() + Math.PI);
				}
				else 
				{
					System.out.println (c1.getArg() );
				}
			}
			else 
			{
				System.out.println ("Ошибка");
				System.exit(0);
			}
		}
		else if (usl==2) 
		{
			System.out.println ("Ввод первого комплексного числа");
			System.out.println ("Введите вещественную часть");
			int j = sc.nextInt();
			System.out.println ("Введите мнимую часть (без i)");
			int k = sc.nextInt();
			Complex c1 = new Complex(j,k);
			System.out.println ("Ввод второго комплексного числа");
			System.out.println ("Введите вещественную часть:");
			int m = sc.nextInt();
			System.out.println ("Введите мнимую часть (без i):");
			int n = sc.nextInt();
			Complex c2 = new Complex(m, n);
			Complex c3 = new Complex();
			System.out.println ("Выберете действие (+ или -)");
			String z = sc.next();
			char c = z.charAt(0);
			if (c == '+')
			{
				c3 = c3.getSum (c1, c2);
				if (c3.re < 0 ) 
				{
					System.out.print("(" + c3.re + ")" + "+");
				}
				else 
				{
					System.out.print (c3.re + "+");
				}
				if (c3.im < 0) 
				{
				System.out.print ("(" + c3.im + "i)");
				}
				else 
				{
					System.out.print(c3.im + "i");
				}
			}
			else if (c == '-')
			{
				c3 = c3.getSub(c1, c2);
				if (c3.re < 0) 
				{
				System.out.print("(" + c3.re + ")" + "+");
				}
				else 
				{
				System.out.print(c3.re + "+");
				}
				if (c3.im < 0) 
				{
				System.out.print("(" + c3.im + "i)");
				}
				else 
				{
					System.out.print (c3.im + "i");
				}
			}
			else 
			{
				System.out.println ("Ошибка");
				System.exit(0);
			}
		}
		sc.close();
	}
}
