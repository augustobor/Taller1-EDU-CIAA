# NeoPixel_Effects Module

## Descripcion

En este modulo se manejan los efectos visuales del sable utilizando las funciones definidas en Neopixel como `setColor` y `mirror` para crear efectos de prendido y apagado.

La ejecucion de estos efectos en tiempo real es posible a traves del manejo de la variable `update` de Neopixel.

## Variables internas definidas:

### BrainTable: Array numerico utilizada para realizar efectos de fade_in y fade_out mediante el recorrido secuencial del mismo y usando `setColor_i` de NeoPixel 

```
uint8_t brain_table[] = { }
```

### angulo_temporal: Variable interna utilizada para asignar dinamica y gradualmente valores entre -360 y 360 para definir la opacidad de un color a lo largo del efecto

```
uint16_t angulo_temporal=0;
```

### Velocity: Define el incremento en la que el `angulo_temporal` aumenta 

```
uint16_t velocity=3;
```

### Desfasaje_by_pixel: Definicion del offset a traves del pixel. Recorre 360� en cada 40pixel[longitud de onda] ; 360/40

```
uint8_t desfazaje_by_pixel=9; 
```

### Corrimiento_angular: Definicion del offset inicial a partir del angulo utilizado como condicion inicial para la definicion de efectos

```
uint16_t corrimiento_angular=0;
```


## Funciones claves

- `Efects_sinoidal_breath_c_mirror`: Genera el efecto de prendido y apagado del sable de forma gradual
- `Efects_porcentual`: Genera el prendido y apagado de forma gradual. Usado solo cuando se prende y apaga el sable para dar la sensacion de sable Jedi.
- `Efects_colision`: BAl llamar esta funcion se genera un destello especifico en la posicion que es pasada. No realiza la parte logica en la que se detecta el impacto sino que recibe la posicion en particular con una distancia radial de leds afectados
