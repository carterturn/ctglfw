CPP=g++

TEXTBOX=cttextbox.cpp cttextbox.h

build: $(TEXTBOX)
	$(CPP) -c -fPIC $(TEXTBOX) --std=c++11 -lftgl -I/usr/include/freetype2
	$(CPP) -shared -Wl,-soname,libctglfw.so -o libctglfw.so *.o
install:
	cp libctglfw.so /usr/lib/
	mkdir /usr/include/ctglfw
	cp cttextbox.h /usr/include/ctglfw/
uninstall:
	rm /usr/lib/libctglfw.so
	rm /usr/include/ctglfw/cttextbox.h
	rmdir /usr/include/ctglfw
clean:
	rm *.o *.so *.gch
