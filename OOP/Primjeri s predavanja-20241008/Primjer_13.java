package Primjer_13;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Primjer_13 
{
	public static void main(String [] args)
	{
		JFrame jf = new JFrame();
		JLabel jl = new JLabel();
		JButton jb = new JButton("Klikni ovdje!");
		JTextField jt1, jt2;
		JTextArea jta = new JTextArea("Podruèje za upis teksta");
		JCheckBox jcb1 = new JCheckBox("Phyton");
		JCheckBox jcb2 = new JCheckBox("C++");
		JCheckBox jcb3 = new JCheckBox("Java", true);
		JRadioButton jrb1 = new JRadioButton("strojarstvo");
		JRadioButton jrb2 = new JRadioButton("raèunarstvo");
		JRadioButton jrb3 = new JRadioButton("elektrotehnika");
		ButtonGroup bg = new ButtonGroup();
		String [] drzave = {"Bosna i Hercegovina", "Hrvatska", "Srbija", "Crna Gora", "Makedonija" };
		JComboBox jcb = new JComboBox(drzave);
		JScrollBar jsb = new JScrollBar();
				
		jf.setSize(1000, 500);
		jf.setTitle("Naslov okvira");
		
		jl.setForeground(Color.BLUE);
		jl.setVisible(false);
		jl.setFont(new Font("Serif", Font.PLAIN, 14));
		jl.setBounds(300, 250, 100, 50);
		jf.add(jl);
		
		jb.setBounds(50, 100, 150, 30);
		jb.addActionListener(new ActionListener()
								{
									public void actionPerformed(ActionEvent e)
									{
										jl.setText("Grafika u Javi");
										jl.setVisible(true);
									}
								});
		jf.add(jb);
		
		jt1 = new JTextField("Prvo tekstualno polje");
		jt1.setBounds(200, 300, 200, 50);
		jt2 = new JTextField("Drugo tekstualno polje");
		jt2.setBounds(200, 400, 200, 50);
		jf.add(jt1);
		jf.add(jt2);
		
		jta.setBounds(10, 200, 150, 200);
		jf.add(jta);

		
		jcb1.setBounds(250, 10, 100, 30);
		jcb2.setBounds(250, 50, 100, 30);
		jcb3.setBounds(250, 90, 100, 30);
		jf.add(jcb1); jf.add(jcb2); jf.add(jcb3);

		bg.add(jrb1); bg.add(jrb2); bg.add(jrb3);
		jrb1.setBounds(250, 130, 100, 30);
		jrb2.setBounds(250, 170, 100, 30);
		jrb3.setBounds(250, 210, 100, 30);
		jf.add(jrb1); jf.add(jrb2); jf.add(jrb3);
		
		jcb.setBounds(500, 100, 200, 50);
		jf.add(jcb);
		
		jsb.setBounds(700, 50, 50, 400);
		jf.add(jsb);
		
		jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		jf.setLayout(null);
		jf.setVisible(true);
	}
}
