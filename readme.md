# Taller 1 - EDU-CIAA

Este repositorio contiene los archivos y el código correspondiente al Taller 1 de la plataforma EDU-CIAA. Este taller tuvo como objetivo realizar el codigo para construir un sable de luz con tias led y sonido controlados por dicha aplicacion.

## Requisitos

Para trabajar con este proyecto, necesitas tener instalado lo siguiente:

- **Compilador GCC ARM**: Para compilar el código para la plataforma EDU-CIAA.
- **EDU-CIAA Firmware**: Librerías necesarias para la programación del microcontrolador.
- **Programador/Depurador**: JTAG o similar compatible con EDU-CIAA.

## Contenidos del Repositorio

- **src/**: Código fuente del proyecto.
- **docs/**: Documentación y materiales de apoyo.
- **Makefile**: Archivo para compilar y generar el binario del proyecto.
- **README.md**: Este archivo con la descripción del proyecto.

## Requisitos

Para trabajar con este proyecto, necesitas tener instalado lo siguiente:

- **Compilador GCC ARM**: Para compilar el código para la plataforma EDU-CIAA.
- **EDU-CIAA Firmware**: Librerías necesarias para la programación del microcontrolador.
- **Programador/Depurador**: JTAG o similar compatible con EDU-CIAA.

## Instrucciones de Uso

1. Clona este repositorio en tu máquina local:

   ```bash
   git clone https://github.com/augustobor/Taller1-EDU-CIAA.git

2. Accede al directorio del proyecto:

    ```bash
    cd Taller1-EDU-CIAA

3. Compila el proyecto utilizando el Makefile:

    ```bash
    make all

4. Conecta la plataforma EDU-CIAA a tu computadora y carga el binario generado.

## Estructura del Proyecto

```
Firmware_SaberLight/
├── scripts/            # Código fuente del proyecto
├── libs/               # Librerias y modulos usados en el proyecto
├── Makefile            # Archivo de configuración para la compilación
└── README.md           # Descripción del proyecto
```

## Contribuir
Si deseas contribuir a este proyecto, sigue los siguientes pasos:

Realiza un fork de este repositorio.

1. Crea una nueva rama con tus cambios:

    ```bash
    git checkout -b nombre-de-tu-rama

2. Realiza tus cambios y haz commit de los mismos:

    ```bash
    git commit -m "Descripción de los cambios"

3. Envía tus cambios al repositorio remoto:

    ```bash
    git push origin nombre-de-tu-rama