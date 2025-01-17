package Ispit_21_02_2023_2345;

import java.util.Random;

interface RangLista 
{
	void rangListaTurnira();
}

abstract class Sahist
{
	public String	imePrezimeSahista;
	public int majstorskiBodovi;
	public String [] osvojeniTurniri = new String[100];
	public int brojOsvojenihTurnira;
	public static String [] kategorija = {"bez kategorije", "majstorski kandidat", "majstor", "meðunarodni majstor", "velemajstor"};

	public void korigirajMajstorskeBodove(int n)
	{
		this.majstorskiBodovi += n;
	}
}

class Turnir implements RangLista
{	
	String nazivTurnira;
	String mjestoOdrzavanja; 
	int godinaOdrzavanja; 
	String kategorijaTurnira;
	Sahist [] prijavljeniSahisti = new Sahist[100];
	int brojSahista = 0;
	int [] Bodovi =  new int[100];
	Sahist pobjednikTurnira;
	
	public Turnir(String nazivTurnira, String mjestoOdrzavanja, int godinaOdrzavanja, String kategorijaTurnira)
	{
		this.nazivTurnira = nazivTurnira;
		this.mjestoOdrzavanja = mjestoOdrzavanja;
		this.godinaOdrzavanja = godinaOdrzavanja;
		this.kategorijaTurnira = kategorijaTurnira;
	}
	
	public void rangListaTurnira()
	{
		
	}
	
