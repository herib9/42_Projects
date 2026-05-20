# C++ — Temario Completo CPP00
## Todo lo que necesitas saber para el Módulo 00

---

# ÍNDICE

1. ¿Qué es C++ y cómo difiere de C?
2. El léxico completo — palabras clave y símbolos nuevos
3. Namespaces — qué es std::
4. Entrada y salida — cout, cin, cerr
5. std::string — todo en profundidad
6. argc y argv — argumentos del programa
7. Clases — el concepto central
8. .hpp y .cpp — cómo separar el código
9. Include guards y pragma once
10. Constructores
11. Destructores
12. El puntero this
13. private y public — encapsulación
14. Getters y Setters
15. static — atributos y métodos de clase
16. const — métodos constantes
17. Arrays de objetos (sin memoria dinámica)
18. iomanip — formatear la salida
19. Glosario completo

---

# PARTE 1 — LOS FUNDAMENTOS

---

## 1. ¿Qué es C++ y cómo difiere de C?

C++ es una extensión de C creada por Bjarne Stroustrup. La idea fue tomar C — que ya era potente a bajo nivel — y añadirle una forma de organizar el código más grande y complejo: la **Programación Orientada a Objetos** (OOP).

Por eso al principio se llamó "C with Classes" — C con clases.

Todo lo que sabes de C sigue funcionando en C++. Las variables, los bucles, los punteros, las funciones, los arrays — todo está. Lo que C++ añade encima es la posibilidad de crear **clases**, que son moldes para crear objetos que agrupan datos y funciones juntos de forma organizada.

### ¿Qué cambia visualmente respecto a C?

```c
// C — así imprimías
printf("Hola %s\n", nombre);

// C++ — así imprimes
std::cout << "Hola " << nombre << std::endl;
```

```c
// C — así leías entrada
scanf("%s", buffer);

// C++ — así lees entrada
std::cin >> variable;
```

```c
// C — archivos de cabecera
#include <stdio.h>
#include <string.h>

// C++ — archivos de cabecera
#include <iostream>
#include <string>
```

En 42 trabajas con el estándar **C++98** — la versión más antigua y estricta. Esto es intencionado: te obliga a entender los fundamentos sin atajos modernos. Además, en CPP00 están prohibidas las funciones de C: `printf`, `malloc`, `free`. Tienes que usar las alternativas de C++.

---

## 2. El léxico completo — palabras clave y símbolos nuevos

Antes de escribir código necesitas conocer el vocabulario. Aquí están todos los términos nuevos que aparecen en CPP00.

### Palabras clave nuevas

| Palabra | Significado |
|---|---|
| `class` | Define una clase — un molde para crear objetos |
| `public` | Lo que es accesible desde fuera de la clase |
| `private` | Lo que solo es accesible desde dentro de la clase |
| `this` | Puntero especial al objeto actual dentro de un método |
| `const` | Indica que algo no puede modificarse |
| `static` | Pertenece a la clase, no a un objeto concreto |
| `bool` | Tipo booleano — solo vale `true` o `false` |
| `true` | Verdadero (equivale a 1) |
| `false` | Falso (equivale a 0) |

### Operadores nuevos

| Operador | Nombre | Uso |
|---|---|---|
| `::` | Resolución de ámbito | `PhoneBook::addContact()` — indica a qué clase pertenece |
| `.` | Acceso a miembro | `contact.getName()` — objeto directo |
| `<<` | Inserción | `std::cout << "hola"` — manda datos a la salida |
| `>>` | Extracción | `std::cin >> variable` — lee datos de la entrada |

### Símbolos importantes en la estructura de clase

```cpp
class PhoneBook {
//              ^-- el cuerpo empieza aquí
    private:    // sección privada
        // ...
    public:     // sección pública
        // ...
};              // <-- el punto y coma al final es OBLIGATORIO
```

El punto y coma después de `}` en una clase es único en C++ — en las funciones normales no lo pones, pero en las clases sí.

---

## 3. Namespaces — qué es std::

Imagina que en una empresa hay dos empleados llamados García. Cuando alguien dice "llama a García", nadie sabe cuál. Para distinguirlos dices "García del departamento de ventas" o "García del departamento técnico".

Un **namespace** (espacio de nombres) es exactamente eso — una etiqueta que agrupa nombres para evitar conflictos.

La librería estándar de C++ mete todo dentro de un namespace llamado `std`. Por eso escribes:

```cpp
std::cout    // el cout del namespace std
std::cin     // el cin del namespace std
std::string  // el string del namespace std
std::endl    // el endl del namespace std
```

El `::` es el operador que dice "dentro de". Así que `std::cout` se lee "el `cout` que está dentro de `std`".

### ¿Por qué no usar `using namespace std`?

Existe un atajo para no escribir `std::` cada vez:

```cpp
using namespace std;
cout << "Hola" << endl;   // ya no necesitas std::
```

**En 42 esto está PROHIBIDO en los headers (`.hpp`)** y muy desaconsejado en general. El motivo: si tu proyecto usa dos namespaces distintos que tienen funciones con el mismo nombre, el compilador no sabe cuál usar y se lía. Es una fuente de bugs difíciles de detectar.

La regla de oro en 42: **escribe siempre `std::` explícitamente.**

### Crear tu propio namespace

En el ex00 de CPP00 (Megaphone) el subject menciona namespaces. Puedes crear el tuyo:

```cpp
namespace MegafoneUtils {
    void convertirMayusculas(std::string &texto);
}

// para usarlo:
MegafoneUtils::convertirMayusculas(mi_texto);
```

---

## 4. Entrada y salida — cout, cin, cerr

Para usar estos necesitas:
```cpp
#include <iostream>
```

