#include <iostream>
#include <string>

class Television {
public:
    void powerOn() {
        std::cout << "Television: on\n";
    }
    void powerOff() {
        std::cout << "Television: off\n";
    }
};

class SoundControl {
public:
    void adjustVolume(int volume) {
        std::cout << "Setting volume: " << volume << "\n";
    }
};

class HDMIInput {
public:
    void connectHDMI() {
        std::cout << "Connecting HDMI\n";
    }
};

class MovieSearcher {
public:
    void searchMovie(const std::string& movie) {
        std::cout << "Searching for movie: " << movie << "\n";
    }
};

class MovieWatchFacade {
public:
    MovieWatchFacade(Television& tv, SoundControl& sound, HDMIInput& hdmi, MovieSearcher& movieSearcher)
        : television(tv), soundControl(sound), hdmiInput(hdmi), movieSearcher(movieSearcher) { }

    void playMovie(const std::string& movie) {
        television.powerOn();
        hdmiInput.connectHDMI();
        soundControl.adjustVolume(50);
        movieSearcher.searchMovie(movie);
        std::cout << "Movie " << movie << " is ready to watch\n";
    }

private:
    Television& television;
    SoundControl& soundControl;
    HDMIInput& hdmiInput;
    MovieSearcher& movieSearcher;
};

int main() {
    Television tv;
    SoundControl soundControl;
    HDMIInput hdmiInput;
    MovieSearcher movieSearcher;

    MovieWatchFacade movieFacade(tv, soundControl, hdmiInput, movieSearcher);

    movieFacade.playMovie("Pearl Harbor");

    return 0;
}
