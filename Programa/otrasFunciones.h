#ifndef OTRASFUNCIONES_H_INCLUDED
#define OTRASFUNCIONES_H_INCLUDED

#include "funcionesBibliotecas.h"

Usuario crearUsuario(){
    Usuario user;
    cin.ignore();
    cout << "Ingrese username: ";

    char username[30];
    cin.getline(username, 30);
    user.setUsername(username);

    cout << "Ingrese nombre y apellido: ";
    char nombre[30];
    cin.getline(nombre, 30);
    user.setNombre(nombre);

    cout << "Ingrese un password: ";
    char pass[30];
    cin.getline(pass, 30);
    user.setClave(pass);

    return user;
}

bool grabarUsuario(Usuario usuario){
    FILE *p = fopen("Usuarios.dat", "ab");
    if(p==NULL)return false;
    fwrite(&usuario, sizeof usuario, 1, p);
    fclose(p);
    return true;
}

Usuario buscarUsuario(char*username){
    Usuario user;
    FILE *p = fopen("Usuarios.dat", "rb");
    while(fread(&user, sizeof user, 1, p)){
        if(strcmp(user.getUsername(), username)==0){
            fclose(p);
            return user;
        }
    }
    fclose(p);
    return user;
}

int generarID(){
    srand (time(NULL));
    int ran = rand() % 1000 + 1000;
    return ran;
}

#endif // OTRASFUNCIONES_H_INCLUDED
