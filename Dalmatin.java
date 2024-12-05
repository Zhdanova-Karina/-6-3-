public class Dalmatin extends Dog {
    private String name; // Поле для имени

    public Dalmatin(String dogName) {
        super(dogName);
        this.name = dogName; // Установка имени через конструктор
    }

    // Метод для получения имени
    public String getName() {
        return name; // Добавлен метод для получения имени
    }

    @Override
    public String makeSound() {
        return "Привет!";
    }

    @Override
    public String toString() {
        return super.toString() + "\nПорода: Далматинец, Имя: " + name; // Вывод имени
    }
}
