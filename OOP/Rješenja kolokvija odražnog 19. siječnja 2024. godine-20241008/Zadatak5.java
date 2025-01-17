package K1_Z5;

// u zadatku se nije tražio unos elemenata matrice ali æemo ga ovdje realizirati 
// kako bi bolje prikazali funkcionalnosti razreda
import java.util.Scanner;

class Matrica
{
	private int brojRedaka;
	private int brojStupaca;
	private int [][] M;
	
	public Matrica(int brojRedaka, int brojStupaca)
	{
		this.brojRedaka = brojRedaka;
		this.brojStupaca = brojStupaca;
		this.M = new int[this.brojRedaka][this.brojStupaca];
	}
	
	// u zadatku se nije tražio unos elemenata matrice ali æemo ga ovdje realizirati 
	// kako bi bolje prikazali funkcionalnosti razreda
	public void UnesiElementeMatrice()
	{
		Scanner ulaz = new Scanner(System.in);
		
		System.out.println("Unesi elemente matrice dimenzije "+ this.brojRedaka + " x " + this.brojStupaca + ":");
		for(int i = 0; i < this.brojRedaka; i++)
			for(int j = 0; j < this.brojStupaca; j++)
				M[i][j] = ulaz.nextInt();
	}
	
	public static Matrica zbroji(Matrica M1, Matrica M2)
	{
		if((M1.brojRedaka != M2.brojRedaka) || (M1.brojStupaca != M2.brojStupaca)) 
			return null;
		else
		{
			Matrica rezultat = new Matrica(M1.brojRedaka, M1.brojStupaca);
			
			for(int i = 0; i < M1.brojRedaka; i++)
				for(int j = 0; j < M1.brojStupaca; j++)
					rezultat.M[i][j] = M1.M[i][j] + M2.M[i][j];
			return rezultat;
		}
	}
	

	public static Matrica pomnozi(Matrica M1, Matrica M2)
	{
		if(M1.brojStupaca != M2.brojRedaka) 
			return null;
		else
		{
			Matrica rezultat = new Matrica(M1.brojRedaka, M2.brojStupaca);
			for(int i = 0; i < M1.brojRedaka; i++)
				for(int j = 0; j < M2.brojStupaca; j++)
				{
					rezultat.M[i][j] = 0;
					for(int k = 0; k < M1.brojStupaca; k++)
						rezultat.M[i][j] += M1.M[i][k] * M2.M[k][j];
				}
			return rezultat;
		}
	}

	
	public String toString()
	{
		String rezultat = "";
		
		for(int i = 0; i < this.brojRedaka; i++)
		{	
			for(int j = 0; j < this.brojStupaca; j++)
				rezultat += String.format("%5s", M[i][j]);
			rezultat += "\n";
		}
		
		return rezultat;
	}
}

public class Zadatak5 
{
	public static void main(String [] args)
	{
		Matrica M1 = new Matrica(3, 4);
		M1.UnesiElementeMatrice();
		System.out.println("Matrica M1:\n" + M1);

		Matrica M2 = new Matrica(3, 3);
		M2.UnesiElementeMatrice();
		System.out.println("Matrica M2:\n" + M2);

		Matrica M3 = new Matrica(3, 4);
		M3.UnesiElementeMatrice();
		System.out.println("Matrica M3:\n" + M2);
		
		Matrica M4 = Matrica.zbroji(M1, M2);
		if (M4 != null)
			System.out.println("Matrica M4 = M1 + M2:\n" + M3);
		else
			System.out.println("Matrice M1 i M2 se ne mogu zbrojiti!\n");

		Matrica M5 = Matrica.zbroji(M1, M3);
		if (M5 != null)
			System.out.println("Matrica M5 = M1 + M3:\n" + M5);
		else
			System.out.println("Matrice M1 i M3 se ne mogu zbrojiti!\n");
		
		Matrica M6 = Matrica.pomnozi(M1, M2);
		if (M6 != null)
			System.out.println("Matrica M6 = M1 * M2:\n" + M6);
		else
			System.out.println("Matrice M1 i M2 se ne mogu pomnoziti!\n");

		Matrica M7 = Matrica.pomnozi(M2, M1);
		if (M7 != null)
			System.out.println("Matrica M7 = M2 * M1:\n" + M7);
		else
			System.out.println("Matrice M2 i M1 se ne mogu pomnoziti!\n");

	}
	
}
