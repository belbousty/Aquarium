CC=gcc
PATH_TO_FX=/usr/share/openjfx/lib
BUILD_DIR=Build
CFALGS=-Wall 

all: utils test client

utils: logger_server
	$(CC) $(CFLAGS) -c Server/utils.c -o $(BUILD_DIR)/utils.o

test: utils
	$(CC) $(CFLAGS) -c Server/test.c -o $(BUILD_DIR)/test.o
	$(CC) $(CFLAGS) $(BUILD_DIR)/test.o $(BUILD_DIR)/utils.o $(BUILD_DIR)/logger_server.o -o $(BUILD_DIR)/test

server: utils logger_server
	$(CC) $(CFLAGS) -c Server/server.c -o $(BUILD_DIR)/server.o
	$(CC) $(CFLAGS) $(BUILD_DIR)/server.o $(BUILD_DIR)/utils.o $(BUILD_DIR)/logger_server.o -o $(BUILD_DIR)/server

client: 
	javac --module-path $(PATH_TO_FX) --add-modules javafx.controls,javafx.fxml -d $(BUILD_DIR) Client/Client.java 
	java  --module-path $(PATH_TO_FX) --add-modules javafx.controls,javafx.fxml -cp $(BUILD_DIR) Client

logger_server:
	$(CC) $(CFLAGS) -c Server/logger.c -o $(BUILD_DIR)/logger_server.o

clean:
	find Build/ \(-iname '*.class' -o -iname '*.o' \) -type f -delete
