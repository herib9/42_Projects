# C++ — Temario Completo CPP01
## Ejercicios 00 y 01 — Memoria dinámica en profundidad

---

# ÍNDICE

1. La memoria RAM — mapa completo
2. El Stack — cómo funciona en detalle
3. El Heap — cómo funciona en detalle
4. Stack vs Heap — la decisión
5. `new` — crear objetos en el heap
6. `delete` — destruir objetos del heap
7. El ciclo de vida completo de un objeto
8. Funciones libres vs métodos de clase
9. Devolver punteros desde funciones
10. Los peligros de la memoria dinámica
11. `new[]` — crear arrays en el heap
12. `delete[]` — destruir arrays del heap
13. El constructor por defecto y `new[]`
14. Recorrer y usar arrays dinámicos
15. Glosario completo

---

# PARTE 1 — LA MEMORIA (ex00: BraiiiiiiinnnzzzZ)

---

## 1. La memoria RAM — mapa completo

Cuando ejecutas un programa, el sistema operativo le asigna un bloque de memoria RAM. Ese bloque no es una masa homogénea — está dividido en zonas con funciones muy distintas.

```
MEMORIA RAM de tu programa
+========================+  <- dirección alta (números grandes)
|                        |
|        STACK           |  crece hacia abajo conforme entras en funciones
|          |             |
|          v             |
|                        |
|    (espacio libre)     |  zona sin usar entre stack y heap
|                        |
|          ^             |
|          |             |
|        HEAP            |  crece hacia arriba conforme reservas con new
|                        |
+------------------------+
|  variables globales    |  viven durante toda la ejecución
|  variables estáticas   |
+------------------------+
|  código (.text)        |  el código compilado de tus funciones
|  (solo lectura)        |  no cambia durante la ejecución
+========================+  <- dirección baja (números pequeños)
```

Cada zona tiene sus reglas:

- **Código (.text)** — las funciones compiladas viven aquí. No se crean ni destruyen. Existen desde que el programa arranca hasta que termina. Son de solo lectura.
- **Variables globales y estáticas** — también viven toda la ejecución.
- **Stack** — zona automática. Rápida, limitada, gestionada por el programa.
- **Heap** — zona dinámica. Manual, grande, gestionada por ti.

---

## 2. El Stack — cómo funciona en detalle

### La analogía perfecta: bandeja de cafetería

Imagina una cafetería con bandejas apiladas. Cada vez que entras en una función, el programa coge una bandeja nueva y la coloca encima de la pila. En esa bandeja viven todas las variables locales de esa función. Cuando la función termina, la bandeja se retira — y todo lo que había en ella desaparece automáticamente.

```
main() llama a randomChump("Bob"):

     +------------------+
     | Zombie z("Bob")  |  <- bandeja de randomChump()
     | ...              |
     +------------------+
     | int x = 5        |  <- bandeja de main()
     | PhoneBook book   |
     +------------------+
     | (base del stack) |
     +------------------+

randomChump() termina → su bandeja se retira:

     +------------------+
     | int x = 5        |  <- bandeja de main() (sigue aquí)
     | PhoneBook book   |
     +------------------+
```

Esto es lo que se llama un **stack frame** — el "espacio" que una función ocupa en la pila.

### Características fundamentales del Stack

**Automático:** No haces nada para gestionar la memoria. El programa lo hace solo.

**Rápido:** Añadir o quitar una bandeja es literalmente mover un puntero del procesador — la operación más barata en memoria que existe.

**Limitado:** El stack tiene un tamaño máximo fijo establecido por el sistema operativo, normalmente entre 1 MB y 8 MB. Si intentas crear variables demasiado grandes o tienes recursión infinita, el stack se desborda. Eso se llama **stack overflow** — sí, el mismo nombre que la web famosa.

**LIFO:** Last In, First Out. La última función en entrar (la última bandeja colocada) es la primera en salir. Siempre se retira de arriba.

**Scope:** Los objetos del stack mueren al salir del bloque `{ }` donde fueron creados.

### ¿Qué ocurre exactamente cuando un objeto del stack "muere"?

