package Kolokvij2;

import java.util.Scanner;
import java.util.Random;

interface Grunt
{
	public Grunt evidencija (String vrsta);
}

abstract class Posjed implements Grunt
{
	protected String evidencijskiBroj;
	protected double povrsina;
	protected double cijena;
	protected static String [] vrsta = {"privatni posjed", "javni posjed", 
			"državni posjed", "graðevinski posjed"};
	protected static double [] cijenaKvadrata = {50.0, 30.0, 5.0, 500.0};
	
	public Posjed(String evidencijskiBroj, double povrsina)
	{
		this.evidencijskiBroj = evidencijskiBroj;
		this.povrsina = povrsina;
	}
	
	public Grunt evidencija(String vrsta)
	{
		if(vrsta == "privatni posjed")
			return new PrivatniPosjed(this.evidencijskiBroj, this.povrsina);
		else if (vrsta == "javni posjed")
			return new JavniPosjed(this.evidencijskiBroj, this.povrsina);
		else if (vrsta == "državni posjed")
			return new DrzavniPosjed(this.evidencijskiBroj, this.povrsina);
		else
			return new GradjevinskiPosjed(this.evidencijskiBroj, this.povrsina);
	}
	
	public Posjed prenamjena(Posjed P, String drugaVrsta)
	{
		return (Posjed)P.evidencija(drugaVrsta);
	}
}

class PrivatniPosjed extends Posjed
{
	public String vrstaPosjeda;
	private static int brojac = 0;
	
	public PrivatniPosjed(String evidencijskiBroj, double povrsina)
	{
		super(evidencijskiBroj, povrsina);
		this.vrstaPosjeda = Posjed.vrsta[0];
		this.cijena = this.povrsina * Posjed.cijenaKvadrata[0];
		brojac++;
	}
	
	public static int dajBrojac()
	{
		return brojac;
	}
	
	public static void postaviBrojac(int novaVrijednost)
	{
		brojac = novaVrijednost;
	}
	
	public String toString()
	{
		return "Posjed "+ this.evidencijskiBroj + ", vrsta (" + this.vrstaPosjeda + 
				"), povrsina = " + this.povrsina + "m^2, cijena = " + 
				this.cijena + "KM";
	}
}

class JavniPosjed extends Posjed
{
	public String vrstaPosjeda;
	private static int brojac = 0;
	
	public JavniPosjed(String evidencijskiBroj, double povrsina)
	{
		super(evidencijskiBroj, povrsina);
		this.vrstaPosjeda = Posjed.vrsta[1];
		this.cijena = this.povrsina * Posjed.cijenaKvadrata[1];
		brojac++;
	}
		
	public static int dajBrojac()
	{
		return brojac;
	}
	
	public static void postaviBrojac(int novaVrijednost)
	{
		brojac = novaVrijednost;
	}
	
	public String toString()
	{
		return "Posjed "+ this.evidencijskiBroj + ", vrsta (" + this.vrstaPosjeda + 
				"), povrsina = " + this.povrsina + "m^2, cijena = " + 
				this.cijena + "KM";
	}
}

class DrzavniPosjed extends Posjed
{
	public String vrstaPosjeda;
	private static int brojac = 0;
	
	public DrzavniPosjed(String evidencijskiBroj, double povrsina)
	{
		super(evidencijskiBroj, povrsina);
		this.vrstaPosjeda = Posjed.vrsta[2];
		this.cijena = this.povrsina * Posjed.cijenaKvadrata[2];
		brojac++;
	}
	
	public static int dajBrojac()
	{
		return brojac;
	}
	
	public static void postaviBrojac(int novaVrijednost)
	{
		brojac = novaVrijednost;
	}

	public String toString()
	{
		return "Posjed "+ this.evidencijskiBroj + ", vrsta (" + this.vrstaPosjeda + 
				"), povrsina = " + this.povrsina + "m^2, cijena = " + 
				this.cijena + "KM";
	}
}

class GradjevinskiPosjed extends Posjed
{
	public String vrstaPosjeda;
	private static int brojac = 0;
	
	public GradjevinskiPosjed(String evidencijskiBroj, double povrsina)
	{
		super(evidencijskiBroj, povrsina);
		this.vrstaPosjeda = Posjed.vrsta[3];
		this.cijena = this.povrsina * Posjed.cijenaKvadrata[3];
		brojac++;
	}
	
	public static int dajBrojac()
	{
		return brojac;
	}
	
	public static void postaviBrojac(int novaVrijednost)
	{
		brojac = novaVrijednost;
	}
	
