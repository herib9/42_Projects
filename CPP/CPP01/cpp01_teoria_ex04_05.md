# C++ — Temario Completo CPP01
## Ejercicios 04 y 05 — Streams de ficheros y Punteros a funciones miembro

---

# ÍNDICE

**PARTE 1 — ex04: Sed is for losers**
1. ¿Qué es un stream?
2. Abrir y cerrar ficheros — ifstream y ofstream
3. Verificar si un fichero se abrió correctamente
4. Leer ficheros — línea a línea con getline
5. Escribir en ficheros — igual que cout
6. Las operaciones de std::string para manipular texto
7. El algoritmo de reemplazar sin usar replace
8. Gestión de errores — casos especiales
9. El flujo completo del ex04

**PARTE 2 — ex05: Harl 2.0**
10. El problema — el bosque de if/else
11. ¿Qué es un puntero a función?
12. Punteros a funciones normales — repaso base
13. Punteros a funciones miembro — la diferencia clave
14. La sintaxis completa desglosada
15. Arrays de punteros a funciones miembro
16. Buscar en el array — el patrón del ex05
17. Por qué esto es mejor que if/else
18. Glosario completo

---

# PARTE 1 — STREAMS DE FICHEROS (ex04: Sed is for losers)

---

## 1. ¿Qué es un stream?

Un **stream** (flujo) es una abstracción que representa una secuencia de datos que fluye de un lado a otro. En C++ todo lo que implica entrada y salida se modela como streams.

Ya conoces dos streams:
- `std::cout` — stream de salida hacia la pantalla
- `std::cin` — stream de entrada desde el teclado

La clave de los streams es que **todos funcionan igual**. El operador `<<` manda datos al stream. El operador `>>` o `std::getline` lee datos del stream. Da igual si el stream es la pantalla, el teclado, un fichero o un string en memoria — la interfaz es la misma.

Esto es muy poderoso: el código que sabes escribir para imprimir en pantalla funciona casi igual para escribir en un fichero.

```cpp
// Escribir en pantalla
std::cout << "Hola mundo" << std::endl;

// Escribir en fichero — casi idéntico
std::ofstream fichero("resultado.txt");
fichero << "Hola mundo" << std::endl;
```

### Los tres streams de fichero

Para usarlos necesitas:
```cpp
#include <fstream>
```

| Tipo | Nombre | Para qué |
|---|---|---|
| `std::ifstream` | input file stream | Leer desde un fichero |
| `std::ofstream` | output file stream | Escribir en un fichero |
| `std::fstream` | file stream | Leer Y escribir |

En el ex04 usas `ifstream` para leer el fichero original y `ofstream` para crear el fichero `.replace`.

---

## 2. Abrir y cerrar ficheros — ifstream y ofstream

### Abrir un fichero para leer

```cpp
std::ifstream entrada("datos.txt");
```

Esto intenta abrir `datos.txt` para leer. Si el fichero existe, lo abre. Si no existe, el stream queda en estado de error.

También puedes declarar primero y abrir después:
```cpp
std::ifstream entrada;
entrada.open("datos.txt");
```

### Abrir un fichero para escribir

```cpp
std::ofstream salida("resultado.txt");
```

Esto crea `resultado.txt` si no existe. Si ya existe, lo **sobreescribe** — borra el contenido anterior. El comportamiento por defecto es destructivo.

Para añadir al final de un fichero existente sin borrar su contenido:
```cpp
std::ofstream salida("resultado.txt", std::ios::app);   // app = append
```

En el ex04 siempre creas un fichero nuevo con el nombre `fichero.replace`, así que el comportamiento por defecto (sobreescribir) es perfecto.

### Cerrar un fichero

```cpp
entrada.close();
salida.close();
```

