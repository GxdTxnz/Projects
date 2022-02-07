import java.util.Scanner;


public class eleventh
{
	public static void main(String[] args) 
	{
		System.out.print("Введите строку: ");
		Scanner s = new Scanner(System.in);
		String a = s.nextLine();
		String b = new String(a);
		int[] res = new int[a.length()];
		int end = 1;
		char q;
		for(int i = 0; i < b.length(); i++)
		{
			for(int j = 0;j < a.length(); j++)
			{
				if(a.charAt(j) == b.charAt(i))
				{
					res[j]++;;
					break;
				}
			}
		}
		int index = 0;
		int min = res[index];
		for (int i = 0; i < res.length; i++)
		{
			if(res[i] > 0)
			{
				if (res[i] <= min)
				{
					min = res[i];
					index = i;
				}
			}
		}
		System.out.println("Элемент, который реже всего встречается: " + a.charAt(index));
	}
}

