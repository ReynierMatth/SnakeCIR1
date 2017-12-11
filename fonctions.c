#include  <stdlib.h>		// Pour pouvoir utiliser void exit(int)
#include <math.h>		// Pour pouvoir utiliser les librairies mathematiques
#include "GfxLib.h"		// Seul cet include est necessaire pour faire du graphique
#include "ESLib.h"		// Inclusion classique
#include <stdio.h>
#include "fonctions.h"
#include <stdbool.h>


///*---------------------------DECLARATION--------------------------*///


int count, appuyeJ, appuyeN, appuyeQ, niveau, choixNiv,gameover;
int depl, corps, param, ABS, ORD, jeuEnCours,score;
Coord S, S2, A,obs, bord;


///*---------------------------DECLARATION--------------------------*///

/*-----------------------------FONCTIONS------------------------------*/
void iniSnake(Coord S, int corps){
	int i,a;
	a=0;
	for(i=0;i<20;i++){//bord haut
	bord[i][0]=450+a;
	bord[i][1]=517;
	a=a+25;}
	a=0;
	for(i=20;i<40;i++){//bord bas
	bord[i][0]=450+a;
	bord[i][1]=42;
	a=a+25;}
	a=0;
	for(i=40;i<58;i++){//bord gauche
	bord[i][0]=450;
	bord[i][1]=67+a;
	a=a+25;}
	a=0;
	for(i=58;i<76;i++){//bord droit
	bord[i][0]=925;
	bord[i][1]=67+a;
	a=a+25;}

	
	
	S[0][0]=677;
	S[0][1]=269;
	S[0][2]=699;
	S[0][3]=290;
	S[1][0]=701;
	S[1][1]=269;
	S[1][2]=724;
	S[1][3]=290;
	S[2][0]=726;
	S[2][1]=269;
	S[2][2]=748;
	S[2][3]=290;

	couleurCourante(0,0,0);	///Rectangle noir
	rectangle((S[0][0]-2),(S[0][1]-2),(S[2][2]+2),(S[2][3]+2));
	
	couleurCourante(24,57,30);
	rectangle(S[0][0],S[0][1],S[0][2],S[0][3]);

	couleurCourante(20,148,20);
	rectangle(S[1][0],S[1][1],S[1][2],S[1][3]);

	couleurCourante(96,244,10);
	rectangle(S[2][0],S[2][1],S[2][2],S[2][3]);
	

}

void calculSnake(Coord S, int corps){
	int i;

	couleurCourante(0,0,0);	///Rectangle noir
	rectangle((S[0][0]-2),(S[0][1]-2),(S[0][2]+2),(S[0][3]+2));
	couleurCourante(24,57,30);	///Tete
	rectangle(S[0][0],S[0][1],S[0][2],S[0][3]);
	
	
	for(i=1;i<corps;i++){
		couleurCourante(0,0,0);	///Rectangle noir
		rectangle((S[i][0]-2),(S[i][1]-2),(S[i][2]+2),(S[i][3]+2));
		if (i%2==0){
			couleurCourante(96,244,10);}
			else{
		couleurCourante(20,148,20);}
		rectangle(S[i][0],S[i][1],S[i][2],S[i][3]);
}

}

