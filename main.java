import java.io.IOException;
import java.util.Scanner;// Базовый класс Place

class Main {
    public static void main(String[] args)  throws CloneNotSupportedException {
        PlaceWithCode cage = new PlaceWithCode("Клетка", true, "ABC");

        // Вызов метода getDetails с базовым поведением
        System.out.println("Стандартные детали клетки:");
        System.out.println(cage.getDetails());

        // Вызов перегруженного метода getDetails без использования базового метода
        System.out.println("\nПерегруженные детали клетки без базовых:");
        System.out.println(cage.getDetails(true)); // Включить помощь
        System.out.println(cage.getDetails(false)); // Без дополнительных деталей

        PlaceWithCode placeWithCode = new PlaceWithCode("Клетка", true, "XYZ");

        // Демонстрация использования методов toString

        System.out.println(placeWithCode.toString()); // Вызывает перегруженный метод toString

        System.out.println(placeWithCode.toString(true)); // Вызывает перегруженный метод с параметром

        System.out.println(placeWithCode.toString(false)); // Вызывает перегруженный метод без параметров

        System.out.println("\nДобавление абстрактного класса:");
        // Создаем экземпляр класса Dalmatin
        Dalmatin dalmatin = new Dalmatin("Рекс");

        // Отображаем информацию о далматинце
        System.out.println(dalmatin.toString());

        // Создаем место и устанавливаем, что там есть далматинец
        Place park = new Place("Парк", true);
        System.out.println(park.getDetails());
        Level originalLevel = new Level("Уровень 1");
        System.out.println("До изменения в мелком клонировании:");
        System.out.println(originalLevel.places[0].getName());
        // Изменяем первое место
        originalLevel.setPlaceName(0, "1. Стол");
        System.out.println("После изменения в мелком клонировании:");
        System.out.println(originalLevel.places[0].getName()); // Ожидается "1. Стол"
        Level shallowClone = (Level) originalLevel.clone();
        System.out.println(shallowClone.places[0].getName()); // Ожидается "1. Стол"
        System.out.println("До изменения в глубоком клонировании:");
        System.out.println(originalLevel.places[1].getName());
        Level deepClone = originalLevel.deepClone();
        System.out.println("Глубокое клонирование:");
        System.out.println(deepClone.places[0].getName()); // Должен вернуть "Стол"
        originalLevel.places[1].setName("2. Шкаф");
        System.out.println("После изменения в глубоком клонировании:");
        System.out.println(originalLevel.places[1].getName()); // Должен вернуть "Шкаф"
        System.out.println(deepClone.places[1].getName()); // Должен вернуть "Клетка"
        // Создание контейнера для собак
        Container<Dog> dogContainer = new Container<>();

        // Добавление далматинцев в контейнер
        Dalmatin dalmatin1 = new Dalmatin("Понго");
        Dalmatin dalmatin2 = new Dalmatin("Патч");

        dogContainer.add(dalmatin1);
        dogContainer.add(dalmatin2);

        // Использование методов контейнера
        for (int i = 0; i < dogContainer.size(); ++i) {
            Dog dog = dogContainer.get(i);
            if (dog instanceof Dalmatin) {
                System.out.println(((Dalmatin) dog).getDetails());
            }
            dog.bark();
        }
    }
    }
