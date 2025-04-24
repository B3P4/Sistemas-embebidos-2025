#include <cmath>
#include <iostream>
#include <math.h>
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
    std::vector<Persona> integrantes;
    std::string direccion;
    char vivienda;
};

void print_information(Persona persona){

    printf("Nombre: %s\n",persona.nombre.c_str());
    printf("Edad: %d\n",persona.edad);
    printf("Sexo: %c\n",persona.sexo);
    printf("Nivel de estudios: %c\n",persona.estudios);
    printf("Estado de estudios: %c\n\n",persona.estado);

}

std::vector<Persona> filter_by_studies(std::vector<Persona> personas, char estudio){
    std::vector<Persona> estudiosos;
    int nivel=0;
    int nivelPersona=0;
    if(estudio=='P'){nivel=2;}   //Asigno un valor numerico al nivel de estudios alcanzados
    if(estudio=='S'){nivel=3;}   //para poder compararlos en el for, ya que si alguine tiene
    if(estudio=='T'){nivel=4;}   //nivel universitario tambien tienen secundario y primario
    if(estudio=='U'){nivel=5;}

    for(int i=0;i<personas.size();i++)
    {
        if(personas[i].estudios=='N'){nivelPersona=1;}  //Asigno un valor numerico al nivel de estudios alcanzados
        if(personas[i].estudios=='P'){nivelPersona=2;}  //para poder compararlos en el for, ya que si alguine tiene
        if(personas[i].estudios=='S'){nivelPersona=3;}  //nivel universitario tambien tienen secundario y primario
        if(personas[i].estudios=='T'){nivelPersona=4;}
        if(personas[i].estudios=='U'){nivelPersona=5;}

        if(nivel<=nivelPersona){
            estudiosos.push_back(personas[i]);
        }
    }
    return estudiosos;
}

std::vector<Persona> filter_by_age_greater_than (std::vector<Persona> personas, int edadCorte){
    std::vector<Persona> viejos;
    for(int i=0;i<personas.size();i++){
        if(personas[i].edad>=edadCorte){
            viejos.push_back(personas[i]);
        }
    }
    return viejos;
}

std::vector<Familia> filter_by_home_type(std::vector<Familia> familias, char vivienda){
    std::vector<Familia> FamiliaFiltrada;

    for(int i=0;i<familias.size();i++){
        if(familias[i].vivienda==vivienda){
            FamiliaFiltrada.push_back(familias[i]);
        }
    }

    return FamiliaFiltrada;
}

Familia find_family_with_most_tertiary_graduates (std::vector<Familia> familias){ //La cambie para que incluya terciario porque es lo que pide el c
    Familia familiaEstudiosa;  //la familia con mas estudios
    int cantEstudiosos=-1;     // la cantidad de graduados terciarios en la familiaEstudiosa. Inicializa en u nvalor menor al minimo posible
    std::vector<Persona> familiaresGraduados;

    for(int i=0;i<familias.size();i++){
        familiaresGraduados=filter_by_studies(familias[i].integrantes,'T'); //Filtro los estudiantes graduados en una variable quee va a ser reciclada
        for(int j=0;j<familiaresGraduados.size();j++){
            if(familiaresGraduados[j].estado=='I'){
                familiaresGraduados.erase(familiaresGraduados.begin()+j); //Elimino los integrants que no tengan la uni terminada
            }
        }
        if((int)familiaresGraduados.size()>cantEstudiosos){
            cantEstudiosos=(int)familiaresGraduados.size();
            familiaEstudiosa = familias[i];
        }
    }
    return familiaEstudiosa;
}

float get_avg_age_by_family(Familia familias){
    float prom;
    int sumaEdades=0;
    for(int i=0; i<4; i++){
        sumaEdades+=familias.integrantes[i].edad;
    }
    prom=(float)sumaEdades/4;

    return prom;
}

float get_male_population_percentage(std::vector<Familia> familias){
    float porcentaje;
    int cantMasculino=0;
    int cantidadPoblacion=(int)familias.size()*4;
    for(int i=0;i<familias.size();i++){
        for(int j=0; j<4; j++){
            if (familias[i].integrantes[j].sexo=='M')
            {
                cantMasculino++;
            }
        }
    }

    porcentaje = (float)cantMasculino/(float)cantidadPoblacion*100;


    return porcentaje;
}


