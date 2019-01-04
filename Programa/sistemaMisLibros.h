#ifndef SISTEMAMISLIBROS_H_INCLUDED
#define SISTEMAMISLIBROS_H_INCLUDED

#include "funcionesMisLibros.h"

void misLibros(Usuario usuario){
    system("cls");
    menu_misLibros();
    int opc2;
    cin >> opc2;
    switch(opc2){
        case 0:
            break;
        case 1:
            system("cls");
            if(grabarLibro(usuario)){
                system("cls");
                cout << "Libro grabado correctamente. " << endl;
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
            if(modificarLibro(usuario)){
                system("cls");
                cout << "Libro modificado correctamente. " << endl;
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
            if(terminarLibro()){
                system("cls");
                cout << "Libro terminado correctamente. " << endl;
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
            if(borrarLibro()){
                system("cls");
                cout << "Libro eliminado correctamente. " << endl;
                system("pause");
            }else{
                    system("cls");
                    cout << "Hubo un error y la operacion no se pudo realizar." << endl;
                    system("pause");
                }
            break;
        case 5:
            system("cls");
            mostrarLibros();
            system("pause");
            break;
        default:
            cin >> opc2;
        }
}

#endif // SISTEMAMISLIBROS_H_INCLUDED
