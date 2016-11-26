# Analisis de algoritmos de ordenamiento

Como parte de un ejercicio típico de algoritmia en la Universidad, hice un pequeño análisis comparativo de los algoritmos de ordenamiento más populares, buscando estudiar la complejidad de cada uno de ellos y como las diferentes formas de resolver un mismo problema pueden afectar los tiempos de ejecución.

Comence desarrollando un pequeño script en Java que permite generar numeros aleatorios de cinco digitos y almacenarlos en un archivo de texto, esto con el fin de poder analizar el mismo conjunto de datos entre los diferentes algoritmos; el script correspondiente lo puede hallar y ejecutar de la siguiente forma:

```
# Ruta del archivo
> algorithms/java/RandomNumbers.java

# Ejecutar script en Java
$ javac RandomNumbers.java && java RandomNumbers
```

Lo anterior generará el archivo de texto **numbers/numbers.txt** con *n* numeros aleatorios que se especifiquen dentro del script de Java; dentro de mis experimentos el archivo que generé fue de 1.000.000.000 millones de datos, el cual no adjunto en el repositorio debido a que termino pesando cerca de 5 GB.

En un paso siguiente procedí a implementar los algoritmos de ordenamiento **burbuja (Bubble Sort), conteo (Counting Sort), montones (HeapSort), inserción (Insertion Sort), mezclas (Merge Sort) y selección (Selection Sort)**; para esta tarea seleccione el lenguaje C y los scripts obtenidos los pueden encontrar en **algorithms/c/sortAlgorithms**.

Por último, dado que para hacer un buen análisis se deben correr muchas pruebas, cree un par de scripts que me permitieran automatizarlas de forma tal que se pudieran correr de forma continua sin intervención, estos son:

```
# Archivo desde el cual se puede correr cualquiera de los algoritmos implementados y permite crear arreglos de forma dinámica con base a la cantidad de elementos a ordenar. Este script además genera dos archivos de salida en el folder "results" con logs sobre los tiempos de ejecución del algoritmo
> algorithms/c/benchmark.c

# Correr prueba
# arg1, arg2 => Son el tipo (nombre) del algoritmo y la cantidad de elementos a probar
$ gcc benchmark.c -o benchmark.out && ./benchmark.out arg1 arg2

---

# El script runtTest.c permite correr multiples pruebas para los diferentes algoritimos y diferentes cantidades de datos haciendo uso del script anterior
> algorithms/c/runTest.c

# Correr pruebas
$ gcc runTest.c -o runTest.out && ./runTest.out
```

En este punto ya tenemos todo listo para hacer las pruebas, solo necesitamos poner a correr nuestro archivo *runtTest.c* en alguna maquina, y dado que esto es un simple ejercicio académico no requiere de mucho rigor científico, pero procure crear un pequeño ambiente controlado en un par de servidores donde no estuvieran ejecutandose en paralelo otras tareas, dado que los tiempos de ejecución de cada prueba puede verse afectado al estar compartiendo recursos con otros procesos.

Dicho lo anterior cree dos **droplets** (término para llamar a servidores en la nube) en
[Digital Ocean](https://www.digitalocean.com/pricing/), los cuales corresponden a:

![digital ocean droplets](media/digitalOceanDroplets.png)

Como se puede observar en la imagen anterior, el segundo servidor posee el doble de capacidades de procesamiento, con lo cual se espera obtener un mejor rendimiento en las pruebas.












