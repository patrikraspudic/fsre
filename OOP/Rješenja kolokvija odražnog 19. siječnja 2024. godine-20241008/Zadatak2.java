package K1_Z2;

import java.util.Scanner;


public class Zadatak2 
{
	public static void main(String [] args)
	{
		Scanner ulaz = new Scanner(System.in);
	
		System.out.print("Unesite stranice trokuta odvojene razmakom: ");
		String triStranice = ulaz.nextLine();

		String [] stranice = triStranice.split(" ");
		int [] s = new int[3];
		
		for(int i = 0; i < 3; i++)
			s[i] = Integer.valueOf(stranice[i]);
		
		
		if((s[0] * s[0] + s[1] * s[1] == s[2] * s[2]) || (s[0] * s[0] + s[2] * s[2] == s[1] * s[1])
				|| (s[1] * s[1] + s[2] * s[2] == s[0] * s[0]))
			System.out.println("DA");
		else
			System.out.println("NE");
		
		// ovo je jedno od moguæih rješenja		
	}
}