```cpp
void randomChump(std::string name) {
    Zombie z(name);    // 1. se reserva espacio en el stack para z
                       // 2. se llama al constructor de Zombie
    z.announce();      // 3. usas el objeto normalmente
}                      // 4. al llegar aquí:
                       //    - se llama al destructor de z AUTOMÁTICAMENTE
                       //    - se libera el espacio del stack que ocupaba z
```

El destructor se llama solo. No tienes que hacer nada. El lenguaje lo garantiza.

### El orden de destrucción en el stack

Cuando múltiples objetos viven en el mismo scope, se destruyen en orden **inverso** a como fueron creados:

```cpp
void funcion() {
    Zombie a("Alice");   // creado primero
    Zombie b("Bob");     // creado segundo
    Zombie c("Carlos");  // creado tercero
}   // al salir:
    // → Carlos destruido primero
    // → Bob destruido segundo
    // → Alice destruida tercera
    // (LIFO — al revés de como nacieron)
```

Este orden tiene sentido porque si `c` depende de `b`, y `b` depende de `a`, destruir primero a `c` garantiza que sus dependencias siguen vivas cuando se destruye.

---

## 3. El Heap — cómo funciona en detalle

### La analogía: el almacén con taquillas numeradas

Imagina un almacén enorme con miles de taquillas numeradas. Cuando pides memoria con `new`, el sistema te busca una taquilla libre, te asigna esa taquilla, y te da la llave — el **puntero**. Lo que metes en esa taquilla vive indefinidamente — no le importa si las funciones entran y salen. Solo desaparece cuando tú mismo abres la taquilla y la vacías con `delete`.

```
HEAP (el almacén):

taquilla 0x7f3a: [Zombie "Alice"]  <- newZombie creó esto
taquilla 0x7f4b: [ vacía ]
taquilla 0x7f5c: [ vacía ]
taquilla 0x7f6d: [Zombie "Bob"]    <- otro new lo creó
...

STACK (las llaves):

main():
  Zombie *z = 0x7f3a   <- la llave de la taquilla de Alice
```

La variable `z` en el stack solo guarda un número — la dirección. El objeto real vive en el heap. Cuando `z` desaparece del stack (porque la función termina), la taquilla del heap **sigue existiendo**. Nadie la vació. Eso es un memory leak.

### Características fundamentales del Heap

**Manual:** Tú decides cuándo nace un objeto (`new`) y cuándo muere (`delete`). Con ese poder viene la responsabilidad.

**Más lento que el stack:** El sistema tiene que buscar un hueco libre en el heap, marcarlo como ocupado, actualizar su mapa interno. Son varias operaciones. En el stack, crear y destruir es mover un registro del procesador — casi sin coste.

**Grande:** Puede ser de gigabytes, limitado solo por la RAM disponible. No tiene el límite rígido del stack.

**Sin scope:** El objeto vive hasta que tú hagas `delete`. No le importa cuántas funciones hayan entrado y salido mientras tanto.

---

## 4. Stack vs Heap — la decisión

Antes de escribir una sola línea, hazte esta pregunta:

```
¿Necesito que este objeto viva fuera de la función donde lo creo?
                          |
              +-----------+-----------+
              NO                      SÍ
              |                        |
            STACK                    HEAP
   Zombie z(name)          Zombie *z = new Zombie(name)
   z.announce()            z->announce()
   } <- muere solo         delete z  <- tú decides cuándo muere
```

### Casos reales del ex00

**randomChump → Stack:**
```cpp
void randomChump(std::string name) {
    Zombie z(name);   // solo lo necesito aquí dentro
    z.announce();
}   // muere solo — no tengo que hacer nada
```

El zombie solo se usa dentro de la función. No tiene sentido que sobreviva. El stack es perfecto — automático y sin riesgos.

**newZombie → Heap:**
```cpp
Zombie *newZombie(std::string name) {
    return new Zombie(name);   // el zombie tiene que sobrevivir a esta función
}

// en main:
Zombie *z = newZombie("Alice");
z->announce();   // uso el zombie fuera de newZombie — sigue vivo
delete z;        // yo decido cuándo muere
```

El zombie tiene que salir de la función y seguir vivo en `main`. El stack no puede hacer eso — si lo creo en el stack de `newZombie`, muere al terminar la función. El heap es la única opción.

### Tabla comparativa

