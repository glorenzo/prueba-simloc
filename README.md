Bienvenido a la prueba práctica de C++ de Simloc Research. Lee cuidadosamente este documento antes de empezar.

Esta prueba consiste en un pequeño ejercicio consistente en un programa al que hay que realizar algunos cambios. Encontrarás el enunciado más adelante en este mismo texto.

Dependiendo del resultado de esta prueba, puedes ser o no seleccionado para realizar una entrevista en la sede de nuestra empresa. En ambos casos contactaremos contigo y te informaremos. Si eres seleccionado, acordaremos fecha y hora para realizar la entrevista en la semana del día 7.

El plazo máximo para entregar el resultado de la prueba es el lunes 7 de septiembre a las 20:00 horas. Más adelante en este texto verás como realizar y entregar la prueba.

Estimo que el tiempo de realización de la prueba es de unas 2 horas.

## Entorno de desarrollo

Hay dos formas de realizar esta prueba:

* Si dispones de una máquina Linux con un compilador GCC, puedes realizar la prueba en tu propio ordenador de forma offline.
* También puedes utilizar el servicio **Cloud9**, que te proporciona un entorno de desarrollo completamente online.

### Instalación en tu propio sistema Linux

Si no dispones de un S.O. Linux con un compilador GCC y un entorno de programación adecuado, pasa a la siguiente sección.

Para obtener el código, necesitarás tener instalado el programa Git. Desde un terminal, accede a tu carpeta de trabajo y escribe:

    git clone https://github.com/glorenzo/prueba-simloc.git prueba-simloc

Git automáticamente descargará el proyecto en la carpeta `prueba-simloc`. Ya lo tienes todo listo para empezar. Para probar que todo funciona correctamente, escribe:
    cd prueba-simloc
    make
    ./prueba

El programa se ejecutará en el terminal y podrás ver cómo funciona. Pulsa Q para salir de él.

Puedes hacer tus propias modificaciones y compilar de nuevo el programa con `make`. Para limpiar los archivos de compilación intermedios (se guardan en la carpeta `build`), escribe `make clean`.

Lee más adelante para saber cómo empezar a hacer el ejercicio.

### Instalación en Cloud9

