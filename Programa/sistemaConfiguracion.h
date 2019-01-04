#ifndef SISTEMACONFIGURACION_H_INCLUDED
#define SISTEMACONFIGURACION_H_INCLUDED

#include "funcionesConfiguracion.h"

void configuracion(){
    while(true){
        system("cls");
        menu_configuracion();
        int opc2;
        cin >> opc2;
        switch(opc2){
            case 0:
                return;
            case 1:
                system("cls");
                crearBackup();
                break;
            case 2:
                system("cls");
                cargarBackup();
                break;
            case 3:
                system("cls");
                borrarArchivos();
                break;
            default:
                cin >> opc2;
        }
    }
}

#endif // SISTEMACONFIGURACION_H_INCLUDED