| | Stack | Heap |
|---|---|---|
| Gestión | Automática | Manual (new / delete) |
| Velocidad | Muy rápida | Más lenta |
| Tamaño máximo | Limitado (1-8 MB) | Gigabytes |
| Cuándo muere el objeto | Al salir del scope `}` | Cuando haces delete |
| Quién gestiona | El programa | Tú |
| Sintaxis de creación | `Zombie z(name)` | `Zombie *z = new Zombie(name)` |
| Acceso a miembros | `z.announce()` | `z->announce()` |
| Riesgo principal | Dangling pointer | Memory leak |
| Cuándo usarlo | Objeto temporal/local | Objeto que debe sobrevivir |

---

## 5. `new` — crear objetos en el heap

`new` es el operador de C++ para reservar memoria en el heap. Hace **tres cosas a la vez**:

1. Busca un hueco libre en el heap del tamaño necesario
2. Llama al **constructor** del objeto automáticamente
3. Devuelve un **puntero** al objeto ya inicializado

```cpp
Zombie *z = new Zombie("Alice");
//      ↑             ↑
//  puntero      parámetro para el constructor
```

### Comparación con malloc (que ya no debes usar)

```c
// C — malloc
Zombie *z = (Zombie *)malloc(sizeof(Zombie));
// malloc reserva memoria pero el constructor NO se llama
// el objeto existe en memoria pero NO está inicializado

// C++ — new
Zombie *z = new Zombie("Alice");
// new reserva memoria Y llama al constructor
// el objeto existe Y está inicializado y listo
```

Esta es una diferencia crítica. Con `malloc`, si tu clase tiene atributos de tipo `std::string`, esos strings no estarán inicializados correctamente — comportamiento indefinido. `new` garantiza que el constructor se ejecuta siempre.

### La sintaxis completa de new

```cpp
// objeto con parámetros
Zombie *z1 = new Zombie("Alice");

// objeto con constructor por defecto (sin parámetros)
Zombie *z2 = new Zombie();
// o equivalentemente:
Zombie *z2 = new Zombie;

// tipo primitivo
int *n = new int(42);      // reserva un int y lo inicializa a 42
int *m = new int;          // reserva un int sin inicializar
```

---

## 6. `delete` — destruir objetos del heap

`delete` es la pareja obligatoria de `new`. Hace **dos cosas a la vez**:

1. Llama al **destructor** del objeto automáticamente
2. Libera la memoria en el heap

```cpp
Zombie *z = new Zombie("Alice");   // constructor llamado
z->announce();
delete z;                           // destructor llamado + memoria liberada
```

### Comparación con free (que ya no debes usar)

```c
// C — free
free(z);   // libera la memoria pero el destructor NO se llama

// C++ — delete
delete z;  // llama al destructor + libera la memoria
```

Si usas `free` en lugar de `delete` con objetos C++, el destructor no se ejecuta. Si tu destructor tenía trabajo importante (cerrar ficheros, liberar otros recursos), ese trabajo no se hace. Bug garantizado.

### La regla de oro: new y delete son inseparables

```
new    →  delete
new[]  →  delete[]
malloc →  free
```

**Nunca mezcles estas parejas.** `new` con `free`, o `malloc` con `delete`, da comportamiento indefinido. El programa puede crashear, corromper memoria, o parecer funcionar y luego fallar misteriosamente.

### Qué hacer después del delete

Después de `delete`, el puntero sigue existiendo en el stack. Sigue conteniendo la dirección de la antigua taquilla — pero esa taquilla ya fue vaciada. Es una dirección inválida. Si intentas usarla, comportamiento indefinido.

La buena práctica: poner el puntero a `nullptr` después de `delete`:

```cpp
Zombie *z = new Zombie("Alice");
delete z;
z = nullptr;   // ahora sabes con certeza que z no apunta a nada válido

if (z != nullptr)
    z->announce();   // nunca se ejecuta — z es nullptr
```

---

## 7. El ciclo de vida completo de un objeto

Visualizando todo el proceso del ex00:

### Zombie en el Stack (randomChump)

