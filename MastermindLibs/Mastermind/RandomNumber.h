#pragma once

//Encapsule le probl�me de la g�n�ration d'un nombre all�atoire
class RandomNumber
{
public:
    RandomNumber(void);
    ~RandomNumber(void);

    int GetNumber(short _max);
};

