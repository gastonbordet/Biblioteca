#ifndef FUNCIONESREPORTES_H_INCLUDED
#define FUNCIONESREPORTES_H_INCLUDED

#include "validaciones.h"

bool mostrarLibrosParaDevolver(Usuario usuario){
    Prestado prestado;
    FILE *p = fopen("Prestados.dat", "rb");
    if(p==NULL)return false;
    while(fread(&prestado, sizeof prestado, 1, p)){
        if(validarBiblioteca(prestado.getIDBibliotecaDestino(), usuario) && prestado.getDevuelto() == false){
            Libro libro;
            FILE *x = fopen("Libros.dat", "rb");
            if(p==NULL)return false;
            while(fread(&libro, sizeof libro, 1, x)){
                if(strcmp(libro.getID(), prestado.getIDLibro())==0){
                    mostrarLibro(libro);
                }
            }
            fclose(x);
        }
    }
    system("pause");
    fclose(p);
    return true;
}

bool mostrarLibrosPorTerminar(Usuario usuario){
    LibroPorBiblioteca libroxbiblio;
    FILE *p = fopen("LibrosPorBibliotecas.dat", "rb");
    if(p==NULL)return false;
    while(fread(&libroxbiblio, sizeof libroxbiblio, 1, p)){
        if(validarBiblioteca(libroxbiblio.getIDBiblioteca(), usuario)){
            //cout << "Biblioteca " << libroxbiblio.getIDBiblioteca() << endl;
            Libro libro;
            FILE *x = fopen("Libros.dat", "rb");
            if(x==NULL)return false;
            while(fread(&libro, sizeof libro, 1, x)){
                if(strcmp(libroxbiblio.getIdLibro(), libro.getID())==0 && libro.getEstado()==1)
                    mostrarLibro(libro);
            }
            fclose(x);
        }
    }
    system("pause");
    fclose(p);
    return true;
}


bool mostrarLibrosTerminados(Usuario usuario){
    LibroPorBiblioteca libroxbiblio;
    FILE *p = fopen("LibrosPorBibliotecas.dat", "rb");
    if(p==NULL)return false;
    while(fread(&libroxbiblio, sizeof libroxbiblio, 1, p)){
        if(validarBiblioteca(libroxbiblio.getIDBiblioteca(), usuario)){
            //cout << "Biblioteca " << libroxbiblio.getIDBiblioteca() << endl;
            Libro libro;
            FILE *x = fopen("Libros.dat", "rb");
            if(x==NULL)return false;
            while(fread(&libro, sizeof libro, 1, x)){
                if(strcmp(libroxbiblio.getIdLibro(), libro.getID())==0 && libro.getEstado()==2)
                    mostrarLibro(libro);
            }
            fclose(x);
        }
    }
    system("pause");
    fclose(p);
    return true;
}


#endif // FUNCIONESREPORTES_H_INCLUDED