```
randomChump("Bob") se llama:
  1. El programa reserva espacio en el stack para z
  2. Zombie::Zombie("Bob") se ejecuta — constructor
     → _name = "Bob"
     → imprime "zombie Bob created"
  3. z.announce() se ejecuta
     → imprime "Bob: BraiiiiiiinnnzzzZ..."
  4. La función llega a }
  5. Zombie::~Zombie() se ejecuta — destructor
     → imprime "Zombie Bob destroyed"
  6. El espacio del stack se libera

  Todo automático. Tú no hiciste nada para los pasos 1, 2, 5, 6.
```

### Zombie en el Heap (newZombie + main)

```
Zombie *z = newZombie("Alice"):
  1. new busca espacio libre en el heap
  2. Zombie::Zombie("Alice") se ejecuta — constructor
     → _name = "Alice"
     → imprime "zombie Alice created"
  3. new devuelve la dirección del objeto
  4. z (en el stack) guarda esa dirección

z->announce() se ejecuta:
  5. Se accede al objeto en el heap mediante z
     → imprime "Alice: BraiiiiiiinnnzzzZ..."

delete z:
  6. Zombie::~Zombie() se ejecuta — destructor
     → imprime "Zombie Alice destroyed"
  7. La memoria en el heap se libera

  Pasos 1, 2, 6, 7 son automáticos.
  Tú hiciste: new (paso 1-4) y delete (pasos 6-7).
```

### Verificar el orden con la salida del programa

Si tu main es:

```cpp
int main() {
    std::cout << "=== HEAP ===" << std::endl;
    Zombie *h = newZombie("HeapZombie");
    h->announce();

    std::cout << "=== STACK ===" << std::endl;
    randomChump("StackZombie");

    std::cout << "=== DELETE HEAP ===" << std::endl;
    delete h;

    std::cout << "=== FIN ===" << std::endl;
    return 0;
}
```

La salida será:

```
=== HEAP ===
zombie HeapZombie created
HeapZombie: BraiiiiiiinnnzzzZ...
=== STACK ===
zombie StackZombie created
StackZombie: BraiiiiiiinnnzzzZ...
Zombie StackZombie destroyed    <- muere al terminar randomChump
=== DELETE HEAP ===
Zombie HeapZombie destroyed     <- muere cuando tú haces delete
=== FIN ===
```

Observa: StackZombie muere **antes** del mensaje "=== DELETE HEAP ===" porque muere al salir de randomChump. HeapZombie sigue vivo todo ese tiempo y solo muere cuando tú haces `delete`.

---

## 8. Funciones libres vs métodos de clase

En el ex00 tienes dos tipos de funciones:

**Métodos de clase** — pertenecen a `Zombie`:
```cpp
// declarados dentro de la clase en Zombie.hpp
void announce(void);

// implementados con Zombie:: en Zombie.cpp
void Zombie::announce(void) {
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

// llamados sobre un objeto
z.announce();    // objeto directo
z->announce();   // puntero
```

**Funciones libres** — no pertenecen a ninguna clase:
```cpp
// declaradas en Zombie.hpp pero FUERA de la clase
Zombie *newZombie(std::string name);
void    randomChump(std::string name);

// implementadas en sus propios .cpp SIN Zombie::
Zombie *newZombie(std::string name) {
    return new Zombie(name);   // SIN Zombie:: delante
}

// llamadas directamente, como funciones de C
Zombie *z = newZombie("Alice");
randomChump("Bob");
```

### ¿Dónde se declaran las funciones libres?

Tienen que declararse en algún sitio para que otros archivos sepan que existen. Las opciones son:

**Opción A — en Zombie.hpp, fuera de la clase:**
```cpp
class Zombie {
    // ...
};

// fuera de la clase — funciones libres
Zombie *newZombie(std::string name);
void    randomChump(std::string name);
```

**Opción B — declararlas en main.cpp antes de usarlas:**
```cpp
Zombie *newZombie(std::string name);   // declaración
void    randomChump(std::string name); // declaración

int main() {
    Zombie *z = newZombie("Alice");   // ya puede usarlas
    randomChump("Bob");
}
```

La opción A es más limpia — todo lo relacionado con Zombie está en Zombie.hpp.

### El operador `.` vs `->`

Cuando tienes el **objeto directamente** (en el stack):
```cpp
Zombie z("Alice");   // objeto directo
z.announce();        // punto — accedes directamente al miembro
```

