#include "midi.h"
#include <chrono>

MidiController::MidiController() {
    midiInput = std::make_unique<RtMidiIn>();
    // Check available ports.
    unsigned int iPorts = midiInput->getPortCount();
    std::cout << iPorts << " input ports available!\n";
    midiInput->openPort(0);
    midiInput->setCallback(inputCallback, this);

    midiOutput = std::make_unique<RtMidiOut>();
    unsigned int oPorts = midiOutput->getPortCount();
    std::cout << oPorts << " output ports available!\n";
    midiOutput->openPort( 0 );
}

void MidiController::callback(double timeStamp, std::vector<unsigned char>* message) {
    std::cout << "Timestamp: " << timeStamp << " message: ";
    for (auto&& m : *message) {
        std::cout << +m << ' ';
    }
    std::cout << "\n";

    midiOutput->sendMessage(message);
}

void inputCallback(double timeStamp, std::vector<unsigned char>* message, void* userData) {
    ((MidiController *) userData)->callback(timeStamp, message);
}
