#include <iostream>
#include <ctime>
#include "Joc.h"
#include <string>

int main()
{
    char Jucator;
    char Computer;
    std::string optiune;
    std::string reluare = "da";

    while (reluare == "da")
    {
        std::cout << "Doriti inceperea jocului?(da): ";
        std::cin >> optiune;

        if (optiune == "da")
        {

            std::cout << "Introduceti elementul dorit(X/O): ";
            std::cin >> Jucator;

            verificaElement(Jucator, Computer); // se verifica daca utilizatorul a introdus un element in asa fel incat i se asigneaza automat calculatorului, celalalt element

            char spatii[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
            DeseneazaTabla(spatii);

            bool run = true; // variabila care sa indice functionarea jocului

            while (run)
            {
                miscareJucator(spatii, Jucator);
                DeseneazaTabla(spatii);
                if (Win(spatii, Jucator, Computer))
                {
                    run = false;
                    break;
                }

                miscareComputer(spatii, Computer);
                DeseneazaTabla(spatii);
                if (Win(spatii, Jucator, Computer))
                {
                    run = false;
                    break; // daca se indeplineste conditia iese din while
                }

                if (VerificaEgalitate(spatii, Jucator, Computer))
                {
                    run = false;
                    break;
                }
            }
            std::cout << "Doriti reluarea jocului(da/nu)?: ";
            std::cin >> reluare;
        }
        else
            reluare = "nu";
    }
    return 0;
}
