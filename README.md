# CheckEng
Checker English


#Dependecies
* Qt 5.15
* nsis

#How to create
* cd checkeng folder
* mkdir build && cd build
    cmake ..
    cmake --build . --config Release
* run in bin folder
    windeployqt --multimedia --plugindir plugins checkeng.exe
* run in install folder
    makensis install.nsi
