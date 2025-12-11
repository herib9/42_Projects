// 📌 1. ¿QUE ES EL PROYECTO PHILOSOPHERS?

El proyecto Philosophers consiste en implementar la solución al problema de los filósofos comensales, un clásico de concurrencia 
y sincronización en programación.

-	El problema:

Hay N filósofos sentados en una mesa redonda.

Cada filósofo alterna entre pensar 🧠, comer 🍝 y dormir 😴.

Para comer necesita dos tenedores (el de su izquierda y el de su derecha).

Los tenedores son recursos compartidos entre los filósofos.

El reto: evitar condiciones de carrera, interbloqueos (deadlocks), inanición (starvation) y hacer que todos funcionen de forma 
sincronizada.


// 📌 2. LO QUE DEBES SABER ANTES DE COMENZAR

Para este proyecto vas a trabajar con threads (hilos) y mutex (mutual exclusion locks) en C. Necesitas conocer:

Threads (pthread):

pthread_create, pthread_join → crear y esperar hilos.

Mutex (pthread_mutex):

pthread_mutex_init, pthread_mutex_lock, pthread_mutex_unlock, pthread_mutex_destroy.

Condiciones de carrera: qué pasa si dos hilos acceden a la vez a la misma variable.

Deadlock: cuando los filósofos se bloquean esperando recursos.

Starvation: cuando alguno nunca logra comer.

Tiempos en C:

gettimeofday, usleep.

Además, es recomendable organizar bien tu código con estructuras y funciones auxiliares.


// 📌 3. REGLAS DEL PROYECTO (resumen)

La simulación recibe parámetros por argv:

./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

number_of_philosophers: número de filósofos (y tenedores).

time_to_die: tiempo máximo sin comer antes de morir.

time_to_eat: cuánto tarda en comer.

time_to_sleep: cuánto tarda en dormir.

[opcional]: si se indica, la simulación termina cuando todos han comido X veces.

Reglas de la simulación:

Todos los filósofos empiezan a pensar.

Para comer, deben coger primero el tenedor izquierdo y luego el derecho (mutex lock).

Si no comen dentro de time_to_die, mueren (se debe imprimir un mensaje y terminar la simulación).

El programa debe imprimir eventos con timestamps y el ID del filósofo:

[tiempo] [filósofo] has taken a fork

[tiempo] [filósofo] is eating

[tiempo] [filósofo] is sleeping

[tiempo] [filósofo] is thinking

[tiempo] [filósofo] died


// 📌 4. PASOS PARA DESARROLLAR EL PROYECTO

🔹 Paso 1: Parseo y validación

Leer los argumentos (argv) y guardarlos en una estructura.

Validar que sean números válidos y positivos.

🔹 Paso 2: Definir estructuras

Una estructura configuración global:

typedef struct s_rules {
    int n_philos;        // número de filósofos
    long time_to_die;
    long time_to_eat;
    long time_to_sleep;
    int must_eat;        // opcional
    int someone_died;
    pthread_mutex_t *forks;  // array de mutex (uno por tenedor)
    pthread_mutex_t print;   // mutex para imprimir sincronizado
    long start_time;
} t_rules;


Una estructura filósofo:

typedef struct s_philo {
    int id;
    int meals_eaten;
    long last_meal;
    pthread_t thread;
    t_rules *rules;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
} t_philo;

🔹 Paso 3: Inicialización

Inicializar mutex para cada tenedor.

Crear un array de filósofos.

Asignar forks (izquierda/derecha).

🔹 Paso 4: Ciclo del filósofo

Cada filósofo (hilo) sigue este ciclo:

while (nadie ha muerto y aún debe comer):
    pensar
    tomar tenedor izquierdo
    tomar tenedor derecho
    comer
    soltar tenedores
    dormir

🔹 Paso 5: Monitor de muerte

Un hilo extra o función que revise constantemente si algún filósofo ha muerto (gettimeofday - last_meal > time_to_die).

Si muere, detener la simulación.

🔹 Paso 6: Limpieza

Liberar mutex, memoria, y terminar todos los hilos.


// 📌 5. ESQUEMA GENERAL DEL PROYECTO

philosophers/
├── Makefile
├── includes/
│   └── philo.h
├── src/
│   ├── main.c         (entrada del programa, parseo, inicio de hilos)
│   ├── init.c         (inicializar estructuras y mutex)
│   ├── philo.c        (lógica del ciclo de vida de cada filósofo)
│   ├── monitor.c      (vigilar muertes y condiciones de parada)
│   ├── utils.c        (funciones auxiliares: tiempo, impresión segura, atoi seguro)
└── README.md


// 📌 6. PSEUDOCODIGO GENERAL
main(argv):
    args = parse_args(argv)
    rules = init_rules(args)
    philos = init_philos(rules)

    start_time = get_time()
    create thread for each philosopher (philo_routine)

    monitor_deaths(philos, rules)  // bucle que vigila muertes

    join all threads
    destroy all mutex
    exit

philo_routine(philo):
    while (!rules.someone_died && (no terminó de comer)):
        print("is thinking")
        take left fork (mutex_lock)
        print("has taken a fork")
        take right fork (mutex_lock)
        print("has taken a fork")
        print("is eating")
        last_meal = get_time()
        sleep(rules.time_to_eat)
        meals_eaten++
        release forks (mutex_unlock)
        print("is sleeping")
        sleep(rules.time_to_sleep)

monitor_deaths(philos, rules):
    while (!rules.someone_died):
        for each philo:
            if (get_time() - philo.last_meal > rules.time_to_die):
                print("died")
                rules.someone_died = 1
                break
        sleep(1ms)  // para no sobrecargar CPU