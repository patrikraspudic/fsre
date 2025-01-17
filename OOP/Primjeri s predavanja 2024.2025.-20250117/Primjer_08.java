package Primjer_08;

class MicrosoftOffice
{
	public String nazivDokumenta;
	public boolean otvoren;
	public static int brojacDokumenata = 0;
	
	// konstruktori
	public MicrosoftOffice()
	{
		brojacDokumenata++;
		this.nazivDokumenta = "No Name " + brojacDokumenata;
		this.otvoren = false;
		System.out.println("Stvaram dokument " + this.nazivDokumenta + ".");		
	}

	public MicrosoftOffice(String nazivDokumenta)
	{
		brojacDokumenata++;
		this.nazivDokumenta = nazivDokumenta;
		this.otvoren = false;
		System.out.println("Stvaram dokument " + this.nazivDokumenta + ".");		
	}

	public static int brojStvorenihDokumenata()
	{
		return brojacDokumenata;
	}
	
	final public void otvoriDokument()
	{
		this.otvoren = true;
	}

	public void zatvoriDokument()
	{
		this.otvoren = false;
	}	

	public void ispisiDokument()
	{
		System.out.println("Ispisujem dokument " + this.nazivDokumenta + 
				" Microsoft Officea na podrazumijevanom pisaèu.");
	}
	
	public String toString()
	{
		if (this.otvoren)
			return "Dokument Microsoft Officea " + this.nazivDokumenta + " je otvoren.";
		else
			return "Dokument Microsoft Officea " + this.nazivDokumenta + " je zatvoren.";
	}
}

class MicrosoftWord extends MicrosoftOffice
{
	public String jezikDokumenta;
	
	//konstruktori
	public MicrosoftWord()
	{
		// implicitno se poziva konstruktor osnovnog razreda bez parametara
		this.nazivDokumenta += ".docx";
		System.out.println("Dodajem ekstenziju .docx nazivu dokumenta " + 
				this.nazivDokumenta + ".");
		this.jezikDokumenta = "bez provjere";
	}

	public MicrosoftWord(String nazivDokumenta, String jezikDokumenta)
	{
		super(nazivDokumenta);
		this.nazivDokumenta += ".docx";
		System.out.println("Dodajem ekstenziju .docx nazivu dokumenta " + 
				this.nazivDokumenta + ".");
		this.jezikDokumenta = jezikDokumenta;
	}

//  ne možemo nadjaæati final metodu osnovnog razreda	
//	public void otvoriDokument()
//	{
//		this.otvoren = true;
//	}

	public void ispisiDokument(String pisac)
	{
		System.out.println("Ispisujem dokument " + this.nazivDokumenta + 
				" Microsoft Worda na " + pisac + " pisaèu.");
	}	
	public String toString()
	{
		return super.toString() + "\nJezik dokumenta je " + this.jezikDokumenta + ".";
	}
}

class MicrosoftExcel extends MicrosoftOffice
{
	public String mjeraDokumenta;
	
	//konstruktori
	public MicrosoftExcel()
	{
		// implicitno se poziva konstruktor osnovnog razreda bez parametara
		this.nazivDokumenta += ".xslx";
		System.out.println("Dodajem ekstenziju .xslx nazivu dokumenta " + 
				this.nazivDokumenta + ".");
		this.mjeraDokumenta = "bez provjere";
	}

	public MicrosoftExcel(String nazivDokumenta, String mjeraDokumenta)
	{
		super(nazivDokumenta);
		this.nazivDokumenta += ".xslx";
		System.out.println("Dodajem ekstenziju .xslx nazivu dokumenta " + 
				this.nazivDokumenta + ".");
		this.mjeraDokumenta = mjeraDokumenta;
	}

	public void ispisiDokument(String pisac)
	{
		System.out.println("Ispisujem proraèunsku tablicu " + this.nazivDokumenta + 
				" Microsoft Excela na " + pisac + " pisaèu.");
	}	
	public String toString()
	{
		return super.toString() + "\nMjera dokumenta je " + this.mjeraDokumenta + ".";
	}
}

class RTFDokument extends MicrosoftWord
{
	// konstruktori
	public RTFDokument()
	{
		this.nazivDokumenta = this.nazivDokumenta.substring(0,
				this.nazivDokumenta.length() - 5) + ".rtf";
		System.out.println("Mijenjam ekstenziju u .rtf u nazivu RTF dokumenta " +
			this.nazivDokumenta + ".");
		this.jezikDokumenta = "bez provjere";
	}
}

public class Primjer_08 
{
	public static void main(String [] args)
	{
		MicrosoftOffice MO1 = new MicrosoftOffice();
		System.out.println(MO1);
		System.out.println("----------");

		MicrosoftOffice MO2 = new MicrosoftOffice("Moj dokument.off");
		System.out.println(MO2);
		System.out.println("----------");
		
		System.out.println("Trenutno postoji " + MicrosoftOffice.brojStvorenihDokumenata()
				+ " stvorenih dokumenata.");
		
		MO2.otvoriDokument();
		System.out.println(MO2);
		MO2.ispisiDokument();
		System.out.println("----------");
		
		MicrosoftWord MW1 = new MicrosoftWord();
		MW1.otvoriDokument();
		System.out.println(MW1);
		System.out.println("----------");

		MicrosoftWord MW2 = new MicrosoftWord("Moj Word dokument", "hrvatski");
		System.out.println(MW2);
		MW2.ispisiDokument("EPSON 123");
		System.out.println("----------");

		MicrosoftExcel ME1 = new MicrosoftExcel();
		ME1.otvoriDokument();
		System.out.println(ME1);
		System.out.println("----------");

		MicrosoftExcel ME2 = new MicrosoftExcel("Moj Excel dokument", "metrièka");
		System.out.println(ME2);
		ME2.ispisiDokument("Fujitsu 321");
		System.out.println("----------");
				
		RTFDokument RTF1 = new RTFDokument();
		System.out.println(RTF1);
		RTF1.ispisiDokument();
		System.out.println("----------");
		
		MicrosoftOffice [] Docs = new MicrosoftOffice[5];
		Docs[0] = new MicrosoftOffice("Dokument u nizu 1");
		Docs[1] = new MicrosoftWord("Dokument u nizu 2", "hrvatski");
		Docs[2] = new MicrosoftExcel("Dokument u nizu 3", "metrièka");
		Docs[3] = new RTFDokument();
		Docs[4] = new MicrosoftOffice();
		
		for(int i = 0; i < Docs.length; i++)
			System.out.println(Docs[i]);
	}
}
