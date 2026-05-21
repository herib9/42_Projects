# C++ — Temario Completo CPP01
## Ejercicio 06 — Switch, Fall-through y Filtrado de niveles

---

# ÍNDICE

1. El problema que plantea el ex06
2. ¿Qué es el switch?
3. Anatomía del switch — cada parte explicada
4. El break — por qué es obligatorio (casi siempre)
5. El fall-through — caer al siguiente case
6. default — el caso cuando nada encaja
7. El fall-through INTENCIONAL — la clave del ex06
8. Limitaciones del switch — qué tipos acepta
9. Convertir un string a un número para el switch
10. La estructura completa del ex06
11. switch vs if/else vs punteros — cuándo usar cada uno
12. Glosario completo

---

## 1. El problema que plantea el ex06

El ex06 es una evolución del ex05. En lugar de llamar a un único nivel, el programa recibe un nivel como argumento y debe imprimir **ese nivel y todos los superiores**.

La jerarquía de niveles de Harl, de menor a mayor severidad:

```
DEBUG   (nivel 0) — el menos grave
INFO    (nivel 1)
WARNING (nivel 2)
ERROR   (nivel 3) — el más grave
```

Si el usuario pide `WARNING`, el programa imprime `WARNING` y `ERROR`. Si pide `DEBUG`, imprime los cuatro. Si pide `INFO`, imprime `INFO`, `WARNING` y `ERROR`.

```
$> ./harlFilter "WARNING"
[ WARNING ]
I think I deserve some extra bacon for free...

[ ERROR ]
This is unacceptable! I want to speak to the manager now.
```

El subject dice: "uno de los métodos más efectivos para tratar con Harl es hacer SWITCH". El juego de palabras es intencional — `switch` es la solución, y "switch off" significa apagarlo.

---

## 2. ¿Qué es el switch?

El `switch` es una estructura de control para seleccionar entre múltiples caminos según el valor de una expresión. Es una alternativa al `if/else if/else` cuando comparas una sola variable contra varios valores concretos.

```cpp
int nivel = 2;

switch (nivel) {
    case 0:
        std::cout << "DEBUG" << std::endl;
        break;
    case 1:
        std::cout << "INFO" << std::endl;
        break;
    case 2:
        std::cout << "WARNING" << std::endl;
        break;
    case 3:
        std::cout << "ERROR" << std::endl;
        break;
    default:
        std::cout << "Nivel desconocido" << std::endl;
        break;
}
// imprime: WARNING
```

El `switch` evalúa la expresión entre paréntesis (`nivel`), salta directamente al `case` cuyo valor coincide, ejecuta el código de ese case, y (con `break`) sale del bloque.

---

## 3. Anatomía del switch — cada parte explicada

```cpp
switch (expresion) {     // 1. la expresión a evaluar
    case valor1:          // 2. etiqueta de caso
        // código         // 3. lo que se ejecuta
        break;            // 4. salir del switch
    case valor2:
        // código
        break;
    default:              // 5. caso por defecto — cuando nada coincide
        // código
        break;
}
```

### 1. La expresión

```cpp
switch (expresion)
```

La expresión debe ser de tipo entero: `int`, `char`, `short`, `long`, `bool`, o un `enum`. **Los strings no funcionan con switch** — esto es una limitación importante que afecta directamente al ex06 y se explica en la sección 8.

### 2. Las etiquetas case

```cpp
case valor:
```

`valor` debe ser una **constante** conocida en tiempo de compilación. No puede ser una variable:

```cpp
int x = 5;
case x:   // ❌ ERROR — x no es constante, puede cambiar
case 5:   // ✅ correcto — 5 siempre es 5
```

Los valores de los `case` deben ser únicos — no puedes tener dos `case 2:` en el mismo switch.

### 3. El código de cada case

Todo lo que hay entre una etiqueta `case` y el siguiente `break` (o el final del switch) pertenece a ese case. Puedes tener tantas líneas como necesites:

```cpp
case 2:
    std::cout << "Nivel WARNING" << std::endl;
    std::cout << "Posible problema en el sistema" << std::endl;
    lanzarAlerta();
    break;
```

