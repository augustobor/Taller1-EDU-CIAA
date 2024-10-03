# Sound Module

## Descripcion

Es la libreria que funciona de interfaz de colision entre el sable y los objetos fisicos a traves del modulo de MPU.

## Como funciona?

- En terminos generales, la colision llega al sable. Si un modulo de MPU lo detecta entonces se habilita un flag o variable interna que modifica una seccion del sable a traves del llamado de NeoPixel a traves de `Efects_colision`.

```
if(flag_touch_4){
    Efects_colision(PIXELS_LENGTH/16,cl,radius);
    flag_touch_4=OFF;
}
if(flag_touch_3){
    Efects_colision(PIXELS_LENGTH*3/16,cl,radius);
    flag_touch_3=OFF;
}
if(flag_touch_2){
    Efects_colision(PIXELS_LENGTH*5/16,cl,radius);
    flag_touch_2=OFF;
}
if(flag_touch_1){
    Efects_colision(PIXELS_LENGTH*7/16,cl,radius);
    flag_touch_1=OFF;
}
```