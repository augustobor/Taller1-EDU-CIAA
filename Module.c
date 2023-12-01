
#define TRUNC(n) ((uint16_t)(n))

uint8_t sound_raw[5000];
uint8_t sound_module[5000];
float vt=1.1; //velocidad de transduccion
float dx; // variacion x
float x; // valor de trabjo actual
float ganancia;

int main(){

    if(FLAG_MPU_libre){
        read_MPU();
        calcular_vt(&vt);
        valcular_ganancia(&ganancia);
        FLAG_modular_frecuencia=ON;
        FLAG_modular_amplitud=ON;
    }

    if(FLAG_modular_frecuencia){
        modular(vt);
    }
    if(FLAG_modular_amplitud){
        amplificar(ganancia);
    }

}

// usa @vt: velocidad de transduccion
// recalcula sound_module y sound_module_limit
void modular(float vt){
    sound_module_limit=5000/vt;
    for(int i=0; i<sound_module_limit ; i++){
        x=TRUNC(i*vt); // valor interpolado inferior
        y1=sound_raw[x];
        y2=sound_raw[x+1];
        dx=TRUNC(i*vt)-x;
        sound_module[i]=interpol(y1,y2,dx);
    }
}

// interpolacion lineal, toma 2 valores , y el porcentaje de cercania entre ellos
uint8_t interpol(uint8_t y1 ,uint8_t y2, float dx ){
    return (y1 + (y2-y1)*dx);
}


// @ganancia cantidad de veces que amplifica respecto al medio de la señal
// si tiene demaciada ganancia habilita el flag de sonido roto
void amplificar(float ganancia){
    uint8_t temp_s;
    float temp_sg;
    for(int i=0; i<sound_module_limit; i++){
        temp_s=sound_module[i];
        temp_sg=(temp_s-128)*ganancia;
        if(temp_sg>128){
            FLAG_crash=ON;  // si tiene demaciada ganancia habilita el flag de sonido roto
            temp_sg=128;
        }
        if(temp_sg<-128){
            FLAG_crash=ON;  // si tiene demaciada ganancia habilita el flag de sonido roto
            temp_sg=-128;
        }
        sound_module[i]= temp_sg + 128; // al valor medio, le suma el delta amplificado
    }
}
