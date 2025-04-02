#include <iostream>
#include "Joc.h"
#include <ctime>

void verificaElement(char &Jucator, char &Computer)
{
    if (Jucator == 'X')
    {
        Computer = 'O';
        std::cout << "Jucator: " << Jucator << std::endl;
        std::cout << "Computer: " << Computer << std::endl;
    }
    else
    {
        Computer = 'X';
        std::cout << "Jucator: " << Jucator << std::endl;
        std::cout << "Computer: " << Computer << std::endl;
    }
}

void DeseneazaTabla(char *spatii)
{
    std::cout << "\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << spatii[0] << "  |  " << spatii[1] << "  |  " << spatii[2] << "\n";
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << spatii[3] << "  |  " << spatii[4] << "  |  " << spatii[5] << "\n";
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << spatii[6] << "  |  " << spatii[7] << "  |  " << spatii[8] << "\n";
    std::cout << "     |     |     \n";
    std::cout << "\n";
}

void miscareJucator(char *spatii, char &Jucator)
{
    int numar;

    while (true)
    {
        std::cout << "Introduceti o pozitie de la (1-9): ";
        std::cin >> numar;

        // verificare pozitie (1-9)
        if (numar < 1 || numar > 9)
        {
            std::cout << "Introduceti o pozitie noua" << std::endl;
            continue;
        }

        // ajustez indexul pentru matricea (0-8)
        numar--;

        // verific daca pozitia este libera
        if (spatii[numar] == ' ')
        {
            spatii[numar] = Jucator;
            break;
        }
        else{
            std::cout << "Pozitia este deja ocupata! Alegeti alta pozitie" << std::endl;
        }
    }
}

void miscareComputer(char *spatii, char &Computer)
{
    int numar;
    srand(time(0));

    while (true)
    {
        numar = rand() % 9;
        if (spatii[numar] == ' ')
        {
            spatii[numar] = Computer;
            break;
        }
    }
}

bool Win(char *spatii, char &Jucator, char &Computer)
{
    if (spatii[0] != ' ' && spatii[0] == spatii[1] && spatii[1] == spatii[2])
    {
        spatii[0] == Jucator ? std::cout << "AI CASTIGAT!" << std::endl : std::cout << "AI PIERDUT:(" << std::endl;
        return true;
    }

    if (spatii[3] != ' ' && spatii[3] == spatii[4] && spatii[4] == spatii[5])
    {
        spatii[3] == Jucator ? std::cout << "AI CASTIGAT!" << std::endl : std::cout << "AI PIERDUT:(" << std::endl;
        return true;
    }

    if(spatii[6] != ' ' && spatii[6] == spatii[7] && spatii[7] == spatii[8])
    {
        spatii[6] == Jucator ? std::cout << "AI CASTIGAT!" << std::endl : std::cout << "AI PIERDUT:(" << std::endl;
        return true;
    }

    if (spatii[0] != ' ' && spatii[0] == spatii[4] && spatii[4] == spatii[8])
    {
        spatii[0] == Jucator ? std::cout << "AI CASTIGAT!" << std::endl : std::cout << "AI PIERDUT:(" << std::endl;
        return true;
    }
    if (spatii[2] != ' ' && spatii[2] == spatii[4] && spatii[4] == spatii[6])
    {
        spatii[2] == Jucator ? std::cout << "AI CASTIGAT!" << std::endl : std::cout << "AI PIERDUT:(" << std::endl;
        return true;
    }

    // Daca nu exista jucatori

    return false;
}

bool VerificaEgalitate(char *spatii, char &Jucator, char &Computer)
{
    if (Win(spatii, Jucator, Computer))
    {
        return false;
    }

    for (int i = 0; i < 9; i++)
    {
        if (spatii[i] == ' ')
        {
            return false;
        }
    }
    std::cout << "Egalitate intre jucatori" << std::endl;
    return true;
}
