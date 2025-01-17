package Primjer_06;

class Tocka2D
{
	private String ime;
	private double xKoordinata;
	private double yKoordinata;
	
	// konstruktor
	public Tocka2D()
	{
		this.ime = "O";
		this.xKoordinata = this.yKoordinata = 0;
	}

	public Tocka2D(String ime, double xKoordinata, double yKoordinata)
	{
		this.ime = ime;
		this.xKoordinata = xKoordinata;
		this.yKoordinata = yKoordinata;
	}	
	
	public Tocka2D(Tocka2D T)
	{
		this.ime = T.ime + "C";
		this.xKoordinata = T.xKoordinata;
		this.yKoordinata = T.yKoordinata;
	}	
	
	// pristupnici za dohvaæanje privatnih èlanova
	// xKoordinata i yKoordinata
	public double dohvatiXKoordinatu()
	{
		return this.xKoordinata;
	}
	
	public double dohvatiYKoordinatu()
	{
		return this.yKoordinata;
	}	
	
	// pristupnici za postavljanje privatnih èlanova
	// xKoordinata i yKoordinata
	public void postaviXKoordinatu(double xKoordinata)
	{
		this.xKoordinata = xKoordinata;
	}
	
	public void postaviYKoordinatu(double yKoordinata)
	{
		this.yKoordinata = yKoordinata;
	}
	
	public void translatiraj(Vektor2D V)
	{
		this.xKoordinata += V.dohvatiXKoordinatu();
		this.yKoordinata += V.dohvatiYKoordinatu();
	}
	
	public double udaljenost(Tocka2D T)
	{
		return Math.sqrt(Math.pow(T.xKoordinata - this.xKoordinata, 2) + 
				Math.pow(T.yKoordinata - this.yKoordinata, 2));
	}
	
	public static double udaljenost(Tocka2D T1, Tocka2D T2)
	{
		return Math.sqrt(Math.pow(T2.xKoordinata - T1.xKoordinata, 2) + 
				Math.pow(T2.yKoordinata - T1.yKoordinata, 2));
	}	

	public static Tocka2D poloviste(Tocka2D T1, Tocka2D T2)
	{
		Tocka2D P = new Tocka2D(T1.ime + "p" + T2.ime, (T2.xKoordinata + T1.xKoordinata) / 2, 
				(T2.yKoordinata + T1.yKoordinata) / 2);
		return P;
	}	
	
	
	public String toString()
	{
		return this.ime + "(" + this.xKoordinata + ", " + this.yKoordinata + ")";
	}
}

class Vektor2D
{
	private String ime;
	private double xKoordinata;
	private double yKoordinata;
	
	// konstruktori
	public Vektor2D()
	{
		this.ime = "i";
		this.xKoordinata = 1;
		this.yKoordinata = 0;
	}
	
	public Vektor2D(String ime, double xKoordinata, double yKoordinata)
	{
		this.ime = ime;
		this.xKoordinata = xKoordinata;
		this.yKoordinata = yKoordinata;
	}	

	public Vektor2D(Vektor2D V)
	{
		this.ime = V.ime + "C";
		this.xKoordinata = V.xKoordinata;
		this.yKoordinata = V.yKoordinata;
	}		

	// pristupnici za dohvaæanje privatnih èlanova
	// xKoordinata i yKoordinata
	public double dohvatiXKoordinatu()
	{
		return this.xKoordinata;
	}
	
	public double dohvatiYKoordinatu()
	{
		return this.yKoordinata;
	}		
	
	public String toString()
	{
		String rezultat = "";
		if (this.yKoordinata >= 0) 
			rezultat += this.ime + " = " + this.xKoordinata + " * i + " + this.yKoordinata + " * j";
		else
			rezultat += this.ime + " = " + this.xKoordinata + " * i - " + Math.abs(yKoordinata) + " * j";
		return rezultat;
	}
}

class Pravokutnik2D
{
	private String ime;
	private Tocka2D DLK;
	private double sirina;
	private double visina;
	
	// konstruktori
	public Pravokutnik2D()
	{
		this.ime = "K";
		this.DLK = new Tocka2D();
		this.sirina = this.visina = 1;
	}

	public Pravokutnik2D(String ime, Tocka2D T, double sirina, double visina)
	{
		this.ime = ime;
		this.DLK = new Tocka2D(T);
		this.sirina = sirina;
		this.visina = visina;
	}
	
	public Pravokutnik2D(Pravokutnik2D P)
	{
		this.ime = P.ime + "C";
		this.DLK = new Tocka2D(P.DLK);
		this.sirina = P.sirina;
		this.visina = P.visina;
	}	
	
	public String toString()
	{
		String rezultat = "";
		rezultat += "Pravokutnik " + this.ime + " èiji je donji lijevi kut u toèki ";
		rezultat += this.DLK.toString();
		rezultat += " ima širinu " + this.sirina + " i visinu " + this.visina + ".";
		return rezultat;
		
	}
}


public class Primjer_06 
{
	public static void main(String [] args)
	{
		Tocka2D T1 = new Tocka2D();
		Tocka2D T2 = new Tocka2D("A", 3.8, -1.4);
		Tocka2D T3 = new Tocka2D("B", 3, 4);
		Tocka2D T4 = new Tocka2D(T2);
		
		System.out.println(T1);
		System.out.println(T2);
		System.out.println(T3);
		System.out.println(T4);
		
		System.out.println("Udaljenost od " + T1 + " do " + T3 + " je " + 
				T1.udaljenost(T3) + ".");

		System.out.println("Udaljenost od " + T3 + " do " + T4 + " je " + 
				Tocka2D.udaljenost(T3, T4) + ".");
	
		Tocka2D T5 = Tocka2D.poloviste(T1, T3);
		System.out.println(T5);
		System.out.println("----------");
		
		Vektor2D V1 = new Vektor2D();
		Vektor2D V2 = new Vektor2D("k", 5, -4);
		Vektor2D V3 = new Vektor2D("l", -3.5, 2.6);
		Vektor2D V4 = new Vektor2D(V2);
		
		System.out.println(V1);
		System.out.println(V2);
		System.out.println(V3);
		System.out.println(V4);
		System.out.println("----------");
		
		System.out.print("Translacijom toèke " + T3 + " za vektor " + V2 + 
				" dobije se toèka ");
		T3.translatiraj(V2);
		System.out.println(T3);
		System.out.println("----------");

		Pravokutnik2D P1 = new Pravokutnik2D();
		Pravokutnik2D P2 = new Pravokutnik2D("PR1", new Tocka2D("X", 3, 2), 5.3, 4.8);
		Pravokutnik2D P3 = new Pravokutnik2D(P2);
		
		System.out.println(P1);
		System.out.println(P2);
		System.out.println(P3);
	}
}
