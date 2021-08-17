/*
 * Определите тип Incognizable, для которого следующий код будет корректен.
 */

struct Incognizable {
    int attr1 = 0;
    int attr2 = 0;
};

int main() {
    Incognizable a;
    Incognizable b = {};
    Incognizable c = {0};
    Incognizable d = {0, 1};
    return 0;
}
