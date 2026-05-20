# C++ — Temario Completo CPP01
## Ejercicios 02 y 03 — Referencias, Punteros y sus diferencias

---

# ÍNDICE

**PARTE 1 — ex02: HI THIS IS BRAIN**
1. ¿Qué es una dirección de memoria?
2. Variables — dónde viven en memoria
3. Punteros — guardar una dirección
4. El operador & en sus dos usos
5. El operador * en sus dos usos
6. Referencias — el alias
7. Imprimir direcciones de memoria
8. La prueba definitiva: misma dirección, mismo objeto
9. Puntero vs Referencia — comparación directa

**PARTE 2 — ex03: Unnecessary violence**
10. El problema que plantea el ejercicio
11. La clase Weapon — getter con referencia constante
12. const & como tipo de retorno — en profundidad
13. HumanA — el que SIEMPRE tiene arma (referencia)
14. HumanB — el que PUEDE no tener arma (puntero)
15. Por qué las referencias de clase van en la lista de inicialización
16. La demostración de que funciona — el arma cambia
17. Tabla definitiva: puntero vs referencia

---

# PARTE 1 — REFERENCIAS Y PUNTEROS (ex02: HI THIS IS BRAIN)

---

## 1. ¿Qué es una dirección de memoria?

Antes de hablar de punteros y referencias, necesitas entender qué es una dirección.

Imagina que la memoria RAM es una calle con miles de casas numeradas. Cada casa puede guardar un dato pequeño. La dirección de una casa es simplemente su número — `0x7fff5a`, `0x7fff5b`, etc.

Cuando creas una variable, el programa le asigna una o varias casas para guardar su valor:

```cpp
std::string brain = "HI THIS IS BRAIN";
```

El string `"HI THIS IS BRAIN"` vive en algún lugar de la memoria. Ese lugar tiene una dirección — un número que identifica exactamente dónde está. Las direcciones en C++ se escriben en hexadecimal y se parecen a `0x7ffeefbff5a0`.

Cada tipo de dato ocupa un número distinto de casas:
- `char` — 1 casa (1 byte)
- `int` — 4 casas (4 bytes)
- `double` — 8 casas (8 bytes)
- `std::string` — varias casas dependiendo de la implementación

---

## 2. Variables — dónde viven en memoria

Cuando declaras una variable, el compilador le reserva espacio en memoria y le da un nombre. Ese nombre es solo para ti — el programa usa las direcciones directamente.

```cpp
std::string brain = "HI THIS IS BRAIN";
```

Visualizado:

```
MEMORIA (stack):
dirección     contenido
0x7fff5a00 -> "HI THIS IS BRAIN"   <- brain vive aquí
```

La variable `brain` **es** el contenido en esa dirección. El nombre `brain` no existe en el ejecutable — el compilador lo reemplaza por la dirección.

---

## 3. Punteros — guardar una dirección

Un puntero es una variable que en lugar de guardar un valor normal, guarda una **dirección de memoria**.

```cpp
std::string brain = "HI THIS IS BRAIN";
std::string *stringPTR = &brain;
```

Visualizado:

```
MEMORIA:
dirección     contenido
0x7fff5a00 -> "HI THIS IS BRAIN"   <- brain
0x7fff5b00 -> 0x7fff5a00           <- stringPTR (guarda la dirección de brain)
```

`stringPTR` es una variable como cualquier otra — ocupa espacio en memoria. Pero su contenido no es texto ni un número útil — es la **dirección** donde vive `brain`.

Para llegar al valor original a través del puntero, usas el operador `*` (desreferenciar):

```cpp
std::cout << *stringPTR << std::endl;   // imprime "HI THIS IS BRAIN"
*stringPTR = "otro texto";               // modifica brain a través del puntero
std::cout << brain << std::endl;         // imprime "otro texto"
```

---

## 4. El operador `&` en sus dos usos — CRUCIAL

El símbolo `&` hace cosas completamente distintas según dónde aparece. Esta es una de las confusiones más comunes en C++.

