# Pruebas de Ejemplo del Neopixel

Este documento describe las pruebas implementadas en `neopixel_example.c`, cómo se evalúan, los resultados esperados y los criterios de fallo.

## Prueba 1: Inicialización del Neopixel

### Descripción
Esta prueba inicializa el Neopixel.

### Evaluación
- Se llama a la función `Neopixel_Init()` para inicializar el Neopixel.

### Resultado Esperado
- El Neopixel debe inicializarse correctamente.

### Criterios de Fallo
- Si el Neopixel no se inicializa correctamente, la prueba falla.

## Prueba 2: Cambio de Color del Neopixel

### Descripción
Esta prueba cambia el color del Neopixel.

### Evaluación
- Se llama a la función `Neopixel_SetColor()` para configurar el color del Neopixel.

### Resultado Esperado
- El Neopixel debe cambiar al color especificado.

### Criterios de Fallo
- Si el Neopixel no cambia al color especificado, la prueba falla.

## Prueba 3: Ajuste de Brillo del Neopixel

### Descripción
Esta prueba ajusta el brillo del Neopixel.

### Evaluación
- Se llama a la función `Neopixel_SetBrightness()` para configurar el brillo del Neopixel.

### Resultado Esperado
- El Neopixel debe ajustarse al nivel de brillo especificado.

### Criterios de Fallo
- Si el Neopixel no se ajusta al nivel de brillo especificado, la prueba falla.
