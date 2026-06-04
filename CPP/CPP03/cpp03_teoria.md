# CPP - Module 03
## Herencia, herencia múltiple y el problema del diamante
## De cero a entenderlo todo de verdad

---

# INDICE

**PARTE 1 — Qué es la herencia y por qué existe**
1. El problema sin herencia — la duplicación de código
2. La herencia — el molde que hereda de otro molde
3. La relación "es un" — cómo pensar en herencia
4. Clase base y clase derivada — los términos
5. La sintaxis de la herencia

**PARTE 2 — Los niveles de acceso en herencia**
6. El problema de private en herencia
7. protected — el nivel intermedio
8. Los tres niveles comparados — private, protected, public
9. La herencia pública — public ClapTrap

**PARTE 3 — Constructores y destructores en herencia**
10. El problema — quién inicializa los atributos del padre
11. Llamar al constructor del padre — la lista de inicialización
12. El orden de construcción — de padre a hijo
13. Qué pasa si no llamas al constructor del padre
14. El orden de destrucción — de hijo a padre
15. Traza completa en RAM — construcción y destrucción de ScavTrap

**PARTE 4 — Sobreescribir métodos**
16. El problema — ScavTrap ataca diferente a ClapTrap
17. Sobreescribir un método — override
18. Llamar al método del padre desde el hijo
19. La resolución de ámbito — ClapTrap::attack()

**PARTE 5 — Herencia múltiple**
20. Qué es la herencia múltiple
21. El problema del diamante — dos copias del mismo abuelo
22. Visualizando el diamante en RAM
23. La ambigüedad — qué pasa al compilar sin solución

**PARTE 6 — Herencia virtual**
24. La solución — virtual
25. Qué hace virtual exactamente
26. El cajón compartido — visualización en RAM
27. La nueva regla del constructor — quién inicializa ClapTrap
28. El orden de construcción con virtual
29. El problema de los stats — por qué hardcodear es correcto

**PARTE 7 — El using para métodos**
30. El problema — dos padres con el mismo método
31. using — elegir cuál heredar
32. using vs override — cuándo usar cada uno

**PARTE 8 — Los ejercicios explicados uno a uno**
33. Ex00: ClapTrap
34. Ex01: ScavTrap — herencia simple
35. Ex02: FragTrap — herencia simple
36. Ex03: DiamondTrap — herencia múltiple con virtual

**Glosario completo**

---

# PARTE 1 — QUÉ ES LA HERENCIA Y POR QUÉ EXISTE

---

## 1. El problema sin herencia — la duplicación de código

Imagina que tienes ClapTrap y luego necesitas crear ScavTrap. ScavTrap es como ClapTrap pero más fuerte y con una habilidad extra. Sin herencia harías esto:

```cpp
class ClapTrap {
    std::string _name;
    int _hitPoints;
    int _energyPoints;
    int _attackDamage;
    void attack(...);
    void takeDamage(...);
    void beRepaired(...);
};

class ScavTrap {
    std::string _name;       // DUPLICADO
    int _hitPoints;          // DUPLICADO
    int _energyPoints;       // DUPLICADO
    int _attackDamage;       // DUPLICADO
    void attack(...);        // DUPLICADO (con pequeños cambios)
    void takeDamage(...);    // DUPLICADO exacto
    void beRepaired(...);    // DUPLICADO exacto
    void guardGate();        // lo único nuevo
};
```

Problemas:
- Si añades un atributo a ClapTrap, tienes que añadirlo también en ScavTrap, FragTrap y cualquier otro robot
- Si corriges un bug en `takeDamage`, tienes que corregirlo en todos los robots
- El código crece sin control

La herencia resuelve esto: defines la base una vez y las clases derivadas solo añaden o cambian lo que necesitan.

---

## 2. La herencia — el molde que hereda de otro molde

Con herencia, ScavTrap dice: "soy como ClapTrap, pero con estas diferencias".

```cpp
class ScavTrap : public ClapTrap {
    // no necesito repetir _name, _hitPoints, etc.
    // no necesito repetir takeDamage ni beRepaired
    // solo declaro lo que cambia o lo que es nuevo:
    void attack(const std::string &target);  // sobreescribo este
    void guardGate();                         // este es nuevo
};
```

ScavTrap hereda automáticamente todo lo de ClapTrap. `_name`, `_hitPoints`, `_energyPoints`, `_attackDamage`, `takeDamage`, `beRepaired` — todo disponible en ScavTrap sin escribir una sola línea extra.

