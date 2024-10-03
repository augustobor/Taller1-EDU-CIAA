/*==================[inclusions]=============================================*/

#include "Encoder.h"

/*==================[variables]=================================*/



static uint8_t select_color = 12; // numero de color seleccionado por defecto
static float procentual_init=0; // estado de prendido (0 apagado ; 1 prendido ; ... )
static float procentual_step=0.02; // velocidad de prendido
static eButton_State Button_state;

/*==================[funciones]=================================*/

void Button_init() {
	Button_state = APAGADO;
}

void Encoder_Efects_Step(){

	if ( (Button_state==STARTING) || (Button_state== STOPPING) ){ // ESTO PUEDE SER UN SWITCH
		if(Button_state== STARTING){ // incremento el porcentaje de inicio
			procentual_init=procentual_init+procentual_step;
			if(procentual_init>=1){
				Button_state=PRENDIDO;
				procentual_init=1;
			}
		}
		if(Button_state== STOPPING){ // decremento el porcentaje de prendido
			procentual_init=procentual_init-procentual_step;
			if(procentual_init<=0){
				Button_state=APAGADO;
				procentual_init=0;
			}
		}

	}

}


// MEF verrifica el estado del encoder, con el puldador en flanco descendente prende y apaga
// con el giro del enconder cambia el color del sistema
void Encoder_MEF_Key() {
	static bool_t CLK_ANT, DT_ANT;
	static bool_t B_CLK , B_DT;
	CLK_ANT=B_CLK;	// guardo los valores anteriores de las se�ales de entrada
	DT_ANT=B_DT;

	// leo los valores nuevos de la se�ales
	B_DT= gpioRead(ENC_B_DT);
	B_CLK= gpioRead(ENC_A_CLK);

	static uint16_t timedelay=0;
	if( ! gpioRead(BOTON_SW) ){ // si se mantiene presionado el boton prendido, acumula
		timedelay++;
	}else{
		timedelay=0;
	}
	if(timedelay==100) { // si acumula 100 veces con el boton presionado
		if(Button_state==APAGADO) Button_state = STARTING; // cambio de estado
		if(Button_state==PRENDIDO) Button_state = STOPPING;
	}
	if(!CLK_ANT && B_CLK) { //si hay un flanco ascencendente del CLK, se verifica direccion con DT
		if(B_DT){
			select_color=(++select_color)%CANT_COLORES;
		}else{
			select_color=(--select_color + CANT_COLORES) %CANT_COLORES;
		}
		setCurrentColor(colorSableLazer[select_color]);
	}

}

// inicializa las entradas digitales del encoder
void Encoder_Init() {
    
    //Configuracion para la rotacion del encoder
    gpioConfig(ENC_A_CLK, GPIO_INPUT );
    gpioConfig(ENC_B_DT, GPIO_INPUT);

    //Configuracion para cuando el pulsador se presiona
    gpioConfig(BOTON_SW, GPIO_INPUT);
}


// retorna si el sable esta totalmente prendido
// retorna FALSE cuando el sable esta apagado, o haciendo transicion de estado
bool_t Encoder_IS_Enable(){
	return  ( Button_state==PRENDIDO );
}

bool_t Encoder_IS_Disable(){
	return (Button_state==APAGADO);
}
bool_t Encoder_IS_Transicion(){
	return (Button_state==STARTING) || (Button_state== STOPPING);
}
float getProcentualState(){
	return procentual_init;
}
