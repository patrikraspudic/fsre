package Primjer_05;

class Televizor
{
	// podatkovni èlanovi razreda
	private String proizvodjac;
	private String model;
	private int dijagonala;
	private boolean HDTVReady;
	private boolean ukljucen;
	private int aktivniProgram;
	
	// funkcijski èlanovi razreda - metode
	
	// konstruktori 
	public Televizor(String proizvodjac, String model, int dijagonala, boolean HDTVReady)
	{
		this.proizvodjac = proizvodjac;
		this.model = model;
		this.dijagonala = dijagonala;
		this.HDTVReady = HDTVReady;
		this.ukljucen = false;
		this.aktivniProgram = 1;
	}

	public Televizor(String proizvodjac, String model)
	{
		this.proizvodjac = proizvodjac;
		this.model = model;
		this.ukljucen = false;
		this.aktivniProgram = 1;
	}	
	
	public Televizor()
	{}	
	
	// ostale metode
	public void dopuniPodatke(String proizvodjac, String model, int dijagonala, boolean HDTVReady)
	{
		this.proizvodjac = proizvodjac;
		this.model = model;
		this.dijagonala = dijagonala;
		this.HDTVReady = HDTVReady;
	}

	public void dopuniPodatke(int dijagonala,  boolean HDTVReady)
	{
		this.dijagonala = dijagonala;
		this.HDTVReady = HDTVReady;
	}	
	
	public void ispisiPodatke()
	{
		System.out.println("Podaci o televizoru:");
		System.out.println(" - proizvoðaè: " + this.proizvodjac);
		System.out.println(" - model: " + this.model);
		System.out.println(" - velièina dijagonale: " + this.dijagonala);
		System.out.println(" - HDTV Ready: " + this.HDTVReady);
		System.out.println(" - ukljuèen: " + this.ukljucen);
		System.out.println(" - aktivni program: " + this.aktivniProgram);
		System.out.println("..............................");
	}

	// nadjaèana metoda toString()
	public String toString()
	{
		String povratnaVrijednost = "";
		
		povratnaVrijednost += ("Podaci o televizoru preko toString():" + "\n");
		povratnaVrijednost += (" - proizvoðaè: " + this.proizvodjac + "\n");
		povratnaVrijednost += (" - model: " + this.model + "\n");
		povratnaVrijednost += (" - velièina dijagonale: " + this.dijagonala + "\n");
		povratnaVrijednost += (" - HDTV Ready: " + this.HDTVReady + "\n");
		povratnaVrijednost += (" - ukljuèen: " + this.ukljucen + "\n");
		povratnaVrijednost += (" - aktivni program: " + this.aktivniProgram + "\n");
		povratnaVrijednost += ("..............................");
		
		return povratnaVrijednost;
	}
	
}

public class Primjer_05 
{
	public static void main(String [] args)
	{
		Televizor T1 = new Televizor();	
		T1.ispisiPodatke();
		
		Televizor T2 = new Televizor("Philips", "PH123", 48, true);
		T2.ispisiPodatke();
		
		Televizor T3 = new Televizor("Sharp", "SH100");
		T3.ispisiPodatke();
		
		T1.dopuniPodatke("LG", "LG45", 45, false);
		T1.ispisiPodatke();
		
		T3.dopuniPodatke(22, false);
		T3.ispisiPodatke();
		
		System.out.println(T2);
		
	}
}
