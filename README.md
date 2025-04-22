# **Hundir la Flota – Implementación modular en lenguaje C**

----

**Universidad de Cádiz – Escuela Superior de Ingeniería**  
**Grado en Ingeniería Informática**  
**Asignatura:** Metodología de la Programación

---

## **1. Descripción general del proyecto**

El presente trabajo tiene como objetivo el diseño e implementación modular del clásico juego **"Hundir la Flota"** utilizando el lenguaje de programación C. La aplicación debe contemplar una arquitectura clara, compuesta por varios módulos funcionales que resuelvan de manera eficiente las distintas partes del juego: carga de datos, jugabilidad, lógica de IA, configuración y persistencia de información.

Cada jugador dispondrá de dos tableros cuadrados de tamaño `n x n`, configurable al inicio de la partida:  
- Uno para posicionar sus propios barcos.  
- Otro para registrar sus disparos contra la flota enemiga.

Los barcos utilizados en el juego podrán comprobarse en un archivo externo `Barcos.txt`, que incluirá el tamaño de cada uno. 

---

## **2. Restricciones y requisitos**

- El lenguaje de programación será **C**.
- **Uso obligatorio de memoria dinámica**.
- **No se permitirá el uso de variables globales**.
- Deberán implementarse dos modos de juego:  
  - **Multijugador local**.  
  - **Jugador contra IA (modo automático)**.
- El sistema debe incluir las siguientes funcionalidades:
  - Opción para generación aleatoria o manual del tablero.
  - El jugador repite turno tras obtener resultado **Tocado** o **Hundido**, hasta que dispare y obtenga **Agua**.
  - Mostrar el disparo realizado y su resultado tras cada turno.
  - Visualización completa de ambos tableros en cada jugada.
  - Guardado automático de los resultados al finalizar la partida.
  - Opción para consultar el historial de resultados desde el menú principal.
  - Funcionalidad de **reinicio de partida**, eliminando:
    - Tableros.
    - Disparos realizados.
    - Resultado (ganador/perdedor).
  - Todos los datos configurables de la partida deben almacenarse en el fichero `Juego.txt`.
  - Los barcos podrán colocarse en horizontal, vertical o diagonal, pero nunca podrán estar adyacentes entre sí: deben estar rodeados de agua o borde del tablero.
  - La partida se desarrollará en varias rondas por turnos hasta que una de las flotas quede completamente destruida.

---

### **4. Miembros del equipo de trabajo**

- *Manuel Vicente Bermúdez Sosa*
- *George Octavian Castillo Florescu*
- *Gabriel Bueno Reyes*

---

## **5. Organigrama de descomposición modular**

El trabajo ha sido descompuesto en tres módulos principales, cada uno asignado a un miembro del equipo. Esta descomposición permite una distribución funcional coherente, facilitando el desarrollo paralelo y la integración modular del sistema.

| Módulo                        | Responsable                          |
|------------------------------|--------------------------------------|
| Tablero y Jugabilidad        | George Octavian Castillo Florescu    |
| Programación del Modo Automático (IA) | Gabriel Bueno Reyes              |
| Configuración y Guardado     | Manuel Vicente Bermúdez Sosa         |

---

## **6. Descripción de módulos**

### **6.1. Módulo: Tablero y Jugabilidad**  
**Responsable: George Octavian Castillo Florescu**

Este módulo se encarga de la gestión de los distintos tipos de tablero y la implementación de la jugabilidad. Incluye:
- Estructuras para representar los tableros.
- Lógica para la inserción válida de barcos.
- Validación de reglas del juego (posición, tamaño y separación de barcos).
- Control del flujo de turnos y verificación de disparos.
- Visualización gráfica del estado actual de los tableros.

### **6.2. Módulo: Programación del modo automático (IA)**  
**Responsable: Gabriel Bueno Reyes**

Este módulo contiene la implementación de una Inteligencia Artificial básica que permita al jugador enfrentarse contra la máquina.  
La IA está diseñada para ser mínimamente competente y seguir un patrón de búsqueda optimizado tras un impacto, mejorando la eficiencia de sus disparos en relación a un algoritmo puramente aleatorio. Se contemplan:
- Estrategias de exploración.
- Reacción inteligente tras un impacto.
- Selección de disparos en zonas no redundantes.

### **6.3. Módulo: Configuración y Guardado**  
**Responsable: Manuel Vicente Bermúdez Sosa**

Este módulo está dedicado a la gestión de la configuración y persistencia de los datos de la partida. Abarca:
- Lectura de configuraciones previas desde el fichero `Juego.txt`.
- Creación manual del tablero y colocación de barcos.
- Guardado de progreso y resultados de partidas.
- Opción de carga de partida.
- Función de reinicio que borre adecuadamente los datos almacenados, restaurando el juego a su estado inicial.