### std::cout — salida estándar (pantalla)

`cout` significa *character output*. Es el objeto que representa la pantalla.

```cpp
std::cout << "Hola mundo" << std::endl;
```

Desglosado:
- `std::cout` — el objeto pantalla
- `<<` — el operador de inserción. "Manda esto a la pantalla"
- `"Hola mundo"` — lo que mandas
- `std::endl` — salta de línea y vacía el buffer

Puedes encadenar varios `<<`:
```cpp
std::string nombre = "Alice";
int edad = 25;
std::cout << "Nombre: " << nombre << ", Edad: " << edad << std::endl;
// imprime: Nombre: Alice, Edad: 25
```

### std::endl vs '\n'

Ambos saltan de línea, pero hay una diferencia:
- `'\n'` — solo salta de línea
- `std::endl` — salta de línea **y además vacía el buffer**

El buffer es una zona de memoria temporal donde se acumula lo que vas a imprimir antes de que aparezca en pantalla. Vaciarlo (`flush`) garantiza que lo que mandas aparece inmediatamente.

En práctica para 42: usa `std::endl`. Es más seguro aunque ligeramente más lento.

### std::cin — entrada estándar (teclado)

`cin` significa *character input*. Es el objeto que representa el teclado.

```cpp
std::string nombre;
std::cin >> nombre;   // espera a que el usuario escriba algo y pulse Enter
```

**Problema importante**: `std::cin >> variable` lee hasta el primer espacio. Si el usuario escribe "Hola mundo", solo guardará "Hola".

Para leer una línea entera incluyendo espacios:
```cpp
std::string frase;
std::getline(std::cin, frase);   // lee toda la línea hasta el Enter
```

### El problema de mezclar cin >> y getline

Este es un bug clásico que aparece en el PhoneBook:

```cpp
int numero;
std::cin >> numero;       // el usuario escribe "5" y pulsa Enter
                          // cin lee el "5" pero deja el '\n' en el buffer

std::string nombre;
std::getline(std::cin, nombre);   // lee el '\n' que quedó → nombre queda vacío!
```

La solución: limpiar el buffer después de `cin >>`:
```cpp
std::cin >> numero;
std::cin.ignore();        // ignora el '\n' que quedó en el buffer
std::getline(std::cin, nombre);   // ahora sí lee correctamente
```

O mejor: usar siempre `std::getline` para todo y convertir cuando necesites un número.

### std::cerr — salida de errores

`cerr` significa *character error*. Funciona igual que `cout` pero está pensado para mensajes de error — va a la salida de errores estándar en lugar de la salida normal:

```cpp
std::cerr << "Error: el archivo no existe" << std::endl;
```

---

## 5. std::string — todo en profundidad

Para usarlo:
```cpp
#include <string>
```

En C, las cadenas de texto eran arrays de `char` terminados en `'\0'`. Gestionarlas era incómodo — tamaño fijo, `strlen`, `strcpy`, `strcat`...

En C++, `std::string` es una clase que gestiona todo automáticamente. Tú solo escribes texto y ella se ocupa del resto.

```cpp
std::string nombre = "Alice";   // sin preocuparte del tamaño ni del '\0'
```

### Operaciones fundamentales

**Crear y asignar:**
```cpp
std::string a = "Alice";          // inicialización directa
std::string b("Bob");             // otra forma
std::string c = b;                // copia
std::string vacio = "";           // string vacío
std::string vacio2;               // también vacío — valor por defecto es ""
```

**Concatenar (unir strings):**
```cpp
std::string nombre = "Alice";
std::string apellido = "Smith";
std::string completo = nombre + " " + apellido;   // "Alice Smith"

nombre += " Cooper";   // añadir al final — nombre ahora es "Alice Cooper"
```

**Tamaño:**
```cpp
std::string texto = "Alice";
int n = texto.length();   // 5
int m = texto.size();     // también 5 — son exactamente equivalentes
```

**Comprobar si está vacío:**
```cpp
std::string texto = "";
if (texto.empty())
    std::cout << "Está vacío" << std::endl;

// equivale a:
if (texto.length() == 0)
    std::cout << "Está vacío" << std::endl;
```

**Acceder a un carácter:**
```cpp
std::string texto = "Alice";
//                   01234    ← índices

char primera = texto[0];    // 'A'
char segunda = texto[1];    // 'l'
char ultima  = texto[4];    // 'e'
```

Los índices empiezan en 0, igual que en C con los arrays.

**Comparar:**
```cpp
std::string a = "ADD";
std::string b = "ADD";
std::string c = "SEARCH";

if (a == b)    // true — son iguales
if (a != c)    // true — son distintos
if (a == "ADD") // también funciona — comparar con string literal
```

En C necesitabas `strcmp`. En C++ puedes usar `==` directamente. Mucho más limpio.

**Buscar dentro del string:**
```cpp
std::string frase = "Hola Alice mundo";
int pos = frase.find("Alice");   // devuelve 5 — posición donde empieza

if (frase.find("zombie") == std::string::npos)
    std::cout << "No encontrado" << std::endl;
```

`std::string::npos` es una constante especial que significa "no encontrado". Es el valor que devuelve `find` cuando la búsqueda falla.

**Extraer parte del string (substring):**
```cpp
std::string texto = "Hola Alice mundo";
//                   0123456789...

std::string trozo = texto.substr(5, 5);
// substr(posición_inicio, cantidad_caracteres)
// desde posición 5, coge 5 caracteres → "Alice"
```

**Convertir a número y viceversa:**

