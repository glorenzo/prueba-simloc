#include "Gauge.h"
#include <curses.h>
#include <cstdlib>
#include <iostream>

#define GAUGESIZE 20

Gauge::Gauge( const string& name, int x, int y )
    : m_name(name), m_x(x), m_y(y)
{
}

Gauge::~Gauge()
{
}

// Refresh() redibuja el instrumento en pantalla mediante ncurses.
// No te preocupes si no entiendes este código, no necesitas modificarlo.
void Gauge::Refresh()
{
    // Etiqueta
    mvprintw( m_y, m_x, "%10s", m_name.c_str() );
    
    // Caja
    mvaddch( m_y - 1, m_x + 11, ACS_ULCORNER );
    hline( ACS_HLINE, GAUGESIZE );
    mvaddch( m_y - 1, m_x + 11 + GAUGESIZE + 1, ACS_URCORNER );
    mvaddch( m_y, m_x + 11, ACS_VLINE );
    mvaddch( m_y, m_x + 11 + GAUGESIZE + 1, ACS_VLINE );
    mvaddch( m_y + 1, m_x + 11, ACS_LLCORNER );
    hline( ACS_HLINE, GAUGESIZE );
    mvaddch( m_y + 1, m_x + 11 + GAUGESIZE + 1, ACS_LRCORNER );
    
    // Barra
    int longitud = static_cast<int>( GAUGESIZE * m_value / 100.f );
    longitud = std::max( std::min( longitud, GAUGESIZE ), 0 );
    mvhline( m_y, m_x + 12, ACS_BOARD, longitud );
    
    // Indicador numérico del valor
    mvprintw( m_y, m_x + 11 + GAUGESIZE + 3, "%6.2f%%", m_value );
}

void Gauge::setValue( float value )
{
    m_value = value;
}

float Gauge::value()
{
    return m_value;
}