---

## 3. La relación "es un" — cómo pensar en herencia

La herencia representa una relación **"es un"**:

```
ScavTrap ES UN ClapTrap (con más características)
FragTrap ES UN ClapTrap (con más características)
DiamondTrap ES UN ScavTrap Y ES UN FragTrap
```

Esta relación tiene una consecuencia importante: puedes usar un ScavTrap donde se espera un ClapTrap:

```cpp
void funcion(ClapTrap &robot) {
    robot.attack("objetivo");
}

ScavTrap scav("AFX");
funcion(scav);   // funciona — ScavTrap ES UN ClapTrap
```

---

## 4. Clase base y clase derivada — los términos

```
ClapTrap  →  clase base (o clase padre, o superclase)
ScavTrap  →  clase derivada (o clase hija, o subclase)
```

La clase base es el molde original. La clase derivada es el molde que hereda del original y lo extiende.

Puedes encadenar la herencia:

```
ClapTrap (base)
  └── ScavTrap (derivada de ClapTrap)
  └── FragTrap (derivada de ClapTrap)
        └── DiamondTrap (derivada de ScavTrap y FragTrap)
```

---

## 5. La sintaxis de la herencia

```cpp
class ScavTrap : public ClapTrap
//               ^^^^^^
//               tipo de herencia — casi siempre public en 42
```

El `:` indica herencia. Lo que viene después es el tipo de herencia y el nombre de la clase base.

---

# PARTE 2 — LOS NIVELES DE ACCESO EN HERENCIA

---

## 6. El problema de private en herencia

En ClapTrap, si los atributos son `private`:

```cpp
class ClapTrap {
    private:
        std::string _name;      // private
        int _hitPoints;         // private
        int _energyPoints;      // private
        int _attackDamage;      // private
};
```

ScavTrap hereda de ClapTrap, pero NO puede acceder a esos atributos:

```cpp
void ScavTrap::attack(const std::string &target) {
    _energyPoints--;    // ERROR — _energyPoints es private en ClapTrap
                        // ScavTrap no puede tocarlo
}
```

Esto es un problema. ScavTrap necesita modificar `_hitPoints`, `_energyPoints` etc. para que `attack`, `takeDamage` y `beRepaired` funcionen.

---

## 7. protected — el nivel intermedio

`protected` es el nivel de acceso diseñado exactamente para la herencia:

```
private    → solo la propia clase puede acceder
protected  → la propia clase Y sus clases derivadas pueden acceder
public     → cualquiera puede acceder
```

Con `protected` en ClapTrap:

```cpp
class ClapTrap {
    protected:               // ← cambiado de private a protected
        std::string _name;
        int _hitPoints;
        int _energyPoints;
        int _attackDamage;
};
```

Ahora ScavTrap, FragTrap y DiamondTrap pueden acceder directamente a estos atributos:

```cpp
void ScavTrap::attack(const std::string &target) {
    _energyPoints--;    // OK — _energyPoints es protected, ScavTrap puede acceder
}
```

Pero desde fuera de la jerarquía, sigue siendo inaccesible:

```cpp
ScavTrap s("AFX");
s._energyPoints = 100;   // ERROR — protected, no accesible desde fuera
s.attack("Bob");          // OK — attack es public
```

---

## 8. Los tres niveles comparados

| | La propia clase | Clases derivadas | Cualquiera |
|---|---|---|---|
| `private` | ✅ | ❌ | ❌ |
| `protected` | ✅ | ✅ | ❌ |
| `public` | ✅ | ✅ | ✅ |

En CPP03, los atributos de ClapTrap deben ser `protected` — si son `private`, las clases hijas no pueden acceder a ellos directamente.

---

## 9. La herencia pública — public ClapTrap

```cpp
class ScavTrap : public ClapTrap
```

El `public` aquí indica el **tipo de herencia** — no el acceso a los atributos. Determina cómo los miembros de la clase base son vistos desde fuera de la clase derivada:

```
Herencia public:    los public del padre siguen siendo public en el hijo
Herencia protected: los public del padre pasan a protected en el hijo
Herencia private:   todo del padre pasa a private en el hijo
```

En 42 siempre usas `public` para la herencia. Es el comportamiento natural — ScavTrap sigue exponiendo los métodos públicos de ClapTrap.

---

