# Para empezar 

1. Descomprimir el zip a una carpeta
2. (Opcional) Desde CLion, ir a File -> Import Project, "Open Project".
 Una vez que termina la carga del proyecto, para correr los tests, 
 elegir "correrTests" desde la esquina superior derecha y 
 hacer click en el botón Play.
 
# Cómo correr los tests desde la línea de comandos (si no usan CLion)

1. mkdir build && cd build
2. cmake ..
3. make
4. ./tests/correrTests

Para volver a compilar, simplemente correr "make" de nuevo.

En caso de que no funcione correctamente la compilación, pueden borrar 
el directorio "build" y volver a realizar los 4 pasos.

