all:
	mkdir -p src 
	gcc -static -o src/init init.c
	gcc -static -o src/ls ls.c
	gcc -static -o src/helloworld helloworld.c
	cd vim73; env CFLAGS="-O2" LDFLAGS="-static" ./configure --prefix=/usr/local --disable-nls --without-x --disable-gui --disable-gpm --with-features=big ; make ; make install; cp src/vim ../src/vim
	cp -r tmp src
	cd src; find . -print0 | cpio --null -ov --format=newc | gzip -9 > ../test.cpio.gz
	cp test.cpio.gz /boot/test.cpio.gz

clean:
	rm -r src
	
	

