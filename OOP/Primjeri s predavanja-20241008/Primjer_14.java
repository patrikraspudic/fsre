package Primjer_14;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Primjer_14 
{
	public static void main(String [] args)
	{
		// okvir windows aplikacije
		JFrame jf_okvir = new JFrame();
		
		// labele
		JLabel jl_prviBroj = new JLabel();
		JLabel jl_drugiBroj = new JLabel();
		JLabel jl_operacija = new JLabel();
		JLabel jl_rezultat = new JLabel();
		
		// dugme
		JButton jb_izracunaj = new JButton("Izraèunaj");
		
		// tekstualni okviri
		JTextField jt_prviBroj = new JTextField();
		JTextField jt_drugiBroj = new JTextField();
		JTextField jt_rezultat = new JTextField();
		
		// padajuæi izbornik
		String [] operacije = {"zbrojanje", "oduzimanje", "množenje", "djeljenje"};
		JComboBox jcb_operacija = new JComboBox(operacije);
			
		jf_okvir.setSize(600, 500);
		jf_okvir.setTitle("Jednostavni kalkulator");
		
		jl_prviBroj.setBounds(50, 50, 200, 50);
		jl_prviBroj.setText("Prvi broj:");
		jl_prviBroj.setVisible(true);
		jf_okvir.add(jl_prviBroj);

		jl_drugiBroj.setBounds(50, 130, 200, 50);
		jl_drugiBroj.setText("Drugi broj:");
		jl_drugiBroj.setVisible(true);
		jf_okvir.add(jl_drugiBroj);
		
		jl_operacija.setBounds(50, 210, 200, 50);
		jl_operacija.setText("Operacija:");
		jl_operacija.setVisible(true);
		jf_okvir.add(jl_operacija);
		
		jl_rezultat.setBounds(50, 370, 200, 50);
		jl_rezultat.setText("Rezultat:");
		jl_rezultat.setVisible(true);
		jf_okvir.add(jl_rezultat);		

		jt_prviBroj.setBounds(350, 50, 200, 50);
		jf_okvir.add(jt_prviBroj);
		
		jt_drugiBroj.setBounds(350, 130, 200, 50);
		jf_okvir.add(jt_drugiBroj);
		
		jt_rezultat.setBounds(350, 370, 200, 50);
		jf_okvir.add(jt_rezultat);
		
		jcb_operacija.setBounds(350, 210, 200, 50);
		jf_okvir.add(jcb_operacija);
		
		jb_izracunaj.setBounds(50, 290, 200, 50);
		jf_okvir.add(jb_izracunaj);
		
		jb_izracunaj.addActionListener(new ActionListener()
								{
									public void actionPerformed(ActionEvent e)
									{
										int prviBroj = Integer.valueOf(jt_prviBroj.getText());
										int drugiBroj = Integer.valueOf(jt_drugiBroj.getText());
										double rezultat = 0;
										if (jcb_operacija.getSelectedIndex() == 0)
											rezultat = prviBroj + drugiBroj;
										if (jcb_operacija.getSelectedIndex() == 1)
											rezultat = prviBroj - drugiBroj;
										if (jcb_operacija.getSelectedIndex() == 2)
											rezultat = prviBroj * drugiBroj;
										if (jcb_operacija.getSelectedIndex() == 3)
											rezultat = prviBroj / drugiBroj;
										jt_rezultat.setText(String.valueOf(rezultat));
									}
								});
	
		jf_okvir.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		jf_okvir.setLayout(null);
		jf_okvir.setVisible(true);
	}
}
