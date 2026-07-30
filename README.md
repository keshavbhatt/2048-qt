# 2048-Qt
 Web based Popular 2048 game app implemented in Qt 6, uses QtWebEngine.


 ## How to build

Requirements: CMake >= 3.21, Ninja, Qt 6.2+ with the WebEngine module.

```bash
git clone https://github.com/keshavbhatt/2048-qt.git
cd 2048-qt
cmake --preset release
cmake --build build/release
./build/release/2048-qt
```

To install:

```bash
cmake --install build/release
```

Alternatively open the project in Qt Creator (it picks up `CMakeLists.txt` and the presets directly).

## Screenshots (could be old)
![MainWindow 2048 qt by Keshav Bhatt](https://github.com/keshavbhatt/2048-qt/blob/master/images/main_window.PNG?raw=true)
![About dialog 2048 qt by Keshav Bhatt](https://github.com/keshavbhatt/2048-qt/blob/master/images/about_dialog.PNG?raw=true)
