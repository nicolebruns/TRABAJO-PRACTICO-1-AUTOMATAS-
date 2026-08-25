# Trabajo Práctico 1 - Autómatas

 Integrantes : Nicole Brunstein
 Curso : K2002
 Docente : Ing.Roxana Leituz

## Ejercicio 1
### Decisiones tomadas
Para la resolución de este ejercicio del TP tuvimos que tomar ciertas decisiones sobre algunos casos que no estaban especificados en la consigna. A continuación, listamos las decisiones tomadas:

- Notación octal: decidimos representar los octales con un 0 inicial y al menos un dígito más entre 0 y 7.
Ej.: 07, 012, 077.
- Notación hexadecimal: decidimos usar el prefijo 0x o 0X.
Ej.: 0xAF, 0X25.
- El 0 solo: decidimos considerarlo decimal y no octal.
- Letras hexadecimales: decidimos aceptar tanto mayúsculas como minúsculas: A..F y a..f.
- 08 y 09: como un número que comienza con 0 intenta reconocerse como octal, decidimos que estos casos sean considerados error léxico, en lugar de interpretarlos como decimales.
- 0x sin dígitos posteriores: decidimos que sea inválido. Después de 0x o 0X debe aparecer al menos un dígito hexadecimal.
- Separador final: decidimos que una cadena como 12@07@ sea inválida, ya que interpretamos @ como separador entre dos constantes y, por lo tanto, después de él debe comenzar otra.
### Autómata

### Definición formal

### Tabla de transiciones

### Implementación

### Casos de prueba

## Ejercicio 2

...

## Ejercicio 3

...

## Instructivo