int main(){

    //Empieza la declaracion de datos
    std::vector<Familia> familias;
    Familia familia1;
    Familia familia2;
    Persona integrante;

    familia1.direccion = "Independencia 1735";
    familia1.vivienda = 'D';

    integrante.nombre = "Benicio Pavon";
    integrante.edad = 18;
    integrante.sexo = 'M';
    integrante.estudios = 'S';
    integrante.estado = 'I';
    familia1.integrantes.push_back(integrante);

    integrante.nombre = "Merlina Pavon";
    integrante.edad = 20;
    integrante.sexo = 'F';
    integrante.estudios = 'U';
    integrante.estado = 'I';
    familia1.integrantes.push_back(integrante);

    integrante.nombre = "Martin Pavon";
    integrante.edad = 62;
    integrante.sexo = 'M';
    integrante.estudios = 'U';
    integrante.estado = 'C';
    familia1.integrantes.push_back(integrante);

    integrante.nombre = "Paula Remesar";
    integrante.edad =55;
    integrante.sexo = 'F';
    integrante.estudios = 'U';
    integrante.estado = 'C';
    familia1.integrantes.push_back(integrante);

    familias.push_back(familia1);


    familia2.direccion = "General Guemes 465";
    familia2.vivienda = 'D';

    integrante.nombre = "Gonzalo Belmonte";
    integrante.edad = 17;
    integrante.sexo = 'M';
    integrante.estudios = 'S';
    integrante.estado = 'I';
    familia2.integrantes.push_back(integrante);

    integrante.nombre = "Morcilla Belmonte";
    integrante.edad = 1;
    integrante.sexo = 'M';
    integrante.estudios = 'N';
    integrante.estado = 'C';
    familia2.integrantes.push_back(integrante);

    integrante.nombre = "Daniel Belmonte";
    integrante.edad = 55;
    integrante.sexo = 'M';
    integrante.estudios = 'U';
    integrante.estado = 'C';
    familia2.integrantes.push_back(integrante);

    integrante.nombre = "Daniela Ameneiros";
    integrante.edad =55;
    integrante.sexo = 'F';
    integrante.estudios = 'U';
    integrante.estado = 'C';
    familia2.integrantes.push_back(integrante);

    familias.push_back(familia2);

    //Termina la declaracion de datos

    std::vector<Persona> primariaCompleta; //Este lo creo para el punto a)
    std::vector<Persona> noAnalfabeto; //Este lo creo para el punto b), la diferencia con primariaCompleta va a ser que este incluye los no terminaron la primaria
    int mayorA10=0; //Para el b)
    std::vector<float> promedioFamiliar; // para el d)

    for(int i=0;i<familias.size();i++){  //En este for voy pasando por las familias y asi poder usar funciones que pidan vectore de Persona y no Familia
        std::vector<Persona> vectorMayorA10 = filter_by_age_greater_than(familias[i].integrantes,10);
        std::vector<Persona> primariaAuxiliar = filter_by_studies(familias[i].integrantes,'P');//Guardo un vector auxiliar de personas con primaria
        for(int j=0;j<primariaAuxiliar.size();j++){
            if(primariaAuxiliar[j].estado == 'C' || primariaAuxiliar[j].estudios != 'P'){primariaCompleta.push_back(primariaAuxiliar[j]);} //Agrego al a la lista definitiva quienes completaron la primaria
            noAnalfabeto.push_back(primariaAuxiliar[j]); //Agrego todos a la lista de "no-analfabetos"
        }

        mayorA10 += (int)vectorMayorA10.size();

        promedioFamiliar.push_back(get_avg_age_by_family(familias[i]));
    }

    printf("a) Datos de quienes terminaron los estudios primarios:\n");

    for(int i=0;i<primariaCompleta.size();i++){

        print_information(primariaCompleta[i]);
    } // imprimo la informacion del a)



    noAnalfabeto=filter_by_age_greater_than(noAnalfabeto,10);


    float porcentajeAnalfabetismo = 100-(float)noAnalfabeto.size()/((float)mayorA10)*100;

    printf("-----\n\nb) Porcentaje de analfabetismo: %.2f \n",porcentajeAnalfabetismo);

    //Ejercicio c)

    std::vector<Familia> vivenDepto = filter_by_home_type(familias,'D');
    Familia familiaUniversitaria = find_family_with_most_tertiary_graduates(vivenDepto);
    float promedioCiudad=0;

    printf("-----\nc) Domicilio de la familia con mayor cantidad de integrantes de nivel terciario que viven en departamento:\n %s \n",familiaUniversitaria.direccion.c_str());


    //Ejercicio d)

    printf("-----\nd)\n");
    for(int i=0;i<promedioFamiliar.size();i++)
    {
        printf("Promedio de edad familia %d: %.2f\n",i+1,promedioFamiliar[i]);
        promedioCiudad += promedioFamiliar[i];
    }
    promedioCiudad = promedioCiudad/(float)promedioFamiliar.size();
    printf("\nPromedio de edad en la ciudad : %.2f\n",promedioCiudad);

    //Ejercicio e)
    int cantP=0;
    int cantS=0;
    int cantT=0;
    int cantU=0;
    for(int i=0;i<familias.size();i++)
    {
        for (int j=0;j<4;j++)
        {
            if (familias[i].integrantes[j].estado == 'I')
            {
                if (familias[i].integrantes[j].estudios == 'P'){cantP++;}
                if (familias[i].integrantes[j].estudios == 'S'){cantS++;}
                if (familias[i].integrantes[j].estudios == 'T'){cantT++;}
                if (familias[i].integrantes[j].estudios == 'U'){cantU++;}

            }
        }
    }
    printf("-----\ne)\n");
    printf("Cantidad de encuestados con primaria incompleta: %d\n",cantP);
    printf("Cantidad de encuestados con secundaria incompleta: %d\n",cantS);
    printf("Cantidad de encuestados con terciario incompleto: %d\n",cantT);
    printf("Cantidad de encuestados con universidad incompleta: %d\n",cantU);

    //Ejercicio f)
    float porcentajeMasculino = get_male_population_percentage(familias);
    printf("-----\nf) \n");
    printf("Porcentaje de poblacion masculina: %2.f\n",porcentajeMasculino);
    printf("Porcentaje de poblacion femenina: %2.f",100-porcentajeMasculino);
    return 0;
}