Cerrar el fichero garantiza que todos los datos pendientes en el buffer se escriben y que el sistema operativo libera el fichero. Si no cierras explícitamente, el destructor del stream lo cierra automáticamente cuando el objeto sale del scope. Pero es buena práctica cerrarlo manualmente cuando ya no lo necesitas.

---

## 3. Verificar si un fichero se abrió correctamente

Abrir un fichero puede fallar. Si el fichero no existe, si no tienes permisos, si la ruta es incorrecta... el stream queda en estado de error. Tienes que comprobarlo antes de usarlo.

### El método is_open()

```cpp
std::ifstream entrada("datos.txt");

if (!entrada.is_open()) {
    std::cerr << "Error: no se puede abrir el fichero datos.txt" << std::endl;
    return 1;   // salir del programa con código de error
}
```

`is_open()` devuelve `true` si el fichero se abrió correctamente, `false` si falló.

### La conversión implícita a bool

Los streams de C++ tienen una conversión implícita a `bool` — devuelven `true` si están en buen estado, `false` si hay algún error:

```cpp
std::ifstream entrada("datos.txt");

if (!entrada) {   // equivalente a if (!entrada.is_open())
    std::cerr << "Error al abrir el fichero" << std::endl;
    return 1;
}
```

Ambas formas funcionan. `is_open()` es más explícito y claro.

### ¿Por qué usar std::cerr en lugar de std::cout para errores?

`std::cerr` es el stream de error estándar. En un terminal normal no hay diferencia visible. Pero en producción o al usar redirección de salida (`./programa > salida.txt`), `cout` se redirige al fichero pero `cerr` sigue apareciendo en la terminal. Los mensajes de error siempre deberían ir a `cerr`.

### Comprobar errores al final de la operación

```cpp
std::ofstream salida("resultado.txt");

if (!salida) {
    std::cerr << "Error: no se puede crear el fichero resultado.txt" << std::endl;
    return 1;
}

salida << "contenido";

if (salida.fail()) {
    std::cerr << "Error al escribir en el fichero" << std::endl;
    return 1;
}
```

`fail()` devuelve `true` si alguna operación de escritura falló — por ejemplo, si el disco está lleno.

---

## 4. Leer ficheros — línea a línea con getline

### Leer una línea

```cpp
std::ifstream entrada("datos.txt");
std::string linea;

std::getline(entrada, linea);   // lee la primera línea
```

`std::getline` lee caracteres desde el stream hasta encontrar `'\n'` (o el final del fichero). El `'\n'` se consume pero no se incluye en `linea`.

### Leer todas las líneas — el bucle estándar

```cpp
std::ifstream entrada("datos.txt");
std::string linea;

while (std::getline(entrada, linea)) {
    // procesa linea
    std::cout << linea << std::endl;
}
```

¿Cómo funciona el `while`? `std::getline` devuelve una referencia al stream. El stream se convierte implícitamente a `bool`: `true` si la lectura fue exitosa, `false` si llegó al final del fichero o hubo un error. Así el bucle continúa mientras haya líneas que leer.

Cuando `getline` llega al final del fichero, devuelve el stream en estado de error (fin de fichero) → el `bool` es `false` → el `while` termina.

### Leer el fichero completo en un string

```cpp
std::ifstream entrada("datos.txt");
std::string contenido;
std::string linea;

while (std::getline(entrada, linea)) {
    contenido += linea + "\n";   // acumula todas las líneas
}
```

**Atención**: al acumular con `getline`, el `'\n'` que separa las líneas no está incluido en `linea` — tienes que añadirlo manualmente si quieres conservar los saltos de línea.

### ¿Por qué leer línea a línea y no el fichero de golpe?

Para el ex04, leer línea a línea es perfectamente válido. Para ficheros muy grandes, leer de golpe puede consumir mucha memoria. Línea a línea es más eficiente en ese sentido.

---

## 5. Escribir en ficheros — igual que cout

Una vez abierto el `ofstream`, escribir en él es idéntico a escribir en `cout`:

