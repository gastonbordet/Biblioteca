#ifndef CLASEPRESTADO_H_INCLUDED
#define CLASEPRESTADO_H_INCLUDED

class Prestado{
    private:
        char IDLibro[30];
        int IDBibliotecaOrigen;
        int IDBibliotecaDestino;
        bool devuelto; // true devuelto false no devuelto
    public:
        //LibroPorBiblioteca();
        /// Sets
        void setIDLibro(char*id){strcpy(IDLibro, id);}
        void setIDBibliotecaOrigen(int x){IDBibliotecaOrigen = x;}
        void setIDBibliotecaDestino(int x){IDBibliotecaDestino = x;}
        void setDevuelto(bool x){devuelto = x;}
        /// Gets
        char*getIDLibro(){return IDLibro;}
        int getIDBibliotecaOrigen(){return IDBibliotecaOrigen;}
        int getIDBibliotecaDestino(){return IDBibliotecaDestino;}
        bool getDevuelto(){return devuelto;}
};

#endif // CLASEPRESTADO_H_INCLUDED