void iniObs(){
	obs[0][0]=500;//L à l'envers
		obs[0][1]=442;
		obs[1][0]=525;
		obs[1][1]=442;
		obs[2][0]=550;
		obs[2][1]=442;
		obs[3][0]=575;
		obs[3][1]=442;
		obs[4][0]=600;
		obs[4][1]=442;
		obs[5][0]=625;
		obs[5][1]=442;
		obs[6][0]=625;
		obs[6][1]=417;
		obs[7][0]=625;
		obs[7][1]=392;
		obs[8][0]=625;
		obs[8][1]=367;
		obs[9][0]=625;
		obs[9][1]=342;
		obs[10][0]=625;
		obs[10][1]=317; //L à l'envers
		obs[11][0]=550; // carre
		obs[11][1]=392;
		obs[12][0]=550;
		obs[12][1]=367;
		obs[13][0]=575;
		obs[13][1]=392;
		obs[14][0]=575;
		obs[14][1]=367;//carre
		obs[15][0]=500;//4 horizontale 
		obs[15][1]=242;
		obs[16][0]=525;
		obs[16][1]=242;
		obs[17][0]=550;
		obs[17][1]=242;
		obs[18][0]=575;
		obs[18][1]=242;// 4 horizontale
		obs[19][0]=525;//3 verticale
		obs[19][1]=167;
		obs[20][0]=525;
		obs[20][1]=142;
		obs[21][0]=525;
		obs[21][1]=117;//3 verticale
		obs[22][0]=700;//petit l penché
		obs[22][1]=417;
		obs[23][0]=700;
		obs[23][1]=392;
		obs[24][0]=725;
		obs[24][1]=392;
		obs[25][0]=750;
		obs[25][1]=392;// petit l penché
		obs[26][0]=825;//celui a coté
		obs[26][1]=392;
		obs[27][0]=825;
		obs[27][1]=367;
		obs[28][0]=850;
		obs[28][1]=367;//celui a coté
		obs[29][0]=850;//celui en dessous
		obs[29][1]=267;
		obs[30][0]=850;
		obs[30][1]=292;
		obs[31][0]=850;
		obs[31][1]=242;
		obs[32][0]=825;
		obs[32][1]=242;//celui en dessous
		obs[33][0]=850;//le 2 carré
		obs[33][1]=167;
		obs[34][0]=850;
		obs[34][1]=142;//le 2 carré
		obs[35][0]=750;//bébé l
		obs[35][1]=217;
		obs[36][0]=750;
		obs[36][1]=192;
		obs[37][0]=725;
		obs[37][1]=192;//bebe l
		obs[38][0]=650;//grand l du dessous
		obs[38][1]=142;
		obs[39][0]=650;
		obs[39][1]=117;
		obs[40][0]=675;
		obs[40][1]=117;
		obs[41][0]=700;
		obs[41][1]=117;
		obs[42][0]=725;
		obs[42][1]=117;
		obs[43][0]=750;
		obs[43][1]=117;//grand l du dessous
		obs[44][0]=850;//carré alone
		obs[44][1]=92;//carré alone
		obs[45][0]=750;//dif banc
		obs[45][1]=442;
		obs[46][0]=750;
		obs[46][1]=467;
		obs[47][0]=775;
		obs[47][1]=467;
		obs[48][0]=800;
		obs[48][1]=467;
		obs[49][0]=825;
		obs[49][1]=467;
		obs[50][0]=850;
		obs[50][1]=467;
		obs[51][0]=875;
		obs[51][1]=467;
		obs[52][0]=875;
		obs[52][1]=442;//dif banc
		obs[53][0]=675;//dif alone
		obs[53][1]=492;//dif alone
		obs[54][0]=475;//dif 2 gauche
		obs[54][1]=367;
		obs[55][0]=475;
		obs[55][1]=392;//dif 2 gauche
		obs[56][0]=500;//dif 4 gauche
		obs[56][1]=292;
		obs[57][0]=500;
		obs[57][1]=317;
		obs[58][0]=525;
		obs[58][1]=292;
		obs[59][0]=550;
		obs[59][1]=292;//dif 4 gauche
		obs[60][0]=725;//dif 4 droite
		obs[60][1]=317;
		obs[61][0]=750;
		obs[61][1]=317;
		obs[62][0]=775;
		obs[62][1]=317;
		obs[63][0]=775;
		obs[63][1]=342;//dif 4 droite
		obs[64][0]=625;//dif 3
		obs[64][1]=192;
		obs[65][0]=650;
		obs[65][1]=192;
		obs[66][0]=650;
		obs[66][1]=217;//dif 3
		obs[67][0]=575;//dif 4 bas
		obs[67][1]=92;
		obs[68][0]=600;
		obs[68][1]=92;
		obs[69][0]=600;
		obs[69][1]=117;
		obs[70][0]=600;
		obs[70][1]=142;//dif 4 bas
		obs[71][0]=800;//dif 1 bas
		obs[71][1]=67;//dif 1 bas
	}

