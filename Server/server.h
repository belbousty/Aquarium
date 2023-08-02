#ifndef _SERVER_H
#define _SERVER_H

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
#include <errno.h>
/********* Déclaration des fonctions *********/

/**
 * @brief 
 * 
 * @param  ClntSock
 * @return NULL 
 */
void* ClientHandler(void *ClntSock);


/**
 * @brief 
 * 
 * @param buffer  
 */
void* ServerHandler(void *);


/**
 * @brief 
 * 
 * @param ServSock
 * @param NumPorts
 * @param ports
 * 
 */
int SocketsCreator(int *ServSock, char* port);



/**
 * @brief 
 * 
 * @param ClntSock
 * @param maxDescriptor
 * @param ServSock
 * @param NumPorts
 */
void threads_management(int maxDescriptor, int ServSock, fd_set SocketSet);


/**
 * @brief 
 * 
 * @param signal
 * 
 */
void handle_interrupt(int signal);
#endif