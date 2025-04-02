#ifndef _JOC_H_
#define _JOC_H_

void verificaElement(char &Jucator, char &Computer);
void DeseneazaTabla(char *spatii);
void miscareJucator(char* spatii, char &Jucator);
void miscareComputer(char* spatii, char &Computer);
bool Win(char* spatii, char &Jucator, char &Computer);
bool VerificaEgalitate(char* spatii, char &Jucator, char &Computer);

#endif