void iniBoutons(){
			/*--------------------------*/
			
			couleurCourante(0,0,0);		//contour rectangle du bas
			rectangle(98,60,282,136);			
			
			couleurCourante(173,79,9);	//rectangle du bas
			rectangle(100,62,280,134);
			
			couleurCourante(255,255,255);			//Ecriture "Quitter"
			epaisseurDeTrait(3);
			afficheChaine("QUITTER", 35, 115, 82);
			
			/*--------------------------*/
			
			couleurCourante(0,0,0);		//contour rectangle du milieu
			rectangle(98,186,282,262);			
			
			couleurCourante(173,79,9);	//rectangle du milieu
			rectangle(100,188,280,260);
			
			couleurCourante(255,255,255);			//Ecriture "Niveau"
			epaisseurDeTrait(3);
			afficheChaine("NIVEAUX", 35, 115, 208);
			
			/*--------------------------*/
			
			couleurCourante(0,0,0);		//contour rectangle du haut
			rectangle(98,312,282,388);			
			
			couleurCourante(173,79,9);	//rectangle du haut
			rectangle(100,314,280,386);
			
			couleurCourante(255,255,255);			//Ecriture "Jouer"
			epaisseurDeTrait(3);
			afficheChaine("JOUER", 35, 130, 334);
			
			/*--------------------------*/
		
			
			couleurCourante(0,0,0);			//Contour Ecriture "Snake"
			epaisseurDeTrait(12);
			afficheChaine("SNAKE", 90, 40, 450);			
			
			/*--------------------------*/
			
			couleurCourante(255,255,255);	//Ecriture "Snake"
			epaisseurDeTrait(8);
			afficheChaine("SNAKE", 90, 40, 450);
			
			
			/*--------------------------*/
			
			couleurCourante(0,0,0);		//contour terrain
			rectangle(450,42,950,542);
			
			
			/*--------------------------*/			
			
			couleurCourante(169, 234, 254);		//terrain
			rectangle(475,67,925,517);	
			
			/*--------------------------*/			
			
			
			
		}

void iniBoutonsNiveaux(){
			/*---------------------------*/
			couleurCourante(0,0,0);		//contour rectangle facile
			rectangle(308,262,428,312);			
			
			couleurCourante(173,79,9);	//rectangle facile
			rectangle(310,264,426,310);
			
			couleurCourante(255,255,255);			//Ecriture "Facile"
			epaisseurDeTrait(2);
			afficheChaine("FACILE", 20, 325, 280);
			
			/*---------------------------*/
			couleurCourante(0,0,0);		//contour rectangle moyen
			rectangle(308,199,428,249);			
			
			couleurCourante(173,79,9);	//rectangle moyen
			rectangle(310,201,426,247);
			
			couleurCourante(255,255,255);			//Ecriture "Moyen"
			epaisseurDeTrait(2);
			afficheChaine("MOYEN", 20, 325, 215);
			
			/*---------------------------*/
			couleurCourante(0,0,0);		//contour rectangle difficile
			rectangle(308,136,428,186);			
			
			couleurCourante(173,79,9);	//rectangle difficile
			rectangle(310,138,426,184);
			
			couleurCourante(255,255,255);			//Ecriture "Difficile"
			epaisseurDeTrait(2);
			afficheChaine("DIFFICILE", 20, 325, 155);
		}
			
void iniJeuFacile(){
	afficheAliment(A);
	}
	