[Cloud9](http://c9.io) es un servicio que proporciona un entorno de desarrollo en la nube, incluso con acceso a una máquina virtual Linux que te permite hacer todas tus ediciones y pruebas sin salir del navegador. Esta es la opción más sencilla si no tienes Linux a mano para programar.

1. Entra en [Cloud9](http://c9.io) y crea una cuenta si no tienes ya una.
2. Crea un espacio de trabajo nuevo en Cloud9. Desde tu cuenta, pulsa _Create a new workspace_.
3. Introduce un nombre y una descripción para tu proyecto. Puedes hacerlo público si quieres, pero no es necesario (preferimos que nos mandes tu código directamente por email).
4. En el apartado _Clone from Git or Mercurial URL_, debes introducir lo siguiente:
        https://github.com/glorenzo/prueba-simloc.git
5. El apartado _Choose a template_ déjalo en _Custom_.
6. Finalmente, pulsa _Create workspace_ y ya tendrás tu espacio de trabajo listo con todo lo necesario.

Recuerda que tu espacio de trabajo se guarda automáticamente. Puedes cerrarlo y volver a él cuando quieras, incluso desde otra máquina, y aparecerá tal como lo dejaste.

En la zona inferior dispones de una ventana con un **terminal** que te permite ejecutar comandos. Para comprobar que todo funciona correctamente, escribe:
    make
    ./prueba

El programa comenzará a ejecutarse, pero la ventana de terminal por defecto es demasiado pequeña. Recomiendo maximizarla o arrastrarla a la barra de pestañas superior para que el programa se muestre correctamente.

Juega un poco con el programa para ver cómo funciona. Pulsa Q en cualquier momento para salir.

Puedes hacer tus propias modificaciones y compilar de nuevo el programa con `make`. Para limpiar los archivos de compilación intermedios (se guardan en la carpeta `build`), escribe `make clean`.

Si quieres aprender más sobre Cloud9, consulta la documentación disponible en http://docs.c9.io. También hay disponibles [tutoriales en vídeo](http://www.youtube.com/user/c9ide).

Lee más adelante para saber cómo empezar a hacer el ejercicio.

## Enunciado de la prueba

Necesitamos desarrollar un panel para un simulador de vuelo que muestre el estado de los dos motores de un avión ficticio.

El estado de cada motor consiste en 3 variables: **Torque**, **RPM** y **ITT**. Lo único que necesitas saber sobre ellas es que su valor puede variar entre 0 y 100 y te lo proporciona el simulador.

El simulador es un programa cerrado. No podemos acceder a su código ni modificarlo, tan sólo acceder a su API, que puedes ver en la cabecera `Simulator.h`.

La única interactividad que nos ofrece la API del simulador consiste en poder encender o apagar cada uno de los dos motores.

El cliente ha visto cómo funciona el programa que llevamos hecho hasta ahora y nos ha enviado la siguiente lista de observaciones:

* Nos gusta cómo ha quedado el panel de instrumentos del motor 1, pero necesitamos también ver los del motor 2.
* La secuencia de arranque del motor necesita algunos ajustes:
    1. El **torque** sube hasta el 5% y eso es correcto, pero debería tardar más tiempo en llegar a ese valor; aproximadamente el doble.
    2. Las **RPM** mostradas dan un pico hasta el 60% y eso no es correcto. Deberían simplemente subir suavemente hasta el 17%.
    3. La **ITT** tampoco es correcta. Debería tardar unos 15 segundos en subir al 60% y luego bajar rápidamente al 40%.
* Aparte de todo esto, el comportamiento del avión simulado es correcto.

Para satisfacer los puntos **1**, **2** y **3**, ya que no podemos modificar el simulador, deberemos _falsear_ los valores mostrados en pantalla para que se ajusten a lo que nos pide el cliente. No habrá problema con esto ya que según nos dicen el comportamiento del avión simulado es correcto, tan sólo necesita mostrar los valores correctos durante el arranque de cada motor.

## Notas para la realización de la prueba

El proyecto que te proporcionamos funciona completamente en modo texto. Para mostrar los gráficos en pantalla hemos usado la librería **ncurses**. No te preocupes si no la conoces: para realizar el ejercicio no necesitas ningún conocimiento previo sobre ncurses.

No hay una solución única. Resuelve la prueba usando tu propio criterio.

Si has mirado entre los archivos del proyecto, verás que tan sólo consta de `prueba.cpp`, que es el archivo del programa principal, y dos clases, llamadas `Gauge` y `Simulator`.

* `Gauge` es una clase muy sencilla que permite crear instrumentos similares a los del panel de un avión (aunque muy esquemáticos, dadas las limitaciones técnicas) y mostrarlos en pantalla. Te proporcionamos su código fuente, aunque no te será necesario modificarlo.
* `Simulator` es una clase abstracta que nos da acceso a nuestro hipotético simulador. Por desgracia es de código cerrado y se nos proporciona ya compilada. Tan sólo tenemos acceso a su API pública.

Lee atentamente los requisitos proporcionados por el cliente y los comentarios del código fuente.

Para satisfacer el primer requisito del cliente (mostrar también los instrumentos correspondientes al motor 2), recomiendo crear una nueva clase (llamada, por ejemplo, `Panel`) que permita agrupar las instancias de `Gauge`. Necesitarás trasladar a esta nueva clase parte del código de `prueba.cpp`.

Para satisfacer el segundo requisito ("falsear" los valores que llegan del simulador) puede serte útil crear otra clase adicional. Aplica el criterio de abstracción que consideres más apropiado para resolver este problema.

Si tienes alguna duda, puedes consultarme en cualquier momento por email: [gabriel.rd@simloc.es](mailto:gabriel.rd@simloc.es).

## Entrega de la solución

Recuerda que el plazo máximo es hasta el lunes 7 de septiembre a las 20:00 horas.

Si no te da tiempo a resolver el ejercicio por completo antes de que finalice el plazo, envíame igualmente lo que tengas, aunque esté incompleto.

Si utilizas Cloud9, utiliza la opción de menú **File -> Download Project** para obtener un `.tar.gz` de tu proyecto y envíamelo por email a [gabriel.rd@simloc.es](mailto:gabriel.rd@simloc.es).

Si no usas Cloud9, archiva tu proyecto en un fichero `.tar.gz` o `.zip` y envíamelo por email a [gabriel.rd@simloc.es](mailto:gabriel.rd@simloc.es).


¡Buena suerte!

Gabriel Lorenzo  
Software I+D  
Simloc Research S.L.  
[gabriel.rd@simloc.es](mailto:gabriel.rd@simloc.es)
