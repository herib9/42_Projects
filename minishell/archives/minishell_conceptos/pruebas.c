#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>     // getcwd(), gethostname(), getlogin()
#include <limits.h>     // PATH_MAX
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

char *build_prompt(void)
{
    static char prompt[PATH_MAX + 128]; // espacio suficiente para prompt completo
    char cwd[PATH_MAX];
    char hostname[HOST_NAME_MAX + 1];
    char *user;

    // Obtener usuario
    user = getlogin();
    if (!user)
        user = "user";

    // Obtener host
    if (gethostname(hostname, sizeof(hostname)) != 0)
        strcpy(hostname, "host");

    // Obtener directorio actual
    if (!getcwd(cwd, sizeof(cwd)))
        strcpy(cwd, "~");

    // Construir prompt con colores:
    // Usuario en azul, host en cian, cwd en verde, símbolo $ en amarillo
    snprintf(prompt, sizeof(prompt), "\033[1;34m%s\033[0m@\033[1;36m%s\033[0m:\033[1;32m%s\033[0m \033[1;33m$\033[0m ",
             user, hostname, cwd);

    return prompt;
}

int main(void)
{
    char *input;

    while (1)
    {
        // Construir prompt dinámicamente
        input = readline(build_prompt());

        // Ctrl+D para salir
        if (!input)
            break;

        // Guardar comando en historial si no está vacío
        if (*input)
            add_history(input);

        // Aquí procesarías el comando
        printf("Comando recibido: %s\n", input);

        free(input);
    }

    printf("\nSaliendo de Minishell...\n");
    return 0;
}