### Uso 1: Operador de dirección (en una expresión)

Cuando `&` aparece **delante de una variable** en una expresión, significa "dame la dirección de esta variable":

```cpp
std::string brain = "HI THIS IS BRAIN";
&brain   // esto es una expresión que devuelve la dirección de brain
         // algo como 0x7fff5a00
```

```cpp
std::string *ptr = &brain;   // &brain en la expresión del lado derecho
//                  ^
//          "dame la dirección de brain"
```

### Uso 2: Declaración de referencia (en una declaración de variable)

Cuando `&` aparece **en la declaración** de una variable, significa "esto es una referencia":

```cpp
std::string &ref = brain;   // & en la declaración — ref ES brain
//           ^
//   "ref es una referencia a brain"
```

Aquí `&` no es un operador que hace algo — es parte del tipo de la variable. `std::string &` significa "referencia a std::string".

### La confusión más típica

```cpp
std::string brain = "HI THIS IS BRAIN";

std::string *ptr = &brain;   // &brain — operador de dirección (expresión)
                              // ptr guarda la dirección de brain

std::string &ref = brain;    // & en la declaración — ref ES brain
                              // ref no guarda nada — es brain con otro nombre

// ¿cómo saber cuál es cuál?
// Mira a qué le pertenece el &:
// std::string *ptr = &brain   → el & pertenece a brain (expresión) → operador de dirección
// std::string &ref = brain    → el & pertenece a ref (declaración) → tipo referencia
```

---

## 5. El operador `*` en sus dos usos — también CRUCIAL

Igual que `&`, el operador `*` tiene dos significados según el contexto.

### Uso 1: Desreferenciar (en una expresión)

Cuando `*` aparece **delante de un puntero** en una expresión, significa "ve a esa dirección y dame lo que hay":

```cpp
std::string *ptr = &brain;
*ptr   // va a la dirección que guarda ptr y devuelve lo que hay → "HI THIS IS BRAIN"
```

```cpp
std::cout << *ptr << std::endl;   // imprime "HI THIS IS BRAIN"
*ptr = "otra cosa";                // modifica el valor en esa dirección
```

### Uso 2: Declaración de puntero (en una declaración de variable)

Cuando `*` aparece **en la declaración** de una variable, significa "esto es un puntero":

```cpp
std::string *stringPTR = &brain;
//           ^
//   "stringPTR es un puntero a std::string"
```

Aquí `*` no desreferencia nada — es parte del tipo. `std::string *` significa "puntero a std::string".

### Resumen de los cuatro casos

```cpp
std::string brain = "HI THIS IS BRAIN";

// & en declaración → tipo referencia
std::string &ref = brain;

// & en expresión → dirección de
std::string *ptr = &brain;

// * en declaración → tipo puntero
std::string *ptr = &brain;

// * en expresión → desreferenciar
std::cout << *ptr;   // lee el valor en la dirección
```

---

## 6. Referencias — el alias

Una referencia es un **segundo nombre** para exactamente la misma variable. No es una copia — es el mismo hueco de memoria con dos nombres distintos.

```cpp
std::string brain = "HI THIS IS BRAIN";
std::string &stringREF = brain;   // stringREF ES brain
```

Visualizado:

```
MEMORIA:
dirección     contenido
0x7fff5a00 -> "HI THIS IS BRAIN"
               ^             ^
             brain        stringREF
           (mismo hueco, dos nombres)
```

`brain` y `stringREF` no son dos variables distintas. Son literalmente el mismo hueco de memoria. Si modificas `stringREF`, modificas `brain`, y viceversa:

```cpp
stringREF = "hola";
std::cout << brain << std::endl;   // imprime "hola"
```

### Las tres reglas inamovibles de las referencias

**1. Deben inicializarse al declararse — obligatorio:**
```cpp
std::string &ref;           // ❌ ERROR — ¿alias de qué?
std::string &ref = brain;   // ✅ correcto
```

