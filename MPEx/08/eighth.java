import java.util.Scanner;

class eighth
{
	public static void main(String[] args)
	{
		Scanner s = new Scanner(System.in);
		System.out.println("Введите количество строк:");
		int num = s.nextInt();
		System.out.println("Заполните " + num + " строк(-и): ");
		String[] arr = new String[num];
		Scanner sc = new Scanner(System.in);
		String help;
		int res = 0;
		int index = 0;
		for(int i = 0; i < num; i++)
		{
			arr[i] = sc.nextLine();
			if(arr[i].length() > res)
			{
				res = arr[i].length();
				index = i;;
			}
		}
		System.out.println("Самая длинная строка: " + arr[index]);
	}
}
