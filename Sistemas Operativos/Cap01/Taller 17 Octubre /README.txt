Cliente: El cliente en este código envía mensajes al servidor a través de un archivo FIFO (tubería con nombre). 
Primero abre el archivo FIFO y luego, en un bucle infinito, le pide al usuario que escriba un mensaje. 
Este mensaje se envía al servidor utilizando la función write(). Después de enviar el mensaje, el cliente espera una respuesta del servidor, 
la cual es leída con la función read() y mostrada en pantalla. Si el usuario escribe "end", el cliente envía ese mensaje al servidor, 
cierra el archivo FIFO, y termina la ejecución del programa.

Servidor: El servidor espera recibir mensajes del cliente a través del archivo FIFO. Una vez que recibe un mensaje,
lo lee y lo imprime en pantalla. Si el mensaje recibido no es "end", el servidor invierte el contenido del mensaje 
utilizando la función reverse_string y luego envía la cadena invertida de vuelta al cliente. Si el mensaje recibido 
es "end", el servidor cierra el archivo FIFO y termina su ejecución. El servidor está diseñado para seguir funcionando 
de forma indefinida hasta que reciba la palabra "end".
