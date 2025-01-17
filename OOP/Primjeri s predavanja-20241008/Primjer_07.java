package Primjer_07;

class Tocka2D
{
	private String ime;
	private double xKoordinata;
	private double yKoordinata;
	
	// konstruktori
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
		this.ime = T.ime + "c";
		this.xKoordinata = T.xKoordinata;
		this.yKoordinata = T.yKoordinata;
	}	
	
	
	// pristupnici za dohvatanje privatnih podatkovnih èlanova
	// xKoordinata i yKoordinata
	public double dohvatiXKoordinatu()
	{
		return this.xKoordinata;
	}

	public double dohvatiYKoordinatu()
	{
		return this.yKoordinata;
	}		
		
	// pristupnici za postavljanje privatnih podatkovnih èlanova
	// xKoordinata i yKoordinata
	public void postaviXKoordinatu(double delta)
	{
		this.xKoordinata += delta;
	}

	public void postaviYKoordinatu(double delta)
	{
		this.yKoordinata += delta;
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
		Tocka2D P = new Tocka2D(T1.ime + "p"+ T2.ime, (T1.xKoordinata + T2.xKoordinata) / 2 ,
				(T1.yKoordinata + T2.yKoordinata) / 2);
		return P;
	}
	
	public String toString()
	{
		return this.ime + "("+ this.xKoordinata + ", " + this.yKoordinata + ")";
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
	
	public Vektor2D(Vektor2D T)
	{
		this.ime = T.ime + "c";
		this.xKoordinata = T.xKoordinata;
		this.yKoordinata = T.yKoordinata;
	}	
	
	// pristupnici za dohvaæanje privatnih podatkovnih èlanova
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
		return this.ime + " = "+ this.xKoordinata + " * i + " + this.yKoordinata + " * j";
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
		this.ime = P.ime + "c"; 
		this.DLK = new Tocka2D(P.DLK);
		this.sirina = P.sirina;
		this.visina = P.visina;
	}	
	
	// ostale metode
	public void translatiraj(Vektor2D V)
	{
		this.DLK.postaviXKoordinatu(V.dohvatiXKoordinatu());
		this.DLK.postaviYKoordinatu(V.dohvatiYKoordinatu());
	}
	
	public static Pravokutnik2D presjek(Pravokutnik2D P1, Pravokutnik2D P2)
	{
		Pravokutnik2D rezultat = null;
		double presjekXKoordinata = 0, presjekYKoordinata = 0, presjekSirina = 0, presjekVisina = 0;
		
		if(P1.DLK.dohvatiXKoordinatu() <= P2.DLK.dohvatiXKoordinatu())
		{
			if(P1.DLK.dohvatiXKoordinatu() + P1.sirina < P2.DLK.dohvatiXKoordinatu())
			{
				// nema presjeka
				rezultat = new Pravokutnik2D("N", new Tocka2D(), 0, 0);
			}
			else
			{
				presjekXKoordinata = P2.DLK.dohvatiXKoordinatu();
				presjekSirina = P1.sirina - (P2.DLK.dohvatiXKoordinatu() - P1.DLK.dohvatiXKoordinatu());
			}
		}
		else
		{
			if(P2.DLK.dohvatiXKoordinatu() + P2.sirina < P1.DLK.dohvatiXKoordinatu())
			{
				// nema presjeka
				rezultat = new Pravokutnik2D("N", new Tocka2D(), 0, 0);
			}
			else
			{
				presjekXKoordinata = P1.DLK.dohvatiXKoordinatu();
				presjekSirina = P2.sirina - (P1.DLK.dohvatiXKoordinatu() - P2.DLK.dohvatiXKoordinatu());
			}
		}

		if(P1.DLK.dohvatiYKoordinatu() <= P2.DLK.dohvatiYKoordinatu())
		{
			if(P1.DLK.dohvatiYKoordinatu() + P1.visina < P2.DLK.dohvatiYKoordinatu())
			{
				// nema presjeka
				rezultat = new Pravokutnik2D("N", new Tocka2D(), 0, 0);
			}
			else
			{
				presjekYKoordinata = P2.DLK.dohvatiYKoordinatu();
				presjekVisina = P1.visina - (P2.DLK.dohvatiYKoordinatu() - P1.DLK.dohvatiYKoordinatu());
			}
		}
		else
		{
			if(P2.DLK.dohvatiYKoordinatu() + P2.visina < P1.DLK.dohvatiYKoordinatu())
			{
				// nema presjeka
				rezultat = new Pravokutnik2D("N", new Tocka2D(), 0, 0);
			}
			else
			{
				presjekYKoordinata = P1.DLK.dohvatiYKoordinatu();
				presjekVisina = P2.visina - (P1.DLK.dohvatiYKoordinatu() - P2.DLK.dohvatiYKoordinatu());
			}
		}		
		
		if(rezultat == null)
		{
			Tocka2D nDLK = new Tocka2D("P-DLK", presjekXKoordinata, presjekYKoordinata);
			rezultat = new Pravokutnik2D(P1.ime + "p" + P2.ime, nDLK, presjekSirina, presjekVisina);
		}
		
		return rezultat;
	}
	
	// preoptereæenje metode toString()
	public String toString()
	{
		String rezultat = "";
		rezultat += "Pravokutnik " + this.ime + " èiji je donji lijevi kut u toèki ";
		rezultat += this.DLK.toString();
		rezultat += " ima sirinu " + this.sirina + " i visinu " + this.visina + ".";
		return rezultat;
	}
}


