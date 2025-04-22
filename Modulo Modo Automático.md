# **Módulo: Programación del modo automático (IA)**

**Autor: Gabriel Bueno Reyes**              

## **1. Objetivo General**

El objetivo de este conjunto de funciones es implementar un sistema automatizado para seleccionar y disparar coordenadas de forma eficiente en el juego "Hundir la Flota".

Se estructura en torno a dos modos de funcionamiento: un modo aleatorio inicial, y un "modo cazador", que activa una lógica más compleja tras detectar un impacto en un barco enemigo. El sistema está orientado a reducir el número de disparos necesarios para localizar y hundir completamente las naves enemigas.


## **2. Estructuras y Variables Principales**

- `Coordenada`: estructura que representa una posición del mapa mediante dos enteros: **x** e **y**.
- `coord[]`: array de coordenadas que representa todas las posiciones del tablero, así como estados de memoria auxiliar (como la posición anterior impactada).
- `coord[80]`: se utiliza como espacio de almacenamiento para coordinar la lógica del modo cazador (registro del primer impacto).
- `tam_mapa`: dimensión del tablero (se asume cuadrado).
- Funciones auxiliares como **barajar**, **marcarAgua**, **reordenarDespuesDeTocado** y **marcarContornoBarcoHundido** gestionan la manipulación de la matriz de coordenadas y el entorno del disparo.


## **3. Funciones Principales**

### **3.1. `inicializar()`**
Inicializa el array de coordenadas si aún no ha sido preparado, rellenándolo con todas las combinaciones posibles de **(x,y)** dentro del tablero. Posteriormente, utiliza el algoritmo de **Fisher-Yates** para barajar aleatoriamente el orden de las coordenadas, garantizando así disparos no repetitivos y desordenados.

**Parámetros**:
- _tam_mapa_, de tipo Integer. Indica el tamaño de uno de los lados del tablero.
- _coord[]_, array estático conformado por elementos de la estructura Coordenada. En él se guardaran las coordenadas sobre las que el modo automático trabajará para disparar y localizar los barcos.

### **3.2. `cazador()`**
Activa un disparo inteligente tras un acierto para detectar si hay más partes del barco adyacentes. Su lógica está dividida en tres fases:

- **Fase 1: Impacto inicial**
  - Si el disparo da en un barco, se registra su posición en *coord[80]* y se reorganiza el array de coordenadas para priorizar las adyacentes con *reordenarDespuesDeTocado*.

- **Fase 2: Dirección del cazador**
  - El sistema identifica si debe explorar en sentido horizontal, vertical o diagonal, según el patrón de los impactos previos, y ajusta *coord[80]* con signos para reflejar la orientación de búsqueda.
  - Explora en la dirección inicial hasta que encuentra agua, un nuevo impacto, o alcanza los límites del mapa. Si encuentra agua, invierte la dirección (*-z.y*) para seguir buscando en la dirección opuesta.

- **Fase 3: Fin del rastreo**
  - Si se localiza el final del barco (es decir, se hunde), se marca su contorno como agua, se actualiza el mapa de coordenadas, se barajan de nuevo las opciones y se llama de forma recursiva a *cazador* para que continue la búsqueda.

**Parámetros**:
- _tam_mapa_, de tipo Integer. Indica el tamaño de uno de los lados del tablero.
- _coord[]_, vector estático conformado por elementos de la estructura Coordenada. En él se guardaran las coordenadas sobre las que el modo automático trabajará para disparar y localizar los barcos.

## **4. Funciones Auxiliares**

### **4.1. `barajar()`**
Implementa el algoritmo de **Fisher-Yates** para desordenar aleatoriamente el array *coord*, con el objetivo de dar imprevisibilidad al modo automatico. Este método es utilizado tanto por inicializar como por el cazador. 

**Parámetros**:
- _coord[]_, vector estático conformado por elementos de estructura Coordenada. En él se guardaran las coordenadas sobre las que el modo automático trabajará para disparar y localizar los barcos.
- _total_, de tipo Integer. Indica el área del tablero.

### **4.2. `jugador()`**
Selecciona la siguiente coordenada válida (es decir, que no haya sido disparada previamente). Este método es solo utilizado por el cazador y devuelve una estructura Coordenada.

**Parámetros**:
- _tam_mapa_, de tipo Integer. Indica el tamaño de uno de los lados del tablero.
- _coord[]_, vector estático conformado por elementos de estructura Coordenada. En él se guardaran las coordenadas sobre las que el modo automático trabajará para disparar y localizar los barcos.

### **4.3. `marcarAgua()`**
Invalida una coordenada que ha sido disparada al agua, estableciendo sus valores en *(0,0)*.

**Parámetros**:
- _tam_mapa_, de tipo Integer. Indica el tamaño de uno de los lados del tablero.
- _c_, estructura Coordenada. Indica la coordenada que queremos invalidar. 
- _coord[]_, vector estático conformado por elementos de estructura Coordenada. En él se guardaran las coordenadas sobre las que el modo automático trabajará para disparar y localizar los barcos.

### **4.4. `reordenarDespuesDeTocado()`**
Tras impactar en un barco, reorganiza las coordenadas que rodean ese punto, moviéndolas al principio del array. Esto permite priorizar la búsqueda en las posiciones adyacentes para seguir con la búsqueda del barco antes de continuar con disparos aleatorios.

**Parámetros**:
- _tam_mapa_, de tipo Integer. Indica el tamaño de uno de los lados del tablero.
- _tocado_, estructura Coordenada. Indica la coordenada donde hemos localizado parte del barco. 
- _coord[]_, vector estático conformado por elementos de estructura Coordenada. En él se guardaran las coordenadas sobre las que el modo automático trabajará para disparar y localizar los barcos.

### **4.5. `marcarContornoBarcoHundido()`**
Marca como inválidas las posiciones adyacentes al barco hundido, siguiendo las reglas del juego clásico para asegurar que no hay barcos contiguos.

**Parámetros**:
- _fin_, estructura Coordenada. Última posición a la que se ha disparado al barco antes de hundirlo.
- _inicio_, estructura Coordenada. Primera posición a la que se ha disparado al barco.
- _tam_mapa_, de tipo Integer. Indica el tamaño de uno de los lados del tablero.
- _coord[]_, vector estático conformado por elementos de estructura Coordenada. En él se guardaran las coordenadas sobre las que el modo automático trabajará para disparar y localizar los barcos.
### **4.6. `marcarAlrededor()`**
Marca como inválidas las posiciones adyacentes a una parte del barco hundido. Sirve como auxiliar para *marcarContornoBarcoHundido*.

**Parámetros**:
- _x_, de tipo Integer. Indica la posición x de la parte tocada del barco hundido.
- _y_, de tipo Integer. Indica la posición y de la parte tocada del barco hundido.
- _tam_, de tipo Integer. Indica el tamaño de uno de los lados del tablero.
- _coord[]_, vector estático conformado por elementos de estructura Coordenada. En él se guardaran las coordenadas sobre las que el modo automático trabajará para disparar y localizar los barcos.