void iniJeuMoyen(){
	
	
	
	
	
	
	
	
	afficheAliment(A);
	
	
	couleurCourante(0,0,0);		///1
	rectangle(500,442,625,467);	///1
	couleurCourante(0,51,153);
	rectangle(502,444,623,465);
	
	couleurCourante(0,0,0);	
	rectangle(625,317,650,467);
	couleurCourante(0,51,153);
	rectangle(627,319,648,465);
	
		
	couleurCourante(0,0,0);	
	rectangle(550,367,600,417);	
	couleurCourante(0,51,153);	
	rectangle(552,369,598,415);
	
	couleurCourante(0,0,0);	
	rectangle(500,242,600,267);	
	couleurCourante(0,51,153);	
	rectangle(502,244,598,265);
	
	couleurCourante(0,0,0);	///5
	rectangle(525,117,550,192);	///5
	couleurCourante(0,51,153);	
	rectangle(527,119,548,190);	
	
	couleurCourante(0,0,0);	
	rectangle(700,392,725,442);	
	couleurCourante(0,51,153);	
	rectangle(702,394,723,440);	
	
	couleurCourante(0,0,0);	
	rectangle(725,392,775,417);	
	couleurCourante(0,51,153);	
	rectangle(727,394,773,415);
	
	couleurCourante(0,0,0);	
	rectangle(725,192,775,217);
	couleurCourante(0,51,153);	
	rectangle(727,194,773,215);	
		
	couleurCourante(0,0,0);	
	rectangle(750,217,775,242);
	couleurCourante(0,51,153);	
	rectangle(752,219,773,240);
	
	couleurCourante(0,0,0);	///10
	rectangle(650,117,675,167);	///10
	couleurCourante(0,51,153);	
	rectangle(652,119,673,165);
	
	couleurCourante(0,0,0);	
	rectangle(675,117,775,142);
	couleurCourante(0,51,153);	
	rectangle(677,119,773,140);	
	
	couleurCourante(0,0,0);	
	rectangle(850,142,875,192);
	couleurCourante(0,51,153);	
	rectangle(852,144,873,190);
	
	couleurCourante(0,0,0);
	rectangle(850,92,875,117);
	couleurCourante(0,51,153);
	rectangle(852,94,873,115);
	
	couleurCourante(0,0,0);
	rectangle(825,242,875,267);
	couleurCourante(0,51,153);
	rectangle(827,244,873,265);
	
	couleurCourante(0,0,0);	///15
	rectangle(850,267,875,317);	///15
	couleurCourante(0,51,153);	
	rectangle(852,269,873,315);
	
	couleurCourante(0,0,0);
	rectangle(825,367,850,417);
	couleurCourante(0,51,153);
	rectangle(827,369,848,415);
	
	couleurCourante(0,0,0);
	rectangle(850,367,875,392);
	couleurCourante(0,51,153);
	rectangle(852,369,873,390);
	
		
}

void iniJeuDifficile(){
	
	iniJeuMoyen();
	
	couleurCourante(0,0,0);
	rectangle(750,442,775,492);
	couleurCourante(0,51,153);
	rectangle(752,444,773,490);
	
	couleurCourante(0,0,0);
	rectangle(775,467,875,492);
	couleurCourante(0,51,153);
	rectangle(777,469,873,490);
	
	couleurCourante(0,0,0);	///20
	rectangle(875,442,900,492);	///20
	couleurCourante(0,51,153);
	rectangle(877,444,898,490);
	
	couleurCourante(0,0,0);	
	rectangle(725,317,775,342);
	couleurCourante(0,51,153);	
	rectangle(727,319,773,340);	
	
	couleurCourante(0,0,0);	
	rectangle(775,317,800,367);
	couleurCourante(0,51,153);	
	rectangle(777,319,798,365);
	
	couleurCourante(0,0,0);
	rectangle(500,292,525,342);
	couleurCourante(0,51,153);
	rectangle(502,294,523,340);
	
	couleurCourante(0,0,0);
	rectangle(525,292,575,317);
	couleurCourante(0,51,153);
	rectangle(527,294,573,315);
	
	couleurCourante(0,0,0);	///25
	rectangle(475,367,500,417);	///25
	couleurCourante(0,51,153);	
	rectangle(477,369,498,415);
	
	couleurCourante(0,0,0);	
	rectangle(625,192,675,217);
	couleurCourante(0,51,153);	
	rectangle(627,194,673,215);	
	
	couleurCourante(0,0,0);	
	rectangle(650,217,675,242);
	couleurCourante(0,51,153);	
	rectangle(652,219,673,240);
	
	couleurCourante(0,0,0);
	rectangle(575,92,625,117);
	couleurCourante(0,51,153);
	rectangle(577,94,623,115);
	
	couleurCourante(0,0,0);
	rectangle(600,117,625,167);
	couleurCourante(0,51,153);
	rectangle(602,119,623,165);
	
	couleurCourante(0,0,0);	///30
	rectangle(675,492,700,517);	///30
	couleurCourante(0,51,153);
	rectangle(677,494,698,515);
	
	couleurCourante(0,0,0);	
	rectangle(775,67,825,92);	
	couleurCourante(0,51,153);
	rectangle(777,69,823,90);
	
		
}

