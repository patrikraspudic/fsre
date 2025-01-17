package Primjer_06;

class Televizor
{
	// podatkovni èlanovi razreda
	private String proizvodjac;
	private String model;
	private int dijagonala;
	private boolean HDTVReady;
	private boolean ukljucen;
	private int aktivniProgram;
	public static int brojTelevizora = 0;
	
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
		brojTelevizora++;
	}

	public Televizor(String proizvodjac, String model)
	{
		this.proizvodjac = proizvodjac;
		this.model = model;
		this.ukljucen = false;
		this.aktivniProgram = 1;
		brojTelevizora++;
	}	
	
	public Televizor()
	{
		this.aktivniProgram = 1;
		brojTelevizora++;
	}	
	
	// konstruktor kopije
	public Televizor(Televizor TV)
	{
		this.proizvodjac = TV.proizvodjac;
		this.model = TV.model;
		this.dijagonala = TV.dijagonala;
		this.HDTVReady = TV.HDTVReady;
		this.ukljucen = false;
		this.aktivniProgram = 1;
		brojTelevizora++;
	}
	
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

	public void ukljuciTelevizor()
	{
		this.ukljucen = true;
	}

	public void iskljuciTelevizor()
	{
		this.ukljucen = false;
	}	
	
	public void promijeniProgram(int noviProgram)
	{
		this.aktivniProgram = noviProgram;
	}
	
	public String dohvatiProizvodjaca()
	{
		return this.proizvodjac;
	}
	
	public static void sviTelevizoriProizvodjaca(Televizor [] TV, String trazeniProizvodjac)
	{
		for(int i = 0; i < TV.length; i++)
			if(TV[i].proizvodjac == trazeniProizvodjac)
				System.out.println(TV[i]);
	}
	
	// nadjaèana metoda toString()
	public String toString()
	{
		String povratnaVrijednost = "";
		
		povratnaVrijednost += ("Podaci o televizoru:" + "\n");
		povratnaVrijednost += (" - proizvoðaè: " + this.proizvodjac + "\n");
		povratnaVrijednost += (" - model: " + this.model + "\n");
		povratnaVrijednost += (" - velièina dijagonale: " + this.dijagonala + "\n");
		povratnaVrijednost += (" - HDTV Ready: " + this.HDTVReady + "\n");
		povratnaVrijednost += (" - ukljuèen: " + this.ukljucen + "\n");
		povratnaVrijednost += (" - aktivni program: " + this.aktivniProgram + "\n");
		povratnaVrijednost += ("Trenutno je u trgovini " + brojTelevizora + " televizora.\n");
		povratnaVrijednost += ("..............................");
		
		return povratnaVrijednost;
	}
	
}

public class Primjer_06 
{
	public static void main(String [] args)
	{
		Televizor T1 = new Televizor();	
		System.out.println(T1);
		
		Televizor T2 = new Televizor("Philips", "PH123", 48, true);
		System.out.println(T2);
		
		Televizor T3 = new Televizor("Sharp", "SH100");
		System.out.println(T3);
		
		T1.dopuniPodatke("LG", "LG45", 45, false);
		System.out.println(T1);
		
		T3.dopuniPodatke(22, false);
		System.out.println(T3);
		
		T3.ukljuciTelevizor();
		System.out.println(T3);
		
		T3.iskljuciTelevizor();
		System.out.println(T3);

		System.out.println(T1);
		
		T1.promijeniProgram(5);
		System.out.println(T1);
		
		Televizor [] NizTV = new Televizor[10];
		
		NizTV[1] = T1;
		NizTV[2] = new Televizor(T2);
		NizTV[3] = T3;
		
		System.out.println(T1);
		System.out.println(NizTV[1]);
		
		T1.ukljuciTelevizor();
		NizTV[1].promijeniProgram(8);
		
		System.out.println(T1);
		System.out.println(NizTV[1]);

		System.out.println(T2);
		System.out.println(NizTV[2]);
		
		T2.ukljuciTelevizor();
		NizTV[2].promijeniProgram(7);
		
		System.out.println(T2);
		System.out.println(NizTV[2]);
	
		NizTV[0] = new Televizor("Sharp", "SH200", 42, false);
		NizTV[4] = new Televizor("Sony", "SO100", 48, true);
		NizTV[5] = new Televizor("Samsung", "SAM10", 45, true);
		NizTV[6] = new Televizor("Gorenje", "G10", 40, false);
		NizTV[7] = new Televizor("LG", "LG200");
		NizTV[8] = new Televizor("Vivax", "VX100");
		NizTV[9] = new Televizor("Beko", "BK800", 51, true);
		
		System.out.println("--------------------------------------------------");
		System.out.println("--------------------------------------------------");
		
		for(int i = 0; i < 10; i++)
			if(NizTV[i].dohvatiProizvodjaca() == "Sharp")
				System.out.println(NizTV[i]);

		System.out.println("--------------------------------------------------");
		System.out.println("--------------------------------------------------");
		
		Televizor.sviTelevizoriProizvodjaca(NizTV, "LG"); 
		
	}
}