# PARTE 3 — CONSTRUCTORES Y DESTRUCTORES EN HERENCIA

---

## 10. El problema — quién inicializa los atributos del padre

Cuando creas un ScavTrap, los atributos `_name`, `_hitPoints`, etc. pertenecen a ClapTrap. ¿Quién los inicializa?

El constructor de ScavTrap no puede inicializarlos directamente en su lista de inicialización — esos atributos pertenecen a ClapTrap y ClapTrap es quien sabe cómo inicializarlos correctamente.

La solución: ScavTrap llama al constructor de ClapTrap explícitamente.

---

## 11. Llamar al constructor del padre — la lista de inicialización

```cpp
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
//                                     ^^^^^^^^^^^^^^
//                          llama al constructor de ClapTrap con el nombre
    _hitPoints    = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << name << " constructor called" << std::endl;
}
```

`ClapTrap(name)` en la lista de inicialización significa: "antes de ejecutar el cuerpo de ScavTrap, ejecuta el constructor de ClapTrap con el argumento `name`".

El constructor de ClapTrap inicializa `_name = name`, `_hitPoints = 10`, `_energyPoints = 10`, `_attackDamage = 0`. Luego el cuerpo de ScavTrap sobreescribe los valores que necesita cambiar.

---

## 12. El orden de construcción — de padre a hijo

El padre siempre se construye antes que el hijo. Siempre.

```cpp
ScavTrap finalBoss("AFX");
```

Orden de ejecución:

```
1. ClapTrap::ClapTrap("AFX")   ← padre primero
   → _name = "AFX"
   → _hitPoints = 10
   → _energyPoints = 10
   → _attackDamage = 0
   → imprime "ClapTrap AFX constructor called"

2. ScavTrap::ScavTrap("AFX")   ← hijo después
   → _hitPoints = 100           (sobreescribe el 10 del padre)
   → _energyPoints = 50         (sobreescribe el 10 del padre)
   → _attackDamage = 20         (sobreescribe el 0 del padre)
   → imprime "ScavTrap AFX constructor called"
```

En la salida del programa lo ves claramente:
```
ClapTrap AFX constructor called
ScavTrap AFX constructor called
```

---

## 13. Qué pasa si no llamas al constructor del padre

Si no pones `ClapTrap(name)` en la lista de inicialización, el compilador llama automáticamente al **constructor por defecto** de ClapTrap (el de sin parámetros):

```cpp
ScavTrap::ScavTrap(std::string name) {   // sin ClapTrap(name)
    // el compilador llama a ClapTrap() automáticamente
    // _name queda como "" — no se pasó el nombre
    _hitPoints = 100;
    // ...
}
```

Por eso en el constructor de ScavTrap es obligatorio llamar a `ClapTrap(name)` explícitamente — para que el nombre se pase correctamente.

---

## 14. El orden de destrucción — de hijo a padre

El orden de destrucción es exactamente el inverso al de construcción:

```
Construcción:  ClapTrap → ScavTrap
Destrucción:   ScavTrap → ClapTrap
```

```cpp
{
    ScavTrap finalBoss("AFX");
}   // sale del scope — destrucción automática

// orden:
// 1. ScavTrap::~ScavTrap()  → "ScavTrap AFX destructor called"
// 2. ClapTrap::~ClapTrap()  → "ClapTrap AFX destructor called"
```

Esto se cumple siempre: el hijo muere antes que el padre. El hijo "desaparece" primero y solo después se destruye el ClapTrap que vivía dentro.

---

## 15. Traza completa en RAM — construcción y destrucción de ScavTrap

```cpp
ScavTrap s("AFX");
```

**Construcción:**

```
Antes:
  STACK: vacío en ese espacio

1. ClapTrap::ClapTrap("AFX") ejecuta:
   STACK:
   s → [ _name = "AFX"    ]
       [ _hitPoints = 10   ]
       [ _energyPoints = 10]
       [ _attackDamage = 0 ]
   imprime: "ClapTrap AFX constructor called"

2. ScavTrap::ScavTrap("AFX") ejecuta:
   STACK:
   s → [ _name = "AFX"    ]  ← sin cambios
       [ _hitPoints = 100  ]  ← sobreescrito
       [ _energyPoints = 50]  ← sobreescrito
       [ _attackDamage = 20]  ← sobreescrito
   imprime: "ScavTrap AFX constructor called"
```

**Destrucción:**