En C++98 no hay `std::stoi` (es C++11). Tienes que usar stringstream:
```cpp
#include <sstream>

// número a string
int numero = 42;
std::stringstream ss;
ss << numero;
std::string texto = ss.str();   // "42"

// string a número
std::string s = "42";
std::stringstream ss2(s);
int n;
ss2 >> n;   // n = 42
```

### Convertir a mayúsculas — el método del CPP00

El ex00 (Megaphone) necesita convertir todo a mayúsculas. `std::string` no tiene un método directo para esto. Tienes que recorrer carácter por carácter:

```cpp
#include <cctype>   // para toupper y tolower

std::string texto = "hola alice";

for (int i = 0; i < (int)texto.length(); i++) {
    texto[i] = toupper(texto[i]);
}
std::cout << texto << std::endl;   // HOLA ALICE
```

- `toupper(c)` — convierte un `char` a su versión mayúscula. Si ya es mayúscula, lo deja igual. Si es un dígito o símbolo, lo deja igual.
- `tolower(c)` — convierte un `char` a su versión minúscula.

Estas funciones trabajan con un solo carácter a la vez — por eso el bucle.

**¿Por qué el cast `(int)texto.length()`?**

`texto.length()` devuelve un tipo `size_t`, que es un entero sin signo. Compararlo con `int i` puede dar warnings porque mezclas tipos con/sin signo. El cast elimina el warning.

### Moverse por un string — tres formas

**Forma 1: con índice (la más simple):**
```cpp
std::string texto = "Alice";

for (int i = 0; i < (int)texto.length(); i++) {
    std::cout << texto[i];   // accedes como array
}
```

**Forma 2: con iterador (la forma C++ estándar):**
```cpp
std::string texto = "Alice";
std::string::iterator it;

for (it = texto.begin(); it != texto.end(); it++) {
    std::cout << *it;   // *it da el carácter actual
}
```

**Forma 3: con iterador constante (cuando no vas a modificar):**
```cpp
std::string texto = "Alice";
std::string::const_iterator it;

for (it = texto.begin(); it != texto.end(); it++) {
    std::cout << *it;
}
```

### Los iteradores — qué son y cómo funcionan

Un **iterador** es como un cursor que señala a un elemento dentro de una colección. Para un string, señala a un carácter concreto.

Piénsalo como el cursor parpadeante en un editor de texto — está en una posición concreta, puedes moverlo hacia adelante o hacia atrás, y en cada posición lees o modificas el carácter que hay allí.

```
texto = "Alice"
         ^   ^
         |   |
      begin() end()
```

Los cuatro iteradores de `std::string`:

| Iterador | Apunta a... |
|---|---|
| `texto.begin()` | El primer carácter ('A') |
| `texto.end()` | La posición DESPUÉS del último — imaginaria, no existe |
| `texto.rbegin()` | El último carácter ('e') — para recorrer al revés |
| `texto.rend()` | La posición ANTES del primero — para recorrer al revés |

**IMPORTANTE**: `end()` no apunta al último carácter. Apunta a una posición imaginaria después de él. Por eso el bucle es `it != texto.end()` (diferente de end) y no `it <= texto.end()` (menor o igual).

**Operaciones sobre iteradores:**

```cpp
std::string::iterator it = texto.begin();

it++;    // avanza al siguiente carácter
it--;    // retrocede al carácter anterior
*it      // el carácter al que apunta (desreferenciar)
*it = 'X';  // modifica el carácter al que apunta
```

**Recorrer modificando con iterador:**
```cpp
std::string texto = "Alice";
std::string::iterator it;

for (it = texto.begin(); it != texto.end(); it++) {
    *it = toupper(*it);   // convierte cada carácter a mayúscula
}
// texto ahora es "ALICE"
```

**¿Cuándo usar iteradores vs índices?**

Para strings simples en CPP00, los índices son más claros y directos. Los iteradores son la forma universal de C++ para recorrer cualquier tipo de colección (strings, listas, mapas...) y funcionan igual en todas. En módulos avanzados (08, 09) los usarás más con contenedores STL.

---

## 6. argc y argv — argumentos del programa

En C ya los conocías. En C++ funcionan exactamente igual:

```cpp
int main(int argc, char **argv) {
    // argc — número de argumentos (incluye el nombre del programa)
    // argv — array de strings con los argumentos
}
```

El ex00 (Megaphone) los usa así:

```
./megaphone "hola mundo" "esto es un test"
argc = 3
argv[0] = "./megaphone"
argv[1] = "hola mundo"
argv[2] = "esto es un test"
```

Para convertir `argv[i]` (que es `char *`) a `std::string`:
```cpp
std::string argumento = argv[1];   // conversión automática
```

Para recorrer todos los argumentos:
```cpp
int main(int argc, char **argv) {
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }

    for (int i = 1; i < argc; i++) {
        std::string argumento = argv[i];
        for (int j = 0; j < (int)argumento.length(); j++) {
            std::cout << (char)toupper(argumento[j]);
        }
    }
    std::cout << std::endl;
    return 0;
}
```

---

# PARTE 2 — CLASES

---

## 7. Clases — el concepto central

Una **clase** es un molde para crear objetos. Define qué datos tiene cada objeto y qué puede hacer.

Analogía: una clase es el plano de un apartamento. El plano en sí no es un apartamento — es la descripción de cómo construirlo. Cada apartamento construido siguiendo ese plano es un **objeto** (también llamado **instancia**).

En el PhoneBook tienes dos clases:
- `Contact` — el plano de un contacto. Define que cada contacto tiene nombre, apellido, apodo, teléfono y secreto
- `PhoneBook` — el plano de la agenda. Define que tiene un array de contactos y puede añadir/buscar

