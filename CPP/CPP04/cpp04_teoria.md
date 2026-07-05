# CPP - Module 04
## Polimorfismo, clases abstractas y copia profunda
## De cero a entenderlo todo de verdad

---

# INDICE

**PARTE 1 — El problema que resuelve el polimorfismo**
1. El problema sin polimorfismo — el bosque de ifs
2. La solucion — tratar objetos distintos de la misma forma
3. Que es el polimorfismo de subtipo

**PARTE 2 — Dispatch estatico vs dispatch dinamico**
4. Dispatch estatico — el compilador decide en tiempo de compilacion
5. El problema del dispatch estatico con punteros a clase base
6. Dispatch dinamico — el programa decide en tiempo de ejecucion
7. La palabra virtual — como cambiar de estatico a dinamico

**PARTE 3 — La vtable — como funciona virtual por dentro**
8. Que es la vtable
9. Como la construye el compilador
10. El puntero oculto — vptr
11. Traza completa en RAM — llamada a makeSound con virtual
12. Traza completa en RAM — llamada a makeSound sin virtual

**PARTE 4 — El destructor virtual**
13. El problema sin virtual en el destructor
14. Traza del desastre — delete sin virtual destructor
15. La solucion — virtual ~Animal()
16. La regla — cuando hacer el destructor virtual

**PARTE 5 — WrongAnimal y WrongCat — el contraste**
17. Por que existen WrongAnimal y WrongCat
18. Comparacion directa — Animal vs WrongAnimal en RAM
19. El output que demuestra la diferencia

**PARTE 6 — Funciones pure virtual y clases abstractas**
20. El problema — Animal no deberia instanciarse
21. Pure virtual — la funcion que obliga a implementar
22. Clase abstracta — que es y que implica
23. Lo que no puedes hacer con una clase abstracta
24. Lo que si puedes hacer — punteros y referencias
25. La clase derivada debe implementar todos los pure virtual
26. El prefijo A — convencion para clases abstractas

**PARTE 7 — Copia superficial vs copia profunda**
27. El problema — atributos que son punteros
28. La copia superficial — shallow copy — el desastre
29. Traza del desastre en RAM
30. La solucion — deep copy
31. Traza de la deep copy en RAM

**PARTE 8 — La clase Brain**
32. Por que existe Brain
33. El array de strings — como se almacena en RAM
34. Por que los arrays no se copian con =
35. El bucle de copia en operator=

**PARTE 9 — Dog y Cat con Brain***
36. new Brain() en el constructor — por que en el heap
37. delete _brain en el destructor — obligatorio
38. El constructor de copia — new Brain() mas copia de contenido
39. El operator= — sin new, solo copia de contenido
40. La diferencia entre constructor de copia y operator=

**PARTE 10 — El array de Animals**
41. Por que usar Animal* y no Dog* o Cat*
42. Como el virtual destructor salva el array
43. El orden de destruccion con virtual
44. Memory leaks — como detectarlos

**PARTE 11 — Los ejercicios explicados uno a uno**
45. Ex00: Polymorphism
46. Ex01: I don't want to set the world on fire
47. Ex02: Abstract class

**Glosario completo**

---

# PARTE 1 — EL PROBLEMA QUE RESUELVE EL POLIMORFISMO

---

## 1. El problema sin polimorfismo — el bosque de ifs

Tienes tres tipos de animales — Dog, Cat y Animal generico. Quieres que cada uno haga su sonido. Sin polimorfismo:

```cpp
void hacerSonar(void *animal, std::string tipo) {
    if (tipo == "Dog")
        // hacer sonar como perro
    else if (tipo == "Cat")
        // hacer sonar como gato
    else
        // hacer sonar como animal generico
}
```

Si manana anaides FragTrap, WhaleTrap y SpiderAnimal, tienes que modificar esta funcion. Y todas las funciones similares que tengas. El codigo crece sin control y cualquier cambio puede romper todo.

---

## 2. La solucion — tratar objetos distintos de la misma forma

Con polimorfismo puedes escribir:

```cpp
void hacerSonar(Animal *animal) {
    animal->makeSound();   // automaticamente llama al sonido correcto
}

Dog d;
Cat c;
hacerSonar(&d);   // "Woof!"
hacerSonar(&c);   // "Meow!"
```

La funcion no sabe ni le importa si recibe un Dog o un Cat. Llama a `makeSound()` y el sistema decide automaticamente cual version ejecutar segun el objeto real. Si manana anaides WhaleTrap, no tocas nada — solo implementas su `makeSound()`.

