# Programming LV2 Music Production Plugins From Scratch

files for the tutorials by BMusic (@sjaehn)  
[
https://github.com/sjaehn/lv2tutorial](https://github.com/sjaehn/lv2tutorial)

- [x] 02 A Simple Amplifier (Part 1)
- [x] 04 A Simple Amplifier (Part 2)
  - compiled with : ```gcc -fvisibility=hidden -fPIC -Wl,-Bstatic -Wl,-Bdynamic -Wl,--as-needed -shared -pthread `pkg-config --cflags lv2` -lm `pkg-config --libs lv2` myAmp.c -o myAmp.so```
- [x] 05 A Sound Generator in C++
  - compiled with : ```g++ -fvisibility=hidden -fPIC -Wl,-Bstatic -Wl,-Bdynamic -Wl,--as-needed -shared -pthread `pkg-config --cflags lv2` -lm `pkg-config --libs lv2` myTestTone.cpp -o myTestTone.so```
- [ ] 07 - The Simplest MIDI Synth (Part 1)
- [ ] 08 - The Simplest MIDI Synth (Part 2)
- [ ] 09 - Waveform Synth In C++ 11
  