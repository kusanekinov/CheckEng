# CheckEng
Checker English program

#Dependecies
* Qt 5.15
* nsis
* cmake 3.16

#How to create
* cd checkeng folder
* mkdir build 
* cd build 
* cmake ..
* cmake --build . --config Release
* cd ../bin
* windeployqt --multimedia --plugindir plugins checkeng.exe
* cd ../install
* makensis install.nsi

#How to translate
* cd checkeng folder
* lupdate -recursive . -ts resources/langs/ru.ts
* open translate

