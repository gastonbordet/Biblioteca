#ifndef CLASEGENERO_H_INCLUDED
#define CLASEGENERO_H_INCLUDED

class Genero{
    private:
        int ID;
        char nombre[30];
        bool estado = true;
    public:
        /// Constructor
        //Genero();

        /// Sets
        void setID(int num){ID = num;}
        void setNombre(char*nom){strcpy(nombre, nom);}
        void setEstado(bool x){estado = x;}

        /// Gets
        int getID(){return ID;}
        char* getNombre(){return nombre;}
        bool getEstado(){return estado;}
};


#endif // CLASEGENERO_H_INCLUDED