```cpp
std::ofstream salida("resultado.txt");

salida << "Primera línea" << std::endl;
salida << "Segunda línea: " << 42 << std::endl;

std::string texto = "Variable";
salida << texto << std::endl;
```

### El nombre del fichero de salida en el ex04

El subject pide crear un fichero llamado `<filename>.replace`. Así construyes el nombre:

```cpp
std::string nombreEntrada = argv[1];         // "datos.txt"
std::string nombreSalida  = nombreEntrada + ".replace";   // "datos.txt.replace"

std::ifstream entrada(nombreEntrada.c_str());
std::ofstream salida(nombreSalida.c_str());
```

**¿Por qué `.c_str()`?** En C++98, los constructores de `ifstream` y `ofstream` aceptan `const char *`, no `std::string`. `.c_str()` convierte un `std::string` a `const char *`. En C++11 ya aceptan `std::string` directamente, pero como trabajas con C++98, necesitas el `.c_str()`.

---

## 6. Las operaciones de std::string para manipular texto

El ex04 pide reemplazar todas las ocurrencias de `s1` con `s2` en el fichero, **sin usar `std::string::replace`**. Necesitas conocer bien las herramientas disponibles.

### find — buscar una subcadena

```cpp
std::string linea = "Hola Alice, como estas Alice?";
std::string s1    = "Alice";

size_t pos = linea.find(s1);
// pos = 5 (primera ocurrencia)

size_t pos2 = linea.find(s1, pos + 1);
// find(s1, inicio) — busca a partir de 'inicio'
// pos2 = 21 (segunda ocurrencia)

if (linea.find("zombie") == std::string::npos)
    // npos significa "no encontrado"
```

**`size_t`** es un tipo entero sin signo — el tipo que `find` devuelve. Usar `int` en lugar de `size_t` puede dar warnings porque `size_t` es sin signo e `int` es con signo.

**`std::string::npos`** es el valor especial que `find` devuelve cuando no encuentra nada. Es el valor máximo de `size_t` — algo como `18446744073709551615` en sistemas de 64 bits.

### substr — extraer una subcadena

```cpp
std::string texto = "Hola Alice mundo";
//                   0123456789...

std::string trozo = texto.substr(5, 5);
// substr(posicion_inicio, cantidad_caracteres)
// desde posición 5, coge 5 caracteres → "Alice"

std::string resto = texto.substr(10);
// substr(posicion_inicio) — hasta el final
// desde posición 10 hasta el final → " mundo"
```

### erase — borrar parte del string

```cpp
std::string texto = "Hola Alice mundo";
texto.erase(5, 5);
// erase(posicion_inicio, cantidad_caracteres)
// borra 5 caracteres desde posición 5 → "Hola  mundo"
```

### insert — insertar texto en una posición

```cpp
std::string texto = "Hola mundo";
texto.insert(5, "Alice ");
// insert(posicion, texto_a_insertar)
// inserta "Alice " en posición 5 → "Hola Alice mundo"
```

### length y size — el tamaño del string

```cpp
std::string s1 = "Alice";
size_t longitud = s1.length();   // 5
// o equivalentemente:
size_t tamanio  = s1.size();     // también 5
```

---

## 7. El algoritmo de reemplazar sin usar replace

El ex04 prohíbe `std::string::replace`. Tienes que construir el reemplazo manualmente usando `find`, `erase` e `insert` (o `substr`).

### El patrón básico para una sola ocurrencia

```cpp
std::string linea = "Hola Alice mundo";
std::string s1    = "Alice";
std::string s2    = "Bob";

size_t pos = linea.find(s1);    // pos = 5

if (pos != std::string::npos) {
    linea.erase(pos, s1.length());   // borra "Alice" → "Hola  mundo"
    linea.insert(pos, s2);           // inserta "Bob"  → "Hola Bob mundo"
}
```

### El patrón para TODAS las ocurrencias — el bucle

