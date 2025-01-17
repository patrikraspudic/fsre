package Primjer_09;

class MicrosoftOffice
{
	public String nazivDokumenta;
	public boolean otvoren;
	public static int brojac = 0;
	
	// konstruktori
	public MicrosoftOffice()
	{
		brojac++;
		this.nazivDokumenta = "No Name " + brojac;
		this.otvoren = false;
		System.out.println("Stvaram dokument " + this.nazivDokumenta + ".");
	}

	public MicrosoftOffice(String nazivDokumenta)
	{
		brojac++;
		this.nazivDokumenta = nazivDokumenta;
		this.otvoren = false;
		System.out.println("Stvaram dokument " + this.nazivDokumenta + ".");
	}
	
	public static int brojStvorenihDokumenata()
	{
		return brojac;
	}
	
	final public void otvoriDokument()
	{
		this.otvoren = true;
	}

	final public void zatvoriDokument()
	{
		this.otvoren = false;
	}	
	
	public void ispisiDokument()
	{
		System.out.println("Ispisujem dokument " + this.nazivDokumenta + " Microsoft Officea "
				+ "na podrazumijevanom pisaèu.");
	}
	
	public String toString()
	{
		if (this.otvoren)
			return "Dokument Microsoft Officea " + this.nazivDokumenta + " je otvoren";
		else
			return "Dokument Microsoft Officea " + this.nazivDokumenta + " je zatvoren";
	}
}

class MicrosoftWord extends MicrosoftOffice
{
	public String jezikDokumenta;
	
	// konstruktori
	public MicrosoftWord()
	{
		// implicitno se poziva konstruktor osnovnog razreda bez parametara super()
		this.nazivDokumenta += ".docx";
		System.out.println("Dodajem ekstenziju .docx nazivu dokumenta " + this.nazivDokumenta + ".");
		this.jezikDokumenta = "bez provjere";
	}
	
	public MicrosoftWord(String nazivDokumenta, String jezikDokumenta)
	{
		super(nazivDokumenta);
		this.nazivDokumenta += ".docx";
		System.out.println("Dodajem ekstenziju .docx nazivu dokumenta " + this.nazivDokumenta + ".");
		this.jezikDokumenta = jezikDokumenta;
	}
	
	public void ispisiDokument(String pisac)
	{
		System.out.println("Ispisujem dokument " + this.nazivDokumenta + " Microsoft Worda "
				+ "na pisaèu " + pisac + ".");
	}	
	
	// ne možemo nadjaèati final metodu osnovnog razreda
	// public void otvoriDokument()
	// {
	//     this.otvoren = true;
	// }

	public String toString()
	{
		return super.toString() + "\nJezik dokumenta je " + this.jezikDokumenta + "."; 
	}
}

class MicrosoftExcel extends MicrosoftOffice
{
	public String mjeraDokumenta;
	
	// konstruktori
	public MicrosoftExcel()
	{
		// implicitno se poziva konstruktor osnovnog razreda bez parametara super()
		this.nazivDokumenta += ".xlsx";
		System.out.println("Dodajem ekstenziju .xlsx nazivu proraèunske tablice " + this.nazivDokumenta + ".");
		this.mjeraDokumenta = "bez provjere";
	}
	
	public MicrosoftExcel(String nazivDokumenta, String mjeraDokumenta)
	{
		super(nazivDokumenta);
		this.nazivDokumenta += ".xlsx";
		System.out.println("Dodajem ekstenziju .xlsx nazivu proraèunske tablice " + this.nazivDokumenta + ".");
		this.mjeraDokumenta = mjeraDokumenta;
	}
	
	public void ispisiDokument(String pisac)
	{
		System.out.println("Ispisujem proraèunsku tablicu " + this.nazivDokumenta + " Microsoft Excela "
				+ "na pisaèu " + pisac + ".");
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
		this.nazivDokumenta = this.nazivDokumenta.substring(0, this.nazivDokumenta.length() - 5)+ ".rtf";
		System.out.println("Mijenjam ekstenziju u .rtf nazivu RTF dokumenta " + this.nazivDokumenta + ".");
		this.jezikDokumenta = "bez provjere";
	}	
}

public class Primjer_09 
{
	public static void main(String [] args)
	{
		MicrosoftOffice MO1 = new MicrosoftOffice();
		System.out.println(MO1);
		System.out.println("----------");
		
		MicrosoftOffice MO2 = new MicrosoftOffice("Moj dokument.off");
		System.out.println(MO1);
		System.out.println("----------");
		
		System.out.println("Trenutno postoji " + MicrosoftOffice.brojStvorenihDokumenata() + 
				" stvorenih dokumenata.");
		
		System.out.println("----------");
		MO1.otvoriDokument();
		System.out.println(MO1);
		
		System.out.println("----------");
		MO1.zatvoriDokument();
		System.out.println(MO1);

		System.out.println("----------");
		MicrosoftWord MW1 = new MicrosoftWord();
		System.out.println(MW1);
		
		System.out.println("----------");
		MicrosoftWord MW2 = new MicrosoftWord("Moj word dokument", "hrvatski");
		System.out.println(MW2);

		System.out.println("----------");
		MO1.ispisiDokument();
		
		System.out.println("----------");
		MW1.ispisiDokument();
		MW1.ispisiDokument("EPSON A123");		
		
		System.out.println("----------");
		MicrosoftExcel ME1 = new MicrosoftExcel();
		System.out.println(ME1);
		
		System.out.println("----------");
		MicrosoftExcel ME2 = new MicrosoftExcel("Moj excel dokument", "metrièka");
		System.out.println(ME2);

		System.out.println("----------");
		ME2.ispisiDokument();
		ME2.ispisiDokument("EPSON A123");		
		
		RTFDokument RTF1 = new RTFDokument();
		
		System.out.println("----------");
		System.out.println(RTF1);

		System.out.println("----------");
		MicrosoftOffice [] Docs = new MicrosoftOffice [5];
		Docs[0] = new MicrosoftOffice("Dokument u nizu 1");
		Docs[1] = new MicrosoftWord("Dokument u nizu 2", "hrvatski");
		Docs[2] = new MicrosoftExcel("Dokument u nizu 3", "metrièka");
		Docs[3] = new RTFDokument();
		Docs[4] = new MicrosoftOffice();
		
		System.out.println("----------");
		for(int i = 0; i < 5; i++)
		{
			System.out.println(Docs[i]);
		}
	}
}
