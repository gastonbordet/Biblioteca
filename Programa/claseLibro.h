#ifndef CLASELIBRO_H_INCLUDED
#define CLASELIBRO_H_INCLUDED

#include "claseUsuario.h"

class Libro{
    private:
        char ID[30]; // ISBN
        char titulo[30];
        int autor; // Apartir de nombre saca ID de autor
        int genero; // Apartir de nombre saca ID de genero
        Fecha publicacion;
        Usuario duenio; // Autogenerado con el dueño de la biblioteca
        int estado; // 0: baja logica, 1: no terminado, 2: terminado
        char prestado[30]; // Nombre de persona a la que le prestamos el libro, debe coincidir en Bibliotecas.dat
    public:
        /// Constructor
        //Libro();

        /// Sets
        void setID(char*num){strcpy(ID, num);}
        void setTitulo(char*ti){strcpy(titulo, ti);}
        void setAutor(int id){autor = id;}
        void setGenero(int id){genero = id;}
        void setFecha(Fecha x){publicacion = x;}
        void setDuenio(Usuario user){duenio = user;}
        void setEstado(int num){estado = num;}
        void setPrestado(char*nombre){strcpy(prestado, nombre);}

        /// Gets
        char* getID(){return ID;}
        char* getTitulo(){return titulo;}
        int getAutor(){return autor;}
        int getGenero(){return genero;}
        Fecha getPublicacion(){return publicacion;}
        Usuario getDuenio(){return duenio;}
        int getEstado(){return estado;}
        char* getPrestado(){return prestado;}
};

#endif // CLASELIBRO_H_INCLUDED
