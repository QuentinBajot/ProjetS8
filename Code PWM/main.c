#include <msp430.h> 

#include "Modes_Moteur.h"

/*-----Variables globales----*/

	unsigned int mode=0,rap_cycle=1500,vit=0,i=0;

int main(void) {

	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	BCSCTL1= CALBC1_1MHZ; //frequence d’horloge 1MHz
	DCOCTL= CALDCO_1MHZ; // "
/*-----directions entrée sortie-----*/

	P2DIR|= BIT1;
/* ------fonctionnement des  ports------*/
    //port1
    P1SEL &= ~(BIT3);
    P1SEL2 &= ~(BIT3);
    P1DIR &= ~(BIT3);
    //port2
    P2DIR |= BIT0|BIT2;
	P2SEL |= (BIT0|BIT2);
	P2SEL2 &= ~(BIT0|BIT2);
	P2SEL &= ~(BIT1);
	P2SEL2 &= ~(BIT1);


	//résistance de tirage pour le bouton
	P1REN |= BIT3;
	P1OUT |= BIT3;

/*--------Timer-----*/
	TA1CTL = 0|(TASSEL_2 | ID_0); //source SMCLK, predivision 8
	TA1CTL |= MC_1; //comptage en mode up
	TA1CCTL1 |= OUTMOD_7; // activation mode de sortie n°7
	TA1CTL |= TAIE; //autorisation interruption TAIE
	TA1CCR0 = 20000; //voir texte
	TA1CCR1 = rap_cycle; // determine le rapport cyclique du signal

/*------Interruption---
	P1IES |= (BIT3);
	P1IFG &= ~(BIT3);
	P1IE |= (BIT3);*/
for(i=0;i<=20000;i=i+100)
{
    TA1CCR1=i;
    __delay_cycles(1000000);

}
}

/*#pragma vector=PORT1_VECTOR
 __interrupt void Port_1(void)
 {
	 if (vit==0)
			 {
				 vit=1;
			 }

	 else if (vit==1)
			{
				 vit=2;
			}

	 else if (vit==2)
				 {
					vit=3;
				 }

	 else if (vit==3)
				 {
					vit=0;
				 }
	 P1IFG &= ~(BIT3);
 }

#pragma vector=TIMER0_A1_VECTOR
__interrupt void ma_fnc_timer(void)
{

	TA1CTL &= ~TAIFG; //RAZ TAIFG
}*/
