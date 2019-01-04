#ifndef CLASELIBROPORBIBLIOTECA_H_INCLUDED
#define CLASELIBROPORBIBLIOTECA_H_INCLUDED

class LibroPorBiblioteca{
    private:
        char idLibro[30];
        int IDBiblioteca;
        bool estado = true;
    public:
        //Prestado();
        /// Sets
        void setIdLibro(char*id){strcpy(idLibro, id);}
        void setIDBiblioteca(int n){IDBiblioteca = n;}
        void setEstado(bool x){estado = x;}
        /// Gets
        char*getIdLibro(){return idLibro;}
        int getIDBiblioteca(){return IDBiblioteca;}
        bool getEstado(){return estado;}

};


#endif // CLASELIBROPORBIBLIOTECA_H_INCLUDED
