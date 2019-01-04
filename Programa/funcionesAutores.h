#ifndef FUNCIONESAUTORES_H_INCLUDED
#define FUNCIONESAUTORES_H_INCLUDED

#include "funcionesGeneros.h"
#include "claseAutor.h"
#include "validaciones.h"

Autor crearAutor(){
    cin.ignore();
    Autor autor;

    /// ID
    cout << "Ingrese ID del autor: ";
    int id;
    cin >> id;
    while(autorValido(id) < 0){
        cout << "El ID ya existe, ingrese uno nuevo: ";
        cin >> id;
    }
    autor.setID(id);
    cin.ignore();
    system("cls");

    /// Nombre
    cout << "Ingrese nombre del autor: ";
    char nombre[30];
    cin.getline(nombre, 30);
    autor.setNombre(nombre);
    system("cls");

    /// Genero
    cout << "Ingrese ID de su genero favorito: ";
    int genero;
    cin >> genero;

    if(generoValido(genero) == 0){
        system("cls");
        cout << "Todavia no se crearon generos. A continuacion podra crear uno nuevo" << endl;
        cout << endl;
        grabarGenero();
    }
    while(generoValido(genero) == 1){
        system("cls");
        cout << "El ID ingresado no existe." << endl;
        cout << "Generos disponibles." << endl;
        mostrarGeneros();
        cout << endl;
        cout << "Ingrese ID del genero o -1 para crear uno nuevo: ";
        cin >> genero;
        if(genero == -1){
            system("cls");
            if(grabarGenero()){
                cout << "Se grabo el genero correctamente" << endl;
                cout << "Ingrese el ID nuevamente: ";
                cin >> genero;
            }
        }
    }

    autor.setIDGeneroFavorito(genero);
    system("cls");



    return autor;
}

bool grabarAutor(){
    Autor autor = crearAutor();
    FILE *p = fopen("Autores.dat", "ab");
    if(p==NULL)return false;
    fwrite(&autor, sizeof autor, 1, p);
    fclose(p);
    return true;
}

void mostrarAutor(Autor autor){
    char genero[30];
    strcpy(genero, buscarGenero(autor.getIDGeneroFavorito()));

    cout << "_____________________________________" << endl;
    cout << endl;
    cout << "ID: " <<autor.getID() << endl;
    cout << "Nombre: " <<autor.getNombre() << endl;
    if(strcmp(genero, " ") == 0){
        cout << "Genero no encontrado, ID: " << autor.getIDGeneroFavorito() << endl;
    }
    else{
        cout << genero << endl;
    }
    cout << "_____________________________________" << endl;
}

bool mostrarAutores(){
    Autor autor;
    FILE*p = fopen("Autores.dat", "rb");
    if(p==NULL) return false;
    cout << "                Autores              " << endl;
    while(fread(&autor, sizeof autor, 1, p)){
        if(autor.getEstado()==true)
            mostrarAutor(autor);
    }
    fclose(p);
    system("pause");
    return true;
}

char* buscarAutor(int id){
    Autor autor;
    FILE *p = fopen("Autores.dat", "rb");
    if(p==NULL)return " ";
    while(fread(&autor, sizeof autor, 1, p)){
        if(autor.getID()==id && autor.getEstado() == true){
            fclose(p);
            return autor.getNombre();
        }
    }
    fclose(p);
    return " ";
}

int posicionAutor(int id){
    Autor autor;
    FILE *p = fopen("Autores.dat", "rb");
    int pos = 0;
    if(p==NULL)return -1;
    while(fread(&autor, sizeof autor, 1, p)){
        if(autor.getID()==id){
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -1;
}


bool modificarAutor(){
    Autor autor;
    int id;
    cout << "Ingrese ID de autor: ";
    cin >> id;
    int pos = posicionAutor(id);
    if(pos == -1){
        cout << "El usuario no existe o fue dado de baja." << endl;
        return false;
    }
    FILE *p = fopen("Autores.dat", "rb+");
    fseek(p, sizeof autor * pos, 0);
    fread(&autor, sizeof autor, 1, p);

    char nombre[30];
    cin.ignore();
    cout << "Ingrese nuevo nombre: ";
    cin.getline(nombre, 30);

    autor.setNombre(nombre);

    int genero;
    cout << "Ingrese nuevo ID de genero favorito: ";
    cin >> genero;

    autor.setIDGeneroFavorito(genero);

    fseek(p, sizeof autor * pos, 0);
    fwrite(&autor, sizeof autor, 1, p);
    fclose(p);
    return true;
}

bool eliminarAutor(){
    Autor autor;
    int id;
    cout << "Ingrese ID de autor: ";
    cin >> id;
    int pos = posicionAutor(id);
    if(pos == -1){
        cout << "El usuario no existe o fue dado de baja." << endl;
        return false;
    }

    FILE *p = fopen("Autores.dat", "rb+");
    fseek(p, sizeof autor * pos, 0);
    fread(&autor, sizeof autor, 1, p);

    autor.setEstado(false);

    fseek(p, sizeof autor * pos, 0);
    fwrite(&autor, sizeof autor, 1, p);
    fclose(p);
    return true;

}

#endif // FUNCIONESAUTORES_H_INCLUDED
