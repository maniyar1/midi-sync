#ifndef MIDISYNC_MIDI
#define MIDISYNC_MIDI
#include "rtmidi/RtMidi.h"
#include <memory>

void inputCallback(double timeStamp, std::vector<unsigned char>* message, void* userData);
class MidiController {
    public:
        MidiController();
        void callback(double timeStamp, std::vector<unsigned char>* message);
    private:
        RtMidiIn midiInput;
        RtMidiOut midiOutput;
};

#endif
