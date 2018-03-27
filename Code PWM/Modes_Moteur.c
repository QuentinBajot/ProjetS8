#include "msp430.h"

void Moteur_IN1(void){
    P2DIR |= BIT0;
	P2SEL |= (BIT0);
	P2SEL2 &= ~(BIT0);
}
void Moteur_IN2(void){
    //Gestion du pont
    P2OUT |= (BIT1);
    //Sens de rotation IN1
    P2OUT &= ~(BIT0);
    P2OUT |= (BIT2);
}

void vitesse_1(void){

	TA1CCR1=15000;
}

void vitesse_2(void){

	TA1CCR1=10000;
}

void vitesse_3(void){

	TA1CCR1=0;
}

void vitesse_0(void){

	TA1CCR1=20000;
}