**2. Una vez asignada, no puede apuntar a otra variable:**
```cpp
std::string brain = "HI THIS IS BRAIN";
std::string otro  = "otro texto";
std::string &ref  = brain;   // ref apunta a brain

ref = otro;   // esto NO hace que ref apunte a otro
              // esto COPIA el valor de otro en brain
              // brain ahora vale "otro texto"
              // ref sigue apuntando a brain (que ahora tiene "otro texto")
```

**3. No puede ser nula:**
```cpp
std::string &ref = nullptr;   // ❌ ERROR — una referencia siempre apunta a algo
```

Un puntero puede ser `nullptr`. Una referencia nunca puede serlo — siempre apunta a un objeto real.

---

## 7. Imprimir direcciones de memoria

El ex02 pide imprimir las direcciones de memoria de las tres variables. Así se hace:

```cpp
std::string brain     = "HI THIS IS BRAIN";
std::string *stringPTR = &brain;
std::string &stringREF = brain;

// imprimir DIRECCIONES
std::cout << &brain     << std::endl;   // dirección de brain
std::cout << stringPTR  << std::endl;   // stringPTR ya ES una dirección
std::cout << &stringREF << std::endl;   // dirección de stringREF (= de brain)

// imprimir VALORES
std::cout << brain      << std::endl;   // valor de brain
std::cout << *stringPTR << std::endl;   // valor apuntado por stringPTR
std::cout << stringREF  << std::endl;   // valor de stringREF (= de brain)
```

### ¿Por qué `stringPTR` sin `&` imprime la dirección?

Porque `stringPTR` ya **es** una dirección. Es un puntero — su contenido es una dirección. Imprimirlo directamente te da esa dirección.

Para imprimir el valor al que apunta, tienes que desreferenciar: `*stringPTR`.

### ¿Por qué `stringREF` necesita `&` para imprimir su dirección?

Porque `stringREF` se comporta como `brain`. Cuando escribes `stringREF`, es como escribir `brain` — te da el valor `"HI THIS IS BRAIN"`. Para obtener la dirección, pones `&stringREF`, igual que pondrías `&brain`.

---

## 8. La prueba definitiva: misma dirección, mismo objeto

La salida del ex02 demuestra algo fundamental: las tres variables apuntan al mismo hueco de memoria.

```
Dirección de brain:     0x7fff5a00
Dirección de stringPTR: 0x7fff5a00   <- misma dirección
Dirección de stringREF: 0x7fff5a00   <- misma dirección

Valor de brain:      HI THIS IS BRAIN
Valor de *stringPTR: HI THIS IS BRAIN   <- mismo valor
Valor de stringREF:  HI THIS IS BRAIN   <- mismo valor
```

Las tres direcciones son **idénticas**. Hay un único objeto en memoria — `"HI THIS IS BRAIN"` — y tres formas de acceder a él:
- `brain` — acceso directo por nombre
- `*stringPTR` — acceso a través del puntero (desreferenciando)
- `stringREF` — acceso a través del alias

La diferencia es que `stringPTR` (el puntero en sí) vive en **otra dirección** — tiene su propio espacio en memoria para guardar la dirección de `brain`. La referencia `stringREF` no tiene espacio propio — es solo otro nombre.

---

## 9. Puntero vs Referencia — comparación directa

Esta es la tabla que el ex02 quiere que interiorices. Misma información, dos herramientas distintas.

| Característica | Puntero (`*`) | Referencia (`&`) |
|---|---|---|
| **Definición** | Variable que guarda una dirección | Alias — segundo nombre del mismo objeto |
| **Tiene espacio propio en memoria** | Sí — ocupa bytes para guardar la dirección | No — es el mismo objeto |
| **Puede ser nulo** | Sí — `nullptr` | No — siempre apunta a algo |
| **Puede cambiar a qué apunta** | Sí — reasignable | No — fijo desde la declaración |
| **Debe inicializarse al declarar** | No (aunque deberías) | Sí — obligatorio |
| **Acceder al valor** | `*ptr` (desreferenciar) | `ref` (como variable normal) |
| **Obtener la dirección** | `ptr` (ya es una dirección) | `&ref` (igual que `&variable`) |
| **Acceder a miembro** | `ptr->metodo()` | `ref.metodo()` |
| **Sintaxis declaración** | `Tipo *nombre = &variable` | `Tipo &nombre = variable` |

