## RotaL
# IASI Proyect

**Resumen del problema de la práctica.**

La práctica consiste en implementar dos técnicas de búsqueda, explicadas en clase, capaces 
de encontrar una solución desde un tablero origen a uno destino. En este destacaremos varias 
partes:

- Dos piezas en forma de L, una de origen y otra de destino, cada una contendrá cuatro 
casillas y diferenciaremos una de la otra a partir del valor de las casillas que la 
conforman. El valor dos para identificar las casillas de la pieza origen y el tres para las de 
destino.
- Una serie de casillas establecidas con el valor uno, estas se dispondrán alrededor del 
tablero, delimitando el mismo, y además se podrán encontrar aleatoriamente en el 
interior del tablero, dificultando el paso e incluso imposibilitando la llegada de la pieza 
inicial a la de destino, simulando la función de un muro.
- El resto de las casillas definidas a cero, estas serán utilizadas en la generación de los
distintos caminos a realizar por la pieza, con la finalidad de encontrar el destino.
Para finalizar, mencionar que la pieza origen solo podrá desplazarse por el tablero mediante
los movimientos: rotación en sentido horario, desplazamiento hacia la derecha e izquierda y 
desplazamiento hacia arriba y abajo.