```
Al salir del scope:

1. ScavTrap::~ScavTrap() ejecuta:
   imprime: "ScavTrap AFX destructor called"

2. ClapTrap::~ClapTrap() ejecuta:
   imprime: "ClapTrap AFX destructor called"
   STACK: espacio liberado
```

---

# PARTE 4 — SOBREESCRIBIR MÉTODOS

---

## 16. El problema — ScavTrap ataca diferente a ClapTrap

ClapTrap tiene su `attack`. ScavTrap quiere un `attack` diferente — mismo nombre, misma firma, pero con su mensaje y sus stats.

Si ScavTrap no declara su propio `attack`, usa el de ClapTrap automáticamente. Para tener el suyo propio, tiene que **sobreescribirlo**.

---

## 17. Sobreescribir un método — override

Sobreescribir es declarar en la clase hija un método con **exactamente la misma firma** que en la clase padre:

```cpp
// en ClapTrap:
void attack(const std::string &target);

// en ScavTrap — misma firma, diferente implementación:
void attack(const std::string &target);
```

Cuando llamas a `attack` sobre un ScavTrap, el compilador usa la versión de ScavTrap. Cuando lo llamas sobre un ClapTrap, usa la de ClapTrap.

```cpp
ClapTrap c("Bob");
ScavTrap s("AFX");

c.attack("target");   // ClapTrap::attack
s.attack("target");   // ScavTrap::attack — sobreescrito
```

---

## 18. Llamar al método del padre desde el hijo

A veces quieres que el método del hijo haga todo lo del padre más algo extra. Puedes llamar al método del padre explícitamente:

```cpp
void ScavTrap::attack(const std::string &target) {
    ClapTrap::attack(target);   // ejecuta el attack del padre primero
    // luego añades lo tuyo
    std::cout << "ScavTrap specific stuff" << std::endl;
}
```

`ClapTrap::attack(target)` es la llamada explícita al método del padre — el `::` de resolución de ámbito especifica de qué clase quieres el método.

---

## 19. La resolución de ámbito — ClapTrap::attack()

El operador `::` en `ClapTrap::attack` significa "el `attack` que pertenece a `ClapTrap`". Sin él, el compilador usaría el método más cercano en la jerarquía — que en ScavTrap sería el propio ScavTrap::attack, creando un bucle infinito.

```cpp
void ScavTrap::attack(const std::string &target) {
    attack(target);             // PELIGRO — llama a ScavTrap::attack de nuevo
                                // bucle infinito
    ClapTrap::attack(target);   // CORRECTO — llama al de ClapTrap explícitamente
}
```

---

# PARTE 5 — HERENCIA MÚLTIPLE

---

## 20. Qué es la herencia múltiple

Una clase puede heredar de **más de una clase base al mismo tiempo**:

```cpp
class DiamondTrap : public ScavTrap, public FragTrap
```

DiamondTrap hereda todo de ScavTrap Y todo de FragTrap simultáneamente. Tiene acceso a `guardGate()` (de ScavTrap) y a `highFivesGuys()` (de FragTrap) sin implementar ninguno.

---

## 21. El problema del diamante — dos copias del mismo abuelo

ScavTrap hereda de ClapTrap. FragTrap también hereda de ClapTrap. DiamondTrap hereda de los dos.

```
        ClapTrap
       /        \
  ScavTrap    FragTrap
       \        /
       DiamondTrap
```

Sin ninguna medida especial, DiamondTrap tendría **dos instancias de ClapTrap**:

```
DiamondTrap contiene:
  → ScavTrap que contiene → ClapTrap (copia 1)
  → FragTrap que contiene → ClapTrap (copia 2)
```

Dos `_name`, dos `_hitPoints`, dos `_energyPoints`, dos `_attackDamage`.

---

## 22. Visualizando el diamante en RAM sin virtual

```
DiamondTrap d("BONITO");

RAM sin virtual:
+--------------------------------+
|  ClapTrap (de ScavTrap)        |
|    _name = "BONITO"            |  ← cajon 1040
|    _hitPoints = ...            |
|    _energyPoints = ...         |
|    _attackDamage = ...         |
+--------------------------------+
|  ScavTrap                      |
+--------------------------------+
|  ClapTrap (de FragTrap)        |
|    _name = "BONITO"            |  ← cajon 2080 — DUPLICADO
|    _hitPoints = ...            |
|    _energyPoints = ...         |
|    _attackDamage = ...         |
+--------------------------------+
|  FragTrap                      |
+--------------------------------+
|  DiamondTrap                   |
+--------------------------------+
```

