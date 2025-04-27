
// create a struct parrellelogram
// with height and base members
#include <stdio.h>

struct pgram{
  float height;
  float base;
};



void setbase(struct pgram* shape, float value){
    shape->height = value;
}

void setheight(struct pgram* shape, float value){
    shape->height = value;
}

float perimeter(struct pgram* shape){
    float p = (2 * shape->height) + (2 * shape->base);
    return p;
}

float area(struct pgram* shape){
    float a = shape->height * shape->base;
    return a;
}

void show(struct pgram* shape){
    printf("base: %f\nheight: %f\narea: %f\nperimeter: %f\n\n", shape->base, shape->height, area(shape), perimeter(shape));
}

int samearea(struct pgram* shape1, struct pgram* shape2){
   float a1 = area(shape1);
   float a2 = area(shape2);
    if(a1 == a2) return 1;
    else return 0;
    
}

int main(){
    struct pgram p1, p2;
    setbase(&p1, 5);
    setheight(&p1, 2.5);
    
    setbase(&p2, 5);
    setheight(&p2, 18.9);
    
    show(&p1);
    show(&p2);
    
    if(samearea(&p1, &p2)){
        printf("same area!");
    } else printf("different areas");
    setbase(&p1, 15);
    setheight(&p1, 6.3);
    
    show(&p1);
    show(&p2);
    

    return 0;
}
