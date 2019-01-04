#ifndef CLASEBIBLIOTECA_H_INCLUDED
#define CLASEBIBLIOTECA_H_INCLUDED

class Biblioteca{
    private:
        int ID;
        Usuario duenio; // nobmre del dueño
        char nombre[30]; // nombre biblitoca
        int tam; // tamaño maximo de libros
        bool presta; // true: puede prestar libros, false: no puede prestar libros
        int estado; // 0: baja logica, 1: activa
    public:
        /// Constructor
        //Biblioteca();

        /// Sets
        void setID(int n){ID = n;}
        void setDuenio(Usuario user){duenio = user;}
        void setNombre(char*n){strcpy(nombre, n);}
        void setTam(int tm){tam = tm;}
        void setPresta(bool x){presta = x;}
        void setEstado(int n){estado = n;}

        /// Gets
        int getID(){return ID;}
        Usuario getDuenio(){return duenio;}
        char* getNombre(){return nombre;}
        int getTam(){return tam;}
        bool getPresta(){return presta;}
        int getEstado(){return estado;}
};

#endif // CLASEBIBLIOTECA_H_INCLUDED