```cpp
class Contact {
    // aquí defines qué tiene y qué puede hacer un Contact
};

Contact alice;   // alice es un objeto de tipo Contact
Contact bob;     // bob es otro objeto de tipo Contact
```

`alice` y `bob` son dos objetos distintos, cada uno con sus propios datos, pero creados con el mismo molde.

### La diferencia entre clase y struct en C++

En C usabas `struct` para agrupar datos. Las clases hacen lo mismo pero añaden dos cosas fundamentales:

**1. Métodos** — funciones que pertenecen al objeto:
```cpp
class Contact {
    public:
        std::string nombre;
        void mostrar() {           // este método es del objeto
            std::cout << nombre;   // puede acceder a los datos directamente
        }
};
```

**2. Encapsulación** — control de acceso con `private` y `public`:
```cpp
class Contact {
    private:
        std::string _nombre;   // nadie de fuera puede tocarlo directamente
    public:
        void mostrar();        // esto sí pueden usarlo desde fuera
};
```

Técnicamente en C++ la diferencia entre `struct` y `class` es solo que en `struct` todo es público por defecto y en `class` todo es privado por defecto. Pero por convención, usamos `class` cuando queremos encapsulación y `struct` para datos simples sin lógica.

### La nomenclatura en 42

- Nombres de clase en **UpperCamelCase**: `Contact`, `PhoneBook`, `Account`
- Nombres de atributos privados con guión bajo: `_nombre`, `_telefono`, `_index`
- Nombres de métodos en **lowerCamelCase**: `getName`, `addContact`, `displayAll`
- Archivos nombrados igual que la clase: `Contact.hpp`, `Contact.cpp`, `PhoneBook.hpp`, `PhoneBook.cpp`

---

## 8. .hpp y .cpp — cómo separar el código

En C++ los archivos de clase se dividen en dos:

**El `.hpp` (header / cabecera):** declara qué existe. Dice qué tiene la clase y qué puede hacer. No dice cómo funciona.

**El `.cpp` (implementación):** define cómo funciona cada cosa declarada en el `.hpp`.

```
Contact.hpp  →  "Contact tiene _nombre y puede getName()"
Contact.cpp  →  "así es como funciona getName()"
```

¿Por qué separar? Porque cuando `PhoneBook.cpp` usa la clase `Contact`, solo necesita incluir `Contact.hpp` — no necesita saber cómo está implementada por dentro. Es como un contrato: el `.hpp` promete lo que la clase hace, el `.cpp` cumple esa promesa.

### Estructura del .hpp

```cpp
#pragma once                        // evita doble inclusión (ver sección 9)

#include <string>                   // dependencias necesarias
#include <iostream>

class Contact {
    private:                        // sección privada — datos protegidos
        std::string _firstName;
        std::string _lastName;
        std::string _nickname;
        std::string _phoneNumber;
        std::string _darkestSecret;

    public:                         // sección pública — lo que el mundo puede usar
        Contact();                  // constructor
        ~Contact();                 // destructor

        void setFirstName(std::string name);
        std::string getFirstName(void) const;
        bool isEmpty(void) const;
};
```

### Estructura del .cpp

```cpp
#include "Contact.hpp"              // incluye su propio header

Contact::Contact() {                // implementación del constructor
    // inicialización si es necesaria
}

Contact::~Contact() {               // implementación del destructor
}

void Contact::setFirstName(std::string name) {
    _firstName = name;
}

std::string Contact::getFirstName(void) const {
    return _firstName;
}

bool Contact::isEmpty(void) const {
    return _firstName.empty();
}
```

El `Contact::` antes de cada método es el **operador de resolución de ámbito** (`::`) — le dice al compilador que este método pertenece a la clase `Contact`. Sin él, el compilador pensaría que son funciones libres sueltas sin relación con ninguna clase.

---

## 9. Include guards y pragma once

Si el mismo `.hpp` se incluye desde varios archivos `.cpp`, el compilador intentaría procesarlo varias veces — y al encontrar la misma clase declarada dos veces, daría error.

Los **include guards** evitan este problema.

### Forma clásica con #ifndef

```cpp
#ifndef CONTACT_HPP
#define CONTACT_HPP

// ... contenido del header

#endif
```

Cómo funciona:
1. Primera vez que el compilador lee `Contact.hpp`: `CONTACT_HPP` no existe → entra, lo define, procesa el contenido
2. Si intenta leerlo una segunda vez: `CONTACT_HPP` ya existe → se salta todo el contenido

El nombre del guard (`CONTACT_HPP`) tiene que ser único en el proyecto. La convención es `NOMBRE_ARCHIVO_HPP` en mayúsculas.

### Forma moderna con #pragma once

```cpp
#pragma once

// ... contenido del header
```

Una sola línea que hace lo mismo. No es parte del estándar oficial de C++ pero todos los compiladores modernos lo soportan. En 42 funciona perfectamente y es más limpia.

### Regla importante

**Nunca pongas implementaciones de funciones en un `.hpp`.**

Si defines el cuerpo de una función en el header, ese código se copia en todos los archivos que incluyan ese header — causando el error "multiple definition" (definición múltiple).

```cpp
// MAL — implementación en el .hpp
class Contact {
    public:
        std::string getFirstName() {
            return _firstName;   // ❌ esto no va aquí
        }
};

// BIEN — solo declaración en el .hpp
class Contact {
    public:
        std::string getFirstName() const;   // ✅ solo la firma
};
// la implementación va en Contact.cpp
```

---

## 10. Constructores

Un **constructor** es una función especial que se ejecuta **automáticamente** cuando se crea un objeto. Su trabajo es dejarlo en un estado válido y listo para usar.

