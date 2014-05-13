#pragma once
#include "RandomNumber.h"
#include "ArrayI.h"
#include "List.h"
#include "MasterMindColor.h"

class Mastermind
{
public:
    Mastermind();
    ~Mastermind();

    int GetNbElements() const;
    ArrayI<Color>* GetElement() const;

    //�pure la liste de s�quences de couleurs en fonction de la s�quence trait�e et des 4 verdicts (valeurs 1 � 3) sur cette derni�re.
    short CleanList(Color* _tabColorRef, short* _tabVerdicts);

private:
    List<ArrayI<Color>>* list; //Contient toutes les s�quences de couleurs possibles, selon le contexte.
    ArrayI<Color>* tabSequences[4096]; //Pointeurs pour la destruction des 4096 s�quences de couleurs cr��es sur le tas par le Mastermind::Mastermind() lors de la cr�ation de la liste.
};