---

## 3. Que es el polimorfismo de subtipo

Polimorfismo significa "muchas formas". En C++, el polimorfismo de subtipo es la capacidad de llamar al metodo correcto de un objeto derivado a traves de un puntero o referencia a la clase base.

El subject lo llama "Subtype Polymorphism" — el mismo metodo (makeSound) se comporta distinto segun el subtipo real del objeto (Dog, Cat...).

---

# PARTE 2 — DISPATCH ESTATICO VS DISPATCH DINAMICO

---

## 4. Dispatch estatico — el compilador decide en tiempo de compilacion

Cuando llamas a una funcion, alguien tiene que decidir cual implementacion ejecutar. En C++ por defecto esa decision se toma en **tiempo de compilacion** — antes de que el programa se ejecute.

```cpp
Dog d;
d.makeSound();
```

El compilador ve: "d es de tipo Dog, llamo a Dog::makeSound()". Decidido. Grabado en el binario. Cuando el programa corre, salta directamente a la direccion de Dog::makeSound sin pensar.

Esto se llama **dispatch estatico** — rapido, eficiente, pero inflexible.

---

## 5. El problema del dispatch estatico con punteros a clase base

```cpp
Animal *p = new Dog();
p->makeSound();
```

El compilador ve: "p es de tipo Animal*, llamo a Animal::makeSound()". No importa que dentro haya un Dog. El tipo del puntero manda.

En RAM:

```
HEAP:
cajon 2080: [ objeto Dog ]
              _type = "Dog"

STACK:
p = 2080   ← puntero de tipo Animal*
```

El compilador en tiempo de compilacion no puede saber que hay en el cajon 2080. Podria ser un Dog, un Cat, o cualquier otra cosa — eso depende de lo que pase durante la ejecucion. Sin informacion adicional, usa el tipo del puntero: Animal.

Resultado: `p->makeSound()` siempre llama a `Animal::makeSound()` aunque dentro haya un Dog. Incorrecto.

---

## 6. Dispatch dinamico — el programa decide en tiempo de ejecucion

La solucion: posponer la decision a **tiempo de ejecucion**. En lugar de que el compilador decida cual funcion llamar, el programa lo decide mientras corre — mirando el objeto real.

Esto se llama **dispatch dinamico** y en C++ se activa con la palabra `virtual`.

---

## 7. La palabra virtual — como cambiar de estatico a dinamico

```cpp
class Animal {
    virtual void makeSound(void) const;
    //^^^^^^
    // esta sola palabra cambia el mecanismo de dispatch
};
```

Con `virtual`, cuando el compilador ve `p->makeSound()` ya no graba "llama a Animal::makeSound". En cambio graba "consulta la tabla del objeto real y llama lo que encuentres ahi". Esa tabla es la vtable.

---

# PARTE 3 — LA VTABLE — COMO FUNCIONA VIRTUAL POR DENTRO

---

## 8. Que es la vtable

La vtable (virtual table) es una tabla que el compilador genera automaticamente para cada clase que tiene metodos virtuales. Contiene punteros a las implementaciones concretas de esos metodos.

```
vtable de Animal:
  [0] → Animal::makeSound   (si no es pure virtual)
  [1] → Animal::~Animal

vtable de Dog:
  [0] → Dog::makeSound      (sobreescribe la de Animal)
  [1] → Dog::~Dog

vtable de Cat:
  [0] → Cat::makeSound
  [1] → Cat::~Cat
```

Cada clase tiene su propia vtable. Las vtables existen en la zona de datos globales del programa — se crean al arrancar y viven hasta que termina.

---

## 9. Como la construye el compilador

El compilador analiza la jerarquia de herencia y genera una vtable por clase:

```
Animal declara: virtual void makeSound()
  → Animal tiene vtable
  → Dog hereda de Animal y sobreescribe makeSound()
    → Dog tiene su propia vtable con Dog::makeSound en [0]
  → Cat hereda de Animal y sobreescribe makeSound()
    → Cat tiene su propia vtable con Cat::makeSound en [0]
```

Si una clase derivada NO sobreescribe un metodo virtual, la vtable de esa clase apunta a la implementacion del padre.

---

## 10. El puntero oculto — vptr

Cada objeto de una clase con metodos virtuales lleva un puntero oculto llamado **vptr** (virtual pointer). Apunta a la vtable de su clase real. Este puntero lo gestiona el compilador automaticamente — tu no lo ves ni lo tocas.

