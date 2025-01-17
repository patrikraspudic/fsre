package Primjer_07;

class OsnovniRazred
{
	// podatkovni clanovi osnovnog razreda
	public int pcPublicInt;
	public double pcPublicDouble;
	public String pcPublicString;
	protected int pcProtectedInt;
	private double pcPrivateDouble;
	
	// konstruktori
	public OsnovniRazred()
	{
		System.out.println("Izvodi se konstuktor osnovnog razreda bez parametara.");
	}
	
	public OsnovniRazred(int pcPublicInt, double pcPublicDouble, String pcPublicString,
			int pcProtectedInt, double pcPrivateDouble)
	{
		this.pcPublicInt = pcPublicInt;
		this.pcPublicDouble = pcPublicDouble;
		this.pcPublicString = pcPublicString;
		this.pcProtectedInt = pcProtectedInt;
		this.pcPrivateDouble = pcPrivateDouble;
		System.out.println("Izvodi se konstuktor osnovnog razreda s pet parametara.");
	}

	public OsnovniRazred(int pcPublicInt, double pcPublicDouble, double pcPrivateDouble)
	{
		this.pcPublicInt = pcPublicInt;
		this.pcPublicDouble = pcPublicDouble;
		this.pcPrivateDouble = pcPrivateDouble;
		System.out.println("Izvodi se konstuktor osnovnog razreda s tri parametra.");
	}

	public void metodaOsnovnogRazreda()
	{
		System.out.println("Izvodi se metoda osnovnog razreda.");
	}

	public void nekaDrugaMetoda(int nekiParametar)
	{
		System.out.println("Izvodi se neka druga metoda osnovnog razreda.");
	}

}

class IzvedeniRazred extends OsnovniRazred
{
	// podatkovni èlanovi izvedenog razreda
	public int pcPublicInt_IR;
	public double pcPublicDouble_IR;
	private double pcPrivateDouble_IR;
	
	// konstruktori
	public IzvedeniRazred()
	{
		System.out.println("Izvodi se konstuktor izvedenog razreda bez parametara.");
	}

	public IzvedeniRazred(int pcPublicInt_IR, double pcPublicDouble_IR, 
			double pcPrivateDouble_IR)
	{
		super(pcPublicInt_IR, pcPublicDouble_IR, pcPrivateDouble_IR);
		this.pcPublicInt_IR = pcPublicInt_IR;
		this.pcPublicDouble_IR = pcPublicDouble_IR;
		this.pcPrivateDouble_IR = pcPrivateDouble_IR;
		System.out.println("Izvodi se konstuktor izvedenog razreda sa tri parametra.");
	}
	
	public void metodaIzvedenogRazreda()
	{
		System.out.println("Izvodi se metoda izvedenog razreda.");
		super.metodaOsnovnogRazreda();
		super.pcPublicString = "Pozdrav";
		super.pcProtectedInt = 123456;
		// super.pcPrivateDouble = 123.456;		nije moguæ pristup privatnim èlanovima osnovnog razreda
	}
	
	public void nekaDrugaMetoda()
	{
		System.out.println("Izvodi se neka druga metoda osnovnog razreda bez parametara.");
	}
	
	public void nekaDrugaMetoda(int nekiParametar)
	{
		System.out.println("Izvodi se neka druga metoda osnovnog razreda s jednim parametrom.");
	}
}

public class Primjer_07 
{
	public static void main(String [] args)
	{
		OsnovniRazred OR1 = new OsnovniRazred();
		OsnovniRazred OR2 = new OsnovniRazred(10, 3.14, "Utorak", 100, -3.14);
		OsnovniRazred OR3 = new OsnovniRazred(45, 123.45, 321.215); 
		System.out.println("----------");
		
		IzvedeniRazred IR1 = new IzvedeniRazred();
		IzvedeniRazred IR2 = new IzvedeniRazred(123, 214.65, 222.22);
		System.out.println("----------");
		
		OR1.metodaOsnovnogRazreda();
		System.out.println("----------");
		
		IR1.metodaOsnovnogRazreda();
		System.out.println("----------");
		
		IR2.metodaIzvedenogRazreda();
		System.out.println("----------");

		// IR2.metodaIzvedenogRazreda(); 	osnovni razred ne može pristupiti èlanovima izvedenog razreda

		IR1.nekaDrugaMetoda(123);
		System.out.println("----------");
		
		IR1.nekaDrugaMetoda();
		System.out.println("----------");	
	}
}
