#include "settings.h"
#include "defines.h"

std::string Settings::filename = "files/emudees.ini";

bool Settings::directBoot = true;
int Settings::fpsLimiter = 1;
bool Settings::threaded2D = false;
int Settings::threaded3D = 2;
int Settings::highRes3D = 0;
std::string Settings::bios9Path = "files/core/bios9.bin";
std::string Settings::bios7Path = "files/core/bios7.bin";
std::string Settings::firmwarePath = "files/core/firmware.bin";
std::string Settings::gbaBiosPath = "files/core/gba_bios.bin";
std::string Settings::sdImagePath = "files/core/sd.img";

std::vector<Setting> Settings::settings =
        {
                Setting("directBoot", &directBoot, false),
                Setting("fpsLimiter", &fpsLimiter, false),
                Setting("threaded2D", &threaded2D, false),
                Setting("threaded3D", &threaded3D, false),
                Setting("highRes3D", &highRes3D, false),
                Setting("bios9Path", &bios9Path, true),
                Setting("bios7Path", &bios7Path, true),
                Setting("firmwarePath", &firmwarePath, true),
                Setting("gbaBiosPath", &gbaBiosPath, true),
                Setting("sdImagePath", &sdImagePath, true)
        };

void Settings::add(std::vector<Setting> platformSettings) {
    // Add additional platform settings to be loaded from the settings file
    settings.insert(settings.end(), platformSettings.begin(), platformSettings.end());
}

bool Settings::load(const std::string &file_name) {
    // Attempt to open the settings file
    // If the file can't be opened, the default values will be used
    Settings::filename = file_name;
    FILE *settingsFile = fopen(file_name.c_str(), "r");
    if (!settingsFile) return false;

    char data[1024];

    // Read each line of the settings file and load the values from them
    while (fgets(data, 1024, settingsFile) != nullptr) {
        std::string line = data;
        int split = line.find('=');
        std::string name = line.substr(0, split);

        for (auto &setting: settings) {
            if (name == setting.name) {
                std::string value = line.substr(split + 1, line.size() - split - 2);
                if (setting.isString)
                    *(std::string *) setting.value = value;
                else if (value[0] >= 0x30 && value[0] <= 0x39)
                    *(int *) setting.value = stoi(value);
                break;
            }
        }
    }

    fclose(settingsFile);
    return true;
}

bool Settings::save() {
    // Attempt to open the settings file
    FILE *settingsFile = fopen(filename.c_str(), "w");
    if (!settingsFile) return false;

    // Write each setting to the settings file
    for (auto &setting: settings) {
        std::string value = setting.isString ? *(std::string *) setting.value : std::to_string(
                *(int *) setting.value);
        fprintf(settingsFile, "%s=%s\n", setting.name.c_str(), value.c_str());
    }

    fclose(settingsFile);
    return true;
}
