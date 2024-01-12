CC=gcc
CFLAGS=-I.

sysinfo_api: main.o server.o http_parser.o router.o system_info.o
	$(CC) -o sysinfo_api main.o server.o http_parser.o router.o system_info.o

main.o: src/main.c
	$(CC) -c src/main.c

server.o: src/server.c src/server.h
	$(CC) -c src/server.c

http_parser.o: src/http_parser.c src/http_parser.h
	$(CC) -c src/http_parser.c

router.o: src/router.c src/router.h
	$(CC) -c src/router.c

system_info.o: src/system_info.c src/system_info.h
	$(CC) -c src/system_info.c

install:
	rm -rf /opt/sysinfo_api
	cp -rf ../sysinfo-api /opt/
	cp -rfu init.d/sysinfo-api.service /etc/systemd/system/
	systemctl daemon-reload
	systemctl enable sysinfo-api.service
	systemctl start sysinfo-api.service
	systemctl restart sysinfo-api.service

clean:
	rm -f *.o sysinfo_api