El ex04 pide reemplazar **todas** las ocurrencias de `s1`, no solo la primera. Necesitas un bucle:

```cpp
void reemplazar(std::string &linea, const std::string &s1, const std::string &s2) {
    if (s1.empty())   // caso especial — no buscar string vacío
        return;

    size_t pos = 0;

    while ((pos = linea.find(s1, pos)) != std::string::npos) {
        linea.erase(pos, s1.length());   // borra s1
        linea.insert(pos, s2);            // inserta s2
        pos += s2.length();               // avanza para no buscar en lo que acabamos de insertar
    }
}
```

**La línea más importante del bucle:**
```cpp
pos += s2.length();
```

¿Por qué es necesaria? Imagina que `s1 = "aa"` y `s2 = "aaa"`. Si no avanzas `pos` después de insertar `s2`, el `find` encontrará `"aa"` dentro del `s2` recién insertado y entrarás en un bucle infinito:

```
"aaa mundo"
 ^^ encuentra "aa" aquí
→ borra "aa", inserta "aaa"
"aaaa mundo"  ← se creció el problema
→ vuelve a encontrar "aa" en la misma posición
→ bucle infinito
```

Con `pos += s2.length()`, después de insertar "aaa" mueves el cursor 3 posiciones — más allá de lo que acabas de insertar. El próximo `find` buscará a partir de ahí, evitando el bucle infinito.

### El caso especial de s1 vacío

El subject dice que debes manejar entradas inesperadas. Si `s1` es un string vacío, `find("", pos)` siempre encuentra una coincidencia — en cada posición del string. Eso causa un bucle infinito. Debes comprobarlo antes:

```cpp
if (s1.empty()) {
    std::cerr << "Error: s1 no puede estar vacío" << std::endl;
    return 1;
}
```

---

## 8. Gestión de errores — casos especiales

El subject dice explícitamente: "handle unexpected inputs and errors". Los casos que debes cubrir:

### El fichero no existe

```cpp
std::ifstream entrada(argv[1]);
if (!entrada.is_open()) {
    std::cerr << "Error: no se puede abrir '" << argv[1] << "'" << std::endl;
    return 1;
}
```

### Número incorrecto de argumentos

```cpp
int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "Uso: " << argv[0] << " <fichero> <s1> <s2>" << std::endl;
        return 1;
    }
    // ...
}
```

### s1 está vacío

```cpp
std::string s1 = argv[2];
if (s1.empty()) {
    std::cerr << "Error: s1 no puede ser un string vacío" << std::endl;
    return 1;
}
```

### No se puede crear el fichero de salida

```cpp
std::ofstream salida((nombreEntrada + ".replace").c_str());
if (!salida.is_open()) {
    std::cerr << "Error: no se puede crear el fichero de salida" << std::endl;
    entrada.close();
    return 1;
}
```

---

## 9. El flujo completo del ex04

Juntando todo, la estructura lógica del programa:

```
1. Comprobar que hay exactamente 3 argumentos (fichero, s1, s2)
2. Comprobar que s1 no está vacío
3. Abrir el fichero de entrada (argv[1]) con ifstream
4. Comprobar que se abrió correctamente
5. Crear el fichero de salida (argv[1] + ".replace") con ofstream
6. Comprobar que se creó correctamente
7. Leer línea a línea con getline
8. Para cada línea, reemplazar todas las ocurrencias de s1 por s2
9. Escribir la línea modificada en el fichero de salida
10. Cerrar ambos ficheros
```