```
HEAP — objeto Dog creado con new Dog():

cajon 2080: [ vptr = direccion vtable de Dog ]  ← primero, oculto
cajon 2088: [ _type = "Dog"                 ]
cajon 2096: [ _brain = 0x9f40               ]

ZONA DE DATOS GLOBALES:
vtable de Dog:
  [0] → Dog::makeSound
  [1] → Dog::~Dog
```

El objeto Dog sabe que es un Dog gracias al vptr. Aunque el puntero externo sea `Animal*`, el objeto en el heap lleva consigo la informacion de su tipo real.

---

## 11. Traza completa en RAM — llamada a makeSound con virtual

```cpp
Animal *p = new Dog();
p->makeSound();
```

Paso a paso:

```
PASO 1: p->makeSound()
  el compilador ha generado: "consulta la vtable del objeto al que apunta p"

PASO 2: sigue el puntero p
  p = 2080 → va al cajon 2080

PASO 3: en el cajon 2080 lee el vptr
  vptr = direccion de la vtable de Dog

PASO 4: va a la vtable de Dog
  vtable de Dog:
    [0] → Dog::makeSound   ← aqui

PASO 5: llama a Dog::makeSound()
  imprime: "DOG barks at the hippies"
```

El dispatch dinamico consulta el vptr en tiempo de ejecucion para encontrar la implementacion correcta.

---

## 12. Traza completa en RAM — llamada a makeSound sin virtual

```cpp
WrongAnimal *p = new WrongCat();
p->makeSound();
```

Sin virtual, no hay vtable ni vptr. El compilador graba directamente la funcion a llamar en tiempo de compilacion:

```
PASO 1: el compilador ve p->makeSound()
  p es WrongAnimal* → graba "llama a WrongAnimal::makeSound"

PASO 2: en ejecucion, salta directamente a WrongAnimal::makeSound
  no consulta nada
  no mira el objeto real
  imprime: "WRONG ANIMAL SOUND SYSTEM"
```

Aunque dentro haya un WrongCat, el compilador ya habia decidido en tiempo de compilacion que llamaria a WrongAnimal::makeSound. No hay forma de cambiarlo en ejecucion.

---

# PARTE 4 — EL DESTRUCTOR VIRTUAL

---

## 13. El problema sin virtual en el destructor

El mismo problema del dispatch estatico ocurre con el destructor cuando usas `delete` con punteros a clase base:

```cpp
Animal *p = new Dog();
delete p;
// sin virtual ~Animal(): el compilador ve Animal* → llama solo a Animal::~Animal()
// Dog::~Dog() NUNCA SE LLAMA
// el Brain del Dog nunca se destruye → MEMORY LEAK
```

---

## 14. Traza del desastre — delete sin virtual destructor

```
Animal *p = new Dog():

HEAP:
cajon 2080: [ objeto Dog ]
              vptr (si lo hay para otros virtuales)
              _type = "Dog"
              _brain = 0x9f40 → [ Brain con 100 ideas ]

delete p — SIN virtual ~Animal():
  el compilador ve Animal* → llama Animal::~Animal()
  Animal::~Animal() imprime "ANIMAL destructor called"
  libera el bloque 2080

Dog::~Dog() NUNCA SE LLAMA
  → el bloque 0x9f40 (el Brain) NUNCA se libera
  → MEMORY LEAK — el Brain queda flotando en el heap para siempre
```

---

## 15. La solucion — virtual ~Animal()

```cpp
class Animal {
    virtual ~Animal();   // destructor virtual
};
```

Con el destructor virtual, `delete p` consulta la vtable igual que con makeSound:

```
delete p — CON virtual ~Animal():
  consulta vptr → vtable de Dog → Dog::~Dog
  llama Dog::~Dog() → imprime "DOG destructor called" → delete _brain
  luego llama Animal::~Animal() automaticamente → imprime "ANIMAL destructor called"
  libera el bloque 2080

Brain destruido correctamente → sin memory leak
```

---

## 16. La regla — cuando hacer el destructor virtual

**Si una clase tiene al menos un metodo virtual, su destructor debe ser virtual.**

En este modulo, Animal tiene `virtual makeSound()` → necesita `virtual ~Animal()`. Dog y Cat heredan el destructor virtual automaticamente — aunque no pongas `virtual` en sus destructores, lo son de facto.

---

# PARTE 5 — WRONGANIMAL Y WRONGCAT — EL CONTRASTE