Cuando tienes un **puntero al objeto** (en el heap o cualquier puntero):
```cpp
Zombie *z = new Zombie("Alice");   // puntero
z->announce();   // flecha — equivale a (*z).announce()
```

El operador `->` hace dos cosas en una: **desreferencia** el puntero (va a la dirección que apunta) y **accede** al miembro. Es una abreviación de `(*z).announce()`.

```cpp
// estas dos líneas son EXACTAMENTE equivalentes:
z->announce();
(*z).announce();
```

En práctica siempre usas `->` con punteros porque es más limpio.

---

## 9. Devolver punteros desde funciones

Este es el patrón central de `newZombie`:

```cpp
Zombie *newZombie(std::string name) {
    return new Zombie(name);
}
```

¿Por qué devolver un puntero y no el objeto directamente?

**Si devolvieras el objeto directamente:**
```cpp
Zombie newZombie(std::string name) {   // devuelve por valor
    return new Zombie(name);   // ERROR — new devuelve puntero, no objeto
}

// O así:
Zombie newZombie(std::string name) {
    Zombie z(name);    // z vive en el stack de newZombie
    return z;          // se hace una COPIA de z para devolver
}                      // z original se destruye al salir
```

Devolver por valor crea una **copia** del objeto. En este caso funciona, pero es ineficiente para objetos grandes y semánticamente confuso.

**Si intentaras devolver una referencia o puntero al stack:**
```cpp
Zombie *newZombie(std::string name) {
    Zombie z(name);   // z en el stack de newZombie
    return &z;        // devuelves la dirección de z
}                     // z MUERE aquí — la dirección ya no es válida
// quien reciba el puntero tiene un DANGLING POINTER
```

Esto es un error crítico — estás devolviendo la dirección de algo que acaba de morir.

**La solución correcta — heap:**
```cpp
Zombie *newZombie(std::string name) {
    return new Zombie(name);   // el objeto vive en el heap
}                              // la función termina pero el heap object sigue vivo
// quien reciba el puntero tiene un objeto válido
// su responsabilidad: hacer delete cuando ya no lo necesite
```

El heap es la única forma de crear un objeto en una función y devolver acceso a él. La responsabilidad de liberarlo se **transfiere** a quien recibe el puntero.

---

## 10. Los peligros de la memoria dinámica

### Memory Leak — la taquilla olvidada

```cpp
void funcion() {
    Zombie *z = new Zombie("Alice");
    z->announce();
    // olvidamos el delete
}   // z desaparece del stack
    // pero Alice sigue en el heap para siempre
    // MEMORY LEAK — memoria perdida hasta que el proceso termine
```

En un programa corto esto no importa mucho — cuando el proceso termina, el SO recupera toda la memoria. Pero en un servidor que corre semanas sin parar, los leaks acumulan y pueden agotar la RAM del sistema.

Para detectar memory leaks en Mac/Linux:
```bash
valgrind --leak-check=full ./mi_programa
```

### Dangling Pointer — la llave de una taquilla vacía

```cpp
Zombie *z = new Zombie("Alice");
delete z;           // Alice destruida, taquilla vaciada
z->announce();      // PELIGRO — z sigue apuntando a la antigua dirección
                    // la taquilla fue vaciada
                    // comportamiento INDEFINIDO
```

El compilador no avisa. El programa puede crashear, imprimir basura, o aparentemente funcionar — hasta que un día falla en producción.

```cpp
// solución: nullptr después del delete
delete z;
z = nullptr;
if (z != nullptr)
    z->announce();   // nunca se ejecuta
```

### Double Free — abrir una taquilla ya abierta

```cpp
Zombie *z = new Zombie("Alice");
delete z;
delete z;   // PELIGRO — doble liberación
            // el heap manager puede corromperse
```

El heap lleva un mapa de qué taquillas están ocupadas y cuáles libres. Si liberas la misma dos veces, ese mapa se corrompe — crashes y comportamiento indefinido garantizados.

### Mezclar new con free o malloc con delete

```cpp
Zombie *z = new Zombie("Alice");
free(z);    // PELIGRO — el destructor NO se llama
            // además, new y free usan gestores distintos
            // corrupción del heap garantizada
```

