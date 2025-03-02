# Pruebas de Ejemplo del Encoder

Este documento describe las pruebas implementadas en `encoder_example.c`, cómo se evalúan, los resultados esperados y los criterios de fallo.

## Prueba 1: Inicialización del Encoder

### Descripción
Esta prueba inicializa el encoder.

### Evaluación
- Se llama a la función `Encoder_Init()` para inicializar el encoder.

### Resultado Esperado
- El encoder debe inicializarse correctamente.

### Criterios de Fallo
- Si el encoder no se inicializa correctamente, la prueba falla.

## Prueba 2: Paso de Efectos del Encoder con STARTING

### Descripción
Esta prueba aplica el paso de efectos del encoder con el estado del botón configurado en `STARTING`.

### Evaluación
- Se llama a la función `Button_init()` para inicializar el botón.
- Se llama a la función `setButtonState(STARTING)` para configurar el estado del botón en `STARTING`.
- Se llama a la función `Encoder_Efects_Step()` para aplicar el paso de efectos del encoder.

### Resultado Esperado
- El paso de efectos del encoder debe aplicarse correctamente con el estado `STARTING`.

### Criterios de Fallo
- Si no hay cambio de señal o el paso de efectos del encoder no se aplica correctamente, la prueba falla.

## Prueba 3: Paso de Efectos del Encoder con STOPPING

### Descripción
Esta prueba aplica el paso de efectos del encoder con el estado del botón configurado en `STOPPING`.

### Evaluación
- Se llama a la función `Button_init()` para inicializar el botón.
- Se llama a la función `setButtonState(STOPPING)` para configurar el estado del botón en `STOPPING`.
- Se llama a la función `Encoder_Efects_Step()` para aplicar el paso de efectos del encoder.

### Resultado Esperado
- El paso de efectos del encoder debe aplicarse correctamente con el estado `STOPPING`.

### Criterios de Fallo
- Si no hay cambio de señal o el paso de efectos del encoder no se aplica correctamente, la prueba falla.

## Prueba 4: Clave MEF del Encoder

### Descripción
Esta prueba ejecuta la clave MEF del encoder.

### Evaluación
- Se llama a la función `Encoder_MEF_Key()` para procesar la clave MEF del encoder.

### Resultado Esperado
- La clave MEF del encoder debe procesarse correctamente.

### Criterios de Fallo
- Si no hay cambio de señal o la clave MEF del encoder no se procesa correctamente, la prueba falla.