	public String toString()
	{
		return "Posjed "+ this.evidencijskiBroj + ", vrsta (" + this.vrstaPosjeda + 
				"), povrsina = " + this.povrsina + "m^2, cijena = " + 
				this.cijena + "KM";
	}
}

public class Kolokvij2 
{	
	public static void main(String [] args)
	{
		Scanner ulaz = new Scanner(System.in); 
		Random slucaj = new Random();
		int n;
		
		System.out.print("Koliko posjeda æeš evidentirati? ");
		n = ulaz.nextInt();
		
		Grunt [] P = new Grunt[n];
		for(int i = 0; i < n; i++)
		{
			int mojSlucaj = slucaj.nextInt(4);
			int mojaPovrsina = slucaj.nextInt(2000);
			switch(mojSlucaj)
			{
				case 0:
				{
					
					P[i] = new PrivatniPosjed("1234-" + (i + 1), mojaPovrsina);
					break;
				}
				case 1:
				{
					
					P[i] = new JavniPosjed("1234-" + (i + 1), mojaPovrsina);
					break;
				}
				case 2:
				{
					
					P[i] = new DrzavniPosjed("1234-" + (i + 1), mojaPovrsina);
					break;
				}
				case 3:
				{
					
					P[i] = new GradjevinskiPosjed("1234-" + (i + 1), mojaPovrsina);
					break;
				}
			}
		}
		
		System.out.println("----------");
		for(int i = 0; i < n; i++)
			System.out.println(P[i]);
		
		System.out.println("----------");
		System.out.println("Poèetno stanje:");
		String [] vrstePosjeda1 = {"privatni posjed", "javni posjed", 
				"državni posjed", "graðevinski posjed"};
		String tmpVrsta1;
		int [] brojPosjeda1 = {PrivatniPosjed.dajBrojac(), JavniPosjed.dajBrojac(), 
				DrzavniPosjed.dajBrojac(), GradjevinskiPosjed.dajBrojac()};
		int tmpBroj1;
		
		for(int i = 0; i < 3; i++)
			for(int j = i + 1; j < 4; j++)
				if(brojPosjeda1[i] < brojPosjeda1[j])
				{
					tmpVrsta1 = vrstePosjeda1[i];
					vrstePosjeda1[i] = vrstePosjeda1[j];
					vrstePosjeda1[j] = tmpVrsta1;
					tmpBroj1 = brojPosjeda1[i];
					brojPosjeda1[i] = brojPosjeda1[j];
					brojPosjeda1[j] = tmpBroj1;
				}
		for(int i = 0; i < 4; i++)
			System.out.println(" - " + vrstePosjeda1[i] + ": " + brojPosjeda1[i]); 

		// prenamjena 
		PrivatniPosjed.postaviBrojac(0);
		JavniPosjed.postaviBrojac(0);
		DrzavniPosjed.postaviBrojac(0);
		GradjevinskiPosjed.postaviBrojac(0);
		
		System.out.println("Prenamjena");
		for(int i = 0; i < n; i++)
		{
			int mojSlucaj = slucaj.nextInt(4);
			P[i] = ((Posjed)P[i]).prenamjena((Posjed)P[i], Posjed.vrsta[mojSlucaj]);
		}

		System.out.println("----------");
		for(int i = 0; i < n; i++)
			System.out.println(P[i]);
		
		System.out.println("----------");
		System.out.println("Završno stanje:");
		String [] vrstePosjeda2 = {"privatni posjed", "javni posjed", 
				"državni posjed", "graðevinski posjed"};
		String tmpVrsta2;
		int [] brojPosjeda2 = {PrivatniPosjed.dajBrojac(), JavniPosjed.dajBrojac(), 
				DrzavniPosjed.dajBrojac(), GradjevinskiPosjed.dajBrojac()};
		int tmpBroj2;
		
		for(int i = 0; i < 3; i++)
			for(int j = i + 1; j < 4; j++)
				if(brojPosjeda2[i] < brojPosjeda2[j])
				{
					tmpVrsta2 = vrstePosjeda2[i];
					vrstePosjeda2[i] = vrstePosjeda2[j];
					vrstePosjeda2[j] = tmpVrsta2;
					tmpBroj2 = brojPosjeda2[i];
					brojPosjeda2[i] = brojPosjeda2[j];
					brojPosjeda2[j] = tmpBroj2;
				}
		for(int i = 0; i < 4; i++)
			System.out.println(" - " + vrstePosjeda2[i] + ": " + brojPosjeda2[i]); 
		
	}
}