Regla absoluta: **lo que nació con `new` muere con `delete`. Siempre.**

---

# PARTE 2 — ARRAYS DINÁMICOS (ex01: Moar brainz!)

---

## 11. `new[]` — crear arrays en el heap

El ex01 pide crear N zombies de golpe en una sola reserva de memoria. Para eso existe `new[]`:

```cpp
// crear un array de N Zombie en el heap
Zombie *horde = new Zombie[N];
```

Esto hace varias cosas:
1. Reserva en el heap espacio para N objetos `Zombie` **consecutivos**
2. Llama al **constructor por defecto** de cada uno de los N zombies
3. Devuelve un puntero al **primer** zombie del array

Visualizado en memoria:

```
HEAP:
+----------+----------+----------+----------+----------+
| Zombie 0 | Zombie 1 | Zombie 2 | Zombie 3 | Zombie 4 |
+----------+----------+----------+----------+----------+
     ^
     |
  horde  (puntero al primero)
```

Los N objetos están uno detrás del otro en memoria, sin espacios entre ellos. El puntero `horde` apunta al primero.

### Por qué los objetos están contiguos en memoria

Esta contigüidad es intencional y eficiente. El procesador puede recorrer arrays contiguos muy rápido porque los datos están juntos en caché. Si estuvieran dispersos por el heap, cada acceso sería más lento.

### Acceder a los elementos

Igual que un array normal de C:

```cpp
horde[0].announce();   // primer zombie — usa . porque no es puntero
horde[1].announce();   // segundo zombie
horde[N-1].announce(); // último zombie

// también puedes recorrerlos con bucle
for (int i = 0; i < N; i++) {
    horde[i].announce();
}
```

Internamente `horde[i]` equivale a `*(horde + i)` — el compilador hace aritmética de punteros. `horde + 1` apunta al segundo zombie, `horde + 2` al tercero, etc.

---

## 12. `delete[]` — destruir arrays del heap

Para liberar un array creado con `new[]` **debes** usar `delete[]` con corchetes:

```cpp
delete[] horde;
```

El `[]` es esencial. Le dice al compilador que hay **varios** objetos que destruir, no uno solo.

¿Qué hace exactamente `delete[]`?
1. Llama al **destructor** de cada uno de los N zombies (en orden inverso)
2. Libera **toda** la memoria del array de una vez

### ¿Qué pasa si usas `delete` sin `[]` en un array?

```cpp
Zombie *horde = new Zombie[5];
delete horde;    // ← MAL — sin []
```

El comportamiento es **indefinido**, pero en la práctica suele pasar:
- Solo se destruye el **primer** zombie — los otros 4 no tienen su destructor llamado
- La liberación de memoria puede ser incorrecta — el heap manager no sabe cuántos objetos hay

Si tus destructores tienen trabajo importante (cerrar ficheros, liberar recursos), ese trabajo no se hace para los zombies 1-4. Memory leak + comportamiento indefinido.

### La tabla completa de parejas

| Reserva | Liberación | ¿Constructor/Destructor? |
|---|---|---|
| `new Zombie("A")` | `delete z` | Sí, constructor con parámetros |
| `new Zombie` | `delete z` | Sí, constructor por defecto |
| `new Zombie[N]` | `delete[] horde` | Sí, constructor por defecto × N |
| `new int(42)` | `delete p` | No (tipo primitivo) |
| `new int[N]` | `delete[] p` | No (tipo primitivo) |
| `malloc(size)` | `free(p)` | Nunca — malloc no llama constructores |

---

## 13. El constructor por defecto y `new[]`

Aquí está el problema que te encuentras en el ex01:

Cuando haces `new Zombie[N]`, el compilador tiene que construir N zombies. Pero no sabe qué nombre darle a cada uno en ese momento. Necesita llamar al constructor **sin parámetros**.

Si tu única definición de constructor es:
```cpp
Zombie(std::string name);   // exige un nombre
```

El compilador intentará `new Zombie[N]` y fallará:
```
error: no matching constructor for initialization of 'Zombie'
```

Porque no tiene ningún constructor que pueda llamar sin parámetros.

**La solución: añadir un constructor por defecto:**

