#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>
#include <vector>

struct Setting {
    Setting(std::string name, void *value, bool isString) : name(name), value(value),
                                                            isString(isString) {}

    std::string name;
    void *value;
    bool isString;
};

class Settings {
public:
    static void add(std::vector<Setting> platformSettings);

    static bool load(const std::string &filename = "files/emudees.ini");

    static bool save();

    static bool getDirectBoot() { return directBoot; }

    static int getFpsLimiter() { return fpsLimiter; }

    static int getThreaded2D() { return threaded2D; }

    static int getThreaded3D() { return threaded3D; }

    static int getHighRes3D() { return highRes3D; }

    static std::string getBios9Path() { return bios9Path; }

    static std::string getBios7Path() { return bios7Path; }

    static std::string getFirmwarePath() { return firmwarePath; }

    static std::string getGbaBiosPath() { return gbaBiosPath; }

    static std::string getSdImagePath() { return sdImagePath; }

    static void setDirectBoot(int value) { directBoot = value; }

    static void setFpsLimiter(int value) { fpsLimiter = value; }

    static void setThreaded2D(bool value) { threaded2D = value; }

    static void setThreaded3D(int value) { threaded3D = value; }

    static void setHighRes3D(int value) { highRes3D = value; }

    static void setBios9Path(std::string value) { bios9Path = value; }

    static void setBios7Path(std::string value) { bios7Path = value; }

    static void setFirmwarePath(std::string value) { firmwarePath = value; }

    static void setGbaBiosPath(std::string value) { gbaBiosPath = value; }

    static void setSdImagePath(std::string value) { sdImagePath = value; }

private:
    Settings() {} // Private to prevent instantiation

    static std::string filename;

    static bool directBoot;
    static int fpsLimiter;
    static bool threaded2D;
    static int threaded3D;
    static int highRes3D;
    static std::string bios9Path;
    static std::string bios7Path;
    static std::string firmwarePath;
    static std::string gbaBiosPath;
    static std::string sdImagePath;

    static std::vector<Setting> settings;
};

#endif // SETTINGS_H