```cpp
int main(int argc, char **argv) {
    // 1. argumentos
    if (argc != 4) {
        std::cerr << "Uso: ./sed <fichero> <s1> <s2>" << std::endl;
        return 1;
    }

    // 2. s1 no vacío
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    if (s1.empty()) {
        std::cerr << "Error: s1 no puede estar vacío" << std::endl;
        return 1;
    }

    // 3-4. abrir entrada
    std::ifstream entrada(argv[1]);
    if (!entrada.is_open()) {
        std::cerr << "Error: no se puede abrir '" << argv[1] << "'" << std::endl;
        return 1;
    }

    // 5-6. crear salida
    std::string nombreSalida = std::string(argv[1]) + ".replace";
    std::ofstream salida(nombreSalida.c_str());
    if (!salida.is_open()) {
        std::cerr << "Error: no se puede crear el fichero de salida" << std::endl;
        entrada.close();
        return 1;
    }

    // 7-9. leer, reemplazar, escribir
    std::string linea;
    while (std::getline(entrada, linea)) {
        // reemplazar todas las ocurrencias
        size_t pos = 0;
        while ((pos = linea.find(s1, pos)) != std::string::npos) {
            linea.erase(pos, s1.length());
            linea.insert(pos, s2);
            pos += s2.length();
        }
        // escribir en el fichero de salida
        salida << linea << "\n";
    }

    // 10. cerrar
    entrada.close();
    salida.close();

    return 0;
}
```

**¿Por qué `"\n"` y no `std::endl`?**

`std::endl` vacía el buffer después de cada línea — operación costosa si el fichero tiene miles de líneas. `"\n"` solo añade el salto de línea sin vaciar el buffer. Para el ex04 ambos funcionan, pero `"\n"` es más eficiente.

---

# PARTE 2 — PUNTEROS A FUNCIONES MIEMBRO (ex05: Harl 2.0)

---

## 10. El problema — el bosque de if/else

El ex05 presenta la clase `Harl` que tiene cuatro mensajes: DEBUG, INFO, WARNING, ERROR. El método `complain(level)` debe llamar al mensaje correspondiente según el nivel.

La solución obvia — prohibida por el subject:

```cpp
void Harl::complain(std::string level) {
    if (level == "DEBUG")
        debug();
    else if (level == "INFO")
        info();
    else if (level == "WARNING")
        warning();
    else if (level == "ERROR")
        error();
    // el "bosque de if/else" que el subject prohíbe
}
```

El subject dice explícitamente: **sin if/else**. Harl no lo piensa dos veces.

La solución elegante usa **punteros a funciones miembro** — una forma de almacenar la dirección de un método de clase y llamarlo dinámicamente.

---

## 11. ¿Qué es un puntero a función?

Antes de entrar en punteros a funciones miembro, repasa los punteros a funciones normales.

En C++ (como en C), las funciones tienen una dirección en memoria — viven en el segmento `.text`. Puedes guardar esa dirección en un puntero y llamar a la función a través de él.

```cpp
void saludar() {
    std::cout << "Hola" << std::endl;
}

void despedir() {
    std::cout << "Adiós" << std::endl;
}

int main() {
    void (*ptr)() = saludar;   // ptr guarda la dirección de saludar
    ptr();                      // llama a saludar() a través del puntero

    ptr = despedir;             // ahora ptr apunta a despedir
    ptr();                      // llama a despedir()
}
```

La sintaxis `void (*ptr)()` se lee así:
- `void` — el tipo de retorno de la función
- `(*ptr)` — ptr es un puntero (los paréntesis son obligatorios)
- `()` — la función no recibe parámetros

¿Para qué sirve esto? Para decidir en tiempo de ejecución qué función llamar — sin if/else. Puedes guardar punteros en arrays y elegir cuál llamar según un índice.

---

## 12. Punteros a funciones normales — ejemplo completo

```cpp
void debug()   { std::cout << "DEBUG"   << std::endl; }
void info()    { std::cout << "INFO"    << std::endl; }
void warning() { std::cout << "WARNING" << std::endl; }
void error()   { std::cout << "ERROR"   << std::endl; }

int main() {
    // array de 4 punteros a función — todos con la misma firma
    void (*funciones[4])() = { debug, info, warning, error };

    // llamar a la función en posición 2 (warning)
    funciones[2]();   // imprime "WARNING"

    // recorrer todas
    for (int i = 0; i < 4; i++) {
        funciones[i]();
    }
}
```

