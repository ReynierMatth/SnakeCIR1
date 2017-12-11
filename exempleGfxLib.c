#include  <stdlib.h>		// Pour pouvoir utiliser void exit(int)
#include <math.h>		// Pour pouvoir utiliser les librairies mathematiques
#include "GfxLib.h"		// Seul cet include est necessaire pour faire du graphique
#include "ESLib.h"		// Inclusion classique
#include <stdio.h>
#include <stdbool.h>
#include "fonctions.h"



///*---------------------------DECLARATION--------------------------*///


int count, appuyeJ, appuyeN, appuyeQ, niveau, choixNiv,gameover;
int depl, corps, param, ABS, ORD, jeuEnCours, score;
double t0;
Coord S, S2, A,obs, bord;


///*---------------------------DECLARATION--------------------------*/// 

int main(int argc, char **argv)
{

	initialiseGfx(argc, argv); 

	prepareFenetreGraphique("Snake :", LargeurFenetre, HauteurFenetre);
	
	lanceBoucleEvenements();

	ecrisChaine("Fin du main "); 
	return 0;
}


void gestionEvenement(EvenementGfx evenement)
{
	rafraichisFenetre();
	char p[256];
	switch (evenement) 
	{
		
		case Initialisation:
		gameover=0;
		count=0; appuyeJ=0; appuyeQ=0; choixNiv=0; jeuEnCours=0;
		appuyeN=0; niveau=0; param=0; depl=0; corps=3; iniObs(); alimentAlea(A);
		t0=tempsCPU();
		 
		
			break;
		
		case Affichage: 
			
			count++;		
			sautDeLigne();
			
			effaceFenetre (231, 168, 84);
			
			iniBoutons();	
			
/**------------------------------------------------------------------**/				
		
		if (appuyeJ==1){	//Bouton Jouer Appuye
			
			couleurCourante(255,255,255);		//contour rectangle du haut
			rectangle(98,312,282,388);			
			
			couleurCourante(0,0,0);	//rectangle du haut
			rectangle(100,314,280,386);
			
			couleurCourante(255,255,255);			//Ecriture "Jouer"
			epaisseurDeTrait(3);
			afficheChaine("JOUER", 35, 130, 334);
	
		
		
			
			}
				
		if (appuyeJ==2){	//Bouton Jouer Relache
			
			if ((choixNiv==0)||(choixNiv==2))
			{ 
				gameover=0;
				afficheAliment(A); 
				iniJeuMoyen();
				if(depl==0){
					iniSnake(S,corps); 
					afficheAliment(A);
				}
				
			}
			if (choixNiv==1){ 
				gameover=0;
				afficheAliment(A);
				iniJeuFacile();
				if(depl==0){ 
					iniSnake(S,corps); 
					afficheAliment(A);
				}
			
					
				}
			if (choixNiv==3){ 
				gameover=0;
				afficheAliment(A);
				iniJeuDifficile();
				if(depl==0){ 
					iniSnake(S,corps);
				    afficheAliment(A);
				}
			
				
				}
			
			jeuEnCours=1;
			
			}
						
		if (appuyeN==1){	//Bouton Niveau Appuye
			
			couleurCourante(255,255,255);		//contour rectangle du milieu
			rectangle(98,186,282,262);			
			
			couleurCourante(0,0,0);	//rectangle du milieu
			rectangle(100,188,280,260);
			
			couleurCourante(255,255,255);			//Ecriture "Niveau"
			epaisseurDeTrait(3);
			afficheChaine("NIVEAUX", 35, 115, 208);
			}
			
		if (niveau==1){		//Bouton Niveau Relache
			if(jeuEnCours==0){
			iniBoutonsNiveaux();}
		}
			
		if (param==1){		//Niveau Facile Appuye
			if(jeuEnCours==0){
			couleurCourante(255,255,255);		//contour rectangle facile
			rectangle(308,262,428,312);			
			
			couleurCourante(0,0,0);	//rectangle facile
			rectangle(310,264,426,310);
			
			couleurCourante(255,255,255);			//Ecriture "Facile"
			epaisseurDeTrait(2);
			afficheChaine("FACILE", 20, 325, 280);
		}
			
		}
		
		if (param==2){		//Niveau Moyen Appuye
			if(jeuEnCours==0){
			couleurCourante(255,255,255);		//contour rectangle moyen
			rectangle(308,199,428,249);			
			
			couleurCourante(0,0,0);	//rectangle moyen
			rectangle(310,201,426,247);
			
			couleurCourante(255,255,255);			//Ecriture "Moyen"
			epaisseurDeTrait(2);
			afficheChaine("MOYEN", 20, 325, 215);}

			
		}
		
		if (param==3){		//Niveau Difficile Appuye
			if(jeuEnCours==0){
			couleurCourante(255,255,255);		//contour rectangle difficile
			rectangle(308,136,428,186);			
			
			couleurCourante(0,0,0);	//rectangle difficile
			rectangle(310,138,426,184);
			
			couleurCourante(255,255,255);			//Ecriture "Difficile"
			epaisseurDeTrait(2);
			afficheChaine("DIFFICILE", 20, 325, 155);}
			
		}
								
		if (appuyeQ==1){	//Gauche Appuye bouton Quitter
			couleurCourante(255,255,255);		//contour rectangle du bas
			rectangle(98,60,282,136);			
			
			couleurCourante(0,0,0);	//rectangle du bas
			rectangle(100,62,280,134);
			
			couleurCourante(255,255,255);			//Ecriture "Quitter"
			epaisseurDeTrait(3);
			afficheChaine("QUITTER", 35, 115, 82);
			
			}
		if((tempsCPU()-t0)>0.15){
		if (depl==1){		//Deplacement Haut
		if (jeuEnCours==1){
		
			if(((S[0][0]-2)==A[0][0])&&((S[0][1]-2)==A[0][1])){
						corps++;
						score=score+10;
						calculSnake(S,corps);
						alimentAlea(A);
						afficheAliment(A);
						}
				deplacementHaut(S,S2,corps);
				collision(S,obs,corps);
				
			}}
	
		if (depl==2){		//Deplacement Bas
		if (jeuEnCours==1){
		if(((S[0][0]-2)==A[0][0])&&((S[0][1]-2)==A[0][1])){
					corps++;
					score=score+10;
					calculSnake(S,corps);
					alimentAlea(A);
					afficheAliment(A);
					}
					deplacementBas(S,S2,corps);
					collision(S,obs,corps);
					
					}}
	
		if (depl==3){		//Deplacement Gauche
		if (jeuEnCours==1){
		if(((S[0][0]-2)==A[0][0])&&((S[0][1]-2)==A[0][1])){
					corps++;
					score=score+10;
					calculSnake(S,corps);
					alimentAlea(A);
					afficheAliment(A);
					}					
					deplacementGauche(S,S2,corps);
					collision(S,obs,corps);
					
					}
				}
		
		if (depl==4){		//Deplacement Droite
				if (jeuEnCours==1){
					if(((S[0][0]-2)==A[0][0])&&((S[0][1]-2)==A[0][1])){
						corps++;
						score=score+10;
						calculSnake(S,corps);
						alimentAlea(A);
						afficheAliment(A);
					}
					deplacementDroite(S,S2,corps);
					collision(S,obs,corps);
								
				}
					
		}
		
		t0=tempsCPU();
	}
	
	if (jeuEnCours==1){
						calculSnake(S,corps);
						collision(S,obs,corps);
						}
	if (gameover==1){
			couleurCourante(255,0,0);			//Ecriture "GAME OVER"
			epaisseurDeTrait(5);
			afficheChaine("GAME OVER", 55, 520, 267);
		}
		
	
		sprintf(p,"Score : %d",score);
		couleurCourante(0,0,0);			
		epaisseurDeTrait(3);
		afficheChaine(p, 30, 550, 10);
		
			
/**------------------------------------------------------------------**/
			
			
			break;
		
		case Clavier:

			switch (caractereClavier())
			{
							
				case 'Z':
				case 'z':
				if (jeuEnCours==1){
					depl=1;
					rafraichisFenetre();
				}
					break;
					
				case 'S':
				case 's':
					if (jeuEnCours==1){
					depl=2;
					rafraichisFenetre();
				}
					break;
					
				case 'Q':
				case 'q':
				if (jeuEnCours==1){
					depl=3;
					rafraichisFenetre();
				}
					break;
					
				case 'D':
				case 'd':
				if (jeuEnCours==1){
					depl=4;
					rafraichisFenetre();
				}
					break;
			}
			break;
		
		case BoutonSouris: 
			if (etatBoutonSouris() == GaucheAppuye)
			{

				ABS=abscisseSouris();
				ORD=ordonneeSouris();
				if(jeuEnCours==0){
				if((ABS>98)&&(ABS<282)&&(ORD>312)&&(ORD<388)){			//Bouton Jouer Appuye
					appuyeJ=1;
					score=0;
					rafraichisFenetre();
					
				}
			}
					if(jeuEnCours==0){
				if((ABS>98)&&(ABS<282)&&(ORD>186)&&(ORD<266)){			//Bouton Niveau Appuye
					appuyeN=1;
					rafraichisFenetre();
										
					}
				}

				if((ABS>98)&&(ABS<282)&&(ORD>60)&&(ORD<136)){			//Bouton Quitter Appuye
					appuyeQ=1;
					rafraichisFenetre();
					
				}
				if(jeuEnCours==0){
				if(niveau==1){	//Bouton Niveau Relache
					if((ABS>308)&&(ABS<428)&&(ORD>262)&&(ORD<312)){		//Bouton Facile Appuye
						if(jeuEnCours==0){
						param=1;
						rafraichisFenetre();}
						
					}
					if((ABS>308)&&(ABS<428)&&(ORD>199)&&(ORD<249)){		//Bouton Moyen Appuye
						if(jeuEnCours==0){
						param=2;
						rafraichisFenetre();}
						
					}
					if((ABS>308)&&(ABS<428)&&(ORD>136)&&(ORD<186)){		//Bouton Difficile Appuye
						if(jeuEnCours==0){
						param=3;
						rafraichisFenetre();}
						
					}
				}
			}
				
			}
			else if (etatBoutonSouris() == GaucheRelache)
			{
				
				ABS=abscisseSouris();
				ORD=ordonneeSouris();
				if(jeuEnCours==0){
				if((ABS>98)&&(ABS<282)&&(ORD>312)&&(ORD<388)){			//Bouton Jouer Relache
						iniSnake(S,corps);
						appuyeJ=2;
						rafraichisFenetre();
					
				}
			}
			if(jeuEnCours==0){
				if((ABS>98)&&(ABS<282)&&(ORD>186)&&(ORD<266)){			//Bouton Niveau Relache
					appuyeN=0;
					niveau=1;
					rafraichisFenetre();
				}
			}

				if((ABS>98)&&(ABS<282)&&(ORD>60)&&(ORD<136)){			//Bouton Quitter Relache

						appuyeQ=0;
						rafraichisFenetre();
						exit(0);
					
				}
				if(jeuEnCours==0){
				if(niveau==1){	//Bouton Niveau Relache
					if((ABS>308)&&(ABS<428)&&(ORD>262)&&(ORD<312)){		//Bouton Facile Relache
						param=0;
						choixNiv=1;	//Choix Niveau Facile
						rafraichisFenetre();
					}
					
					if((ABS>308)&&(ABS<428)&&(ORD>199)&&(ORD<249)){		//Bouton Moyen Relache
						param=0;
						choixNiv=2;	//Choix Niveau Moyen
						rafraichisFenetre();
							
					}
					
					if((ABS>308)&&(ABS<428)&&(ORD>136)&&(ORD<186)){		//Bouton Difficile Relache
						param=0;
						choixNiv=3;	//Choix Niveau Difficile				
						rafraichisFenetre();
						
					}			
				
				}	
			}
			}
			
			

		// Les messages suivants ne sont pas traites ici, mais existent
		case Inactivite:
        case ClavierSpecial:
		case Souris:
		case Redimensionnement:
	 		 break;
	}
}






