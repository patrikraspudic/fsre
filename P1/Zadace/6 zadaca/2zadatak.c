/*Patrik Raspudic 2233/rr*/
/*Napisati program koji unosi cijele brojeve sve dok se ne unese prost broj, u funkciji
najmanji() pronalazi najmanji, a u funkciji najveci() najveći uneseni broj, a zatim u funkciji
svi_slozeni() ispisuje sve složene prirodne brojeve između najmanjeg i najvećeg unesenog
broja.
*/

#include <stdio.h>

void najmanji(int brojevi[100], int i, int *najmanji_broj); 
void najveci(int brojevi[100], int i, int *najveci_broj); 
void svi_slozeni(int brojevi[100], int i, int najmanji_broj, int najveci_broj);

int main ()
    {
        int brojevi[100], i=0,bool,najmanji_broj,najveci_broj;
        do
        {
            bool=1;
            scanf("%d", &brojevi[i]);
            if (brojevi[i]<2)
            {
                bool=0;
            }
            else
            {
                for (int j=2;j<brojevi[i];j++)
                {
                    if(brojevi[i]%j==0)
                    {
                        bool=0;
                        break;
                    } 
                }
            }
            i++;
            
        } while (bool!=1);

        najmanji(brojevi,i,&najmanji_broj);
        najveci(brojevi,i,&najveci_broj);
        svi_slozeni(brojevi,i,najmanji_broj,najveci_broj);

        return 0;
    }

    void najmanji(int brojevi[100], int i, int *najmanji_broj)
        {
            *najmanji_broj=brojevi[0]; 
            for(int j=1; j<i;j++)
                {
                    if(brojevi[j]<*najmanji_broj)
                        {
                        *najmanji_broj=brojevi[j];
                        }
                }
        }

    void najveci(int brojevi[100], int i, int *najveci_broj)
        {
            *najveci_broj=brojevi[0]; 
            for(int j=1; j<i;j++)
                {
                    if(brojevi[j]>*najveci_broj)
                       {
                        *najveci_broj=brojevi[j];
                        }
                }
        }

    void svi_slozeni(int brojevi[100], int i, int najmanji_broj, int najveci_broj)
    {
        int prost;
        for (int j=0;j<i;j++)
        {
            if(brojevi[j]>najmanji_broj&&brojevi[j]<najveci_broj)
            {
                prost = 1;
                if (brojevi[j]<2)
                {
                    prost=0;
                }
                else
                {
                    for (int k=2;k<brojevi[j];k++)
                    {
                        if(brojevi[j]%k==0)
                        {
                        prost=0;
                        break;
                    } 
                }
                }   

                if(!prost)
                {
                    printf("%d ", brojevi[j]);   
                } 
            }
        }
    }