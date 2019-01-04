#ifndef SISTEMABIBLIOTECAS_H_INCLUDED
#define SISTEMABIBLIOTECAS_H_INCLUDED


#include "funcionesBibliotecas.h"
#include "funcionesBibliotecas2.h"

void bibliotecas2(Usuario usuario){
    char username[30];
    cin.ignore();
    cout << "Ingrese username de usuario que busca: ";
    cin.getline(username, 30);
    if(!(validarUsuario(username))){
        cout << "El usuario buscado no existe." << endl;
        system("pause");
        return;
    }
    Usuario otroUsuario = buscarUsuario(username);

    while(true){
        system("cls");
        menu_otrasBibliotecas2(otroUsuario.getNombre());
        int opc3;
        cin >> opc3;
        switch(opc3){
            case 0:
                return;
            case 1:
                system("cls");
                mostrarLibrosPorBibliotecas(otroUsuario);
                //system("pause");
                break;
            case 2:
                system("cls");
                pedirLibro(usuario, otroUsuario);
                break;
            case 3:
                system("cls");
                devolverLibro();
                break;
            default:
                cin >> opc3;
        }
    }
}

void bibliotecas(Usuario usuario){
    while(true){
        system("cls");
        menu_otrasBibliotecas();
        int opc2;
        cin >> opc2;
        switch(opc2){
            case 0:
                return;
            case 1:
                system("cls");
                if(grabarBiblioteca(usuario)){
                    system("cls");
                    cout << "Biblioteca grabado correctamente. " << endl;
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
                if(editarBiblioteca(usuario)){
                    system("cls");
                    cout << "Biblioteca modificada correctamente. " << endl;
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
                if(!(mostrarBibliotecas(usuario))){
                    cout << "Hubo un error y la operacion no se pudo realizar."<< endl;
                    system("pause");
                }
                break;
            case 4:
                system("cls");
                if(!(mostrarLibrosPorBibliotecas(usuario))){
                    cout << "No hay libros en las bibliotecas."<< endl;
                    system("pause");
                }
                break;
            case 5:
                system("cls");
                if(borrarBiblioteca()){
                    system("cls");
                    cout << "Biblioteca eliminada correctamente. " << endl;
                    system("pause");
                }
                else{
                    system("cls");
                    cout << "Hubo un error y la operacion no se pudo realizar." << endl;
                    system("pause");
                }
                break;
            case 6:
                system("cls");
                if(guardarLibro(usuario)){
                    system("cls");
                    cout << "Libro guardado correctamente. " << endl;
                    system("pause");
                }
                else{
                    system("cls");
                    cout << "Hubo un error y la operacion no se pudo realizar." << endl;
                    system("pause");
                }
                break;
            case 7:
                system("cls");
                bibliotecas2(usuario);
                break;
            default:
                cin >> opc2;
        }
    }

}

#endif // SISTEMABIBLIOTECAS_H_INCLUDED
