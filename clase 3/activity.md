## Realiza un programa en Cpp donde se simule el juego bingo, con las siguientes características:
- El usuario podrá elegir si juega contra la máquina o contra otro usuario.

- Si elige jugar contra la máquina, el usuario podrá elegir los números que contendrá su tablero de juego, siendo este una matriz de 4X4. De igual manera se generará el tablero del sistema, siendo una matriz de 4X4 que se llenará de manera automática con valores random (investigar como se genera un número random y aplicar), todos los valores permitidos serán entre 1 y 100, sin repetir valores.
- Sí elige jugar contra otro usuario, cada uno de los usuarios podrá generar su carta indicando los valores entre 1 y 100 siendo esta de 4X4, sin repetir valores.
- También cada usuario podrá elegir la opción de generar tabla aleatoriamente, sin repetir valores.
- Comenzar juego: se irán generando números aleatorios de uno en uno entre 1 y 100, cada valor será comparado en ambas tablas cuadro por cuadro para verificar si existe, se irá incrementando un contados para el usuario 1 y el usuario 2 (o el sistema en dado caso).
- El juego termina en el momento que uno de los dos jugadores llega a 16 puntos, es decir el tablero completo.
- Al final, debe especificar el usuario ganador.
- El usuario podrá seguir jugando, seleccionando en las opciones del menú, hasta el momento que seleccione salir del programa y todo se cierra.
- El programa se podrá trabajar en parejas, no olviden que solo un integrante es el encargado de subir la actividad y colocar en los comentarios el nombre de los integrantes.

## El diagrama de flujo es el siguiente:

```mermaid
flowchart TD
    A([Inicio]) --> B[Inicializar generador de números aleatorios]
    B --> C[Mostrar menú principal]

    C --> D{¿Opción válida?}
    D -->|No| C
    D -->|Salir| Z([Cerrar programa])
    D -->|Jugar contra la máquina| E[Seleccionar modo: Usuario vs Sistema]
    D -->|Jugar contra otro usuario| F[Seleccionar modo: Usuario 1 vs Usuario 2]

    E --> G[Crear tableros 4x4]
    F --> G

    G --> H[Permitir elegir llenado manual o aleatorio]

    H --> I{¿Llenado manual?}
    I -->|Sí| J[Solicitar números del 1 al 100]
    J --> K{¿Número válido y no repetido?}
    K -->|No| J
    K -->|Sí| L[Guardar número en el tablero]
    L --> M{¿Tablero completo?}
    M -->|No| J
    M -->|Sí| N

    I -->|No| O[Generar números aleatorios del 1 al 100 sin repetir]
    O --> N

    N{¿Modo contra la máquina?}
    N -->|Sí| P[Generar automáticamente tablero del sistema]
    N -->|No| Q[Preparar tablero del usuario 2]

    P --> R[Inicializar posiciones marcadas]
    Q --> R

    R --> S[Inicializar puntajes, turnos y registro de números]
    S --> T[Mostrar tableros iniciales]

    T --> U{¿Algún participante tiene 16 puntos?}
    U -->|Sí| AA[Comparar resultados finales]
    U -->|No| V[Generar número aleatorio del 1 al 100]

    V --> W{¿El número ya salió?}
    W -->|Sí| V
    W -->|No| X[Registrar número generado]

    X --> Y[Buscar número en ambos tableros]

    Y --> AB{¿Aparece en el tablero del usuario 1?}
    AB -->|Sí| AC[Marcar posición y aumentar puntaje del usuario 1]
    AB -->|No| AD[Continuar]

    AC --> AD

    AD --> AE{¿Aparece en el tablero del usuario 2/sistema?}
    AE -->|Sí| AF[Marcar posición y aumentar puntaje del usuario 2/sistema]
    AE -->|No| AG[Continuar]

    AF --> AG

    AG --> AH[Mostrar número generado, puntos y tableros actualizados]
    AH --> AI[Aumentar contador de turnos]
    AI --> U

    AA --> AJ{¿Ambos tienen 16 puntos?}
    AJ -->|Sí| AK{¿Completaron en el mismo turno?}
    AK -->|Sí| AL[Declarar empate]
    AK -->|No| AM[Determinar quién completó primero]

    AJ -->|No| AM

    AM --> AN{¿Quién completó primero?}
    AN -->|Usuario 1| AO[Declarar ganador al usuario 1]
    AN -->|Usuario 2| AP[Declarar ganador al usuario 2]
    AN -->|Sistema| AQ[Declarar ganador al sistema]

    AL --> AR[Finalizar partida]
    AO --> AR
    AP --> AR
    AQ --> AR

    AR --> C
```