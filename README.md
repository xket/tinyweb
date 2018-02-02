# tinyweb version01
a tiny web server of multithreading.
This is a Multithreading Tiny Web Server which derived from
UNP and CS:APP,only supports GET method.In this programming pattern,
threads is pre-generated.

1.compile commands:
 gcc -pthread -o a.out prethreaded_server.c pthread01.c request_process.c tinyweb.c wrappthread.c 

2.and run in : ./a.out  <#port>  <#threads>

3.connect to host through browser: host-IP:port

4.or use telnet commandline: a): telnet host-IP port , b): GET / HTTP/1.0