### Cuándo usar cada uno — la pregunta clave

**Usa referencia cuando:**
- El objeto siempre va a existir (nunca será nulo)
- No necesitas cambiar a qué objeto apunta
- Quieres código más limpio (sin `*` ni `->`)

**Usa puntero cuando:**
- El objeto puede no existir (puede ser nulo)
- Necesitas poder cambiar a qué objeto apunta
- Necesitas aritmética de punteros (arrays dinámicos)
- Necesitas `nullptr` como valor válido

---

# PARTE 2 — REFERENCIAS EN CLASES (ex03: Unnecessary violence)

---

## 10. El problema que plantea el ejercicio

El ex03 te hace pensar antes de empezar:

> "¿En qué caso usarías un puntero a Weapon? ¿Y una referencia? ¿Por qué?"

Tienes dos humanos muy parecidos pero con una diferencia crucial:

- **HumanA** — recibe el arma en el constructor y **siempre tiene una**. Nunca estará desarmado.
- **HumanB** — puede crearse sin arma y se la asignas después. **Puede estar sin arma**.

Esta diferencia dicta la elección:

```
HumanA siempre tiene arma → el arma nunca será null → REFERENCIA
HumanB puede no tener arma → el arma puede ser null → PUNTERO
```

¿Por qué? Porque una referencia **no puede ser nula**. Si HumanA usara referencia, el compilador te obligaría a darle un arma desde el principio — exactamente lo que pide el ejercicio. Si HumanB usara referencia, no podrías crearlo sin arma — romperías el comportamiento pedido.

---

## 11. La clase Weapon — getter con referencia constante

La clase `Weapon` es el punto de partida. Tiene un atributo privado `_type` (el tipo de arma) y dos métodos para leerlo y modificarlo.

```cpp
// Weapon.hpp
class Weapon {
    private:
        std::string _type;

    public:
        Weapon(std::string type);
        ~Weapon();

        const std::string &getType(void) const;
        void               setType(std::string type);
};
```

```cpp
// Weapon.cpp
Weapon::Weapon(std::string type) : _type(type) { }
Weapon::~Weapon() { }

const std::string &Weapon::getType(void) const {
    return _type;
}

void Weapon::setType(std::string type) {
    _type = type;
}
```

El setter es sencillo. El getter tiene una firma especial que merece explicación detallada.

---

## 12. `const std::string &` como tipo de retorno — en profundidad

Esta firma es la más importante del ex03:

```cpp
const std::string &Weapon::getType(void) const;
```

Tiene tres usos de `const` y uno de `&`. Vamos uno por uno de derecha a izquierda:

### El `const` al final de la firma

```cpp
const std::string &getType(void) const;
//                                 ^^^^ este
```

Este `const` pertenece al **método**. Significa: "este método no modifica ningún atributo del objeto". Es una promesa al compilador.

Si dentro de `getType` intentaras modificar `_type`, el compilador daría error. Los getters solo leen — nunca escriben — así que siempre deben marcarse como `const`.

Esto también permite llamar a `getType` sobre objetos que son `const`:
```cpp
const Weapon espada("espada");   // objeto constante
espada.getType();    // ✅ funciona — getType es const
espada.setType("hacha");   // ❌ ERROR — setType no es const
```

### El `&` en el tipo de retorno

```cpp
const std::string &getType(void) const;
//              ^^^
```

El `&` significa que devuelves una **referencia** al `_type` original, no una copia.

**Sin `&` (devuelve copia):**
```cpp
std::string getType(void) const {
    return _type;   // C++ copia _type y devuelve la copia
}
// quien recibe el valor tiene una copia INDEPENDIENTE
// si _type cambia después, la copia no se actualiza
```