```cpp
// en Contact.hpp
class Contact {
    public:
        Contact();                    // constructor por defecto
        Contact(std::string nombre);  // constructor con parámetros
};

// en Contact.cpp
Contact::Contact() {
    // objeto creado sin parámetros — inicializamos con valores por defecto
    _firstName = "";
    _lastName  = "";
}

Contact::Contact(std::string nombre) {
    _firstName = nombre;
}
```

Cuando haces:
```cpp
Contact alice;              // se llama al constructor por defecto
Contact bob("Bob");         // se llama al constructor con parámetros
```

El constructor se llama automáticamente — tú no lo llamas explícitamente.

### Características del constructor

- **Mismo nombre que la clase** — siempre
- **Sin tipo de retorno** — ni siquiera `void`
- **Se llama automáticamente** — al crear el objeto
- **Puede sobrecargarse** — puedes tener varios con distintos parámetros
- **El compilador crea uno vacío automáticamente** si no defines ninguno — pero en cuanto defines uno, el automático desaparece

### La lista de inicialización

Es una forma más eficiente de inicializar atributos. Va entre los paréntesis del constructor y el cuerpo `{ }`:

```cpp
Contact::Contact() : _firstName(""), _lastName(""), _nickname("") {
    // el cuerpo puede estar vacío
}
```

El `: _firstName(""), _lastName(""), _nickname("")` significa: "antes de ejecutar el cuerpo `{ }`, inicializa estos atributos con estos valores".

Es más eficiente que asignar dentro del cuerpo porque evita construir el objeto con valor por defecto y luego sobreescribirlo — lo construye directamente con el valor correcto.

Para múltiples atributos, se separan por comas:
```cpp
Contact::Contact(std::string first, std::string last)
    : _firstName(first), _lastName(last), _nickname(""), _phoneNumber("") {
}
```

### ¿Por qué en el PhoneBook necesitas el constructor por defecto?

Porque `PhoneBook` tiene un array de `Contact`:
```cpp
class PhoneBook {
    private:
        Contact _contacts[8];   // array de 8 Contact
};
```

Cuando el compilador crea el array de 8 `Contact`, necesita construir cada uno. No te pasa ningún parámetro. Necesita el constructor sin parámetros. Si no lo tienes, error de compilación.

---

## 11. Destructores

El **destructor** es lo opuesto del constructor. Se ejecuta **automáticamente** cuando el objeto va a ser destruido.

```cpp
// en Contact.hpp
class Contact {
    public:
        ~Contact();   // la tilde ~ indica destructor
};

// en Contact.cpp
Contact::~Contact() {
    // aquí liberas recursos si los hay
    // en el PhoneBook no hay nada que liberar
}
```

### Características del destructor

- **Tilde `~` delante del nombre** — siempre
- **Sin parámetros** — nunca recibe nada
- **Sin tipo de retorno** — ni siquiera `void`
- **Solo puede haber uno** — no se puede sobrecargar
- **Se llama automáticamente** — al destruir el objeto

### Cuándo se llama

En CPP00 trabajas sin `new`/`delete` (memoria dinámica está prohibida en el PhoneBook). Los objetos viven en el stack:

```cpp
int main() {
    PhoneBook book;    // constructor de PhoneBook llamado
                       // también constructores de los 8 Contact del array
    // ...
    return 0;
}   // al salir del main:
    // → destructores de los 8 Contact llamados
    // → destructor de PhoneBook llamado
```

Los objetos del stack se destruyen en **orden inverso** a como fueron creados (LIFO — Last In First Out):

```cpp
Contact a;   // creado primero
Contact b;   // creado segundo
// al salir del scope:
// → b destruido primero
// → a destruida después
```

### ¿Para qué sirve el destructor en la práctica?

En el PhoneBook no hace nada especial porque no hay memoria dinámica. Pero es buena práctica definirlo siempre. En proyectos más avanzados (cuando uses `new`), el destructor es donde haces `delete` de todo lo que reservaste.

---

## 12. El puntero this

`this` es un puntero especial que existe dentro de cualquier método de clase. Apunta al objeto concreto sobre el que ese método está siendo llamado en ese momento.

```cpp
void Contact::setFirstName(std::string name) {
    this->_firstName = name;
}
```

Si tienes tres contactos y llamas a `alice.setFirstName("Alice")`, dentro de ese método `this` apunta a `alice`. Si llamas a `bob.setFirstName("Bob")`, `this` apunta a `bob`. El mismo código, pero `this` cambia según quién lo ejecuta.

### ¿Cuándo usar `this->` y cuándo no?

Dentro de un método puedes escribir `_firstName` o `this->_firstName` — ambos significan lo mismo cuando no hay ambigüedad.

Pero hay un caso donde sí es útil: cuando el nombre del parámetro y el atributo se parecen o son iguales:

```cpp
void Contact::setFirstName(std::string firstName) {
    //                              ↑ mismo nombre que el atributo sin _
    this->_firstName = firstName;   // this-> hace clara la distinción
}
```

Por eso en 42 se usa `_` en los atributos — para distinguirlos visualmente de los parámetros sin necesidad de `this->` todo el rato.

---

## 13. private y public — encapsulación

La **encapsulación** es uno de los pilares de la OOP. Significa que los datos de un objeto están protegidos — nadie de fuera puede tocarlos directamente. Solo el objeto puede modificarse a sí mismo, a través de los métodos que expone.

```cpp
class Contact {
    private:
        std::string _firstName;   // protegido — solo Contact puede tocarlo

    public:
        std::string getFirstName() const;   // accesible desde cualquier sitio
        void setFirstName(std::string name);
};
```