---

## 23. La ambigüedad — qué pasa al compilar sin solución

Con dos copias de ClapTrap, cualquier acceso a `_name` dentro de DiamondTrap es ambiguo:

```cpp
void DiamondTrap::whoAmI() {
    std::cout << _name << std::endl;   // ERROR — ¿cuál de los dos _name?
    // el compilador no sabe si quieres ClapTrap(ScavTrap)::_name
    // o ClapTrap(FragTrap)::_name
}
```

El compilador da error:

```
error: member '_name' found in multiple base classes of different types
```

---

# PARTE 6 — HERENCIA VIRTUAL

---

## 24. La solución — virtual

La palabra `virtual` en la herencia le dice al compilador:

> "Si alguien hereda de mí y de otra clase que también hereda de la misma base, no dupliques la base — compartid una sola instancia."

```cpp
// ScavTrap.hpp
class ScavTrap : virtual public ClapTrap { ... };

// FragTrap.hpp
class FragTrap : virtual public ClapTrap { ... };
```

Con esto, cuando DiamondTrap hereda de los dos, el compilador crea **una sola instancia compartida** de ClapTrap.

---

## 25. Qué hace virtual exactamente

Sin virtual:
```
ScavTrap → tiene su propia copia de ClapTrap
FragTrap → tiene su propia copia de ClapTrap
DiamondTrap → tiene DOS copias (una de cada)
```

Con virtual:
```
ScavTrap → tiene una referencia al ClapTrap compartido
FragTrap → tiene una referencia al mismo ClapTrap compartido
DiamondTrap → tiene UNA sola copia de ClapTrap, compartida
```

---

## 26. El cajón compartido — visualización en RAM

```
DiamondTrap d("BONITO");

RAM con virtual:
+--------------------------------+
|  ClapTrap COMPARTIDO           |
|    _name = "BONITO_clap_name"  |  ← un solo cajon, compartido
|    _hitPoints = 100            |
|    _energyPoints = 50          |
|    _attackDamage = 30          |
+--------------------------------+
|  ScavTrap                      |  ← usa el ClapTrap de arriba
+--------------------------------+
|  FragTrap                      |  ← usa el mismo ClapTrap
+--------------------------------+
|  DiamondTrap                   |
|    _name = "BONITO"            |  ← su propio _name (diferente)
+--------------------------------+
```

Ahora cuando accedes a `_name` dentro de DiamondTrap, hay dos opciones claras:
- `_name` → el propio de DiamondTrap ("BONITO")
- `ClapTrap::_name` → el del ClapTrap compartido ("BONITO_clap_name")

Sin ambigüedad.

---

## 27. La nueva regla del constructor — quién inicializa ClapTrap

Con herencia virtual, surge una regla nueva e importante:

**El constructor de ClapTrap lo llama DIRECTAMENTE la clase más derivada (DiamondTrap), no las intermedias (ScavTrap y FragTrap).**

Sin virtual, la cadena era:
```
DiamondTrap llama a ScavTrap
  ScavTrap llama a ClapTrap
DiamondTrap llama a FragTrap
  FragTrap llama a ClapTrap   ← segunda vez — problema
```

Con virtual, el compilador ignora las llamadas a ClapTrap desde ScavTrap y FragTrap cuando se construye un DiamondTrap. Solo cuenta la llamada desde DiamondTrap:

```
DiamondTrap llama a ClapTrap directamente
DiamondTrap llama a ScavTrap (ScavTrap NO llama a ClapTrap esta vez)
DiamondTrap llama a FragTrap (FragTrap NO llama a ClapTrap esta vez)
```

Por eso en el constructor de DiamondTrap debes llamar a ClapTrap explícitamente:

```cpp
DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name"),   // OBLIGATORIO con virtual
      ScavTrap(name),
      FragTrap(name),
      _name(name)
{
    _hitPoints    = 100;
    _energyPoints = 50;
    _attackDamage = 30;
}
```

---

## 28. El orden de construcción con virtual

Con virtual, el orden es:

```
1. Virtual base primero: ClapTrap(name + "_clap_name")
2. Bases no virtuales en orden de declaración: ScavTrap, FragTrap
3. Miembros propios: _name
4. Cuerpo del constructor

Resultado en la salida:
  ClapTrap BONITO_clap_name constructor called
  ScavTrap BONITO constructor called
  FragTrap BONITO constructor called
  DiamondTrap BONITO constructor called
```