**Con `&` (devuelve referencia):**
```cpp
const std::string &getType(void) const {
    return _type;   // devuelve una referencia al _type ORIGINAL
}
// quien recibe la referencia tiene ACCESO DIRECTO a _type
// si _type cambia después, la referencia ve el cambio
```

### El `const` delante del tipo de retorno

```cpp
const std::string &getType(void) const;
// ^^^^ este
```

Este `const` protege el valor devuelto. Quien reciba la referencia puede **leer** `_type` pero no **modificarlo**:

```cpp
const std::string &tipo = weapon.getType();
std::cout << tipo;    // ✅ leer — permitido
tipo = "hacha";       // ❌ ERROR — es const, no puedes modificarlo
```

Sin este `const`, alguien podría modificar `_type` directamente a través de la referencia, saltándose el setter y toda la encapsulación.

### La analogía de la pizarra (ya vista, ahora en contexto)

Imagina que `_type` es una pizarra en la pared del objeto `Weapon`.

Sin `&` (devuelve copia): alguien saca una **foto** de la pizarra. Tiene una copia del texto. Si borras la pizarra y escribes otra cosa, la foto no cambia.

Con `const std::string &` (devuelve referencia constante): alguien puede **mirar directamente** la pizarra. Si borras y escribes otra cosa, ellos ven el cambio. Pero no pueden modificar la pizarra ellos mismos (el `const` lo impide).

### Por qué esto importa en el ex03

El main del subject hace esto:

```cpp
Weapon club = Weapon("crude spiked club");
HumanA bob("Bob", club);
bob.attack();                              // "Bob attacks with their crude spiked club"
club.setType("some other type of club");   // cambia el arma
bob.attack();                              // "Bob attacks with their some other type of club"
```

El segundo `attack()` debe ver el arma actualizada. Esto solo funciona si `getType()` devuelve una **referencia** al `_type` original — así cuando `_type` cambia con `setType`, el `attack()` ve el cambio automáticamente.

Si `getType()` devolviera una copia, el segundo `attack()` seguiría imprimiendo `"crude spiked club"` aunque el arma hubiera cambiado.

---

## 13. HumanA — el que SIEMPRE tiene arma (referencia)

HumanA siempre tiene arma desde el momento en que se crea. Nunca estará desarmado. La elección correcta es una **referencia**:

```cpp
// HumanA.hpp
class HumanA {
    private:
        std::string _name;
        Weapon      &_weapon;    // REFERENCIA — nunca es nula

    public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA();
        void attack(void);
};
```

```cpp
// HumanA.cpp
HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {
}

HumanA::~HumanA() {
}

void HumanA::attack(void) {
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
```

Dentro de `attack()`, `_weapon.getType()` usa el punto `.` porque `_weapon` es una referencia — se comporta como un objeto directo, no como un puntero.

---

## 14. HumanB — el que PUEDE no tener arma (puntero)

HumanB puede crearse sin arma. También puede asignársele un arma después. La elección correcta es un **puntero**:

```cpp
// HumanB.hpp
class HumanB {
    private:
        std::string _name;
        Weapon      *_weapon;    // PUNTERO — puede ser nullptr

    public:
        HumanB(std::string name);
        ~HumanB();
        void attack(void);
        void setWeapon(Weapon &weapon);
};
```

```cpp
// HumanB.cpp
HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {
    // _weapon empieza como nullptr — sin arma
}

HumanB::~HumanB() {
}

void HumanB::attack(void) {
    if (!_weapon) {
        std::cout << _name << " has no weapon" << std::endl;
        return ;
    }
    std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
    _weapon = &weapon;   // guarda la dirección del arma
}
```

Dentro de `attack()`, `_weapon->getType()` usa la flecha `->` porque `_weapon` es un puntero.

### La comprobación `if (!_weapon)`

```cpp
if (!_weapon)
```

Esto es equivalente a `if (_weapon == nullptr)`. El operador `!` sobre un puntero devuelve `true` si el puntero es nulo (no apunta a nada válido).

