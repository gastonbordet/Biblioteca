#ifndef FUNCIONESBIBLIOTECAS_H_INCLUDED
#define FUNCIONESBIBLIOTECAS_H_INCLUDED

#include "claseUsuario.h"
#include "claseBiblioteca.h"
#include "claseLibroPorBiblioteca.h"
#include "funcionesMisLibros.h"
#include "funcionesAutores.h"
#include "funcionesGeneros.h"
#include "otrasFunciones.h"
#include "validaciones.h"

Biblioteca crearBiblioteca(Usuario user, int id = 0){
    Biblioteca biblioteca;

    /// ID
    if(id==0){
        cout << "Ingrese ID de biblioteca: ";
        cin >> id;

        while(validarIdBiblioteca(id) < 0 || id < 0){
            cout << "Ese ID ya esta en uso o es invalido. Ingrese uno nuevo: ";
            cin >> id;
        }
    }
    biblioteca.setID(id);

    /// Dueño
    biblioteca.setDuenio(user);

    /// Nombre
    cin.ignore();
    char nombre[30];
    cout << "Ingrese nombre biblioteca: ";
    cin.getline(nombre, 30);
    biblioteca.setNombre(nombre);

    /// Tamaño
    int tam;
    cout << "Ingrese tamanio maximo de la biblioteca: ";
    cin >> tam;
    while(tam <= 0){
        cout << "Ingrese una cantidad mayor a 0: ";
        cin >> tam;
    }
    biblioteca.setTam(tam);


    /// Presta
    biblioteca.setPresta(true);

    /// Estado
    biblioteca.setEstado(1);

    cin.ignore();
    return biblioteca;
}

bool grabarBiblioteca(Usuario user){
    Biblioteca biblioteca = crearBiblioteca(user);
    FILE *p = fopen("Bibliotecas.dat", "ab");
    if(p==NULL)return false;
    fwrite(&biblioteca, sizeof biblioteca, 1, p);
    fclose(p);
    return true;
}

void mostrarBiblioteca(Biblioteca biblioteca){
    if(biblioteca.getEstado()==1){

        cout << "_____________________________________" << endl;
        cout << "ID: " << biblioteca.getID() << endl;
        cout << "Nombre:  " << biblioteca.getNombre() << endl;
        cout << "Tamanio maximo: " << biblioteca.getTam() << endl;
        if(biblioteca.getPresta()==true){
            cout << "Presta libros" << endl;
        }
        else{
            cout << "No presta libros" << endl;
        }
        cout << "_____________________________________" << endl;
    }
}

bool mostrarBibliotecas(Usuario user){
    Biblioteca biblioteca;
    FILE *p = fopen("Bibliotecas.dat", "rb");
    if(p==NULL)return false;
    cout << "             Bibliotecas             " << endl;
    while(fread(&biblioteca, sizeof biblioteca, 1, p)){
        if(validarBiblioteca(biblioteca.getID(), user))
            mostrarBiblioteca(biblioteca);
    }

    system("pause");

    fclose(p);
    return true;
}

int encontrarBiblioteca(int id){
    Biblioteca biblioteca;
    FILE *p = fopen("Bibliotecas.dat", "rb");
    if(p==NULL)return -1;
    int i = 0;
    while(fread(&biblioteca, sizeof biblioteca, 1, p)){
        if(biblioteca.getID()==id){
            fclose(p);
            return i;
        }
        i++;
    }
    fclose(p);
    return -1;
}

bool borrarBiblioteca(){
    //cin.ignore();
    Biblioteca biblioteca;
    FILE *p = fopen("Bibliotecas.dat", "rb+");
    int id;

    cout << "Ingrese ID de biblioteca a borrar: ";
    cin >> id;

    int pos = encontrarBiblioteca(id);
    if(pos == -1){
        cout << "No se pudo encontrar la biblioteca." << endl;
        return false;
    }

    fseek(p, sizeof biblioteca * pos, 0);
    fread(&biblioteca, sizeof biblioteca, 1, p);

    biblioteca.setEstado(0);

    fseek(p, sizeof biblioteca * pos, 0);
    fwrite(&biblioteca, sizeof biblioteca, 1, p);

    fclose(p);
    return true;
}

