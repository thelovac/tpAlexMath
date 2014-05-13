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

					list->PushBack(tabSequences[iterateur]);

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
	Iterator<ArrayI<Color>>* iterateur = new Iterator<ArrayI<Color>>;
	iterateur->SetCurrent(list->Begin());
	int nbElements;

	while(iterateur->GetCurrent() != NULL)
	{
		nbElements++;
	}

    return nbElements;
}


ArrayI<Color>* Mastermind::GetElement() const
{
    //Utiliser la classe RandomNumber pour ne pas offrir toujours le premier élément de la liste (les parties seraient toutes pareilles avec la même séquence cachée)

	Iterator<ArrayI<Color>>* iterateur = new Iterator<ArrayI<Color>>;
	iterateur->SetCurrent(list->Begin());

	RandomNumber rdm;

	int color = rdm.GetNumber(list->GetNbElements());

	for(int i = 1; i < color; i++);
	{
		iterateur->Next();
	}

	return iterateur->GetCurrentElement();
}

short Mastermind::CleanList(Color* _tabColorRef, short* _tabVerdicts)
{
	for(int j = 1; j < list->GetNbElements(); j++)
	{

		for(int i = 0; i < 4; i++)
		{
			switch(_tabVerdicts[i])
			{
                
                case 1: //Bonne couleur, bonne place

                        //Si la séquence de couleurs traitée n'a pas la couleur à la bonne place, il faut la retirer de la liste.


                case 2: //Bonne couleur, mauvaise place

                        //Si la séquence de couleurs traitée n'a pas la couleur à un autre emplacement que celui de la couleur de référence,
                        //il faut la retirer de la liste.
           
                case 3: //Mauvaise couleur
                        //Si la séquence de couleurs traitée a la couleur, il faut la retirer de la liste.
			};
		}
	}
    return 1; //Pour Compiler
}