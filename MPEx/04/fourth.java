import java.util.Scanner;
 
public class fourth 
{
	public static void main(String[] args) 
	{
		Scanner sc = new Scanner (System.in);
		String s = sc.next();
		char[] arr = s.toCharArray();        
		int count = 1;
		int max = 0;
		char c = 0;
		for (int i = 1; i < arr.length; i++) 
		{
			if (arr[i] == arr[i - 1]) 
			{
				count++;
				if (count > max) 
				{
					c = arr[i];
					max = count;
				}
			} 
			else 
			{
				count = 1;
			}
		}     
		if (max > 1)
		{
			System.out.println("Символ " + c + " повторяется " + max + " раз");
		}
	}
}
