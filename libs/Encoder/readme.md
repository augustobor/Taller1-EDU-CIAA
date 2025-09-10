# Encoder Module

## Descripcion

Es la libreria que se encarga de manejar la interfaz de control del sable desde el lado del usaurio.

Con el encoder el usuario puede:
- Prender y apagar el sable
- Cambiar el color del sable sin transiciones ni efectos


## Como funciona?

- El encoder tiene su propia MEF en donde se encuentran los siguientes estados (en terminos del funcionamiento del sable):
    - PRENDIDO: El sable muestra todos sus colores. Se pasa a este estado despues de STARTING
    - STARTING: El sable comienza a prenderse y ocurre cuando el usuario mantiene presionado el encoder al estado apagado
    - APAGADO: Idem que prendido pero al reves
    - STOPPING: Ideam que STARTING pero al reves

Cuando el usuario interactua con el encoder rotando o presionando el boton, la funcion `Encoder_MEF_Key` se encarga de definir el nuevo estado y por ende el valor de sus variables internas.

Para controlar las luces se invoca NeoPixel y se actualizan los colores en base al estado y al `select_color` que es define el color definido en el array de colores.

Para realizar el efecto de prendido y apagado del sable en la aplicacion usando NeoPixel Effects se usan las funciones `Encoder_IS_Transicion` y `getProcentualState` como funciones de consulta.


## Estructuras de datos definidas:
    
### colorSableLazer: Array de struct color pre definidos. Son los colores posibles que podemos utilizar para modificar el sable usando el encoder

```
static struct color colorSableLazer[CANT_COLORES] = {
    (struct color){R, G, B},  
};
``` 
### Button_state: Variable de estado para la MEF

```
static eButton_State Button_state;
```

### procentual_init: Variable entera de estado APAGADO y ENCENDIDO

### procentual_step: Velocidad de cambio entre un estado y otro (Basicamente definr el tiempo del estado STOPPING y STARTING)

## Funciones claves

- [DEPRECATED?] `Encoder_Efects_Step`: Es la funcion que define el flujo de la MEF en base al estado anterior y al valor numerico de `procentual_step`.
- `Encoder_MEF_Key`: Es la funcion que escucha los eventos del encoder y en base a eso modifica el estado de la MEF. Esta es la verdadera funcion que vincula los eventos del encoder con el modelo MEF. Indirectamente controla la dinamica de encendido y apagado del sable ya que define la salida de `Encoder_IS_Enable` por ejemplo. Tambien es la funcion que invoca a NeoPixel para setar el color.

## Comentarios adicionales

- Usar un switch en `Encoder_Efects_Step`

- Separar la interfaz del Encoder de la manipulacion de la MEF desde el Encoder. Modulo propio de la MEF. Tanto las funciones de consulta como la manipulacion del estado de la MEF.

- Para futuras actualizaciones el Encoder debe ser solamente una interfaz de entrada de eventos del Encoder. Luego estos eventos son enviados una MEF centralizada que en base a las demas entradas de los modulos define el siguiente estado de control. De esta forma removemos la prioridad de NeoPixel por sobre otros modulos como el modulo Sound.
