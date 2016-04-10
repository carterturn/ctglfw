CPP=g++

TEXTBOX=cttextbox.cpp cttextbox.h

build: $(TEXTBOX)
	$(CPP) -c -fPIC $(TEXTBOX) --std=c++11 -lftgl -I/usr/include/freetype2
	$(CPP) -shared -Wl,-soname,libctglfw.so -o libctglfw.so *.o
install:
	cp -f libctglfw.so /usr/lib/
	[ -d /usr/include/ctglfw ] || mkdir /usr/include/ctglfw
	cp -f cttextbox.h /usr/include/ctglfw/
	cp -f font.ttf /etc/ctfont.ttf
uninstall:
	rm -f /usr/lib/libctglfw.so
	rm -f /usr/include/ctglfw/cttextbox.h
	rm -f /etc/ctfont.ttf
	[ -d /usr/include/ctglfw ] && rmdir /usr/include/ctglfw
clean:
	for file in $$(ls *.o); do rm $$file; done
	for file in $$(ls *.so); do rm $$file; done
	for file in $$(ls *.gch); do rm $$file; done
