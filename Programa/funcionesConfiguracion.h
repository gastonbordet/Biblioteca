#ifndef FUNCIONESCONFIGURACION_H_INCLUDED
#define FUNCIONESCONFIGURACION_H_INCLUDED

#include "claseAutor.h"
#include "claseBiblioteca.h"
#include "claseFecha.h"
#include "claseGenero.h"
#include "claseLibro.h"
#include "claseLibroPorBiblioteca.h"
#include "clasePrestado.h"
#include "claseUsuario.h"
#include "validaciones.h"

bool crearBackup(){
    /// Autores
    Autor autor;
    FILE *p = fopen("Autores.dat", "rb");
    FILE *x = fopen("bkp/Autores.dat", "wb");

    while(fread(&autor, sizeof autor, 1, p)){
        fwrite(&autor, sizeof autor, 1, x);
    }

    /// Bibliotecas
    Biblioteca biblioteca;
    p = fopen("Bibliotecas.dat", "rb");
    x = fopen("bkp/Bibliotecas.dat", "wb");

    while(fread(&biblioteca, sizeof biblioteca, 1, p)){
        fwrite(&biblioteca, sizeof biblioteca, 1, x);
    }

    /// Generos
    Genero genero;
    p = fopen("Generos.dat", "rb");
    x = fopen("bkp/Generos.dat", "wb");

    while(fread(&genero, sizeof genero, 1, p)){
        fwrite(&genero, sizeof genero, 1, x);
    }

    /// Libros
    Libro libro;
    p = fopen("Libros.dat", "rb");
    x = fopen("bkp/Libros.dat", "wb");

    while(fread(&libro, sizeof libro, 1, p)){
        fwrite(&libro, sizeof libro, 1, x);
    }

    /// LibrosPorBiblioteca
    LibroPorBiblioteca libroxbiblio;
    p = fopen("LibrosPorBibliotecas.dat", "rb");
    x = fopen("bkp/LibrosPorBibliotecas.dat", "wb");

    while(fread(&libroxbiblio, sizeof libroxbiblio, 1, p)){
        fwrite(&libroxbiblio, sizeof libroxbiblio, 1, x);
    }

    /// Prestados
    Prestado prestado;
    p = fopen("Prestados.dat", "rb");
    x = fopen("bkp/Prestados.dat", "wb");

    while(fread(&prestado, sizeof prestado, 1, p)){
        fwrite(&prestado, sizeof prestado, 1, x);
    }

    /// Usuarios
    Usuario usuario;
    p = fopen("Usuarios.dat", "rb");
    x = fopen("bkp/Usuarios.dat", "wb");

    while(fread(&usuario, sizeof usuario, 1, p)){
        fwrite(&usuario, sizeof usuario, 1, x);
    }

    fclose(p);
    fclose(x);

    cout << "Se han creado todos los backups sin problemas." << endl;
    system("pause");
    return true;
}

bool cargarBackup(){
/// Autores
    Autor autor;
    FILE *x = fopen("Autores.dat", "wb");
    FILE *p = fopen("bkp/Autores.dat", "rb");

    while(fread(&autor, sizeof autor, 1, p)){
        fwrite(&autor, sizeof autor, 1, x);
    }


    /// Bibliotecas
    Biblioteca biblioteca;
    x = fopen("Bibliotecas.dat", "wb");
    p = fopen("bkp/Bibliotecas.dat", "rb");

    while(fread(&biblioteca, sizeof biblioteca, 1, p)){
        fwrite(&biblioteca, sizeof biblioteca, 1, x);
    }

    /// Generos
    Genero genero;
    x = fopen("Generos.dat", "wb");
    p = fopen("bkp/Generos.dat", "rb");

    while(fread(&genero, sizeof genero, 1, p)){
        fwrite(&genero, sizeof genero, 1, x);
    }

    /// Libros
    Libro libro;
    x = fopen("Libros.dat", "wb");
    p = fopen("bkp/Libros.dat", "rb");

    while(fread(&libro, sizeof libro, 1, p)){
        fwrite(&libro, sizeof libro, 1, x);
    }

    /// LibrosPorBiblioteca
    LibroPorBiblioteca libroxbiblio;
    x = fopen("LibrosPorBibliotecas.dat", "wb");
    p = fopen("bkp/LibrosPorBibliotecas.dat", "rb");

    while(fread(&libroxbiblio, sizeof libroxbiblio, 1, p)){
        fwrite(&libroxbiblio, sizeof libroxbiblio, 1, x);
    }

    /// Prestados
    Prestado prestado;
    x = fopen("Prestados.dat", "wb");
    p = fopen("bkp/Prestados.dat", "rb");

    while(fread(&prestado, sizeof prestado, 1, p)){
        fwrite(&prestado, sizeof prestado, 1, x);
    }

    /// Usuarios
    Usuario usuario;
    x = fopen("Usuarios.dat", "wb");
    p = fopen("bkp/Usuarios.dat", "rb");

    while(fread(&usuario, sizeof usuario, 1, p)){
        fwrite(&usuario, sizeof usuario, 1, x);
    }

    fclose(p);
    fclose(x);

    cout << "Se han cargado todos los backups sin problemas." << endl;
    system("pause");
    return true;
}

bool borrarArchivos(){
    /// Autores
    FILE *p = fopen("Autores.dat", "wb");

    /// Bibliotecas
    p = fopen("Bibliotecas.dat", "wb");

    /// Generos
    p = fopen("Generos.dat", "wb");

    /// Libros
    p = fopen("Libros.dat", "wb");

    /// LibrosPorBiblioteca
    p = fopen("LibrosPorBibliotecas.dat", "wb");

    /// Prestados
    p = fopen("Prestados.dat", "wb");

    /// Usuarios
    p = fopen("Usuarios.dat", "wb");

    fclose(p);

    cout << "Se han borrado todos los archivos." << endl;
    system("pause");
    return true;
}

#endif // FUNCIONESCONFIGURACION_H_INCLUDED