Este patrón — array de punteros a función + índice — elimina completamente el if/else.

---

## 13. Punteros a funciones miembro — la diferencia clave

El problema es que `debug`, `info`, `warning` y `error` son **métodos privados** de `Harl`, no funciones libres. Los punteros a funciones normales no pueden apuntar a métodos de clase.

¿Por qué? Porque los métodos de clase tienen un parámetro oculto: `this`. Cuando llamas a `harl.debug()`, el compilador internamente pasa `&harl` como primer argumento para que el método sepa sobre qué objeto opera. Los punteros a funciones normales no saben nada de esto.

Para apuntar a un método de clase necesitas un **puntero a función miembro**, que incluye la información de a qué clase pertenece.

### La diferencia en memoria

```
Función libre:
  dirección → código de la función

Método de clase:
  dirección → código del método
  + necesita saber qué objeto usar (this)
```

Un puntero a función miembro no es solo una dirección — es una dirección **más la información de que pertenece a una clase concreta**.

---

## 14. La sintaxis completa desglosada

La sintaxis de punteros a funciones miembro es la más extraña de C++. Vamos carácter por carácter.

### Declarar un puntero a método de Harl

```cpp
void (Harl::*ptr)(void);
```

Desglosado:
- `void` — el método devuelve `void`
- `(Harl::*ptr)` — `ptr` es un puntero a algo de la clase `Harl`
- `(void)` — el método no recibe parámetros

Comparación con puntero a función normal:
```cpp
void (*ptr)(void);         // puntero a función normal
void (Harl::*ptr)(void);   // puntero a función miembro de Harl
//        ^^^^^
//   la única diferencia — Harl::
```

### Asignar un método al puntero

```cpp
ptr = &Harl::debug;
```

El `&` delante de `Harl::debug` es **obligatorio** para punteros a funciones miembro (aunque algunos compiladores lo aceptan sin él, el estándar lo requiere).

### Llamar al método a través del puntero

Para llamar a un método a través de un puntero necesitas un objeto de esa clase:

```cpp
Harl harl;

(harl.*ptr)();   // llama al método al que apunta ptr sobre el objeto harl
```

O con un puntero al objeto:
```cpp
Harl *pHarl = new Harl();

(pHarl->*ptr)();   // con puntero al objeto

delete pHarl;
```

Los paréntesis son **obligatorios**:
```cpp
harl.*ptr();     // ❌ ERROR — el compilador lo interpreta mal
(harl.*ptr)();   // ✅ correcto — los paréntesis establecen el orden correcto
```

### La tabla de sintaxis

```cpp
// funciones normales              vs    funciones miembro de Harl

// declarar puntero
void (*ptr)(void);                       void (Harl::*ptr)(void);

// asignar
ptr = funcion;                           ptr = &Harl::debug;

// llamar (con objeto directo)
ptr();                                   (harl.*ptr)();

// llamar (con puntero a objeto)
ptr();                                   (pHarl->*ptr)();
```

---

## 15. Arrays de punteros a funciones miembro

La solución del ex05 combina lo anterior con un array:

```cpp
void (Harl::*metodos[4])(void) = {
    &Harl::debug,
    &Harl::info,
    &Harl::warning,
    &Harl::error
};
```

Desglosado:
- `void` — todos los métodos devuelven `void`
- `(Harl::*metodos[4])` — `metodos` es un array de 4 punteros a miembro de `Harl`
- `(void)` — todos los métodos no reciben parámetros

Esto solo funciona porque los cuatro métodos tienen **la misma firma** (mismo tipo de retorno, mismos parámetros). Si tuvieran firmas distintas, no podrías guardarlos en el mismo array.

