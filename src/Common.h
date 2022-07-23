
/**
 * \mainpage
 * # Proyecto 02 Programación II - Monster-Flag-Eater Game

### Crear un juego gráfico que implemente el uso de herencia y polimorfismo

El usuario inicializa el juego y se le muestra si quiere jugar. Una vez que el usuario dice si, se le muestra el primer nivel. El objetivo de cada nivel es que el personaje llegue a la bandera. El nivel va a tener obstáculos como paredes, cajas que se empujan, cajas que se jalan y suelo resbalozo. El usuario tiene que ingeniarselas para llegar a la bandera. 
Una vez que llega a la bandera se le muestra un nuevo nivel con distinto acomodamiento de  los objetos.

Además, el README debe proveer ayuda  al usuario para saber cómo instalarlo y comandos que se pueden usar dentro del juego. Se debe llevar un control de versiones a través de repositorios de Git. El programa debe imprimir la versión que se encuentra o el mensaje de ayuda si se pide.

## Narrativa
El "monstruo" come-banderas al despertarse reconocio que su unico objetivo en la vida era llegar a comer mas y mas banderas. Para mala fortuna de el, no sabe como funcionan los objetos y estaria 
completamente perdido sin su ayuda. Podran juntos dominar el mundo? O mas precisamente las banderas del mundo? 

## Objetivo
El objetivo es completar todos los niveles que se presenten. Un nivel se completa cuando el personaje llega hasta la bandera.

## Reglas del juego
El jugador tiene control de un personaje.
El personaje solo se puede mover en cuatro direcciones. Arriba, abajo, derecha o izquierda.
Un nivel se completa cuando el personaje llega a la bandera.
El personaje no se puede salir de la matriz.
El personaje no puede ni empujar, ni jalar paredes.
El personaje solo puede empujar cajas rojas.
El personaje solo puede jalar cajas azules.
El personaje cuando se intenta mover en suelo resbaloso, continua moviendose hasta que tope con pared o con una caja.
El nivel se puede resetear con la tecla 'R'.

## Caso normal de uso
Curso normal:	
1. El sistema carga los elementos del nivel: MainCharacter, PushBox, IceFloor, Wall, Flag, EmptyLot.
2. El jugador presiona las teclas de flecha para mover el personaje una posicion.
3. El systema mueve al personaje de acuerdo con la direccion de la flecha.
4. Si el personaje choca con una pared, no se mueve.
5. Si el personaje choca contra una caja, la empuja y el adquiere la posicion de la caja.
6. Si el personaje se mueve en piso resbaloso, continua su movimiento hasta encontrar una casilla vacia o una pared.
7. Si el personaje come la bandera, gana el nivel.
8. Si el usuario presiona la tecla 'R', el nivel se resetea.
9. Si 'M' le presentemos el menu para dejar de jugar.


## Equipo de desarrollo

* **Juan Ignacio Pacheco**
* **David Xie Li**

Este proyecto es parte del curso de CI-0113 Programacion II de la Universidad de Costa Rica.
Realizado durante el primer semestre del año 2020. 

## Para crear niveles
La matriz con la que se crean niveles siempres va a ser una matriz de 5 filas y 6 columnas. Se tiene que especificar en las primeras dos lineas las coordenadas del personaje principal y de la bandera,
respectivamente. Procede a poner los siguientes caracteres y se al leerlo se crea el nivel.

## Symbologia letra para interfaz en línea de comandos:
1. M = Maincharacter
2. S = puShbox
3. . = Emptyslot
4. F = Flag
5. W = Wall
6. '*' = IceFloor

## Licencia

CC BY Proyecto 02 Programación II - Monster Flag Eater Game

 */ 

#ifndef COMMON_H
#define COMMON_H

#define DECLARE_RULE5(Class, action) \
    Class(const Class& other) = action; \
    Class(Class&& other) = action; \
    Class& operator=(const Class& other) = action; \
    Class& operator=(Class&& other) = action

#define DISABLE_COPY(Class) \
    DECLARE_RULE5(Class, delete)

#endif // COMMON_H
