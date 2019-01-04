#ifndef FUNCIONESMISLIBROS_H_INCLUDED
#define FUNCIONESMISLIBROS_H_INCLUDED

#include "claseFecha.h"
#include "claseLibro.h"
#include "clasePrestado.h"
#include "otrasFunciones.h"
#include "validaciones.h"
#include "funcionesAutores.h"
#include "funcionesGeneros.h"

/// LIBROS

Fecha crearFecha(){
    Fecha fecha;

    /// Dia
    cout << "Ingrese dia: ";
    int dia;
    cin >> dia;
    fecha.setDia(dia);

    /// Mes
    cout << "Ingrese mes: ";
    int mes;
    cin >> mes;
    fecha.setMes(mes);

    /// Año
    cout << "Ingrese anio: ";
    int anio;
    cin >> anio;
    fecha.setAnio(anio);

    return fecha;
}

Libro crearLibro(Usuario duenio){
    Libro libro;

    /// ID
    cin.ignore();
    cout << "Ingrese ID del libro: ";
    char id[30];
    cin.getline(id, 30);
    while(validarIdLibro(id) < 0){
        cout << "El ID ya existe, intente uno nuevo: ";
        cin.getline(id, 30);
    }
    libro.setID(id);

    /// Titulo

    cout << "Ingrese titulo del libro: ";
    char titulo[30];
    cin.getline(titulo, 30);
    libro.setTitulo(titulo);
    system("cls");

    /// Autor
    cout << "Ingrese ID del autor: ";
    int autor;
    cin >> autor;
    if(autorValido(autor) == 0){
        system("cls");
        cout << "Todavia no se crearon autores. A continuacion podra crear uno nuevo" << endl;
        cout << endl;
        grabarAutor();
    }
    while(autorValido(autor) == 1){
        system("cls");
        cout << "El ID ingresado no existe." << endl;
        cout << "Autores disponibles." << endl;
        mostrarAutores();
        cout << endl;
        cout << "Ingrese ID del autor o -1 para crear uno nuevo: ";
        cin >> autor;
        if(autor == -1){
            system("cls");
            if(grabarAutor()){
                cout << "Se grabo el autor correctamente" << endl;
                cout << "Ingrese el ID nuevamente: ";
                cin >> autor;
            }
        }
    }
    libro.setAutor(autor);
    system("cls");

    /// Genero
    cout << "Ingrese ID del genero: ";
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
    libro.setGenero(genero);
    system("cls");

    /// Fecha
    cout << "Ingrese fecha de publicacion: " << endl;
    Fecha fecha = crearFecha();
    while(!(fechaValida(fecha))){
        cout << "Fecha invalida, intente de nuevo. " << endl;
        fecha = crearFecha();
    }
    libro.setFecha(fecha);

    /// Dueño
    libro.setDuenio(duenio);

    /// Estado
    libro.setEstado(1);

    /// Prestado A
    libro.setPrestado(" ");

    cin.ignore();
    return libro;
}

bool grabarLibro(Usuario duenio){
    Libro libro = crearLibro(duenio);
    FILE * p = fopen("Libros.dat", "ab");
    if(p == NULL) return false;
    fwrite(&libro, sizeof libro, 1, p);
    fclose(p);
    return true;
}

void mostrarLibro(Libro libro){
    char autor[30];
    char genero[30];
    strcpy(autor, buscarAutor(libro.getAutor()));
    strcpy(genero, buscarGenero(libro.getGenero()));

    if(libro.getEstado()>0){

        cout << "_____________________________________" << endl;
        cout << endl;
        cout << "ID: " << libro.getID() << endl;
        cout << "Titulo: " << libro.getTitulo() << endl;
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

bool mostrarLibros(){
    Libro libro;
    FILE *x = fopen("Libros.dat", "rb");
    if(x==NULL)return false;
    cout << "               Libros                " << endl;
    while(fread(&libro, sizeof libro, 1, x))
        mostrarLibro(libro);
    fclose(x);
    return true;
}

int encontrarLibro(char*id){
    Libro libro;
    int i = 0;
    FILE *p = fopen("Libros.dat", "rb");
    if(p==NULL)return -1;
    while(fread(&libro, sizeof libro, 1, p)){
        if(strcmp(libro.getID(), id)==0){
            return i;
        }
        i++;
    }
    return -1;
}

bool terminarLibro(){
    Libro libro;
    char id[30];
    int pos = 0;
    FILE *p = fopen("Libros.dat", "rb+");
    if(p==NULL)return false;
    cin.ignore();
    cout << "Ingrese el ID del libro: ";
    cin.getline(id, 30);
    pos = encontrarLibro(id);
    if(pos == -1){
        cout << "no se pudo encontrar" << endl;
        system("pause");
        return false;}


    fseek(p, sizeof libro * pos, 0);
    fread(&libro, sizeof libro, 1, p);
    //fclose(p);
    //libro.estado = 2;
    libro.setEstado(2);

    //p = fopen("Libros.dat", "rb+");
    if(p==NULL)return false;
    fseek(p, sizeof libro * pos, 0);
    fwrite(&libro, sizeof libro, 1, p);

    fclose(p);
    return true;
}

bool borrarLibro(){
    Libro libro;
    char id[30];
    int pos = 0;
    FILE *p = fopen("Libros.dat", "rb+");
    if(p==NULL)return false;
    cin.ignore();
    cout << "Ingrese el ID del libro: ";
    cin.getline(id, 30);
    pos = encontrarLibro(id);
    if(pos == -1){
        cout << "no se pudo encontrar" << endl;
        system("pause");
        return false;}


    fseek(p, sizeof libro * pos, 0);
    fread(&libro, sizeof libro, 1, p);
    //fclose(p);
    //libro.estado = 2;
    libro.setEstado(0);

    //p = fopen("Libros.dat", "rb+");
    if(p==NULL)return false;
    fseek(p, sizeof libro * pos, 0);
    fwrite(&libro, sizeof libro, 1, p);

    fclose(p);
    return true;
}

bool modificarLibro(Usuario usuario){
    char id[30];
    cin.ignore();
    cout << "Ingrese ID del libro que quiere modificar: ";
    cin.getline(id, 30);
    int pos = encontrarLibro(id);
    if(pos == -1){
        cout << "No se encontro el libro." << endl;
        system("pause");
        return false;
    }
    FILE *p = fopen("Libros.dat", "rb+");
    cout << "Ingrese los nuevos datos. " << endl;
    Libro libro = crearLibro(usuario);
    fseek(p, sizeof libro * pos, 0);
    fwrite(&libro, sizeof libro, 1, p);
    fclose(p);
    cout << "Guardado correctamente." << endl;
    return true;
}

#endif // FUNCIONESMISLIBROS_H_INCLUDED
