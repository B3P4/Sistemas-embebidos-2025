#include <iostream>
#include <string>
#include <vector>

struct Persona{
    std::string nombre;
    int edad;
    char sexo;
    char estudios;
    char estado;
};

struct Familia {
    Persona integrantes[4];
    std::string direccion;
    char vivienda;
};

void print_information(Persona persona){

    printf("Nombre: %s\n",persona.nombre.c_str());
    printf("Edad: %d\n",persona.edad);
    printf("Sexo: %c\n",persona.sexo);
    printf("Nivel de estudios: %c\n",persona.estudios);
    printf("Estado de estudios: %c\n",persona.estado);

}

std::vector<Persona> filter_by_primary_studies(Familia familias[]){
    std::vector<Persona> primaria_completa;

    for(int i=0;i<2;i++)
    {
        for(int j=0; j<4;j++){
            if(familias[i].integrantes[j].estudios!='N' && !(familias[i].integrantes[j].estudios=='P' && familias[i].integrantes[j].estado=='I')){

                primaria_completa.push_back(familias[i].integrantes[j]);
            }
        }
    }

    return primaria_completa;
}

int main() {


    //Empieza la declaracion de datos
    Familia familias[2];
    Persona integrante;

    familias[0].direccion = "Independencia 1735";
    familias[0].vivienda = 'D';

    integrante.nombre = "Benicio Pavon";
    integrante.edad = 18;
    integrante.sexo = 'M';
    integrante.estudios = 'S';
    integrante.estado = 'I';
    familias[0].integrantes[0] = integrante;

    integrante.nombre = "Merlina Pavon";
    integrante.edad = 20;
    integrante.sexo = 'F';
    integrante.estudios = 'U';
    integrante.estado = 'I';
    familias[0].integrantes[1] = integrante;

    integrante.nombre = "Martin Pavon";
    integrante.edad = 62;
    integrante.sexo = 'M';
    integrante.estudios = 'U';
    integrante.estado = 'C';
    familias[0].integrantes[2] = integrante;

    integrante.nombre = "Paula Remesar";
    integrante.edad =55;
    integrante.sexo = 'F';
    integrante.estudios = 'U';
    integrante.estado = 'C';
    familias[0].integrantes[3] = integrante;



    familias[1].direccion = "General Guemes 465";
    familias[1].vivienda = 'C';

    integrante.nombre = "Gonzalo Belmonte";
    integrante.edad = 17;
    integrante.sexo = 'M';
    integrante.estudios = 'S';
    integrante.estado = 'I';
    familias[1].integrantes[0] = integrante;

    integrante.nombre = "Morcilla Belmonte";
    integrante.edad = 1;
    integrante.sexo = 'M';
    integrante.estudios = 'N';
    integrante.estado = 'C';
    familias[1].integrantes[1] = integrante;

    integrante.nombre = "Daniel Belmonte";
    integrante.edad = 55;
    integrante.sexo = 'M';
    integrante.estudios = 'U';
    integrante.estado = 'C';
    familias[1].integrantes[2] = integrante;

    integrante.nombre = "Daniela Ameneiros";
    integrante.edad =55;
    integrante.sexo = 'F';
    integrante.estudios = 'U';
    integrante.estado = 'C';
    familias[1].integrantes[3] = integrante;

    //Termina la declaracion de datos

    print_information(familias[0].integrantes[0]);

    std::vector<Persona> primaria_completa = filter_by_primary_studies(familias);
    printf("%s",primaria_completa[3].nombre.c_str()); //Chequeo que funcione

    return 0;
}