---

## 16. Buscar en el array — el patrón del ex05

El método `complain(level)` recibe un string con el nivel y debe llamar al método correspondiente. Sin if/else.

El patrón es usar un array de **strings** paralelo al array de punteros:

```cpp
void Harl::complain(std::string level) {
    // los niveles en el mismo orden que los punteros
    std::string niveles[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

    // los punteros a los métodos correspondientes
    void (Harl::*metodos[4])(void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    // buscar el nivel en el array de strings
    for (int i = 0; i < 4; i++) {
        if (niveles[i] == level) {
            (this->*metodos[i])();   // llamar al método correspondiente
            return;
        }
    }
    // si llegamos aquí, el nivel no existía
    std::cerr << "Nivel desconocido: " << level << std::endl;
}
```

**`this->*metodos[i]`** — dentro de un método de clase, `this` es el puntero al objeto actual. Para llamar al método del array usas `this->*`:

```cpp
(this->*metodos[i])();
// this → puntero al objeto Harl actual
// ->* → operador de acceso a miembro a través de puntero (como ->  pero para función miembro)
// metodos[i] → el puntero al método
// () → llama al método
```

### ¿Por qué no necesitas if/else?

El bucle `for` encuentra el índice `i` donde `niveles[i] == level`. Con ese mismo `i` accedes directamente al método correcto: `metodos[i]`. La búsqueda y la llamada ocurren en el mismo índice — sin necesidad de decir explícitamente "si es DEBUG llama a debug, si es INFO llama a info...".

---

## 17. Por qué esto es mejor que if/else

### Escalabilidad

Si mañana tienes que añadir un nivel "CRITICAL":

**Con if/else:** tienes que encontrar el bloque if/else y añadir otro `else if`. Si hay varios métodos con if/else (por ejemplo si tienes `complain` en varios sitios), tienes que modificarlos todos.

**Con punteros:** añades un string al array de niveles y un puntero al array de métodos. Dos líneas. El resto del código no cambia.

### Extensibilidad

Con punteros, los arrays podrían venir de una configuración externa, un fichero, o ser modificados en tiempo de ejecución. El if/else está fijo en el código — no puede cambiar sin recompilar.

### Limpieza

```cpp
// CON if/else — 8 líneas que hacen lo mismo repetidamente
if (level == "DEBUG")
    debug();
else if (level == "INFO")
    info();
else if (level == "WARNING")
    warning();
else if (level == "ERROR")
    error();

// CON punteros — 1 línea que funciona para cualquier cantidad de métodos
(this->*metodos[i])();
```

### La tabla comparativa

| | if/else | Punteros a función |
|---|---|---|
| **Líneas de código** | Crece con cada caso | Constante |
| **Añadir nuevo nivel** | Modificar el if/else | Añadir entrada al array |
| **Legibilidad** | Repetitivo | Compacto |
| **Escalabilidad** | Mala | Excelente |
| **Velocidad** | O(n) — revisa uno a uno | O(n) — también recorre el array |
| **Flexibilidad** | Fija en compilación | Puede ser dinámica |

---

## 18. Glosario completo de ex04 y ex05

### Ex04 — Streams de ficheros

