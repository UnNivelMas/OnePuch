/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: betoio
 *
 * Created on 25 de julio de 2016, 08:12
 */

#include <cstdlib>
#include "Rendering/RenderManager.h"
#include "File/FileManager.h"
#include "Clases/Director/Director.h"

int main(int argc, char** argv) {
	FileManager::getInstance()->openPropertiesFile("OnePunch.properties");

    Director* dir = new Director();
    dir->start();
    return 0;
}

