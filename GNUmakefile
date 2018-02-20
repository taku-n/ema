ema.ex5: ema.mq5 ema.dll
	-metaeditor64.exe /compile:ema.mq5 /log:log.log
	cat log.log
	rm log.log

ema.dll: ema.c
	clang -Wall -shared -o ema.dll ema.c
