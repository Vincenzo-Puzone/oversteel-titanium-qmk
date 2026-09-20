#ifdef RGB_MATRIX_ENABLE

#include "rgb_matrix.h"
#include "config_led.h"

// --- LED laterali (fix definitivo) ---
// Individuati sperimentalmente tramite firmware diagnostico (vedi cronologia):
// condividono la scansione riga/colonna con celle della matrice mai associate a un
// tasto fisico (righe/colonne "di riempimento" attorno a Pause e alla barra spazio).
// - col18,19,20 della riga 0 (dopo Pause)      -> i 3 LED laterali di destra
// - col3,4,5 della riga 5 (sotto la barra spazio) -> i 3 LED laterali di sinistra
// Ora hanno indici LED reali (106-111) invece di NO_LED, quindi sono LED a tutti gli
// effetti: compaiono in OpenRGB, rispondono a Direct e a tutti gli effetti RGB Matrix.
//
// --- Numerazione PrtSc (fix "in sequenza") ---
// Il LED aggiunto per il tasto PrtSc (che duplicava il punto di F12) ora ha indice 13,
// in sequenza subito dopo F12 (12) e prima di ScrLk/Pause, invece di stare in coda
// all'array. Tutti i LED originali da 13 a 104 sono quindi slittati di +1 (14-105).
// I 6 LED laterali restano 106-111, invariati.
led_config_t g_led_config = { {
    {  0,      1,      2,      3,      4,      5,      6,      7,      8,      9,     10,     11,     12, NO_LED,     13,     14,     15, NO_LED,    106,    107,    108 },  // col14 (PrtSc) = 13, in sequenza dopo F12
    { 16,     17,     18,     19,     20,     21,     22,     23,     24,     25,     26,     27,     28,     29,     30,     31,     32,     33,     34,     35,     36 },
    { 37,     38,     39,     40,     41,     42,     43,     44,     45,     46,     47,     48,     49,     50,     51,     52,     53,     54,     55,     56,     57 },
    { 58,     59,     60,     61,     62,     63,     64,     65,     66,     67,     68,     69,     70,     71, NO_LED, NO_LED, NO_LED,     72,     73,     74, NO_LED },
    { 75,     76,     77,     78,     79,     80,     81,     82,     83,     84,     85,     86, NO_LED,     87, NO_LED,     88, NO_LED,     89,     90,     91,     92 },
    { 93,     94,     95,    109,    110,    111,     96, NO_LED, NO_LED,     97,     98,     99, NO_LED,    100,    101,    102,    103, NO_LED,    104,    105, NO_LED }

}, {
    {0  ,  0},            {30 ,  0}, {40 ,  0}, {50 ,  0}, {65 ,  0}, {75 ,  0}, {85 ,  0}, {95 ,  0}, {110,  0}, {120,  0}, {130,  0}, {140,  0}, {157,  0}, {162,  0}, {167,  0}, {177,  0},  // LED 13: PrtSc (in sequenza dopo F12)
    {0  , 17}, {10 , 17}, {20 , 17}, {30 , 17}, {40 , 17}, {50 , 17}, {60 , 17}, {70 , 17}, {80 , 17}, {90 , 17}, {100, 17}, {110, 17}, {120, 17}, {137, 17}, {157, 17}, {167, 17}, {177, 17}, {194, 17}, {204, 17}, {214, 17}, {224, 17},
    {3  , 29}, {15 , 29}, {25 , 29}, {35 , 29}, {45 , 29}, {55 , 29}, {65 , 29}, {75 , 29}, {85 , 29}, {95 , 29}, {105, 29}, {115, 29}, {125, 29}, {129, 41}, {157, 29}, {167, 29}, {177, 29}, {194, 29}, {204, 29}, {214, 29}, {224, 35},
    {5  , 41}, {19 , 41}, {29 , 41}, {39 , 41}, {49 , 41}, {59 , 41}, {69 , 41}, {79 , 41}, {89 , 41}, {99 , 41}, {109, 41}, {119, 41}, {135, 41}, {141, 41},                                  {194, 41}, {204, 41}, {214, 41},
    {2  , 52}, {12 , 52}, {22 , 52}, {32 , 52}, {42 , 52}, {52 , 52}, {62 , 52}, {72 , 52}, {82 , 52}, {92 , 52}, {102, 52}, {112, 52},      {132, 52},            {167, 52},                  {194, 52}, {204, 52}, {214, 52}, {224, 55},
    {2  , 64}, {13 , 64}, {26 , 64},                                  {67 , 64},                       {124, 64}, {134, 64}, {144, 64}, {150, 64},      {157, 64}, {167, 64}, {177, 64},             {197, 64},      {214, 64},
    // LED 106-111: laterali. NOTA: il punto e' un uint8_t (0-224): niente valori
    // negativi (avrebbero fatto il "wrap" ammucchiando tutto a destra in OpenRGB) e
    // niente valori di y oltre l'altezza normale della tastiera (0-64): alcuni
    // effetti RGB calcolano il colore in base alla posizione, e con coordinate
    // "fuori scala" possono generare lampi bianchi imprevisti. Restiamo quindi
    // dentro il range normale, solo con y leggermente diversi da quelli gia' usati.
    {224,  6}, {224, 26}, {224, 46},  // LED 106-108: laterali destra (alto/centro/basso)
    {0  ,  6}, {0  , 26}, {0  , 46},  // LED 109-111: laterali sinistra (alto/centro/basso)
}, {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 4, 4, 4, 1,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 4, 4, 4,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 4, 4, 4, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4,
    1, 1, 1, 1, 1, 1, // LED 106-111
} };

#endif
