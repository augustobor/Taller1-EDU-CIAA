# NeoPixel Module

## Descripcion

Es la libreria core en cuanto al manejo de la tira led se refiere. Controla directamente los colores del sable mediante:

- HW mediante la generacion de interrupciones periodicas casa 1250ns, c
- SW a traves de getters y seters del color que operan el array `datachain`

## Como funciona?

- La tira led RGB se modela como una matriz flat vector de. La configuracion de cada componente RGB de cada led se modifica en cada celda del array. 
- Logicamente se modelo el sistema en su conjunto como una MEF en donde se encuentra el estado de actualizacion o no de la hoja del sable a travez de la variable `update`. Actualmente dicha variable tiene un scope por encima del modulo para servir como semaforo a otros modulos modelados como MEFs
- Se puede actualizar la hoja de forma pixeleada o contiguamente


## Estructuras de datos definidas:
    
### Color: estructura para definir un color en formato RGB

```
struct color {
    uint8_t g;
    uint8_t r;
    uint8_t b;
};
``` 
### Datachain: Array de Color para modelar la hoja del sable

Cada 3 pixeles representa un led ya que cada pixel representa un componente del RGB

```
static volatile uint8_t datachain[PIXELS_LENGTH*3];
```

### PIXEL_BIT_LENGHT

Es la cantidad de bits necesarios para modificar toda la hoja del sable

```
static uint32_t PIXEL_BITS_LENGTH = PIXELS_LENGTH*24;
```

## Funciones claves

- `setCurrentColor`: Permite actualizar toda la hoja directamente y practicamente sin latencia al ser acceso directo
- `setColor`: Define el RGB de un led en particular. Para determinar la opacidad de todo el RGB se puede usar `setcolor_i`.
- `mirror`: Basicamente replica el color que hay de un extremo a otro. Sabiendo que la hoja del sable es un elemento simetrico, aprovechamos en realizar una asignacion mas eficiente y evitando varias ejecucion bucle de for
- `setColor_fade`: Permite definir colores personalizados a partir de la combinacion de 2 colores con respectivos niveles de intensidad en %

## Comentarios adicionales

- Para el upgrade de este modulo se espera que la funcion `SysTick_Handler` sea definida en un modulo aparte y que en el example de Neopixel se realice un llamado

- Es requerible analizar la viabilidad de migrar la logica de manejo de MEF a un modulo mas abarcativo para evitar el uso de variables definidas en modulos fuera del scope