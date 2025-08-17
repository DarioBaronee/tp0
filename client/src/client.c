#include "client.h"

int main(void)
{
	/*---------------------------------------------------PARTE 2-------------------------------------------------------------*/

	int conexion;
	char* ip;
	char* puerto;
	char* valor;

	t_log* logger;
	t_config* config;

	/* ---------------- LOGGING ---------------- */

	logger = iniciar_logger();

	// Usando el logger creado previamente
	// Escribi: "Hola! Soy un log"
	log_info(logger, "Hola! Soy un log");


	/* ---------------- ARCHIVOS DE CONFIGURACION ---------------- */

	config = iniciar_config();

	// Usando el config creado previamente, leemos los valores del config y los 
	// dejamos en las variables 'ip', 'puerto' y 'valor'
	ip = config_get_string_value(config, "IP");
	puerto = config_get_string_value(config, "PUERTO");
	valor = config_get_string_value(config, "CLAVE");

	// Loggeamos el valor de config
	log_info(logger, "El valor de config es: %s", valor);


	/* ---------------- LEER DE CONSOLA ---------------- */

	leer_consola(logger);

	/*---------------------------------------------------PARTE 3-------------------------------------------------------------*/

	// ADVERTENCIA: Antes de continuar, tenemos que asegurarnos que el servidor esté corriendo para poder conectarnos a él

	// Creamos una conexión hacia el servidor
	conexion = crear_conexion(ip, puerto);

	// Enviamos al servidor el valor de CLAVE como mensaje
	enviar_mensaje(valor, conexion);

	// Armamos y enviamos el paquete
	paquete(conexion);

	terminar_programa(conexion, logger, config);

	/*---------------------------------------------------PARTE 5-------------------------------------------------------------*/
	// Proximamente
	log_destroy(logger);
	config_destroy(config);
}

t_log* iniciar_logger(void)
{
	/*
	Loguee en el archivo "tp0.log"
    Muestre los logs por pantalla (y no solo los escriba en el archivo)
    Muestre solo los logs a partir del nivel "info".
	*/
	t_log* nuevo_logger = log_create ("tp0.log", "TP0_LOGGER", true, LOG_LEVEL_INFO);
	if(nuevo_logger == NULL) {
		fprintf(stderr, "Error al crear el logger\n");
		abort(); // Termina el programa si no se pudo crear el logger
	}

	return nuevo_logger;
}


t_config* iniciar_config(void)
{
	t_config* nuevo_config = config_create("cliente.config");
	if(nuevo_config == NULL) {
		fprintf(stderr, "No se pudo cargar el archivo de configuración cliente.config\n");
		abort(); // Termina el programa si no se pudo cargar la configuración
	}
	return nuevo_config;
}

void leer_consola(t_log* logger)
{
	char* leido = NULL;

	// Leemos y logueamos hasta recibir un string vacío
	while ((leido = readline("> ")) != NULL && leido[0] != '\0') {
		log_info(logger, "Leído de consola: %s", leido);
		free(leido); // Liberamos la memoria de la línea leída
	}
	if (leido != NULL) {
		free(leido); // Liberamos la memoria si la última línea fue vacía
	}

}

void paquete(int conexion)
{
	// Ahora toca lo divertido!
	char* leido;
	t_paquete* paquete;

	// Leemos y esta vez agregamos las lineas al paquete


	// ¡No te olvides de liberar las líneas y el paquete antes de regresar!
	
}

void terminar_programa(int conexion, t_log* logger, t_config* config)
{
	/* Y por ultimo, hay que liberar lo que utilizamos (conexion, log y config) 
	  con las funciones de las commons y del TP mencionadas en el enunciado */
}
