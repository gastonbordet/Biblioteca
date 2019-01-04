#ifndef SISTEMAGENEROS_H_INCLUDED
#define SISTEMAGENEROS_H_INCLUDED

#include "funcionesGeneros.h"

void generos(){
    while(true){
        system("cls");
        menu_generos();
        int opc2;
        cin >> opc2;
        switch(opc2){
            case 0:
                return;
            case 1:
                system("cls");
                if(grabarGenero()){
                    system("cls");
                    cout << "Genero grabado correctamente. " << endl;
                    system("pause");
                }
                else{
                    system("cls");
                    cout << "Hubo un error y la operacion no se pudo realizar." << endl;
                    system("pause");
                }
                break;
            case 2:
                system("cls");
                if(modificarGenero()){
                    system("cls");
                    cout << "Genero modificado correctamente. " << endl;
                    system("pause");
                }
                else{
                    system("cls");
                    cout << "Hubo un error y la operacion no se pudo realizar." << endl;
                    system("pause");
                }
                break;
            case 3:
                system("cls");
                if(eliminarGenero()){
                    system("cls");
                    cout << "Genero eliminado correctamente. " << endl;
                    system("pause");
                }
                else{
                    system("cls");
                    cout << "Hubo un error y la operacion no se pudo realizar." << endl;
                    system("pause");
                }
                break;
            case 4:
                system("cls");
                mostrarGeneros();
                break;
            default:
                cin >> opc2;
        }
    }
}

#endif // SISTEMAGENEROS_H_INCLUDED
