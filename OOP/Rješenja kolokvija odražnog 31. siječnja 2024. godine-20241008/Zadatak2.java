package K2_Z2;

import java.util.Random;

interface Vozilo
{
	int dohvatiMaksimalanBrojPutnika();
	double dohvatiMaksimalnuNosivost(); 
}

abstract class CestovnoVozilo implements Vozilo
{
	private String modelVozila;
	private String registracijaVozila;
	
	public CestovnoVozilo (String modelVozila, String registracijaVozila)
	{	
		this.modelVozila = modelVozila;
		this.registracijaVozila = registracijaVozila;
	}
	
	public String toString() 
	{
		return String.format("Vozilo %s ima registarsku oznaku %s.", 
				this.modelVozila, this.registracijaVozila); 
	}
	
	// metode za postavljanje i dohvaæanje podatkovnih èlanova
	public String getModelVozila() { return this.modelVozila; }
	public void setModelVozila(String modelVozila) { this.modelVozila = modelVozila; }
	public String getRegistracijaVozila() { return this.registracijaVozila; }
	public void setRegistracijaVozila(String registracijaVozila) { this.registracijaVozila = registracijaVozila; }
	
	// metode koje propisuje suèelje su po defaultu apstraktne i ne moraju se navoditi u apstraktnom razredu
}

class OsobnoVozilo extends CestovnoVozilo
{
	private String tipOsobnogVozila;
	private int brojSjedala;
	private double zapreminaPrtljaznika; 

	public OsobnoVozilo (String modelVozila, String registracijaVozila, String tipOsobnogVozila, 
			int brojSjedala, double zapreminaPrtljaznika)
	{	
		super(modelVozila, registracijaVozila);
		this.tipOsobnogVozila = tipOsobnogVozila;
		this.brojSjedala = brojSjedala;
		this.zapreminaPrtljaznika = zapreminaPrtljaznika;
	}

	public String toString() 
	{
		return String.format("%s\nOsobno vozilo tipa %s ima %d sjedala i zapreminu prtljažnika od %.2f litara.", 
			super.toString(), this.tipOsobnogVozila, this.brojSjedala, this.zapreminaPrtljaznika); 
	}

	// metode za postavljanje i dohvaæanje podatkovnih èlanova
	public String getTipOsobnogVozila() { return this.tipOsobnogVozila; }
	public void setTipOsobnogVozila(String tipOsobnogVozila) { this.tipOsobnogVozila = tipOsobnogVozila; }
	public int getBrojSjedala() { return this.brojSjedala; }
	public void setBrojSjedala(int brojSjedala) { this.brojSjedala = brojSjedala; }
	public double getZapreminaPrtljaznika() { return this.zapreminaPrtljaznika; }
	public void setZapreminaPrtljaznika(double zapreminaPrtljaznika) { this.zapreminaPrtljaznika = zapreminaPrtljaznika; }

	// implementacija metoda koje propisuje suèelje
	public int dohvatiMaksimalanBrojPutnika() { return this.getBrojSjedala(); }
	public double dohvatiMaksimalnuNosivost() { return this.getZapreminaPrtljaznika() / 0.00375; } 
}

abstract class Kombi extends CestovnoVozilo
{
	private double visinaKombija;
	private double duzinaKombija;

	public Kombi (String modelVozila, String registracijaVozila, double visinaKombija,
			double duzinaKombija)
	{	
		super(modelVozila, registracijaVozila);
		this.visinaKombija = visinaKombija;
		this.duzinaKombija = duzinaKombija;
	}

	public String toString() 
	{
		return String.format("%s\nKombi je visok %.2f metara i dug %.2f metara.", 
				super.toString(), this.visinaKombija, this.duzinaKombija); 
	}

	// metode za postavljanje i dohvaæanje podatkovnih èlanova
	public double getVisinaKombija() { return this.visinaKombija; }
	public void setVisinaKombija(double visinaKombija) { this.visinaKombija = visinaKombija; }
	
	// metode koje propisuje suèelje su po defaultu apstraktne i ne moraju se navoditi u apstraktnom razredu
}

class PutnickiKombi extends Kombi
{
	private int brojPutnika;
	
	public PutnickiKombi (String modelVozila, String registracijaVozila, double visinaKombija,
			double duzinaKombija, int brojPutnika)
	{	
		super(modelVozila, registracijaVozila, visinaKombija, duzinaKombija);
		this.brojPutnika = brojPutnika;
	}

	public String toString() 
	{
		return String.format("%s\nPutnièki kombi može prevesti %d putnika.",
				super.toString(), this.brojPutnika); 
	}

	// metode za postavljanje i dohvaæanje podatkovnih èlanova
	public int getBrojPutnika() { return this.brojPutnika; }
	public void setBrojPutnika(int brojPutnika) { this.brojPutnika = brojPutnika; }

	// implementacija metoda koje propisuje suèelje
	public int dohvatiMaksimalanBrojPutnika() { return this.getBrojPutnika(); }
	public double dohvatiMaksimalnuNosivost() { return 0; } 
}

class TeretniKombi extends Kombi
{
	private double zapreminaPrtljaznogProstora;
	