```cpp
// en Zombie.hpp
class Zombie {
    public:
        Zombie(std::string name);   // con nombre
        Zombie();                    // sin nombre — constructor por defecto
        ~Zombie();
        void announce(void);
        void setName(std::string name);   // para asignar el nombre después
};
```

```cpp
// en Zombie.cpp
Zombie::Zombie() {
    // no hacemos nada — _name queda como "" (string vacío por defecto)
}
```

El constructor por defecto no necesita hacer nada porque `std::string` ya se inicializa solo como string vacío.

### El flujo completo del ex01

```cpp
Zombie *zombieHorde(int N, std::string name) {
    // 1. crear el array — llama al constructor por defecto N veces
    Zombie *horde = new Zombie[N];

    // 2. asignar el nombre a cada uno
    for (int i = 0; i < N; i++) {
        horde[i].setName(name);
    }

    // 3. devolver el puntero al primero
    return horde;
}
```

El `setName` es necesario porque en el momento del `new Zombie[N]` todavía no tienes el nombre disponible para pasárselo al constructor.

### ¿Por qué el constructor por defecto no aparecía en el ex00?

En el ex00 siempre creabas los zombies con nombre:
```cpp
Zombie z("Alice");            // constructor con nombre
Zombie *z = new Zombie("Bob"); // constructor con nombre
```

El compilador nunca necesitó el constructor por defecto. En el ex01, al hacer `new Zombie[N]`, sí lo necesita.

**Regla:** Necesitas constructor por defecto cuando:
- Creas arrays de objetos con `new Clase[N]`
- Creas arrays de objetos en el stack: `Clase array[N]` (como en PhoneBook)
- Declaras un objeto sin inicializarlo: `Clase obj;`

---

## 14. Recorrer y usar arrays dinámicos

Una vez creado el array, lo usas exactamente como un array normal:

### Recorrer con índice

```cpp
Zombie *horde = zombieHorde(5, "LegionZombie");

for (int i = 0; i < 5; i++) {
    horde[i].announce();   // punto — horde[i] es un objeto, no un puntero
}

delete[] horde;
```

### Recorrer con puntero (aritmética de punteros)

```cpp
for (Zombie *ptr = horde; ptr < horde + N; ptr++) {
    ptr->announce();   // flecha — ptr ES un puntero
}
```

`horde + N` apunta a la posición después del último zombie — la misma idea que `end()` en los iteradores.

### El main completo del ex01

```cpp
int main() {
    int N = 5;
    Zombie *horde = zombieHorde(N, "LegionZombie");

    // todos anuncian
    for (int i = 0; i < N; i++) {
        horde[i].announce();
    }

    // liberar todos de golpe
    delete[] horde;
    horde = nullptr;

    return 0;
}
```

Salida esperada:
```
LegionZombie: BraiiiiiiinnnzzzZ...
LegionZombie: BraiiiiiiinnnzzzZ...
LegionZombie: BraiiiiiiinnnzzzZ...
LegionZombie: BraiiiiiiinnnzzzZ...
LegionZombie: BraiiiiiiinnnzzzZ...
Zombie LegionZombie destroyed    <- delete[] llama al destructor 5 veces
Zombie LegionZombie destroyed
Zombie LegionZombie destroyed
Zombie LegionZombie destroyed
Zombie LegionZombie destroyed
```

Los destructores se llaman en **orden inverso** — del zombie 4 al zombie 0.

### Diferencia entre `delete` y `delete[]` visualmente

```
new Zombie("Alice")  →  [Alice]
delete z             →  destructor de Alice, libera [Alice]

new Zombie[5]        →  [Z0][Z1][Z2][Z3][Z4]
delete[] horde       →  destructor de Z4, Z3, Z2, Z1, Z0 (inverso)
                        libera todo el bloque de golpe
```

---

## 15. Glosario completo de ex00 y ex01

