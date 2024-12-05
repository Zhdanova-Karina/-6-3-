abstract class Dog {
    protected String name;

    public Dog(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    // Абстрактный метод для получения звука
    public abstract String makeSound();

    // Метод для отображения информации о собаке
    public String toString() {
        return "Имя собаки: " + name + "\nГоворит: " + makeSound();
    }
    public void bark() {
        System.out.println(name + " найден!");
    }
    public String getDetails() {
        return "Далматинец: " + getName();
    }
}
