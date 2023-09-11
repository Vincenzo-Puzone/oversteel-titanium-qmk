#ifdef RGB_MATRIX_ENABLE

#include "rgb_matrix.h"
#include "config_led.h"

led_config_t g_led_config = { {
    {  0,      1,      2,      3,      4,      5,      6,      7,      8,      9,     10,     11,     12, NO_LED,     12,     13,     14, NO_LED, NO_LED, NO_LED, NO_LED },
    { 15,     16,     17,     18,     19,     20,     21,     22,     23,     24,     25,     26,     27,     28,     29,     30,     31,     32,     33,     34,     35 },
    { 36,     37,     38,     39,     40,     41,     42,     43,     44,     45,     46,     47,     48,     49,     50,     51,     52,     53,     54,     55,     56 },
    { 57,     58,     59,     60,     61,     62,     63,     64,     65,     66,     67,     68,     69,     70, NO_LED, NO_LED, NO_LED,     71,     72,     73, NO_LED },
    { 74,     75,     76,     77,     78,     79,     80,     81,     82,     83,     84,     85, NO_LED,     86, NO_LED,     87, NO_LED,     88,     89,     90,     91 },
    { 92,     93,     94, NO_LED, NO_LED, NO_LED,     95, NO_LED, NO_LED,     96,     97,     98, NO_LED,     99,    100,    101,    102, NO_LED,    103,    104, NO_LED }

}, {
    {0  ,  0},            {30 ,  0}, {40 ,  0}, {50 ,  0}, {65 ,  0}, {75 ,  0}, {85 ,  0}, {95 ,  0}, {110,  0}, {120,  0}, {130,  0}, {140,  0},            {157,  0}, {167,  0}, {177,  0},
    {0  , 17}, {10 , 17}, {20 , 17}, {30 , 17}, {40 , 17}, {50 , 17}, {60 , 17}, {70 , 17}, {80 , 17}, {90 , 17}, {100, 17}, {110, 17}, {120, 17}, {137, 17}, {157, 17}, {167, 17}, {177, 17}, {194, 17}, {204, 17}, {214, 17}, {224, 17},
    {3  , 29}, {15 , 29}, {25 , 29}, {35 , 29}, {45 , 29}, {55 , 29}, {65 , 29}, {75 , 29}, {85 , 29}, {95 , 29}, {105, 29}, {115, 29}, {125, 29}, {129, 41}, {157, 29}, {167, 29}, {177, 29}, {194, 29}, {204, 29}, {214, 29}, {224, 35},
    {5  , 41}, {19 , 41}, {29 , 41}, {39 , 41}, {49 , 41}, {59 , 41}, {69 , 41}, {79 , 41}, {89 , 41}, {99 , 41}, {109, 41}, {119, 41}, {135, 41}, {141, 41},                                  {194, 41}, {204, 41}, {214, 41},
    {2  , 52}, {12 , 52}, {22 , 52}, {32 , 52}, {42 , 52}, {52 , 52}, {62 , 52}, {72 , 52}, {82 , 52}, {92 , 52}, {102, 52}, {112, 52},      {132, 52},            {167, 52},                  {194, 52}, {204, 52}, {214, 52}, {224, 55},
    {2  , 64}, {13 , 64}, {26 , 64},                                  {67 , 64},                       {124, 64}, {134, 64}, {144, 64}, {150, 64},      {157, 64}, {167, 64}, {177, 64},             {197, 64},      {214, 64},
}, {
   8,    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,    8, 8, 8,
   8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
   8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
   8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,          8, 8, 8,
   8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,   8,     8,    8, 8, 8, 8,
   8, 8, 8,          8,       8, 8, 8,    8, 8, 8, 8,    8, 8,
} };

#endif