---

## 17. Por que existen WrongAnimal y WrongCat

El subject pide crear estas clases para demostrar por contraste que sin `virtual` el polimorfismo no funciona. Son copias exactas de Animal y Cat pero sin `virtual` en ningun metodo.

```
Animal      → virtual void makeSound()  → dispatch dinamico → correcto
WrongAnimal → void makeSound()          → dispatch estatico → incorrecto
```

---

## 18. Comparacion directa — Animal vs WrongAnimal en RAM

```
const Animal *p = new Cat():
  HEAP: [ objeto Cat con vptr → vtable de Cat ]
  p->makeSound() → consulta vtable → Cat::makeSound() → "CAT purrs to heal"
  CORRECTO

const WrongAnimal *w = new WrongCat():
  HEAP: [ objeto WrongCat SIN vptr ]
  w->makeSound() → compilador ya decidio → WrongAnimal::makeSound() → "WRONG ANIMAL..."
  INCORRECTO — imprime el sonido del padre, no del hijo
```

---

## 19. El output que demuestra la diferencia

```
// con virtual:
const Animal *p = new Cat();
p->makeSound();
→ "CAT purrs to heal"   ← correcto, es el sonido del Cat

// sin virtual:
const WrongAnimal *w = new WrongCat();
w->makeSound();
→ "WRONG ANIMAL SOUND SYSTEM"   ← incorrecto, es el sonido del WrongAnimal
```

---

# PARTE 6 — FUNCIONES PURE VIRTUAL Y CLASES ABSTRACTAS

---

## 20. El problema — Animal no deberia instanciarse

Crear un Animal directamente no tiene sentido:

```cpp
Animal *a = new Animal();
a->makeSound();   // que sonido hace un "Animal"? ninguno concreto
```

Animal existe solo como molde para Dog y Cat. Deberia ser imposible crear uno directamente.

---

## 21. Pure virtual — la funcion que obliga a implementar

Una funcion **pure virtual** se declara con `= 0` al final:

```cpp
virtual void makeSound(void) const = 0;
//                                  ^^^
//                          pure virtual — sin implementacion en esta clase
```

El `= 0` no significa que devuelva cero. Es una sintaxis especial que le dice al compilador dos cosas:

1. Esta funcion no tiene implementacion en esta clase
2. Cualquier clase que herede de esta y no la implemente sera tambien abstracta

---

## 22. Clase abstracta — que es y que implica

Una clase con al menos un metodo pure virtual es una **clase abstracta**. No se puede instanciar directamente:

```cpp
Animal *a = new Animal();   // ERROR — Animal es abstracta
Animal a;                   // ERROR — Animal es abstracta
```

El compilador da error en tiempo de compilacion. Es imposible crear un objeto Animal — exactamente lo que queremos.

---

## 23. Lo que no puedes hacer con una clase abstracta

```cpp
Animal a;                         // ERROR — instancia directa
Animal *p = new Animal();         // ERROR — instancia en heap
Animal animales[10];              // ERROR — array de instancias
void funcion(Animal a) { ... }    // ERROR — parametro por valor (implica copia)
```

---

## 24. Lo que si puedes hacer — punteros y referencias

Los punteros y referencias a clases abstractas son perfectamente validos:

```cpp
Animal *p = new Dog();   // OK — p apunta a un Dog (que si es instanciable)
Animal &r = dog;         // OK — referencia a un Dog existente
Animal *array[10];       // OK — array de punteros (no de instancias)
void funcion(Animal &a); // OK — parametro por referencia
void funcion(Animal *a); // OK — parametro por puntero
```

Esto es exactamente lo que hace el array del ex01 y ex02 — `const Animal *animals[10]` es un array de punteros a Animal, no un array de objetos Animal.

---

## 25. La clase derivada debe implementar todos los pure virtual

Si Dog hereda de Animal y no implementa `makeSound()`, Dog tambien es abstracta:

```cpp
class Dog : public Animal {
    // no implementa makeSound()
};

Dog d;   // ERROR — Dog tambien es abstracta porque no implemento makeSound()
```

Para que Dog sea instanciable, DEBE implementar todos los metodos pure virtual que hereda:

```cpp
class Dog : public Animal {
    virtual void makeSound(void) const;   // declarado
};

// Dog.cpp:
void Dog::makeSound(void) const {
    std::cout << "DOG barks at the hippies" << std::endl;
}
// ahora Dog es instanciable
```

---

## 26. El prefijo A — convencion para clases abstractas