Si alguien intenta acceder desde fuera:
```cpp
Contact c;
c._firstName = "Alice";   // ❌ ERROR — _firstName es private
c.setFirstName("Alice");  // ✅ correcto — setFirstName es public
```

### ¿Por qué proteger los datos?

Sin protección, cualquiera puede poner cualquier basura en los atributos:
```cpp
// sin protección
contact._firstName = "";          // nombre vacío — estado inválido
contact._phoneNumber = "abc123";  // teléfono inválido
contact._firstName = "   ";       // solo espacios
```

Con un setter puedes **validar** antes de guardar:
```cpp
void Contact::setFirstName(std::string name) {
    if (name.empty())    // si está vacío, no lo guardo
        return;
    _firstName = name;  // solo guardo si es válido
}
```

La clase controla su propio estado. Nadie puede dejarlo en un estado inválido sin que la clase lo sepa.

### ¿Qué va en private y qué en public?

**private:**
- Todos los atributos (datos) — casi siempre
- Métodos auxiliares internos que solo usa la propia clase

**public:**
- Constructor y destructor — para poder crear y destruir objetos desde fuera
- Getters — para que otros puedan leer los datos
- Setters — para que otros puedan modificar los datos de forma controlada
- Métodos que el usuario de la clase necesita llamar (como `addContact`, `searchContact`)

En el PhoneBook:
```
PhoneBook
    private:
        Contact _contacts[8]   ← nadie de fuera debe tocar el array directamente
        int _nextIndex         ← control interno de dónde añadir el siguiente
    public:
        addContact()           ← el main llama a esto
        searchContact()        ← el main llama a esto

Contact
    private:
        _firstName, _lastName, _nickname, _phoneNumber, _darkestSecret
    public:
        getters y setters para cada campo
        isEmpty() para saber si el contacto está vacío
```

---

## 14. Getters y Setters

Como los atributos son privados, necesitas métodos para leerlos y modificarlos desde fuera.

**Getter** — para leer un atributo:
```cpp
// en Contact.hpp
std::string getFirstName(void) const;

// en Contact.cpp
std::string Contact::getFirstName(void) const {
    return _firstName;
}

// uso:
Contact c;
std::cout << c.getFirstName() << std::endl;
```

**Setter** — para modificar un atributo:
```cpp
// en Contact.hpp
void setFirstName(std::string name);

// en Contact.cpp
void Contact::setFirstName(std::string name) {
    _firstName = name;
}

// uso:
Contact c;
c.setFirstName("Alice");
```

### La convención de nombres

- **Getters**: `get` + NombreAtributo → `getFirstName`, `getLastName`, `getPhoneNumber`
- **Setters**: `set` + NombreAtributo → `setFirstName`, `setLastName`, `setPhoneNumber`

No es obligatorio — son nombres que tú decides. Pero es una convención tan universal que en 42 y en el mundo real todos la esperan.

### El `const` en los getters

```cpp
std::string Contact::getFirstName(void) const {
//                                       ^^^^ este const
    return _firstName;
}
```

El `const` al final de la firma del método significa: **"este método no modifica ningún atributo del objeto"**. Es una promesa al compilador.

Los getters solo leen datos — no modifican nada — así que deben marcarse como `const`. Esto permite llamarlos sobre objetos que también son `const`:

```cpp
const Contact c;           // objeto constante — no se puede modificar
c.getFirstName();          // ✅ funciona porque getFirstName es const
c.setFirstName("Alice");   // ❌ ERROR — setFirstName no es const
```

Si intentas modificar un atributo dentro de un método marcado como `const`, el compilador da error. Es una red de seguridad.

---

## 15. static — atributos y métodos de clase

`static` en el contexto de una clase significa que algo pertenece a **la clase en sí**, no a ningún objeto concreto.

### Atributo static

Un atributo normal existe en cada objeto:
```cpp
Contact alice;   // alice tiene su propio _firstName
Contact bob;     // bob tiene su propio _firstName
// son cosas distintas en memoria
```

Un atributo `static` existe **una sola vez**, compartido por todos los objetos de la clase:
```cpp
class Account {
    private:
        static int _nbAccounts;   // existe una sola vez para TODOS los Account
        int _accountIndex;        // cada Account tiene el suyo propio
};

// inicialización FUERA de la clase (obligatorio):
int Account::_nbAccounts = 0;
```

```cpp
Account a1;   // _nbAccounts pasa a 1
Account a2;   // _nbAccounts pasa a 2
Account a3;   // _nbAccounts pasa a 3
// los tres comparten el mismo _nbAccounts
```

**¿Para qué sirve?** El ex02 de CPP00 (Account) lo usa para llevar la cuenta total de cuántas cuentas existen, cuánto dinero hay en total, etc. — datos que son de "toda la clase", no de ninguna cuenta concreta.

### Inicialización del atributo static

Esto es una particularidad importante: los atributos `static` deben inicializarse **fuera** de la clase, en el `.cpp`:

```cpp
// en Account.hpp — solo la declaración
class Account {
    static int _nbAccounts;
};

// en Account.cpp — la inicialización
int Account::_nbAccounts = 0;
```

Si no lo inicializas fuera, el compilador da error de "undefined reference".

### Método static

Un método `static` puede llamarse **sin crear ningún objeto**:

```cpp
class Account {
    public:
        static int getNbAccounts();   // método estático
};

int Account::getNbAccounts() {
    return _nbAccounts;
}

// llamada SIN crear ningún Account:
std::cout << Account::getNbAccounts() << std::endl;
```

Un método `static` **no tiene acceso a `this`** — no pertenece a ningún objeto concreto, así que no sabe a cuál apuntar. Solo puede acceder a atributos `static`.

### En el PhoneBook — ¿por qué no usar static?

