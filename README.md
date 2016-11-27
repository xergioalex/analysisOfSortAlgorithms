# Analisis de algoritmos de ordenamiento

## 1. Definición y procedimiento

Como parte de un ejercicio típico de algoritmia en la Universidad, hice un pequeño análisis comparativo de los algoritmos de ordenamiento más populares, buscando estudiar la complejidad de cada uno de ellos y como las diferentes formas de resolver un mismo problema pueden afectar los tiempos de ejecución. Quiero aclarar que este es solo un análisis academíco muy simple que quiero documentar, el cual tal vez sirva a futuro para otros estudiantes de ciencias de la computación.

Comence desarrollando un pequeño script en Java que permite generar numeros aleatorios de cinco digitos y almacenarlos en un archivo de texto, esto con el fin de poder analizar el mismo conjunto de datos entre los diferentes algoritmos; el script correspondiente lo puede hallar y ejecutar de la siguiente forma:

```
# Ruta del archivo
> algorithms/java/RandomNumbers.java

# Ejecutar script en Java
$ javac RandomNumbers.java && java RandomNumbers
```

Lo anterior generará el archivo de texto **numbers/numbers.txt** con *n* numeros aleatorios que se especifiquen dentro del script de Java; dentro de mis experimentos el archivo que generé fue de 1.000.000.000 millones de datos, el cual no adjunto en el repositorio debido a que termino pesando cerca de 5 GB.

En un paso siguiente procedí a implementar los algoritmos de ordenamiento:
* **[Burbuja (Bubble Sort)](https://es.wikipedia.org/wiki/Ordenamiento_de_burbuja):** Complejidad O(n^2)
* **[Conteo (Counting Sort)](https://es.wikipedia.org/wiki/Ordenamiento_por_cuentas):** Complejidad O(n+k)
* **[Montones (Heapsort)](https://es.wikipedia.org/wiki/Heapsort):** Complejidad O(n log n )
* **[Inserción (Insertion Sort)](https://es.wikipedia.org/wiki/Ordenamiento_por_inserci%C3%B3n):** Complejidad O(n^2)
* **[Mezclas (Merge Sort)](https://es.wikipedia.org/wiki/Ordenamiento_por_mezcla):** Complejidad O(n log n).
* **[Rápido (Quicksort)](https://es.wikipedia.org/wiki/Quicksort):** Complejidad O(n log n).
* **[Selección (Selection Sort)](https://es.wikipedia.org/wiki/Ordenamiento_por_selecci%C3%B3n):** Complejidad O(n^2).

Para esta tarea seleccione el lenguaje C y los scripts obtenidos los pueden encontrar en **algorithms/c/sortAlgorithms**

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

Finalmente procedo a configurar el servidor asegurandome de tener los compiladores tanto de Java y C; pueden encontrar el archivo de aprovisionamiento que corri en cada uno de los servidores en **ServerConfig/provision.sh**.

```
# Base installation
sudo apt-get update -y
sudo apt-get upgrade -y
sudo apt-get install -y build-essential gcc python-dev python-pip python-setuptools

# Git
sudo apt-get install -y git

# Install Java
sudo apt-get install default-jre -y
sudo apt-get install default-jdk -y
sudo apt-get install openjdk-7-jre -y
sudo apt-get install openjdk-7-jdk -y
```

## 2. Resultados

En cada maquina se corrieron las pruebas con el mismo archivo de numeros aleatorios a ordenar, en intervalos inicialmente de 10 en 10, luego 100 en 100, luego 1.000, luego 10.000 etc, hasta 1.000.000.000 de datos; estos resultados se pueden visualizar en el archivo **results/analysis.ods**.

Al cabo de 3 o 4 días de haber lanzado el archivo **runTest.c**, revise que las pruebas y apenas iban en 1.600.000 de datos, me parecio que era suficiente para sacar conclusiones así que decidí parar el experimento en ambos servidores, y ahora procedo a mostrar los resultados obtenidos comparando los tiempos de respuesta de cada algoritmo en cada maquina:

#### 2.1. Burbuja (Bubble Sort)
![Burbuja (Bubble Sort)](media/bubbleSort.png)

#### 2.2. Conteo (Counting Sort)
![Conteo (Counting Sort)](media/countingSort.png)

#### 2.3. Montones (Heapsort)
![Montones (Heapsort)](media/heapSort.png)

#### 2.4. Inserción (Insertion Sort)
![Inserción (Insertion Sort)](media/insertionSort.png)

#### 2.5. Mezclas (Merge Sort)
![Mezclas (Merge Sort)](media/mergeSort.png)

#### 2.6. Rápido (Quicksort)
![Rápido (Quicksort)](media/quickSort.png)

#### 2.7. Selección (Selection Sort)
![Selección (Selection Sort)](media/selectionSort.png)









