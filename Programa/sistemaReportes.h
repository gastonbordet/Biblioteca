#ifndef SISTEMAREPORTES_H_INCLUDED
#define SISTEMAREPORTES_H_INCLUDED

#include "funcionesReportes.h"

void reportes(Usuario usuario){
    while(true){
        system("cls");
        menu_reportes();
        int opc2;
        cin >> opc2;
        switch(opc2){
            case 0:
                return;
            case 1:
                system("cls");
                mostrarLibrosParaDevolver(usuario);
                break;
            case 2:
                system("cls");
                mostrarLibrosPorTerminar(usuario);
                break;
            case 3:
                system("cls");
                mostrarLibrosTerminados(usuario);
                break;
            default:
                cin >> opc2;
        }
    }
}

#endif // SISTEMAREPORTES_H_INCLUDED
