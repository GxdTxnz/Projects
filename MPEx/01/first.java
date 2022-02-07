import java.util.Scanner;

public class first
{
	public static void main(String[] args) 
	{
		System.out.println("Введите строку: ");
		Scanner sc = new Scanner (System.in);
		String s = sc.next();
		char[] arr = s.toCharArray();
		int sum = 0;
		for(int i = 0; i < arr.length; i++)
		{
			sum++;
		}
		System.out.println("В строке " + sum + " символов");
	}
}
