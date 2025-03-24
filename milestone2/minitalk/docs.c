/////////////////////////RECURSOS///////////////////////////////////////////////

// https://www.geeksforgeeks.org/inter-process-communication-ipc/?ref=lbp
// https://www.man7.org/linux/man-pages/man7/signal.7.html
// https://en.wikipedia.org/wiki/Signal_(IPC)
// https://www.tutorialspoint.com/unix_system_calls/sigaction.htm
// https://people.kth.se/~johanmon/ose/assignments/signals.pdf
// https://pubs.opengroup.org/onlinepubs/007904875/functions/sigaction.html
// https://stackoverflow.com/questions/231912/what-is-the-difference-between-sigaction-and-signal
// https://www.ibm.com/docs/en/i/7.2?topic=ssw_ibm_i_72/apis/sigactn.htm
// http://manpagesfr.free.fr/man/man2/sigaction.2.html
// https://www.dummytextgenerator.com/#jump
// https://excerpts.numilog.com/books/9782212677607-extrait.pdf
// https://en.wikipedia.org/wiki/Thread_(computing)
// https://www.man7.org/linux/man-pages/man5/core.5.html
// https://www.geeksforgeeks.org/introduction-of-process-management/?ref=lbp
// https://en.wikipedia.org/wiki/Process_(computing)
// https://man7.org/linux/man-pages/man2/kill.2.html
// https://www.tutorialspoint.com/unix/unix-signals-traps.htm
// https://linuxhint.com/signal_handlers_c_programming_language/
// https://decimal.info/hex-to-decimal/1/how-to-convert-0X10-to-decimal.html
// https://www.rapidtables.com/convert/number/ascii-to-binary.html
// https://www.mkssoftware.com/docs/man5/siginfo_t.5.asp
// https://sites.uclouvain.be/SystInfo/notes/Theorie/Fichiers/fichiers-signaux.html
// https://www.tutorialspoint.com/unix/unix-processes.htm
// http://convertalot.com/bitwise_operators.html
// https://doc.lagout.org/LPI/LINUX%20Préparation%20à%20la%20certification%20LPIC-1%20%28LPI%20101%20LPI%20102%29%202ème%20Edition.pdf
// https://bitwisecmd.com
// https://jameshfisher.com/2017/01/13/c-sigaction/
// https://man7.org/linux/man-pages/man2/sigaction.2.html
// https://miro.com/app/board/uXjVOY6DYx8=/?invite_link_id=689990184473
// https://leeters.netlify.app/what-you-need-to-know-about-minitalk/
// https://www.youtube.com/watch?v=L3XuR-iRysU
// https://askcodez.com/gestion-du-signal-et-sigemptyset.html




//https://medium.com/@oduwoledare/42-minitalk-explained-5b236adc2c24
//https://42-cursus.gitbook.io/guide/rank-02/minitalk
//https://www.codequoi.com/en/sending-and-intercepting-a-signal-in-c/
//https://github.com/STC71/42_malaga/blob/main/minitalk/server.c
// https://github.com/Surfi89/minitalk/tree/main/src
//https://github.com/leogaudin/minitalk



/////////////////////////RESUMEN SEÑALES///////////////////////////////////////////////

//Las señales son mecanismos de comunicación entre procesos que permiten que el sistema operativo o un proceso envíe notificaciones a otros procesos sobre ciertos eventos, como errores o condiciones específicas (por ejemplo, la terminación de un proceso hijo).

// Concepto de señales
// En Unix, una señal es una notificación asíncrona que informa a un proceso de que ha ocurrido un evento. Cuando un proceso recibe una señal, puede reaccionar de diferentes formas, dependiendo de la acción asociada a esa señal. Algunas de las señales más comunes incluyen:

// SIGINT: Interrupción (generalmente al presionar Ctrl + C en la terminal).
// SIGKILL: Terminación forzada del proceso.
// SIGSEGV: Violación de segmento (segfault), ocurre cuando un proceso intenta acceder a memoria no permitida.
// Envío de señales
// Las señales se pueden enviar de diversas maneras:

// Usando el comando kill: Aunque su nombre puede inducir a confusión, kill no solo se usa para terminar procesos, sino que también puede enviar cualquier señal a un proceso. Por ejemplo, para enviar la señal de interrupción (SIGINT), se usa kill -SIGINT <PID>, donde <PID> es el ID del proceso destinatario.

// Llamadas al sistema en C: Los programas pueden enviar señales a otros procesos usando funciones como kill(), raise() o abort(), que permiten que un proceso envíe señales a otros procesos o a sí mismo.