| Término | Definición |
|---|---|
| **Stream** | Abstracción para secuencias de datos — pantalla, teclado, fichero, todos funcionan igual |
| **`std::ifstream`** | Input file stream — abre un fichero para leer |
| **`std::ofstream`** | Output file stream — crea/abre un fichero para escribir |
| **`std::fstream`** | File stream bidireccional — leer y escribir |
| **`is_open()`** | Método que devuelve true si el fichero se abrió correctamente |
| **`close()`** | Cierra el fichero y vacía el buffer pendiente |
| **`std::getline(stream, string)`** | Lee una línea completa del stream hasta '\n' |
| **`fail()`** | Devuelve true si alguna operación de E/S falló |
| **`std::ios::app`** | Modo de apertura para añadir al final sin borrar el contenido |
| **`std::string::find(s, pos)`** | Busca s en el string a partir de pos — devuelve la posición o npos |
| **`std::string::npos`** | Constante especial que significa "no encontrado" |
| **`std::string::erase(pos, n)`** | Borra n caracteres desde la posición pos |
| **`std::string::insert(pos, s)`** | Inserta el string s en la posición pos |
| **`std::string::substr(pos, n)`** | Devuelve n caracteres desde la posición pos |
| **`std::string::length()`** | Número de caracteres del string |
| **`size_t`** | Tipo entero sin signo — el que devuelven find y length |
| **`.c_str()`** | Convierte std::string a const char * (necesario en C++98 para abrir ficheros) |
| **Buffer** | Zona de memoria temporal donde se acumula la E/S antes de procesarse |
| **Flush** | Vaciar el buffer y escribir los datos pendientes |
| **`std::endl`** | Salto de línea + flush del buffer |
| **`"\n"`** | Solo salto de línea, sin flush — más eficiente para muchas escrituras |
| **`std::cerr`** | Stream de error estándar — para mensajes de error, no se redirige con > |

### Ex05 — Punteros a funciones miembro

| Término | Definición |
|---|---|
| **Puntero a función** | Variable que guarda la dirección de una función libre |
| **Puntero a función miembro** | Variable que guarda la dirección de un método de clase |
| **`void (*ptr)()`** | Declaración de puntero a función que devuelve void y no recibe args |
| **`void (Clase::*ptr)()`** | Declaración de puntero a función miembro de Clase |
| **`ptr = &Clase::metodo`** | Asignar un método al puntero (& obligatorio en el estándar) |
| **`(objeto.*ptr)()`** | Llamar al método del puntero sobre un objeto directo |
| **`(puntero->*ptr)()`** | Llamar al método del puntero a través de un puntero al objeto |
| **`(this->*ptr)()`** | Llamar al método del puntero desde dentro de la propia clase |
| **Firma de función** | La combinación de tipo de retorno + parámetros — debe ser igual en todos los punteros del array |
| **Array paralelo** | Técnica de usar dos arrays con los mismos índices — uno de strings, otro de punteros |
| **Tabla de despacho** | Término técnico para el patrón de array de punteros a función |
| **Escalabilidad** | Capacidad de crecer sin que el código se complique — los punteros escalan mejor que if/else |

---

# APÉNDICE — Estructura de archivos de ex04 y ex05

### ex04: Sed is for losers

```
ex04/
├── Makefile
├── main.cpp          ← toda la lógica o llama a funciones auxiliares
└── (opcionales: replace.hpp, replace.cpp si separas la lógica)

Flujo del programa:
  argv[1] → nombre del fichero de entrada
  argv[2] → s1 (string a buscar)
  argv[3] → s2 (string a insertar)

  Comprobaciones → abrir fichero → crear fichero.replace →
  mientras haya líneas:
    reemplazar s1 por s2 (sin std::string::replace)
    escribir línea en fichero.replace
  cerrar ficheros
```

### ex05: Harl 2.0

```
ex05/
├── Makefile
├── Harl.hpp          ← clase Harl con métodos privados y complain público
├── Harl.cpp          ← implementación con array de punteros a función miembro
└── main.cpp          ← llama a harl.complain("DEBUG") etc.

Harl.hpp:
  class Harl {
    private:
      void debug(void);
      void info(void);
      void warning(void);
      void error(void);
    public:
      void complain(std::string level);
  };

Harl.cpp complain():
  std::string niveles[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
  void (Harl::*metodos[4])(void) = {
      &Harl::debug, &Harl::info, &Harl::warning, &Harl::error
  };
  for (int i = 0; i < 4; i++) {
      if (niveles[i] == level) {
          (this->*metodos[i])();
          return;
      }
  }
```
