## Zadanie: Implementacja figur

## Cel zadania
Zmodyfikuj utworzone w ramach poprzedniego zadania klasy reprezentujące figury geometryczne tak, aby
- Klasy `Line`, `Triangle` i `Quadrilateral` dziedziczyły po klasie Figure. Zaimplementuj brakujące metody.
  - Metoda `equals(Figure* other)` dla klasy `Triangle` wygląda nastepująco:
    ```cpp
    bool Triangle::equals(Figure* other) {
        Triangle* otherTriangle = dynamic_cast<Triangle*>(other);
        if (otherTriangle == nullptr) {
            return false;
        }
        return (a->equals(otherTriangle->a) && b->equals(otherTriangle->b) && c->equals(otherTriangle->c));
    }
    ```
- Klasa `Group` posiadała zamiast 3 przeciążonych metod `add(..)`, `remove(..)` jedną metodę `add(Figure* figure)` i `remove(Figure *)`.
- Klasa `Group` posiadała zamiast 3 wektorów jedno pole typu `std::vector<Figure*> figures`.


Testy jednostkowe umieszczone są w:
- `test_line.cpp`
- `test_point.cpp`
- `test_triangle.cpp`
- `test_quadrilateral.cpp`
- `test_group.cpp`
 
## Test
Aby uruchomić testy jednostkowe, wykonaj komendę w terminalu:
```bash
make test_line
make test_point
make test_triangle
make test_quadrilateral
make test_group
```