// Interceptación de señales
// Los procesos pueden interceptar señales para modificar su comportamiento predeterminado. En lugar de permitir que el sistema operativo ejecute la acción predeterminada (como terminar el proceso), se puede definir un controlador de señales (signal handler) que especifique lo que debe hacer el proceso cuando reciba una señal determinada.

// El artículo resalta el uso de la función sigaction() para configurar estos controladores. Esta función permite asociar un manejador de señales personalizado, lo cual es más robusto que el método tradicional signal(), ya que ofrece un mayor control sobre el manejo de señales.

// La función sigaction()
// La función sigaction() se utiliza para configurar un manejador de señales específico para un proceso. El prototipo es el siguiente:

// c
// Copy
// int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
// signum: Es el número o nombre de la señal que se desea interceptar.
// act: Es una estructura que especifica el nuevo manejador de la señal.
// oldact: (opcional) Puede almacenar el manejador anterior de la señal.
// En la estructura sigaction, se puede definir el manejador (sa_handler) y opciones adicionales para controlar cómo el sistema maneja la señal.

// Bloqueo y desbloqueo de señales
// Aparte de interceptar señales, también es posible bloquearlas temporalmente usando sigprocmask(). Esta técnica es útil para evitar que un proceso maneje señales durante una operación crítica. Por ejemplo, si un proceso está realizando una secuencia de operaciones y no quiere ser interrumpido por una señal, puede bloquear ciertas señales hasta que termine la operación.

// Seguridad de los manejadores de señales
// El artículo también menciona la importancia de escribir manejadores de señales de manera segura. Algunas funciones no son seguras para ser utilizadas dentro de un manejador de señales, ya que el comportamiento podría ser impredecible si el proceso está interrumpido por una señal mientras ejecuta una función no segura. En general, se recomienda que los manejadores de señales realicen solo tareas simples, como la actualización de una variable global o el establecimiento de un flag, y eviten llamadas a funciones no seguras, como malloc() o printf().

// Resumen de los puntos clave:
// Las señales son mecanismos de comunicación entre procesos que permiten notificar eventos como errores o terminaciones.
// Las señales se pueden enviar con kill() o raise(), entre otras formas.
// Se puede interceptar señales usando el manejador de señales con sigaction() para personalizar la respuesta a las señales.
// Es importante tener en cuenta la seguridad de los manejadores de señales, evitando funciones no seguras dentro de estos.
// Bloquear señales es útil para evitar interrupciones durante operaciones críticas.
// Este artículo es útil para entender cómo trabajar con señales en C y cómo tener control sobre la ejecución de los programas mediante la interceptación y personalización de las señales recibidas.



///////// MAKEFILE WITH LIBFT //////////


// # CC = cc
// # CFLAGS = -Wall -Wextra -Werror
// # CLIENT_SRCS = client.c
// # SERVER_SRCS = server.c
// # LIBFT_PATH = libft
// # LIBFT_ARCHIVE = $(LIBFT_PATH)/libft.a
// # CLIENT_NAME = client
// # SERVER_NAME = server

// # all: $(CLIENT_NAME) $(SERVER_NAME)

// # $(CLIENT_NAME): $(CLIENT_SRCS) $(LIBFT_ARCHIVE)
// # 	$(CC) $(CFLAGS) -o $@ $(CLIENT_SRCS) -L$(LIBFT_PATH) -lft

// # $(SERVER_NAME): $(SERVER_SRCS) $(LIBFT_ARCHIVE)
// # 	$(CC) $(CFLAGS) -o $@ $(SERVER_SRCS) -L$(LIBFT_PATH) -lft

// # $(LIBFT_ARCHIVE):
// # 	$(MAKE) -C $(LIBFT_PATH)

// # clean:
// # 	$(MAKE) -C $(LIBFT_PATH) clean

// # fclean: clean
// # 	$(MAKE) -C $(LIBFT_PATH) fclean
// # 	rm -f $(CLIENT_NAME) $(SERVER_NAME)

// # re: fclean all

// # .PHONY: all clean fclean re


///////// MAKEFILE WITHOUT LIBFT //////////

// CC = cc
// CFLAGS = -Wall -Wextra -Werror
// CLIENT_SRCS = client.c
// SERVER_SRCS = server.c
// CLIENT_NAME = client
// SERVER_NAME = server

// all: $(CLIENT_NAME) $(SERVER_NAME)

// $(CLIENT_NAME): $(CLIENT_SRCS)
// 	$(CC) $(CFLAGS) -o $@ $(CLIENT_SRCS)

// $(SERVER_NAME): $(SERVER_SRCS)
// 	$(CC) $(CFLAGS) -o $@ $(SERVER_SRCS)

// clean:
// 	rm -f $(CLIENT_NAME) $(SERVER_NAME)

// fclean: clean

// re: fclean all

// .PHONY: all clean fclean re
