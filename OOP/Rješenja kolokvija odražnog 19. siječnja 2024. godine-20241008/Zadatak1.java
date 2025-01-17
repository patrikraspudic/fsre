package K1_Z1;

import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;

public class Zadatak1 
{
	public static void main(String [] args)
	{
		Scanner ulaz = new Scanner(System.in);
		
		System.out.print("Unesi neki broj: ");
		int broj = ulaz.nextInt();

		ArrayList<Integer> znamenke = new ArrayList<>();
		
		while(broj != 0)
		{
			znamenke.add(broj % 10);
			broj /= 10;
		}
		
		System.out.println("Najmanja znamenka je " + Collections.min(znamenke) + 
				", a najveæa " + Collections.max(znamenke) + ".");	
		
		// ovo je jedno od moguæih rješenja
	}
}
