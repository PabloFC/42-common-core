// https://medium.com/@oduwoledare/42-minitalk-explained-5b236adc2c24
//https://42-cursus.gitbook.io/guide/rank-02/minitalk
//https://www.codequoi.com/en/sending-and-intercepting-a-signal-in-c/
//https://github.com/STC71/42_malaga/blob/main/minitalk/server.c




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