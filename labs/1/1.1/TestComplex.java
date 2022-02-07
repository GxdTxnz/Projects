
public class TestComplex 
	{
		public static void main(String[] args) 
		{
			Complex x = new Complex(8, 4);
			Complex y = new Complex(5, -3);
			System.out.println(Complex.plus(x, y));
			System.out.println(Complex.minus(x, y));
			System.out.println(x.module());
			System.out.println(x.arg());
		}
	}