Y la destrucción en orden inverso:

```
  DiamondTrap BONITO destructor called
  FragTrap BONITO_clap_name destructor called
  ScavTrap BONITO_clap_name destructor called
  ClapTrap BONITO_clap_name destructor called
```

---

## 29. El problema de los stats — por qué hardcodear es correcto

Con herencia virtual hay UN SOLO cajón para `_energyPoints`. Cuando ScavTrap escribe 50 y luego FragTrap escribe 100 en ese mismo cajón, el resultado es 100.

```
Construcción de DiamondTrap("BONITO"):

1. ClapTrap: _energyPoints = 10  (valor inicial)
2. ScavTrap: _energyPoints = 50  (sobreescribe)
3. FragTrap: _energyPoints = 100 (sobreescribe de nuevo — mismo cajón)

Al llegar al cuerpo de DiamondTrap: _energyPoints = 100
```

El subject dice que DiamondTrap debe tener 50 de energía (de ScavTrap). La única forma de garantizarlo es asignarlo directamente en el cuerpo de DiamondTrap:

```cpp
_hitPoints    = 100;   // de FragTrap
_energyPoints = 50;    // de ScavTrap — tiene que ponerse explícitamente
_attackDamage = 30;    // de FragTrap
```

Esto no es un parche — es la decisión de diseño del ejercicio. DiamondTrap sabe exactamente qué quiere tomar de cada padre y lo declara explícitamente.

---

# PARTE 7 — EL USING PARA MÉTODOS

---

## 30. El problema — dos padres con el mismo método

DiamondTrap hereda de ScavTrap y FragTrap. Los dos tienen `attack`. ¿Cuál usa DiamondTrap?

```cpp
DiamondTrap d("BONITO");
d.attack("target");   // ERROR — ambiguo: ¿ScavTrap::attack o FragTrap::attack?
```

El compilador no puede decidir solo. Hay que decírselo.

---

## 31. using — elegir cuál heredar

```cpp
// en DiamondTrap.hpp, dentro de la clase:
using ScavTrap::attack;
```

Esto le dice al compilador: "cuando alguien llame a `attack` en un DiamondTrap, usa directamente el de ScavTrap."

No hay implementación en el `.cpp`. El `using` en el `.hpp` es suficiente.

---

## 32. using vs override — cuándo usar cada uno

**Usa `using`** cuando quieres heredar un método de un padre específico sin modificarlo:

```cpp
using ScavTrap::attack;   // usa ScavTrap::attack tal cual
```

**Sobreescribe** cuando quieres tu propia implementación diferente:

```cpp
// en .hpp:
void attack(const std::string &target);

// en .cpp:
void DiamondTrap::attack(const std::string &target) {
    // tu implementación propia
}
```

En CPP03, si DiamondTrap::attack debe mostrar el nombre propio de DiamondTrap (no el de ClapTrap), necesitas sobreescribir — porque `ScavTrap::attack` usa `ClapTrap::_name` internamente, no el `_name` propio de DiamondTrap.

---

# PARTE 8 — LOS EJERCICIOS EXPLICADOS UNO A UNO

---

## 33. Ex00: ClapTrap

**Concepto central:** primera clase con OCF y comportamiento de combate.

**Atributos:** `_name` (del constructor), `_hitPoints = 10`, `_energyPoints = 10`, `_attackDamage = 0`

**Regla clave:** si `_hitPoints < 1` O `_energyPoints < 1`, no puede atacar ni repararse.

**Métodos:**
- `attack` — cuesta 1 energía, imprime el daño que causaría
- `takeDamage` — resta vida, sin coste de energía
- `beRepaired` — cuesta 1 energía, suma vida

**Atributos `protected`** — obligatorio para que las clases hijas puedan acceder.

---

## 34. Ex01: ScavTrap — herencia simple

**Concepto central:** herencia simple — ScavTrap ES UN ClapTrap mejorado.

**Stats:** `_hitPoints = 100`, `_energyPoints = 50`, `_attackDamage = 20`

**Cambios respecto a ClapTrap:**
- Constructor llama a `ClapTrap(name)` en la lista de inicialización
- Sobreescribe `attack` con su propio mensaje
- Añade `guardGate()`

**Orden de construcción:**
```
ClapTrap constructor → ScavTrap constructor
```

