#pragma once
#include <string>

using std::string;

// La clase Gauge proporciona un sencillo instrumento al cual se le puede asignar un valor
// en forma de porcentaje (0-100) y permite ser dibujado en pantalla.
// No necesitas modificar esta clase para la realización de la prueba.

class Gauge
{
public:
    Gauge( const string& name, int x, int y );
    virtual ~Gauge();
    
    // Redibuja el instrumento en pantalla
    void Refresh();
    
    // Métodos para leer o cambiar el valor que muestra el instrumento
    void setValue( float value );
    float value();
    
private:
    const string m_name;    // Nombre del instrumento
    int m_x, m_y;           // Coordenadas en pantalla
    float m_value = 0.f;    // Valor actual
};