El subject sugiere llamar a la clase `AAnimal` en lugar de `Animal`. La A al principio es una convencion para indicar visualmente que la clase es abstracta — igual que la I al principio indica interfaz en otros lenguajes.

Es opcional. Si usas el prefijo, aplícalo en todos los archivos — el .hpp, el .cpp y todos los includes. En este modulo la clase se llama `Animal` pero el archivo se llama `AAnimal.hpp` — lo importante es ser consistente.

---

# PARTE 7 — COPIA SUPERFICIAL VS COPIA PROFUNDA

---

## 27. El problema — atributos que son punteros

Dog y Cat tienen un atributo `Brain *_brain` — un puntero a un objeto en el heap. Cuando copias un Dog, tienes que decidir que hacer con ese puntero.

---

## 28. La copia superficial — shallow copy — el desastre

Sin definir el constructor de copia y el operator=, el compilador genera versiones automaticas que copian los atributos byte por byte. Para un `int` o un `std::string` eso es correcto. Para un puntero es catastrofico:

```cpp
Dog a;
Dog b = a;   // shallow copy automatica del compilador

// lo que hace la shallow copy:
b._type  = a._type;    // copia el string — correcto
b._brain = a._brain;   // copia el PUNTERO — catastrofico
```

Ahora `a._brain` y `b._brain` tienen la misma direccion — apuntan al mismo Brain.

---

## 29. Traza del desastre en RAM

```
Despues de Dog b = a (shallow copy):

STACK:
  a._brain = 0x9f40
  b._brain = 0x9f40   ← misma direccion

HEAP:
  cajon 0x9f40: [ Brain con 100 ideas ]
                  ↑                ↑
             a apunta aqui    b apunta aqui tambien

Problema 1 — modificar b modifica a:
  b.getBrain()->setIdea(0, "nueva idea");
  → modifica el cajon 0x9f40
  → a.getBrain()->getIdea(0) devuelve "nueva idea" — no deberia

Problema 2 — destruir b destruye el Brain de a:
  ~Dog() de b: delete _brain → libera el cajon 0x9f40
  a._brain = 0x9f40 → DANGLING POINTER — apunta a memoria liberada
  ~Dog() de a: delete _brain → libera 0x9f40 de nuevo → DOUBLE FREE → CRASH
```

---

## 30. La solucion — deep copy

La deep copy crea un Brain nuevo para cada objeto copiado y copia el contenido:

```cpp
Dog::Dog(const Dog &copy) : Animal(copy)
{
    this->_brain = new Brain();        // crea un Brain nuevo en el heap
    *this->_brain = *copy._brain;     // copia el CONTENIDO del Brain original
}
```

`*copy._brain` desreferencia el puntero — accede al objeto Brain en si, no al puntero. `*this->_brain = ...` llama al `Brain::operator=` que copia las 100 ideas una a una.

---

## 31. Traza de la deep copy en RAM

```
Dog b = a (deep copy):

PASO 1: new Brain()
  HEAP reserva cajon 0xb230 → nuevo Brain vacio

PASO 2: *this->_brain = *copy._brain
  copia los 100 strings de 0x9f40 en 0xb230
  llama a Brain::operator= que hace el bucle while

Resultado:
STACK:
  a._brain = 0x9f40
  b._brain = 0xb230   ← direccion diferente

HEAP:
  cajon 0x9f40: [ Brain de a — sin cambios ]
  cajon 0xb230: [ Brain de b — copia identica pero independiente ]

Ahora:
  b.getBrain()->setIdea(0, "nueva idea");
  → modifica solo el cajon 0xb230
  → a.getBrain()->getIdea(0) sigue siendo la idea original → CORRECTO

Destruir b:
  delete b._brain → libera 0xb230 — solo el Brain de b
  a._brain = 0x9f40 → sigue valido → SIN DANGLING POINTER
```

---

# PARTE 8 — LA CLASE BRAIN

---

## 32. Por que existe Brain

Brain representa la "mente" del animal — una coleccion de 100 ideas. Al separarlo en su propia clase:

1. Dog y Cat pueden tener su Brain en el heap (con `new`) en lugar del stack
2. Puedes demostrar la deep copy de forma concreta y verificable
3. Si el Brain crece o cambia, no hay que modificar Dog ni Cat

---

## 33. El array de strings — como se almacena en RAM

```cpp
class Brain {
    std::string _ideas[100];
};
```

