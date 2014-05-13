#pragma once

#include <iostream>
using namespace std;

template <class TYPE>
class ArrayI
{
public:
    ArrayI(int _nbElements);
    ~ArrayI(void);

    int GetNbElements() const;
    TYPE GetElement(const int &_position) const;
    void SetElement(const TYPE &_element, const int &_position);

    //Surcharges
    TYPE& operator[](const int& _position);
    void operator=(const ArrayI<TYPE> &_arrayI);

    template <class TYPE>
    friend ostream& operator<<(ostream& _sortie, const ArrayI<TYPE> &_arrayI);

private:
    ArrayI(ArrayI&); //Copieur d�sactiv�
    //static const int NB_ELEMENTS = 100;
    int nbElements;
    TYPE* tab;
};

#include "ArrayI.hpp"
























//int rechercheDichoRec(TYPE element, int deb, int fin) {
//    if(deb > fin) return -1;
//
//    int milieu = (deb + fin)/2 ;
//
//    TYPE e = _pTab[milieu] ;
//
//    if(e==element)
//        return (milieu); //On a trouv�!
//    else if (e<element)
//        return (rechercheDicho(element, milieu+1, fin));
//    else
//        return(rechercheDicho(element, deb, milieu-1));
//}


//Quick Sort: Diviser pour mieux r�gner!
//
//Algorithme:
//D�terminer PIVOT (s�pare le pTab en 2), 
//         ->On fait passer � droite du PIVOT les valeurs plus grandes
//         ->On fait passer � gauche du PIVOT les valeurs plus petites
//       ->On recommence avec la partie de gauche
//         ->On recommence avec la partie de droite
// et MAGIE!

//void quickSort(TYPE *pTab, int premier, int dernier) {
//    static int numAppel=0;
//    numAppel++;
//
//
//    //Affichage du tableau a traiter
//    for(int i = premier; i<= dernier; i++){
//        if(i==premier) cout<<"Appel de quickSort "<<numAppel<<endl;
//            
//        cout<<pTab[i]<<" ";
//
//        if(i==dernier) cout<<endl;
//    }
//        
//    int indexPivot;
//
//    //Si la partie est trop petite pour �tre tri�e, on doit rien faire
//    if(premier<dernier) {
//
//        indexPivot = partitionner(pTab, premier, dernier); //D�termine le prochain PIVOT, tout ce qui est � droite de ce PIVOT est plus grand ou �gale � ce qui se trouve � gauche
//
//        /*Tout ce qui est plus petit se retrouve � gauche (incluant le pivot) du tableau
//        et tout ce qui est plus grand se retrouve � droite (exluant le pivot) du tableau */
//
//        quickSort(pTab, premier, indexPivot); //On recommence avec la partie de gauche (inclut le PIVOT car il n'est pas n�cessairement le plus grand m�me s'il est plac� � la derni�re postion)
//        quickSort(pTab, indexPivot+1, dernier);  //On recommence avec la partie de droite (exclut le PIVOT)
//    }
//}
     
//Place tout ce qui est plus petit que le PIVOT (premier �l�ment) � gauche de tout ce qui est plus grand que le PIVOT.
//D�termine le nouveau PIVOT, il correspond � la premier valeur plus petite que le PIVOT en partant de la fin
//int partitionner(TYPE *pTab, int premier, int dernier) {
//    const int pivot = pTab[premier]; //Le PIVOT est le premier �l�ment du tableau pTab (sous tableau de QuickSort)
//    int gauche = premier-1; //It�rateur � partir du d�but
//    int droite = dernier+1; //It�rateur � partir de la fin
//    while(true) {
//        do
//            droite--;
//        while(pTab[droite] > pivot); //Les �l�ments plus grands que le PIVOT (premier �l�ment) en partant de la droite ne sont pas d�plac�s.
//
//        do
//            gauche++;
//        while(pTab[gauche] < pivot); //Les �l�ments plus petits que le PIVOT (premier �l�ment) en partant de la gauche ne sont pas d�plac�s.
//
//        if(gauche<droite) //Si un �l�ment plus grand se trouve � gauche d'un �l�ment plus petit, on les permute
//            permuter(pTab[gauche], pTab[droite]);
//        else
//            return droite;  //L'�l�ment plus grand se trouve � la droite du plus petit, ce dernier (le plus petit) est le prochain PIVOT
//    }
//}



//Surcharges
//TYPE& operator[](const int& position){
//    assert(position>=0 && position<_nbElements);
//    return _pTab[position];
//}
//
//void operator=(const tabSafe<TYPE>& p){ //Affectateur
//    delete[] _pTab; //Libere la m�miore en premier
//
//    _pTab = new TYPE[p._nbElements];
//        
//    //Copie des valeurs
//    for(int i=0;i<p._nbElements;i++){
//        _pTab[i]=p._pTab[i];
//    }
//}
//friend ostream& operator<<(ostream& sortie, const tabSafe& t){
//    for(int i=0;i<t._nbElements;i++){
//        sortie<<"["<<i<<"]: "<<t._pTab[i]<<endl;
//    }
//    return sortie;
//}
