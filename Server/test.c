#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

#include <regex.h>

// void addFishVisitor(View *v, Fish f, int original_view)
// {

//     if (v->num_fishes_visitors == 0)
//     {
//         v->fishes_visitors = (Fish *)malloc(sizeof(Fish));
//         v->fishes_visitors[0] = f;
//         v->num_fishes_visitors++;
//         //v->fishes_visitors_view = (int *)malloc(sizeof(int));
//         v->fishes_visitors_view[0] = original_view;
//     }
//     else
//     {
//         v->num_fishes_visitors++;
//         v->fishes_visitors = (Fish *)realloc(v->fishes_visitors, v->num_fishes_visitors * sizeof(Fish));
//         v->fishes_visitors[v->num_fishes_visitors - 1] = f;
//         //v->fishes_visitors_view = (int *)realloc(v->fishes_visitors_view, v->num_fishes_visitors * sizeof(int));
//         v->fishes_visitors_view[v->num_fishes_visitors - 1] = original_view;
//     }
   


// }

int main() {
   

    Aquarium *aquarium = loadAquarium("aquarium");
    

    printf("num_fishes_visitors: %d\n", strcmp("list ", "list [PoissonRouge at 92x40,10x4,5] [PoissonClown at 22x80,12x6,5]"));
    

    return 0;
}