Si HumanB no tiene arma asignada, `_weapon` vale `nullptr`. Intentar hacer `_weapon->getType()` sobre un puntero nulo es comportamiento indefinido — crash garantizado. La comprobación lo evita.

HumanA no necesita esta comprobación porque su `_weapon` es una referencia — siempre apunta a un objeto real.

---

## 15. Por qué las referencias de clase van en la lista de inicialización

Esta es una regla de C++ que no tiene excepciones:

**Los atributos que son referencias DEBEN inicializarse en la lista de inicialización del constructor. No pueden asignarse en el cuerpo.**

```cpp
// ❌ MAL — no funciona
HumanA::HumanA(std::string name, Weapon &weapon) {
    _name   = name;
    _weapon = weapon;   // ERROR — no puedes asignar una referencia en el cuerpo
}

// ✅ BIEN — en la lista de inicialización
HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {
    // el cuerpo puede estar vacío
}
```

¿Por qué? Porque una referencia es un alias — debe establecerse en el momento de la creación. Es como pegar una etiqueta: la etiqueta existe desde el principio y siempre apunta al mismo objeto. No puedes crear la etiqueta vacía y pegarla después.

Los punteros en cambio sí pueden asignarse en el cuerpo — o inicializarse a `nullptr` en la lista y asignarse después:

```cpp
// ✅ para punteros — ambas formas funcionan
HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) { }
// o:
HumanB::HumanB(std::string name) {
    _name   = name;
    _weapon = NULL;   // ✅ los punteros sí pueden asignarse en el cuerpo
}
```

---

## 16. La demostración de que funciona — el arma cambia

El main del subject demuestra algo importante: cuando el arma cambia, `attack()` lo refleja automáticamente.

```cpp
// Test con HumanA (referencia)
{
    Weapon club = Weapon("crude spiked club");
    HumanA bob("Bob", club);
    bob.attack();
    // "Bob attacks with their crude spiked club"

    club.setType("some other type of club");
    bob.attack();
    // "Bob attacks with their some other type of club"
}
```

¿Por qué funciona? Porque:

1. `HumanA bob("Bob", club)` — `_weapon` es una **referencia** a `club`
2. `bob.attack()` llama a `_weapon.getType()` que devuelve una **referencia** a `_type`
3. Cuando `club.setType("some other type of club")` cambia `_type`, la referencia que tiene `attack()` ve el cambio automáticamente

Si `_weapon` fuera una copia de `club` (no una referencia), el segundo `attack()` seguiría viendo `"crude spiked club"`. Las referencias hacen que todo esté sincronizado.

```cpp
// Test con HumanB (puntero)
{
    Weapon club = Weapon("crude spiked club");
    HumanB jim("Jim");
    jim.setWeapon(club);
    jim.attack();
    // "Jim attacks with their crude spiked club"

    club.setType("some other type of club");
    jim.attack();
    // "Jim attacks with their some other type of club"
}
```

El puntero también mantiene la sincronización porque `_weapon` apunta a `club` — cuando `club` cambia, el puntero sigue apuntando al mismo `club` (ahora modificado).

### El flujo completo visualizado

```
MEMORIA:
club._type → "crude spiked club"
              ^
              |
bob._weapon --+  (referencia a club)
jim._weapon --+  (puntero a club)

Después de club.setType("some other type of club"):

club._type → "some other type of club"
              ^
              |
bob._weapon --+  (sigue referenciando club — ve el cambio)
jim._weapon --+  (sigue apuntando a club — ve el cambio)
```

---

## 17. Tabla definitiva: puntero vs referencia — todo junto

Con lo aprendido en ex02 y ex03, la tabla completa:

