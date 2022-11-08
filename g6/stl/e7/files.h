#ifndef FILES_H_INCLUDED
#define FILES_H_INCLUDED

#include "empleado.h"

#include <fstream>
#include <vector>
#include <sstream>

void leer_empleados(const char* fname, std::vector<empleado>& v);
void guardar_empleados(const char* fname, const std::vector<empleado>& v);

#endif // FILES_H_INCLUDED