Un array de 100 strings es un bloque contiguo en memoria. Cuando el Brain se crea en el heap con `new Brain()`:

```
HEAP:
cajon 0x9f40: [ _ideas[0]  = "" ]
cajon 0x9f60: [ _ideas[1]  = "" ]
cajon 0x9f80: [ _ideas[2]  = "" ]
...
cajon 0xa6c0: [ _ideas[99] = "" ]
```

Cada `std::string` gestiona su propia memoria interna. El array en si es un bloque de 100 strings contiguos.

---

## 34. Por que los arrays no se copian con =

En C++, los arrays nativos no son copiables directamente:

```cpp
std::string a[100];
std::string b[100];
b = a;   // ERROR — los arrays no tienen operator= en C++
```

Esta es la razon por la que el `Brain::operator=` necesita un bucle — para copiar los 100 strings uno a uno. No hay atajo.

```cpp
Brain &Brain::operator=(const Brain &copy) {
    if (this != &copy) {
        int i = 0;
        while (i < 100) {
            this->_ideas[i] = copy._ideas[i];   // copia string por string
            i++;
        }
    }
    return *this;
}
```

---

## 35. El bucle de copia en operator=

El bucle copia cada `std::string` individualmente. Cada `std::string` tiene su propio `operator=` que hace una copia profunda del contenido del string. Asi que la copia del Brain es automaticamente una deep copy — cada idea es una cadena independiente.

---

# PARTE 9 — DOG Y CAT CON BRAIN*

---

## 36. new Brain() en el constructor — por que en el heap

El Brain se crea en el heap con `new Brain()` en el constructor:

```cpp
Dog::Dog() : Animal("Dog")
{
    this->_brain = new Brain();   // en el heap
}
```

Por que en el heap y no en el stack? Porque el Dog podria ser creado el mismo en el heap con `new Dog()`. Si el Brain fuera un atributo de valor (no puntero), existiria dentro del bloque del Dog en el heap — correcto. Pero al ser un puntero, el Brain es un objeto independiente en el heap con su propio tiempo de vida.

En RAM cuando se hace `new Dog()`:

```
HEAP:
cajon 2080: [ Dog object ]
              vptr → vtable de Dog
              _type = "Dog"
              _brain = 0x9f40   ← puntero al Brain

cajon 0x9f40: [ Brain object ]
               _ideas[0..99] = ""
```

Dos objetos en el heap, uno apuntando al otro.

---

## 37. delete _brain en el destructor — obligatorio

Cada `new` debe tener su `delete`. El Brain se crea en el constructor con `new`, se destruye en el destructor con `delete`:

```cpp
Dog::~Dog()
{
    std::cout << "- DOG destructor called" << std::endl;
    delete _brain;   // libera el Brain del heap
}
```

Si olvidas el `delete _brain`, cada vez que un Dog se destruye el Brain queda flotando en el heap — memory leak. Con el array de 10 Animals del main, tendrias 10 Brains perdidos.

El orden importa: primero el mensaje (para que sea legible en el output), luego el delete.

---

## 38. El constructor de copia — new Brain() mas copia de contenido

```cpp
Dog::Dog(const Dog &copy) : Animal(copy)
{
    std::cout << "- DOG copy constructor called" << std::endl;
    this->_brain = new Brain();        // crea Brain nuevo — deep copy
    *this->_brain = *copy._brain;     // copia el contenido
}
```

Dos operaciones separadas:

1. `new Brain()` — reserva espacio en el heap para un Brain nuevo, llama a `Brain::Brain()` que inicializa las 100 ideas a string vacio
2. `*this->_brain = *copy._brain` — copia las 100 ideas del Brain original al nuevo, llamando a `Brain::operator=`

No uses `*this = copy` en el constructor de copia — llamaria al `Dog::operator=` que a su vez intenta copiar el Brain... pero el Brain ya acaba de ser inicializado con `new Brain()`. Funcionaria pero es redundante y confuso.

---

## 39. El operator= — sin new, solo copia de contenido

```cpp
Dog &Dog::operator=(const Dog &copy)
{
    if (this != &copy) {
        Animal::operator=(copy);
        *this->_brain = *copy._brain;   // copia contenido — SIN new
    }
    return *this;
}
```

La diferencia critica con el constructor de copia:

```
Constructor de copia:
  _brain no existe todavia → new Brain() OBLIGATORIO para crearlo
  luego copiar el contenido

Operator=:
  _brain YA existe (fue creado en el constructor) → NO hacer new
  solo copiar el contenido con *this->_brain = *copy._brain
```

