/*==================[inclusions]=============================================*/

#include "Encoder.h"

/*==================[variables]=================================*/



static uint8_t select_color = 0; // numero de color seleccionado
static float procentual_init=0;
static float procentual_step=0.008;
static eButton_State Button_state;

/*==================[funciones]=================================*/

void Button_init() {
	Button_state = APAGADO;
}

void Encoder_Efects_Step(){

	if ( (Button_state==STARTING) || (Button_state== STOPPING) ){
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
		Efects_porcentual(procentual_init); // efecto
		//Sound_Module_Porcentual(procentual_init);
	}


}


// MEF verrifica el estado del encoder, con el puldador en flanco descendente prende y apaga
// con el giro del enconder cambia el color del sistema
void Encoder_MEF_Key() {
	static bool_t CLK_ANT, DT_ANT, SW_ANT,SW_ANT_ANT;
	static bool_t B_CLK , B_DT, B_SW;
	CLK_ANT=B_CLK;	// guardo los valores anteriores de las señales de entrada
	DT_ANT=B_DT;
	SW_ANT_ANT=SW_ANT;
	SW_ANT=B_SW;
	B_SW= gpioRead(BOTON_SW); // leo los valores nuevos de la señales
	B_DT= gpioRead(ENC_B_DT);
	B_CLK= gpioRead(ENC_A_CLK);

	if(!SW_ANT_ANT && SW_ANT && B_SW) { // flanco ascendente de 3 lecturas
		if(Button_state==APAGADO) Button_state = STARTING;
		if(Button_state==PRENDIDO) Button_state = STOPPING;
	}
	if(!CLK_ANT && B_CLK) { //si hay un flanco ascencendente del CLK, se verifica direccion con DT
		if(B_DT){
			select_color=(++select_color)%CANT_COLORS;
		}else{
			select_color=(--select_color + CANT_COLORS) %CANT_COLORS;
		}
		setCurrentColor(colorSystem[select_color]);
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

