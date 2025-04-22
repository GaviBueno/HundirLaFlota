# Proyecto del Segundo Cuatrimestre Fundamentos de Programación (Curso 22/23)
Autor: Gabriel Bueno Reyes              
UVUS: CMB8064

Este proyecto (aún en desarrollo) define el objeto Jardineria y sus propiedades. 
El archivo CSV de este proyecto es "jardinería_50_Java".

## Estructura de las carpetas del proyecto

* **/src**: Contiene los diferentes archivos que forman parte del proyecto. Debe estar estructurado en los siguentes paquetes:
  * **fp.jardinerias**: Paquete que contiene los tipos del proyecto.
  * **fp.common**: Paquete que contiene los tipos auxiliares del proyecto
  * **fp.utiles**:  Paquete que contiene las clases de utilidad. 
  * **test.jardinerias**: Paquete que contiene las clases de test del proyecto.
* **/data**: Contiene el dataset del proyecto
    * **jardinería_50_Java.csv**: Archivo csv que contiene los datos registrados por una compañía encargada de realizar trabajos de jardinería.
    
## Estructura del *dataset*

Cada fila del dataset recoge diferentes datos de los trabajos realizados por una compañía que desempeña el mantenimiento de jardines. Cada trabajo registra 9 datos.

El dataset está compuesto por 9 columnas, con la siguiente descripción:

* **Calle**: de tipo String, indica la calle donde se realizó el trabajo.
* **Numero**: de tipo Integer, dice cual es el número de la casa o edificio donde fue hecho el trabajo.
* **Fecha**: de tipo LocalDate, señala la fecha en la que se elaboro el trabajo.
* **Hora**: de tipo LocalTime, representa la hora en la cual se empezó a trabajar.
* **Importe**: de tipo Double, indica la factura que pago el cliente.
* **Nro. jardineros**: de tipo Integer, señala el número de jardineros que fueron necesarios para hacer el trabajo.
* **Trabajos realizados**: de tipo List\<String>, representa los trabajos que se realizaron. La compañía lleva a cabo los siguientes trabajos:
  * _Poda_
  * _Cesped_
  * _Abonado_
  * _Fitosanitarios_
* **Contrato de mantenimiento**: de tipo Boolean, indica si el cliente tiene un contrato para cuidar su jardín:
  * _N_: Simboliza que el cliente no tiene un contrato y, por ende, representa el valor *false*.
  * _S_: Representa que el propietario tiene un contrato y, además, simboliza el valor *true*.
* **Propietario vivienda**: de tipo Propietario, nos dice quien es el propietario del jardín, es decir, el cliente. Para ello nos proporciona los siguientes datos:
  * _Apellidos_: Los dos apellidos del propietario.
  * _Nombre_: El nombre del propietario.
  * _NIF_: El DNI o el NIE del propietario.

## Tipos implementados

Los tipos que se han implementado en el proyecto son los siguientes:

### Tipo Base - Jardineria
Representa un trabajos realizados por la compañía.

**Propiedades**:
- _calle_, de tipo String, consultable. Indica la calle donde se realizó el trabajo.
- _numero_, de tipo Integer, consultable. Dice cual es el número de la casa o edificio donde fue hecho el trabajo.
- _fecha_, de tipo LocalDate, consultable. Señala la fecha en la que se elaboro el trabajo.
- _hora_, de tipo LocalTime, consultable. Representa la hora en la cual se empezó a trabajar.
- _importe_, de tipo Double, consultable y modificable. Indica la factura que pago el cliente.
- _nJardineros_, de tipo Integer, consultable y modificable. Señala el número de jardineros que estuvieron haciendo el trabajo.
- _trabajoRealizado_, de tipo List\<String>, consultable. Representa los trabajos que se realizaron.
- _contratoMantenimiento_, de tipo Boolean, consultable. Indica si el cliente tiene un contrato para cuidar su jardín.
- _propietario_, de tipo Propietario, consultable. Nos dice quien es el propietario del jardín.

**Constructores**: 

- C1: Tiene un parámetro por cada propiedad primitiva.
- C2: Crea un objeto de tipo Jardineria a partir de los siguientes parámetros: String calle, Integer numero, LocalDate fecha, LocalTime hora, Double importe, Integer nJardineros. Asignandole a las restantes propiedades primitivas los siguientes parámetros predefinidos:
  - List\<String> trabajoRealizado: se le dará una lista vacía.
  - Boolean contratoMantenimiento: se le aplicará el valor *false*.
  - Propietario propietario: tendrá como parámetro predefinido *null*.

**Restricciones**:
 
- R1: La fecha no puede ser mayor que la actual.
- R2: El número de jardinero no puede ser negativo.

**Criterio de igualdad**: Dos objetos de tipo Jardineria son iguales si su _calle_, _numero_ y _fecha_ coinciden.

**Criterio de ordenación**: Los objetos de tipo Jardineria se ordenan según sus propiedades primitivas: _fecha_, _hora_ y _nJardineros_. Debe tenerse en cuenta que, si empatan por la propiedad que se indica primero, desempatan por la segunda y si es necesario desempatan por la tercera.

**Otras operaciones**:
 
-	_Integer getNumTrabajos()_: Propiedad derivada que nos permite ver con facilidad el número de trabajos que se han realizado.
-	_String toString()_: Método que nos permite presentar al objeto de tipo Jardineria como una cadena de texto.

#### **Tipos auxiliares**
- _Propietario_, record. Formado por las propiedades: String apellidos, String nombre, String nif; permite que la propiedad primitiva *propietario* del objeto de tipo Jardineria tome los tres parámetros que le corresponden y los organice de la forma específicada (siguiendo el orden: apellidos, nombre y NIF; todos ellos separados por una coma).