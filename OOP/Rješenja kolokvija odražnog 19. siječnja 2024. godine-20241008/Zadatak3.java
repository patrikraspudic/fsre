package K1_Z3;

import java.util.Scanner;
import java.time.*;
import java.time.format.*;
import java.time.temporal.*;

public class Zadatak3 
{
	public static void main(String [] args)
	{	
		Scanner ulaz = new Scanner(System.in);
		
		System.out.print("Unesi prvi datum (DD.MM.GGGG): ");
		String sDatum1 = ulaz.nextLine();
		System.out.print("Unesi drugi datum (DD.MM.GGGG): ");
		String sDatum2 = ulaz.nextLine();
		
		try
		{
			LocalDate datum1 = LocalDate.parse(sDatum1, DateTimeFormatter.ofPattern("dd.MM.yyyy"));
			// System.out.println(datum1);
			
			try 
			{
				LocalDate datum2 = LocalDate.parse(sDatum2, DateTimeFormatter.ofPattern("dd.MM.yyyy"));
				// System.out.println(datum2);
				
				long razmak = Math.abs(ChronoUnit.DAYS.between(datum1, datum2));
				System.out.println("Izme�u je " + razmak + " dana.");
			}
			catch (Exception e)
			{	
				System.out.println("Pogre�no unesen prvi datum! Prekidam izvo�enje programa.");
			}
		}
		
		// ovo je jedno od mogu�ih rje�enja
		catch (Exception e)
		{	
			System.out.println("Pogre�no unesen prvi datum! Prekidam izvo�enje programa.");
		}
	}
}
