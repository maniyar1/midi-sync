project('midi-sync', 'cpp')
cc = meson.get_compiler('cpp')
executable('midisync', ['main.cpp', 'midi.cpp'], dependencies:[cc.find_library('fltk'), cc.find_library('rtmidi')])
