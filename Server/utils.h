#ifndef _UTILS_H
#define _UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/select.h>
#include <signal.h>
#include <regex.h>
#include <sys/mman.h>
#include "logger.h"
#include <time.h>
#include <stdlib.h>

/********* Déclaration des structures *********/

// Définition de la structure Coordinates
struct Coordinates
{
    int x;
    int y;
};
typedef struct Coordinates Coordinates;

// Définition de la structure Fish
struct Fish
{
    char name[50];
    int width;
    int height;
    char mobilityPattern[50];
    Coordinates coord;
    int mobile;
    int property;
};
typedef struct Fish Fish;






// Définition de la structure View
struct View
{
    char name[50];
    struct Coordinates coord;
    int width;
    int height;
    int num_fishes;
    int num_fishes_visitors;
    Fish *fishes;
    Fish fishes_visitors[50];
    int fishes_visitors_view[50];
    int socket;
};
typedef struct View View;

// Définition de la structure Aquarium
struct Aquarium
{
    char name[50];
    int dimensions[2];
    View *views;
    int num_views;
};
typedef struct Aquarium Aquarium;

/********* Déclaration des fonctions *********/

/**
 * @brief Parse a file and return an Aquarium structure
 *
 * @param AquariumName
 * @return Aquarium
 */
Aquarium *loadAquarium(char *AquariumName);

/**
 * @brief Display an aquarium
 *
 * @param aquarium
 */
void showAquarium(const Aquarium *aquarium);

/**
 * @brief Add a view to an aquarium
 *
 * @param a
 * @param name
 * @param x
 * @param y
 * @param width
 * @param height

 */
void addView(Aquarium *a, const char *name, int x, int y ,int width, int height);

/**
 * @brief Delete a view from an aquarium
 *
 * @param a
 * @param viewName
 */
void deleteView(Aquarium *a, char *viewName);

/**
 * @brief Save an aquarium to a file
 *
 * @param aquarium
 * @param aquariumName
 */
void saveAquarium(Aquarium *aquarium, char *aquariumName);

/**
 * @brief Add a fish to a view
 *
 * @param aquarium
 * @param client
 * @param name
 * @param x
 * @param y
 * @param weight
 * @param height
 * @param mobilityPattern
 */
char* addFish(Aquarium *a, int client, char *name, int x , int y, int height, int width, char *mobilityPattern);

/**
 * @brief Delete a fish from a view
 *
 * @param aquarium
 * @param client
 * @param fishName
 */
int deleteFish(Aquarium *a, int client, char *fishName);

/**
 * @brief authentication
 *
 * @param input
 * @param aquarium
 * @param socket
 * @return char*
 */

char *authenticate(char *input, Aquarium *aquarium, int socket);


/**
 * @brief remove fish from view and client socket when client disconnect
 *
 * @param aquarium
 * @param client_socket
 * 
 */

void disconnect(Aquarium *aquarium, int client_socket);


/**
 * @brief verif command with regex
 *
 * @param buffer
 * @param pattern
 * @return int
 **/

int verifRegex(char *buffer, char *pattern);


/**
 * @brief extracter with regex
 * 
 * @param buffer
 * @param pattern
 * @param num_params
 * 
 * @return char**
 
**/

char **extractStrings(char *buffer, char *pattern, int num_params);


/**
 * @brief extracter with regex
 * 
 * @param buffer
 * @param pattern
 * 
 * @return char*
 
**/

char *extractString(char *buffer, char *pattern);


/**
 * @brief return status of view for client 
 * 
 * @param aquarium
 * @param client
 * 
 * @return char*
*/

char *status(Aquarium *aquarium, int client);


/** 
 * @brief return response of ping
 * 
 * @param port
 * 
 * @return char*
*/

char *pong(char *port);


/**
 * @brief return response of startFish
 * 
 * @param aquarium
 * @param client
 * @param fishName
 * 
 * @return char*
 *
*/

char *startFish(Aquarium *aquarium, int client, char *fishName);

/**
 * @brief return response of getFishes
 * 
 * @return char*
 *
*/
char *getFishes(Aquarium *aquarium, int client);


/**
 *  @brief validate the mobility pattern
 * 
 * @return bool
 *  
*/
int isValidMobilityPattern(const char* mobilityPattern);



// /**
//  * @brief return position of fish
//  * 
//  * @param aquarium
//  * @param client
//  * 
//  * @return char* 
//  *  
// */
// char* ls(Aquarium *aquarium, int client);

/**
 * @brief return random positions
 * 
 * @param aquarium
 * 
 * @return int*
 * 
*/
int* RandomWayPoint(Aquarium *aquarium) ;
/**
 * @brief apply a given pathWay function
 * 
 * @return int*
*/


// // Définition d'un type de données pour l'utiliser dans les fonctions de pathWay
// typedef int* (*PathWayFunction) (aquarium*);

// typedef struct {
//     char* name;
//     PathWayFunction function;
// } PathWayEntry;

// // Table de hachage des fonctions de PathWay
// PathWayEntry pathWayTable[] = {
//     {"RandomPathWay", &RandomPathWay},
//     //{"HorizontalPathWay", &applyHorizontalPathWay},
// };
// const int PATH_WAY_TABLE_SIZE = sizeof(PathWayTable) / sizeof(PathWayEntry);



int* applyPathWay(Aquarium* aquarium, char* pathWay, View view);
/**
 * 
 * @brief search for a pathWay function by its name
 * 
 * @return PathWayFunction
 * 
*/
// PathWayFunction findPathWayFunction(char* name);

char *getFishesContinuously(Aquarium *aquarium, int client);
void *send_message_continuously(Aquarium *aquarium, int client);

#endif
