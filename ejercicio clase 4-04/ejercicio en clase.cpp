#include <stdio.h>

struct Sensor { 
    int sensor_id;
    int timestamp;
    int value_type;
    int value;
};

int datos[7][4]{
    {28,1313009355,0,426}, //0=flow
    {65,1120382229,1,555}, //1=level
    {72,1675846041,2,592}, //2=temperature
    {44,1433302985,0,352},
    {99,1397135423,3,244}, //3=pressure
    {16,1718956004,0,766},
    {65,1158080786,3,393},
};

Sensor parse_sensor(int datos[4]){
    Sensor senseo;
    senseo.sensor_id=datos[0];
    senseo.timestamp=datos[1];
    senseo.value_type=datos[2];
    senseo.value=datos[3];
    return senseo;
}

int get_highest_value(int datos[7][4],int tipo_sensor){
    int mayor=0;
    for(int i=0;i<7;i++){
        
        if(datos[i][2]==tipo_sensor && datos[i][3]>mayor){
            mayor=datos[i][3];
        }
    }

    return mayor;
}

int get_lowest_value(int datos[7][4],int tipo_sensor){
    int menor=1000;
    for(int i=0;i<7;i++){
        
        if(datos[i][2]==tipo_sensor && datos[i][3]<menor){
            menor=datos[i][3];
        }
    }

    return menor;
}

float get_average_value(int datos[7][4],int tipo_sensor){
    int contador=0;
    int suma=0;
    for(int i=0;i<7;i++){
        if(datos[i][2]==tipo_sensor){
            suma+=datos[i][3];
            contador++;
        }
    }
    
    float avg = (float)suma/(float)contador;
    return avg;
}

/*int get_range_value(int datos[7][4],int tipo_sensor){
    int menor=get_lowest_value(datos,tipo_sensor);
    int mayor=get_highest_value(datos,tipo_sensor);
    return menor,mayor;
}*/

int main() {
   
   Sensor vacio;
   
   vacio = parse_sensor(datos[2]);
   printf("%d\n",vacio.sensor_id);
   printf("%d\n",vacio.timestamp);
   printf("%d\n",vacio.value_type);
   printf("%d\n\n",vacio.value);
 
   int mayor=get_highest_value(datos,3);
   printf("%d\n",mayor);
   
   int menor=get_lowest_value(datos,3);
   printf("%d\n",menor);

   float promedio=get_average_value(datos,3);
   printf("%f\n",promedio);
   
   /*int rango[2]=get_range_value(datos,3);
   printf("%d\n",rango);*/

    return 0;
}