### 4. El break

`break` hace que la ejecución salte al final del bloque `switch { }`. Sin él, la ejecución **continúa** con el siguiente case — el famoso fall-through.

### 5. El default

`default:` es el caso que se ejecuta cuando ningún `case` coincide. Es opcional, pero es buena práctica incluirlo siempre — cubre entradas inesperadas.

```cpp
default:
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    break;
```

El `default` puede ir en cualquier posición dentro del switch, aunque por convención va al final.

---

## 4. El break — por qué es obligatorio (casi siempre)

La regla es simple: **sin break, la ejecución cae al siguiente case**.

```cpp
int nivel = 1;

switch (nivel) {
    case 0:
        std::cout << "case 0" << std::endl;
        break;
    case 1:
        std::cout << "case 1" << std::endl;
        // sin break — cae al siguiente
    case 2:
        std::cout << "case 2" << std::endl;
        break;
    case 3:
        std::cout << "case 3" << std::endl;
        break;
}
// imprime:
// case 1
// case 2
```

La ejecución entró en `case 1` (porque `nivel == 1`), ejecutó su código, y al no encontrar `break` continuó directamente con `case 2`, ignorando la etiqueta `case 2:` como si no existiera. Cuando llegó a `break` en el case 2, salió.

Este comportamiento se llama **fall-through** (caída). Normalmente es un error — un `break` olvidado. Pero en el ex06 es exactamente lo que necesitas.

---

## 5. El fall-through — caer al siguiente case

El fall-through ocurre cuando hay código en un case **sin break** al final. La ejecución literalmente "cae" al siguiente case sin comprobación alguna:

```cpp
switch (nivel) {
    case 0:
        hacerAlgo();
        // sin break → cae a case 1
    case 1:
        hacerOtraCosa();
        // sin break → cae a case 2
    case 2:
        hacerLoUltimo();
        break;   // aquí para
    case 3:
        // si nivel era 0, 1 o 2, nunca llegamos aquí (por el break de case 2)
        // si nivel era 3, entramos aquí directamente
        break;
}
```

Si `nivel == 0`: se ejecutan `hacerAlgo()`, `hacerOtraCosa()` y `hacerLoUltimo()`.
Si `nivel == 1`: se ejecutan `hacerOtraCosa()` y `hacerLoUltimo()`.
Si `nivel == 2`: se ejecuta solo `hacerLoUltimo()`.
Si `nivel == 3`: no se ejecuta nada (solo el break vacío).

Esta cascada de ejecución es exactamente el comportamiento que necesita el ex06 — imprimir desde el nivel seleccionado hasta el final.

---

## 6. default — el caso cuando nada encaja

`default` funciona igual que un `case`, pero sin valor específico — se ejecuta cuando ningún `case` coincide. Es el "para todo lo demás":

```cpp
switch (nivel) {
    case 0:
        debug();
        break;
    case 1:
        info();
        break;
    default:
        std::cout << "Nivel no reconocido" << std::endl;
        break;
}
```

Si `nivel` es 0 → `debug()`. Si es 1 → `info()`. Si es cualquier otra cosa (2, 7, -1, 999...) → el mensaje de error.

### ¿Necesita break el default?

Técnicamente, si `default` es el último case, el `break` es redundante porque la ejecución llegaría al final del `switch` de todas formas. Sin embargo, **incluirlo siempre es buena práctica** porque:

1. Si alguien añade otro `case` después del `default`, el `break` evita un fall-through accidental.
2. Es más explícito y fácil de leer.

---

## 7. El fall-through INTENCIONAL — la clave del ex06

El ex06 pide imprimir **desde el nivel seleccionado en adelante**. Si el usuario pide `WARNING`, imprime WARNING y ERROR. Si pide `DEBUG`, imprime los cuatro.

Esto es fall-through intencional — el comportamiento por defecto del switch sin break, usado aquí a propósito:

