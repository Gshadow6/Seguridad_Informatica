# Keylogger para Seguridad Informática

* * *
## Explicación de Cada Sección
1. **Descripción:** Un resumen breve del propósito del programa.
2. **Instrucciones de Uso:** Detalles sobre cómo compilar y ejecutar el programa, así como la ubicación del archivo de log.
3. **Supuestos del Programa:** Cualquier supuesto que el programa haga, como permisos y compatibilidad del teclado.
4. **Casos de Uso:** Ejemplos prácticos de cómo el programa debería comportarse en diferentes situaciones.
5. **Notas:** Información adicional sobre depuración y uso responsable.
6. **Contacto:** Información para obtener ayuda o soporte.

* * *
## Descripción
Este programa es un keylogger desarrollado para registrar las teclas presionadas en un teclado. Está diseñado como parte de una tarea para un curso de Seguridad Informática. El keylogger guarda las entradas del teclado en un archivo de log y maneja teclas especiales como Shift, Caps Lock, y Alt Gr.

* * *
## Instrucciones de Uso
1. **Requisitos:**
   - Sistema operativo Linux.
   - Permisos de administrador para acceder a dispositivos de entrada (teclado).

2. **Compilación:**
   `gcc -o keylogger keylogger.c`

4. **Ejecución:**
Ejecuta el keylogger con permisos de superusuario para poder acceder al dispositivo del teclado:
  `sudo ./keylogger`

5. **Salida:**
Las teclas presionadas se registran en el archivo de log especificado en LOGFILEPATH:
  `/home/kali/SeguridadInformatica/KeyLogger/keylogger.txt`

6. **Detención:**
  Para detener el keylogger, presiona Ctrl + C en la terminal donde se está ejecutando el programa.

* * *
## Supuestos del Programa
- Permisos de Acceso: Se asume que el usuario tiene permisos necesarios para acceder al dispositivo de teclado. Si encuentras un error de "Permission denied", asegúrate de ejecutar el programa con permisos de superusuario.
- Compatibilidad de Teclado: El keylogger está diseñado para teclados configurados en el idioma y distribución especificados. Los mapeos de teclas pueden variar dependiendo del teclado y la configuración regional.

* * *
## Casos de Uso
1. **Registro de Entradas:**
    - Caso: El usuario presiona varias teclas, incluyendo letras, números y caracteres especiales.
    - Resultado Esperado: Todas las entradas se registran en el archivo de log con el formato correspondiente a las teclas presionadas.

2. **Teclas Especiales:**
   - Caso: El usuario presiona Shift, Caps Lock o Alt Gr junto con otras teclas.
   - Resultado Esperado: El keylogger maneja y registra las combinaciones de teclas especiales correctamente, reflejando el carácter adecuado en el archivo de log.

3. **Verificación de Mapeo:**
    - Caso: El usuario presiona diferentes combinaciones de teclas para verificar el mapeo.
    - Resultado Esperado: Los caracteres en el archivo de log corresponden correctamente a las teclas presionadas, incluyendo caracteres especiales obtenidos con Alt Gr.

* * *
## Notas
- Seguridad: Este programa es una herramienta de aprendizaje. El uso de keyloggers en entornos no autorizados puede ser ilegal. Asegúrate de usar este software solo en entornos controlados y con permisos adecuados.

* * *
## Contacto
  ###### Elaborado por Axel Quijano para la materia de Seguridad Informatica de FES Aragon
  ###### Contactar en caso cualquier duda a axelquijano25@aragon.unam.mx
