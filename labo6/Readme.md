## Algoritmos 2 -- Labo 3 -- Ejercitación

Fecha de entrega: 1/10

### Consigna

1) Implementar un conjunto genérico y testearlo. 

* Elegir una representación y agregarla a la parte privada de la clase Conjunto
* Implementar todos los métodos de Conjunto sobre la estructura elegida
* Escribir tests minimales para cada funcionalidad para extender los que ya existen 

2) Entregar a algo2.dc+taller3@gmail.com

* Adjuntar los archivos Conjunto.h y Conjunto.inl

### Instrucciones

* Bajarse el zip con la consigna a una carpeta 
* Importar el proyecto en CLion
* Codear!

### Aclaraciones
El proyecto tal como está no compila. La idea es que escriban los métodos en el .iml; siendo una clase con templates no se pueden implementar en un .cpp

Pueden hacer los métodos iterativos o recursivos. Pueden agregarle a los nodos un puntero al padre si lo necesitan.

Las complejidades pedidas son:
* Crear y cantidad: O(1)
* Insertar, eliminar, pertenece, siguiente, mínimo, máximo: O(la altura del arbol), es decir, O(N) peor caso, O(log N) caso promedio.
* Mostrar: O(N)
