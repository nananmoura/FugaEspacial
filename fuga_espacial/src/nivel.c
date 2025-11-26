#include "nivel.h"

int get_num_tiros(int nivel) {
    switch(nivel) {
        case 1: return 1;
        case 2: return 2;
        case 3: return 3;
        case 4: return 5; 
        default: return 1;
    }
}

int get_tiro_offset(int nivel, int i) {
    switch(nivel) {
        case 1: return 0;                    
        case 2: return (i == 0 ? -4 : 4);    
        case 3: return (i == 0 ? -4 : (i==1 ? 0 : 4));
        case 4: return (i == 0 ? -4 : (i==1 ? -2 : (i==2 ? 0 : (i==3 ? 2 : 4))));
        default: return 0;
    }
}
