// Este es el programa principal. Lee detenidamente el enunciado de la prueba para saber
// qué cambios debes realizar aquí.
// Algunas funciones pertenecen a la librería ncurses. No te preocupes si no las conoces,
// la mayoría no necesitas cambiarlas. Si necesitas usar alguna se indicará en los comentarios.

#include "Gauge.h"
#include "Simulator.h"
#include <curses.h>
#include <unistd.h>

int main()
{
    // Inicialización de ncurses	
	initscr();
	start_color();
    cbreak();
    noecho();
    curs_set( 0 );
    nodelay( stdscr, TRUE );
	keypad( stdscr, TRUE );

	// Inicialización del simulador
	Simulator* simulator = Simulator::GetInstance();
	
	// Inicialización de instrumentos
	Gauge* gTorque = new Gauge( "Torque", 5, 3 );
	Gauge* gRPM = new Gauge( "RPM", 5, 6 );
	Gauge* gITT = new Gauge( "ITT", 5, 9 );
	
	// Bucle principal
    int tecla;
	while( (tecla = getch()) != 'q' )
	{
		// Leemos el teclado
	    switch( tecla ) {	
	        case '1':
	       		simulator->StartEngine1();
				break;
			case '2':
				simulator->StopEngine1();
				break;
			case '3':
				break;
			case '4':
				break;
		}
		
		// Actualizamos el estado del simulador
		simulator->Update();
		
		// Asignamos los valores actualizados a los instrumentos
		gTorque->setValue( simulator->torque1() );
		gRPM->setValue( simulator->rpm1() );
		gITT->setValue( simulator->itt1() );
		
		// Borramos la pantalla y redibujamos todo
		erase();
		
		mvprintw( 0, 20, "ENGINE 1" );	// mvprintw escribe un texto en unas coordenadas (y,x). Permite formato al estilo de printf()
		gTorque->Refresh();
		gRPM->Refresh();
		gITT->Refresh();

		// LINES es la altura actual de la pantalla en líneas de texto
		mvprintw( LINES - 3, 0, "1 = Arrancar motor 1		2 = Parar motor 1" );
		mvprintw( LINES - 2, 0, "3 = Arrancar motor 2		4 = Parar motor 2" );
		mvprintw( LINES - 1, 0, "Q = Salir" );

		refresh();
		
		// Detenemos el programa 1 ms para no saturar la CPU
		usleep( 1000 );
	}
	
	// Desinicialización de instrumentos
	delete gTorque;
	delete gRPM;
	delete gITT;
	
	// Desinicialización de ncurses
	endwin();
}