**Orden de destrucción:**
```
ScavTrap destructor → ClapTrap destructor
```

---

## 35. Ex02: FragTrap — herencia simple

**Concepto central:** segunda herencia simple — mismo patrón que ScavTrap.

**Stats:** `_hitPoints = 100`, `_energyPoints = 100`, `_attackDamage = 30`

**Cambios respecto a ClapTrap:**
- Constructor llama a `ClapTrap(name)` en la lista de inicialización
- Sobreescribe `attack`
- Añade `highFivesGuys()`

**Importante:** en el `.hpp`, `class FragTrap : virtual public ClapTrap` — el `virtual` se añade aquí preparando el ex03. Sin él, el ex03 no compilará correctamente.

---

## 36. Ex03: DiamondTrap — herencia múltiple con virtual

**Concepto central:** herencia múltiple + problema del diamante + herencia virtual.

**Stats:** `_hitPoints = 100`, `_energyPoints = 50`, `_attackDamage = 30`

**Lo que tiene de especial:**
- Su propio atributo `_name` (además del `ClapTrap::_name`)
- `ClapTrap::_name` se inicializa a `name + "_clap_name"`
- Stats hardcodeados en el constructor — por el problema del cajón compartido
- `whoAmI()` — imprime ambos nombres

**Constructor con nombre:**
```cpp
DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name"),
      ScavTrap(name),
      FragTrap(name),
      _name(name)
{
    _hitPoints    = 100;
    _energyPoints = 50;
    _attackDamage = 30;
}
```

**Orden de construcción:**
```
ClapTrap BONITO_clap_name  (virtual base — primero siempre)
ScavTrap BONITO
FragTrap BONITO
DiamondTrap BONITO
```

**Orden de destrucción:**
```
DiamondTrap BONITO
FragTrap BONITO_clap_name
ScavTrap BONITO_clap_name
ClapTrap BONITO_clap_name
```

---

# GLOSARIO COMPLETO

| Término | Definición |
|---|---|
| Herencia | Mecanismo que permite a una clase adquirir atributos y métodos de otra |
| Clase base | La clase de la que se hereda — ClapTrap en este módulo |
| Clase derivada | La clase que hereda — ScavTrap, FragTrap, DiamondTrap |
| `class A : public B` | A hereda públicamente de B |
| `private` | Solo accesible desde la propia clase |
| `protected` | Accesible desde la propia clase y sus clases derivadas |
| `public` | Accesible desde cualquier sitio |
| Override | Sobreescribir un método del padre en la clase hija con la misma firma |
| `ClapTrap(name)` en lista de inicialización | Llama al constructor del padre antes de ejecutar el cuerpo del hijo |
| Orden de construcción | Padre primero, hijo después — siempre |
| Orden de destrucción | Hijo primero, padre después — siempre (inverso a construcción) |
| Herencia múltiple | Una clase hereda de más de una clase base |
| Problema del diamante | Dos copias del mismo abuelo cuando dos padres heredan de la misma base |
| `virtual` en herencia | Garantiza que solo existe una instancia compartida de la base |
| Clase base virtual | La clase base marcada con virtual — ClapTrap en el ex03 |
| Cajón compartido | Con virtual, los atributos de la base existen una sola vez para toda la jerarquía |
| Constructor de la clase más derivada | Con virtual, la clase más derivada es responsable de llamar al constructor de la base virtual |
| Ambigüedad | Error de compilación cuando el compilador no puede determinar cuál de las dos copias usar |
| `ClapTrap::_name` | Acceso explícito al atributo de ClapTrap — necesario cuando DiamondTrap tiene su propio `_name` |
| `using ScavTrap::attack` | Indica al compilador que use el attack de ScavTrap sin crear un método propio |
| Stats hardcodeados | Asignar los valores fijos directamente en el constructor — solución correcta al problema del cajón compartido |
| `whoAmI()` | Método de DiamondTrap que imprime su propio nombre y el de ClapTrap |
| `_name` propio de DiamondTrap | Atributo privado que "tapa" el `ClapTrap::_name` dentro de DiamondTrap |
| `name + "_clap_name"` | El nombre que recibe ClapTrap en DiamondTrap — diferente del nombre propio |
| Relación "es un" | Un ScavTrap ES UN ClapTrap — base de la herencia |
| `guardGate()` | Método exclusivo de ScavTrap |
| `highFivesGuys()` | Método exclusivo de FragTrap |