```cpp
void Harl::filterComplain(std::string level) {
    int levelIndex = getLevelIndex(level);   // convierte el string a número

    switch (levelIndex) {
        case 0:
            debug();     // si es DEBUG, imprime DEBUG
            // sin break → cae a INFO
        case 1:
            info();      // si es DEBUG o INFO, imprime INFO
            // sin break → cae a WARNING
        case 2:
            warning();   // si es DEBUG, INFO o WARNING, imprime WARNING
            // sin break → cae a ERROR
        case 3:
            error();     // siempre llega aquí excepto con nivel desconocido
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]"
                      << std::endl;
            break;
    }
}
```

**Si `levelIndex == 0` (DEBUG):**
→ entra en `case 0`, llama a `debug()`
→ sin break, cae a `case 1`, llama a `info()`
→ sin break, cae a `case 2`, llama a `warning()`
→ sin break, cae a `case 3`, llama a `error()`
→ break, sale
→ resultado: imprime los 4 niveles

**Si `levelIndex == 2` (WARNING):**
→ salta directamente a `case 2`, llama a `warning()`
→ sin break, cae a `case 3`, llama a `error()`
→ break, sale
→ resultado: imprime WARNING y ERROR

**Si el nivel es desconocido (`levelIndex == -1` u otro valor):**
→ ningún case coincide → `default`
→ imprime el mensaje de insignificant problems

Esto es elegante: en lugar de filtrar manualmente qué niveles imprimir, el switch hace la cascada de forma natural. El punto de entrada es el nivel seleccionado, y desde ahí todo cae hacia abajo automáticamente.

---

## 8. Limitaciones del switch — qué tipos acepta

El switch **solo acepta tipos enteros**: `int`, `char`, `short`, `long`, `unsigned int`, `bool`, y `enum`.

```cpp
int n = 2;
switch (n) { ... }    // ✅ int

char c = 'A';
switch (c) { ... }    // ✅ char — los chars son enteros (código ASCII)

std::string s = "hola";
switch (s) { ... }    // ❌ ERROR — los strings no son tipos enteros
```

Esto es una limitación importante de C++ (y de C). Los strings son objetos complejos — el switch no puede usarlos directamente porque no puede comparar objetos con `==` de la misma forma que compara enteros.

En la práctica, cuando necesitas un switch sobre strings, tienes dos opciones:

**Opción A — Convertir el string a un entero o enum manualmente** (la más común en 42):

```cpp
int getLevelIndex(std::string level) {
    if (level == "DEBUG")   return 0;
    if (level == "INFO")    return 1;
    if (level == "WARNING") return 2;
    if (level == "ERROR")   return 3;
    return -1;   // nivel desconocido
}

switch (getLevelIndex(level)) {
    case 0: ...
    case 1: ...
}
```

**Opción B — Usar un enum** (más semántico):

```cpp
enum Level { DEBUG = 0, INFO = 1, WARNING = 2, ERROR = 3, UNKNOWN = -1 };

Level stringToLevel(std::string level) {
    if (level == "DEBUG")   return DEBUG;
    if (level == "INFO")    return INFO;
    if (level == "WARNING") return WARNING;
    if (level == "ERROR")   return ERROR;
    return UNKNOWN;
}

switch (stringToLevel(level)) {
    case DEBUG:   ...
    case INFO:    ...
    case WARNING: ...
    case ERROR:   ...
    default:      ...
}
```

Los enums en C++ son tipos enteros con nombres — el switch los acepta perfectamente.

---

## 9. Convertir un string a un número para el switch

Para el ex06, necesitas traducir el nivel (`"DEBUG"`, `"INFO"`, etc.) a un número que el switch pueda usar.

### Con función auxiliar simple

```cpp
int getLevelIndex(std::string level) {
    std::string niveles[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++) {
        if (niveles[i] == level)
            return i;   // 0, 1, 2 o 3
    }
    return -1;   // nivel desconocido
}
```

Esta función recorre el array de nombres y devuelve el índice del nivel. Si no encuentra ninguno, devuelve -1, que el `default` del switch capturará.

### Con punteros a función del ex05 (reutilizando código)

Una alternativa elegante es reutilizar el patrón del ex05. El array de strings ya existe — solo necesitas el índice:

