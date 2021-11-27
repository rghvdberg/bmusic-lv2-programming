# Programming LV2 Music Production Plugins From Scratch

files for the tutorials by BMusic (@sjaehn)  
[
https://github.com/sjaehn/lv2tutorial](https://github.com/sjaehn/lv2tutorial)

- [x] 02 A Simple Amplifier (Part 1)
- [x] 04 A Simple Amplifier (Part 2)
  - compiled with : ```gcc -fvisibility=hidden -fPIC -Wl,-Bstatic -Wl,-Bdynamic -Wl,--as-needed -shared -pthread `pkg-config --cflags lv2` -lm `pkg-config --libs lv2` myAmp.c -o myAmp.so```
