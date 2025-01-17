// primjer unosi dva cijela broja x i y, i ispisuje operaciju zbrajanja u obliku x + y = z

package Primjer_03;

import java.util.Scanner;

public class Primjer_03 
{
	public static void main(String [] args)
	{
		Scanner ulaz = new Scanner(System.in);
		
		System.out.print("Unesi prvi cijeli broj: ");
		int x = ulaz.nextInt();
		System.out.print("Unesi drugi cijeli broj: ");
		int y = ulaz.nextInt();
		
		System.out.println(x + " + " + y + " = " + (x + y));
	}
}