```cpp
// en Harl.cpp
static const std::string LEVELS[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

int Harl::getLevelIndex(std::string level) const {
    for (int i = 0; i < 4; i++) {
        if (LEVELS[i] == level)
            return i;
    }
    return -1;
}
```

---

## 10. La estructura completa del ex06

### Harl.hpp (los cambios respecto al ex05)

```cpp
class Harl {
    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);

    public:
        void complain(std::string level);      // ex05 — un nivel exacto
        void filterComplain(std::string level); // ex06 — ese nivel y superiores
};
```

### Harl.cpp — filterComplain

```cpp
void Harl::filterComplain(std::string level) {
    // convertir el string a índice
    std::string niveles[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int index = -1;
    for (int i = 0; i < 4; i++) {
        if (niveles[i] == level) {
            index = i;
            break;
        }
    }

    // el switch con fall-through intencional
    switch (index) {
        case 0:
            debug();
        case 1:
            info();
        case 2:
            warning();
        case 3:
            error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]"
                      << std::endl;
            break;
    }
}
```

### main.cpp

```cpp
int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Uso: ./harlFilter <nivel>" << std::endl;
        return 1;
    }

    Harl harl;
    harl.filterComplain(argv[1]);

    return 0;
}
```

### La salida esperada

```
$> ./harlFilter "WARNING"
[ WARNING ]
I think I deserve to have some extra bacon for free.
I've been coming for years, whereas you started working here just last month.

[ ERROR ]
This is unacceptable! I want to speak to the manager now.

$> ./harlFilter "DEBUG"
[ DEBUG ]
I love having extra bacon...

[ INFO ]
I cannot believe adding extra bacon costs more money...

[ WARNING ]
I think I deserve to have some extra bacon for free...

[ ERROR ]
This is unacceptable! I want to speak to the manager now.

$> ./harlFilter "yo no sé qué nivel es esto"
[ Probably complaining about insignificant problems ]
```

---

## 11. switch vs if/else vs punteros — cuándo usar cada uno

Ahora que conoces los tres, esta es la guía de cuándo usar cada herramienta:

### switch

**Úsalo cuando:**
- Comparas **una sola variable** contra **valores concretos y fijos**
- Los valores son tipos enteros (int, char, enum)
- Necesitas **fall-through** — que varios casos compartan código en cascada
- El número de casos es moderado (3-10)

**No lo uses cuando:**
- Necesitas comparar strings directamente
- Las condiciones son complejas (rangos, múltiples variables, llamadas a función)
- Necesitas lógica distinta para cada caso sin relación entre ellos

```cpp
// switch — perfecto aquí
switch (getLevelIndex(level)) {
    case 0: debug();    // fall-through
    case 1: info();     // fall-through
    case 2: warning();  // fall-through
    case 3: error(); break;
    default: mensajeError(); break;
}
```

### if/else if/else

**Úsalo cuando:**
- Las condiciones son complejas: rangos (`x > 5 && x < 10`), múltiples variables, resultados de funciones
- Compares strings directamente
- Cada caso es completamente independiente de los demás
- Tienes pocos casos (2-4)

```cpp
// if/else — necesario aquí porque es un rango
if (edad < 18)
    std::cout << "menor" << std::endl;
else if (edad < 65)
    std::cout << "adulto" << std::endl;
else
    std::cout << "senior" << std::endl;
```

### Punteros a funciones miembro (ex05)

**Úsalos cuando:**
- Tienes muchos casos (5+) y cada uno llama a una función distinta
- Necesitas escalabilidad — poder añadir casos sin modificar el código principal
- Los métodos tienen la misma firma
- Necesitas flexibilidad en tiempo de ejecución

```cpp
// punteros — perfecto cuando tienes muchos casos uniformes
(this->*metodos[i])();   // llama al método i-ésimo
```

### La tabla comparativa definitiva