	public void simulirajTurnir()
	{
		Random slucaj = new Random();
		
		for(int i = 0; i < brojSahista; i++)
			for(int j = 0; j < brojSahista; j++)
				if(i != j)
				{
					int rezultat = slucaj.nextInt(3);
					switch (rezultat)
					{
						case 0:			// pobjeda i-tog šahista
						{
							int prethodniBodoviI = prijavljeniSahisti[i].majstorskiBodovi;
							prijavljeniSahisti[i].korigirajMajstorskeBodove(10);
							int naknadniBodoviI = prijavljeniSahisti[i].majstorskiBodovi;
							Bodovi[i] += 10;
							
							if((prethodniBodoviI / 100 != naknadniBodoviI / 100) && (naknadniBodoviI / 100 > 19) && (naknadniBodoviI / 100 < 24))
							{
								if(prijavljeniSahisti[i] instanceof BezKategorije)
									prijavljeniSahisti[i] = ((BezKategorije) prijavljeniSahisti[i]).napredak();
								else if (prijavljeniSahisti[i] instanceof MajstorskiKandidat)
									prijavljeniSahisti[i] = ((MajstorskiKandidat) prijavljeniSahisti[i]).napredak();
								else if (prijavljeniSahisti[i] instanceof Majstor)
									prijavljeniSahisti[i] = ((Majstor) prijavljeniSahisti[i]).napredak();
								else if (prijavljeniSahisti[i] instanceof MedjunarodniMajstor)
									prijavljeniSahisti[i] = ((MedjunarodniMajstor) prijavljeniSahisti[i]).napredak();
							}
							break;
						}
						case 1:			// remi
						{
							int prethodniBodoviI = prijavljeniSahisti[i].majstorskiBodovi;
							int prethodniBodoviJ = prijavljeniSahisti[j].majstorskiBodovi;
							prijavljeniSahisti[i].korigirajMajstorskeBodove(5);
							prijavljeniSahisti[j].korigirajMajstorskeBodove(5);
							int naknadniBodoviI = prijavljeniSahisti[i].majstorskiBodovi;
							int naknadniBodoviJ = prijavljeniSahisti[j].majstorskiBodovi;							
							Bodovi[i] += 5;
							Bodovi[j] += 5;

							if((prethodniBodoviI / 100 != naknadniBodoviI / 100) && (naknadniBodoviI / 100 > 19) && (naknadniBodoviI / 100 < 24))
							{
								if(prijavljeniSahisti[i] instanceof BezKategorije)
									prijavljeniSahisti[i] = ((BezKategorije) prijavljeniSahisti[i]).napredak();
								else if (prijavljeniSahisti[i] instanceof MajstorskiKandidat)
									prijavljeniSahisti[i] = ((MajstorskiKandidat) prijavljeniSahisti[i]).napredak();
								else if (prijavljeniSahisti[i] instanceof Majstor)
									prijavljeniSahisti[i] = ((Majstor) prijavljeniSahisti[i]).napredak();
								else if (prijavljeniSahisti[i] instanceof MedjunarodniMajstor)
									prijavljeniSahisti[i] = ((MedjunarodniMajstor) prijavljeniSahisti[i]).napredak();
							}
							if((prethodniBodoviJ / 100 != naknadniBodoviJ / 100) && (naknadniBodoviJ / 100 > 19) && (naknadniBodoviJ / 100 < 24))
							{
								if(prijavljeniSahisti[j] instanceof BezKategorije)
									prijavljeniSahisti[j] = ((BezKategorije) prijavljeniSahisti[j]).napredak();
								else if (prijavljeniSahisti[j] instanceof MajstorskiKandidat)
									prijavljeniSahisti[j] = ((MajstorskiKandidat) prijavljeniSahisti[j]).napredak();
								else if (prijavljeniSahisti[j] instanceof Majstor)
									prijavljeniSahisti[j] = ((Majstor) prijavljeniSahisti[j]).napredak();
								else if (prijavljeniSahisti[j] instanceof MedjunarodniMajstor)
									prijavljeniSahisti[j] = ((MedjunarodniMajstor) prijavljeniSahisti[j]).napredak();
							}							
							break;
						}						
						case 2:			// pobjeda j-tog šahista
						{
							int prethodniBodoviJ = prijavljeniSahisti[j].majstorskiBodovi;
							prijavljeniSahisti[j].korigirajMajstorskeBodove(10);
							int naknadniBodoviJ = prijavljeniSahisti[j].majstorskiBodovi;
							Bodovi[j] += 10;

							if((prethodniBodoviJ / 100 != naknadniBodoviJ / 100) && (naknadniBodoviJ / 100 > 19) && (naknadniBodoviJ / 100 < 24))
							{
								if(prijavljeniSahisti[j] instanceof BezKategorije)
									prijavljeniSahisti[j] = ((BezKategorije) prijavljeniSahisti[j]).napredak();
								else if (prijavljeniSahisti[j] instanceof MajstorskiKandidat)
									prijavljeniSahisti[j] = ((MajstorskiKandidat) prijavljeniSahisti[j]).napredak();
								else if (prijavljeniSahisti[j] instanceof Majstor)
									prijavljeniSahisti[j] = ((Majstor) prijavljeniSahisti[j]).napredak();
								else if (prijavljeniSahisti[j] instanceof MedjunarodniMajstor)
									prijavljeniSahisti[j] = ((MedjunarodniMajstor) prijavljeniSahisti[j]).napredak();
							}							

							break;
						}
					}
				}
		
		int maxBod = 0;
		int indexPobjednika = 0;
			
		System.out.println("Osvojeni bodovi");
		for(int i = 0; i < this.brojSahista; i++)
		{
			System.out.println(this.prijavljeniSahisti[i].imePrezimeSahista + " - " + this.Bodovi[i] + " bodova");
			if(this.Bodovi[i] > maxBod)
			{
				maxBod = this.Bodovi[i];
				indexPobjednika = i;
			}
		}
		
		this.pobjednikTurnira = this.prijavljeniSahisti[indexPobjednika];
		this.prijavljeniSahisti[indexPobjednika].osvojeniTurniri[this.prijavljeniSahisti[indexPobjednika].brojOsvojenihTurnira] = this.nazivTurnira + ", " + this.godinaOdrzavanja;
		this.prijavljeniSahisti[indexPobjednika].brojOsvojenihTurnira++;
		this.pobjednikTurnira = this.prijavljeniSahisti[indexPobjednika];
		System.out.println("Pobjednik turnira " + this.nazivTurnira + " " + this.godinaOdrzavanja + " je " + this.pobjednikTurnira.imePrezimeSahista + ".");
		System.out.println(this.prijavljeniSahisti[indexPobjednika]);
	}
	
	static String pobjednikTurnira()
	{
		return "";
	}
	
	public String toString()
	{
		String Izlaz = "Turnir: " + this.nazivTurnira + " održan je u " + this.mjestoOdrzavanja + " ";
		Izlaz +=  this.godinaOdrzavanja + "godine.\n";
		Izlaz += "Kategorija turnira bila je: " + this.kategorijaTurnira + ", a pobjedio je " + pobjednikTurnira();
		
		return Izlaz;
	}
}

class BezKategorije extends Sahist
{
	String kategorijaSahista;
	
	public BezKategorije(String imePrezimeSahista, int majstorskiBodovi)
	{
		this.imePrezimeSahista = imePrezimeSahista;
		this.majstorskiBodovi = majstorskiBodovi;
		this.kategorijaSahista = Sahist.kategorija[0];
		this.brojOsvojenihTurnira = 0;
	}
	
