// MastermindCLR.h

#pragma once

using namespace System;

namespace MastermindCLR {

    public ref class Ordinateur
    {
        // TODO: Add your methods for this class here.
    public:

        Ordinateur();
        ~Ordinateur();

        void genererSequence();  //Les tableaux ne peuvent pas �tre pass�s du CSHARP au C++ (il ne sont pas encore support�s).
                                 //C'est pourquoi nous d�cortiquons la s�quence (ArrayI<Couleur>) en 4 entiers (c1 � c4)
                                 //Rappel: Une couleur encapsule un entier ;)
        int getCouleur1();
        int getCouleur2();
        int getCouleur3();
        int getCouleur4();

        void epurerListe(int _c1, //4 couleurs de r�f�rence
                         int _c2,
                         int _c3,
                         int _c4, 
                         int _v1, //4 verdicts
                         int _v2,
                         int _v3,
                         int _v4);

    private:
        
        Mastermind* mastermind;

        //Les 4 entiers qui font office de couleur
        int c1;
        int c2;
        int c3;
        int c4;
    };
}
