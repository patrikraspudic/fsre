package Primjer_05;

// definicija razreda Televizor
class Televizor
{
	// podatkovni èlanovi
	private String Proizvodjac;
	public String Model;
	public String TipEkrana;
	public int Dijagonala;
	public boolean HDTVReady;
	public boolean Ukljucen;
	public int AktivniProgram;
	static public int BrojTelevizora = 0;
	
	// funkcijski èlanovi (metode)
	// konstruktori
	public Televizor(String Proizvodjac, String Model, String TipEkrana, int Dijagonala, boolean HDTVReady)
	{
		this.Proizvodjac = Proizvodjac;
		this.Model = Model;
		this.TipEkrana = TipEkrana;
		this.Dijagonala = Dijagonala;
		this.HDTVReady = HDTVReady;
		this.Ukljucen = false;
		this.AktivniProgram = 1;
		BrojTelevizora++;
	}

	public Televizor(String Proizvodjac, String TipEkrana, int Dijagonala)
	{
		this.Proizvodjac = Proizvodjac;
		this.TipEkrana = TipEkrana;
		this.Dijagonala = Dijagonala;
		this.Ukljucen = false;
		this.AktivniProgram = 1;
		BrojTelevizora++;
	}

	public Televizor()
	{
		this.Ukljucen = false;
		this.AktivniProgram = 1;
		BrojTelevizora++;
	}
	
	// konstruktor kopije
	public Televizor(Televizor TV)
	{
		this.Proizvodjac = TV.Proizvodjac;
		this.Model = TV.Model;
		this.TipEkrana = TV.TipEkrana;
		this.Dijagonala = TV.Dijagonala;
		this.HDTVReady = TV.HDTVReady;
		this.Ukljucen = TV.Ukljucen;
		this.AktivniProgram = TV.AktivniProgram;
		BrojTelevizora++;
	}
	
	// pristupnici za privatni podatkovni èlan Proizvoðaè
	public void setProizvodjac(String Proizvodjac)
	{
		this.Proizvodjac = Proizvodjac;
	}
	
	public String getProizvodjac()
	{
		return this.Proizvodjac;
	}
	
	
	// ostale metode	
	public void DopuniPodatke(String Model, boolean HDTVReady)
	{
		this.Model = Model;
		this.HDTVReady = HDTVReady;
	}

	public void DopuniPodatke(String Proizvodjac, String Model, String TipEkrana, int Dijagonala, boolean HDTVReady)	
	{
		this.Proizvodjac = Proizvodjac;
		this.Model = Model;
		this.TipEkrana = TipEkrana;
		this.Dijagonala = Dijagonala;
		this.HDTVReady = HDTVReady;
	}
	
	public void UkljuciTelevizor()
	{
		this.Ukljucen = true;
	}
	
	public void IskljuciTelevizor()
	{
		this.Ukljucen = false;
	}	
	
	public void PromijeniProgram(int NoviProgram)
	{
		this.AktivniProgram = NoviProgram;
	}	
	
	
	public String IspisiPodatke()
	{
		String rezultat = "";
		rezultat += "Televizor proizvoðaèa " + this.Proizvodjac;
		rezultat += ", model " + this.Model;
		rezultat += ", sa " + this.TipEkrana + " ekranom\n";
		rezultat += " ima dijagonalu od " + this.Dijagonala + " inèa i";
		if(this.HDTVReady)
			rezultat += " ima HDTV moguænost.\n";
		else
			rezultat += " nema HDTV moguænost.\n";
		if(this.Ukljucen)
			rezultat += "Televizor je ukljuèen i aktivni program je " + 
					this.AktivniProgram + ".\n";
		else
			rezultat += "Televizor nije ukljuèen.\n";
		rezultat += "U trgovini je " + BrojTelevizora + " televizora.";
		return rezultat;
	}	
		
	// nadjaèavanje metode toString()
	public String toString()
	{
		String rezultat = "";
		rezultat += "Televizor proizvoðaèa " + this.Proizvodjac;
		rezultat += ", model " + this.Model;
		rezultat += ", sa " + this.TipEkrana + " ekranom\n";
		rezultat += " ima dijagonalu od " + this.Dijagonala + " inèa i";
		if(this.HDTVReady)
			rezultat += " ima HDTV moguænost.\n";
		else
			rezultat += " nema HDTV moguænost.\n";
		if(this.Ukljucen)
			rezultat += "Televizor je ukljuèen i aktivni program je " + 
					this.AktivniProgram + ".\n";
		else
			rezultat += "Televizor nije ukljuèen.\n";
		rezultat += "U trgovini je " + BrojTelevizora + " televizora.";		
		return rezultat;
	}
}

public class Primjer_05 
{
	public static void main(String [] args)
	{
		Televizor TV1 = new Televizor("Samsung", "SH123", "LCD", 50, true);
		System.out.println(TV1.IspisiPodatke());
		System.out.println("----------");

		Televizor TV2 = new Televizor("LG", "Plazma", 40);
		System.out.println(TV2);
		System.out.println("----------");

		Televizor TV3 = new Televizor();
		System.out.println(TV3);
		System.out.println("----------");

		Televizor TV4 = new Televizor(TV1);
		System.out.println(TV4);
		System.out.println("----------");

		Televizor TV5 = TV2;		
		System.out.println(TV5);
		
		TV1.setProizvodjac("Sharp");
		System.out.println("----------");
		System.out.println(TV1);
		System.out.println("----------");
		System.out.println(TV4);
		
		TV2.DopuniPodatke("LG1234", true);
		TV3.DopuniPodatke("Konèar", "Zagreb_1", "Katodni", 24, false);
		System.out.println("----------");
		System.out.println(TV2);
		System.out.println("----------");
		System.out.println(TV3);
		System.out.println("----------");		
		System.out.println("Proizvoðaè za TV3 je " + TV3.getProizvodjac() + ".");
		System.out.println("----------");		
		
		System.out.println(TV4);
		System.out.println("----------");
		TV4.UkljuciTelevizor();
		System.out.println(TV4);
		System.out.println("----------");
		TV4.PromijeniProgram(25);
		System.out.println(TV4);
		System.out.println("----------");		
		TV4.IskljuciTelevizor();
		System.out.println(TV4);
		System.out.println("----------");
		TV4.UkljuciTelevizor();
		System.out.println(TV4);
		System.out.println("----------");
		
		System.out.println("U trgovini je ukupno " + Televizor.BrojTelevizora + 
				" televizora.");		
		System.out.println("U trgovini je ukupno " + TV1.BrojTelevizora + 
				" televizora.");		
		System.out.println("----------");
		
		Televizor [] NizTV = new Televizor[5];
		NizTV[0] = new Televizor ("Pr01", "Mo01", "Ek01", 34, true);
		NizTV[1] = new Televizor ("Pr02", "Mo02", "Ek02", 30, false);
		NizTV[2] = new Televizor ("Pr03", "Mo03", "Ek03", 42, true);
		NizTV[3] = new Televizor ("Pr04", "Mo04", "Ek04", 26, false);
		NizTV[4] = new Televizor ("Pr05", "Mo05", "Ek05", 50, true);
		
		int HDTVuNizTV = 0;
		for(int i = 0; i < 5; i++)
		{
			NizTV[i].Ukljucen = true;
			NizTV[i].AktivniProgram = i + 1;
			if(NizTV[i].HDTVReady)
				HDTVuNizTV++;
			System.out.println(NizTV[i]);
		}
		System.out.println("Od zadnjih 5 televizora njih " + HDTVuNizTV + 
				" ima HDTV moguænost.");		
		
		System.out.println("----------");
		
	}	
}