El subject del PhoneBook dice que la **memoria dinámica está prohibida**. El array de contactos no es dinámico — es estático (de tamaño fijo):

```cpp
class PhoneBook {
    private:
        Contact _contacts[8];   // array estático — tamaño fijo, en el stack
        int _nextIndex;
};
```

Este array **no** usa `static` en el sentido de atributo de clase — es simplemente un array de tamaño fijo que vive en el stack. No confundas "array estático" (tamaño fijo) con "atributo static" (compartido por todos los objetos).

---

## 16. const — métodos constantes

Ya vimos `const` en los getters. Aquí la explicación completa.

`const` es una promesa: "esto no va a cambiar".

### Variables const

```cpp
const int MAX_CONTACTS = 8;   // MAX_CONTACTS nunca cambiará
MAX_CONTACTS = 10;             // ❌ ERROR — es const
```

### Parámetros const

```cpp
void imprimir(const std::string &texto) {
    std::cout << texto << std::endl;
    texto = "otra cosa";   // ❌ ERROR — texto es const
}
```

Útil para pasar strings u objetos grandes **sin copiarlos** y **sin riesgo de modificarlos**.

### Métodos const

```cpp
bool Contact::isEmpty(void) const {
    return _firstName.empty();
    // _firstName = "algo";   ← si añadieras esto, ERROR de compilación
}
```

El `const` al final garantiza que el método no toca ningún atributo del objeto. Es una promesa que el compilador verifica — si intentas modificar algo dentro, error inmediato.

**Regla práctica**: todo getter y todo método que solo lee datos → márcalo como `const`.

### Por qué esto es importante en el PhoneBook

Cuando el PhoneBook muestra un contacto, necesita leer sus datos. Si el contacto fuera `const` en ese contexto, solo podría llamar a métodos `const`:

```cpp
void PhoneBook::displayContact(int index) const {
    // aquí solo puedes llamar a métodos const de Contact
    std::cout << _contacts[index].getFirstName() << std::endl;
    // getFirstName DEBE ser const para que esto compile
}
```

---

## 17. Arrays de objetos (sin memoria dinámica)

El PhoneBook tiene un array de 8 contactos. La memoria dinámica (`new`/`delete`) está prohibida, así que usas un array de tamaño fijo en el stack:

```cpp
class PhoneBook {
    private:
        Contact _contacts[8];   // 8 objetos Contact, creados en el stack
        int _nextIndex;         // índice del próximo contacto a reemplazar
};
```

Cuando se crea un objeto `PhoneBook`, automáticamente se crean los 8 `Contact` — por eso necesitas el constructor por defecto de `Contact`.

### Acceder a los elementos

```cpp
_contacts[0]   // primer contacto
_contacts[7]   // octavo contacto (último)
_contacts[i]   // contacto en posición i
```

Igual que un array normal en C.

### La lógica de reemplazar el más antiguo

El subject dice: si hay 9 contactos, el nuevo reemplaza al más antiguo. La forma más simple:

```cpp
class PhoneBook {
    private:
        Contact _contacts[8];
        int _nextIndex;    // siempre apunta al siguiente hueco a usar

    public:
        PhoneBook() : _nextIndex(0) { }  // empieza en 0

        void addContact(Contact c) {
            _contacts[_nextIndex] = c;
            _nextIndex = (_nextIndex + 1) % 8;
            //                            ^^^
            // % 8 hace que cuando llega a 8, vuelva a 0
            // 0→1→2→3→4→5→6→7→0→1→2... (ciclo)
        }
};
```

El operador `%` (módulo) devuelve el resto de la división. `8 % 8 = 0`, `9 % 8 = 1`, etc. Hace que el índice cicle de 0 a 7 y vuelva a 0.

---

## 18. iomanip — formatear la salida

El subject del PhoneBook pide mostrar los contactos en columnas de exactamente 10 caracteres, alineados a la derecha, con `|` como separador. Para esto necesitas:

```cpp
#include <iomanip>
```

### std::setw — establecer el ancho de campo

`setw(n)` hace que el próximo valor que imprimas ocupe exactamente `n` caracteres:

```cpp
std::cout << std::setw(10) << "Alice" << std::endl;
// imprime: "     Alice" (5 espacios + "Alice" = 10 caracteres total)
```

Si el texto tiene menos de 10 caracteres, rellena con espacios por la izquierda.
Si tiene más de 10 caracteres, NO lo trunca automáticamente — eso lo tienes que hacer tú.

**Importante**: `setw` solo afecta al **siguiente** elemento que imprimes. Después vuelve al comportamiento normal.

```cpp
std::cout << std::setw(10) << "Alice" << "Bob" << std::endl;
// imprime: "     AliceBob"
// setw solo afectó a "Alice", no a "Bob"
```

### std::right y std::left — alineación

Por defecto, `setw` alinea a la derecha. Puedes especificarlo explícitamente:

```cpp
std::cout << std::right << std::setw(10) << "Alice" << std::endl;
// "     Alice" — alineado a la derecha (por defecto)

std::cout << std::left << std::setw(10) << "Alice" << std::endl;
// "Alice     " — alineado a la izquierda
```

`std::right` y `std::left` **sí persisten** — una vez que los pones, se aplican a todos los campos siguientes hasta que los cambias.

### Truncar strings largos — lo que tienes que hacer tú

El subject pide: si el texto tiene más de 10 caracteres, truncarlo y reemplazar el último carácter por un punto:

```cpp
std::string formatearCampo(std::string texto) {
    if (texto.length() > 10)
        return texto.substr(0, 9) + ".";
        // coge los primeros 9 caracteres + "." = 10 total
    return texto;
}
```