Si hicieras `new Brain()` en el operator=, perderia la referencia al Brain anterior — memory leak. El Brain viejo quedaria en el heap sin posibilidad de borrarlo.

---

## 40. La diferencia entre constructor de copia y operator=

```
                     ¿El objeto destino existe ya?
                            /         \
                          NO           SI
                           |            |
              Constructor de copia   Operator=
                     |                  |
              new Brain()          no new Brain()
              copiar contenido     copiar contenido
```

Esta distincion es exactamente la misma que aprendiste en CPP02 con la OCF, pero ahora con un puntero a objeto dinamico donde el error tiene consecuencias reales — memory leak o double free.

---

# PARTE 10 — EL ARRAY DE ANIMALS

---

## 41. Por que usar Animal* y no Dog* o Cat*

```cpp
const Animal *animals[10];   // array de punteros a Animal
animals[0] = new Dog();      // OK — Dog ES UN Animal
animals[5] = new Cat();      // OK — Cat ES UN Animal
```

Si usaras `Dog *dogs[5]` y `Cat *cats[5]`, tendrias dos arrays separados y no podrias destruirlos en un solo bucle. Con `Animal*` puedes mezclar Dogs y Cats en el mismo array y tratarlos uniformemente.

Esto es polimorfismo en accion: el array no sabe ni le importa si cada elemento es un Dog o un Cat. Solo sabe que son Animals.

---

## 42. Como el virtual destructor salva el array

```cpp
int i = 0;
while (i < 10) {
    delete animals[i];
    i++;
}
```

`animals[i]` es `Animal*`. Sin `virtual ~Animal()`, `delete animals[i]` llamaria solo a `Animal::~Animal()` — nunca a `Dog::~Dog()` ni `Cat::~Cat()`. Los Brains nunca se destruirian. Memory leak en cada iteracion.

Con `virtual ~Animal()`:

```
delete animals[0]   (es un Dog):
  consulta vptr → vtable de Dog → Dog::~Dog
  Dog::~Dog() → "DOG destructor called" → delete _brain
  Animal::~Animal() → "ANIMAL destructor called"
  Brain destruido, Dog destruido → sin leak

delete animals[5]   (es un Cat):
  consulta vptr → vtable de Cat → Cat::~Cat
  Cat::~Cat() → "CAT destructor called" → delete _brain
  Animal::~Animal() → "ANIMAL destructor called"
  Brain destruido, Cat destruido → sin leak
```

---

## 43. El orden de destruccion con virtual

Para cada elemento del array:

```
1. Destructor del tipo real (Dog o Cat) — imprime mensaje y borra Brain
2. Destructor de Animal — imprime mensaje
```

El Brain siempre se destruye antes que el Animal. El Animal es el ultimo en morir.

---

## 44. Memory leaks — como detectarlos

El subject dice "don't forget to check for memory leaks". Para verificar en Linux:

```bash
valgrind --leak-check=full ./animal
```

Si la salida muestra "All heap blocks were freed -- no leaks are possible", no hay leaks. Si muestra "definitely lost: X bytes", hay un `new` sin su `delete`.

En Mac:

```bash
leaks --atExit -- ./animal
```

El programa del ex01 y ex02 es correcto si: cada `new Dog()` tiene su `delete` correspondiente en el destructor del Dog, y lo mismo para Cat. Con el array de 10 Animals y el test de deep copy, hay exactamente este numero de new/delete:

```
Array: 5 Dog (5 Brain) + 5 Cat (5 Brain) = 10 new + 10 new Brain = 20 new
Deep copy Dog: 2 Dog (2 Brain) = 2 new + 2 new Brain = 4 new
Deep copy Cat: 2 Cat (2 Brain) = 2 new + 2 new Brain = 4 new
Total: 28 new → deben existir exactamente 28 delete
```

---

# PARTE 11 — LOS EJERCICIOS EXPLICADOS UNO A UNO

---

## 45. Ex00: Polymorphism

**Concepto central:** virtual functions y polimorfismo de subtipo.

**Clases:** Animal (base), Dog (derivada), Cat (derivada), WrongAnimal (base sin virtual), WrongCat (derivada sin virtual).

**La clave:** `virtual void makeSound() const` en Animal. Con puntero `Animal*`, el sistema consulta la vtable del objeto real y llama al sonido correcto.