void alimentAlea (Coord A){

int i,j,x1,y1,x2,y2,x3,y3,a;
y3=0;
x3=0;

while ((y3>=518)||(x3>=926)||(y3<=66)||(x3<=474)){
i=(valeurIntervalleZeroUn()*450);
j=(valeurIntervalleZeroUn()*450);

x1=(int)(475+i);
x1=x1-(x1%25);

y1=(int)(j-17);
y1=y1-(y1%25);
y1=y1+17;


x2=x1+25;
y2=y1+25;

A[0][0]=x1;
A[0][1]=y1;
A[0][2]=x2;
A[0][3]=y2;

y3=y1;
x3=x1;
if ((choixNiv==0)||(choixNiv==2)){ //medium
for (a=0; a<=44; a++){
		if ((x3==obs[a][0])&&(y3==obs[a][1])){ //obstacle moyen
			y3=0;
			x3=0;
		}
	}
}
if (choixNiv==3){ //difficile
for (a=0; a<=71; a++){ //44 a changé
		if ((x3==obs[a][0])&&(y3==obs[a][1])){ //obstacle moyen
			y3=0;
			x3=0;
		}
	}
}
for (a=0; a<=corps; a++){
		if ((x3==(S[a][0])-2)&&(y3==(S[a][1]-2))){ //snake
			y3=0;
			x3=0;
		}
	}
	
	
}


}

void afficheAliment(Coord A){
	couleurCourante(0,0,0);		///1
	rectangle(A[0][0],A[0][1],A[0][2],A[0][3]);	///1
	couleurCourante(169,17,1);
	rectangle(A[0][0]+2,A[0][1]+2,A[0][2]-2,A[0][3]-2);

}

void deplacementHaut(Coord S, Coord S2, int corps){
	int i,j;
	
		S2[0][0]=S[0][0];
		S2[0][1]=S[0][1]+25;
		S2[0][2]=S[0][2];
		S2[0][3]=S[0][3]+25;
	for(i=1;i<corps;i++){
		S2[i][0]=S[i-1][0];
		S2[i][1]=S[i-1][1];
		S2[i][2]=S[i-1][2];
		S2[i][3]=S[i-1][3];
	}
		
	for (i=0;i<corps;i++){
		for (j=0;j<=3;j++){
			S[i][j]=S2[i][j];
		}
	}
	
	calculSnake(S,corps);
}		
	
void deplacementBas(Coord S, Coord S2, int corps){
	int i,j;

		S2[0][0]=S[0][0];
		S2[0][1]=S[0][1]-25;
		S2[0][2]=S[0][2];
		S2[0][3]=S[0][3]-25;
	
	for(i=1;i<corps;i++){
		S2[i][0]=S[i-1][0];
		S2[i][1]=S[i-1][1];
		S2[i][2]=S[i-1][2];
		S2[i][3]=S[i-1][3];
	}
	
		
	for (i=0;i<corps;i++){
		for (j=0;j<=3;j++){
			S[i][j]=S2[i][j];
		}
	}
	
	calculSnake(S,corps);	
	}