Y luego:
```cpp
std::cout << std::setw(10) << formatearCampo(nombre) << "|";
```

### La fila completa del PhoneBook

Combinando todo:

```cpp
void PhoneBook::displayRow(int index) const {
    std::string first  = _contacts[index].getFirstName();
    std::string last   = _contacts[index].getLastName();
    std::string nick   = _contacts[index].getNickname();

    // truncar si es necesario
    if (first.length() > 10) first = first.substr(0, 9) + ".";
    if (last.length()  > 10) last  = last.substr(0, 9)  + ".";
    if (nick.length()  > 10) nick  = nick.substr(0, 9)  + ".";

    std::cout << std::right;
    std::cout << std::setw(10) << index << "|";
    std::cout << std::setw(10) << first << "|";
    std::cout << std::setw(10) << last  << "|";
    std::cout << std::setw(10) << nick  << std::endl;
}
```

Resultado esperado para un contacto con nombre "Alice":
```
         0|     Alice|     Smith|      Ali|
```

---

## 19. Glosario completo de CPP00

| Término | Definición |
|---|---|
| **Clase** | Molde para crear objetos — agrupa datos y funciones relacionados |
| **Objeto / Instancia** | Elemento concreto creado a partir de una clase |
| **Atributo** | Variable que pertenece a una clase |
| **Método** | Función que pertenece a una clase |
| **Constructor** | Método especial que se llama automáticamente al crear un objeto |
| **Constructor por defecto** | Constructor sin parámetros — necesario para arrays de objetos |
| **Destructor** | Método especial que se llama automáticamente al destruir un objeto |
| **Encapsulación** | Proteger los datos de una clase — acceso solo mediante métodos |
| **Getter** | Método que devuelve el valor de un atributo privado |
| **Setter** | Método que modifica el valor de un atributo privado |
| **this** | Puntero al objeto actual dentro de un método |
| **private** | Solo accesible desde dentro de la clase |
| **public** | Accesible desde cualquier sitio |
| **static (atributo)** | Existe una sola vez, compartido por todos los objetos de la clase |
| **static (método)** | Puede llamarse sin crear ningún objeto |
| **const (método)** | El método no modifica ningún atributo del objeto |
| **Namespace** | Espacio de nombres — etiqueta para evitar conflictos de nombres |
| **std::** | El namespace de la librería estándar de C++ |
| **::** | Operador de resolución de ámbito — indica a qué clase o namespace pertenece algo |
| **Include guard** | Mecanismo para evitar que un header se incluya dos veces |
| **#pragma once** | Versión moderna y simple del include guard |
| **.hpp** | Archivo de cabecera — declara qué existe en la clase |
| **.cpp** | Archivo de implementación — define cómo funciona cada cosa |
| **Stack** | Zona de memoria automática donde viven las variables locales |
| **Array estático** | Array de tamaño fijo que vive en el stack |
| **std::cout** | Stream de salida — la pantalla |
| **std::cin** | Stream de entrada — el teclado |
| **std::cerr** | Stream de error — para mensajes de error |
| **std::endl** | Salta de línea y vacía el buffer |
| **std::getline** | Lee una línea completa incluyendo espacios |
| **std::string** | Clase de C++ para cadenas de texto — reemplaza a char* |
| **toupper(c)** | Convierte un char a mayúscula |
| **tolower(c)** | Convierte un char a minúscula |
| **std::setw(n)** | Establece el ancho del siguiente campo a n caracteres |
| **std::right** | Alinea los campos a la derecha (persiste) |
| **std::left** | Alinea los campos a la izquierda (persiste) |
| **argc** | Número de argumentos pasados al programa |
| **argv** | Array de strings con los argumentos |
| **UpperCamelCase** | Estilo de nombre para clases: PrimeraLetraEnMayúscula |
| **lowerCamelCase** | Estilo de nombre para métodos: primeraLetraEnMinúscula |
| **OOP** | Object-Oriented Programming — Programación Orientada a Objetos |
| **LIFO** | Last In First Out — orden de destrucción en el stack |
| **Buffer** | Zona de memoria temporal donde se acumula la salida antes de imprimirse |
| **Flush** | Vaciar el buffer y mandar la salida inmediatamente |
| **Módulo (%)** | Resto de la división — útil para hacer índices cíclicos |

---

# APÉNDICE — Estructura completa del PhoneBook

Para que lo tengas de referencia visual:

```
CPP00/ex01/
├── Makefile
├── main.cpp
├── Contact.hpp       ← declaración de la clase Contact
├── Contact.cpp       ← implementación de Contact
├── PhoneBook.hpp     ← declaración de la clase PhoneBook
└── PhoneBook.cpp     ← implementación de PhoneBook

Contact.hpp
  private:
    _firstName, _lastName, _nickname, _phoneNumber, _darkestSecret
  public:
    Contact()           ← constructor por defecto (necesario para el array)
    ~Contact()          ← destructor
    setFirstName(name)  ← setter
    getFirstName()      ← getter (const)
    ... (setters/getters para cada campo)
    isEmpty()           ← saber si el contacto tiene datos (const)

PhoneBook.hpp
  private:
    Contact _contacts[8]  ← array estático de 8 Contact
    int _nextIndex        ← próxima posición donde añadir
  public:
    PhoneBook()           ← constructor
    ~PhoneBook()          ← destructor
    addContact()          ← añadir un contacto
    searchContact()       ← mostrar contactos y pedir índice
    displayRow(index)     ← mostrar una fila del SEARCH (const)

main.cpp
  Bucle infinito:
    leer comando (ADD / SEARCH / EXIT / ignorar)
    según el comando, llamar al método correspondiente de PhoneBook
```
