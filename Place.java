import java.io.IOException;
import java.util.Scanner;// Базовый класс Place
class Place implements Cloneable{
    protected String name; // Использование модификатора protected
    protected boolean existDalmatian;    public Place(String placeName, boolean trueORfalse) {
        name = placeName;
        existDalmatian = trueORfalse;
    }

    @Override
    public Object clone() throws CloneNotSupportedException {
        return super.clone(); // Выполняет мелкое клонирование для Place
    }
    public String getName() { return name; }
    public void setName(String name) { this.name = name; } // Метод для изменения названия места

    public boolean getExistDalmatian() { return existDalmatian; }

    public void setExistDalmatian(boolean trueORfalse) { existDalmatian = trueORfalse; }

    // Метод getDetails, который будет перегружен
    public String getDetails() {
        return "Название места: " + name + "\nДалматинец на месте: " + (existDalmatian ? "Да" : "Нет");
    }
    @Override
    public String toString() {
        return "Название места: " + name + "\nДалматинец на месте: " + (existDalmatian ? "Да" : "Нет");
    }

}