	public MajstorskiKandidat napredak()
	{
		MajstorskiKandidat visiRang = new MajstorskiKandidat(this.imePrezimeSahista, this.majstorskiBodovi);
		visiRang.brojOsvojenihTurnira = this.brojOsvojenihTurnira;
		for(int i = 0; i < this.brojOsvojenihTurnira; i++)
			visiRang.osvojeniTurniri[i] = this.osvojeniTurniri[i];
		System.out.println(this.imePrezimeSahista + ": Bez kategorije -> Majstorski kandidat");
		
		return visiRang;
	}	
	
	public String toString()
	{
		String Izlaz = this.imePrezimeSahista + ", " + this.kategorijaSahista + ", trenutno ima ";
		Izlaz += this.majstorskiBodovi + " majstorskih bodova.\n";
		if(this.brojOsvojenihTurnira != 0)
		{
			Izlaz += "Do sada osvojeni turniri:\n";
			for(int i = 0; i < this.brojOsvojenihTurnira; i++)
				Izlaz += this.osvojeniTurniri[i] + "\n";
		}
		else
			Izlaz += "Do sada nema osvojenih turnira.\n";
	
		return Izlaz;		
	}
}

class MajstorskiKandidat extends Sahist
{
	String kategorijaSahista;
	
	public MajstorskiKandidat(String imePrezimeSahista, int majstorskiBodovi)
	{
		this.imePrezimeSahista = imePrezimeSahista;
		this.majstorskiBodovi = majstorskiBodovi;
		this.kategorijaSahista = Sahist.kategorija[1];
		this.brojOsvojenihTurnira = 0;
	}
	
	public Majstor napredak()
	{
		Majstor visiRang = new Majstor(this.imePrezimeSahista, this.majstorskiBodovi);
		visiRang.brojOsvojenihTurnira = this.brojOsvojenihTurnira;
		for(int i = 0; i < this.brojOsvojenihTurnira; i++)
			visiRang.osvojeniTurniri[i] = this.osvojeniTurniri[i];
		System.out.println(this.imePrezimeSahista + ": Majstorski kandidat -> Majstor");
		
		return visiRang;
	}

	public String toString()
	{
		String Izlaz = this.imePrezimeSahista + ", " + this.kategorijaSahista + ", trenutno ima ";
		Izlaz += this.majstorskiBodovi + " majstorskih bodova.\n";
		if(this.brojOsvojenihTurnira != 0)
		{
			Izlaz += "Do sada osvojeni turniri:\n";
			for(int i = 0; i < this.brojOsvojenihTurnira; i++)
				Izlaz += this.osvojeniTurniri[i] + "\n";
		}
		else
			Izlaz += "Do sada nema osvojenih turnira.\n";
	
		return Izlaz;		
	}
}

class Majstor extends Sahist
{
	public String kategorijaSahista;
	
	public Majstor(String imePrezimeSahista, int majstorskiBodovi)
	{
		this.imePrezimeSahista = imePrezimeSahista;
		this.majstorskiBodovi = majstorskiBodovi;
		this.kategorijaSahista = Sahist.kategorija[2];
		this.brojOsvojenihTurnira = 0;
	}
	
	public MedjunarodniMajstor napredak()
	{
		MedjunarodniMajstor visiRang = new MedjunarodniMajstor(this.imePrezimeSahista, this.majstorskiBodovi);
		visiRang.brojOsvojenihTurnira = this.brojOsvojenihTurnira;
		for(int i = 0; i < this.brojOsvojenihTurnira; i++)
			visiRang.osvojeniTurniri[i] = this.osvojeniTurniri[i];
		System.out.println(this.imePrezimeSahista + ": Majstor -> Meðunarodni majstor");
		
		return visiRang;
	}
	
	public String toString()
	{
		String Izlaz = this.imePrezimeSahista + ", " + this.kategorijaSahista + ", trenutno ima ";
		Izlaz += this.majstorskiBodovi + " majstorskih bodova.\n";
		if(this.brojOsvojenihTurnira != 0)
		{
			Izlaz += "Do sada osvojeni turniri:\n";
			for(int i = 0; i < this.brojOsvojenihTurnira; i++)
				Izlaz += this.osvojeniTurniri[i] + "\n";
		}
		else
			Izlaz += "Do sada nema osvojenih turnira.\n";
	
		return Izlaz;		
	}
}

class MedjunarodniMajstor extends Sahist
{
	String kategorijaSahista;

	public MedjunarodniMajstor(String imePrezimeSahista, int majstorskiBodovi)
	{
		this.imePrezimeSahista = imePrezimeSahista;
		this.majstorskiBodovi = majstorskiBodovi;
		this.kategorijaSahista = Sahist.kategorija[3];
		this.brojOsvojenihTurnira = 0;
	}
	
