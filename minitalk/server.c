/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <hmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:37:37 by hmolina           #+#    #+#             */
/*   Updated: 2025/07/21 23:15:06 by hmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	process_char(char add_char, char *buffer, int *buffer_position)
{
	if (add_char == '\0')
	{
		if (*buffer_position > 0)
		{
			buffer[*buffer_position] = '\0';
			write(1, buffer, *buffer_position);
			write(1, "\n", 1);
			*buffer_position = 0;
		}
	}
	else if (*buffer_position < 4095)
		buffer[(*buffer_position)++] = add_char;
}

void	handle_signal(int signum)
{
	static char	add_char = 0;
	static int	add_bit_count = 0;
	static char	buffer[4096] = {0};
	static int	buffer_position = 0;

	if (signum == SIGUSR1)
		add_char = add_char << 1;
	else if (signum == SIGUSR2)
		add_char = (add_char << 1) | 1;
	add_bit_count++;
	if (add_bit_count == 8)
	{
		process_char(add_char, buffer, &buffer_position);
		add_char = 0;
		add_bit_count = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	write(1, "WELCOME 2 The MINITALK HERIB9\n", 30);
	write(1, "\n", 1);
	write(1, "Your PID is: ", 13);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		pause();
	return (0);
}

/*
El servidor es el receptor, que imprime un mensaje de bienvenida. 
Imprime su PID para que el cliente sepa a donde tiene que enviar el mensaje.
Si le llega SIGUSR1 o SIGUSR2, llama a handle_signal y se queda esperando

handle_signal es el que recibe las señales en forma de bits 
char	add_char = 0;        // ← Carácter que estoy construyendo
int		add_bit_count = 0;   // ← Cuántos bits he recibido
char	buffer[4096] = {0};  // ← Donde guardo el mensaje completo
int		buffer_position = 0; // ← Posición en el buffer

Si la señal es SIGUSR1 añade un 0, si es SIGUSR2 añade un 1
Cuando tiene 8 bits (1 char), resetea add_char para el siguiente caracter
y resetea el contador de bits
EJEMPLO: Recibiendo la letra 'A' (01000001 en binario)

--Llega SIGUSR1: "Es un 0"
	add_char = 0 << 1 = 0 (añado 0)
	add_bit_count = 1
--Llega SIGUSR2: "Es un 1"
	add_char = 0 << 1 | 1 = 1 (añado 1)
	add_bit_count = 2
--Llega SIGUSR1: "Es un 0"
	add_char = 1 << 1 = 10 (muevo y añado 0)
	add_bit_count = 3
--Continúa así hasta...
	add_bit_count = 8
	add_char = 01000001 (la 'A' completa)

Llama a process_char, que es el encargado de procesar cada caracter
Si add_char ha terminado de procesar, mira si buffer_position es mayor a 0
si es asi, termina el string con '\0', imprime el mensaje + '\n' y resetea el
contador de buffer para el siguiente mensaje

Si no, si hay espacio en el buffer, guarda el caracter en el buffer

--Caso 1: Carácter normal (ej: 'A')
	Guarda 'A' en buffer[0]
	buffer_position pasa de 0 a 1
--Caso 2: Carácter normal (ej: 'B')
	Guarda 'B' en buffer[1]
	buffer_position pasa de 1 a 2
--Caso 3: Carácter fin '\0'
	¡IMPRIME TODO EL MENSAJE!
Resetea para el siguiente mensaje
*/