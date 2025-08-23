                ┌───────────────────────────────────┐
                │          PUSH_SWAP (42)           │
                └───────────────────────────────────┘
                             │
      ┌──────────────────────┴──────────────────────┐
      │                                             │
┌───────────────┐                           ┌─────────────────┐
│ 1. Entender   │                           │ 2. Fundamentos  │
│ el problema   │                           │ en C            │
└───────────────┘                           └─────────────────┘
      │                                             │
  • Leer PDF oficial                          • Listas enlazadas
  • Operaciones permitidas                    • malloc / free
  • Objetivo: min movimientos                 • ft_split, ft_atoi, etc.
  • Ejemplos entrada/salida                   • Rango INT_MIN/MAX
      │                                             │
      └──────────────────────┐   ┌──────────────────┘
                             ▼   ▼
                   ┌───────────────────┐
                   │ 3. Validaciones   │
                   └───────────────────┘
                      • Leer argv
                      • Solo enteros
                      • Sin duplicados
                      • Error\n y exit
                      • Crear stack A
                             │
                             ▼
                   ┌───────────────────┐
                   │ 4. Operaciones    │
                   └───────────────────┘
                      • sa, sb, ss
                      • pa, pb
                      • ra, rb, rr
                      • rra, rrb, rrr
                      • Probar una a una
                             │
        ┌────────────────────┴───────────────────┐
        │                                        │
┌───────────────┐                        ┌───────────────────┐
│ 5. Casos      │                        │ 6. Algoritmos     │
│ pequeños      │                        │ grandes           │
└───────────────┘                        └───────────────────┘
• 2 elementos                          • Radix sort
• 3 elementos                          • LIS + chunks
• 5 elementos                          • Optimización pasos
        │                                        │
        └────────────────────┐   ┌───────────────┘
                             ▼   ▼
                   ┌───────────────────┐
                   │ 7. Optimización   │
                   └───────────────────┘
                      • Fusionar rr, rrr
                      • Reducir pasos
                      • Mejorar casos
                             │
                             ▼
                   ┌───────────────────┐
                   │ 8. Testeo         │
                   └───────────────────┘
                      • Positivos / negativos
                      • Orden inverso
                      • Aleatorios
                      • Contar movimientos
                             │
                             ▼
                   ┌───────────────────┐
                   │ 9. Presentación   │
                   └───────────────────┘
                      • Norminette OK
                      • Sin fugas
                      • Explicar algoritmo

📌 1. ¿Qué es push_swap?

Te dan una lista de números desordenados en stack A.

Tienes un stack B vacío.

Solo puedes usar un conjunto limitado de instrucciones (sa, sb, pa, pb, ra, rra, etc.).

Tu objetivo: ordenar stack A en el menor número de movimientos posibles.



📌 2. Pasos para arrancar el proyecto

Antes de pensar en algoritmos, necesitas una base sólida:

Parseo de argumentos

Leer los números de argv.

Manejar errores (números duplicados, no numéricos, fuera de rango de int).

Guardarlos en una estructura (t_list de tu libft o tu propia struct de nodos).

Estructuras de datos

Representa tus stacks con listas enlazadas o arrays.

Recomendación: listas enlazadas dobles → fáciles para rotaciones y pop/push.

Implementar las operaciones

Implementa cada instrucción (sa, pb, ra, etc.).

Haz una función por operación, que además imprima el nombre de la operación al ejecutarla (ej. printf("sa\n")).

Asegúrate de que funcionan correctamente.

Pruebas básicas

Coge una lista pequeña (ej. 3–5 números).

Aplica manualmente tus operaciones para comprobar que funciona.



📌 3. Algoritmos principales de push_swap

Aquí es donde se diferencian los proyectos. Todos comparten el parseo, errores y operaciones, lo que cambia es cómo eliges qué operación aplicar para ordenar.

Hardcode para casos pequeños

Con 2 → swap si hace falta.

Con 3 → hay solo 5 casos posibles → puedes hacer un if/else.

Con 5 → pasas los dos más pequeños a B, ordenas los 3 de A, y los traes de vuelta.

⚡ Es obligatorio, porque la corrección de 42 te evalúa con números muy pequeños también.

Insertion sort / algoritmo ingenuo

Vas pasando elementos de A a B y recolocándolos.

Muy sencillo de implementar, pero genera muchos movimientos.

Malo en puntuación, pero útil para empezar.

Radix sort (binario)

Convierte cada número a un índice (normalización: el menor es 0, el siguiente 1, etc.).

Recorres bit a bit (del menos significativo al más significativo).

Los números con el bit en 0 van a B, luego los vuelves a A.

Repite por cada bit → termina ordenado.

👍 Fácil de implementar, el más común en 42, siempre ordena bien, pero no es el más eficiente en movimientos.

Algoritmos avanzados (Greedy / Chunking)

"Chunks": divides en grupos (ej. de 20–50 números), los pasas a B y luego los reinsertas en orden.

Greedy con "longest increasing subsequence" (LIS): mantienes en A la subsecuencia creciente más larga y mueves el resto a B. Luego reinsertas optimizando rotaciones.

⚡ Mucho más eficiente, pero bastante más complejo.

Normalmente se hace si quieres ir a por la nota máxima.



📌 4. ¿Cuál elegir?

Depende del tiempo que tengas:

Poco tiempo → Radix sort (rápido de programar, fácil de entender).

Tiempo medio → Radix + Hardcode para 3 y 5 → suficiente para pasar bien.

Mucho tiempo y quieres nota top → LIS o Chunking → optimización avanzada.



📌 5. Roadmap recomendado para ti

Parsear y validar argumentos.

Montar stacks.

Implementar TODAS las operaciones.

Hardcode para 2, 3 y 5.

Implementar Radix sort.

Testear con el checker de 42.

(Opcional) Mejorar con chunks o LIS.