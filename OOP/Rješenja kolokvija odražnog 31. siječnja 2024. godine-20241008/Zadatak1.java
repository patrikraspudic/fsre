package K2_Z1;

import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

abstract class Osoba
{
	private int ID;
	private String imePrezime;
	
	public Osoba(int ID, String imePrezime)
	{
		this.ID = ID;
		this.imePrezime = imePrezime;
	}
	
	abstract public double dohvatiOcjenu();
	
	final public boolean jeLiIzvanredan()
	{
		return (this.dohvatiOcjenu() > 4.5);
	}
	
	public String toString()
	{
		return imePrezime + "(ID: " + ID + ")"; 
	}
	
	// metode za postavljanje i dohvaæanje podatkovnih èlanova
	public int getID() { return this.ID; }
	public void setID(int ID) { this.ID = ID; }
	public String getImePrezime() {return this.imePrezime; }
	public void setImePrezime(String imePrezime) { this.imePrezime = imePrezime; }
}

class Student extends Osoba
{
	private int godinaStudija;
	private ArrayList <Integer> ocjeneIspita = new ArrayList<>();
	
	public Student(int ID, String imePrezime, int godinaStudija)
	{
		super(ID, imePrezime);
		this.godinaStudija = godinaStudija;
		this.unesiOcjene();
	}
	
	private void unesiOcjene()
	{
		Scanner ulaz = new Scanner(System.in);
		int ocjena;
		
		System.out.println("Unesi ocjene (1 - 5) za studenta " + this.getImePrezime() + ":");
		do
		{
			ocjena = ulaz.nextInt();
			if ((ocjena >= 1) && (ocjena <= 5))
				this.ocjeneIspita.add(ocjena);
		}
		while (ocjena != 0);	
	}
	
	public double dohvatiOcjenu()
	{
		double sumaOcjena = 0;
		for(int ocjena: this.ocjeneIspita)
			sumaOcjena += ocjena;
		
		return sumaOcjena / this.ocjeneIspita.size();
	}

	public String toString()
	{
		return String.format("%s je student %d. godine s prosjekom ocjena %.2f", super.toString(), this.godinaStudija, this.dohvatiOcjenu()); 
	}	
	
	// metode za postavljanje i dohvaæanje podatkovnih èlanova
	public int getGodinaStudija() { return this.godinaStudija; }
	public void setGodinaStudija(int godinaStudija) { this.godinaStudija = godinaStudija; }
}

class Nastavnik extends Osoba
{
	private String predmet;
	private double ocjenaNastavnika;
	
	public Nastavnik(int ID, String imePrezime, String predmet, double ocjenaNastavnika)
	{
		super(ID, imePrezime);
		this.predmet = predmet;
		this.ocjenaNastavnika = ocjenaNastavnika;
	}
	
	public double dohvatiOcjenu()
	{
		return ocjenaNastavnika;
	}

	public String toString()
	{
		return String.format("%s je nastavnik koji predaje %s s ocjenom nastavnika %.2f", super.toString(), this.predmet, this.ocjenaNastavnika);
	}	
	
	// metode za postavljanje i dohvaæanje podatkovnih èlanova
	public String getPredmet() { return this.predmet; }
	public void setPredmet(String predmet) { this.predmet = predmet; }
	public double getOcjenaNastavnika() { return this.ocjenaNastavnika; }
	public void setOcjenaNastavnika(double ocjenaNastavnika) { this.ocjenaNastavnika = ocjenaNastavnika; }	
}


public class Zadatak1 
{
	public static void main(String [] args)
	{
		Osoba [] Fakultet = new Osoba[10];
		Random slucajanIzbor = new Random();
		
		for(int i = 0; i < 5; i++)
		{
			int slucaj = slucajanIzbor.nextInt(2);
			switch (slucaj)
			{
				case 0:
				{
					System.out.println((i + 1) + ". osoba je student.");
					Fakultet[i] = new Student(i + 1, "Student_" + (i + 1), slucajanIzbor.nextInt(5) + 1);
					break;
				}	
				case 1:
				{
					System.out.println((i + 1) + ". osoba je nastavnik.");
					Fakultet[i] = new Nastavnik(i + 1, "Nastavnik_" + (i + 1), "Predmet_" + (i + 1), 1 + slucajanIzbor.nextFloat() * 4);
					break;
				}
			}
		}

		// provjera ispravnosti sluèajnog generiranja studenata i nastavnika 
		System.out.println("----------");
		for(int i = 0; i < 5; i++)
			System.out.println(Fakultet[i]);
		System.out.println("----------");
		
		System.out.println("Izvanredni studenti su:");
		for(int i = 0; i < 5; i++)
			if((Fakultet[i] instanceof Student) && (Fakultet[i].jeLiIzvanredan()))
				System.out.println(Fakultet[i]);
		System.out.println("----------");

		System.out.println("Izvanredni nastavnici su:");
		for(int i = 0; i < 5; i++)
			if((Fakultet[i] instanceof Nastavnik) && (Fakultet[i].jeLiIzvanredan()))
				System.out.println(Fakultet[i]);
		System.out.println("----------");

	}

}
