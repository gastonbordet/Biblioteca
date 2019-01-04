#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cstdlib>
#include <time.h>

using namespace std;

#include "menues.h"
#include "sistemaMisLibros.h"
#include "sistemaAutores.h"
#include "sistemaGeneros.h"
#include "sistemaBibliotecas.h"
#include "sistemaReportes.h"
#include "sistemaConfiguracion.h"

/// Validaciones libros
    /// Validacion autor (Si no existe autor se cancela operacion)
    /// Validacion genero (Si no existe genero se cancela operacion)

   /// Poner mensajes de grabado exitoso
int main()
{
    Usuario usuario;
    char username[30];
    cout << "       Username: ";
    cin.getline(username, 30);
    if(validarUsuario(username)){
       usuario = buscarUsuario(username);
       char password[30];
       cout << "       Password: ";
       cin.getline(password, 30);
       while(!(validarPassword(password, usuario))){
            cout << "Contraseña incorrecta. Intente nuevamente: ";
            cin.getline(password, 30);
       }
    }
    else{
        cout << "No se encontro el usuario, continue para crear uno nuevo." << endl;

        cout << endl;
        usuario = crearUsuario();
        if(grabarUsuario(usuario)){
            cout << "Se grabo exitosamente" << endl;
            system("pause");
        }
    }
    while(true){
        system("cls");
        int opc;
        menu_principal();

        cin >> opc;
        switch(opc){
            case 0:
                return 0;
                break;
            case 1: /// MIS LIBROS
                misLibros(usuario);
                break;
            case 2: /// AUTORES
                autores();
                break;
            case 3: /// GENEROS
                system("cls");
                generos();
                break;
            case 4: /// BIBLIOTECAS
                system("cls");
                bibliotecas(usuario);
                break;
            case 5: /// REPORTES
                system("cls");
                reportes(usuario);
                break;
            case 6: /// CONFIGURACION
                system("cls");
                configuracion();
                break;
            default:
                cin >> opc;
        }

    }

    return 0;
}