void deplacementGauche(Coord S, Coord S2, int corps){
	int i,j;
	
		S2[0][0]=S[0][0]-25;
		S2[0][1]=S[0][1];
		S2[0][2]=S[0][2]-25;
		S2[0][3]=S[0][3];
		
		for(i=1;i<corps;i++){
		S2[i][0]=S[i-1][0];
		S2[i][1]=S[i-1][1];
		S2[i][2]=S[i-1][2];
		S2[i][3]=S[i-1][3];	}
		
	for (i=0;i<corps;i++){
		for (j=0;j<=3;j++){
			S[i][j]=S2[i][j];
		}
	}
	
	calculSnake(S,corps);
	}
	
void deplacementDroite(Coord S, Coord S2, int corps){
	int i,j;

		S2[0][0]=S[0][0]+25;
		S2[0][1]=S[0][1];
		S2[0][2]=S[0][2]+25;
		S2[0][3]=S[0][3];
		
		for(i=1;i<corps;i++){
		S2[i][0]=S[i-1][0];
		S2[i][1]=S[i-1][1];
		S2[i][2]=S[i-1][2];
		S2[i][3]=S[i-1][3];
	}
		
	for (i=0;i<corps;i++){
		for (j=0;j<=3;j++){
			S[i][j]=S2[i][j];
		}
	}
	
	calculSnake(S,corps);
	}

void collision(Coord S, Coord obs, int corps){
	int i,a;
	if ((choixNiv==0)||(choixNiv==2))//medium
			{ 
			for (i=0;i<=44;i++){	//Obstacles
				if (((S[0][0]-2)==obs[i][0])&&((S[0][1]-2)==obs[i][1])){
					reinitJeu();
					couleurCourante(255,0,0);			//Ecriture "GAME OVER"
					epaisseurDeTrait(5);
					afficheChaine("GAME OVER", 55, 520, 267);
					gameover=1;
				}
			}
	}
	if ((choixNiv==3))//difficile
			{ 
			for (i=0;i<=71;i++){	//Obstacles (44 a changé)
				if (((S[0][0]-2)==obs[i][0])&&((S[0][1]-2)==obs[i][1])){
					reinitJeu();
					couleurCourante(255,0,0);			//Ecriture "GAME OVER"
					epaisseurDeTrait(5);
					afficheChaine("GAME OVER", 55, 520, 267);
					gameover=1;
				}
			}
	}
	for(a=1;a<=corps;a++){//Snake
		if (((S[0][0]-2)==(S[a][0]-2))&&((S[0][1]-2)==(S[a][1]-2))){
			reinitJeu();
			couleurCourante(255,0,0);			//Ecriture "GAME OVER"
			epaisseurDeTrait(5);
			afficheChaine("GAME OVER", 55, 520, 267);
			gameover=1;	
		}
	
	}
	
	for(a=0;a<76;a++){//bord
		if (((S[0][0]-2)==bord[a][0])&&((S[0][1]-2)==bord[a][1])){
			reinitJeu();
			couleurCourante(255,0,0);			//Ecriture "GAME OVER"
			epaisseurDeTrait(5);
			afficheChaine("GAME OVER", 55, 520, 267);	
			gameover=1;		
		}
	
	}
}

void reinitJeu(){
	int i;
	count=0; appuyeJ=0; appuyeQ=0; depl=5;jeuEnCours=0;
	appuyeN=0; niveau=0; param=0;   alimentAlea(A);
		
			effaceFenetre (231, 168, 84);
			
			iniBoutons();
	
	for (i=3;i<=corps;i++){
		S[i][0]=1600;
		S[i][1]=1600;
		S[i][2]=1600;
		S[i][3]=1600;
	}
	corps=3;
	
}
/*-----------------------------FONCTIONS------------------------------*/
