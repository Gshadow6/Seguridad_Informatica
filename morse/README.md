# Codificar/Decodificar Código Morse

## Historia

El código Morse fue desarrollado en la década de 1830 por Samuel Morse y Alfred Vail como un método para transmitir mensajes a través de telégrafos eléctricos. Este sistema usa secuencias de puntos y rayas para representar letras y números. Originalmente empleado para comunicaciones telegráficas a larga distancia, el código Morse ha sido fundamental en la evolución de las telecomunicaciones y sigue siendo utilizado en diversas aplicaciones, incluyendo la radioafición y la señalización de emergencia.

## ¿Cómo se usa?

1. **Clona el repositorio**

   Para obtener el código fuente, primero clona el repositorio con el siguiente comando:

   ```git clone https://github.com/ferpalma21/morse.git```

2. **Instala Dependencias**
Asegúrate de tener Python 3 instalado.

3. **Uso del script**
Navega al directorio del proyecto:

```python3 morse.py "cadena_a_codificar"```

Donde ```cadena_a_codificar``` es el texto que deseas convertir a código Morse.

Para decodificar un mensaje en código Morse, utiliza el argumento -d:
```python3 morse.py -d "cadena_a_decodificar"```

## Ejemplos

Codificar:
```python3 morse.py "HELLO WORLD"```

Salida esperada:
```.... . .-.. .-.. ---   .-- --- .-. .-.. -..```

Decodificación:
```python3 morse.py -d ".... . .-.. .-.. ---   .-- --- .-. .-.. -.."```

Salida esperada
```HELLO WORLD```
