![alt text](./images/linux_penguin.png)
![alt text](./images/pc.png)
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

## Pasos de instalacion

1. **Ir a:** https://github.com/epernia/software y descargar la ultima release para utilizar el entorno **EDU-CIAA**
2. Descomprimir la carpeta en una ruta conocida, sin espacios y con los permisos adecuados. Se
recomiendan
    a. Windows. `C:\CIAA\`
3. Descargar el repositorio Firmware `v3` release `v1.3.0` y Descomprimir la carpeta en una ruta conocida, sin espacios y con los permisos adecuados. Se
recomiendan
    a. Windows. `C:\CIAA\`
4. Copiar los archivo `app/` y libs cusotoms a las `libs/` del firmware v3
5. Compilar el firmware v3



> **Nota Importante:**
> 👀 Verificar en los archivos de configuracionque no se este llamando a `sapi.h` y que `sapi.h` no se este llamando en otros programas.
>

6. **Configuracion Zadig**: En el menu seleccione el dispositivo "Dual RS232HS (Interface 0)" y presionar el botón "Replace Driver":

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