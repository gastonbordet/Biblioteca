#ifndef CLASEFECHA_H_INCLUDED
#define CLASEFECHA_H_INCLUDED

class Fecha{
private:
    int dia, mes, anio;
public:
    //Fecha();
    void setDia(int n){dia = n;}
    void setMes(int n){mes = n;}
    void setAnio(int n){anio = n;}
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}

};

#endif // CLASEFECHA_H_INCLUDED