| | Puntero | Referencia |
|---|---|---|
| **Declaración** | `Tipo *p = &var` | `Tipo &r = var` |
| **En atributo de clase** | `Weapon *_weapon` | `Weapon &_weapon` |
| **Inicialización** | Cuerpo del constructor o lista | OBLIGATORIAMENTE en la lista |
| **Puede ser nulo** | Sí — `nullptr` / `NULL` | No — siempre apunta a algo |
| **Puede reasignarse** | Sí — puede apuntar a otro objeto | No — siempre el mismo |
| **Tiene espacio propio** | Sí — ocupa bytes para la dirección | No — es el mismo objeto |
| **Acceso al valor** | `*p` o `p->miembro` | `r` o `r.miembro` |
| **Obtener dirección** | `p` (ya es la dirección) | `&r` |
| **Comprobación de nulidad** | `if (!p)` o `if (p == nullptr)` | No necesaria — nunca es nulo |
| **Sintaxis de acceso a miembro** | `p->getType()` | `r.getType()` |
| **Cuándo usar en clase** | Objeto que puede no existir (HumanB) | Objeto que siempre existe (HumanA) |
| **Cuándo usar como parámetro** | Cuando puede ser nulo o necesitas aritmética | Cuando siempre hay objeto — más limpio |
| **Cuándo usar como retorno** | Cuando puede devolver nullptr | Cuando siempre hay objeto que devolver |

### La regla de decisión simplificada

```
¿El objeto puede ser nulo (no existir)?
        |
    +---+---+
    NO      SÍ
    |        |
  REF      PTR
```

---

# APÉNDICE — Estructura de archivos de ex02 y ex03

### ex02: HI THIS IS BRAIN

```
ex02/
└── main.cpp   ← único archivo necesario

main.cpp contiene:
  std::string brain     = "HI THIS IS BRAIN"
  std::string *stringPTR = &brain     ← puntero
  std::string &stringREF = brain      ← referencia

  Imprime:
    &brain          → dirección de brain
    stringPTR       → también dirección de brain (misma)
    &stringREF      → también dirección de brain (misma)

    brain           → "HI THIS IS BRAIN"
    *stringPTR      → "HI THIS IS BRAIN"
    stringREF       → "HI THIS IS BRAIN"
```

### ex03: Unnecessary violence

```
ex03/
├── Makefile
├── Weapon.hpp / Weapon.cpp      ← clase Weapon: _type, getType (const &), setType
├── HumanA.hpp / HumanA.cpp      ← HumanA: Weapon &_weapon (referencia)
├── HumanB.hpp / HumanB.cpp      ← HumanB: Weapon *_weapon (puntero)
└── main.cpp                     ← el que viene dado en el subject

Weapon:
  private: std::string _type
  public:
    Weapon(std::string type)
    ~Weapon()
    const std::string &getType() const   ← referencia constante
    void setType(std::string type)

HumanA:
  private:
    std::string _name
    Weapon &_weapon      ← REFERENCIA — siempre tiene arma
  public:
    HumanA(std::string name, Weapon &weapon)   ← recibe arma en constructor
    ~HumanA()
    void attack()        ← usa _weapon.getType() con punto

HumanB:
  private:
    std::string _name
    Weapon *_weapon      ← PUNTERO — puede no tener arma
  public:
    HumanB(std::string name)    ← no recibe arma en constructor
    ~HumanB()
    void attack()               ← comprueba if (!_weapon) y usa _weapon->getType()
    void setWeapon(Weapon &w)   ← asigna arma después: _weapon = &w
```

### Diferencias clave entre HumanA y HumanB en el código

```
HumanA:
  .hpp → Weapon &_weapon         (referencia)
  .cpp → : _weapon(weapon)       (lista de inicialización — OBLIGATORIO para referencias)
  attack() → _weapon.getType()   (punto — referencia se comporta como objeto)
  NO tiene setWeapon              (una referencia no se puede reasignar)

HumanB:
  .hpp → Weapon *_weapon         (puntero)
  .cpp → : _weapon(NULL)         (inicializar a nullptr en lista)
  attack() → if (!_weapon) ...   (comprobar nulidad antes de usar)
           → _weapon->getType()  (flecha — puntero)
  SÍ tiene setWeapon              (_weapon = &weapon — guardar dirección)
```
