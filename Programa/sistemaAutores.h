#ifndef SISTEMAAUTORES_H_INCLUDED
#define SISTEMAAUTORES_H_INCLUDED

#include "funcionesAutores.h"

void autores(){
    while(true){
        system("cls");
        menu_autores();
        int opc2;
        cin >> opc2;
        switch(opc2){
            case 0:
                return;
            case 1:
                system("cls");
                if(grabarAutor()){
                    system("cls");
                    cout << "Autor grabado correctamente. " << endl;
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
                if(modificarAutor()){
                    system("cls");
                    cout << "Autor modificado correctamente. " << endl;
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
                if(eliminarAutor()){
                    system("cls");
                    cout << "Autor eliminado correctamente. " << endl;
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
                mostrarAutores();
                break;
            default:
                cin >> opc2;
        }
    }
}

#endif // SISTEMAAUTORES_H_INCLUDED
