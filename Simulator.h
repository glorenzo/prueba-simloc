#pragma once

// La clase Simulator nos da acceso a la simulación del comportamiento de un avión.
// Su implementación está oculta, no podemos ver cómo funciona por dentro ni modificar su comportamiento.

class Simulator
{
public:
    // Este método nos da siempre la misma única instancia de Simulator
    static Simulator* GetInstance();
    
    // Este método debe ser llamado en un bucle para que el estado del simulador se vaya actualizando
    virtual void Update() = 0;
    
    // Acciones que podemos enviar al simulador
    virtual void StartEngine1() = 0;
    virtual void StartEngine2() = 0;
    virtual void StopEngine1() = 0;
    virtual void StopEngine2() = 0;
    
    // Devuelve el tiempo que lleva ejecutándose la simulación, en milisegundos
    virtual unsigned int simulationTime() = 0;
    
    // Métodos para obtener el valor actual de otras variables del simulador
    virtual bool engine1Started() = 0;
    virtual bool engine2Started() = 0;
    virtual float torque1() = 0;
    virtual float torque2() = 0;
    virtual float rpm1() = 0;
    virtual float rpm2() = 0;
    virtual float itt1() = 0;
    virtual float itt2() = 0;
    
protected:
    Simulator();
};