	public Velemajstor napredak()
	{
		Velemajstor visiRang = new Velemajstor(this.imePrezimeSahista, this.majstorskiBodovi);
		visiRang.brojOsvojenihTurnira = this.brojOsvojenihTurnira;
		for(int i = 0; i < this.brojOsvojenihTurnira; i++)
			visiRang.osvojeniTurniri[i] = this.osvojeniTurniri[i];
		System.out.println(this.imePrezimeSahista + ": Meðunarodni majstor -> Velemajstor");
		
		return visiRang;
	}

	public String toString()
	{
		String Izlaz = this.imePrezimeSahista + ", " + this.kategorijaSahista + ", trenutno ima ";
		Izlaz += this.majstorskiBodovi + " majstorskih bodova.\n";
		if(this.brojOsvojenihTurnira != 0)
		{
			Izlaz += "Do sada osvojeni turniri:\n";
			for(int i = 0; i < this.brojOsvojenihTurnira; i++)
				Izlaz += this.osvojeniTurniri[i] + "\n";
		}
		else
			Izlaz += "Do sada nema osvojenih turnira.\n";
	
		return Izlaz;		
	}
}

class Velemajstor extends Sahist
{
	String kategorijaSahista;
	
	public Velemajstor(String imePrezimeSahista, int majstorskiBodovi)
	{
		this.imePrezimeSahista = imePrezimeSahista;
		this.majstorskiBodovi = majstorskiBodovi;
		this.kategorijaSahista = Sahist.kategorija[4];
		this.brojOsvojenihTurnira = 0;
	}
	
	public String toString()
	{
		String Izlaz = this.imePrezimeSahista + ", " + this.kategorijaSahista + ", trenutno ima ";
		Izlaz += this.majstorskiBodovi + " majstorskih bodova.\n";
		if(this.brojOsvojenihTurnira != 0)
		{
			Izlaz += "Do sada osvojeni turniri:\n";
			for(int i = 0; i < this.brojOsvojenihTurnira; i++)
				Izlaz += this.osvojeniTurniri[i] + "\n";
		}
		else
			Izlaz += "Do sada nema osvojenih turnira.\n";
	
		return Izlaz;		
	}
}

public class Ispit_21_02_2023_2345 
{
	public static void main(String [] args)
	{
		Random slucaj = new Random();
		
		Turnir T1 = new Turnir("Mostar Open", "Mostar", 2023, "Turnir bez kategorije");
		Turnir T2 = new Turnir("Split Open", "Split", 2023, "Turnir majstorskih kandidata");
		Turnir T3 = new Turnir("Zagreb Open", "Zagreb", 2023, "Turnir majstora");
		Turnir T4 = new Turnir("Sarajevo Open", "Sarajevo", 2023, "Turnir meðunarodnih majstora");
		Turnir T5 = new Turnir("New York Open", "New York", 2023, "Turnir velemajstora");
		
		Sahist [] S = new Sahist[100];
		
		for(int i = 0; i < 100; i++)
		{
			String mojeImePrezime = "Sahist_" + (i + 1);
			int mojiBodovi = slucaj.nextInt(501) + 1900;

			if(mojiBodovi < 2000)
			{
				S[i] = new BezKategorije(mojeImePrezime, mojiBodovi);
				T1.prijavljeniSahisti[T1.brojSahista] = S[i];
				T1.brojSahista++;
			}
			else if(mojiBodovi < 2100)
			{
				S[i] = new MajstorskiKandidat(mojeImePrezime, mojiBodovi);
				T2.prijavljeniSahisti[T2.brojSahista] = S[i];
				T2.brojSahista++;
			}
			else if(mojiBodovi < 2200)
			{
				S[i] = new Majstor(mojeImePrezime, mojiBodovi);
				T3.prijavljeniSahisti[T3.brojSahista] = S[i];
				T3.brojSahista++;
			}
			else if(mojiBodovi < 2300)
			{
				S[i] = new MedjunarodniMajstor(mojeImePrezime, mojiBodovi);
				T4.prijavljeniSahisti[T4.brojSahista] = S[i];
				T4.brojSahista++;
			}
			else
			{
				S[i] = new Velemajstor(mojeImePrezime, mojiBodovi);
				T5.prijavljeniSahisti[T5.brojSahista] = S[i];
				T5.brojSahista++;
			}
		}
	
		T1.simulirajTurnir();
		T2.simulirajTurnir();
		T3.simulirajTurnir();
		T4.simulirajTurnir();
		T5.simulirajTurnir();		
	}
}
