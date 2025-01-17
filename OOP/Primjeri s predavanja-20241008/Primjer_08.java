package Primjer_08;

class OsnovniRazred
{
	// podatkovni clanovi osnovnog razreda 
	public int pcPublicInt;
	public double pcPublicDouble;
	public String pcPublicString;
	protected int pcProtectedInt;
	private double pcPrivateDouble;
	
	// konstruktor 
	public OsnovniRazred()
	{
		System.out.println("Izvodi se konstruktor osnovnog razreda bez parametara!");	
	}
	
	public OsnovniRazred(int pcPublicInt, double pcPublicDouble, String pcPublicString, 
			int pcProtectedInt, double pcPrivateDouble)
	{
		this.pcPublicInt = pcPublicInt;
		this.pcPublicDouble = pcPublicDouble;
		this.pcPublicString = pcPublicString;
		this.pcProtectedInt = pcProtectedInt;
		this.pcPrivateDouble = pcPrivateDouble;
		System.out.println("Izvodi se konstruktor osnovnog razreda s pet parametara!");	
	}

	public OsnovniRazred(int pcPublicInt, double pcPublicDouble, double pcPrivateDouble)
	{
		this.pcPublicInt = pcPublicInt;
		this.pcPublicDouble = pcPublicDouble;
		this.pcPrivateDouble = pcPrivateDouble;
		System.out.println("Izvodi se konstruktor osnovnog razreda s tri parametara!");	
	}
	
	
	public void metodaOsnovnogRazreda()
	{
		System.out.println("Izvodi se metoda osnovnog razreda!");
	}
}

// nasljeðivanje
class IzvedeniRazred extends OsnovniRazred 
{
	// podatkovni clanovi izvedenog razreda 
	public int pcPublicInt_IR;
	public double pcPublicDouble_IR;
	private double pcPrivateDouble_IR;
	
	// konstruktor
	public IzvedeniRazred()
	{
		System.out.println("Izvodi se konstruktor izvedenog razreda bez parametara!");
	}

	public IzvedeniRazred(int pcPublicInt_IR, double pcPublicDouble_IR, double pcPrivateDouble_IR)
	{
		super(pcPublicInt_IR, pcPublicDouble_IR, pcPrivateDouble_IR);
		this.pcPublicInt_IR = pcPublicInt_IR;
		this.pcPublicDouble_IR = pcPublicDouble_IR;
		this.pcPrivateDouble_IR = pcPrivateDouble_IR;
		System.out.println("Izvodi se konstruktor izvedenog razreda s tri parametra!");		
	}
	
	public void metodaIzvedenogRazreda()
	{

		System.out.println("Izvodi se metoda izvedenog razreda!");
		super.metodaOsnovnogRazreda();
		super.pcPublicString = "Pozdrav";
	}	
}



public class Primjer_08 
{
	public static void main(String [] args)
	{
		OsnovniRazred OR1 = new OsnovniRazred();
		OsnovniRazred OR2 = new OsnovniRazred(10, 3.14, "Utorak", 100, -3.14);
		System.out.println("--------------------");
		IzvedeniRazred IR1 = new IzvedeniRazred(123, 1.23, 3.21);
		System.out.println("--------------------");
		IzvedeniRazred IR2 = new IzvedeniRazred();
		System.out.println("--------------------");
		OR1.metodaOsnovnogRazreda();
		System.out.println("--------------------");
//		OR1.metodaIzvedenogRazreda(); // ne može!
		IR1.metodaIzvedenogRazreda();
		System.out.println(IR1.pcPublicString);
		System.out.println("--------------------");
		IR2.metodaOsnovnogRazreda();
		System.out.println("--------------------");
		
	}
	
}
