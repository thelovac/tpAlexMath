#include "Mastermind.h"


Mastermind::Mastermind()
{
	int iterateur = 0;

   for(int i = 0; i < 8; i++)
   {
	   for(int j = 0; j < 8; j++)
	   {
		   for(int k = 0; k < 8; k++)
			{
				for(int l = 0; l < 8; l++)
				{
					tabSequences[iterateur]->SetElement(i, 1);
					tabSequences[iterateur]->SetElement(j, 2);
					tabSequences[iterateur]->SetElement(k, 3);
					tabSequences[iterateur]->SetElement(l, 4);
					iterateur++;
				}
			}
	   }
   }
}

Mastermind::~Mastermind()
{
}

int Mastermind::GetNbElements() const
{
    return 1;
}


ArrayI<Color>* Mastermind::GetElement() const
{
    //Utiliser la classe RandomNumber pour ne pas offrir toujours le premier �l�ment de la liste (les parties seraient toutes pareilles avec la m�me s�quence cach�e)
    ArrayI<Color>* PourCompiler;

	RandomNumber* rdm = new RandomNumber();
	rdm->GetNumber(list->GetNbElements());

	PourCompiler->operator=(tabSequences[*rdm]);

    return PourCompiler;
}

short Mastermind::CleanList(Color* _tabColorRef, short* _tabVerdicts)
{

     /*switch(tabVerdicts[i]){
                
                case 1: //Bonne couleur, bonne place

                        //Si la s�quence de couleurs trait�e n'a pas la couleur � la bonne place, il faut la retirer de la liste.

                case 2: //Bonne couleur, mauvaise place

                        //Si la s�quence de couleurs trait�e n'a pas la couleur � un autre emplacement que celui de la couleur de r�f�rence,
                        //il faut la retirer de la liste.
           
                case 3: //Mauvaise couleur
                        //Si la s�quence de couleurs trait�e a la couleur, il faut la retirer de la liste.
    };*/
    return 1; //Pour Compiler
}