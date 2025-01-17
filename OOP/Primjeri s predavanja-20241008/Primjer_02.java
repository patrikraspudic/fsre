// primjer unosi ime korisnika i ispisuje pozdravnu poruku

package Primjer_02;

// ukljuèuje se razred java.util.Scanner
import java.util.Scanner;

public class Primjer_02 
{
	public static void main(String [] args)
	{
		// instancira se objekt razreda java.util.Scanner
		Scanner ulaz = new Scanner(System.in);
		
		System.out.print("Kako se zoveš? ");
		String ime = ulaz.nextLine();
		
		System.out.println("Pozdrav " + ime + "!");
	}
}
