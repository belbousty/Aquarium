#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include "logger.h"

// Pointeur sur le fichier de log
static FILE* log_file = NULL;

void logger_init(char* filename) {
    log_file = fopen(filename, "a+");
    if (log_file == NULL) {
        printf("Erreur : impossible d'ouvrir le fichier de log\n");
        return;
    }
    // Se déplacer au début du fichier pour écrire en haut
    fseek(log_file, 0, SEEK_SET);
}

void logger_log(int level, const char* format, ...) {
    // Vérification du niveau de log
    if (level < DEBUG || level > ERROR) {
        printf("Erreur : niveau de log invalide\n");
        return;
    }

    // Vérification de l'initialisation du logger
    if (log_file == NULL) {
        printf("Erreur : le logger n'a pas été initialisé\n");
        return;
    }

    // Obtention de la date et de l'heure actuelles
    time_t raw_time;
    struct tm* time_info;
    time(&raw_time);
    time_info = localtime(&raw_time);
    char time_str[20];
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", time_info);

    // Écriture du message de log
    char level_str[10];
    char color_str[20];
    switch (level) {
        case DEBUG:
            sprintf(level_str, "DEBUG");
            break;
        case INFO:
            sprintf(level_str, "INFO");
            break;
        case WARNING:
            sprintf(level_str, "WARNING");
            break;
        case ERROR:
            sprintf(level_str, "ERROR");
            break;
    }

    fprintf(log_file, "[%s] %s%s ", level_str, color_str, time_str);

    va_list args;
    va_start(args, format);
    vfprintf(log_file, format, args);
    va_end(args);

    fprintf(log_file, "\n");
}

void logger_close() {
    if (log_file != NULL) {
        fclose(log_file);
    }
}