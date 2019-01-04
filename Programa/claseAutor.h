#ifndef CLASEAUTOR_H_INCLUDED
#define CLASEAUTOR_H_INCLUDED

class Autor{
    private:
        int ID;
        char nombre[30] = " ";
        int IDGeneroFavorito;
        bool estado = true;

    public:
        /// Constructor
        //Autor();

        /// Sets
        void setID(int num){ID = num;}
        void setNombre(char*nom){strcpy(nombre, nom);}
        void setIDGeneroFavorito(int num){IDGeneroFavorito = num;}
        void setEstado(bool x){estado = x;}

        /// Gets
        int getID(){return ID;}
        char* getNombre(){return nombre;}
        int getIDGeneroFavorito(){return IDGeneroFavorito;}
        bool getEstado(){return estado;}
};

#endif // CLASEAUTOR_H_INCLUDED