	public TeretniKombi (String modelVozila, String registracijaVozila, double visinaKombija,
			double duzinaKombija, double zapreminaPrtljaznogProstora)
	{	
		super(modelVozila, registracijaVozila, visinaKombija, duzinaKombija);
		this.zapreminaPrtljaznogProstora = zapreminaPrtljaznogProstora;
	}

	public String toString() 
	{
		return String.format("%s\nTeretni kombi ima zapreminu prtljažnog prostora od %.2f litara.",
				super.toString(), this.zapreminaPrtljaznogProstora); 
	}

	// metode za postavljanje i dohvaæanje podatkovnih èlanova
	public double getZapreminaPrtljaznogProstora() { return this.zapreminaPrtljaznogProstora; }
	public void setZapreminaPrtljaznogProstora(double zapreminaPrtljaznogProstora) { this.zapreminaPrtljaznogProstora = zapreminaPrtljaznogProstora; }

	// implementacija metoda koje propisuje suèelje
	public int dohvatiMaksimalanBrojPutnika() { return 0; }
	public double dohvatiMaksimalnuNosivost() { return this.getZapreminaPrtljaznogProstora() / 0.00375; } 
}

class TeretnoVozilo extends CestovnoVozilo
{
	private int brojOsovina;
	private double maksimalnaNosivost; 

	public TeretnoVozilo (String modelVozila, String registracijaVozila, int brojOsovina, 
			double maksimalnaNosivost)
	{	
		super(modelVozila, registracijaVozila);
		this.brojOsovina = brojOsovina;
		this.maksimalnaNosivost = maksimalnaNosivost;
	}

	public String toString() 
	{
		return String.format("%s\nTeretno vozilo ime %d osovina i maksimalnu nosivost od %.2f tona.", 
				super.toString(), this.brojOsovina, this.maksimalnaNosivost); 
	}

	// metode za postavljanje i dohvaæanje podatkovnih èlanova
	public int getBrojOsovina() { return this.brojOsovina; }
	public void setBrojOsovina(int brojOsovina) { this.brojOsovina = brojOsovina; }
	public double getMaksimalnaNosivost() { return this.maksimalnaNosivost; }
	public void setMaksimalnaNosivost(double maksimalnaNosivost) { this.maksimalnaNosivost = maksimalnaNosivost; }

	// implementacija metoda koje propisuje suèelje
	public int dohvatiMaksimalanBrojPutnika() { return 0; }
	public double dohvatiMaksimalnuNosivost() { return this.getMaksimalnaNosivost(); } 
}

public class Zadatak2 
{
	public static void main(String [] args)
	{
		Vozilo [] mojaVozila = new Vozilo[10];
		Random slucajanIzbor = new Random();
		
		for(int i = 0; i < 10; i++)
		{
			// instancirati se mogu razredi OsobnoVozilo, TeretnoVozilo, PutnickiKombi i TeretniKombi
			int izbor = slucajanIzbor.nextInt(4);
			
			switch(izbor)
			{
				case 0:
				{
					System.out.println((i + 1) + ". vozilo je osobno vozilo.");
					mojaVozila[i] = new OsobnoVozilo("Model_" + (i + 1), "ABC-" + (i + 1), 
							"Tip_" + (i + 1), slucajanIzbor.nextInt(3) + 2, 
							slucajanIzbor.nextDouble() * 3000 + 2000);
					break;
				}
				case 1:
				{
					System.out.println((i + 1) + ". vozilo je teretno vozilo.");
					mojaVozila[i] = new TeretnoVozilo("Model_" + (i + 1), "ABC-" + (i + 1), 
							slucajanIzbor.nextInt(3) + 2, slucajanIzbor.nextDouble() * 8 + 2);
					break;
				}
				case 2:
				{
					System.out.println((i + 1) + ". vozilo je putnièki kombi.");
					mojaVozila[i] = new PutnickiKombi("Model_" + (i + 1), "ABC-" + (i + 1), 
							slucajanIzbor.nextDouble() * 1.5 + 2, 
							slucajanIzbor.nextDouble() * 3 + 3, slucajanIzbor.nextInt(2) + 2); 
					break;
				}
				case 3:
				{
					System.out.println((i + 1) + ". vozilo je teretni kombi.");
					mojaVozila[i] = new TeretniKombi("Model_" + (i + 1), "ABC-" + (i + 1), 
							slucajanIzbor.nextDouble() * 1.5 + 2, slucajanIzbor.nextDouble() * 3 + 3, 
							slucajanIzbor.nextDouble() * 10000 + 10000); 
					break;
				}				
			}
		}
		
		System.out.println("\n\nVozila pogodna za prijevoz putnika su:");
		for(int i = 0; i < 10; i++)
		{
			if(mojaVozila[i].dohvatiMaksimalanBrojPutnika() != 0)
				System.out.println(mojaVozila[i] + "\n----------");
		}
		
		System.out.println("\nVozila pogodna za prijevoz tereta su:");
		for(int i = 0; i < 10; i++)
		{
			if(mojaVozila[i].dohvatiMaksimalnuNosivost() != 0)
				System.out.println(mojaVozila[i] + "\n----------");
		}
	}
}
