/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <hmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:37:20 by hmolina           #+#    #+#             */
/*   Updated: 2025/07/21 23:20:05 by hmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int pid, int sig)
{
	if (kill(pid, sig) == -1)
	{
		ft_putstr_fd("Error: No se puedo enviar la señal\n", 2);
		exit(EXIT_FAILURE);
	}
	usleep(100);
}

void	send_char(int pid, char c)
{
	int	bit;
	int	i;

	i = 7;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		if (bit == 0)
			send_signal(pid, SIGUSR1);
		else
			send_signal(pid, SIGUSR2);
		i--;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	if (ac != 3)
	{
		ft_putstr_fd("Error: ./client [PID del servidor] [mensaje]\n", 2);
		return (1);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0)
	{
		ft_putstr_fd("Error: PID incorrecto\n", 2);
		return (1);
	}
	i = 0;
	while (av[2][i])
	{
		send_char(pid, av[2][i]);
		i++;
	}
	send_char(pid, '\0');
	return (0);
}

/*
El cliente es el emisor del mensaje, que funciona siendo ejecutado, añadiendo el
PID + el mensaje
Si los argumentos no son 2, da error mostrando lo que necesita para funcionar
El av[1] convierte el PID de texto a numero 
Si el PID es invalido, da PID error
Mientras haya letras en el mensaje, envia cada letra y por ultimo envia '\0'

send_char envia un caracter convirtiendolo a bits
EJEMPLO DETALLADO: Enviando 'A' (ASCII 65 = 01000001)

--	i = 7: bit = (01000001 >> 7) & 1 = 0
		Envía SIGUSR1 (0)
--	i = 6: bit = (01000001 >> 6) & 1 = 1
		Envía SIGUSR2 (1)
--	i = 5: bit = (01000001 >> 5) & 1 = 0
		Envía SIGUSR1 (0)
--	i = 4: bit = (01000001 >> 4) & 1 = 0
		Envía SIGUSR1 (0)
--	i = 3: bit = (01000001 >> 3) & 1 = 0
		Envía SIGUSR1 (0)
--	i = 2: bit = (01000001 >> 2) & 1 = 0
		Envía SIGUSR1 (0)
--	i = 1: bit = (01000001 >> 1) & 1 = 0
		Envía SIGUSR1 (0)
--	i = 0: bit = (01000001 >> 0) & 1 = 1
		Envía SIGUSR2 (1)
Resultado: Envía: 0-1-0-0-0-0-0-1 (¡la 'A' en binario!)

send_signal envia una señal
verifica si se pudo enviar, si no, muestra error
si se pudo enviar espera 100 microsegundos para no saturar al servidor

EJEMPLO enviando "HOLA"
CLIENTE:
--Envía 'H' (72 = 01001000):
	SIGUSR1, SIGUSR2, SIGUSR1, SIGUSR1, SIGUSR2, SIGUSR1, SIGUSR1, SIGUSR1
--Envía 'O' (79 = 01001111):
	SIGUSR1, SIGUSR2, SIGUSR1, SIGUSR1, SIGUSR2, SIGUSR2, SIGUSR2, SIGUSR2
--Envía 'L' (76 = 01001100):
	SIGUSR1, SIGUSR2, SIGUSR1, SIGUSR1, SIGUSR2, SIGUSR2, SIGUSR1, SIGUSR1
--Envía 'A' (65 = 01000001):
	SIGUSR1, SIGUSR2, SIGUSR1, SIGUSR1, SIGUSR1, SIGUSR1, SIGUSR1, SIGUSR2
--Envía '\0' (fin):
	SIGUSR1, SIGUSR1, SIGUSR1, SIGUSR1, SIGUSR1, SIGUSR1, SIGUSR1, SIGUSR1

SERVIDOR:
--Recibe 8 señales → 'H' → Guarda en buffer[0]
--Recibe 8 señales → 'O' → Guarda en buffer[1]
--Recibe 8 señales → 'L' → Guarda en buffer[2]
--Recibe 8 señales → 'A' → Guarda en buffer[3]
--Recibe 8 señales → '\0' → ¡IMPRIME "HOLA"!

RESUMEN
1	Servidor: "Estoy escuchando en el PID 12345"
2	Cliente: "Voy a enviar HOLA al PID 12345"
3	Cliente convierte: H→01001000, O→01001111, L→01001100, A→01000001
4	Cliente envía: 32 señales (4 letras × 8 bits + 8 bits del '\0')
5	Servidor recibe: Las 32 señales, las convierte de vuelta a letras
6	Servidor imprime: "HOLA"
*/