| Término | Definición |
|---|---|
| **Stack** | Zona de memoria automática gestionada como una pila de bandejas |
| **Heap** | Zona de memoria dinámica gestionada manualmente con new/delete |
| **Stack frame** | El espacio que ocupa una función en el stack — sus variables locales |
| **Scope** | El bloque `{ }` donde existe una variable — al salir, las variables del stack mueren |
| **new** | Reserva memoria en el heap Y llama al constructor |
| **delete** | Llama al destructor Y libera la memoria del heap |
| **new[]** | Reserva un array en el heap Y llama al constructor por defecto de cada elemento |
| **delete[]** | Llama al destructor de cada elemento Y libera todo el array del heap |
| **Puntero** | Variable que guarda una dirección de memoria |
| **nullptr** | Puntero nulo — no apunta a nada válido |
| **Operador `.`** | Accede a un miembro de un objeto directo (no puntero) |
| **Operador `->`** | Accede a un miembro de un objeto a través de un puntero — equivale a `(*p).miembro` |
| **Memory leak** | Memoria reservada en el heap que nunca se libera — se pierde para siempre |
| **Dangling pointer** | Puntero que apunta a memoria que ya fue liberada — usarlo es comportamiento indefinido |
| **Double free** | Llamar a delete dos veces sobre el mismo puntero — corrompe el heap |
| **Constructor por defecto** | Constructor sin parámetros — necesario para `new Clase[N]` y arrays en el stack |
| **Función libre** | Función que no pertenece a ninguna clase — como `newZombie` y `randomChump` |
| **Método** | Función que pertenece a una clase — como `announce` |
| **Operador `::`** | Resolución de ámbito — indica a qué clase pertenece un método en el `.cpp` |
| **Transferencia de responsabilidad** | Cuando una función crea un objeto en el heap y lo devuelve, quien recibe el puntero es responsable de hacer delete |
| **LIFO** | Last In First Out — el orden en que se destruyen los objetos del stack (inverso a como se crearon) |
| **Contiguo en memoria** | Los elementos de un array están uno detrás del otro sin espacios — permite aritmética de punteros |
| **Aritmética de punteros** | `horde + i` apunta al elemento i-ésimo del array — el compilador calcula el offset automáticamente |
| **Comportamiento indefinido** | Lo que pasa cuando violas las reglas de C++ — puede crashear, dar resultados incorrectos o parecer funcionar |
| **valgrind** | Herramienta para detectar memory leaks y accesos inválidos en Linux |
| **Stack overflow** | Cuando el stack se desborda por usar demasiada memoria o recursión infinita |
| **setName** | Setter necesario en el ex01 porque `new[]` no puede pasar parámetros al constructor |

---

# APÉNDICE — Estructura de archivos de ex00 y ex01

### ex00: BraiiiiiiinnnzzzZ

```
ex00/
├── Makefile
├── Zombie.hpp          ← clase Zombie + declaración de funciones libres
├── Zombie.cpp          ← implementación: constructor, destructor, announce
├── newZombie.cpp       ← función libre: crea Zombie en heap, devuelve puntero
├── randomChump.cpp     ← función libre: crea Zombie en stack, lo usa, muere solo
└── main.cpp            ← prueba ambas formas y muestra cuándo muere cada zombie

Zombie.hpp contiene:
  class Zombie {
    private: _name
    public:  Zombie(std::string name), ~Zombie(), announce()
  };
  Zombie *newZombie(std::string name);   ← fuera de la clase
  void randomChump(std::string name);    ← fuera de la clase
```

### ex01: Moar brainz!

```
ex01/
├── Makefile
├── Zombie.hpp          ← clase Zombie CON constructor por defecto y setName
├── Zombie.cpp          ← implementación: ambos constructores, destructor, announce, setName
├── zombieHorde.cpp     ← función libre: new Zombie[N], setName en bucle, return horde
└── main.cpp            ← llama a zombieHorde, anuncia cada zombie, delete[] al final

Zombie.hpp contiene:
  class Zombie {
    private: _name
    public:  Zombie(std::string name)  ← constructor con nombre
             Zombie()                  ← constructor por defecto — nuevo en ex01
             ~Zombie()
             void announce(void)
             void setName(std::string name)  ← nuevo en ex01
  };
  Zombie *zombieHorde(int N, std::string name);
```

### Diferencia clave entre ex00 y ex01

```
ex00: un zombie a la vez
  new Zombie("Alice")  →  delete z

ex01: N zombies de golpe, un solo new
  new Zombie[N]  →  setName en bucle  →  delete[] horde
```