| Criterio | switch | if/else | Punteros a función |
|---|---|---|---|
| **Tipos aceptados** | Solo enteros/enum | Cualquier condición | Misma firma de función |
| **Strings directamente** | ❌ No | ✅ Sí | ✅ Sí (como comparación) |
| **Fall-through** | ✅ Nativo | ❌ No existe | ❌ No existe |
| **Escalabilidad** | Media | Baja | Alta |
| **Legibilidad** | Alta (casos claros) | Media (se complica) | Media (sintaxis compleja) |
| **Añadir caso nuevo** | Añadir case | Añadir else if | Añadir entrada al array |
| **Cuándo usarlo** | Valores fijos, fall-through | Condiciones complejas | Muchos casos uniformes |

---

## 12. Glosario completo del ex06

| Término | Definición |
|---|---|
| **switch** | Estructura de control que selecciona entre múltiples casos según el valor de una expresión entera |
| **case** | Etiqueta que marca el inicio de un caso en el switch — debe ser un valor constante |
| **break** | Salta al final del bloque switch — sin él ocurre fall-through |
| **default** | Caso especial que se ejecuta cuando ningún case coincide — equivale al else final |
| **Fall-through** | Comportamiento del switch sin break — la ejecución "cae" al siguiente case |
| **Fall-through intencional** | Uso deliberado de la caída para ejecutar múltiples cases en cascada |
| **enum** | Tipo de dato que define nombres simbólicos para valores enteros — se puede usar con switch |
| **Jerarquía de niveles** | El orden de severidad de los mensajes — DEBUG < INFO < WARNING < ERROR |
| **Filtrado por nivel** | Mostrar un nivel y todos los superiores — el comportamiento del ex06 |
| **getLevelIndex** | Función auxiliar que convierte un string de nivel a su índice numérico |
| **Tipo entero** | Los tipos que acepta switch: int, char, short, long, bool, enum |
| **Constante en tiempo de compilación** | Valor que el compilador conoce antes de ejecutar el programa — requerido en case |
| **Índice** | La posición numérica de un elemento en un array — 0, 1, 2, 3 |

---

# APÉNDICE FINAL — Mapa completo del CPP01

Ahora que tienes todos los ejercicios, aquí el panorama completo del módulo:

```
CPP01 — Memoria, punteros y referencias

ex00: BraiiiiiiinnnzzzZ
  Concepto central: STACK vs HEAP
  Herramientas: new, delete, funciones libres, operadores . y ->
  Clave: el zombie en stack muere solo, el del heap muere cuando tú quieres

ex01: Moar brainz!
  Concepto central: ARRAYS EN EL HEAP
  Herramientas: new[], delete[], constructor por defecto, setter
  Clave: new[] llama al constructor por defecto → necesitas Zombie() vacío

ex02: HI THIS IS BRAIN
  Concepto central: PUNTEROS vs REFERENCIAS — las dos caras de & y *
  Herramientas: &variable (dirección), Tipo &ref (alias), *ptr (desreferenciar)
  Clave: misma dirección, tres formas de acceder — el string solo existe una vez

ex03: Unnecessary violence
  Concepto central: REFERENCIA vs PUNTERO en atributos de clase
  Herramientas: Weapon &_weapon, Weapon *_weapon, const std::string &getType()
  Clave: HumanA siempre tiene arma → referencia | HumanB puede no tener → puntero

ex04: Sed is for losers
  Concepto central: STREAMS DE FICHEROS
  Herramientas: ifstream, ofstream, getline, find, erase, insert
  Clave: el algoritmo de reemplazar sin replace + pos += s2.length() evita bucle infinito

ex05: Harl 2.0
  Concepto central: PUNTEROS A FUNCIONES MIEMBRO
  Herramientas: void (Clase::*ptr)(), array de punteros, (this->*ptr)()
  Clave: array de strings paralelo al array de punteros — sin if/else

ex06: Harl filter
  Concepto central: SWITCH con FALL-THROUGH INTENCIONAL
  Herramientas: switch, case sin break, default
  Clave: sin break entre cases → la cascada imprime todos los niveles desde el seleccionado

Progresión del módulo:
  Memoria dinámica (ex00, ex01)
  → Alias y direcciones (ex02)
  → Aplicación en clases (ex03)
  → Entrada/Salida de ficheros (ex04)
  → Técnicas avanzadas de despacho (ex05, ex06)
```
