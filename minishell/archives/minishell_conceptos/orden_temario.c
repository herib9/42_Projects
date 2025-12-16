📚 Temario recomendado de conceptos

1. Conceptos básicos de procesos

Proceso padre e hijo: entender qué es un proceso y cómo se crean procesos hijos.

Fork: cómo se crea un proceso hijo y la diferencia entre padre e hijo.

Waitpid() y control de procesos: cómo la shell espera a que los hijos terminen.

Señales: qué son y cómo afectan a procesos (ej. Ctrl+C, Ctrl+Z).


2. Entrada y salida de datos

stdin, stdout, stderr: qué son los flujos de entrada/salida estándar.

Redirecciones básicas (>, <): enviar o recibir datos de archivos.


3. Pipes y herencia de procesos

Pipes: cómo conectar stdout de un proceso con stdin de otro.

Heredoc: cómo pasar texto directamente desde la shell a un proceso.

Flujo de datos entre procesos: combinar pipes y heredocs.


4. Comandos y ejecución

Comandos externos: cómo la shell ejecuta programas que no son builtins.

Exec(): cómo un proceso hijo reemplaza su memoria con un programa externo.

Builtins: comandos internos de la shell que afectan su propio estado.


5. Bash y shells

Qué es Bash: función de la shell, intérprete de comandos y scripting.

Cómo Bash ejecuta comandos: diferencia entre builtins y externos, manejo de pipes y heredocs.


6. Integración práctica

Combinación de fork + pipes + heredoc + builtins: entender cómo se integran todos los conceptos en Minishell.

Flujo completo de ejecución:

Usuario escribe comando → shell analiza → decide builtin o externo → redirecciones y pipes → ejecución → espera a hijos → prompt listo para siguiente comando.