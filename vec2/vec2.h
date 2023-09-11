typedef struct {
    double e[2];
} Vec2;

Vec2    Vec2_Add       (Vec2 v1, Vec2 v2);
Vec2    Vec2_Subtract  (Vec2 v1, Vec2 v2);
Vec2    Vec2_Scale     (double scaleFactor, Vec2 v);
double  Vec2_Dot       (Vec2 v1, Vec2 v2);