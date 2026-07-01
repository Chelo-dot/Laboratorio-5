# Laboratorio-5 Memoria Dinámica y Estructuras de Datos

Daniel Castro (C21931), Sofía Castro (C5D998) y Marcelo Villalobos (C5K960)

## Descripción

El objetivo fue implementar diferentes estructuras de datos utilizando **memoria dinámica**, además de aplicar conceptos de **proyectos colaborativos** mediente la plataforma Git y el uso de **branches** para el desarrollo de las difenteres funciones.

Se desarrollaron las siguientes estructuras:

- Listas enlazadas
- Listas doblemente enlazadas
- Arreglos dinámicos
- Stack

## Funcionalidades implementadas

Dependiendo de la estructura de datos, se implementaron funciones como:

- Crear
- Insertar elemento
- Eliminar elemento
- Buscar elemento
- Imprimir el contenido
- Liberar la memoria utilizada
- Otras funciones auxiliares necesarias para el funcionamiento de cada estructura

## Estructura del repositorio

```
.
├── include/
│   ├── arreglos.h
│   ├── listas.h
│   ├── dlista.h
│   └── stack_arr.h
│
├── src/
│   ├── arreglos.c
│   ├── listas.c
│   ├── dlista.c
│   └── stack_arr.c
│
├── main.c
├── Makefile
└── README.md
```

### Descripción de los archivos

| Archivo/Directorio | Descripción |
|--------------------|-------------|
| `main.c` | Contiene un ejemplo de uso de todas las estructuras de datos implementadas. |
| `src/` | Implementación de las funciones correspondientes a cada estructura de datos. |
| `include/` | Header files con las declaraciones de funciones y estructuras. |
| `Makefile` | Compilación del proyecyo. |

## Compilación

Primero, debe crear un copia del repositorio:

```bash
git clone https://github.com/Chelo-dot/Laboratorio-5.git
```

Para compilar el proyecto, abra una terminal en el directorio del repositorio y ejecute:

```bash
make
```

Si la compilación es exitosa, se generará el ejecutable llamado:

```text
programa
```

## Ejecución

Para ejecutar el programa:

```bash
./programa
```