bool guardarLibro(Usuario usuario){
    cin.ignore();
    char idLibro[30];
    cout << "Ingrese ID del libro que desea: ";
    cin.getline(idLibro, 30);
    // Validar id de libro
    if(validarIdLibro(idLibro) != -1){
        cout << "ID no existe o es invalido." << endl;
        system("pause");
        return false;
    }

    int idBiblio;
    cout << "Ingrese ID de biblioteca donde desea guardarlo: ";
    cin >> idBiblio;
    if(!(validarBiblioteca(idBiblio, usuario))){
        cout << "La biblioteca no pertenece al usuario o es invalida" << endl;
        system("pause");
        return false;
    }

    LibroPorBiblioteca libroxbiblio;
    FILE *p = fopen("LibrosPorBibliotecas.dat", "ab");
    if(p==NULL)return false;

    if(!(validarEspacioBiblioteca(idBiblio))){
        cout << "No se pueden agregar mas libros a la biblioteca.";
        system("pause");
        return false;
    }
    libroxbiblio.setIdLibro(idLibro);
    libroxbiblio.setIDBiblioteca(idBiblio);
    libroxbiblio.setEstado(true);
    fwrite(&libroxbiblio, sizeof libroxbiblio, 1, p);
    fclose(p);
    return true;
}

bool editarBiblioteca(Usuario usuario){
    Biblioteca biblioteca;
    FILE *p = fopen("Bibliotecas.dat", "rb+");
    if(p==NULL){
        cout << "No se pudo abrir biblioteca" << endl;
        return false;
    }

    int id;
    cout << "Ingrese ID de biblioteca que quiere modificar: ";
    cin >> id;
    if(!(validarBiblioteca(id, usuario))){
        cout << "La biblioteca no existe o pertenece a otro usuario." << endl;
        system("pause");
        return false;
    }

    cout << "Ingrese los nuevos datos de la biblioteca: ";
    biblioteca = crearBiblioteca(usuario, id);

    int pos = encontrarBiblioteca(id);
    fseek(p, sizeof biblioteca * pos, 0);
    fwrite(&biblioteca, sizeof biblioteca, 1, p);
    fclose(p);

    return true;
}

void mostrarLibro2(Libro libro){
    char autor[30];
    char genero[30];
    strcpy(autor, buscarAutor(libro.getAutor()));
    strcpy(genero, buscarGenero(libro.getGenero()));

    if(libro.getEstado()>0){

        cout << "_____________________________________" << endl;
        cout << endl;
        cout << libro.getID() << endl;
        cout << libro.getTitulo() << endl;
        if(strcmp(autor, " ") == 0){
            cout << "Autor: " << libro.getAutor() << endl;
        }
        else{
            cout << "Autor: " << autor << endl;
        }
        if(strcmp(genero, " ") == 0){
            cout << "Genero no encontrado, ID: " << libro.getGenero() << endl;
        }
        else{
            cout << "Genero: " << genero << endl;
        }
        cout << "Fecha de publicacion: ";
        cout << libro.getPublicacion().getDia() << "/" <<
                libro.getPublicacion().getMes() << "/" <<
                libro.getPublicacion().getAnio() << endl;
        //cout << "Duenio: " << libro->getDuenio().getNombre() << endl;
        if(libro.getEstado()==1)cout << "No se termino de leer" << endl;
        if(libro.getEstado()==2)cout << "Se termino de leer" << endl;
        cout << "_____________________________________" << endl;
    }
}


bool mostrarLibrosPorBibliotecas(Usuario duenio){
    LibroPorBiblioteca libroxbiblio;
    FILE *p = fopen("LibrosPorBibliotecas.dat", "rb");
    if(p==NULL)return false;
    cout << "        Libros por biblioteca        " << endl;
    cout << "_____________________________________" << endl;
    while(fread(&libroxbiblio, sizeof libroxbiblio, 1, p)){
        if(validarBiblioteca(libroxbiblio.getIDBiblioteca(), duenio)){
            Libro libro;
            FILE *x = fopen("Libros.dat", "rb");
            if(x==NULL)return false;
            while(fread(&libro, sizeof libro, 1, x)){
                if(strcmp(libroxbiblio.getIdLibro(), libro.getID())==0 && libroxbiblio.getEstado()==true){
                    cout << endl << "Biblioteca " << libroxbiblio.getIDBiblioteca() << endl;
                    mostrarLibro2(libro);
                }
            }
            fclose(x);
        }
    }
    fclose(p);
    Prestado prestados;
    p = fopen("Prestados.dat", "rb");
    if(p==NULL){
        system("pause");
        return true;
    }
    while(fread(&prestados, sizeof prestados, 1, p)){
        if(validarBiblioteca(prestados.getIDBibliotecaDestino(), duenio)){

            Libro libro;
            FILE *x = fopen("Libros.dat", "rb");
            if(x==NULL)return false;
            while(fread(&libro, sizeof libro, 1, x)){

                if(strcmp(prestados.getIDLibro(), libro.getID())== 0 && prestados.getDevuelto()== false){
                    cout << endl << "Biblioteca " << prestados.getIDBibliotecaDestino() << endl;
                    mostrarLibro2(libro);
                }
            }
            fclose(x);
        }
    }
    system("pause");
    fclose(p);
    return true;
}

#endif // FUNCIONESBIBLIOTECAS_H_INCLUDED