**El contraste WrongAnimal/WrongCat:** sin virtual, el tipo del puntero manda. Un puntero `WrongAnimal*` a un objeto WrongCat siempre llama a `WrongAnimal::makeSound()`.

**getType():** devuelve `const std::string &` — referencia constante, sin copia. El `const` al final del metodo garantiza que no modifica el objeto.

---

## 46. Ex01: I don't want to set the world on fire

**Concepto central:** deep copy con atributos puntero.

**La clase Brain:** array de 100 strings. Su `operator=` copia los 100 strings en un bucle while — no hay atajo porque los arrays no son copiables directamente.

**Dog y Cat con Brain*:**

```
Constructor:       _brain = new Brain()
Constructor copia: _brain = new Brain() + *_brain = *copy._brain
Operator=:         *_brain = *copy._brain (sin new — _brain ya existe)
Destructor:        delete _brain
```

**El array de Animals:** `const Animal *animals[10]` — punteros a Animal que pueden apuntar a Dogs o Cats. El virtual destructor garantiza que al hacer `delete animals[i]` se llama al destructor correcto y el Brain se libera.

**Test de deep copy:** crear Dog a, poner una idea, crear Dog b = a, cambiar la idea en b, verificar que a no cambio. Si los valores son distintos, la deep copy es correcta.

---

## 47. Ex02: Abstract class

**Concepto central:** pure virtual functions y clases abstractas.

**El unico cambio:** en `Animal.hpp`:

```cpp
// antes:
virtual void makeSound(void) const;

// despues:
virtual void makeSound(void) const = 0;
```

Y eliminar la implementacion de `makeSound()` en `Animal.cpp`.

**Consecuencia:** `Animal` ya no se puede instanciar directamente. La linea del main `new Animal()` da error de compilacion — exactamente lo que el subject pide.

**Dog y Cat siguen siendo instanciables** porque implementan el metodo pure virtual heredado.

**El nombre AAnimal:** convencion para indicar que es abstracta. Si se usa, debe aplicarse en todos los archivos — hpp, cpp y todos los includes.

---

# GLOSARIO COMPLETO

| Termino | Definicion |
|---|---|
| Polimorfismo | Capacidad de tratar objetos de tipos distintos de forma uniforme |
| Polimorfismo de subtipo | Llamar al metodo correcto de un objeto derivado a traves de puntero a clase base |
| Dispatch estatico | El compilador decide en tiempo de compilacion que funcion llamar |
| Dispatch dinamico | El programa decide en tiempo de ejecucion consultando la vtable |
| virtual (metodo) | Activa el dispatch dinamico — el objeto real manda, no el tipo del puntero |
| vtable | Tabla generada por el compilador con punteros a los metodos virtuales de cada clase |
| vptr | Puntero oculto en cada objeto que apunta a la vtable de su clase real |
| virtual (destructor) | Garantiza que delete con puntero a clase base llama al destructor correcto |
| Pure virtual (= 0) | Funcion virtual sin implementacion — obliga a las clases derivadas a implementarla |
| Clase abstracta | Clase con al menos un metodo pure virtual — no se puede instanciar directamente |
| Instanciar | Crear un objeto de una clase |
| WrongAnimal | Clase igual que Animal pero sin virtual — demuestra el comportamiento incorrecto sin virtual |
| Shallow copy | Copia byte a byte — copia el puntero, no el objeto apuntado |
| Deep copy | Crea un objeto nuevo y copia el contenido — objetos completamente independientes |
| Brain* | Puntero a Brain — requiere new en el constructor y delete en el destructor |
| new Brain() | Reserva memoria en el heap y llama al constructor de Brain |
| delete _brain | Llama al destructor de Brain y libera la memoria del heap |
| *this->_brain = *copy._brain | Copia el contenido del Brain — llama a Brain::operator= |
| Memory leak | Memoria reservada con new que nunca se libera con delete |
| Double free | Hacer delete dos veces al mismo bloque de memoria — crash garantizado |
| Dangling pointer | Puntero que apunta a memoria ya liberada |
| Array de Animals | const Animal *animals[10] — punteros a Animal que pueden apuntar a Dogs o Cats |
| getBrain() | Getter que devuelve el puntero al Brain — necesario para verificar la deep copy |
| Valgrind | Herramienta para detectar memory leaks en Linux |
| AAnimal | Convencion de nombre para indicar que la clase es abstracta (prefijo A) |
| const (metodo) | El metodo no modifica ningun atributo del objeto |
| const std::string & | Devuelve referencia constante — eficiente, sin copia del string |
