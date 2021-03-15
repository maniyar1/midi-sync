#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>

#include "midi.h"

#include <iostream>
#include <memory>


std::unique_ptr<MidiController> midiController;
void startServerCallback(Fl_Widget* w, void* data) {
    // TODO: Start the server here!
    std::cout << "Starting server...\n";
    midiController = std::make_unique<MidiController>();
}

void connectCallback(Fl_Widget* w, void* data) {
    // TODO: Connect here
    std::cout << "Connecting...\n";
    Fl_Input* textInput = static_cast<Fl_Input*>(data);
    textInput->deactivate();
    char val[200]; // TODO Fix this
    textInput->value(val); 
    std::cout << "Address: " << val << "\n";
}

int main(int argc, char **argv) {
    Fl_Window window(300,180);

    Fl_Button startServerButton(10, 20,130,50,"Start server");
    startServerButton.callback(startServerCallback);

    
    Fl_Input connectAddressInput(300/2 - 65, 180/2 - 10,130, 20,"Address");

    Fl_Button connectButton(300-130-10, 20,130,50,"Connect");
    connectButton.callback(connectCallback, &connectAddressInput);



    window.end();
    window.show(argc, argv);
    while (Fl::wait()) {
    }
    return 0;
}