public class Primjer_07 
{
	public static void main(String [] args)
	{
		Tocka2D O = new Tocka2D();
		System.out.println(O);
		
		Tocka2D A = new Tocka2D("A", 2.45, 3.11);
		System.out.println(A);
		
		Tocka2D B = new Tocka2D(A);
		System.out.println(B);

		Vektor2D i = new Vektor2D();
		System.out.println(i);
		
		Vektor2D a = new Vektor2D("a", 7.14, 0.23);
		System.out.println(a);
		
		Vektor2D b = new Vektor2D(a);
		System.out.println(b);		
		
		B.translatiraj(a);
		System.out.println(B);

		System.out.println("Udaljenost od O do A je " + O.udaljenost(A));
		System.out.println("Udaljenost od A do B je " + Tocka2D.udaljenost(A, B));
		
		Tocka2D P = Tocka2D.poloviste(A, B);
		System.out.println(P);
		
		Pravokutnik2D PR1 = new Pravokutnik2D();
		System.out.println(PR1);
		
		Pravokutnik2D PR2 = new Pravokutnik2D("J", A, 4.22, 3.26);
		System.out.println(PR2);
		
		Pravokutnik2D PR3 = new Pravokutnik2D(PR2);
		System.out.println(PR3);
		
		PR3.translatiraj(b);
		System.out.println(PR3);
		System.out.println("------------------------------");
		
		Pravokutnik2D PRx1 = new Pravokutnik2D("P1", new Tocka2D("P", 1, 3), 4, 3);
		Pravokutnik2D PRx2 = new Pravokutnik2D("P2", new Tocka2D("Q", -1, 2), 4, 2);
		
		System.out.println(PRx1);
		System.out.println(PRx2);		
		
		Pravokutnik2D PRx3 = Pravokutnik2D.presjek(PRx1, PRx2);
		System.out.println(PRx3);

		System.out.println("------------------------------");
		
		Pravokutnik2D PRx4 = new Pravokutnik2D("P3", new Tocka2D("R", 0, 0), 5, 5);
		Pravokutnik2D PRx5 = new Pravokutnik2D("P4", new Tocka2D("S", 10, 10), 3, 3);
		
		System.out.println(PRx4);
		System.out.println(PRx5);		
		
		Pravokutnik2D PRx6 = Pravokutnik2D.presjek(PRx4, PRx5);
		System.out.println(PRx6);
		
		
		
	}
}
