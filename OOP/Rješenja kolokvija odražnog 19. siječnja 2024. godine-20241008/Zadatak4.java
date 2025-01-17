package K1_Z4;

import java.util.Scanner;
import java.util.ArrayList;

class GeometrijskiLik
{
	private int BrojStranica;
	private ArrayList<Double> Stranice = new ArrayList<>();
	
	public GeometrijskiLik(int BrojStranica)
	{
		this.BrojStranica = BrojStranica;
		UcitajStranice();
	}
	
	private void UcitajStranice()
	{
		Scanner ulaz = new Scanner(System.in);
		System.out.println("Unesi duljine " + this.BrojStranica + " stranica: ");
		for(int i = 0; i < this.BrojStranica; i++)
			this.Stranice.add(ulaz.nextDouble());
	}
	
	private double Opseg()
	{
		double opseg = 0;
		for(int i = 0; i < this.BrojStranica; i++)
			opseg += Stranice.get(i);
		return opseg;
	}
	
	public String toString()
	{
		String rezultat = "";
		rezultat += "Geometrijski lik ima " + this.BrojStranica + " stranica, duljina ";
		for(int i = 0; i < this.BrojStranica - 1; i++)
			rezultat += this.Stranice.get(i) + ", ";
		rezultat += this.Stranice.get(this.BrojStranica - 1) + " i opseg " + Opseg();
		
		return rezultat;
	}
}

public class Zadatak4 
{
	public static void main(String [] args)
	{
		GeometrijskiLik G3 = new GeometrijskiLik(3);
		System.out.println(G3);
		
		GeometrijskiLik G4 = new GeometrijskiLik(4);
		System.out.println(G4);
		
		GeometrijskiLik G5 = new GeometrijskiLik(5);
		System.out.println(G5);
		
		GeometrijskiLik G6 = new GeometrijskiLik(6);
		System.out.println(G6);
		
		GeometrijskiLik G7 = new GeometrijskiLik(7);
		System.out.println(G7);		
	}
}
